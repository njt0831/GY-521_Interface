#include "MPUInterface.h"
#include <stdio.h>

MPUInterface::MPUInterface(){

	device = wiringPiI2CSetup(0x68);
	wiringPiI2CWriteReg8(device, 0x6B, 0);
	setSensitivity(PLUS_MINUS_2_G);

}

void MPUInterface::setSensitivity(unsigned char value){
	
	wiringPiI2CWriteReg8(device, 0x1C, value);
	
	if (value == PLUS_MINUS_2_G){ sensitivity = 2; }
	else if (value == PLUS_MINUS_4_G){ sensitivity = 4; }
	else if (value == PLUS_MINUS_8_G){ sensitivity = 8; }
	else{ sensitivity = 16; }

}

float MPUInterface::getXAccel(){

	hb = wiringPiI2CReadReg8(device, 0x3B);
	lb = wiringPiI2CReadReg8(device, 0x3D);
	int registerValue = (hb << 8 | lb) - 32767.5;
	return copysign((abs(registerValue) - 32767.5) * ((sensitivity * 9.81) / 32767.5), registerValue);

}

float MPUInterface::getYAccel(){

	hb = wiringPiI2CReadReg8(device, 0x3D);
	lb = wiringPiI2CReadReg8(device, 0x3E);
	
	int registerValue = (hb << 8 | lb) - 32767.5;
	return copysign((abs(registerValue) - 32767.5) * ((sensitivity * 9.81) / 32767.5), registerValue);

}

float MPUInterface::getZAccel(){

	hb = wiringPiI2CReadReg8(device, 0x3F);
	lb = wiringPiI2CReadReg8(device, 0x40);
	
	int registerValue = (hb << 8 | lb) - 32767.5;
	return copysign((abs(registerValue) - 32767.5) * ((sensitivity * 9.81) / 32767.5), registerValue);

}
