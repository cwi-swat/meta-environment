#include "support.h"
static asymbol * lf_AUX_MuASF_Rules2C16_3sym;
static aterm * lf_AUX_MuASF_Rules2C16_3( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * lf_AUX_MuASF_Rules2C16_1sym;
static aterm * lf_AUX_MuASF_Rules2C16_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * lf6sym;
static aterm * lf6( aterm * arg1);
static asymbol * lf_AUX_MuASF_Rules2C16_2sym;
static aterm * lf_AUX_MuASF_Rules2C16_2( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
void register_AUX_MuASF_Rules2C16( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Rules2C16_3sym= TmkSymbol( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"listpattern2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"AInt\"),ql(\",\"))" , SYM_STRING);
lf_AUX_MuASF_Rules2C16_1sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , SYM_STRING);
lf6sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf_AUX_MuASF_Rules2C16_2sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_MuASF_Rules2C16_1 , lf_AUX_MuASF_Rules2C16_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Rules2C16_2 , lf_AUX_MuASF_Rules2C16_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"listpattern2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Rules2C16_3 , lf_AUX_MuASF_Rules2C16_3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"AInt\"),ql(\",\"))") , lf5 , lf5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf6 , lf6sym);
}
void resolve_AUX_MuASF_Rules2C16( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"listpattern2cstats\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"listpattern2cstats\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Rules2C16_3( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4) {
{
aterm * tmp[22];
PROF( prof_lf_AUX_MuASF_Rules2C16_3);
if( check_sym( arg0 , lf_AUX_MuASF_Rules2C16_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg3 , lf_AUX_MuASF_Rules2C16_2sym)) {
{
aterm * atmp30= arg_0( arg3);
if( m_not_empty_list( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
tmp[ 1]= m_list_tail( atmp00);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
tmp[ 4]= arg_2( tmp[ 0]);
tmp[ 5]= arg_3( tmp[ 0]);
tmp[ 6]= arg_4( tmp[ 0]);
if( check_sym( tmp[ 2] , lf4sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf6sym)) {
tmp[ 8]= arg_0( tmp[ 3]);
if( m_not_empty_list( tmp[ 7])) {
tmp[ 9]= m_list_head( tmp[ 7]);
tmp[ 10]= m_list_tail( tmp[ 7]);
if( check_sym( tmp[ 9] , ef2sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
if( check_sym( tmp[ 11] , lf4sym)) {
tmp[ 12]= arg_0( tmp[ 11]);
if( m_not_empty_list( tmp[ 12])) {
tmp[ 13]= m_list_head( tmp[ 12]);
tmp[ 14]= m_list_tail( tmp[ 12]);
if( m_not_empty_list( tmp[ 14])) {
if( check_sym( tmp[ 13] , ef3sym)) {
tmp[ 15]= arg_0( tmp[ 13]);
tmp[ 16]= arg_1( tmp[ 13]);
if( check_sym( tmp[ 16] , lf5sym)) {
tmp[ 17]= arg_0( tmp[ 16]);
t_protect( tmp[ 14]);
t_protect( tmp[ 10]);
t_protect( tmp[ 8]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( tmp[ 1]);
t_protect( arg1);
t_protect( arg2);
t_protect( atmp30);
t_protect( arg4);
tmp[ 18]= ( * ef5)( ( * ef6)( ) , lf4( make_list( tmp[ 14])) , lf_AUX_MuASF_Rules2C16_1( cons( make_list( ( * ef1)( lf4( make_list( tmp[ 10])) , lf6( make_list( tmp[ 8])) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 1]))) , arg1 , arg2 , lf_AUX_MuASF_Rules2C16_2( make_list( atmp30)) , arg4);
if( check_sym( tmp[ 18] , ef4sym)) {
tmp[ 19]= arg_0( tmp[ 18]);
tmp[ 20]= arg_1( tmp[ 18]);
tmp[ 21]= arg_2( tmp[ 18]);
t_protect( tmp[ 19]);
t_protect( tmp[ 20]);
t_protect( tmp[ 21]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 18]);
return ( * ef4)( tmp[ 19] , tmp[ 20] , tmp[ 21]);
}
t_unprotect( tmp[ 18]);
}
}
}
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 13]);
}
}
}
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 9]);
}
}
}
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
}
}
}
}
return make_nf5( lf_AUX_MuASF_Rules2C16_3sym , arg0 , arg1 , arg2 , arg3 , arg4);
}
}
aterm * lf_AUX_MuASF_Rules2C16_2( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C16_2);
return make_nf1( lf_AUX_MuASF_Rules2C16_2sym , arg0);
}
aterm * lf6( aterm * arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf_AUX_MuASF_Rules2C16_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C16_1);
return make_nf1( lf_AUX_MuASF_Rules2C16_1sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}

