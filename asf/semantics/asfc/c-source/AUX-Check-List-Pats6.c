#include "support.h"
static asymbol * lf_AUX_Check_List_Pats6_2sym;
static aterm * lf_AUX_Check_List_Pats6_2( aterm * arg1);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf_AUX_Check_List_Pats6_1sym;
static aterm * lf_AUX_Check_List_Pats6_1( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
void register_AUX_Check_List_Pats6( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Check_List_Pats6_2sym= TmkSymbol( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"are-lookup-lhs-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Check_List_Pats6_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_Check_List_Pats6_1 , lf_AUX_Check_List_Pats6_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"are-lookup-lhs-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Check_List_Pats6_2 , lf_AUX_Check_List_Pats6_2sym);
}
void resolve_AUX_Check_List_Pats6( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-lookup-pattern\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-lookup-pattern\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Check_List_Pats6_2( aterm * arg0) {
{
aterm * tmp[3];
PROF( prof_lf_AUX_Check_List_Pats6_2);
if( check_sym( arg0 , lf_AUX_Check_List_Pats6_1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
{
t_protect( atmp00);
tmp[ 1]= list_tail( atmp00);
t_protect( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
t_protect( tmp[ 0]);
tmp[ 2]= ( * ef2)( tmp[ 0]);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , ( * ef1)( ))) {
t_protect( tmp[ 1]);
if( term_equal( lf_AUX_Check_List_Pats6_2( lf_AUX_Check_List_Pats6_1( make_list( tmp[ 1]))) , ( * ef3)( ))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef1)( );
}
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , ( * ef3)( ))) {
t_protect( tmp[ 1]);
if( term_equal( lf_AUX_Check_List_Pats6_2( lf_AUX_Check_List_Pats6_1( make_list( tmp[ 1]))) , ( * ef1)( ))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef1)( );
}
}
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
t_protect( atmp00);
if( is_single_element( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
t_unprotect( arg0);
return ( * ef2)( tmp[ 0]);
}
}
}
return make_nf1( lf_AUX_Check_List_Pats6_2sym , arg0);
}
}
aterm * lf_AUX_Check_List_Pats6_1( aterm * arg0) {
PROF( prof_lf_AUX_Check_List_Pats6_1);
return make_nf1( lf_AUX_Check_List_Pats6_1sym , arg0);
}

