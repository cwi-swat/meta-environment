#include "support.h"
static Symbol lf_AUX_Make_Left_Linear5_1sym;
static ATerm lf_AUX_Make_Left_Linear5_1( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol ef1sym;
static funcptr ef1;
void register_AUX_Make_Left_Linear5( ) {
lf_AUX_Make_Left_Linear5_1sym= ATmakeSymbol( "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-l-l-lhs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"
 , 3 , ATtrue);
ATprotectSymbol( lf_AUX_Make_Left_Linear5_1sym);
register_prod( ATparse( "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-l-l-lhs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)") , lf_AUX_Make_Left_Linear5_1 , lf_AUX_Make_Left_Linear5_1sym);
}
void resolve_AUX_Make_Left_Linear5( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-l-l-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-l-l-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
}
void init_AUX_Make_Left_Linear5( ) {
}
ATerm lf_AUX_Make_Left_Linear5_1( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_Make_Left_Linear5_1);
return ( * ef1)( arg0 , arg1 , arg2);
}

