/*
 * mcp4017.h
 *
 * Created: 11/08/2014 11:29:16 PM
 * Author: CaptainSpaceToaster
 */ 

#ifndef MCP4017_H
#define MCP4017_H

//definitions
#define MCP4017_ADDR           (0x2F<<1) //device address shifted over one

//functions
void mcp4017_init(void);
uint8_t mcp4017_set_resistance(uint8_t res);
uint8_t mcp4017_get_resistance(void);

#endif //MCP4017

