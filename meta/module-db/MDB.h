#ifndef _MDB_H
#define _MDB_H

/*{{{  includes */

#include <aterm1.h>
#include "MDB_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _MDB_Entry *MDB_Entry;

/*}}}  */

void MDB_initMDBApi(void);

/*{{{  term conversion functions */

MDB_Entry MDB_EntryFromTerm(ATerm t);
ATerm MDB_EntryToTerm(MDB_Entry arg);

/*}}}  */
/*{{{  constructors */

MDB_Entry MDB_makeEntryDefault(char * path, ATerm sdfTree, int sdfTreeCreationTime, ATerm asfTree, ATerm asfText, int asfTreeCreationTime, ATerm asfTable, int asfTableCreationTime, ATerm trmTable, int trmTableCreationTime);

/*}}}  */
/*{{{  equality functions */

ATbool MDB_isEqualEntry(MDB_Entry arg0, MDB_Entry arg1);

/*}}}  */
/*{{{  MDB_Entry accessors */

ATbool MDB_isValidEntry(MDB_Entry arg);
inline ATbool MDB_isEntryDefault(MDB_Entry arg);
ATbool MDB_hasEntryPath(MDB_Entry arg);
char * MDB_getEntryPath(MDB_Entry arg);
MDB_Entry MDB_setEntryPath(MDB_Entry arg, char * path);
ATbool MDB_hasEntrySdfTree(MDB_Entry arg);
ATerm MDB_getEntrySdfTree(MDB_Entry arg);
MDB_Entry MDB_setEntrySdfTree(MDB_Entry arg, ATerm sdfTree);
ATbool MDB_hasEntrySdfTreeCreationTime(MDB_Entry arg);
int MDB_getEntrySdfTreeCreationTime(MDB_Entry arg);
MDB_Entry MDB_setEntrySdfTreeCreationTime(MDB_Entry arg, int sdfTreeCreationTime);
ATbool MDB_hasEntryAsfTree(MDB_Entry arg);
ATerm MDB_getEntryAsfTree(MDB_Entry arg);
MDB_Entry MDB_setEntryAsfTree(MDB_Entry arg, ATerm asfTree);
ATbool MDB_hasEntryAsfText(MDB_Entry arg);
ATerm MDB_getEntryAsfText(MDB_Entry arg);
MDB_Entry MDB_setEntryAsfText(MDB_Entry arg, ATerm asfText);
ATbool MDB_hasEntryAsfTreeCreationTime(MDB_Entry arg);
int MDB_getEntryAsfTreeCreationTime(MDB_Entry arg);
MDB_Entry MDB_setEntryAsfTreeCreationTime(MDB_Entry arg, int asfTreeCreationTime);
ATbool MDB_hasEntryAsfTable(MDB_Entry arg);
ATerm MDB_getEntryAsfTable(MDB_Entry arg);
MDB_Entry MDB_setEntryAsfTable(MDB_Entry arg, ATerm asfTable);
ATbool MDB_hasEntryAsfTableCreationTime(MDB_Entry arg);
int MDB_getEntryAsfTableCreationTime(MDB_Entry arg);
MDB_Entry MDB_setEntryAsfTableCreationTime(MDB_Entry arg, int asfTableCreationTime);
ATbool MDB_hasEntryTrmTable(MDB_Entry arg);
ATerm MDB_getEntryTrmTable(MDB_Entry arg);
MDB_Entry MDB_setEntryTrmTable(MDB_Entry arg, ATerm trmTable);
ATbool MDB_hasEntryTrmTableCreationTime(MDB_Entry arg);
int MDB_getEntryTrmTableCreationTime(MDB_Entry arg);
MDB_Entry MDB_setEntryTrmTableCreationTime(MDB_Entry arg, int trmTableCreationTime);

/*}}}  */
/*{{{  sort visitors */

MDB_Entry MDB_visitEntry(MDB_Entry arg, char * (*acceptPath)(char *), ATerm (*acceptSdfTree)(ATerm), int (*acceptSdfTreeCreationTime)(int), ATerm (*acceptAsfTree)(ATerm), ATerm (*acceptAsfText)(ATerm), int (*acceptAsfTreeCreationTime)(int), ATerm (*acceptAsfTable)(ATerm), int (*acceptAsfTableCreationTime)(int), ATerm (*acceptTrmTable)(ATerm), int (*acceptTrmTableCreationTime)(int));

/*}}}  */

#endif /* _MDB_H */
