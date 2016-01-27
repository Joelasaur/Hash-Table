#ifndef adt_H_
#define adt_H_

// Declare csString instance.
typedef struct csString {
	struct csStringMethods *methods;
	int size;
	char * contents;
} csString, *csStringRef;

// Declare types of methods.
typedef int (*pfn_strRef_int)(csStringRef);
typedef char * (*pfn_strRef_cStr)(csStringRef);

// Declare csString interface.
typedef struct csStringMethods {
	pfn_strRef_int	size;
	pfn_strRef_cStr	cStr;
} csStringMethods, *csStringMethodsRef;

#ifdef __cplusplus
extern "C" {
#endif

csStringRef newCSString(char *cStr);

#ifdef __cplusplus
}
#endif

#endif
