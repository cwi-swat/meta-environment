#include  "asc-support.h"
static Symbol lf_AUX_Grammar_Projection2_1sym ;
static ATerm lf_AUX_Grammar_Projection2_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_Grammar_Projection2 ( ) {
lf_AUX_Grammar_Projection2_1sym = ATmakeSymbol ( "prod(id(\"Grammar-Projection\"),w(\"\"),[ql(\"if\"),w(\"\"),sort(\"Bool\"),w(\"\"),ql(\"then\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"else\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"fi\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"delaying2\"),w(\"\"),sep(\",\"),w(\"\"),l(\"delaying3\")],w(\"\"),l(\"}\")))"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Grammar_Projection2_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Grammar-Projection\"),w(\"\"),[ql(\"if\"),w(\"\"),sort(\"Bool\"),w(\"\"),ql(\"then\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"else\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"fi\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"delaying2\"),w(\"\"),sep(\",\"),w(\"\"),l(\"delaying3\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Grammar_Projection2_1 , lf_AUX_Grammar_Projection2_1sym ) ;
}
void resolve_AUX_Grammar_Projection2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Grammar_Projection2 ( ) {
}
ATerm lf_AUX_Grammar_Projection2_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
FUNC_ENTRY ( lf_AUX_Grammar_Projection2_1sym , ATmakeAppl ( lf_AUX_Grammar_Projection2_1sym , arg0 , arg1 , arg2 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
FUNC_EXIT ( unquote ( arg1 ) ) ;
}
if ( check_sym ( arg0 , ef2sym ) ) {
FUNC_EXIT ( unquote ( arg2 ) ) ;
}
FUNC_EXIT ( make_nf3 ( lf_AUX_Grammar_Projection2_1sym , arg0 , arg1 , arg2 ) ) ;
}

