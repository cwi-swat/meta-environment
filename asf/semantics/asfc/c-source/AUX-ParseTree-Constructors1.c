#include  "support.h"
static Symbol lf_AUX_ParseTree_Constructors1_1sym ;
static ATerm lf_AUX_ParseTree_Constructors1_1 ( ) ;
static Symbol lf_AUX_ParseTree_Constructors1_2sym ;
static ATerm lf_AUX_ParseTree_Constructors1_2 ( ) ;
static Symbol lf_AUX_ParseTree_Constructors1_3sym ;
static ATerm lf_AUX_ParseTree_Constructors1_3 ( ) ;
static Symbol lf_AUX_ParseTree_Constructors1_4sym ;
static ATerm lf_AUX_ParseTree_Constructors1_4 ( ) ;
static Symbol lf_AUX_ParseTree_Constructors1_5sym ;
static ATerm lf_AUX_ParseTree_Constructors1_5 ( ) ;
static Symbol lf_AUX_ParseTree_Constructors1_6sym ;
static ATerm lf_AUX_ParseTree_Constructors1_6 ( ) ;
static Symbol lf_AUX_ParseTree_Constructors1_7sym ;
static ATerm lf_AUX_ParseTree_Constructors1_7 ( ) ;
void register_AUX_ParseTree_Constructors1 ( ) {
lf_AUX_ParseTree_Constructors1_1sym = ATmakeSymbol ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ParseTree_Constructors1_1sym ) ;
lf_AUX_ParseTree_Constructors1_2sym = ATmakeSymbol ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ParseTree_Constructors1_2sym ) ;
lf_AUX_ParseTree_Constructors1_3sym = ATmakeSymbol ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ParseTree_Constructors1_3sym ) ;
lf_AUX_ParseTree_Constructors1_4sym = ATmakeSymbol ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"meta-var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ParseTree_Constructors1_4sym ) ;
lf_AUX_ParseTree_Constructors1_5sym = ATmakeSymbol ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ParseTree_Constructors1_5sym ) ;
lf_AUX_ParseTree_Constructors1_6sym = ATmakeSymbol ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ParseTree_Constructors1_6sym ) ;
lf_AUX_ParseTree_Constructors1_7sym = ATmakeSymbol ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ParseTree_Constructors1_7sym ) ;
register_prod ( ATparse ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ParseTree_Constructors1_1 , lf_AUX_ParseTree_Constructors1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ParseTree_Constructors1_2 , lf_AUX_ParseTree_Constructors1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ParseTree_Constructors1_3 , lf_AUX_ParseTree_Constructors1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"meta-var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ParseTree_Constructors1_4 , lf_AUX_ParseTree_Constructors1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ParseTree_Constructors1_5 , lf_AUX_ParseTree_Constructors1_5sym ) ;
register_prod ( ATparse ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ParseTree_Constructors1_6 , lf_AUX_ParseTree_Constructors1_6sym ) ;
register_prod ( ATparse ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ParseTree_Constructors1_7 , lf_AUX_ParseTree_Constructors1_7sym ) ;
}
void resolve_AUX_ParseTree_Constructors1 ( ) {
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
static ATerm constant3 = NULL ;
static ATerm constant4 = NULL ;
static ATerm constant5 = NULL ;
static ATerm constant6 = NULL ;
void init_AUX_ParseTree_Constructors1 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
ATprotect ( & constant3 ) ;
ATprotect ( & constant4 ) ;
ATprotect ( & constant5 ) ;
ATprotect ( & constant6 ) ;
}
ATerm lf_AUX_ParseTree_Constructors1_7 ( ) {
PROF ( prof_lf_AUX_ParseTree_Constructors1_7 ) ;
return ( constant0 ? constant0 : ( constant0 = make_nf0 ( lf_AUX_ParseTree_Constructors1_7sym ) ) ) ;
}
ATerm lf_AUX_ParseTree_Constructors1_6 ( ) {
PROF ( prof_lf_AUX_ParseTree_Constructors1_6 ) ;
return ( constant1 ? constant1 : ( constant1 = make_nf0 ( lf_AUX_ParseTree_Constructors1_6sym ) ) ) ;
}
ATerm lf_AUX_ParseTree_Constructors1_5 ( ) {
PROF ( prof_lf_AUX_ParseTree_Constructors1_5 ) ;
return ( constant2 ? constant2 : ( constant2 = make_nf0 ( lf_AUX_ParseTree_Constructors1_5sym ) ) ) ;
}
ATerm lf_AUX_ParseTree_Constructors1_4 ( ) {
PROF ( prof_lf_AUX_ParseTree_Constructors1_4 ) ;
return ( constant3 ? constant3 : ( constant3 = make_nf0 ( lf_AUX_ParseTree_Constructors1_4sym ) ) ) ;
}
ATerm lf_AUX_ParseTree_Constructors1_3 ( ) {
PROF ( prof_lf_AUX_ParseTree_Constructors1_3 ) ;
return ( constant4 ? constant4 : ( constant4 = make_nf0 ( lf_AUX_ParseTree_Constructors1_3sym ) ) ) ;
}
ATerm lf_AUX_ParseTree_Constructors1_2 ( ) {
PROF ( prof_lf_AUX_ParseTree_Constructors1_2 ) ;
return ( constant5 ? constant5 : ( constant5 = make_nf0 ( lf_AUX_ParseTree_Constructors1_2sym ) ) ) ;
}
ATerm lf_AUX_ParseTree_Constructors1_1 ( ) {
PROF ( prof_lf_AUX_ParseTree_Constructors1_1 ) ;
return ( constant6 ? constant6 : ( constant6 = make_nf0 ( lf_AUX_ParseTree_Constructors1_1sym ) ) ) ;
}

