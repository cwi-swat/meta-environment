#include "support.h"
static asymbol * lf_AUX_MuASF_Basics24_2sym;
static aterm * lf_AUX_MuASF_Basics24_2( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf_AUX_MuASF_Basics24_1sym;
static aterm * lf_AUX_MuASF_Basics24_1( aterm * arg1);
void register_AUX_MuASF_Basics24( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Basics24_2sym= TmkSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-list-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf_AUX_MuASF_Basics24_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_MuASF_Basics24_1 , lf_AUX_MuASF_Basics24_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-list-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics24_2 , lf_AUX_MuASF_Basics24_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
}
void resolve_AUX_MuASF_Basics24( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Basics24_2( aterm * arg0) {
{
aterm * tmp[3];
PROF( prof_lf_AUX_MuASF_Basics24_2);
if( check_sym( arg0 , lf_AUX_MuASF_Basics24_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( m_is_single_element( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
t_unprotect( arg0);
return tmp[ 0];
}
if( m_not_empty_list( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
tmp[ 1]= m_list_tail( atmp00);
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
tmp[ 2]= lf_AUX_MuASF_Basics24_2( lf_AUX_MuASF_Basics24_1( make_list( tmp[ 1])));
t_unprotect( arg0);
t_unprotect( tmp[ 1]);
return ( * ef1)( ( * ef2)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf_AUX_MuASF_Basics24_1( cons( make_list( tmp[ 0]) , make_list( tmp[ 2]))));
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
}
}
return make_nf1( lf_AUX_MuASF_Basics24_2sym , arg0);
}
}
aterm * lf_AUX_MuASF_Basics24_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Basics24_1);
return make_nf1( lf_AUX_MuASF_Basics24_1sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

