/*$Id$*/

#ifndef __INPUT_STRING_API__
#define __INPUT_STRING_API__

#include <aterm1.h>
#include <Error.h>
#include "tokens.h"
#include <ptable.h>
#include <inputString-data.h>

InputString IS_allocateString(const char *path, const unsigned char *buffer, int length);
void        IS_destroyInputString(InputString inputString);
Token       IS_getCurrentToken(InputString inputString);
void        IS_readNextToken(InputString inputString);
int         IS_getNumberOfTokensRead(InputString inputString);
int         IS_getLength(InputString inputString);
ATbool      IS_isEndOfString(InputString inputString);
size_t      IS_getLinesRead(InputString inputString);
size_t      IS_getColumnsRead(InputString inputString);
ATbool      IS_checkLookahead(InputString inputString, PTBL_Restrictions restrictions);
const char* IS_getPath(InputString inputString);      
ERR_Location IS_currentPosInfo(InputString inputString);
void        IS_output(InputString inputString);
#endif /* __INPUT_STRING_API__ */


