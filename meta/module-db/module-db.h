#include <atb-tool.h>
#include <string.h>
#include <AsFix.h>
#include "AsFix-access.h"
#include "aterm2.h"
#include "deprecated.h"
#include <stdlib.h>
#include <limits.h>

#include "module-db.tif.h"

#define GetValue(db,k) (ATtableGet(db,k))
#define PutValue(db,k,v) (ATtablePut(db,k,v))
#define RemoveKey(db,k) (ATtableRemove(db,k))
#define CreateValueStore(i1,i2) (ATtableCreate(i1,i2))

#define path_syn_loc 0    /* Location to store the path to the syntax file. */
#define syn_loc 1         /* Baf file of the syntax file. */
#define syn_updated_loc 2 /* Is the syntax changed? */
#define path_eqs_loc 3    /* Location to store the path to the equations. */
#define eqs_loc 4         /* Baf file of the equations. */
#define eqs_updated_loc 5 /* Are the equations changed? */
#define table_loc 6       /* Location to store the path to the parse-table. */

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
