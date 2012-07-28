#include "builtin-common.h"
#include "Library.h"

/*{{{  static PT_Tree next_id()  */

static PT_Tree next_id() 
{
  static unsigned long id = 0L;
  char str[32]; /* long enough for the largest unsigned long */
  sprintf(str, "%ld", id++);

  return (PT_Tree) CO_makeStrCon(str);
}

/*}}}  */

/*{{{  PT_Tree ASFE_next_id(PT_Symbol type)  */

PT_Tree ASFE_next_id(PT_Symbol type) 
{
  return next_id();
}

/*}}}  */
/*{{{  PT_Tree ASC_next_id(ATerm type) */

PT_Tree ASC_next_id(ATerm type)
{
  return next_id();
}

/*}}}  */
