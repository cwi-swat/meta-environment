#include "support.h"
static asymbol * lf_AUX_Integers15_1sym;
static aterm * lf_AUX_Integers15_1( aterm * arg1);
static asymbol * lf_AUX_Integers15_2sym;
static aterm * lf_AUX_Integers15_2( aterm * arg1);
static asymbol * lf_AUX_Integers15_3sym;
static aterm * lf_AUX_Integers15_3( aterm * arg1);
static asymbol * lf_AUX_Integers15_4sym;
static aterm * lf_AUX_Integers15_4( aterm * arg1);
void register_AUX_Integers15( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Integers15_1sym= TmkSymbol( "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Integers15_2sym= TmkSymbol( "prod(id(\"Integers\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , SYM_STRING);
lf_AUX_Integers15_3sym= TmkSymbol( "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Integers15_4sym= TmkSymbol( "prod(id(\"Integers\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"INT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)") , lf_AUX_Integers15_1 , lf_AUX_Integers15_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))") , lf_AUX_Integers15_2 , lf_AUX_Integers15_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)") , lf_AUX_Integers15_3 , lf_AUX_Integers15_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"INT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))") , lf_AUX_Integers15_4 , lf_AUX_Integers15_4sym);
}
void resolve_AUX_Integers15( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_Integers15_4( aterm * arg0) {
PROF( prof_lf_AUX_Integers15_4);
return make_nf1( lf_AUX_Integers15_4sym , arg0);
}
aterm * lf_AUX_Integers15_3( aterm * arg0) {
PROF( prof_lf_AUX_Integers15_3);
return make_nf1( lf_AUX_Integers15_3sym , arg0);
}
aterm * lf_AUX_Integers15_2( aterm * arg0) {
PROF( prof_lf_AUX_Integers15_2);
return make_nf1( lf_AUX_Integers15_2sym , arg0);
}
aterm * lf_AUX_Integers15_1( aterm * arg0) {
PROF( prof_lf_AUX_Integers15_1);
return make_nf1( lf_AUX_Integers15_1sym , arg0);
}

