#include  "support.h"
static Symbol lf_AUX_Follow_Earley6_1sym ;
static ATerm lf_AUX_Follow_Earley6_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_Follow_Earley6 ( ) {
lf_AUX_Follow_Earley6_1sym = ATmakeSymbol ( "prod(id(\"Follow-Earley\"),w(\"\"),[l(\"step\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)"
 , 4 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Follow_Earley6_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Production\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Symbol\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"Follow-Earley\"),w(\"\"),[l(\"step\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) , lf_AUX_Follow_Earley6_1 , lf_AUX_Follow_Earley6_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Production\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Symbol\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Follow_Earley6 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Follow-Earley\"),w(\"\"),[l(\"prod\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Follow-Earley\"),w(\"\"),[l(\"prod\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\".\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Item\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\".\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Item\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Follow_Earley6 ( ) {
}
ATerm lf_AUX_Follow_Earley6_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3 ) {
{
ATerm tmp [ 7 ] ;
FUNC_ENTRY ( lf_AUX_Follow_Earley6_1sym , ATmakeAppl ( lf_AUX_Follow_Earley6_1sym , arg0 , arg1 , arg2 , arg3 ) ) ;
lbl_lf_AUX_Follow_Earley6_1 : if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( not_empty_list ( atmp100 ) ) {
tmp [ 0 ] = list_head ( atmp100 ) ;
tmp [ 1 ] = list_tail ( atmp100 ) ;
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 2 ] , ef3sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 5 ] , lf3sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
arg0 = arg0 ;
arg1 = ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ;
arg2 = arg2 ;
arg3 = ( * ef4 ) ( arg0 , ( * ef5 ) ( ( * ef3 ) ( lf3 ( make_list ( null ( ) ) ) ) , ( * ef2 ) ( ( * ef3 ) ( lf3 ( make_list ( tmp [ 6 ] ) ) ) , tmp [ 3 ] , tmp [ 4 ] ) ) , arg2 , arg3 ) ;
goto lbl_lf_AUX_Follow_Earley6_1 ;
}
}
}
}
else {
FUNC_EXIT ( arg3 ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf4 ( lf_AUX_Follow_Earley6_1sym , arg0 , arg1 , arg2 , arg3 ) ) ;
}
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

