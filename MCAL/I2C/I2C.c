
#include "I2C.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/twi.h>

static volatile uint8_t TWI_busy = 0;

// Define your own callback functions for write collision and TWI interrupt handling
// You can implement these functions according to your application's requirements.

// Example callback for write collision handling
//void TWI_WriteCollisionCallback() {
//    // Implement your logic here
//}

// Example callback for TWI interrupt handling
//void TWI_InterruptHandlerCallback() {
//    // Implement your logic here
//}

std_return_type TWI_int(const TWI_T *TWI) {
    // Configure TWI settings based on the provided TWI_CONFIG
    // You may need to adjust this part according to your specific TWI configuration
    if (TWI->TWI_CFG.TWI_MODE == master_mode) {
        // Configure TWI in master mode
        // Set the TWI bit rate register (TWBR) for the desired baud rate
        TWBR = (uint8_t)((cpu_fre / (2 * TWI->twi_rate)) - 8);
        TWSR = (TWSR & 0xFC) | (pre1);  // Set prescaler to 1 (adjust as needed)

        // Enable TWI
        TWCR = (1 << TWEN);
    } else if (TWI->TWI_CFG.TWI_MODE == slave_mode) {
        // Configure TWI in slave mode
        // Set the slave address and general call recognition
        TWAR = (TWI->TWI_CFG.genral_call << 0) | (TWI->TWI_CFG.slave_adress << 1);
        // Enable TWI and TWI interrupt
        TWCR = (1 << TWEN) | (1 << TWIE);
    }

    // Enable global interrupts
    sei();

    return E_OK;
}

std_return_type TWI_deint() {
    // Disable TWI and TWI interrupt
    TWCR = 0;

    return E_OK;
}

std_return_type TWI_send_start() {
    // Generate start condition
    TWCR = (1 << TWSTA) | (1 << TWINT) | (1 << TWEN);
    // Wait until start condition is executed
    while (!(TWCR & (1 << TWINT)));

    return E_OK;
}

std_return_type TWI_send_stop() {
    // Generate stop condition
    TWCR = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN);
    // Wait until stop condition is executed
    while (TWCR & (1 << TWSTO));

    return E_OK;
}

std_return_type TWI_write(uint8_t data) {
    // Copy data to TWI data register
    TWDR = data;
    // Clear the TWI interrupt flag
    TWCR = (1 << TWINT) | (1 << TWEN);
    // Wait until write operation is complete
    while (!(TWCR & (1 << TWINT)));

    return E_OK;
}

std_return_type TWI_read(uint8_t *data) {
    // Enable TWI and clear interrupt flag to start reception
    TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);
    // Wait until read operation is complete
    while (!(TWCR & (1 << TWINT)));
    // Read received data
    *data = TWDR;

    return E_OK;
}

// Implement your TWI interrupt handler function here, if needed
//ISR(TWI_vect) {
//    // Handle TWI interrupts as needed
//}

