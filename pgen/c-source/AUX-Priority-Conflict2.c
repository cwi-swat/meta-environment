#include  "asc-support.h"
static Symbol lf_AUX_Priority_Conflict2_1sym ;
static ATerm lf_AUX_Priority_Conflict2_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_Priority_Conflict2 ( ) {
lf_AUX_Priority_Conflict2_1sym = ATmakeSymbol ( "prod(id(\"Priority-Conflict\"),w(\"\"),[l(\"cnf\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Priorities\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Conflict2_1sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Group\"),ql(\">\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Priority\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Symbol\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Conflict\"),w(\"\"),[l(\"cnf\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Priorities\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Priority_Conflict2_1 , lf_AUX_Priority_Conflict2_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Priority\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Symbol\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Group\"),ql(\">\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_Priority_Conflict2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\".\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Item\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\".\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Item\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Projection\"),w(\"\"),[sort(\"Priority\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"Priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Projection\"),w(\"\"),[sort(\"Priority\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"Priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Group\"),w(\"\"),ql(\">\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Group\"),w(\"\"),ql(\">\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Group\"),w(\"\"),sort(\"Associativity\"),w(\"\"),sort(\"Group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Group\"),w(\"\"),sort(\"Associativity\"),w(\"\"),sort(\"Group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"right\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"right\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"non-assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"non-assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"left\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"left\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" ) ) ;
}
static ATermTable table_lf_AUX_Priority_Conflict2_1 ;
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
static ATerm constant3 = NULL ;
void init_AUX_Priority_Conflict2 ( ) {
create_table ( table_lf_AUX_Priority_Conflict2_1 , 0 ) ;
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
ATprotect ( & constant3 ) ;
}
ATerm lf_AUX_Priority_Conflict2_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
ATerm interm = make_tuple3 ( arg0 , arg1 , arg2 ) ;
ATermTable table = get_table ( table_lf_AUX_Priority_Conflict2_1 ) ;
ATerm result = get_result ( table , interm ) ;
if ( result ) return result ;
else {
{
ATerm tmp [ 3 ] ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( arg1 , ef2sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef3sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , lf3sym ) ) {
{
ATerm atmp1000 = arg_0 ( atmp100 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( check_sym ( atmp11 , ef4sym ) ) {
{
ATerm atmp110 = arg_0 ( atmp11 ) ;
if ( check_sym ( atmp110 , ef3sym ) ) {
{
ATerm atmp1100 = arg_0 ( atmp110 ) ;
if ( check_sym ( atmp1100 , lf3sym ) ) {
{
ATerm atmp11000 = arg_0 ( atmp1100 ) ;
{
ATerm atmp111 = arg_1 ( atmp11 ) ;
{
ATerm atmp112 = arg_2 ( atmp11 ) ;
if ( ! not_empty_list ( atmp1000 ) ) {
if ( is_single_element ( atmp11000 ) ) {
tmp [ 0 ] = list_head ( atmp11000 ) ;
result = ( * ef5 ) ( ( * ef6 ) ( lf4 ( cons ( make_list ( ( * ef7 ) ( ( * ef4 ) ( ( * ef3 ) ( lf3 ( make_list ( tmp [ 0 ] ) ) ) , atmp111 , atmp112 ) ) ) , make_list ( ( * ef7 ) ( arg2 ) ) ) ) ) , ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) ) ;
put_result ( table , interm , result ) ;
return result ;
}
if ( not_empty_list ( atmp11000 ) ) {
tmp [ 0 ] = list_head ( atmp11000 ) ;
tmp [ 1 ] = list_tail ( atmp11000 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
tmp [ 2 ] = ( * ef4 ) ( ( * ef3 ) ( lf3 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( tmp [ 1 ] ) ) ) ) , atmp111 , atmp112 ) ;
result = ( * ef8 ) ( ( * ef8 ) ( ( * ef5 ) ( ( * ef9 ) ( ( * ef7 ) ( tmp [ 2 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef10 ) ( ) ) ) , ( * ef7 ) ( arg2 ) ) , ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) ) , ( * ef5 ) ( ( * ef6 ) ( lf4 ( cons ( make_list ( ( * ef7 ) ( tmp [ 2 ] ) ) , make_list ( ( * ef7 ) ( arg2 ) ) ) ) ) , ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) ) ) , ( * ef5 ) ( ( * ef9 ) ( ( * ef7 ) ( tmp [ 2 ] ) , ( constant1 ? constant1 : ( constant1 = ( * ef11 ) ( ) ) ) , ( * ef7 ) ( arg2 ) ) , ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) ) ) ;
put_result ( table , interm , result ) ;
return result ;
}
}
}
else {
if ( not_empty_list ( atmp11000 ) ) {
tmp [ 0 ] = list_head ( atmp11000 ) ;
tmp [ 1 ] = list_tail ( atmp11000 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
result = ( * ef5 ) ( ( * ef6 ) ( lf4 ( cons ( make_list ( ( * ef7 ) ( ( * ef4 ) ( ( * ef3 ) ( lf3 ( cons ( make_list ( atmp1000 ) , cons ( make_list ( tmp [ 0 ] ) , make_list ( tmp [ 1 ] ) ) ) ) ) , atmp111 , atmp112 ) ) ) , make_list ( ( * ef7 ) ( arg2 ) ) ) ) ) , ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) ) ;
put_result ( table , interm , result ) ;
return result ;
}
}
if ( is_single_element ( atmp11000 ) ) {
tmp [ 0 ] = list_head ( atmp11000 ) ;
tmp [ 1 ] = ( * ef4 ) ( ( * ef3 ) ( lf3 ( cons ( make_list ( atmp1000 ) , make_list ( tmp [ 0 ] ) ) ) ) , atmp111 , atmp112 ) ;
result = ( * ef8 ) ( ( * ef8 ) ( ( * ef8 ) ( ( * ef5 ) ( ( * ef9 ) ( ( * ef7 ) ( tmp [ 1 ] ) , ( constant2 ? constant2 : ( constant2 = ( * ef12 ) ( ) ) ) , ( * ef7 ) ( arg2 ) ) , ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) ) , ( * ef5 ) ( ( * ef6 ) ( lf4 ( cons ( make_list ( ( * ef7 ) ( tmp [ 1 ] ) ) , make_list ( ( * ef7 ) ( arg2 ) ) ) ) ) , ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) ) ) , ( * ef5 ) ( ( * ef9 ) ( ( * ef7 ) ( tmp [ 1 ] ) , ( constant3 ? constant3 : ( constant3 = ( * ef13 ) ( ) ) ) , ( * ef7 ) ( arg2 ) ) , ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) ) ) , ( * ef5 ) ( ( * ef9 ) ( ( * ef7 ) ( tmp [ 1 ] ) , ( constant1 ? constant1 : ( constant1 = ( * ef11 ) ( ) ) ) , ( * ef7 ) ( arg2 ) ) , ( * ef1 ) ( lf2 ( make_list ( atmp000 ) ) ) ) ) ;
put_result ( table , interm , result ) ;
return result ;
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
FUNC_EXIT ( make_nf3 ( lf_AUX_Priority_Conflict2_1sym , arg0 , arg1 , arg2 ) ) ;
}
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
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}

