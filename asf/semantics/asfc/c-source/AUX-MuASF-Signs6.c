#include "support.h"
static asymbol * lf_AUX_MuASF_Signs6_1sym;
static aterm * lf_AUX_MuASF_Signs6_1( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_MuASF_Signs6( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Signs6_1sym= TmkSymbol( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"remove-ssfuncdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"remove-ssfuncdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Signs6_1 , lf_AUX_MuASF_Signs6_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf2 , lf2sym);
}
void resolve_AUX_MuASF_Signs6( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Signs6_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[5];
PROF( prof_lf_AUX_MuASF_Signs6_1);
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
t_protect( arg0);
t_protect( tmp[ 1]);
tmp[ 2]= lf_AUX_MuASF_Signs6_1( arg0 , ( * ef1)( lf2( make_list( tmp[ 1]))));
if( check_sym( tmp[ 2] , ef1sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf2sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
t_protect( tmp[ 4]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef1)( lf2( cons( make_list( tmp[ 0]) , make_list( tmp[ 4]))));
}
}
t_unprotect( tmp[ 2]);
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( tmp[ 1])));
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( lf2( make_list( null( ))));
}
}
}
}
}
return make_nf2( lf_AUX_MuASF_Signs6_1sym , arg0 , arg1);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

