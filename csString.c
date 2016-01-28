#include "adt.h"
#include <string.h>
#include <stdlib.h>

// forward declaration of method implementations
int stringSize(csStringRef self);
char * stringCStr(csStringRef self);

// declare the method structure for csString
csStringMethods strMethods = {
	stringSize,
	stringCStr,
};

// declare csString constructor function
csStringRef newCSString(char *cStr){
	csStringRef aString = (csStringRef)malloc(sizeof(csString));
	if(aString == (csStringRef)NULL){
		return (csStringRef)NULL;
	}
	aString->methods = &strMethods;
	aString->size = strlen(cStr);
	aString->contents = cStr;
	return aString;
}


int stringSize(csStringRef self){
	return self->size;
}

char * stringCStr(csStringRef self){
	return self->contents;
}
