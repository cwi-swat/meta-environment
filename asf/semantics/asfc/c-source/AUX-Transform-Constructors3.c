#include  "asc-support.h"
static Symbol lf_AUX_Transform_Constructors3_2sym ;
static ATerm lf_AUX_Transform_Constructors3_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol lf_AUX_Transform_Constructors3_1sym ;
static ATerm lf_AUX_Transform_Constructors3_1 ( ATerm arg1 ) ;
void register_AUX_Transform_Constructors3 ( ) {
lf_AUX_Transform_Constructors3_2sym = ATmakeSymbol ( "prod(id(\"Transform-Constructors\"),w(\"\"),[l(\"move-cons-terms-in-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Transform_Constructors3_2sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf_AUX_Transform_Constructors3_1sym = ATmakeSymbol ( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Transform_Constructors3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"NamePair\"),ql(\",\"))" ) , lf_AUX_Transform_Constructors3_1 , lf_AUX_Transform_Constructors3_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Transform-Constructors\"),w(\"\"),[l(\"move-cons-terms-in-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) , lf_AUX_Transform_Constructors3_2 , lf_AUX_Transform_Constructors3_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf5 , lf5sym ) ;
}
void resolve_AUX_Transform_Constructors3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"make-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"make-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Transform-Constructors\"),w(\"\"),[l(\"move-cons-terms-in-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TsCE\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Transform-Constructors\"),w(\"\"),[l(\"move-cons-terms-in-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TsCE\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Transform-Constructors\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TsCE\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Transform-Constructors\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TsCE\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Transform_Constructors3 ( ) {
}
ATerm lf_AUX_Transform_Constructors3_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 6 ] ;
FUNC_ENTRY ( lf_AUX_Transform_Constructors3_2sym , ATmakeAppl ( lf_AUX_Transform_Constructors3_2sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
{
ATerm atmp001 = arg_1 ( atmp00 ) ;
if ( check_sym ( atmp001 , lf3sym ) ) {
{
ATerm atmp0010 = arg_0 ( atmp001 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( arg1 , lf_AUX_Transform_Constructors3_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp0010 ) ) {
( tmp [ 0 ] = ( * ef5 ) ( lf3 ( make_list ( atmp0010 ) ) , lf_AUX_Transform_Constructors3_1 ( make_list ( atmp10 ) ) , ( * ef6 ) ( ( * ef7 ) ( lf5 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef8sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_2 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 1 ] , lf3sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
FUNC_EXIT ( ( * ef3 ) ( ( * ef4 ) ( ) , lf4 ( make_list ( tmp [ 5 ] ) ) , ( * ef2 ) ( atmp000 , lf3 ( make_list ( tmp [ 4 ] ) ) ) , atmp01 ) ) ;
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
if ( check_sym ( arg0 , ef9sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
{
ATerm atmp001 = arg_1 ( atmp00 ) ;
if ( check_sym ( atmp001 , lf3sym ) ) {
{
ATerm atmp0010 = arg_0 ( atmp001 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( arg1 , lf_AUX_Transform_Constructors3_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp0010 ) ) {
( tmp [ 0 ] = ( * ef5 ) ( lf3 ( make_list ( atmp0010 ) ) , lf_AUX_Transform_Constructors3_1 ( make_list ( atmp10 ) ) , ( * ef6 ) ( ( * ef7 ) ( lf5 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef8sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_2 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 1 ] , lf3sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
FUNC_EXIT ( ( * ef3 ) ( ( * ef10 ) ( ) , lf4 ( make_list ( tmp [ 5 ] ) ) , ( * ef2 ) ( atmp000 , lf3 ( make_list ( tmp [ 4 ] ) ) ) , atmp01 ) ) ;
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
if ( check_sym ( arg0 , ef11sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef12sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf4sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef2sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
{
ATerm atmp011 = arg_1 ( atmp01 ) ;
if ( check_sym ( atmp011 , lf3sym ) ) {
{
ATerm atmp0110 = arg_0 ( atmp011 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
if ( check_sym ( arg1 , lf_AUX_Transform_Constructors3_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp0000 ) ) {
if ( not_empty_list ( atmp0110 ) ) {
( tmp [ 0 ] = ( * ef5 ) ( lf3 ( make_list ( atmp0110 ) ) , lf_AUX_Transform_Constructors3_1 ( make_list ( atmp10 ) ) , ( * ef6 ) ( ( * ef7 ) ( lf5 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef8sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_2 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 1 ] , lf3sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
FUNC_EXIT ( ( * ef3 ) ( ( * ef4 ) ( ) , lf4 ( cons ( make_list ( tmp [ 5 ] ) , make_list ( atmp0000 ) ) ) , ( * ef2 ) ( atmp010 , lf3 ( make_list ( tmp [ 4 ] ) ) ) , atmp02 ) ) ;
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
if ( check_sym ( arg0 , ef13sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef12sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf4sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef2sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
{
ATerm atmp011 = arg_1 ( atmp01 ) ;
if ( check_sym ( atmp011 , lf3sym ) ) {
{
ATerm atmp0110 = arg_0 ( atmp011 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
if ( check_sym ( arg1 , lf_AUX_Transform_Constructors3_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp0000 ) ) {
if ( not_empty_list ( atmp0110 ) ) {
( tmp [ 0 ] = ( * ef5 ) ( lf3 ( make_list ( atmp0110 ) ) , lf_AUX_Transform_Constructors3_1 ( make_list ( atmp10 ) ) , ( * ef6 ) ( ( * ef7 ) ( lf5 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef8sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_2 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 1 ] , lf3sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
FUNC_EXIT ( ( * ef3 ) ( ( * ef10 ) ( ) , lf4 ( cons ( make_list ( tmp [ 5 ] ) , make_list ( atmp0000 ) ) ) , ( * ef2 ) ( atmp010 , lf3 ( make_list ( tmp [ 4 ] ) ) ) , atmp02 ) ) ;
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
if ( check_sym ( arg1 , lf_AUX_Transform_Constructors3_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
FUNC_EXIT ( arg0 ) ;
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Transform_Constructors3_2sym , arg0 , arg1 ) ) ;
}
}
ATerm lf_AUX_Transform_Constructors3_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Transform_Constructors3_1sym , ATmakeAppl ( lf_AUX_Transform_Constructors3_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Transform_Constructors3_1sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf5 ( ATerm arg0 ) {
CONS_ENTRY ( lf5sym , ATmakeAppl ( lf5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf5sym , arg0 ) ) ;
}

