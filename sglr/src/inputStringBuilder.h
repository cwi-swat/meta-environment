/*$Id$*/

#ifndef __INPUT_STRING_BUILDER__
#define  __INPUT_STRING_BUILDER__

#include "inputString-data.h"

/* |string| is a C-style string that is terminated by '\0'. Consequently 
 * if '\0' is a token, the input string will not be correctly handled. If
 * '\0' can appear in the input string then IS_createInputStringFromBytes()
 * should be used instead.
 */
InputString  IS_createInputStringFromString(const unsigned char *string);
InputString  IS_createInputStringFromBytes(const char *path, 
					   const unsigned char *string,
					   const int length);
InputString IS_createInputStringFromFile(const char *path);
double IS_getTimeTakenToReadInput(void);

#endif /* __INPUT_STRING_BUILDER__ */


