#include "support.h"
static asymbol * lf_AUX_MuASF_Rules2C15_3sym;
static aterm * lf_AUX_MuASF_Rules2C15_3( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * lf_AUX_MuASF_Rules2C15_1sym;
static aterm * lf_AUX_MuASF_Rules2C15_1( aterm * arg1);
static asymbol * lf_AUX_MuASF_Rules2C15_2sym;
static aterm * lf_AUX_MuASF_Rules2C15_2( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef20sym;
static funcptr ef20;
static asymbol * ef21sym;
static funcptr ef21;
static asymbol * lf6sym;
static aterm * lf6( aterm * arg1);
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef3sym;
static funcptr ef3;
void register_AUX_MuASF_Rules2C15( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Rules2C15_3sym= TmkSymbol( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"listpatterns2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"AInt\"),ql(\",\"))" , SYM_STRING);
lf_AUX_MuASF_Rules2C15_1sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
lf_AUX_MuASF_Rules2C15_2sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf6sym= TmkSymbol( "listtype(sort(\"Expression\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_MuASF_Rules2C15_1 , lf_AUX_MuASF_Rules2C15_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Rules2C15_2 , lf_AUX_MuASF_Rules2C15_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"listpatterns2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Rules2C15_3 , lf_AUX_MuASF_Rules2C15_3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"AInt\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf5 , lf5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Expression\"),ql(\",\"))") , lf6 , lf6sym);
}
void resolve_AUX_MuASF_Rules2C15( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++d\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++d\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"listpattern2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"listpattern2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-same-list-pat\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-same-list-pat\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"get-first-vf-path\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"get-first-vf-path\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-atmp\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-atmp\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef20= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef21= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Rules2C15_3( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4) {
{
aterm * tmp[23];
PROF( prof_lf_AUX_MuASF_Rules2C15_3);
if( check_sym( arg0 , lf_AUX_MuASF_Rules2C15_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg3 , lf_AUX_MuASF_Rules2C15_2sym)) {
{
aterm * atmp30= arg_0( arg3);
if( m_not_empty_list( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
tmp[ 1]= m_list_tail( atmp00);
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 0]);
t_protect( tmp[ 1]);
tmp[ 2]= ( * ef7)( lf_AUX_MuASF_Rules2C15_1( cons( make_list( tmp[ 0]) , make_list( tmp[ 1]))));
if( check_sym( tmp[ 2] , ef8sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
if( check_sym( tmp[ 3] , lf_AUX_MuASF_Rules2C15_1sym)) {
tmp[ 5]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf_AUX_MuASF_Rules2C15_1sym)) {
tmp[ 6]= arg_0( tmp[ 4]);
if( m_not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
t_protect( arg1);
t_protect( arg2);
t_protect( atmp30);
t_protect( arg4);
tmp[ 7]= ( * ef4)( lf_AUX_MuASF_Rules2C15_1( make_list( tmp[ 5])) , arg1 , arg2 , lf_AUX_MuASF_Rules2C15_2( make_list( atmp30)) , arg4);
if( check_sym( tmp[ 7] , ef5sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
tmp[ 9]= arg_1( tmp[ 7]);
tmp[ 10]= arg_2( tmp[ 7]);
t_protect( tmp[ 5]);
tmp[ 11]= ( * ef9)( lf_AUX_MuASF_Rules2C15_1( make_list( tmp[ 5])));
if( check_sym( tmp[ 11] , ef10sym)) {
tmp[ 12]= arg_0( tmp[ 11]);
tmp[ 13]= arg_1( tmp[ 11]);
if( check_sym( tmp[ 12] , ef11sym)) {
tmp[ 14]= arg_0( tmp[ 12]);
if( check_sym( tmp[ 13] , lf4sym)) {
tmp[ 15]= arg_0( tmp[ 13]);
t_protect( tmp[ 15]);
tmp[ 16]= ( * ef12)( ( * ef13)( ( * ef14)( lf4( make_list( tmp[ 15])))));
t_protect( tmp[ 6]);
t_protect( arg1);
t_protect( arg2);
t_protect( atmp30);
t_protect( tmp[ 10]);
tmp[ 17]= lf_AUX_MuASF_Rules2C15_3( lf_AUX_MuASF_Rules2C15_1( make_list( tmp[ 6])) , arg1 , arg2 , lf_AUX_MuASF_Rules2C15_2( make_list( atmp30)) , tmp[ 10]);
if( check_sym( tmp[ 17] , ef1sym)) {
tmp[ 18]= arg_0( tmp[ 17]);
tmp[ 19]= arg_1( tmp[ 17]);
t_protect( arg1);
t_protect( tmp[ 16]);
tmp[ 20]= ( * ef15)( ( * ef16)( ( * ef17)( ( * ef18)( arg1 , ( * ef12)( ( * ef19)( ( * ef13)( ( * ef20)( lf5( cons( make_list( make_char( 97)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 103)) , cons( make_list( make_char( 95)) , make_list( make_char( 48))))))))) , ( * ef21)( lf6( make_list( tmp[ 16])))))))));
t_protect( tmp[ 20]);
t_protect( tmp[ 18]);
tmp[ 21]= ( * ef6)( tmp[ 20] , tmp[ 18]);
t_protect( tmp[ 8]);
t_protect( tmp[ 9]);
tmp[ 22]= ( * ef3)( tmp[ 8] , tmp[ 9]);
t_protect( tmp[ 19]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 20]);
return ( * ef1)( ( * ef6)( tmp[ 22] , tmp[ 21]) , tmp[ 19]);
}
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 16]);
}
}
}
t_unprotect( tmp[ 11]);
}
t_unprotect( tmp[ 7]);
}
}
}
}
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
return ( * ef1)( ( * ef2)( ) , arg4);
}
if( m_is_single_element( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
t_protect( tmp[ 0]);
t_protect( arg1);
t_protect( arg2);
t_protect( atmp30);
t_protect( arg4);
tmp[ 1]= ( * ef4)( lf_AUX_MuASF_Rules2C15_1( make_list( tmp[ 0])) , arg1 , arg2 , lf_AUX_MuASF_Rules2C15_2( make_list( atmp30)) , arg4);
if( check_sym( tmp[ 1] , ef5sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
tmp[ 3]= arg_1( tmp[ 1]);
tmp[ 4]= arg_2( tmp[ 1]);
t_protect( tmp[ 2]);
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
return ( * ef1)( ( * ef3)( tmp[ 2] , tmp[ 3]) , tmp[ 4]);
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
}
}
}
}
return make_nf5( lf_AUX_MuASF_Rules2C15_3sym , arg0 , arg1 , arg2 , arg3 , arg4);
}
}
aterm * lf6( aterm * arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
aterm * lf_AUX_MuASF_Rules2C15_2( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C15_2);
return make_nf1( lf_AUX_MuASF_Rules2C15_2sym , arg0);
}
aterm * lf_AUX_MuASF_Rules2C15_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C15_1);
return make_nf1( lf_AUX_MuASF_Rules2C15_1sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}

