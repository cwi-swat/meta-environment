#include  "asc-support.h"
static Symbol lf_AUX_Basic_Sdf_Normalization11_1sym ;
static ATerm lf_AUX_Basic_Sdf_Normalization11_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
void register_AUX_Basic_Sdf_Normalization11 ( ) {
lf_AUX_Basic_Sdf_Normalization11_1sym = ATmakeSymbol ( "prod(id(\"Basic-Sdf-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"-CF\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Basic_Sdf_Normalization11_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Priority\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Production\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"Basic-Sdf-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"-CF\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) , lf_AUX_Basic_Sdf_Normalization11_1 , lf_AUX_Basic_Sdf_Normalization11_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Priority\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Production\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Basic_Sdf_Normalization11 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"priorities\"),w(\"\"),sort(\"Priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"priorities\"),w(\"\"),sort(\"Priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Sdf2-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Priorities\"),w(\"\"),ql(\"-CFp\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Sdf2-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Priorities\"),w(\"\"),ql(\"-CFp\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Normalization\"),w(\"\"),[ql(\"norm\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Priorities\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Normalization\"),w(\"\"),[ql(\"norm\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Priorities\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[ql(\"syntax\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[ql(\"syntax\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Sdf-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"-CFs\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Sdf-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"-CFs\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[sort(\"Grammar\"),w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[sort(\"Grammar\"),w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[ql(\"(/)\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[ql(\"(/)\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Basic_Sdf_Normalization11 ( ) {
}
ATerm lf_AUX_Basic_Sdf_Normalization11_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_Basic_Sdf_Normalization11_1sym , ATmakeAppl ( lf_AUX_Basic_Sdf_Normalization11_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf2sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef2 ) ( lf2 ( make_list ( atmp0000 ) ) ) ) ) ) ) ;
}
}
}
}
}
}
if ( check_sym ( arg0 , ef5sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef6sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf3sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
FUNC_EXIT ( ( * ef5 ) ( ( * ef7 ) ( ( * ef6 ) ( lf3 ( make_list ( atmp0000 ) ) ) ) ) ) ;
}
}
}
}
}
}
if ( check_sym ( arg0 , ef8sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
FUNC_EXIT ( ( * ef8 ) ( lf_AUX_Basic_Sdf_Normalization11_1 ( atmp00 ) , lf_AUX_Basic_Sdf_Normalization11_1 ( atmp01 ) ) ) ;
}
}
}
if ( check_sym ( arg0 , ef9sym ) ) {
FUNC_EXIT ( arg0 ) ;
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Basic_Sdf_Normalization11_1sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

