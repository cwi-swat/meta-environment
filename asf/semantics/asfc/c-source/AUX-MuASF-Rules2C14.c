#include "support.h"
static asymbol * lf_AUX_MuASF_Rules2C14_3sym;
static aterm * lf_AUX_MuASF_Rules2C14_3( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5);
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * lf_AUX_MuASF_Rules2C14_1sym;
static aterm * lf_AUX_MuASF_Rules2C14_1( aterm * arg1);
static asymbol * lf_AUX_MuASF_Rules2C14_2sym;
static aterm * lf_AUX_MuASF_Rules2C14_2( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
void register_AUX_MuASF_Rules2C14( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Rules2C14_3sym= TmkSymbol( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"listpatterns2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"Expression\"),ql(\",\"))" , SYM_STRING);
lf_AUX_MuASF_Rules2C14_1sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
lf_AUX_MuASF_Rules2C14_2sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_MuASF_Rules2C14_1 , lf_AUX_MuASF_Rules2C14_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Rules2C14_2 , lf_AUX_MuASF_Rules2C14_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"listpatterns2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Rules2C14_3 , lf_AUX_MuASF_Rules2C14_3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Expression\"),ql(\",\"))") , lf4 , lf4sym);
}
void resolve_AUX_MuASF_Rules2C14( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++d\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++d\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"listpattern2cstats\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"listpattern2cstats\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
}
aterm * lf_AUX_MuASF_Rules2C14_3( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4) {
{
aterm * tmp[14];
PROF( prof_lf_AUX_MuASF_Rules2C14_3);
if( check_sym( arg0 , lf_AUX_MuASF_Rules2C14_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg3 , lf_AUX_MuASF_Rules2C14_2sym)) {
{
aterm * atmp30= arg_0( arg3);
t_protect( atmp00);
if( is_single_element( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
t_protect( tmp[ 0]);
t_protect( arg1);
t_protect( arg2);
t_protect( atmp30);
t_protect( arg4);
tmp[ 1]= ( * ef3)( tmp[ 0] , arg1 , arg2 , lf_AUX_MuASF_Rules2C14_2( make_list( atmp30)) , arg4);
if( check_sym( tmp[ 1] , ef4sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
tmp[ 3]= arg_1( tmp[ 1]);
tmp[ 4]= arg_2( tmp[ 1]);
tmp[ 5]= arg_3( tmp[ 1]);
if( check_sym( tmp[ 2] , ef5sym)) {
tmp[ 6]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 6] , lf4sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
t_protect( tmp[ 7]);
if( is_single_element( tmp[ 7])) {
t_protect( tmp[ 7]);
tmp[ 8]= list_head( tmp[ 7]);
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 8]);
return ( * ef1)( ( * ef2)( tmp[ 3] , tmp[ 4]) , tmp[ 5]);
}
}
}
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
t_protect( atmp00);
tmp[ 1]= list_tail( atmp00);
t_protect( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
t_protect( tmp[ 0]);
t_protect( arg1);
t_protect( arg2);
t_protect( atmp30);
t_protect( arg4);
tmp[ 2]= ( * ef3)( tmp[ 0] , arg1 , arg2 , lf_AUX_MuASF_Rules2C14_2( make_list( atmp30)) , arg4);
if( check_sym( tmp[ 2] , ef4sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
tmp[ 5]= arg_2( tmp[ 2]);
tmp[ 6]= arg_3( tmp[ 2]);
if( check_sym( tmp[ 3] , ef5sym)) {
tmp[ 7]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 7] , lf4sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
t_protect( tmp[ 8]);
if( is_single_element( tmp[ 8])) {
t_protect( tmp[ 8]);
tmp[ 9]= list_head( tmp[ 8]);
t_protect( tmp[ 1]);
t_protect( arg1);
t_protect( arg2);
t_protect( atmp30);
t_protect( tmp[ 6]);
tmp[ 10]= lf_AUX_MuASF_Rules2C14_3( lf_AUX_MuASF_Rules2C14_1( make_list( tmp[ 1])) , arg1 , arg2 , lf_AUX_MuASF_Rules2C14_2( make_list( atmp30)) , tmp[ 6]);
if( check_sym( tmp[ 10] , ef1sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
tmp[ 12]= arg_1( tmp[ 10]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
tmp[ 13]= ( * ef2)( tmp[ 4] , tmp[ 5]);
t_protect( tmp[ 11]);
t_protect( tmp[ 12]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
return ( * ef1)( ( * ef6)( tmp[ 11] , tmp[ 13]) , tmp[ 12]);
}
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 9]);
}
}
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
return make_nf5( lf_AUX_MuASF_Rules2C14_3sym , arg0 , arg1 , arg2 , arg3 , arg4);
}
}
aterm * lf_AUX_MuASF_Rules2C14_2( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C14_2);
return make_nf1( lf_AUX_MuASF_Rules2C14_2sym , arg0);
}
aterm * lf_AUX_MuASF_Rules2C14_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C14_1);
return make_nf1( lf_AUX_MuASF_Rules2C14_1sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}

