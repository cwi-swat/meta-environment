#include "support.h"
static asymbol * lf_AUX_Rules2C_Aux7_2sym;
static aterm * lf_AUX_Rules2C_Aux7_2( aterm * arg1 , aterm * arg2);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf_AUX_Rules2C_Aux7_1sym;
static aterm * lf_AUX_Rules2C_Aux7_1( aterm * arg1);
void register_AUX_Rules2C_Aux7( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Rules2C_Aux7_2sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-ofs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Rules2C_Aux7_1sym= TmkSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Rule\"),ql(\";\"))") , lf_AUX_Rules2C_Aux7_1 , lf_AUX_Rules2C_Aux7_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-ofs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux7_2 , lf_AUX_Rules2C_Aux7_2sym);
}
void resolve_AUX_Rules2C_Aux7( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Rules2C_Aux7_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[8];
PROF( prof_lf_AUX_Rules2C_Aux7_2);
if( check_sym( arg1 , lf_AUX_Rules2C_Aux7_1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( m_not_empty_list( atmp10)) {
tmp[ 0]= m_list_head( atmp10);
{
tmp[ 1]= m_list_tail( atmp10);
{
t_protect( tmp[ 0]);
tmp[ 2]= ( * ef2)( tmp[ 0]);
t_protect( arg0);
t_protect( tmp[ 2]);
if( ! term_equal( arg0 , tmp[ 2])) {
t_protect( arg0);
t_protect( tmp[ 1]);
tmp[ 3]= lf_AUX_Rules2C_Aux7_2( arg0 , lf_AUX_Rules2C_Aux7_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 3] , ef1sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
tmp[ 5]= arg_1( tmp[ 3]);
if( check_sym( tmp[ 4] , lf_AUX_Rules2C_Aux7_1sym)) {
tmp[ 6]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 5] , lf_AUX_Rules2C_Aux7_1sym)) {
tmp[ 7]= arg_0( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( tmp[ 7]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef1)( lf_AUX_Rules2C_Aux7_1( make_list( tmp[ 6])) , lf_AUX_Rules2C_Aux7_1( cons( make_list( tmp[ 0]) , make_list( tmp[ 7]))));
}
}
}
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 2]);
t_protect( tmp[ 0]);
t_protect( arg0);
if( term_equal( ( * ef2)( tmp[ 0]) , arg0)) {
t_protect( arg0);
t_protect( tmp[ 1]);
tmp[ 2]= lf_AUX_Rules2C_Aux7_2( arg0 , lf_AUX_Rules2C_Aux7_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 2] , ef1sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
if( check_sym( tmp[ 3] , lf_AUX_Rules2C_Aux7_1sym)) {
tmp[ 5]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf_AUX_Rules2C_Aux7_1sym)) {
tmp[ 6]= arg_0( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 6]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef1)( lf_AUX_Rules2C_Aux7_1( cons( make_list( tmp[ 0]) , make_list( tmp[ 5]))) , lf_AUX_Rules2C_Aux7_1( make_list( tmp[ 6])));
}
}
}
t_unprotect( tmp[ 2]);
}
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( lf_AUX_Rules2C_Aux7_1( make_list( null( ))) , lf_AUX_Rules2C_Aux7_1( make_list( null( ))));
}
}
}
return make_nf2( lf_AUX_Rules2C_Aux7_2sym , arg0 , arg1);
}
}
aterm * lf_AUX_Rules2C_Aux7_1( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux7_1);
return make_nf1( lf_AUX_Rules2C_Aux7_1sym , arg0);
}

