#include "support.h"
static asymbol * lf_AUX_MuASF_Basics5_1sym;
static aterm * lf_AUX_MuASF_Basics5_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_MuASF_Basics5( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Basics5_1sym= TmkSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics5_1 , lf_AUX_MuASF_Basics5_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf2 , lf2sym);
}
void resolve_AUX_MuASF_Basics5( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Basics5_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Basics5_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_unprotect( arg0);
return ( * ef2)( lf2( make_list( null( ))));
}
}
if( check_sym( arg0 , ef3sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , lf2sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( m_not_empty_list( atmp010)) {
t_protect( atmp010);
t_unprotect( arg0);
return ( * ef2)( lf2( make_list( atmp010)));
}
}
}
}
}
}
return make_nf1( lf_AUX_MuASF_Basics5_1sym , arg0);
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

