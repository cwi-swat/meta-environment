#include "support.h"
static asymbol * lf_AUX_C1_2sym;
static aterm * lf_AUX_C1_2( aterm * arg1);
static asymbol * lf_AUX_C1_3sym;
static aterm * lf_AUX_C1_3( aterm * arg1);
static asymbol * lf_AUX_C1_1sym;
static aterm * lf_AUX_C1_1( aterm * arg1);
static asymbol * lf_AUX_C1_4sym;
static aterm * lf_AUX_C1_4( aterm * arg1);
static asymbol * lf_AUX_C1_5sym;
static aterm * lf_AUX_C1_5( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_C1_6sym;
static aterm * lf_AUX_C1_6( aterm * arg1);
static asymbol * lf_AUX_C1_7sym;
static aterm * lf_AUX_C1_7( aterm * arg1);
static asymbol * lf_AUX_C1_8sym;
static aterm * lf_AUX_C1_8( aterm * arg1 , aterm * arg2);
void register_AUX_C1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_C1_2sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"cfilename\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CFilename\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_C1_3sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"cdirs\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CDirs\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_C1_1sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf_AUX_C1_4sym= TmkSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"cdir\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CDir\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_C1_5sym= TmkSymbol( "prod(id(\"C\"),w(\"\"),[sort(\"INCLUDES\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CProgram\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_C1_6sym= TmkSymbol( "prod(id(\"C\"),w(\"\"),[ql(\"#include\"),w(\"\"),sort(\"CFilename\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INCLUDE\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_C1_7sym= TmkSymbol( "prod(id(\"C\"),w(\"\"),[sort(\"INCLUDE\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INCLUDES\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_C1_8sym= TmkSymbol( "prod(id(\"C\"),w(\"\"),[sort(\"INCLUDES\"),w(\"\"),sort(\"INCLUDE\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INCLUDES\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf_AUX_C1_1 , lf_AUX_C1_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"cfilename\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CFilename\"),w(\"\"),no-attrs)") , lf_AUX_C1_2 , lf_AUX_C1_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"cdirs\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CDirs\"),w(\"\"),no-attrs)") , lf_AUX_C1_3 , lf_AUX_C1_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"cdir\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CDir\"),w(\"\"),no-attrs)") , lf_AUX_C1_4 , lf_AUX_C1_4sym);
register_prod( TmakeSimple( & local , "prod(id(\"C\"),w(\"\"),[sort(\"INCLUDES\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CProgram\"),w(\"\"),no-attrs)") , lf_AUX_C1_5 , lf_AUX_C1_5sym);
register_prod( TmakeSimple( & local , "prod(id(\"C\"),w(\"\"),[ql(\"#include\"),w(\"\"),sort(\"CFilename\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INCLUDE\"),w(\"\"),no-attrs)") , lf_AUX_C1_6 , lf_AUX_C1_6sym);
register_prod( TmakeSimple( & local , "prod(id(\"C\"),w(\"\"),[sort(\"INCLUDE\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INCLUDES\"),w(\"\"),no-attrs)") , lf_AUX_C1_7 , lf_AUX_C1_7sym);
register_prod( TmakeSimple( & local , "prod(id(\"C\"),w(\"\"),[sort(\"INCLUDES\"),w(\"\"),sort(\"INCLUDE\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INCLUDES\"),w(\"\"),no-attrs)") , lf_AUX_C1_8 , lf_AUX_C1_8sym);
}
void resolve_AUX_C1( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_C1_8( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_C1_8);
return make_nf2( lf_AUX_C1_8sym , arg0 , arg1);
}
aterm * lf_AUX_C1_7( aterm * arg0) {
PROF( prof_lf_AUX_C1_7);
return make_nf1( lf_AUX_C1_7sym , arg0);
}
aterm * lf_AUX_C1_6( aterm * arg0) {
PROF( prof_lf_AUX_C1_6);
return make_nf1( lf_AUX_C1_6sym , arg0);
}
aterm * lf_AUX_C1_5( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_C1_5);
return make_nf2( lf_AUX_C1_5sym , arg0 , arg1);
}
aterm * lf_AUX_C1_4( aterm * arg0) {
PROF( prof_lf_AUX_C1_4);
return make_nf1( lf_AUX_C1_4sym , arg0);
}
aterm * lf_AUX_C1_1( aterm * arg0) {
PROF( prof_lf_AUX_C1_1);
return make_nf1( lf_AUX_C1_1sym , arg0);
}
aterm * lf_AUX_C1_3( aterm * arg0) {
PROF( prof_lf_AUX_C1_3);
return make_nf1( lf_AUX_C1_3sym , arg0);
}
aterm * lf_AUX_C1_2( aterm * arg0) {
PROF( prof_lf_AUX_C1_2);
return make_nf1( lf_AUX_C1_2sym , arg0);
}

