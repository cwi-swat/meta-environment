#include "support.h"
static Symbol lf_AUX_Normalize_Conds4_2sym;
static ATerm lf_AUX_Normalize_Conds4_2( ATerm arg1);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf_AUX_Normalize_Conds4_1sym;
static ATerm lf_AUX_Normalize_Conds4_1( ATerm arg1);
void register_AUX_Normalize_Conds4( ) {
lf_AUX_Normalize_Conds4_2sym= ATmakeSymbol( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Normalize_Conds4_2sym);
lf_AUX_Normalize_Conds4_1sym= ATmakeSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Normalize_Conds4_1sym);
register_prod( ATparse( "listtype(sort(\"Rule\"),ql(\";\"))") , lf_AUX_Normalize_Conds4_1 , lf_AUX_Normalize_Conds4_1sym);
register_prod( ATparse( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)") , lf_AUX_Normalize_Conds4_2 , lf_AUX_Normalize_Conds4_2sym);
}
void resolve_AUX_Normalize_Conds4( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
}
void init_AUX_Normalize_Conds4( ) {
}
ATerm lf_AUX_Normalize_Conds4_2( ATerm arg0) {
{
ATerm tmp[6];
PROF( prof_lf_AUX_Normalize_Conds4_2);
if( check_sym( arg0 , lf_AUX_Normalize_Conds4_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( is_single_element( atmp00)) {
tmp[ 0]= list_head( atmp00);
return ( * ef1)( lf_AUX_Normalize_Conds4_1( make_list( ( * ef2)( tmp[ 0]))));
}
if( not_empty_list( atmp00)) {
tmp[ 0]= list_head( atmp00);
tmp[ 1]= list_tail( atmp00);
if( not_empty_list( tmp[ 1])) {
tmp[ 2]= ( * ef2)( tmp[ 0]);
tmp[ 3]= lf_AUX_Normalize_Conds4_2( lf_AUX_Normalize_Conds4_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 3] , ef1sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf_AUX_Normalize_Conds4_1sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( not_empty_list( tmp[ 5])) {
return ( * ef1)( lf_AUX_Normalize_Conds4_1( cons( make_list( tmp[ 2]) , make_list( tmp[ 5]))));
}
}
}
}
}
}
}
return make_nf1( lf_AUX_Normalize_Conds4_2sym , arg0);
}
}
ATerm lf_AUX_Normalize_Conds4_1( ATerm arg0) {
PROF( prof_lf_AUX_Normalize_Conds4_1);
return make_nf1( lf_AUX_Normalize_Conds4_1sym , arg0);
}

