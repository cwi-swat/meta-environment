#include "support.h"
static asymbol * lf_AUX_RenameVars7_1sym;
static aterm * lf_AUX_RenameVars7_1( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_RenameVars7_3sym;
static aterm * lf_AUX_RenameVars7_3( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_RenameVars7_2sym;
static aterm * lf_AUX_RenameVars7_2( aterm * arg1);
static asymbol * lf_AUX_RenameVars7_4sym;
static aterm * lf_AUX_RenameVars7_4( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_RenameVars7_6sym;
static aterm * lf_AUX_RenameVars7_6( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_RenameVars7_5sym;
static aterm * lf_AUX_RenameVars7_5( aterm * arg1);
void register_AUX_RenameVars7( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_RenameVars7_1sym= TmkSymbol( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVE\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_RenameVars7_3sym= TmkSymbol( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVEs\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_RenameVars7_2sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf_AUX_RenameVars7_4sym= TmkSymbol( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVE\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_RenameVars7_6sym= TmkSymbol( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVEs\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_RenameVars7_5sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVE\"),w(\"\"),no-attrs)") , lf_AUX_RenameVars7_1 , lf_AUX_RenameVars7_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_RenameVars7_2 , lf_AUX_RenameVars7_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVEs\"),w(\"\"),no-attrs)") , lf_AUX_RenameVars7_3 , lf_AUX_RenameVars7_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVE\"),w(\"\"),no-attrs)") , lf_AUX_RenameVars7_4 , lf_AUX_RenameVars7_4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_RenameVars7_5 , lf_AUX_RenameVars7_5sym);
register_prod( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVEs\"),w(\"\"),no-attrs)") , lf_AUX_RenameVars7_6 , lf_AUX_RenameVars7_6sym);
}
void resolve_AUX_RenameVars7( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_RenameVars7_5( aterm * arg0) {
PROF( prof_lf_AUX_RenameVars7_5);
return make_nf1( lf_AUX_RenameVars7_5sym , arg0);
}
aterm * lf_AUX_RenameVars7_6( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_RenameVars7_6);
return make_nf2( lf_AUX_RenameVars7_6sym , arg0 , arg1);
}
aterm * lf_AUX_RenameVars7_4( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_RenameVars7_4);
return make_nf2( lf_AUX_RenameVars7_4sym , arg0 , arg1);
}
aterm * lf_AUX_RenameVars7_2( aterm * arg0) {
PROF( prof_lf_AUX_RenameVars7_2);
return make_nf1( lf_AUX_RenameVars7_2sym , arg0);
}
aterm * lf_AUX_RenameVars7_3( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_RenameVars7_3);
return make_nf2( lf_AUX_RenameVars7_3sym , arg0 , arg1);
}
aterm * lf_AUX_RenameVars7_1( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_RenameVars7_1);
return make_nf2( lf_AUX_RenameVars7_1sym , arg0 , arg1);
}

