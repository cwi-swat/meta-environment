/*
    $Id$
*/
#include <atb-tool.h>
#include <string.h>

#include <MEPT-utils.h>
#include <SDFME-utils.h>
#include <ASFME-utils.h>   
#include <aterm2.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#include "module-db.tif.h"

ATbool complete_asf_sdf2_specification(ATerm module);
SDF_SDF getSyntax(ATermList modules);

ASF_CondEquationList renameParametersInEquations(PT_Tree sdfTree, ASF_CondEquationList asfEqs, SDF_Symbols actualParams);
SDF_ImportList renameParametersInImportList(SDF_ModuleName name, PT_Tree sdfTree, SDF_ImportList importList);
ASF_CondEquationList renameSymbolsInEquations(ASF_CondEquationList asfEqs, SDF_Renamings renamings);

#define GetValue(db,k) (ATtableGet(db,k))
#define PutValue(db,k,v) (ATtablePut(db,k,v))
#define RemoveKey(db,k) (ATtableRemove(db,k))
#define CreateValueStore(i1,i2) (ATtableCreate(i1,i2))

#define PATH_SYN_LOC 0        /* Location to store the path to syntax file. */
#define SYN_LOC 1             /* Tree of the syntax file. */
#define SYN_TIME_LOC 2        /* Timestamp of the syntax file. */
#define SYN_UPDATED_LOC 3     /* Is the syntax changed? */
#define PATH_EQS_LOC 4        /* Location to store the path to the equations. */
#define EQS_TREE_LOC 5        /* Tree of the equations. */
#define EQS_TEXT_LOC 6        /* Text file of the equations. */
#define EQS_TIME_LOC 7        /* Timestamp of equations file. */
#define EQS_UPDATED_LOC 8     /* Are the equations changed? */
#define EQS_TABLE_LOC 9       /* Location to store path to equations
                               * parse-table. */
#define EQS_TABLE_TIME_LOC 10 /* Location to store timestamp of equations
                               * parse-table. */
#define TRM_TABLE_LOC 11      /* Location to store path to term parse-table. */
#define TRM_TABLE_TIME_LOC 12 /* Location to store timestamp of term 
                               * parse-table. */
#define LOC_CNT 13            /* Number of locations in entry */

#define Mtrue (ATerm)ATmakeInt(1)
#define Mfalse (ATerm)ATmakeInt(0)
