#include "support.h"
static asymbol * lf_AUX_MuASF_Basics7_2sym;
static aterm * lf_AUX_MuASF_Basics7_2( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf_AUX_MuASF_Basics7_1sym;
static aterm * lf_AUX_MuASF_Basics7_1( aterm * arg1);
void register_AUX_MuASF_Basics7( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Basics7_2sym= TmkSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-conditional-rule\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_MuASF_Basics7_1sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_MuASF_Basics7_1 , lf_AUX_MuASF_Basics7_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-conditional-rule\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics7_2 , lf_AUX_MuASF_Basics7_2sym);
}
void resolve_AUX_MuASF_Basics7( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Basics7_2( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_MuASF_Basics7_2);
if( check_sym( arg0 , lf_AUX_MuASF_Basics7_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
{
aterm * atmp11= arg_1( arg1);
if( m_not_empty_list( atmp00)) {
t_protect( atmp00);
t_protect( atmp10);
t_protect( atmp11);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( ( * ef3)( lf_AUX_MuASF_Basics7_1( make_list( atmp00))) , atmp10 , atmp11);
}
}
}
}
if( check_sym( arg1 , ef4sym)) {
{
aterm * atmp10= arg_0( arg1);
{
aterm * atmp11= arg_1( arg1);
if( m_not_empty_list( atmp00)) {
t_protect( atmp00);
t_protect( atmp10);
t_protect( atmp11);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef5)( ( * ef3)( lf_AUX_MuASF_Basics7_1( make_list( atmp00))) , atmp10 , atmp11);
}
}
}
}
t_protect( atmp00);
if( ! not_empty_list( atmp00)) {
t_unprotect( arg0);
return arg1;
}
}
}
return make_nf2( lf_AUX_MuASF_Basics7_2sym , arg0 , arg1);
}
aterm * lf_AUX_MuASF_Basics7_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Basics7_1);
return make_nf1( lf_AUX_MuASF_Basics7_1sym , arg0);
}

