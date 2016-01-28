#include "adt.h"
#include <stdlib.h>

// forward declaration of method implementations
int adtHash(csAdtRef self);
bool adtEquals(csAdtRef self, csAdtRef other);
char * adtDescription(csAdtRef self);


// declare the method structure for csAdtMethods
csAdtMethods adtMethods = {
	adtHash,
	adtEquals,
	adtDescription,
};

// declare csAdt constructor function
csAdtRef newCsAdt(){
	csAdtRef anAdtRef = (csAdtRef)malloc(sizeof(csAdt));
	if(anAdtRef == (csAdtRef)NULL){
		return (csAdtRef)NULL;
	}
	anAdtRef->methods = &adtMethods;
	return anAdtRef;
}

// nextHash()
//  Generate 32 bit hash using a linear feedback shift register.
//      feedback polynomial: x^32 + x^31 + x^29 + x + 1
//      taps: 32 31 29 1
uint32_t adtHash(csAdtRef self){
		static uint32_t lfsr = 1;
	  return (lfsr >> 1) ^ (-(lfsr & 1u) & 0xD0000001u);
}

bool adtEquals(csAdtRef self, csAdtRef other){

}
char * adtDescription(csAdtRef self){

}
