#include  "support.h"
static Symbol lf_AUX_Follow_Earley8_1sym ;
static ATerm lf_AUX_Follow_Earley8_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Follow_Earley8 ( ) {
lf_AUX_Follow_Earley8_1sym = ATmakeSymbol ( "prod(id(\"Follow-Earley\"),w(\"\"),[l(\"sons\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)"
 , 4 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Follow_Earley8_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Production\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Follow-Earley\"),w(\"\"),[l(\"sons\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) , lf_AUX_Follow_Earley8_1 , lf_AUX_Follow_Earley8_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Production\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Follow_Earley8 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Follow-Earley\"),w(\"\"),[l(\"nm-sons\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Follow-Earley\"),w(\"\"),[l(\"nm-sons\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Follow_Earley8 ( ) {
}
ATerm lf_AUX_Follow_Earley8_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3 ) {
FUNC_ENTRY ( lf_AUX_Follow_Earley8_1sym , ATmakeAppl ( lf_AUX_Follow_Earley8_1sym , arg0 , arg1 , arg2 , arg3 ) ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
FUNC_EXIT ( ( * ef2 ) ( arg0 , ( * ef1 ) ( lf2 ( make_list ( atmp100 ) ) ) , arg2 , arg3 ) ) ;
}
}
}
}
FUNC_EXIT ( make_nf4 ( lf_AUX_Follow_Earley8_1sym , arg0 , arg1 , arg2 , arg3 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

