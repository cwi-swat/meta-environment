#ifndef _SNAPSHOT_H
#define _SNAPSHOT_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "Snapshot_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _SS_Snapshot *SS_Snapshot;
typedef struct _SS_Tables *SS_Tables;
typedef struct _SS_Table *SS_Table;
typedef struct _SS_Rows *SS_Rows;
typedef struct _SS_Row *SS_Row;

/*}}}  */

void SS_initSnapshotApi(void);

/*{{{  protect functions */

void SS_protectSnapshot(SS_Snapshot *arg);
void SS_protectTables(SS_Tables *arg);
void SS_protectTable(SS_Table *arg);
void SS_protectRows(SS_Rows *arg);
void SS_protectRow(SS_Row *arg);

/*}}}  */
/*{{{  term conversion functions */

SS_Snapshot SS_SnapshotFromTerm(ATerm t);
ATerm SS_SnapshotToTerm(SS_Snapshot arg);
SS_Tables SS_TablesFromTerm(ATerm t);
ATerm SS_TablesToTerm(SS_Tables arg);
SS_Table SS_TableFromTerm(ATerm t);
ATerm SS_TableToTerm(SS_Table arg);
SS_Rows SS_RowsFromTerm(ATerm t);
ATerm SS_RowsToTerm(SS_Rows arg);
SS_Row SS_RowFromTerm(ATerm t);
ATerm SS_RowToTerm(SS_Row arg);

/*}}}  */
/*{{{  list functions */

int SS_getTablesLength (SS_Tables arg);
SS_Tables SS_reverseTables(SS_Tables arg);
SS_Tables SS_appendTables(SS_Tables arg, SS_Table elem);
SS_Tables SS_concatTables(SS_Tables arg0, SS_Tables arg1);
SS_Tables SS_sliceTables(SS_Tables arg, int start, int end);
SS_Table SS_getTablesTableAt(SS_Tables arg, int index);
SS_Tables SS_replaceTablesTableAt(SS_Tables arg, SS_Table elem, int index);
SS_Tables SS_makeTables2(SS_Table elem1, SS_Table elem2);
SS_Tables SS_makeTables3(SS_Table elem1, SS_Table elem2, SS_Table elem3);
SS_Tables SS_makeTables4(SS_Table elem1, SS_Table elem2, SS_Table elem3, SS_Table elem4);
SS_Tables SS_makeTables5(SS_Table elem1, SS_Table elem2, SS_Table elem3, SS_Table elem4, SS_Table elem5);
SS_Tables SS_makeTables6(SS_Table elem1, SS_Table elem2, SS_Table elem3, SS_Table elem4, SS_Table elem5, SS_Table elem6);
int SS_getRowsLength (SS_Rows arg);
SS_Rows SS_reverseRows(SS_Rows arg);
SS_Rows SS_appendRows(SS_Rows arg, SS_Row elem);
SS_Rows SS_concatRows(SS_Rows arg0, SS_Rows arg1);
SS_Rows SS_sliceRows(SS_Rows arg, int start, int end);
SS_Row SS_getRowsRowAt(SS_Rows arg, int index);
SS_Rows SS_replaceRowsRowAt(SS_Rows arg, SS_Row elem, int index);
SS_Rows SS_makeRows2(SS_Row elem1, SS_Row elem2);
SS_Rows SS_makeRows3(SS_Row elem1, SS_Row elem2, SS_Row elem3);
SS_Rows SS_makeRows4(SS_Row elem1, SS_Row elem2, SS_Row elem3, SS_Row elem4);
SS_Rows SS_makeRows5(SS_Row elem1, SS_Row elem2, SS_Row elem3, SS_Row elem4, SS_Row elem5);
SS_Rows SS_makeRows6(SS_Row elem1, SS_Row elem2, SS_Row elem3, SS_Row elem4, SS_Row elem5, SS_Row elem6);

/*}}}  */
/*{{{  constructors */

SS_Snapshot SS_makeSnapshotMain(SS_Tables tables);
SS_Tables SS_makeTablesEmpty(void);
SS_Tables SS_makeTablesSingle(SS_Table head);
SS_Tables SS_makeTablesMany(SS_Table head, SS_Tables tail);
SS_Table SS_makeTableDefault(const char* name, const char* valueType, SS_Rows rows);
SS_Rows SS_makeRowsEmpty(void);
SS_Rows SS_makeRowsSingle(SS_Row head);
SS_Rows SS_makeRowsMany(SS_Row head, SS_Rows tail);
SS_Row SS_makeRowDefault(ATerm key, ATerm value);

