#include  "asc-support.h"
static Symbol lf_AUX_Follow_Earley3_1sym ;
static ATerm lf_AUX_Follow_Earley3_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4 ) ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_Follow_Earley3 ( ) {
lf_AUX_Follow_Earley3_1sym = ATmakeSymbol ( "prod(id(\"Follow-Earley\"),w(\"\"),[l(\"follows\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))"
 , 4 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Follow_Earley3_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Symbol\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"STPair\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"Follow-Earley\"),w(\"\"),[l(\"follows\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Follow_Earley3_1 , lf_AUX_Follow_Earley3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Symbol\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"STPair\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Follow_Earley3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\".\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Item\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\".\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Item\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Symbol-Tables\"),w(\"\"),[ql(\"[\"),w(\"\"),iter(sort(\"STPair\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbol-Tables\"),w(\"\"),[ql(\"[\"),w(\"\"),iter(sort(\"STPair\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Symbol-Tables\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Label\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"STPair\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbol-Tables\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Label\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"STPair\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Conflict\"),w(\"\"),[l(\"cnf\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Priorities\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Conflict\"),w(\"\"),[l(\"cnf\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Priorities\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Projection\"),w(\"\"),[ql(\"Pr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Projection\"),w(\"\"),[ql(\"Pr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_Follow_Earley3 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_Follow_Earley3_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Follow_Earley3_1sym , ATmakeAppl ( lf_AUX_Follow_Earley3_1sym , arg0 , arg1 , arg2 , arg3 ) ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , lf2sym ) ) {
{
ATerm atmp1000 = arg_0 ( atmp100 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
{
ATerm atmp12 = arg_2 ( arg1 ) ;
if ( check_sym ( arg2 , ef3sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , ef2sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
if ( check_sym ( atmp200 , lf2sym ) ) {
{
ATerm atmp2000 = arg_0 ( atmp200 ) ;
{
ATerm atmp21 = arg_1 ( arg2 ) ;
if ( check_sym ( atmp21 , ef1sym ) ) {
{
ATerm atmp210 = arg_0 ( atmp21 ) ;
if ( check_sym ( atmp210 , ef2sym ) ) {
{
ATerm atmp2100 = arg_0 ( atmp210 ) ;
if ( check_sym ( atmp2100 , lf2sym ) ) {
{
ATerm atmp21000 = arg_0 ( atmp2100 ) ;
{
ATerm atmp211 = arg_1 ( atmp21 ) ;
{
ATerm atmp212 = arg_2 ( atmp21 ) ;
if ( not_empty_list ( atmp21000 ) ) {
tmp [ 0 ] = list_head ( atmp21000 ) ;
tmp [ 1 ] = list_tail ( atmp21000 ) ;
if ( term_equal ( atmp11 , tmp [ 0 ] ) ) {
if ( term_equal ( ( * ef7 ) ( ( * ef8 ) ( arg0 ) , ( * ef3 ) ( ( * ef2 ) ( lf2 ( make_list ( atmp2000 ) ) ) , ( * ef1 ) ( ( * ef2 ) ( lf2 ( cons ( make_list ( atmp11 ) , make_list ( tmp [ 1 ] ) ) ) ) , atmp211 , atmp212 ) ) , ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( atmp1000 ) ) ) , atmp11 , atmp12 ) ) , ( constant0 ? constant0 : ( constant0 = ( * ef9 ) ( ) ) ) ) ) {
FUNC_EXIT ( ( * ef4 ) ( lf3 ( make_list ( ( * ef5 ) ( ( * ef6 ) ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( atmp1000 ) ) ) , atmp11 , atmp12 ) ) , arg3 ) ) ) ) ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( ( * ef4 ) ( lf3 ( make_list ( ( * ef5 ) ( ( * ef6 ) ( arg1 ) , arg3 ) ) ) ) ) ;
FUNC_EXIT_CONST ( constant1 , ( * ef4 ) ( lf3 ( make_list ( null ( ) ) ) ) ) ;
FUNC_EXIT ( make_nf4 ( lf_AUX_Follow_Earley3_1sym , arg0 , arg1 , arg2 , arg3 ) ) ;
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

