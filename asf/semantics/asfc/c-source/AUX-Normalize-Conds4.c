#include "support.h"
static Symbol lf_AUX_Normalize_Conds4_1sym;
static ATerm lf_AUX_Normalize_Conds4_1( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef3sym;
static funcptr ef3;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
void register_AUX_Normalize_Conds4( ) {
lf_AUX_Normalize_Conds4_1sym= ATmakeSymbol( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-rulesopt\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Normalize_Conds4_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-rulesopt\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)") , lf_AUX_Normalize_Conds4_1 , lf_AUX_Normalize_Conds4_1sym);
register_prod( ATparse( "listtype(sort(\"Rule\"),ql(\";\"))") , lf2 , lf2sym);
}
void resolve_AUX_Normalize_Conds4( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"rules\"),w(\"\"),sort(\"RuleList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"rules\"),w(\"\"),sort(\"RuleList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
void init_AUX_Normalize_Conds4( ) {
ATprotect( & constant0);
}
ATerm lf_AUX_Normalize_Conds4_1( ATerm arg0) {
{
ATerm tmp[3];
PROF( prof_lf_AUX_Normalize_Conds4_1);
if( check_sym( arg0 , ef1sym)) {
return arg0;
}
if( check_sym( arg0 , ef2sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef3sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf2sym)) {
{
ATerm atmp0000= arg_0( atmp000);
if( not_empty_list( atmp0000)) {
tmp[ 0]= ( * ef4)( lf2( make_list( atmp0000)));
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf2sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( not_empty_list( tmp[ 2])) {
return ( * ef2)( ( * ef3)( lf2( make_list( tmp[ 2]))));
}
}
}
}
else {
return ( constant0? constant0: ( constant0= ( * ef2)( ( * ef3)( lf2( make_list( null( )))))));
}
}
}
}
}
}
}
return make_nf1( lf_AUX_Normalize_Conds4_1sym , arg0);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

