#include "support.h"
static asymbol * lf_AUX_Check_List_Pats21_2sym;
static aterm * lf_AUX_Check_List_Pats21_2( aterm * arg1 , aterm * arg2);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf_AUX_Check_List_Pats21_1sym;
static aterm * lf_AUX_Check_List_Pats21_1( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
void register_AUX_Check_List_Pats21( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Check_List_Pats21_2sym= TmkSymbol( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"are-rhs-args\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Check_List_Pats21_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_Check_List_Pats21_1 , lf_AUX_Check_List_Pats21_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"are-rhs-args\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Check_List_Pats21_2 , lf_AUX_Check_List_Pats21_2sym);
}
void resolve_AUX_Check_List_Pats21( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-rhs-pattern\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-rhs-pattern\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Check_List_Pats21_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[3];
PROF( prof_lf_AUX_Check_List_Pats21_2);
if( check_sym( arg1 , lf_AUX_Check_List_Pats21_1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( m_not_empty_list( atmp10)) {
tmp[ 0]= m_list_head( atmp10);
{
tmp[ 1]= m_list_tail( atmp10);
{
if( m_not_empty_list( tmp[ 1])) {
t_protect( arg0);
t_protect( tmp[ 0]);
tmp[ 2]= ( * ef2)( arg0 , tmp[ 0]);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , ( * ef1)( ))) {
t_protect( arg0);
t_protect( tmp[ 1]);
if( term_equal( lf_AUX_Check_List_Pats21_2( arg0 , lf_AUX_Check_List_Pats21_1( make_list( tmp[ 1]))) , ( * ef3)( ))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef1)( );
}
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , ( * ef3)( ))) {
t_protect( arg0);
t_protect( tmp[ 1]);
if( term_equal( lf_AUX_Check_List_Pats21_2( arg0 , lf_AUX_Check_List_Pats21_1( make_list( tmp[ 1]))) , ( * ef1)( ))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef1)( );
}
}
t_unprotect( tmp[ 2]);
}
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
if( m_is_single_element( atmp10)) {
tmp[ 0]= m_list_head( atmp10);
t_unprotect( arg1);
return ( * ef2)( arg0 , tmp[ 0]);
}
}
}
return make_nf2( lf_AUX_Check_List_Pats21_2sym , arg0 , arg1);
}
}
aterm * lf_AUX_Check_List_Pats21_1( aterm * arg0) {
PROF( prof_lf_AUX_Check_List_Pats21_1);
return make_nf1( lf_AUX_Check_List_Pats21_1sym , arg0);
}