/*}}}  */
/*{{{  equality functions */

ATbool SS_isEqualSnapshot(SS_Snapshot arg0, SS_Snapshot arg1);
ATbool SS_isEqualTables(SS_Tables arg0, SS_Tables arg1);
ATbool SS_isEqualTable(SS_Table arg0, SS_Table arg1);
ATbool SS_isEqualRows(SS_Rows arg0, SS_Rows arg1);
ATbool SS_isEqualRow(SS_Row arg0, SS_Row arg1);

/*}}}  */
/*{{{  SS_Snapshot accessors */

ATbool SS_isValidSnapshot(SS_Snapshot arg);
inline ATbool SS_isSnapshotMain(SS_Snapshot arg);
ATbool SS_hasSnapshotTables(SS_Snapshot arg);
SS_Tables SS_getSnapshotTables(SS_Snapshot arg);
SS_Snapshot SS_setSnapshotTables(SS_Snapshot arg, SS_Tables tables);

/*}}}  */
/*{{{  SS_Tables accessors */

ATbool SS_isValidTables(SS_Tables arg);
inline ATbool SS_isTablesEmpty(SS_Tables arg);
inline ATbool SS_isTablesSingle(SS_Tables arg);
inline ATbool SS_isTablesMany(SS_Tables arg);
ATbool SS_hasTablesHead(SS_Tables arg);
SS_Table SS_getTablesHead(SS_Tables arg);
SS_Tables SS_setTablesHead(SS_Tables arg, SS_Table head);
ATbool SS_hasTablesTail(SS_Tables arg);
SS_Tables SS_getTablesTail(SS_Tables arg);
SS_Tables SS_setTablesTail(SS_Tables arg, SS_Tables tail);

/*}}}  */
/*{{{  SS_Table accessors */

ATbool SS_isValidTable(SS_Table arg);
inline ATbool SS_isTableDefault(SS_Table arg);
ATbool SS_hasTableName(SS_Table arg);
char* SS_getTableName(SS_Table arg);
SS_Table SS_setTableName(SS_Table arg, const char* name);
ATbool SS_hasTableValueType(SS_Table arg);
char* SS_getTableValueType(SS_Table arg);
SS_Table SS_setTableValueType(SS_Table arg, const char* valueType);
ATbool SS_hasTableRows(SS_Table arg);
SS_Rows SS_getTableRows(SS_Table arg);
SS_Table SS_setTableRows(SS_Table arg, SS_Rows rows);

/*}}}  */
/*{{{  SS_Rows accessors */

ATbool SS_isValidRows(SS_Rows arg);
inline ATbool SS_isRowsEmpty(SS_Rows arg);
inline ATbool SS_isRowsSingle(SS_Rows arg);
inline ATbool SS_isRowsMany(SS_Rows arg);
ATbool SS_hasRowsHead(SS_Rows arg);
SS_Row SS_getRowsHead(SS_Rows arg);
SS_Rows SS_setRowsHead(SS_Rows arg, SS_Row head);
ATbool SS_hasRowsTail(SS_Rows arg);
SS_Rows SS_getRowsTail(SS_Rows arg);
SS_Rows SS_setRowsTail(SS_Rows arg, SS_Rows tail);

/*}}}  */
/*{{{  SS_Row accessors */

ATbool SS_isValidRow(SS_Row arg);
inline ATbool SS_isRowDefault(SS_Row arg);
ATbool SS_hasRowKey(SS_Row arg);
ATerm SS_getRowKey(SS_Row arg);
SS_Row SS_setRowKey(SS_Row arg, ATerm key);
ATbool SS_hasRowValue(SS_Row arg);
ATerm SS_getRowValue(SS_Row arg);
SS_Row SS_setRowValue(SS_Row arg, ATerm value);

/*}}}  */
/*{{{  sort visitors */

SS_Snapshot SS_visitSnapshot(SS_Snapshot arg, SS_Tables (*acceptTables)(SS_Tables));
SS_Tables SS_visitTables(SS_Tables arg, SS_Table (*acceptHead)(SS_Table));
SS_Table SS_visitTable(SS_Table arg, char* (*acceptName)(char*), char* (*acceptValueType)(char*), SS_Rows (*acceptRows)(SS_Rows));
SS_Rows SS_visitRows(SS_Rows arg, SS_Row (*acceptHead)(SS_Row));
SS_Row SS_visitRow(SS_Row arg, ATerm (*acceptKey)(ATerm), ATerm (*acceptValue)(ATerm));

/*}}}  */

#endif /* _SNAPSHOT_H */
