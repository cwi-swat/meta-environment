#include "support.h"
static asymbol * lf_AUX_C_Basics19_1sym;
static aterm * lf_AUX_C_Basics19_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_C_Basics19( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_C_Basics19_1sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-name\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-name\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics19_1 , lf_AUX_C_Basics19_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_C_Basics19( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_C_Basics19_1( aterm * arg0) {
{
aterm * tmp[5];
PROF( prof_lf_AUX_C_Basics19_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( m_is_single_element( atmp000)) {
t_protect( atmp000);
if( term_equal( list_head( atmp000) , make_char( 45))) {
t_unprotect( arg0);
return ( * ef2)( lf2( make_list( make_char( 95))));
}
tmp[ 0]= m_list_head( atmp000);
t_protect( tmp[ 0]);
if( ! term_equal( ( * ef1)( lf2( make_list( tmp[ 0]))) , ( * ef1)( lf2( make_list( make_char( 45)))))) {
t_unprotect( arg0);
return ( * ef2)( lf2( make_list( tmp[ 0])));
}
t_unprotect( tmp[ 0]);
}
{
if( m_not_empty_list( atmp000)) {
t_protect( atmp000);
if( term_equal( list_head( atmp000) , make_char( 45))) {
tmp[ 0]= m_list_tail( atmp000);
t_protect( tmp[ 0]);
tmp[ 1]= lf_AUX_C_Basics19_1( ( * ef1)( lf2( make_list( tmp[ 0]))));
if( check_sym( tmp[ 1] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf2sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
t_protect( tmp[ 3]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
return ( * ef2)( lf2( cons( make_list( make_char( 95)) , make_list( tmp[ 3]))));
}
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
tmp[ 0]= m_list_head( atmp000);
tmp[ 1]= m_list_tail( atmp000);
t_protect( tmp[ 0]);
if( ! term_equal( ( * ef1)( lf2( make_list( tmp[ 0]))) , ( * ef1)( lf2( make_list( make_char( 45)))))) {
t_protect( tmp[ 1]);
tmp[ 2]= lf_AUX_C_Basics19_1( ( * ef1)( lf2( make_list( tmp[ 1]))));
if( check_sym( tmp[ 2] , ef2sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf2sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
t_protect( tmp[ 4]);
t_unprotect( arg0);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( lf2( cons( make_list( tmp[ 0]) , make_list( tmp[ 4]))));
}
}
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
}
}
}
}
}
return make_nf1( lf_AUX_C_Basics19_1sym , arg0);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

