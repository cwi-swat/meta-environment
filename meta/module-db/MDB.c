#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "MDB.h"

/*{{{  typedefs */

typedef struct ATerm _MDB_Entry;

/*}}}  */

/*{{{  void MDB_initMDBApi(void) */

void MDB_initMDBApi(void)
{
  init_MDB_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  MDB_Entry MDB_EntryFromTerm(ATerm t) */

MDB_Entry MDB_EntryFromTerm(ATerm t)
{
  return (MDB_Entry)t;
}

/*}}}  */
/*{{{  ATerm MDB_EntryToTerm(MDB_Entry arg) */

ATerm MDB_EntryToTerm(MDB_Entry arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  MDB_Entry MDB_makeEntryDefault(char * path, ATerm sdfTree, int sdfTreeCreationTime, int sdfUpdated, ATerm asfTree, ATerm asfText, int asfTreeCreationTime, ATerm asfTable, int asfTableCreationTime, ATerm trmTable, int trmTableCreationTime) */

MDB_Entry MDB_makeEntryDefault(char * path, ATerm sdfTree, int sdfTreeCreationTime, int sdfUpdated, ATerm asfTree, ATerm asfText, int asfTreeCreationTime, ATerm asfTable, int asfTableCreationTime, ATerm trmTable, int trmTableCreationTime)
{
  return (MDB_Entry)(ATerm)ATmakeAppl(MDB_afun0, (ATerm)ATmakeAppl0(ATmakeAFun(path, 0, ATtrue)), (ATerm)sdfTree, (ATerm)ATmakeInt(sdfTreeCreationTime), (ATerm)ATmakeInt(sdfUpdated), (ATerm)asfTree, (ATerm)asfText, (ATerm)ATmakeInt(asfTreeCreationTime), (ATerm)asfTable, (ATerm)ATmakeInt(asfTableCreationTime), (ATerm)trmTable, (ATerm)ATmakeInt(trmTableCreationTime));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool MDB_isEqualEntry(MDB_Entry arg0, MDB_Entry arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  MDB_Entry accessors */

/*{{{  ATbool MDB_isValidEntry(MDB_Entry arg) */

ATbool MDB_isValidEntry(MDB_Entry arg)
{
  if (MDB_isEntryDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MDB_isEntryDefault(MDB_Entry arg) */

inline ATbool MDB_isEntryDefault(MDB_Entry arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MDB_patternEntryDefault, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MDB_hasEntryPath(MDB_Entry arg) */

ATbool MDB_hasEntryPath(MDB_Entry arg)
{
  if (MDB_isEntryDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MDB_getEntryPath(MDB_Entry arg) */

char * MDB_getEntryPath(MDB_Entry arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  MDB_Entry MDB_setEntryPath(MDB_Entry arg, char * path) */

MDB_Entry MDB_setEntryPath(MDB_Entry arg, char * path)
{
  if (MDB_isEntryDefault(arg)) {
    return (MDB_Entry)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(path, 0, ATtrue)), 0);
  }

  ATabort("Entry has no Path: %t\n", arg);
  return (MDB_Entry)NULL;
}

/*}}}  */
/*{{{  ATbool MDB_hasEntrySdfTree(MDB_Entry arg) */

ATbool MDB_hasEntrySdfTree(MDB_Entry arg)
{
  if (MDB_isEntryDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm MDB_getEntrySdfTree(MDB_Entry arg) */

ATerm MDB_getEntrySdfTree(MDB_Entry arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  MDB_Entry MDB_setEntrySdfTree(MDB_Entry arg, ATerm sdfTree) */

MDB_Entry MDB_setEntrySdfTree(MDB_Entry arg, ATerm sdfTree)
{
  if (MDB_isEntryDefault(arg)) {
    return (MDB_Entry)ATsetArgument((ATermAppl)arg, (ATerm)sdfTree, 1);
  }

  ATabort("Entry has no SdfTree: %t\n", arg);
  return (MDB_Entry)NULL;
}

/*}}}  */
/*{{{  ATbool MDB_hasEntrySdfTreeCreationTime(MDB_Entry arg) */

ATbool MDB_hasEntrySdfTreeCreationTime(MDB_Entry arg)
{
  if (MDB_isEntryDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int MDB_getEntrySdfTreeCreationTime(MDB_Entry arg) */

int MDB_getEntrySdfTreeCreationTime(MDB_Entry arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 2));
}

/*}}}  */
/*{{{  MDB_Entry MDB_setEntrySdfTreeCreationTime(MDB_Entry arg, int sdfTreeCreationTime) */

MDB_Entry MDB_setEntrySdfTreeCreationTime(MDB_Entry arg, int sdfTreeCreationTime)
{
  if (MDB_isEntryDefault(arg)) {
    return (MDB_Entry)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(sdfTreeCreationTime), 2);
  }

  ATabort("Entry has no SdfTreeCreationTime: %t\n", arg);
  return (MDB_Entry)NULL;
}

/*}}}  */
/*{{{  ATbool MDB_hasEntrySdfUpdated(MDB_Entry arg) */

ATbool MDB_hasEntrySdfUpdated(MDB_Entry arg)
{
  if (MDB_isEntryDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int MDB_getEntrySdfUpdated(MDB_Entry arg) */

int MDB_getEntrySdfUpdated(MDB_Entry arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 3));
}

/*}}}  */
/*{{{  MDB_Entry MDB_setEntrySdfUpdated(MDB_Entry arg, int sdfUpdated) */

MDB_Entry MDB_setEntrySdfUpdated(MDB_Entry arg, int sdfUpdated)
{
  if (MDB_isEntryDefault(arg)) {
    return (MDB_Entry)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(sdfUpdated), 3);
  }

  ATabort("Entry has no SdfUpdated: %t\n", arg);
  return (MDB_Entry)NULL;
}

/*}}}  */
/*{{{  ATbool MDB_hasEntryAsfTree(MDB_Entry arg) */

ATbool MDB_hasEntryAsfTree(MDB_Entry arg)
{
  if (MDB_isEntryDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm MDB_getEntryAsfTree(MDB_Entry arg) */

ATerm MDB_getEntryAsfTree(MDB_Entry arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 4);
}

/*}}}  */
/*{{{  MDB_Entry MDB_setEntryAsfTree(MDB_Entry arg, ATerm asfTree) */

MDB_Entry MDB_setEntryAsfTree(MDB_Entry arg, ATerm asfTree)
{
  if (MDB_isEntryDefault(arg)) {
    return (MDB_Entry)ATsetArgument((ATermAppl)arg, (ATerm)asfTree, 4);
  }

  ATabort("Entry has no AsfTree: %t\n", arg);
  return (MDB_Entry)NULL;
}

/*}}}  */
/*{{{  ATbool MDB_hasEntryAsfText(MDB_Entry arg) */

ATbool MDB_hasEntryAsfText(MDB_Entry arg)
{
  if (MDB_isEntryDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm MDB_getEntryAsfText(MDB_Entry arg) */

ATerm MDB_getEntryAsfText(MDB_Entry arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 5);
}

/*}}}  */
/*{{{  MDB_Entry MDB_setEntryAsfText(MDB_Entry arg, ATerm asfText) */

MDB_Entry MDB_setEntryAsfText(MDB_Entry arg, ATerm asfText)
{
  if (MDB_isEntryDefault(arg)) {
    return (MDB_Entry)ATsetArgument((ATermAppl)arg, (ATerm)asfText, 5);
  }

  ATabort("Entry has no AsfText: %t\n", arg);
  return (MDB_Entry)NULL;
}

/*}}}  */
/*{{{  ATbool MDB_hasEntryAsfTreeCreationTime(MDB_Entry arg) */

ATbool MDB_hasEntryAsfTreeCreationTime(MDB_Entry arg)
{
  if (MDB_isEntryDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int MDB_getEntryAsfTreeCreationTime(MDB_Entry arg) */

int MDB_getEntryAsfTreeCreationTime(MDB_Entry arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 6));
}

/*}}}  */
/*{{{  MDB_Entry MDB_setEntryAsfTreeCreationTime(MDB_Entry arg, int asfTreeCreationTime) */

MDB_Entry MDB_setEntryAsfTreeCreationTime(MDB_Entry arg, int asfTreeCreationTime)
{
  if (MDB_isEntryDefault(arg)) {
    return (MDB_Entry)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(asfTreeCreationTime), 6);
  }

  ATabort("Entry has no AsfTreeCreationTime: %t\n", arg);
  return (MDB_Entry)NULL;
}

/*}}}  */
/*{{{  ATbool MDB_hasEntryAsfTable(MDB_Entry arg) */

ATbool MDB_hasEntryAsfTable(MDB_Entry arg)
{
  if (MDB_isEntryDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm MDB_getEntryAsfTable(MDB_Entry arg) */

ATerm MDB_getEntryAsfTable(MDB_Entry arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 7);
}

/*}}}  */
/*{{{  MDB_Entry MDB_setEntryAsfTable(MDB_Entry arg, ATerm asfTable) */

MDB_Entry MDB_setEntryAsfTable(MDB_Entry arg, ATerm asfTable)
{
  if (MDB_isEntryDefault(arg)) {
    return (MDB_Entry)ATsetArgument((ATermAppl)arg, (ATerm)asfTable, 7);
  }

  ATabort("Entry has no AsfTable: %t\n", arg);
  return (MDB_Entry)NULL;
}

/*}}}  */
/*{{{  ATbool MDB_hasEntryAsfTableCreationTime(MDB_Entry arg) */

ATbool MDB_hasEntryAsfTableCreationTime(MDB_Entry arg)
{
  if (MDB_isEntryDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int MDB_getEntryAsfTableCreationTime(MDB_Entry arg) */

int MDB_getEntryAsfTableCreationTime(MDB_Entry arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 8));
}

/*}}}  */
/*{{{  MDB_Entry MDB_setEntryAsfTableCreationTime(MDB_Entry arg, int asfTableCreationTime) */

MDB_Entry MDB_setEntryAsfTableCreationTime(MDB_Entry arg, int asfTableCreationTime)
{
  if (MDB_isEntryDefault(arg)) {
    return (MDB_Entry)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(asfTableCreationTime), 8);
  }

  ATabort("Entry has no AsfTableCreationTime: %t\n", arg);
  return (MDB_Entry)NULL;
}

/*}}}  */
/*{{{  ATbool MDB_hasEntryTrmTable(MDB_Entry arg) */

ATbool MDB_hasEntryTrmTable(MDB_Entry arg)
{
  if (MDB_isEntryDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm MDB_getEntryTrmTable(MDB_Entry arg) */

ATerm MDB_getEntryTrmTable(MDB_Entry arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 9);
}

/*}}}  */
/*{{{  MDB_Entry MDB_setEntryTrmTable(MDB_Entry arg, ATerm trmTable) */

MDB_Entry MDB_setEntryTrmTable(MDB_Entry arg, ATerm trmTable)
{
  if (MDB_isEntryDefault(arg)) {
    return (MDB_Entry)ATsetArgument((ATermAppl)arg, (ATerm)trmTable, 9);
  }

  ATabort("Entry has no TrmTable: %t\n", arg);
  return (MDB_Entry)NULL;
}

/*}}}  */
/*{{{  ATbool MDB_hasEntryTrmTableCreationTime(MDB_Entry arg) */

ATbool MDB_hasEntryTrmTableCreationTime(MDB_Entry arg)
{
  if (MDB_isEntryDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int MDB_getEntryTrmTableCreationTime(MDB_Entry arg) */

int MDB_getEntryTrmTableCreationTime(MDB_Entry arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 10));
}

/*}}}  */
/*{{{  MDB_Entry MDB_setEntryTrmTableCreationTime(MDB_Entry arg, int trmTableCreationTime) */

MDB_Entry MDB_setEntryTrmTableCreationTime(MDB_Entry arg, int trmTableCreationTime)
{
  if (MDB_isEntryDefault(arg)) {
    return (MDB_Entry)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(trmTableCreationTime), 10);
  }

  ATabort("Entry has no TrmTableCreationTime: %t\n", arg);
  return (MDB_Entry)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  MDB_Entry MDB_visitEntry(MDB_Entry arg, char * (*acceptPath)(char *), ATerm (*acceptSdfTree)(ATerm), int (*acceptSdfTreeCreationTime)(int), int (*acceptSdfUpdated)(int), ATerm (*acceptAsfTree)(ATerm), ATerm (*acceptAsfText)(ATerm), int (*acceptAsfTreeCreationTime)(int), ATerm (*acceptAsfTable)(ATerm), int (*acceptAsfTableCreationTime)(int), ATerm (*acceptTrmTable)(ATerm), int (*acceptTrmTableCreationTime)(int)) */

MDB_Entry MDB_visitEntry(MDB_Entry arg, char * (*acceptPath)(char *), ATerm (*acceptSdfTree)(ATerm), int (*acceptSdfTreeCreationTime)(int), int (*acceptSdfUpdated)(int), ATerm (*acceptAsfTree)(ATerm), ATerm (*acceptAsfText)(ATerm), int (*acceptAsfTreeCreationTime)(int), ATerm (*acceptAsfTable)(ATerm), int (*acceptAsfTableCreationTime)(int), ATerm (*acceptTrmTable)(ATerm), int (*acceptTrmTableCreationTime)(int))
{
  if (MDB_isEntryDefault(arg)) {
    return MDB_makeEntryDefault(
        acceptPath ? acceptPath(MDB_getEntryPath(arg)) : MDB_getEntryPath(arg),
        acceptSdfTree ? acceptSdfTree(MDB_getEntrySdfTree(arg)) : MDB_getEntrySdfTree(arg),
        acceptSdfTreeCreationTime ? acceptSdfTreeCreationTime(MDB_getEntrySdfTreeCreationTime(arg)) : MDB_getEntrySdfTreeCreationTime(arg),
        acceptSdfUpdated ? acceptSdfUpdated(MDB_getEntrySdfUpdated(arg)) : MDB_getEntrySdfUpdated(arg),
        acceptAsfTree ? acceptAsfTree(MDB_getEntryAsfTree(arg)) : MDB_getEntryAsfTree(arg),
        acceptAsfText ? acceptAsfText(MDB_getEntryAsfText(arg)) : MDB_getEntryAsfText(arg),
        acceptAsfTreeCreationTime ? acceptAsfTreeCreationTime(MDB_getEntryAsfTreeCreationTime(arg)) : MDB_getEntryAsfTreeCreationTime(arg),
        acceptAsfTable ? acceptAsfTable(MDB_getEntryAsfTable(arg)) : MDB_getEntryAsfTable(arg),
        acceptAsfTableCreationTime ? acceptAsfTableCreationTime(MDB_getEntryAsfTableCreationTime(arg)) : MDB_getEntryAsfTableCreationTime(arg),
        acceptTrmTable ? acceptTrmTable(MDB_getEntryTrmTable(arg)) : MDB_getEntryTrmTable(arg),
        acceptTrmTableCreationTime ? acceptTrmTableCreationTime(MDB_getEntryTrmTableCreationTime(arg)) : MDB_getEntryTrmTableCreationTime(arg));
  }
  ATabort("not a Entry: %t\n", arg);
  return (MDB_Entry)NULL;
}

/*}}}  */

/*}}}  */
