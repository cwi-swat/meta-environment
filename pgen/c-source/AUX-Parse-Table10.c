#include  "asc-support.h"
static Symbol lf_AUX_Parse_Table10_1sym ;
static ATerm lf_AUX_Parse_Table10_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_Parse_Table10 ( ) {
lf_AUX_Parse_Table10_1sym = ATmakeSymbol ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Parse-Table\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"follow\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Parse_Table10_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Parse-Table\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"follow\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) , lf_AUX_Parse_Table10_1 , lf_AUX_Parse_Table10_1sym ) ;
}
void resolve_AUX_Parse_Table10 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"parse-table\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Label-Table\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"States\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"parse-table\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Label-Table\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"States\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Parse_Table10 ( ) {
}
ATerm lf_AUX_Parse_Table10_1 ( ATerm arg0 , ATerm arg1 ) {
FUNC_ENTRY ( lf_AUX_Parse_Table10_1sym , ATmakeAppl ( lf_AUX_Parse_Table10_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
{
ATerm atmp03 = arg_3 ( arg0 ) ;
if ( check_sym ( atmp03 , ef2sym ) ) {
{
ATerm atmp030 = arg_0 ( atmp03 ) ;
{
ATerm atmp04 = arg_4 ( arg0 ) ;
FUNC_EXIT ( ( * ef1 ) ( atmp00 , arg1 , atmp02 , ( * ef2 ) ( atmp030 ) , atmp04 ) ) ;
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Parse_Table10_1sym , arg0 , arg1 ) ) ;
}

