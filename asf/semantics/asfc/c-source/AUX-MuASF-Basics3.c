#include  "asc-support.h"
static Symbol lf_AUX_MuASF_Basics3_2sym ;
static ATerm lf_AUX_MuASF_Basics3_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf_AUX_MuASF_Basics3_1sym ;
static ATerm lf_AUX_MuASF_Basics3_1 ( ATerm arg1 ) ;
void register_AUX_MuASF_Basics3 ( ) {
lf_AUX_MuASF_Basics3_2sym = ATmakeSymbol ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"addto-rulesopt\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Basics3_2sym ) ;
lf_AUX_MuASF_Basics3_1sym = ATmakeSymbol ( "listtype(sort(\"Rule\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Basics3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Rule\"),ql(\";\"))" ) , lf_AUX_MuASF_Basics3_1 , lf_AUX_MuASF_Basics3_1sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"addto-rulesopt\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Basics3_2 , lf_AUX_MuASF_Basics3_2sym ) ;
}
void resolve_AUX_MuASF_Basics3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"rules\"),w(\"\"),sort(\"RuleList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"rules\"),w(\"\"),sort(\"RuleList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_MuASF_Basics3 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_MuASF_Basics3_2 ( ATerm arg0 , ATerm arg1 ) {
FUNC_ENTRY ( lf_AUX_MuASF_Basics3_2sym , ATmakeAppl ( lf_AUX_MuASF_Basics3_2sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
if ( check_sym ( arg1 , lf_AUX_MuASF_Basics3_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp10 ) ) {
FUNC_EXIT ( ( * ef2 ) ( ( * ef3 ) ( lf_AUX_MuASF_Basics3_1 ( make_list ( atmp10 ) ) ) ) ) ;
}
else {
FUNC_EXIT ( arg0 ) ;
}
}
}
}
if ( check_sym ( arg0 , ef2sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef3sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf_AUX_MuASF_Basics3_1sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( arg1 , lf_AUX_MuASF_Basics3_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( ! not_empty_list ( atmp0000 ) ) {
if ( not_empty_list ( atmp10 ) ) {
FUNC_EXIT ( ( * ef2 ) ( ( * ef3 ) ( lf_AUX_MuASF_Basics3_1 ( make_list ( atmp10 ) ) ) ) ) ;
}
else {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( ) ) ;
}
}
else {
if ( not_empty_list ( atmp10 ) ) {
FUNC_EXIT ( ( * ef2 ) ( ( * ef3 ) ( lf_AUX_MuASF_Basics3_1 ( cons ( make_list ( atmp0000 ) , make_list ( atmp10 ) ) ) ) ) ) ;
}
else {
FUNC_EXIT ( ( * ef2 ) ( ( * ef3 ) ( lf_AUX_MuASF_Basics3_1 ( make_list ( atmp0000 ) ) ) ) ) ;
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
FUNC_EXIT ( make_nf2 ( lf_AUX_MuASF_Basics3_2sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_MuASF_Basics3_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuASF_Basics3_1sym , ATmakeAppl ( lf_AUX_MuASF_Basics3_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuASF_Basics3_1sym , arg0 ) ) ;
}

