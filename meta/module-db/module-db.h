#include <atb-tool.h>
#include <string.h>
#include <AsFix.h>
#include "AsFix-access.h"
#include "aterm2.h"
#include "deprecated.h"
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#include "module-db.tif.h"

#define GetValue(db,k) (ATtableGet(db,k))
#define PutValue(db,k,v) (ATtablePut(db,k,v))
#define RemoveKey(db,k) (ATtableRemove(db,k))
#define CreateValueStore(i1,i2) (ATtableCreate(i1,i2))

#define PATH_SYN_LOC 0     /* Location to store the path to the syntax file. */
#define SYN_LOC 1          /* Tree of the syntax file. */
#define SYN_TIME_LOC 2     /* Timestamp of the syntax file. */
#define SYN_UPDATED_LOC 3  /* Is the syntax changed? */
#define PATH_EQS_LOC 4     /* Location to store the path to the equations. */
#define EQS_TREE_LOC 5     /* Tree of the equations. */
#define EQS_TEXT_LOC 6     /* Text file of the equations. */
#define EQS_TIME_LOC 7     /* Timestamp of equations file. */
#define EQS_UPDATED_LOC 8  /* Are the equations changed? */
#define TABLE_LOC 9        /* Location to store the path to the parse-table. */
#define TABLE_TIME_LOC 10  /* Location to store the timestamp of the parse-table. */
#define LOC_CNT 11         /* Number of locations in entry */

#define Mtrue (ATerm)ATmakeInt(1)
#define Mfalse (ATerm)ATmakeInt(0)
void AFinitAsFixPatterns();

extern ATerm pattern_asfix_module;
extern ATerm pattern_asfix_term;
extern ATerm pattern_asfix_imports;
extern ATerm pattern_asfix_ews;
extern ATerm pattern_asfix_ws;
extern ATerm pattern_asfix_nlws;
extern ATerm pattern_asfix_sort;
extern ATerm pattern_asfix_l;
extern ATerm pattern_asfix_ql;
extern ATerm pattern_asfix_sep;
extern ATerm pattern_asfix_iter;
extern ATerm pattern_asfix_itersep;
extern ATerm pattern_asfix_noattrs;
extern ATerm pattern_asfix_attrs;
extern ATerm pattern_asfix_prod;
extern ATerm pattern_asfix_appl;
extern ATerm pattern_asfix_list;
extern ATerm pattern_asfix_lex;
extern ATerm pattern_asfix_id;
