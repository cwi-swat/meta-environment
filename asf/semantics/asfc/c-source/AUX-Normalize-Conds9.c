#include "support.h"
static asymbol * lf_AUX_Normalize_Conds9_3sym;
static aterm * lf_AUX_Normalize_Conds9_3( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_Normalize_Conds9_1sym;
static aterm * lf_AUX_Normalize_Conds9_1( aterm * arg1);
static asymbol * lf_AUX_Normalize_Conds9_2sym;
static aterm * lf_AUX_Normalize_Conds9_2( aterm * arg1);
void register_AUX_Normalize_Conds9( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Normalize_Conds9_3sym= TmkSymbol( "prod(id(\"Normalize-Conds\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Normalize_Conds9_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf_AUX_Normalize_Conds9_2sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_Normalize_Conds9_1 , lf_AUX_Normalize_Conds9_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_Normalize_Conds9_2 , lf_AUX_Normalize_Conds9_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Normalize_Conds9_3 , lf_AUX_Normalize_Conds9_3sym);
}
void resolve_AUX_Normalize_Conds9( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_Normalize_Conds9_2( aterm * arg0) {
PROF( prof_lf_AUX_Normalize_Conds9_2);
return make_nf1( lf_AUX_Normalize_Conds9_2sym , arg0);
}
aterm * lf_AUX_Normalize_Conds9_1( aterm * arg0) {
PROF( prof_lf_AUX_Normalize_Conds9_1);
return make_nf1( lf_AUX_Normalize_Conds9_1sym , arg0);
}
aterm * lf_AUX_Normalize_Conds9_3( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_Normalize_Conds9_3);
return make_nf3( lf_AUX_Normalize_Conds9_3sym , arg0 , arg1 , arg2);
}

