#include <aterm2.h>
#include <aterm1.h>
#include <MEPT-utils.h>

static ATermTable hashtable;
static AFun tuplefun;

static void check(void) {
  if (hashtable == NULL) {
    hashtable = ATtableCreate(1024,75); /* magic initial size and load pct */
    tuplefun = ATmakeAFun("",2,ATfalse);
    ATprotectAFun(tuplefun);
  }
}

static ATerm makeKey(PT_Tree name, PT_Tree key)
{
  return (ATerm) ATmakeAppl(tuplefun, (ATerm) name, (ATerm) key);
}
  
PT_Tree hashtable_lookup(ATerm builtin, PT_Tree input)
{
  PT_Args args = PT_getTreeArgs(input);
  PT_Tree name_arg = PT_getArgsArgumentAt(args,4);
  PT_Tree key_arg  = PT_getArgsArgumentAt(args,8);
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

PT_Tree hashtable_store(ATerm builtin, PT_Tree input)
{
  PT_Args args = PT_getTreeArgs(input);
  PT_Tree name_arg = PT_getArgsArgumentAt(args,4);
  PT_Tree key_arg  = PT_getArgsArgumentAt(args,8);
  PT_Tree value_arg  = PT_getArgsArgumentAt(args,12);
  ATerm key;
  ATerm value;

  check();

  key = makeKey(name_arg, key_arg);
  ATtablePut(hashtable,key,(ATerm) value_arg);

  return name_arg;
}

PT_Tree hashtable_delete(ATerm builtin, PT_Tree input)
{
  PT_Args args = PT_getTreeArgs(input);
  PT_Tree name_arg = PT_getArgsArgumentAt(args,4);
  PT_Tree key_arg  = PT_getArgsArgumentAt(args,8);
  PT_Tree value_arg  = PT_getArgsArgumentAt(args,12);
  ATerm key;
  ATerm value;

  check();

  key = makeKey(name_arg, key_arg);
  ATtableRemove(hashtable,key);

  return name_arg;
}
