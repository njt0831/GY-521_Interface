#include <wiringPiI2C.h>
#include <math.h>

struct MPUInterface{

	// Device handle 
	int device;

	// Sensitivity multiplier
	int sensitivity = 2;

	// Temporary variables for register reading
	int hb;
	int lb;

	// Constructor
	MPUInterface();


	// Set the sensitivity
	// Values range from +-2g to +-16g
	// See constants below for valuee
	void setSensitivity(unsigned char value);
	

	// Interaction methods
	// Outputs acceleration in m/s^2
	float getXAccel();
	float getYAccel();
	float getZAccel();

	// Acceleration configuration register values
	static const unsigned char PLUS_MINUS_2_G = 0;
	static const unsigned char PLUS_MINUS_4_G = 0x08;
	static const unsigned char PLUS_MINUS_8_G = 0x10;
	static const unsigned char PLUS_MINUS_16_G = 0x18;

};
