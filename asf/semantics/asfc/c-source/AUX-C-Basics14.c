#include "support.h"
static asymbol * lf_AUX_C_Basics14_1sym;
static aterm * lf_AUX_C_Basics14_1( aterm * arg1 , aterm * arg2);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_C_Basics14( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_C_Basics14_1sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[l(\"celookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"TE-pair\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"celookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics14_1 , lf_AUX_C_Basics14_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"TE-pair\"),ql(\",\"))") , lf2 , lf2sym);
}
void resolve_AUX_C_Basics14( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_C_Basics14_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[4];
PROF( prof_lf_AUX_C_Basics14_1);
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
{
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
if( m_term_equal( arg0 , tmp[ 2])) {
t_protect( tmp[ 3]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
return ( * ef3)( tmp[ 3]);
}
else {
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return lf_AUX_C_Basics14_1( arg0 , ( * ef1)( lf2( make_list( tmp[ 1]))));
}
}
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
return make_nf2( lf_AUX_C_Basics14_1sym , arg0 , arg1);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

