#include "support.h"
static asymbol * lf_AUX_MuASF_Basics19_2sym;
static aterm * lf_AUX_MuASF_Basics19_2( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf_AUX_MuASF_Basics19_1sym;
static aterm * lf_AUX_MuASF_Basics19_1( aterm * arg1);
void register_AUX_MuASF_Basics19( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Basics19_2sym= TmkSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_MuASF_Basics19_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_MuASF_Basics19_1 , lf_AUX_MuASF_Basics19_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics19_2 , lf_AUX_MuASF_Basics19_2sym);
}
void resolve_AUX_MuASF_Basics19( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Basics19_2( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_MuASF_Basics19_2);
if( check_sym( arg1 , lf_AUX_MuASF_Basics19_1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( m_not_empty_list( atmp10)) {
t_protect( atmp10);
t_unprotect( arg1);
return ( * ef2)( arg0 , lf_AUX_MuASF_Basics19_1( make_list( atmp10)));
}
else {
t_unprotect( arg1);
return ( * ef1)( arg0);
}
}
}
return make_nf2( lf_AUX_MuASF_Basics19_2sym , arg0 , arg1);
}
aterm * lf_AUX_MuASF_Basics19_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Basics19_1);
return make_nf1( lf_AUX_MuASF_Basics19_1sym , arg0);
}

