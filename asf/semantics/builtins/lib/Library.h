#ifndef _LIBRARY_H
#define _LIBRARY_H

/*{{{  includes */

#include <aterm1.h>
#include "Library_dict.h"

/*}}}  */

/*{{{  prologue */

typedef struct _CO_CHARLIST *CO_CHARLIST;

ATbool CO_isValidCHARLIST(CO_CHARLIST arg);
ATbool CO_isCHARLISTString(CO_CHARLIST arg);
char*  CO_getCHARLISTString(CO_CHARLIST arg);
CO_CHARLIST  CO_setCHARLISTString(CO_CHARLIST arg, char *str);
ATerm  CO_CHARLISTToTerm(CO_CHARLIST arg);
CO_CHARLIST CO_CHARLISTFromTerm(ATerm trm);
CO_CHARLIST CO_makeCHARLISTString(char *str);

/*}}}  */
/*{{{  typedefs */


/*}}}  */

void CO_initLibraryApi(void);

/*{{{  term conversion functions */


/*}}}  */
/*{{{  list functions */


/*}}}  */
/*{{{  constructors */


/*}}}  */
/*{{{  equality functions */


/*}}}  */
/*{{{  sort visitors */


/*}}}  */

#endif /* _LIBRARY_H */
