#include "support.h"
static asymbol * lf_AUX_AsFix_Basics9_2sym;
static aterm * lf_AUX_AsFix_Basics9_2( aterm * arg1);
static asymbol * lf_AUX_AsFix_Basics9_1sym;
static aterm * lf_AUX_AsFix_Basics9_1( aterm * arg1);
void register_AUX_AsFix_Basics9( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_AsFix_Basics9_2sym= TmkSymbol( "prod(id(\"AsFix-Basics\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SortList\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_AsFix_Basics9_1sym= TmkSymbol( "listtype(sort(\"ATerm\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"ATerm\"),ql(\";\"))") , lf_AUX_AsFix_Basics9_1 , lf_AUX_AsFix_Basics9_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"AsFix-Basics\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SortList\"),w(\"\"),no-attrs)") , lf_AUX_AsFix_Basics9_2 , lf_AUX_AsFix_Basics9_2sym);
}
void resolve_AUX_AsFix_Basics9( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_AsFix_Basics9_1( aterm * arg0) {
PROF( prof_lf_AUX_AsFix_Basics9_1);
return make_nf1( lf_AUX_AsFix_Basics9_1sym , arg0);
}
aterm * lf_AUX_AsFix_Basics9_2( aterm * arg0) {
PROF( prof_lf_AUX_AsFix_Basics9_2);
return make_nf1( lf_AUX_AsFix_Basics9_2sym , arg0);
}

