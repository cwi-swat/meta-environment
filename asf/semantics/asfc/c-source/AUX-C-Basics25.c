#include "support.h"
static asymbol * lf_AUX_C_Basics25_2sym;
static aterm * lf_AUX_C_Basics25_2( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_C_Basics25_3sym;
static aterm * lf_AUX_C_Basics25_3( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_C_Basics25_1sym;
static aterm * lf_AUX_C_Basics25_1( aterm * arg1);
static asymbol * lf_AUX_C_Basics25_4sym;
static aterm * lf_AUX_C_Basics25_4( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_C_Basics25_6sym;
static aterm * lf_AUX_C_Basics25_6( aterm * arg1);
static asymbol * lf_AUX_C_Basics25_5sym;
static aterm * lf_AUX_C_Basics25_5( aterm * arg1);
static asymbol * lf_AUX_C_Basics25_7sym;
static aterm * lf_AUX_C_Basics25_7( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4);
static asymbol * lf_AUX_C_Basics25_8sym;
static aterm * lf_AUX_C_Basics25_8( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_C_Basics25_9sym;
static aterm * lf_AUX_C_Basics25_9( aterm * arg1);
static asymbol * lf_AUX_C_Basics25_10sym;
static aterm * lf_AUX_C_Basics25_10( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_C_Basics25_12sym;
static aterm * lf_AUX_C_Basics25_12( aterm * arg1);
static asymbol * lf_AUX_C_Basics25_11sym;
static aterm * lf_AUX_C_Basics25_11( aterm * arg1);
static asymbol * lf_AUX_C_Basics25_13sym;
static aterm * lf_AUX_C_Basics25_13( aterm * arg1 , aterm * arg2);
void register_AUX_C_Basics25( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_C_Basics25_2sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_C_Basics25_3sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_C_Basics25_1sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
lf_AUX_C_Basics25_4sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_C_Basics25_6sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_C_Basics25_5sym= TmkSymbol( "listtype(sort(\"TE-pair\"),ql(\",\"))" , SYM_STRING);
lf_AUX_C_Basics25_7sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DCAS-tuple\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_C_Basics25_8sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_C_Basics25_9sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_C_Basics25_10sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EI-pair\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_C_Basics25_12sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"EI-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"A-set\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_C_Basics25_11sym= TmkSymbol( "listtype(sort(\"EI-pair\"),ql(\",\"))" , SYM_STRING);
lf_AUX_C_Basics25_13sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PA-tuple\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf_AUX_C_Basics25_1 , lf_AUX_C_Basics25_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics25_2 , lf_AUX_C_Basics25_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics25_3 , lf_AUX_C_Basics25_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics25_4 , lf_AUX_C_Basics25_4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"TE-pair\"),ql(\",\"))") , lf_AUX_C_Basics25_5 , lf_AUX_C_Basics25_5sym);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics25_6 , lf_AUX_C_Basics25_6sym);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DCAS-tuple\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics25_7 , lf_AUX_C_Basics25_7sym);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics25_8 , lf_AUX_C_Basics25_8sym);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics25_9 , lf_AUX_C_Basics25_9sym);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EI-pair\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics25_10 , lf_AUX_C_Basics25_10sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"EI-pair\"),ql(\",\"))") , lf_AUX_C_Basics25_11 , lf_AUX_C_Basics25_11sym);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"EI-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"A-set\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics25_12 , lf_AUX_C_Basics25_12sym);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PA-tuple\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics25_13 , lf_AUX_C_Basics25_13sym);
}
void resolve_AUX_C_Basics25( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_C_Basics25_13( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_C_Basics25_13);
return make_nf2( lf_AUX_C_Basics25_13sym , arg0 , arg1);
}
aterm * lf_AUX_C_Basics25_11( aterm * arg0) {
PROF( prof_lf_AUX_C_Basics25_11);
return make_nf1( lf_AUX_C_Basics25_11sym , arg0);
}
aterm * lf_AUX_C_Basics25_12( aterm * arg0) {
PROF( prof_lf_AUX_C_Basics25_12);
return make_nf1( lf_AUX_C_Basics25_12sym , arg0);
}
aterm * lf_AUX_C_Basics25_10( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_C_Basics25_10);
return make_nf2( lf_AUX_C_Basics25_10sym , arg0 , arg1);
}
aterm * lf_AUX_C_Basics25_9( aterm * arg0) {
PROF( prof_lf_AUX_C_Basics25_9);
return make_nf1( lf_AUX_C_Basics25_9sym , arg0);
}
aterm * lf_AUX_C_Basics25_8( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_C_Basics25_8);
return make_nf3( lf_AUX_C_Basics25_8sym , arg0 , arg1 , arg2);
}
aterm * lf_AUX_C_Basics25_7( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3) {
PROF( prof_lf_AUX_C_Basics25_7);
return make_nf4( lf_AUX_C_Basics25_7sym , arg0 , arg1 , arg2 , arg3);
}
aterm * lf_AUX_C_Basics25_5( aterm * arg0) {
PROF( prof_lf_AUX_C_Basics25_5);
return make_nf1( lf_AUX_C_Basics25_5sym , arg0);
}
aterm * lf_AUX_C_Basics25_6( aterm * arg0) {
PROF( prof_lf_AUX_C_Basics25_6);
return make_nf1( lf_AUX_C_Basics25_6sym , arg0);
}
aterm * lf_AUX_C_Basics25_4( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_C_Basics25_4);
return make_nf2( lf_AUX_C_Basics25_4sym , arg0 , arg1);
}
aterm * lf_AUX_C_Basics25_1( aterm * arg0) {
PROF( prof_lf_AUX_C_Basics25_1);
return make_nf1( lf_AUX_C_Basics25_1sym , arg0);
}
aterm * lf_AUX_C_Basics25_3( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_C_Basics25_3);
return make_nf2( lf_AUX_C_Basics25_3sym , arg0 , arg1);
}
aterm * lf_AUX_C_Basics25_2( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_C_Basics25_2);
return make_nf3( lf_AUX_C_Basics25_2sym , arg0 , arg1 , arg2);
}

