#include "MPUInterface.h"
#include <stdio.h>

int main(){

	
	MPUInterface mpu = MPUInterface();
	
	while (1){
		
		printf("Xaccel: %f, Yaccel: %f, Zaccel %f\n", mpu.getXAccel(), mpu.getYAccel(), mpu.getZAccel());
		
	}

}
