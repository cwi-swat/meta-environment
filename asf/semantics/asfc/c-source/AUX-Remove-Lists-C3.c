#include "support.h"
static Symbol lf_AUX_Remove_Lists_C3_1sym;
static ATerm lf_AUX_Remove_Lists_C3_1( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef5sym;
static funcptr ef5;
static Symbol lf4sym;
static ATerm lf4( ATerm arg1);
static Symbol ef6sym;
static funcptr ef6;
static Symbol ef7sym;
static funcptr ef7;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
void register_AUX_Remove_Lists_C3( ) {
lf_AUX_Remove_Lists_C3_1sym= ATmakeSymbol( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-ruleopt\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRulePair\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Remove_Lists_C3_1sym);
lf4sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf4sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
register_prod( ATparse( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-ruleopt\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRulePair\"),w(\"\"),no-attrs)") , lf_AUX_Remove_Lists_C3_1 , lf_AUX_Remove_Lists_C3_1sym);
register_prod( ATparse( "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf2 , lf2sym);
register_prod( ATparse( "listtype(sort(\"Rule\"),ql(\";\"))") , lf3 , lf3sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf4 , lf4sym);
}
void resolve_AUX_Remove_Lists_C3( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRulePair\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRulePair\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"rules\"),w(\"\"),sort(\"RuleList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"rules\"),w(\"\"),sort(\"RuleList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
void init_AUX_Remove_Lists_C3( ) {
ATprotect( & constant0);
ATprotect( & constant1);
}
ATerm lf_AUX_Remove_Lists_C3_1( ATerm arg0) {
{
ATerm tmp[6];
PROF( prof_lf_AUX_Remove_Lists_C3_1);
if( check_sym( arg0 , ef1sym)) {
return ( constant0? constant0: ( constant0= ( * ef2)( lf2( make_list( null( ))) , lf3( make_list( null( ))))));
}
if( check_sym( arg0 , ef3sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef4sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf3sym)) {
{
ATerm atmp0000= arg_0( atmp000);
if( not_empty_list( atmp0000)) {
tmp[ 0]= ( * ef5)( lf3( make_list( atmp0000)) , ( constant1? constant1: ( constant1= ( * ef6)( lf4( make_list( make_char( 49)))))));
if( check_sym( tmp[ 0] , ef7sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
if( check_sym( tmp[ 1] , lf2sym)) {
tmp[ 4]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
return ( * ef2)( lf2( make_list( tmp[ 4])) , lf3( make_list( tmp[ 5])));
}
}
}
}
else {
return ( constant0? constant0: ( constant0= ( * ef2)( lf2( make_list( null( ))) , lf3( make_list( null( ))))));
}
}
}
}
}
}
}
return make_nf1( lf_AUX_Remove_Lists_C3_1sym , arg0);
}
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}
ATerm lf4( ATerm arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}

