#ifndef _SNAPSHOT_H
#define _SNAPSHOT_H

/*{{{  includes */

#include <aterm1.h>
#include "Snapshot_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _SS_Snapshot *SS_Snapshot;
typedef struct _SS_Tables *SS_Tables;
typedef struct _SS_Table *SS_Table;
typedef struct _SS_ValueType *SS_ValueType;
typedef struct _SS_Rows *SS_Rows;
typedef struct _SS_Row *SS_Row;

/*}}}  */

void SS_initSnapshotApi(void);

/*{{{  term conversion functions */

SS_Snapshot SS_SnapshotFromTerm(ATerm t);
ATerm SS_SnapshotToTerm(SS_Snapshot arg);
SS_Tables SS_TablesFromTerm(ATerm t);
ATerm SS_TablesToTerm(SS_Tables arg);
SS_Table SS_TableFromTerm(ATerm t);
ATerm SS_TableToTerm(SS_Table arg);
SS_ValueType SS_ValueTypeFromTerm(ATerm t);
ATerm SS_ValueTypeToTerm(SS_ValueType arg);
SS_Rows SS_RowsFromTerm(ATerm t);
ATerm SS_RowsToTerm(SS_Rows arg);
SS_Row SS_RowFromTerm(ATerm t);
ATerm SS_RowToTerm(SS_Row arg);

/*}}}  */
/*{{{  constructors */

SS_Snapshot SS_makeSnapshotMain(SS_Tables tables);
SS_Tables SS_makeTablesEmpty();
SS_Tables SS_makeTablesMany(SS_Table head, SS_Tables tail);
SS_Table SS_makeTableDefault(char* name, SS_ValueType valueType, SS_Rows tuples);
SS_ValueType SS_makeValueTypeStringType();
SS_ValueType SS_makeValueTypeTermType();
SS_Rows SS_makeRowsEmpty();
SS_Rows SS_makeRowsMany(SS_Row head, SS_Rows tail);
SS_Row SS_makeRowDefault(ATerm key, ATerm value);

/*}}}  */
/*{{{  equality functions */

ATbool SS_isEqualSnapshot(SS_Snapshot arg0, SS_Snapshot arg1);
ATbool SS_isEqualTables(SS_Tables arg0, SS_Tables arg1);
ATbool SS_isEqualTable(SS_Table arg0, SS_Table arg1);
ATbool SS_isEqualValueType(SS_ValueType arg0, SS_ValueType arg1);
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
SS_Table SS_setTableName(SS_Table arg, char* name);
ATbool SS_hasTableValueType(SS_Table arg);
SS_ValueType SS_getTableValueType(SS_Table arg);
SS_Table SS_setTableValueType(SS_Table arg, SS_ValueType valueType);
ATbool SS_hasTableTuples(SS_Table arg);
SS_Rows SS_getTableTuples(SS_Table arg);
SS_Table SS_setTableTuples(SS_Table arg, SS_Rows tuples);

/*}}}  */
/*{{{  SS_ValueType accessors */

ATbool SS_isValidValueType(SS_ValueType arg);
inline ATbool SS_isValueTypeStringType(SS_ValueType arg);
inline ATbool SS_isValueTypeTermType(SS_ValueType arg);

/*}}}  */
/*{{{  SS_Rows accessors */

ATbool SS_isValidRows(SS_Rows arg);
inline ATbool SS_isRowsEmpty(SS_Rows arg);
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
SS_Table SS_visitTable(SS_Table arg, char* (*acceptName)(char*), SS_ValueType (*acceptValueType)(SS_ValueType), SS_Rows (*acceptTuples)(SS_Rows));
SS_ValueType SS_visitValueType(SS_ValueType arg);
SS_Rows SS_visitRows(SS_Rows arg, SS_Row (*acceptHead)(SS_Row));
SS_Row SS_visitRow(SS_Row arg, ATerm (*acceptKey)(ATerm), ATerm (*acceptValue)(ATerm));

/*}}}  */

#endif /* _SNAPSHOT_H */
