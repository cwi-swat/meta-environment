#include "support.h"
static asymbol * lf_AUX_MuASF_Basics2_2sym;
static aterm * lf_AUX_MuASF_Basics2_2( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf_AUX_MuASF_Basics2_1sym;
static aterm * lf_AUX_MuASF_Basics2_1( aterm * arg1);
void register_AUX_MuASF_Basics2( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Basics2_2sym= TmkSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"addto-rulesopt\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_MuASF_Basics2_1sym= TmkSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Rule\"),ql(\";\"))") , lf_AUX_MuASF_Basics2_1 , lf_AUX_MuASF_Basics2_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"addto-rulesopt\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics2_2 , lf_AUX_MuASF_Basics2_2sym);
}
void resolve_AUX_MuASF_Basics2( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"rules\"),w(\"\"),sort(\"RuleList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"rules\"),w(\"\"),sort(\"RuleList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Basics2_2( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_MuASF_Basics2_2);
if( check_sym( arg0 , ef1sym)) {
if( check_sym( arg1 , lf_AUX_MuASF_Basics2_1sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp10);
if( not_empty_list( atmp10)) {
t_unprotect( arg0);
return ( * ef2)( ( * ef3)( arg1));
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( );
}
}
}
}
if( check_sym( arg0 , ef2sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef3sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf_AUX_MuASF_Basics2_1sym)) {
{
aterm * atmp0000= arg_0( atmp000);
if( check_sym( arg1 , lf_AUX_MuASF_Basics2_1sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp0000);
if( ! not_empty_list( atmp0000)) {
t_protect( atmp10);
if( not_empty_list( atmp10)) {
t_unprotect( arg0);
return ( * ef2)( ( * ef3)( arg1));
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( );
}
}
else {
t_protect( atmp10);
if( not_empty_list( atmp10)) {
t_protect( atmp0000);
t_protect( atmp10);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( ( * ef3)( lf_AUX_MuASF_Basics2_1( cons( make_list( atmp0000) , make_list( atmp10)))));
}
else {
t_protect( atmp0000);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( ( * ef3)( lf_AUX_MuASF_Basics2_1( make_list( atmp0000))));
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
return make_nf2( lf_AUX_MuASF_Basics2_2sym , arg0 , arg1);
}
aterm * lf_AUX_MuASF_Basics2_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Basics2_1);
return make_nf1( lf_AUX_MuASF_Basics2_1sym , arg0);
}

