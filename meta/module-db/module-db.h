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
#include <ctype.h>

#include "module-db.tif.h"

ATerm complete_asf_sdf2_specification(ATerm module);
SDF_SDF getSyntax(ATermList modules);

ASF_CondEquationList renameParametersInEquations(PT_Tree sdfTree, ASF_CondEquationList asfEqs, SDF_Symbols actualParams);
SDF_ImportList renameParametersInImportList(SDF_ModuleName name, PT_Tree sdfTree, SDF_ImportList importList);
ASF_CondEquationList renameSymbolsInEquations(ASF_CondEquationList asfEqs, SDF_Renamings renamings);

#define GetValue(db,k) (ATtableGet(db,k))
#define PutValue(db,k,v) (ATtablePut(db,k,v))
#define RemoveKey(db,k) (ATtableRemove(db,k))
#define CreateValueStore(i1,i2) (ATtableCreate(i1,i2))

#define Mtrue (ATerm)ATmakeInt(1)
#define Mfalse (ATerm)ATmakeInt(0)
