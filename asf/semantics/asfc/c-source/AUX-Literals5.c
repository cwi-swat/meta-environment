#include "support.h"
static asymbol * lf_AUX_Literals5_2sym;
static aterm * lf_AUX_Literals5_2( aterm * arg1);
static asymbol * lf_AUX_Literals5_3sym;
static aterm * lf_AUX_Literals5_3( aterm * arg1);
static asymbol * lf_AUX_Literals5_1sym;
static aterm * lf_AUX_Literals5_1( aterm * arg1);
static asymbol * lf_AUX_Literals5_4sym;
static aterm * lf_AUX_Literals5_4( aterm * arg1);
void register_AUX_Literals5( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Literals5_2sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"escchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EscChar\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Literals5_3sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"l-char\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"L-Char\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Literals5_1sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf_AUX_Literals5_4sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf_AUX_Literals5_1 , lf_AUX_Literals5_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"escchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EscChar\"),w(\"\"),no-attrs)") , lf_AUX_Literals5_2 , lf_AUX_Literals5_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"l-char\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"L-Char\"),w(\"\"),no-attrs)") , lf_AUX_Literals5_3 , lf_AUX_Literals5_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)") , lf_AUX_Literals5_4 , lf_AUX_Literals5_4sym);
}
void resolve_AUX_Literals5( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_Literals5_4( aterm * arg0) {
PROF( prof_lf_AUX_Literals5_4);
return make_nf1( lf_AUX_Literals5_4sym , arg0);
}
aterm * lf_AUX_Literals5_1( aterm * arg0) {
PROF( prof_lf_AUX_Literals5_1);
return make_nf1( lf_AUX_Literals5_1sym , arg0);
}
aterm * lf_AUX_Literals5_3( aterm * arg0) {
PROF( prof_lf_AUX_Literals5_3);
return make_nf1( lf_AUX_Literals5_3sym , arg0);
}
aterm * lf_AUX_Literals5_2( aterm * arg0) {
PROF( prof_lf_AUX_Literals5_2);
return make_nf1( lf_AUX_Literals5_2sym , arg0);
}

