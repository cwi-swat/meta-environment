#include "support.h"
static asymbol * lf_AUX_Grammars6_1sym;
static aterm * lf_AUX_Grammars6_1( );
static asymbol * lf_AUX_Grammars6_2sym;
static aterm * lf_AUX_Grammars6_2( );
static asymbol * lf_AUX_Grammars6_3sym;
static aterm * lf_AUX_Grammars6_3( );
static asymbol * lf_AUX_Grammars6_4sym;
static aterm * lf_AUX_Grammars6_4( aterm * arg1);
static asymbol * lf_AUX_Grammars6_5sym;
static aterm * lf_AUX_Grammars6_5( aterm * arg1);
static asymbol * lf_AUX_Grammars6_6sym;
static aterm * lf_AUX_Grammars6_6( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Grammars6_7sym;
static aterm * lf_AUX_Grammars6_7( aterm * arg1);
static asymbol * lf_AUX_Grammars6_8sym;
static aterm * lf_AUX_Grammars6_8( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Grammars6_9sym;
static aterm * lf_AUX_Grammars6_9( aterm * arg1);
static asymbol * lf_AUX_Grammars6_10sym;
static aterm * lf_AUX_Grammars6_10( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Grammars6_12sym;
static aterm * lf_AUX_Grammars6_12( aterm * arg1);
static asymbol * lf_AUX_Grammars6_11sym;
static aterm * lf_AUX_Grammars6_11( aterm * arg1);
static asymbol * lf_AUX_Grammars6_13sym;
static aterm * lf_AUX_Grammars6_13( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_Grammars6_15sym;
static aterm * lf_AUX_Grammars6_15( aterm * arg1);
static asymbol * lf_AUX_Grammars6_14sym;
static aterm * lf_AUX_Grammars6_14( aterm * arg1);
static asymbol * lf_AUX_Grammars6_16sym;
static aterm * lf_AUX_Grammars6_16( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Grammars6_17sym;
static aterm * lf_AUX_Grammars6_17( );
static asymbol * lf_AUX_Grammars6_19sym;
static aterm * lf_AUX_Grammars6_19( aterm * arg1);
static asymbol * lf_AUX_Grammars6_18sym;
static aterm * lf_AUX_Grammars6_18( aterm * arg1);
void register_AUX_Grammars6( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Grammars6_1sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[ql(\"Layout\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Grammars6_2sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[ql(\"Text\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Grammars6_3sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[ql(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Grammars6_4sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Grammars6_5sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Grammars6_6sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Grammars6_7sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Grammars6_8sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Grammars6_9sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Grammars6_10sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Grammars6_12sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Grammars6_11sym= TmkSymbol( "listtype(sort(\"Symbol\"))" , SYM_STRING);
lf_AUX_Grammars6_13sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Grammars6_15sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Grammars6_14sym= TmkSymbol( "listtype(sort(\"Production\"))" , SYM_STRING);
lf_AUX_Grammars6_16sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[ql(\"lexical syntax\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"context-free syntax\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Grammars6_17sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Grammars6_19sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Grammars6_18sym= TmkSymbol( "listtype(sort(\"ATerm\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"Layout\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_1 , lf_AUX_Grammars6_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"Text\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_2 , lf_AUX_Grammars6_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_3 , lf_AUX_Grammars6_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_4 , lf_AUX_Grammars6_4sym);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_5 , lf_AUX_Grammars6_5sym);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_6 , lf_AUX_Grammars6_6sym);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_7 , lf_AUX_Grammars6_7sym);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_8 , lf_AUX_Grammars6_8sym);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_9 , lf_AUX_Grammars6_9sym);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_10 , lf_AUX_Grammars6_10sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Symbol\"))") , lf_AUX_Grammars6_11 , lf_AUX_Grammars6_11sym);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_12 , lf_AUX_Grammars6_12sym);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_13 , lf_AUX_Grammars6_13sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Production\"))") , lf_AUX_Grammars6_14 , lf_AUX_Grammars6_14sym);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_15 , lf_AUX_Grammars6_15sym);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"lexical syntax\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"context-free syntax\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_16 , lf_AUX_Grammars6_16sym);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_17 , lf_AUX_Grammars6_17sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"ATerm\"),ql(\",\"))") , lf_AUX_Grammars6_18 , lf_AUX_Grammars6_18sym);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_19 , lf_AUX_Grammars6_19sym);
}
void resolve_AUX_Grammars6( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_Grammars6_18( aterm * arg0) {
PROF( prof_lf_AUX_Grammars6_18);
return make_nf1( lf_AUX_Grammars6_18sym , arg0);
}
aterm * lf_AUX_Grammars6_19( aterm * arg0) {
PROF( prof_lf_AUX_Grammars6_19);
return make_nf1( lf_AUX_Grammars6_19sym , arg0);
}
aterm * lf_AUX_Grammars6_17( ) {
PROF( prof_lf_AUX_Grammars6_17);
return make_nf0( lf_AUX_Grammars6_17sym);
}
aterm * lf_AUX_Grammars6_16( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Grammars6_16);
return make_nf2( lf_AUX_Grammars6_16sym , arg0 , arg1);
}
aterm * lf_AUX_Grammars6_14( aterm * arg0) {
PROF( prof_lf_AUX_Grammars6_14);
return make_nf1( lf_AUX_Grammars6_14sym , arg0);
}
aterm * lf_AUX_Grammars6_15( aterm * arg0) {
PROF( prof_lf_AUX_Grammars6_15);
return make_nf1( lf_AUX_Grammars6_15sym , arg0);
}
aterm * lf_AUX_Grammars6_13( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_Grammars6_13);
return make_nf3( lf_AUX_Grammars6_13sym , arg0 , arg1 , arg2);
}
aterm * lf_AUX_Grammars6_11( aterm * arg0) {
PROF( prof_lf_AUX_Grammars6_11);
return make_nf1( lf_AUX_Grammars6_11sym , arg0);
}
aterm * lf_AUX_Grammars6_12( aterm * arg0) {
PROF( prof_lf_AUX_Grammars6_12);
return make_nf1( lf_AUX_Grammars6_12sym , arg0);
}
aterm * lf_AUX_Grammars6_10( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Grammars6_10);
return make_nf2( lf_AUX_Grammars6_10sym , arg0 , arg1);
}
aterm * lf_AUX_Grammars6_9( aterm * arg0) {
PROF( prof_lf_AUX_Grammars6_9);
return make_nf1( lf_AUX_Grammars6_9sym , arg0);
}
aterm * lf_AUX_Grammars6_8( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Grammars6_8);
return make_nf2( lf_AUX_Grammars6_8sym , arg0 , arg1);
}
aterm * lf_AUX_Grammars6_7( aterm * arg0) {
PROF( prof_lf_AUX_Grammars6_7);
return make_nf1( lf_AUX_Grammars6_7sym , arg0);
}
aterm * lf_AUX_Grammars6_6( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Grammars6_6);
return make_nf2( lf_AUX_Grammars6_6sym , arg0 , arg1);
}
aterm * lf_AUX_Grammars6_5( aterm * arg0) {
PROF( prof_lf_AUX_Grammars6_5);
return make_nf1( lf_AUX_Grammars6_5sym , arg0);
}
aterm * lf_AUX_Grammars6_4( aterm * arg0) {
PROF( prof_lf_AUX_Grammars6_4);
return make_nf1( lf_AUX_Grammars6_4sym , arg0);
}
aterm * lf_AUX_Grammars6_3( ) {
PROF( prof_lf_AUX_Grammars6_3);
return make_nf0( lf_AUX_Grammars6_3sym);
}
aterm * lf_AUX_Grammars6_2( ) {
PROF( prof_lf_AUX_Grammars6_2);
return make_nf0( lf_AUX_Grammars6_2sym);
}
aterm * lf_AUX_Grammars6_1( ) {
PROF( prof_lf_AUX_Grammars6_1);
return make_nf0( lf_AUX_Grammars6_1sym);
}

