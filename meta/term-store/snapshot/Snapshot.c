#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Snapshot.h"

/*{{{  typedefs */

typedef struct ATerm _SS_TermStore;
typedef struct ATerm _SS_Tables;
typedef struct ATerm _SS_Table;
typedef struct ATerm _SS_ValueType;
typedef struct ATerm _SS_Rows;
typedef struct ATerm _SS_Row;

/*}}}  */

/*{{{  void SS_initSnapshotApi(void) */

void SS_initSnapshotApi(void)
{
  init_Snapshot_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  SS_TermStore SS_TermStoreFromTerm(ATerm t) */

SS_TermStore SS_TermStoreFromTerm(ATerm t)
{
  return (SS_TermStore)t;
}

/*}}}  */
/*{{{  ATerm SS_TermStoreToTerm(SS_TermStore arg) */

ATerm SS_TermStoreToTerm(SS_TermStore arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SS_Tables SS_TablesFromTerm(ATerm t) */

SS_Tables SS_TablesFromTerm(ATerm t)
{
  return (SS_Tables)t;
}

/*}}}  */
/*{{{  ATerm SS_TablesToTerm(SS_Tables arg) */

ATerm SS_TablesToTerm(SS_Tables arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SS_Table SS_TableFromTerm(ATerm t) */

SS_Table SS_TableFromTerm(ATerm t)
{
  return (SS_Table)t;
}

/*}}}  */
/*{{{  ATerm SS_TableToTerm(SS_Table arg) */

ATerm SS_TableToTerm(SS_Table arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SS_ValueType SS_ValueTypeFromTerm(ATerm t) */

SS_ValueType SS_ValueTypeFromTerm(ATerm t)
{
  return (SS_ValueType)t;
}

/*}}}  */
/*{{{  ATerm SS_ValueTypeToTerm(SS_ValueType arg) */

ATerm SS_ValueTypeToTerm(SS_ValueType arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SS_Rows SS_RowsFromTerm(ATerm t) */

SS_Rows SS_RowsFromTerm(ATerm t)
{
  return (SS_Rows)t;
}

/*}}}  */
/*{{{  ATerm SS_RowsToTerm(SS_Rows arg) */

ATerm SS_RowsToTerm(SS_Rows arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  SS_Row SS_RowFromTerm(ATerm t) */

SS_Row SS_RowFromTerm(ATerm t)
{
  return (SS_Row)t;
}

/*}}}  */
/*{{{  ATerm SS_RowToTerm(SS_Row arg) */

ATerm SS_RowToTerm(SS_Row arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  SS_TermStore SS_makeTermStoreMain(SS_Tables tables) */

SS_TermStore SS_makeTermStoreMain(SS_Tables tables)
{
  return (SS_TermStore)(ATerm)ATmakeAppl1(SS_afun0, (ATerm)tables);
}

/*}}}  */
/*{{{  SS_Tables SS_makeTablesEmpty() */

SS_Tables SS_makeTablesEmpty()
{
  return (SS_Tables)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SS_Tables SS_makeTablesMany(SS_Table head, SS_Tables tail) */

SS_Tables SS_makeTablesMany(SS_Table head, SS_Tables tail)
{
  return (SS_Tables)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  SS_Table SS_makeTableDefault(char* name, SS_ValueType valueType, SS_Rows tuples) */

SS_Table SS_makeTableDefault(char* name, SS_ValueType valueType, SS_Rows tuples)
{
  return (SS_Table)(ATerm)ATmakeAppl3(SS_afun1, (ATerm)ATmakeAppl0(ATmakeAFun(name, 0, ATtrue)), (ATerm)valueType, (ATerm)tuples);
}

/*}}}  */
/*{{{  SS_ValueType SS_makeValueTypeStringType() */

SS_ValueType SS_makeValueTypeStringType()
{
  return (SS_ValueType)(ATerm)ATmakeAppl0(SS_afun2);
}

/*}}}  */
/*{{{  SS_ValueType SS_makeValueTypeTermType() */

SS_ValueType SS_makeValueTypeTermType()
{
  return (SS_ValueType)(ATerm)ATmakeAppl0(SS_afun3);
}

/*}}}  */
/*{{{  SS_Rows SS_makeRowsEmpty() */

SS_Rows SS_makeRowsEmpty()
{
  return (SS_Rows)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SS_Rows SS_makeRowsMany(SS_Row head, SS_Rows tail) */

SS_Rows SS_makeRowsMany(SS_Row head, SS_Rows tail)
{
  return (SS_Rows)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  SS_Row SS_makeRowDefault(ATerm key, ATerm value) */

SS_Row SS_makeRowDefault(ATerm key, ATerm value)
{
  return (SS_Row)(ATerm)ATmakeAppl2(SS_afun4, (ATerm)key, (ATerm)value);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool SS_isEqualTermStore(SS_TermStore arg0, SS_TermStore arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SS_isEqualTables(SS_Tables arg0, SS_Tables arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SS_isEqualTable(SS_Table arg0, SS_Table arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SS_isEqualValueType(SS_ValueType arg0, SS_ValueType arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SS_isEqualRows(SS_Rows arg0, SS_Rows arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SS_isEqualRow(SS_Row arg0, SS_Row arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  SS_TermStore accessors */

/*{{{  ATbool SS_isValidTermStore(SS_TermStore arg) */

ATbool SS_isValidTermStore(SS_TermStore arg)
{
  if (SS_isTermStoreMain(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SS_isTermStoreMain(SS_TermStore arg) */

inline ATbool SS_isTermStoreMain(SS_TermStore arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SS_patternTermStoreMain, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool SS_hasTermStoreTables(SS_TermStore arg) */

ATbool SS_hasTermStoreTables(SS_TermStore arg)
{
  if (SS_isTermStoreMain(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SS_Tables SS_getTermStoreTables(SS_TermStore arg) */

SS_Tables SS_getTermStoreTables(SS_TermStore arg)
{
  
    return (SS_Tables)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  SS_TermStore SS_setTermStoreTables(SS_TermStore arg, SS_Tables tables) */

SS_TermStore SS_setTermStoreTables(SS_TermStore arg, SS_Tables tables)
{
  if (SS_isTermStoreMain(arg)) {
    return (SS_TermStore)ATsetArgument((ATermAppl)arg, (ATerm)tables, 0);
  }

  ATabort("TermStore has no Tables: %t\n", arg);
  return (SS_TermStore)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SS_Tables accessors */

/*{{{  ATbool SS_isValidTables(SS_Tables arg) */

ATbool SS_isValidTables(SS_Tables arg)
{
  if (SS_isTablesEmpty(arg)) {
    return ATtrue;
  }
  else if (SS_isTablesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SS_isTablesEmpty(SS_Tables arg) */

inline ATbool SS_isTablesEmpty(SS_Tables arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SS_patternTablesEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SS_isTablesMany(SS_Tables arg) */

inline ATbool SS_isTablesMany(SS_Tables arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SS_patternTablesMany, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool SS_hasTablesHead(SS_Tables arg) */

ATbool SS_hasTablesHead(SS_Tables arg)
{
  if (SS_isTablesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SS_Table SS_getTablesHead(SS_Tables arg) */

SS_Table SS_getTablesHead(SS_Tables arg)
{
  
    return (SS_Table)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  SS_Tables SS_setTablesHead(SS_Tables arg, SS_Table head) */

SS_Tables SS_setTablesHead(SS_Tables arg, SS_Table head)
{
  if (SS_isTablesMany(arg)) {
    return (SS_Tables)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Tables has no Head: %t\n", arg);
  return (SS_Tables)NULL;
}

/*}}}  */
/*{{{  ATbool SS_hasTablesTail(SS_Tables arg) */

ATbool SS_hasTablesTail(SS_Tables arg)
{
  if (SS_isTablesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SS_Tables SS_getTablesTail(SS_Tables arg) */

SS_Tables SS_getTablesTail(SS_Tables arg)
{
  
    return (SS_Tables)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  SS_Tables SS_setTablesTail(SS_Tables arg, SS_Tables tail) */

SS_Tables SS_setTablesTail(SS_Tables arg, SS_Tables tail)
{
  if (SS_isTablesMany(arg)) {
    return (SS_Tables)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("Tables has no Tail: %t\n", arg);
  return (SS_Tables)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SS_Table accessors */

/*{{{  ATbool SS_isValidTable(SS_Table arg) */

ATbool SS_isValidTable(SS_Table arg)
{
  if (SS_isTableDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SS_isTableDefault(SS_Table arg) */

inline ATbool SS_isTableDefault(SS_Table arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SS_patternTableDefault, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool SS_hasTableName(SS_Table arg) */

ATbool SS_hasTableName(SS_Table arg)
{
  if (SS_isTableDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* SS_getTableName(SS_Table arg) */

char* SS_getTableName(SS_Table arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  SS_Table SS_setTableName(SS_Table arg, char* name) */

SS_Table SS_setTableName(SS_Table arg, char* name)
{
  if (SS_isTableDefault(arg)) {
    return (SS_Table)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(name, 0, ATtrue)), 0);
  }

  ATabort("Table has no Name: %t\n", arg);
  return (SS_Table)NULL;
}

/*}}}  */
/*{{{  ATbool SS_hasTableValueType(SS_Table arg) */

ATbool SS_hasTableValueType(SS_Table arg)
{
  if (SS_isTableDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SS_ValueType SS_getTableValueType(SS_Table arg) */

SS_ValueType SS_getTableValueType(SS_Table arg)
{
  
    return (SS_ValueType)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  SS_Table SS_setTableValueType(SS_Table arg, SS_ValueType valueType) */

SS_Table SS_setTableValueType(SS_Table arg, SS_ValueType valueType)
{
  if (SS_isTableDefault(arg)) {
    return (SS_Table)ATsetArgument((ATermAppl)arg, (ATerm)valueType, 1);
  }

  ATabort("Table has no ValueType: %t\n", arg);
  return (SS_Table)NULL;
}

/*}}}  */
/*{{{  ATbool SS_hasTableTuples(SS_Table arg) */

ATbool SS_hasTableTuples(SS_Table arg)
{
  if (SS_isTableDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SS_Rows SS_getTableTuples(SS_Table arg) */

SS_Rows SS_getTableTuples(SS_Table arg)
{
  
    return (SS_Rows)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  SS_Table SS_setTableTuples(SS_Table arg, SS_Rows tuples) */

SS_Table SS_setTableTuples(SS_Table arg, SS_Rows tuples)
{
  if (SS_isTableDefault(arg)) {
    return (SS_Table)ATsetArgument((ATermAppl)arg, (ATerm)tuples, 2);
  }

  ATabort("Table has no Tuples: %t\n", arg);
  return (SS_Table)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SS_ValueType accessors */

/*{{{  ATbool SS_isValidValueType(SS_ValueType arg) */

ATbool SS_isValidValueType(SS_ValueType arg)
{
  if (SS_isValueTypeStringType(arg)) {
    return ATtrue;
  }
  else if (SS_isValueTypeTermType(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SS_isValueTypeStringType(SS_ValueType arg) */

inline ATbool SS_isValueTypeStringType(SS_ValueType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SS_patternValueTypeStringType);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SS_isValueTypeTermType(SS_ValueType arg) */

inline ATbool SS_isValueTypeTermType(SS_ValueType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SS_patternValueTypeTermType);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  SS_Rows accessors */

/*{{{  ATbool SS_isValidRows(SS_Rows arg) */

ATbool SS_isValidRows(SS_Rows arg)
{
  if (SS_isRowsEmpty(arg)) {
    return ATtrue;
  }
  else if (SS_isRowsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SS_isRowsEmpty(SS_Rows arg) */

inline ATbool SS_isRowsEmpty(SS_Rows arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SS_patternRowsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool SS_isRowsMany(SS_Rows arg) */

inline ATbool SS_isRowsMany(SS_Rows arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SS_patternRowsMany, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool SS_hasRowsHead(SS_Rows arg) */

ATbool SS_hasRowsHead(SS_Rows arg)
{
  if (SS_isRowsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SS_Row SS_getRowsHead(SS_Rows arg) */

SS_Row SS_getRowsHead(SS_Rows arg)
{
  
    return (SS_Row)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  SS_Rows SS_setRowsHead(SS_Rows arg, SS_Row head) */

SS_Rows SS_setRowsHead(SS_Rows arg, SS_Row head)
{
  if (SS_isRowsMany(arg)) {
    return (SS_Rows)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Rows has no Head: %t\n", arg);
  return (SS_Rows)NULL;
}

/*}}}  */
/*{{{  ATbool SS_hasRowsTail(SS_Rows arg) */

ATbool SS_hasRowsTail(SS_Rows arg)
{
  if (SS_isRowsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SS_Rows SS_getRowsTail(SS_Rows arg) */

SS_Rows SS_getRowsTail(SS_Rows arg)
{
  
    return (SS_Rows)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  SS_Rows SS_setRowsTail(SS_Rows arg, SS_Rows tail) */

SS_Rows SS_setRowsTail(SS_Rows arg, SS_Rows tail)
{
  if (SS_isRowsMany(arg)) {
    return (SS_Rows)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("Rows has no Tail: %t\n", arg);
  return (SS_Rows)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  SS_Row accessors */

/*{{{  ATbool SS_isValidRow(SS_Row arg) */

ATbool SS_isValidRow(SS_Row arg)
{
  if (SS_isRowDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SS_isRowDefault(SS_Row arg) */

inline ATbool SS_isRowDefault(SS_Row arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SS_patternRowDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool SS_hasRowKey(SS_Row arg) */

ATbool SS_hasRowKey(SS_Row arg)
{
  if (SS_isRowDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm SS_getRowKey(SS_Row arg) */

ATerm SS_getRowKey(SS_Row arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  SS_Row SS_setRowKey(SS_Row arg, ATerm key) */

SS_Row SS_setRowKey(SS_Row arg, ATerm key)
{
  if (SS_isRowDefault(arg)) {
    return (SS_Row)ATsetArgument((ATermAppl)arg, (ATerm)key, 0);
  }

  ATabort("Row has no Key: %t\n", arg);
  return (SS_Row)NULL;
}

/*}}}  */
/*{{{  ATbool SS_hasRowValue(SS_Row arg) */

ATbool SS_hasRowValue(SS_Row arg)
{
  if (SS_isRowDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm SS_getRowValue(SS_Row arg) */

ATerm SS_getRowValue(SS_Row arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  SS_Row SS_setRowValue(SS_Row arg, ATerm value) */

SS_Row SS_setRowValue(SS_Row arg, ATerm value)
{
  if (SS_isRowDefault(arg)) {
    return (SS_Row)ATsetArgument((ATermAppl)arg, (ATerm)value, 1);
  }

  ATabort("Row has no Value: %t\n", arg);
  return (SS_Row)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  SS_TermStore SS_visitTermStore(SS_TermStore arg, SS_Tables (*acceptTables)(SS_Tables)) */

SS_TermStore SS_visitTermStore(SS_TermStore arg, SS_Tables (*acceptTables)(SS_Tables))
{
  if (SS_isTermStoreMain(arg)) {
    return SS_makeTermStoreMain(
        acceptTables ? acceptTables(SS_getTermStoreTables(arg)) : SS_getTermStoreTables(arg));
  }
  ATabort("not a TermStore: %t\n", arg);
  return (SS_TermStore)NULL;
}

/*}}}  */
/*{{{  SS_Tables SS_visitTables(SS_Tables arg, SS_Table (*acceptHead)(SS_Table)) */

SS_Tables SS_visitTables(SS_Tables arg, SS_Table (*acceptHead)(SS_Table))
{
  if (SS_isTablesEmpty(arg)) {
    return SS_makeTablesEmpty();
  }
  if (SS_isTablesMany(arg)) {
    return SS_makeTablesMany(
        acceptHead ? acceptHead(SS_getTablesHead(arg)) : SS_getTablesHead(arg),
        SS_visitTables(SS_getTablesTail(arg), acceptHead));
  }
  ATabort("not a Tables: %t\n", arg);
  return (SS_Tables)NULL;
}

/*}}}  */
/*{{{  SS_Table SS_visitTable(SS_Table arg, char* (*acceptName)(char*), SS_ValueType (*acceptValueType)(SS_ValueType), SS_Rows (*acceptTuples)(SS_Rows)) */

SS_Table SS_visitTable(SS_Table arg, char* (*acceptName)(char*), SS_ValueType (*acceptValueType)(SS_ValueType), SS_Rows (*acceptTuples)(SS_Rows))
{
  if (SS_isTableDefault(arg)) {
    return SS_makeTableDefault(
        acceptName ? acceptName(SS_getTableName(arg)) : SS_getTableName(arg),
        acceptValueType ? acceptValueType(SS_getTableValueType(arg)) : SS_getTableValueType(arg),
        acceptTuples ? acceptTuples(SS_getTableTuples(arg)) : SS_getTableTuples(arg));
  }
  ATabort("not a Table: %t\n", arg);
  return (SS_Table)NULL;
}

/*}}}  */
/*{{{  SS_ValueType SS_visitValueType(SS_ValueType arg) */

SS_ValueType SS_visitValueType(SS_ValueType arg)
{
  if (SS_isValueTypeStringType(arg)) {
    return SS_makeValueTypeStringType();
  }
  if (SS_isValueTypeTermType(arg)) {
    return SS_makeValueTypeTermType();
  }
  ATabort("not a ValueType: %t\n", arg);
  return (SS_ValueType)NULL;
}

/*}}}  */
/*{{{  SS_Rows SS_visitRows(SS_Rows arg, SS_Row (*acceptHead)(SS_Row)) */

SS_Rows SS_visitRows(SS_Rows arg, SS_Row (*acceptHead)(SS_Row))
{
  if (SS_isRowsEmpty(arg)) {
    return SS_makeRowsEmpty();
  }
  if (SS_isRowsMany(arg)) {
    return SS_makeRowsMany(
        acceptHead ? acceptHead(SS_getRowsHead(arg)) : SS_getRowsHead(arg),
        SS_visitRows(SS_getRowsTail(arg), acceptHead));
  }
  ATabort("not a Rows: %t\n", arg);
  return (SS_Rows)NULL;
}

/*}}}  */
/*{{{  SS_Row SS_visitRow(SS_Row arg, ATerm (*acceptKey)(ATerm), ATerm (*acceptValue)(ATerm)) */

SS_Row SS_visitRow(SS_Row arg, ATerm (*acceptKey)(ATerm), ATerm (*acceptValue)(ATerm))
{
  if (SS_isRowDefault(arg)) {
    return SS_makeRowDefault(
        acceptKey ? acceptKey(SS_getRowKey(arg)) : SS_getRowKey(arg),
        acceptValue ? acceptValue(SS_getRowValue(arg)) : SS_getRowValue(arg));
  }
  ATabort("not a Row: %t\n", arg);
  return (SS_Row)NULL;
}

/*}}}  */

/*}}}  */
