#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Snapshot.h"

/*{{{  conversion functions */

ATerm SS_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

char *SS_charsToString(ATerm arg)
{
  ATermList list = (ATermList) arg;
  int len = ATgetLength(list);
  int i;
  char *str;

  str = (char *) malloc(len+1);
  if (str == NULL) {
      return NULL;
  }

  for (i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    str[i] = (char) ATgetInt((ATermInt) ATgetFirst(list));
  }
  str[i] = '\0';

  return str;
}


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _SS_Snapshot;
typedef struct ATerm _SS_Tables;
typedef struct ATerm _SS_Table;
typedef struct ATerm _SS_Rows;
typedef struct ATerm _SS_Row;

/*}}}  */

/*{{{  void SS_initSnapshotApi(void) */

void SS_initSnapshotApi(void)
{
  init_Snapshot_dict();
}

/*}}}  */

/*{{{  protect functions */

void SS_protectSnapshot(SS_Snapshot *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void SS_protectTables(SS_Tables *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void SS_protectTable(SS_Table *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void SS_protectRows(SS_Rows *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void SS_protectRow(SS_Row *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  SS_Snapshot SS_SnapshotFromTerm(ATerm t) */

SS_Snapshot SS_SnapshotFromTerm(ATerm t)
{
  return (SS_Snapshot)t;
}

/*}}}  */
/*{{{  ATerm SS_SnapshotToTerm(SS_Snapshot arg) */

ATerm SS_SnapshotToTerm(SS_Snapshot arg)
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
/*{{{  list functions */

int SS_getTablesLength (SS_Tables arg) {
  return ATgetLength((ATermList) arg);
}
SS_Tables SS_reverseTables(SS_Tables arg) {
  return (SS_Tables) ATreverse((ATermList) arg);
}
SS_Tables SS_appendTables(SS_Tables arg, SS_Table elem) {
  return (SS_Tables) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
SS_Tables SS_concatTables(SS_Tables arg0, SS_Tables arg1) {
  return (SS_Tables) ATconcat((ATermList) arg0, (ATermList) arg1);
}
SS_Tables SS_sliceTables(SS_Tables arg, int start, int end) {
  return (SS_Tables) ATgetSlice((ATermList) arg, start, end);
}
SS_Table SS_getTablesTableAt(SS_Tables arg, int index) {
 return (SS_Table)ATelementAt((ATermList) arg,index);
}
SS_Tables SS_replaceTablesTableAt(SS_Tables arg, SS_Table elem, int index) {
 return (SS_Tables) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
SS_Tables SS_makeTables2(SS_Table elem1, SS_Table elem2) {
  return (SS_Tables) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
SS_Tables SS_makeTables3(SS_Table elem1, SS_Table elem2, SS_Table elem3) {
  return (SS_Tables) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
SS_Tables SS_makeTables4(SS_Table elem1, SS_Table elem2, SS_Table elem3, SS_Table elem4) {
  return (SS_Tables) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
SS_Tables SS_makeTables5(SS_Table elem1, SS_Table elem2, SS_Table elem3, SS_Table elem4, SS_Table elem5) {
  return (SS_Tables) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
SS_Tables SS_makeTables6(SS_Table elem1, SS_Table elem2, SS_Table elem3, SS_Table elem4, SS_Table elem5, SS_Table elem6) {
  return (SS_Tables) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int SS_getRowsLength (SS_Rows arg) {
  return ATgetLength((ATermList) arg);
}
SS_Rows SS_reverseRows(SS_Rows arg) {
  return (SS_Rows) ATreverse((ATermList) arg);
}
SS_Rows SS_appendRows(SS_Rows arg, SS_Row elem) {
  return (SS_Rows) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
SS_Rows SS_concatRows(SS_Rows arg0, SS_Rows arg1) {
  return (SS_Rows) ATconcat((ATermList) arg0, (ATermList) arg1);
}
SS_Rows SS_sliceRows(SS_Rows arg, int start, int end) {
  return (SS_Rows) ATgetSlice((ATermList) arg, start, end);
}
SS_Row SS_getRowsRowAt(SS_Rows arg, int index) {
 return (SS_Row)ATelementAt((ATermList) arg,index);
}
SS_Rows SS_replaceRowsRowAt(SS_Rows arg, SS_Row elem, int index) {
 return (SS_Rows) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
SS_Rows SS_makeRows2(SS_Row elem1, SS_Row elem2) {
  return (SS_Rows) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
SS_Rows SS_makeRows3(SS_Row elem1, SS_Row elem2, SS_Row elem3) {
  return (SS_Rows) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
SS_Rows SS_makeRows4(SS_Row elem1, SS_Row elem2, SS_Row elem3, SS_Row elem4) {
  return (SS_Rows) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
SS_Rows SS_makeRows5(SS_Row elem1, SS_Row elem2, SS_Row elem3, SS_Row elem4, SS_Row elem5) {
  return (SS_Rows) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
SS_Rows SS_makeRows6(SS_Row elem1, SS_Row elem2, SS_Row elem3, SS_Row elem4, SS_Row elem5, SS_Row elem6) {
  return (SS_Rows) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  SS_Snapshot SS_makeSnapshotMain(SS_Tables tables) */

SS_Snapshot SS_makeSnapshotMain(SS_Tables tables)
{
  return (SS_Snapshot)(ATerm)ATmakeAppl1(SS_afun0, (ATerm) tables);
}

/*}}}  */
/*{{{  SS_Tables SS_makeTablesEmpty(void) */

SS_Tables SS_makeTablesEmpty(void)
{
  return (SS_Tables)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SS_Tables SS_makeTablesSingle(SS_Table head) */

SS_Tables SS_makeTablesSingle(SS_Table head)
{
  return (SS_Tables)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  SS_Tables SS_makeTablesMany(SS_Table head, SS_Tables tail) */

SS_Tables SS_makeTablesMany(SS_Table head, SS_Tables tail)
{
  return (SS_Tables)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  SS_Table SS_makeTableDefault(const char* name, const char* valueType, SS_Rows rows) */

SS_Table SS_makeTableDefault(const char* name, const char* valueType, SS_Rows rows)
{
  return (SS_Table)(ATerm)ATmakeAppl3(SS_afun1, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(valueType, 0, ATtrue)), (ATerm) rows);
}

/*}}}  */
/*{{{  SS_Rows SS_makeRowsEmpty(void) */

SS_Rows SS_makeRowsEmpty(void)
{
  return (SS_Rows)(ATerm)ATempty;
}

/*}}}  */
/*{{{  SS_Rows SS_makeRowsSingle(SS_Row head) */

SS_Rows SS_makeRowsSingle(SS_Row head)
{
  return (SS_Rows)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  SS_Rows SS_makeRowsMany(SS_Row head, SS_Rows tail) */

SS_Rows SS_makeRowsMany(SS_Row head, SS_Rows tail)
{
  return (SS_Rows)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  SS_Row SS_makeRowDefault(ATerm key, ATerm value) */

SS_Row SS_makeRowDefault(ATerm key, ATerm value)
{
  return (SS_Row)(ATerm)ATmakeAppl2(SS_afun2, (ATerm) key, (ATerm) value);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool SS_isEqualSnapshot(SS_Snapshot arg0, SS_Snapshot arg1)
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

ATbool SS_isEqualRows(SS_Rows arg0, SS_Rows arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool SS_isEqualRow(SS_Row arg0, SS_Row arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  SS_Snapshot accessors */

/*{{{  ATbool SS_isValidSnapshot(SS_Snapshot arg) */

ATbool SS_isValidSnapshot(SS_Snapshot arg)
{
  if (SS_isSnapshotMain(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool SS_isSnapshotMain(SS_Snapshot arg) */

inline ATbool SS_isSnapshotMain(SS_Snapshot arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, SS_patternSnapshotMain, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool SS_hasSnapshotTables(SS_Snapshot arg) */

ATbool SS_hasSnapshotTables(SS_Snapshot arg)
{
  if (SS_isSnapshotMain(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SS_Tables SS_getSnapshotTables(SS_Snapshot arg) */

SS_Tables SS_getSnapshotTables(SS_Snapshot arg)
{
  
    return (SS_Tables)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  SS_Snapshot SS_setSnapshotTables(SS_Snapshot arg, SS_Tables tables) */

SS_Snapshot SS_setSnapshotTables(SS_Snapshot arg, SS_Tables tables)
{
  if (SS_isSnapshotMain(arg)) {
    return (SS_Snapshot)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) tables), 0);
  }

  ATabort("Snapshot has no Tables: %t\n", arg);
  return (SS_Snapshot)NULL;
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
  else if (SS_isTablesSingle(arg)) {
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
/*{{{  inline ATbool SS_isTablesSingle(SS_Tables arg) */

inline ATbool SS_isTablesSingle(SS_Tables arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SS_patternTablesSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SS_isTablesMany(SS_Tables arg) */

inline ATbool SS_isTablesMany(SS_Tables arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SS_patternTablesMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SS_hasTablesHead(SS_Tables arg) */

ATbool SS_hasTablesHead(SS_Tables arg)
{
  if (SS_isTablesSingle(arg)) {
    return ATtrue;
  }
  else if (SS_isTablesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SS_Table SS_getTablesHead(SS_Tables arg) */

SS_Table SS_getTablesHead(SS_Tables arg)
{
  if (SS_isTablesSingle(arg)) {
    return (SS_Table)ATgetFirst((ATermList)arg);
  }
  else 
    return (SS_Table)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  SS_Tables SS_setTablesHead(SS_Tables arg, SS_Table head) */

SS_Tables SS_setTablesHead(SS_Tables arg, SS_Table head)
{
  if (SS_isTablesSingle(arg)) {
    return (SS_Tables)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (SS_isTablesMany(arg)) {
    return (SS_Tables)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
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
    return (SS_Tables)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
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
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  SS_Table SS_setTableName(SS_Table arg, const char* name) */

SS_Table SS_setTableName(SS_Table arg, const char* name)
{
  if (SS_isTableDefault(arg)) {
    return (SS_Table)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
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
/*{{{  char* SS_getTableValueType(SS_Table arg) */

char* SS_getTableValueType(SS_Table arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  SS_Table SS_setTableValueType(SS_Table arg, const char* valueType) */

SS_Table SS_setTableValueType(SS_Table arg, const char* valueType)
{
  if (SS_isTableDefault(arg)) {
    return (SS_Table)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(valueType, 0, ATtrue))), 1);
  }

  ATabort("Table has no ValueType: %t\n", arg);
  return (SS_Table)NULL;
}

/*}}}  */
/*{{{  ATbool SS_hasTableRows(SS_Table arg) */

ATbool SS_hasTableRows(SS_Table arg)
{
  if (SS_isTableDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SS_Rows SS_getTableRows(SS_Table arg) */

SS_Rows SS_getTableRows(SS_Table arg)
{
  
    return (SS_Rows)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  SS_Table SS_setTableRows(SS_Table arg, SS_Rows rows) */

SS_Table SS_setTableRows(SS_Table arg, SS_Rows rows)
{
  if (SS_isTableDefault(arg)) {
    return (SS_Table)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) rows), 2);
  }

  ATabort("Table has no Rows: %t\n", arg);
  return (SS_Table)NULL;
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
  else if (SS_isRowsSingle(arg)) {
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
/*{{{  inline ATbool SS_isRowsSingle(SS_Rows arg) */

inline ATbool SS_isRowsSingle(SS_Rows arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SS_patternRowsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool SS_isRowsMany(SS_Rows arg) */

inline ATbool SS_isRowsMany(SS_Rows arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, SS_patternRowsMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool SS_hasRowsHead(SS_Rows arg) */

ATbool SS_hasRowsHead(SS_Rows arg)
{
  if (SS_isRowsSingle(arg)) {
    return ATtrue;
  }
  else if (SS_isRowsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  SS_Row SS_getRowsHead(SS_Rows arg) */

SS_Row SS_getRowsHead(SS_Rows arg)
{
  if (SS_isRowsSingle(arg)) {
    return (SS_Row)ATgetFirst((ATermList)arg);
  }
  else 
    return (SS_Row)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  SS_Rows SS_setRowsHead(SS_Rows arg, SS_Row head) */

SS_Rows SS_setRowsHead(SS_Rows arg, SS_Row head)
{
  if (SS_isRowsSingle(arg)) {
    return (SS_Rows)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (SS_isRowsMany(arg)) {
    return (SS_Rows)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
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
    return (SS_Rows)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
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
    return (SS_Row)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) key), 0);
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
    return (SS_Row)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) value), 1);
  }

  ATabort("Row has no Value: %t\n", arg);
  return (SS_Row)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  SS_Snapshot SS_visitSnapshot(SS_Snapshot arg, SS_Tables (*acceptTables)(SS_Tables)) */

SS_Snapshot SS_visitSnapshot(SS_Snapshot arg, SS_Tables (*acceptTables)(SS_Tables))
{
  if (SS_isSnapshotMain(arg)) {
    return SS_makeSnapshotMain(
        acceptTables ? acceptTables(SS_getSnapshotTables(arg)) : SS_getSnapshotTables(arg));
  }
  ATabort("not a Snapshot: %t\n", arg);
  return (SS_Snapshot)NULL;
}

/*}}}  */
/*{{{  SS_Tables SS_visitTables(SS_Tables arg, SS_Table (*acceptHead)(SS_Table)) */

SS_Tables SS_visitTables(SS_Tables arg, SS_Table (*acceptHead)(SS_Table))
{
  if (SS_isTablesEmpty(arg)) {
    return SS_makeTablesEmpty();
  }
  if (SS_isTablesSingle(arg)) {
    return SS_makeTablesSingle(
        acceptHead ? acceptHead(SS_getTablesHead(arg)) : SS_getTablesHead(arg));
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
/*{{{  SS_Table SS_visitTable(SS_Table arg, char* (*acceptName)(char*), char* (*acceptValueType)(char*), SS_Rows (*acceptRows)(SS_Rows)) */

SS_Table SS_visitTable(SS_Table arg, char* (*acceptName)(char*), char* (*acceptValueType)(char*), SS_Rows (*acceptRows)(SS_Rows))
{
  if (SS_isTableDefault(arg)) {
    return SS_makeTableDefault(
        acceptName ? acceptName(SS_getTableName(arg)) : SS_getTableName(arg),
        acceptValueType ? acceptValueType(SS_getTableValueType(arg)) : SS_getTableValueType(arg),
        acceptRows ? acceptRows(SS_getTableRows(arg)) : SS_getTableRows(arg));
  }
  ATabort("not a Table: %t\n", arg);
  return (SS_Table)NULL;
}

/*}}}  */
/*{{{  SS_Rows SS_visitRows(SS_Rows arg, SS_Row (*acceptHead)(SS_Row)) */

SS_Rows SS_visitRows(SS_Rows arg, SS_Row (*acceptHead)(SS_Row))
{
  if (SS_isRowsEmpty(arg)) {
    return SS_makeRowsEmpty();
  }
  if (SS_isRowsSingle(arg)) {
    return SS_makeRowsSingle(
        acceptHead ? acceptHead(SS_getRowsHead(arg)) : SS_getRowsHead(arg));
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
