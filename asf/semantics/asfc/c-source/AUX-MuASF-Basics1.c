#include "support.h"
static asymbol * lf_AUX_MuASF_Basics1_2sym;
static aterm * lf_AUX_MuASF_Basics1_2( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf_AUX_MuASF_Basics1_1sym;
static aterm * lf_AUX_MuASF_Basics1_1( aterm * arg1);
void register_AUX_MuASF_Basics1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Basics1_2sym= TmkSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"create-new-rulesopt\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_MuASF_Basics1_1sym= TmkSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Rule\"),ql(\";\"))") , lf_AUX_MuASF_Basics1_1 , lf_AUX_MuASF_Basics1_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"create-new-rulesopt\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics1_2 , lf_AUX_MuASF_Basics1_2sym);
}
void resolve_AUX_MuASF_Basics1( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"rules\"),w(\"\"),sort(\"RuleList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"rules\"),w(\"\"),sort(\"RuleList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Basics1_2( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Basics1_2);
if( check_sym( arg0 , lf_AUX_MuASF_Basics1_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( m_not_empty_list( atmp00)) {
t_protect( atmp00);
t_unprotect( arg0);
return ( * ef2)( ( * ef3)( lf_AUX_MuASF_Basics1_1( make_list( atmp00))));
}
else {
t_unprotect( arg0);
return ( * ef1)( );
}
}
}
return make_nf1( lf_AUX_MuASF_Basics1_2sym , arg0);
}
aterm * lf_AUX_MuASF_Basics1_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Basics1_1);
return make_nf1( lf_AUX_MuASF_Basics1_1sym , arg0);
}

