#include "common.h"

static ATermTable hashtable;
static AFun tuplefun;

/*{{{  static void check(void)  */

static void check(void) 
{
  if (hashtable == NULL) {
    hashtable = ATtableCreate(1024,75); /* magic initial size and load pct */
    tuplefun = ATmakeAFun("",2,ATfalse);
    ATprotectAFun(tuplefun);
  }
}

/*}}}  */
/*{{{  static ATerm makeKey(PT_Tree name, PT_Tree key) */

static ATerm makeKey(PT_Tree name, PT_Tree key)
{
  return (ATerm) ATmakeAppl(tuplefun, (ATerm) name, (ATerm) key);
}

/*}}}  */
  
/*{{{  PT_Tree hashtable_lookup(ATerm builtin, PT_Tree input) */

PT_Tree hashtable_lookup(ATerm builtin, PT_Tree input)
{
  PT_Tree name_arg = CO_getFunctionArgument(input,0);
  PT_Tree key_arg  = CO_getFunctionArgument(input,1);
  ATerm key;
  ATerm value;

  check();
  key   = makeKey(name_arg, key_arg);
  value = ATtableGet(hashtable,key);

  if (value == NULL) {
    return NULL;
  }
  else {
    return PT_TreeFromTerm(value);
  }
}

/*}}}  */
/*{{{  PT_Tree hashtable_store(ATerm builtin, PT_Tree input) */

PT_Tree hashtable_store(ATerm builtin, PT_Tree input)
{
  PT_Tree name_arg = CO_getFunctionArgument(input,0);
  PT_Tree key_arg  = CO_getFunctionArgument(input,1);
  PT_Tree value_arg  = CO_getFunctionArgument(input,2);
  ATerm key;

  check();

  key = makeKey(name_arg, key_arg);
  ATtablePut(hashtable,key,(ATerm) value_arg);

  return name_arg;
}

/*}}}  */
/*{{{  PT_Tree hashtable_delete(ATerm builtin, PT_Tree input) */

PT_Tree hashtable_delete(ATerm builtin, PT_Tree input)
{
  PT_Tree name_arg = CO_getFunctionArgument(input,0);
  PT_Tree key_arg  = CO_getFunctionArgument(input,1);
  ATerm key;

  check();

  key = makeKey(name_arg, key_arg);
  ATtableRemove(hashtable,key);

  return name_arg;
}

/*}}}  */
