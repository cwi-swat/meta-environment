#include <atb-tool.h>
#include <string.h>
#include <AsFix.h>
#include "aterm2.h"
#include "deprecated.h"
#include <stdlib.h>
#include <limits.h>

#include "module-db.tif.h"

#define GetValue(db,k) (ATtableGet(db,k))
#define PutValue(db,k,v) (ATtablePut(db,k,v))
#define RemoveKey(db,k) (ATtableRemove(db,k))
#define CreateValueStore(i1,i2) (ATtableCreate(i1,i2))

void AFinitAsFixPatterns();

extern ATerm pattern_asfix_module;
extern ATerm pattern_asfix_imports;
extern ATerm pattern_asfix_nlws;
extern ATerm pattern_asfix_sort;
extern ATerm pattern_asfix_l;
extern ATerm pattern_asfix_ql;
extern ATerm pattern_asfix_iter;
extern ATerm pattern_asfix_itersep;
extern ATerm pattern_asfix_noattrs;
extern ATerm pattern_asfix_attrs;
extern ATerm pattern_asfix_prod;
extern ATerm pattern_asfix_id;
