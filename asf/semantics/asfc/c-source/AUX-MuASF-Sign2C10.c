#include "support.h"
static asymbol * lf_AUX_MuASF_Sign2C10_2sym;
static aterm * lf_AUX_MuASF_Sign2C10_2( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf_AUX_MuASF_Sign2C10_1sym;
static aterm * lf_AUX_MuASF_Sign2C10_1( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
void register_AUX_MuASF_Sign2C10( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Sign2C10_2sym= TmkSymbol( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"namepairs2lstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_MuASF_Sign2C10_1sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Sign2C10_1 , lf_AUX_MuASF_Sign2C10_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"namepairs2lstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Sign2C10_2 , lf_AUX_MuASF_Sign2C10_2sym);
}
void resolve_AUX_MuASF_Sign2C10( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"namepair2lstats\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"NamePair\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"namepair2lstats\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"NamePair\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
}
aterm * lf_AUX_MuASF_Sign2C10_2( aterm * arg0) {
{
aterm * tmp[2];
PROF( prof_lf_AUX_MuASF_Sign2C10_2);
if( check_sym( arg0 , lf_AUX_MuASF_Sign2C10_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( m_not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_prefix( atmp00);
if( m_not_empty_list( tmp[ 0])) {
t_protect( atmp00);
tmp[ 1]= list_last( atmp00);
t_unprotect( arg0);
return ( * ef3)( lf_AUX_MuASF_Sign2C10_2( lf_AUX_MuASF_Sign2C10_1( make_list( tmp[ 0]))) , ( * ef2)( tmp[ 1]));
}
t_unprotect( tmp[ 0]);
}
else {
t_unprotect( arg0);
return ( * ef1)( );
}
if( m_is_single_element( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
t_unprotect( arg0);
return ( * ef2)( tmp[ 0]);
}
}
}
return make_nf1( lf_AUX_MuASF_Sign2C10_2sym , arg0);
}
}
aterm * lf_AUX_MuASF_Sign2C10_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Sign2C10_1);
return make_nf1( lf_AUX_MuASF_Sign2C10_1sym , arg0);
}

