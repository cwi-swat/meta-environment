#include "support.h"
static asymbol * lf_AUX_Make_Assign_Conds_C1_1sym;
static aterm * lf_AUX_Make_Assign_Conds_C1_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_Make_Assign_Conds_C1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Make_Assign_Conds_C1_1sym= TmkSymbol( "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-matching-conds\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-matching-conds\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)") , lf_AUX_Make_Assign_Conds_C1_1 , lf_AUX_Make_Assign_Conds_C1_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Rule\"),ql(\";\"))") , lf2 , lf2sym);
}
void resolve_AUX_Make_Assign_Conds_C1( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"module\"),w(\"\"),sort(\"ModId\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),sort(\"RulesOpt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"module\"),w(\"\"),sort(\"ModId\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),sort(\"RulesOpt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-mc-ruleopt\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-mc-ruleopt\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"create-new-rulesopt\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"create-new-rulesopt\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Make_Assign_Conds_C1_1( aterm * arg0) {
{
aterm * tmp[4];
PROF( prof_lf_AUX_Make_Assign_Conds_C1_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
{
aterm * atmp02= arg_2( arg0);
t_protect( atmp02);
tmp[ 0]= ( * ef2)( atmp02);
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf2sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
t_protect( tmp[ 2]);
tmp[ 3]= ( * ef4)( lf2( make_list( tmp[ 2])));
t_protect( atmp00);
t_protect( atmp01);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( atmp00 , atmp01 , tmp[ 3]);
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
return make_nf1( lf_AUX_Make_Assign_Conds_C1_1sym , arg0);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

