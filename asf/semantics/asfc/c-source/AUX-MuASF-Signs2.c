#include "support.h"
static asymbol * lf_AUX_MuASF_Signs2_1sym;
static aterm * lf_AUX_MuASF_Signs2_1( aterm * arg1 , aterm * arg2);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_MuASF_Signs2( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Signs2_1sym= TmkSymbol( "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDef\"),w(\"\"),ql(\"in_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDef\"),w(\"\"),ql(\"in_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Signs2_1 , lf_AUX_MuASF_Signs2_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf2 , lf2sym);
}
void resolve_AUX_MuASF_Signs2( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Signs2_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[2];
PROF( prof_lf_AUX_MuASF_Signs2_1);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( m_not_empty_list( atmp100)) {
tmp[ 0]= m_list_head( atmp100);
{
tmp[ 1]= m_list_tail( atmp100);
t_protect( arg0);
t_protect( tmp[ 0]);
if( ! term_equal( arg0 , tmp[ 0])) {
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return lf_AUX_MuASF_Signs2_1( arg0 , ( * ef1)( lf2( make_list( tmp[ 1]))));
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
return ( * ef3)( );
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( );
}
}
}
}
}
return make_nf2( lf_AUX_MuASF_Signs2_1sym , arg0 , arg1);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

