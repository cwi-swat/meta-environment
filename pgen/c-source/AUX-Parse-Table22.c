#include  "asc-support.h"
static Symbol lf_AUX_Parse_Table22_1sym ;
static ATerm lf_AUX_Parse_Table22_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_Parse_Table22 ( ) {
lf_AUX_Parse_Table22_1sym = ATmakeSymbol ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"State\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"closure\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Parse_Table22_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"State\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"closure\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),no-attrs)" ) , lf_AUX_Parse_Table22_1 , lf_AUX_Parse_Table22_1sym ) ;
}
void resolve_AUX_Parse_Table22 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"state-rec\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Vertex\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Vertex\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"State\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"state-rec\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Vertex\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Vertex\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"State\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Parse_Table22 ( ) {
}
ATerm lf_AUX_Parse_Table22_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_Parse_Table22_1sym , ATmakeAppl ( lf_AUX_Parse_Table22_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
{
ATerm atmp03 = arg_3 ( arg0 ) ;
{
ATerm atmp04 = arg_4 ( arg0 ) ;
FUNC_EXIT ( atmp02 ) ;
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Parse_Table22_1sym , arg0 ) ) ;
}

