#include "support.h"
static asymbol * lf_AUX_ParseTrees17_1sym;
static aterm * lf_AUX_ParseTrees17_1( );
static asymbol * lf_AUX_ParseTrees17_2sym;
static aterm * lf_AUX_ParseTrees17_2( );
static asymbol * lf_AUX_ParseTrees17_3sym;
static aterm * lf_AUX_ParseTrees17_3( );
static asymbol * lf_AUX_ParseTrees17_4sym;
static aterm * lf_AUX_ParseTrees17_4( );
static asymbol * lf_AUX_ParseTrees17_5sym;
static aterm * lf_AUX_ParseTrees17_5( );
static asymbol * lf_AUX_ParseTrees17_6sym;
static aterm * lf_AUX_ParseTrees17_6( );
static asymbol * lf_AUX_ParseTrees17_7sym;
static aterm * lf_AUX_ParseTrees17_7( );
static asymbol * lf_AUX_ParseTrees17_8sym;
static aterm * lf_AUX_ParseTrees17_8( aterm * arg1);
static asymbol * lf_AUX_ParseTrees17_9sym;
static aterm * lf_AUX_ParseTrees17_9( aterm * arg1);
void register_AUX_ParseTrees17( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_ParseTrees17_1sym= TmkSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_ParseTrees17_2sym= TmkSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ParseTrees17_3sym= TmkSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ParseTrees17_4sym= TmkSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"meta-var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ParseTrees17_5sym= TmkSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ParseTrees17_6sym= TmkSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ParseTrees17_7sym= TmkSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ParseTrees17_8sym= TmkSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ParseTrees17_9sym= TmkSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"cons2lit\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_1 , lf_AUX_ParseTrees17_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_2 , lf_AUX_ParseTrees17_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_3 , lf_AUX_ParseTrees17_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"meta-var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_4 , lf_AUX_ParseTrees17_4sym);
register_prod( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_5 , lf_AUX_ParseTrees17_5sym);
register_prod( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_6 , lf_AUX_ParseTrees17_6sym);
register_prod( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_7 , lf_AUX_ParseTrees17_7sym);
register_prod( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_8 , lf_AUX_ParseTrees17_8sym);
register_prod( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"cons2lit\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_9 , lf_AUX_ParseTrees17_9sym);
}
void resolve_AUX_ParseTrees17( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_ParseTrees17_9( aterm * arg0) {
PROF( prof_lf_AUX_ParseTrees17_9);
return make_nf1( lf_AUX_ParseTrees17_9sym , arg0);
}
aterm * lf_AUX_ParseTrees17_8( aterm * arg0) {
PROF( prof_lf_AUX_ParseTrees17_8);
return make_nf1( lf_AUX_ParseTrees17_8sym , arg0);
}
aterm * lf_AUX_ParseTrees17_7( ) {
PROF( prof_lf_AUX_ParseTrees17_7);
return make_nf0( lf_AUX_ParseTrees17_7sym);
}
aterm * lf_AUX_ParseTrees17_6( ) {
PROF( prof_lf_AUX_ParseTrees17_6);
return make_nf0( lf_AUX_ParseTrees17_6sym);
}
aterm * lf_AUX_ParseTrees17_5( ) {
PROF( prof_lf_AUX_ParseTrees17_5);
return make_nf0( lf_AUX_ParseTrees17_5sym);
}
aterm * lf_AUX_ParseTrees17_4( ) {
PROF( prof_lf_AUX_ParseTrees17_4);
return make_nf0( lf_AUX_ParseTrees17_4sym);
}
aterm * lf_AUX_ParseTrees17_3( ) {
PROF( prof_lf_AUX_ParseTrees17_3);
return make_nf0( lf_AUX_ParseTrees17_3sym);
}
aterm * lf_AUX_ParseTrees17_2( ) {
PROF( prof_lf_AUX_ParseTrees17_2);
return make_nf0( lf_AUX_ParseTrees17_2sym);
}
aterm * lf_AUX_ParseTrees17_1( ) {
PROF( prof_lf_AUX_ParseTrees17_1);
return make_nf0( lf_AUX_ParseTrees17_1sym);
}

