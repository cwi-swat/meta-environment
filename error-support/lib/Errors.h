#ifndef _ERRORS_H
#define _ERRORS_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "Errors_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _ME_NatCon *ME_NatCon;
typedef struct _ME_String *ME_String;

/*}}}  */

/*{{{  definition of bottom types */


/*}}}  */

void ME_initErrorsApi(void);

/*{{{  term conversion functions */

ME_NatCon ME_NatConFromTerm(ATerm t);
ATerm ME_NatConToTerm(ME_NatCon arg);
ME_String ME_StringFromTerm(ATerm t);
ATerm ME_StringToTerm(ME_String arg);

/*}}}  */
/*{{{  list functions */


/*}}}  */
/*{{{  constructors */

ME_NatCon ME_makeNatConNatCon(char* string);
ME_String ME_makeStringString(char* string);

/*}}}  */
/*{{{  equality functions */

ATbool ME_isEqualNatCon(ME_NatCon arg0, ME_NatCon arg1);
ATbool ME_isEqualString(ME_String arg0, ME_String arg1);

/*}}}  */
/*{{{  ME_NatCon accessors */

ATbool ME_isValidNatCon(ME_NatCon arg);
inline ATbool ME_isNatConNatCon(ME_NatCon arg);
ATbool ME_hasNatConString(ME_NatCon arg);
char* ME_getNatConString(ME_NatCon arg);
ME_NatCon ME_setNatConString(ME_NatCon arg, char* string);

/*}}}  */
/*{{{  ME_String accessors */

ATbool ME_isValidString(ME_String arg);
inline ATbool ME_isStringString(ME_String arg);
ATbool ME_hasStringString(ME_String arg);
char* ME_getStringString(ME_String arg);
ME_String ME_setStringString(ME_String arg, char* string);

/*}}}  */
/*{{{  sort visitors */

ME_NatCon ME_visitNatCon(ME_NatCon arg, char* (*acceptString)(char*));
ME_String ME_visitString(ME_String arg, char* (*acceptString)(char*));

/*}}}  */

#endif /* _ERRORS_H */
