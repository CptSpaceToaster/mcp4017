/*
 * mcp4017.c
 *
 * Created: 11/08/2014 11:29:16 PM
 * Author: CaptainSpaceToaster
 */ 

#include "avr/io.h"
#include "util/delay.h"

#include "mcp4017.h"
#include "../twi/i2cmaster.h"

void mcp4017_init(void) {
	//Nothing to do here
}


uint8_t mcp4017_set_resistance(uint8_t res) {
	if (res > 0x7F) {
		//error resistance too large
		return 2;
	}
	
	int err = i2c_start(MCP4017_ADDR | I2C_WRITE);
	if (err) {
		//error, device did not ack	
		return 1;
	}
	i2c_write(res);
	
	i2c_stop();
	return 0;
}


uint8_t mcp4017_get_resistance(void) {
	int err = i2c_start(MCP4017_ADDR | I2C_READ);
	if (err) {
		//error, device did not ack
		return 0xFF;
	}
	return i2c_readNak();
}
