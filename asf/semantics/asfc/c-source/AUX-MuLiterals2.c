#include "support.h"
static asymbol * lf_AUX_MuLiterals2_2sym;
static aterm * lf_AUX_MuLiterals2_2( aterm * arg1);
static asymbol * lf_AUX_MuLiterals2_3sym;
static aterm * lf_AUX_MuLiterals2_3( aterm * arg1);
static asymbol * lf_AUX_MuLiterals2_4sym;
static aterm * lf_AUX_MuLiterals2_4( aterm * arg1);
static asymbol * lf_AUX_MuLiterals2_5sym;
static aterm * lf_AUX_MuLiterals2_5( aterm * arg1);
static asymbol * lf_AUX_MuLiterals2_6sym;
static aterm * lf_AUX_MuLiterals2_6( aterm * arg1);
static asymbol * lf_AUX_MuLiterals2_1sym;
static aterm * lf_AUX_MuLiterals2_1( aterm * arg1);
static asymbol * lf_AUX_MuLiterals2_7sym;
static aterm * lf_AUX_MuLiterals2_7( aterm * arg1);
void register_AUX_MuLiterals2( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuLiterals2_2sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"escchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EscChar\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_MuLiterals2_3sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"qchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"QChar\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_MuLiterals2_4sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_MuLiterals2_5sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"varid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_MuLiterals2_6sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"modid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModId\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_MuLiterals2_1sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf_AUX_MuLiterals2_7sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"propid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PropId\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf_AUX_MuLiterals2_1 , lf_AUX_MuLiterals2_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"escchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EscChar\"),w(\"\"),no-attrs)") , lf_AUX_MuLiterals2_2 , lf_AUX_MuLiterals2_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"qchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"QChar\"),w(\"\"),no-attrs)") , lf_AUX_MuLiterals2_3 , lf_AUX_MuLiterals2_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)") , lf_AUX_MuLiterals2_4 , lf_AUX_MuLiterals2_4sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"varid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)") , lf_AUX_MuLiterals2_5 , lf_AUX_MuLiterals2_5sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"modid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModId\"),w(\"\"),no-attrs)") , lf_AUX_MuLiterals2_6 , lf_AUX_MuLiterals2_6sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"propid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PropId\"),w(\"\"),no-attrs)") , lf_AUX_MuLiterals2_7 , lf_AUX_MuLiterals2_7sym);
}
void resolve_AUX_MuLiterals2( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_MuLiterals2_7( aterm * arg0) {
PROF( prof_lf_AUX_MuLiterals2_7);
return make_nf1( lf_AUX_MuLiterals2_7sym , arg0);
}
aterm * lf_AUX_MuLiterals2_1( aterm * arg0) {
PROF( prof_lf_AUX_MuLiterals2_1);
return make_nf1( lf_AUX_MuLiterals2_1sym , arg0);
}
aterm * lf_AUX_MuLiterals2_6( aterm * arg0) {
PROF( prof_lf_AUX_MuLiterals2_6);
return make_nf1( lf_AUX_MuLiterals2_6sym , arg0);
}
aterm * lf_AUX_MuLiterals2_5( aterm * arg0) {
PROF( prof_lf_AUX_MuLiterals2_5);
return make_nf1( lf_AUX_MuLiterals2_5sym , arg0);
}
aterm * lf_AUX_MuLiterals2_4( aterm * arg0) {
PROF( prof_lf_AUX_MuLiterals2_4);
return make_nf1( lf_AUX_MuLiterals2_4sym , arg0);
}
aterm * lf_AUX_MuLiterals2_3( aterm * arg0) {
PROF( prof_lf_AUX_MuLiterals2_3);
return make_nf1( lf_AUX_MuLiterals2_3sym , arg0);
}
aterm * lf_AUX_MuLiterals2_2( aterm * arg0) {
PROF( prof_lf_AUX_MuLiterals2_2);
return make_nf1( lf_AUX_MuLiterals2_2sym , arg0);
}

