#include  "support.h"
static Symbol lf_AUX_C_Basics5_1sym ;
static ATerm lf_AUX_C_Basics5_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_C_Basics5 ( ) {
lf_AUX_C_Basics5_1sym = ATmakeSymbol ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++r\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C_Basics5_1sym ) ;
register_prod ( ATparse ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++r\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) , lf_AUX_C_Basics5_1 , lf_AUX_C_Basics5_1sym ) ;
}
void resolve_AUX_C_Basics5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"return\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"return\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_C_Basics5 ( ) {
}
ATerm lf_AUX_C_Basics5_1 ( ATerm arg0 , ATerm arg1 ) {
PROF ( prof_lf_AUX_C_Basics5_1 ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
return arg1 ;
}
if ( check_sym ( arg0 , ef2sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef3sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef4sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
return arg0 ;
}
}
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef6sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( atmp0000 , ef7sym ) ) {
{
ATerm atmp0001 = arg_1 ( atmp000 ) ;
if ( check_sym ( atmp0001 , ef2sym ) ) {
{
ATerm atmp00010 = arg_0 ( atmp0001 ) ;
if ( check_sym ( atmp00010 , ef3sym ) ) {
{
ATerm atmp000100 = arg_0 ( atmp00010 ) ;
if ( check_sym ( atmp000100 , ef4sym ) ) {
{
ATerm atmp0001000 = arg_0 ( atmp000100 ) ;
return arg0 ;
}
}
}
}
{
ATerm atmp00010 = arg_0 ( atmp0001 ) ;
if ( check_sym ( atmp00010 , ef5sym ) ) {
{
ATerm atmp000100 = arg_0 ( atmp00010 ) ;
{
ATerm atmp000101 = arg_1 ( atmp00010 ) ;
if ( check_sym ( atmp000101 , ef4sym ) ) {
{
ATerm atmp0001010 = arg_0 ( atmp000101 ) ;
return arg0 ;
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
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef5sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
{
ATerm atmp001 = arg_1 ( atmp00 ) ;
if ( check_sym ( atmp001 , ef4sym ) ) {
{
ATerm atmp0010 = arg_0 ( atmp001 ) ;
return arg0 ;
}
}
{
ATerm atmp001 = arg_1 ( atmp00 ) ;
if ( check_sym ( atmp001 , ef6sym ) ) {
{
ATerm atmp0010 = arg_0 ( atmp001 ) ;
if ( check_sym ( atmp0010 , ef7sym ) ) {
{
ATerm atmp0011 = arg_1 ( atmp001 ) ;
if ( check_sym ( atmp0011 , ef2sym ) ) {
{
ATerm atmp00110 = arg_0 ( atmp0011 ) ;
if ( check_sym ( atmp00110 , ef3sym ) ) {
{
ATerm atmp001100 = arg_0 ( atmp00110 ) ;
if ( check_sym ( atmp001100 , ef4sym ) ) {
{
ATerm atmp0011000 = arg_0 ( atmp001100 ) ;
return arg0 ;
}
}
}
}
{
ATerm atmp00110 = arg_0 ( atmp0011 ) ;
if ( check_sym ( atmp00110 , ef5sym ) ) {
{
ATerm atmp001100 = arg_0 ( atmp00110 ) ;
{
ATerm atmp001101 = arg_1 ( atmp00110 ) ;
if ( check_sym ( atmp001101 , ef4sym ) ) {
{
ATerm atmp0011010 = arg_0 ( atmp001101 ) ;
return arg0 ;
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
if ( check_sym ( arg0 , ef2sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
return ( * ef8 ) ( arg0 , arg1 ) ;
}
}
return make_nf2 ( lf_AUX_C_Basics5_1sym , arg0 , arg1 ) ;
}

