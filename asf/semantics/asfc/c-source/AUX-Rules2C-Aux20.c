#include "support.h"
static asymbol * lf_AUX_Rules2C_Aux20_2sym;
static aterm * lf_AUX_Rules2C_Aux20_2( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf_AUX_Rules2C_Aux20_1sym;
static aterm * lf_AUX_Rules2C_Aux20_1( aterm * arg1);
void register_AUX_Rules2C_Aux20( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Rules2C_Aux20_2sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"add-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Rules2C_Aux20_1sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_Rules2C_Aux20_1 , lf_AUX_Rules2C_Aux20_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"add-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux20_2 , lf_AUX_Rules2C_Aux20_2sym);
}
void resolve_AUX_Rules2C_Aux20( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Rules2C_Aux20_2( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Rules2C_Aux20_2);
if( check_sym( arg0 , lf_AUX_Rules2C_Aux20_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , lf_AUX_Rules2C_Aux20_1sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp10);
if( ! not_empty_list( atmp10)) {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( lf_AUX_Rules2C_Aux20_1( make_list( null( ))));
}
else {
t_protect( atmp10);
t_protect( atmp00);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( lf_AUX_Rules2C_Aux20_1( cons( make_list( atmp10) , make_list( atmp00))));
}
}
else {
t_protect( atmp10);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( lf_AUX_Rules2C_Aux20_1( make_list( atmp10)));
}
}
}
}
}
return make_nf2( lf_AUX_Rules2C_Aux20_2sym , arg0 , arg1);
}
aterm * lf_AUX_Rules2C_Aux20_1( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux20_1);
return make_nf1( lf_AUX_Rules2C_Aux20_1sym , arg0);
}

