#include  "support.h"
static Symbol lf_AUX_AsFix2muASF_C5_1sym ;
static ATerm lf_AUX_AsFix2muASF_C5_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef8sym ;
static funcptr ef8 ;
void register_AUX_AsFix2muASF_C5 ( ) {
lf_AUX_AsFix2muASF_C5_1sym = ATmakeSymbol ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"pln-ceqeq2rules\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix2muASF_C5_1sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"pln-ceqeq2rules\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFix2muASF_C5_1 , lf_AUX_AsFix2muASF_C5_1sym ) ;
}
void resolve_AUX_AsFix2muASF_C5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFix2muASF\"),w(\"\"),[ql(\"term-equ2rules\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFix2muASF\"),w(\"\"),[ql(\"term-equ2rules\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"get-equ-type\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"get-equ-type\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"remove-annotation\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"remove-annotation\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-term-ceq\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-term-ceq\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"ceqeq2rules\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"ceqeq2rules\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_AsFix2muASF_C5 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_AsFix2muASF_C5_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_AsFix2muASF_C5_1sym , ATmakeAppl ( lf_AUX_AsFix2muASF_C5_1sym , arg0 , arg1 ) ) ;
tmp [ 0 ] = ( * ef3 ) ( arg0 ) ;
tmp [ 1 ] = ( * ef4 ) ( tmp [ 0 ] ) ;
if ( term_equal ( tmp [ 1 ] , ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( ) ) ) ) ) {
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( tmp [ 0 ] ) , tmp [ 0 ] , arg1 ) ) ;
}
if ( term_equal ( tmp [ 1 ] , ( constant1 ? constant1 : ( constant1 = ( * ef8 ) ( ) ) ) ) ) {
FUNC_EXIT ( ( * ef6 ) ( ( * ef7 ) ( tmp [ 0 ] ) , tmp [ 0 ] , arg1 ) ) ;
}
FUNC_EXIT ( make_nf2 ( lf_AUX_AsFix2muASF_C5_1sym , arg0 , arg1 ) ) ;
}
}

