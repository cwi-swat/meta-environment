#include "support.h"
static asymbol * lf_AUX_MuASF_Term2C3_2sym;
static aterm * lf_AUX_MuASF_Term2C3_2( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5 , aterm * arg6 , aterm * arg7 , aterm * arg8);
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef20sym;
static funcptr ef20;
static asymbol * lf_AUX_MuASF_Term2C3_1sym;
static aterm * lf_AUX_MuASF_Term2C3_1( aterm * arg1);
void register_AUX_MuASF_Term2C3( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Term2C3_2sym= TmkSymbol( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"term2carg\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Expression\"),ql(\",\"))" , SYM_STRING);
lf_AUX_MuASF_Term2C3_1sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Term2C3_1 , lf_AUX_MuASF_Term2C3_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"term2carg\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Term2C3_2 , lf_AUX_MuASF_Term2C3_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Expression\"),ql(\",\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf4 , lf4sym);
}
void resolve_AUX_MuASF_Term2C3( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"cecontains\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"cecontains\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"celookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"celookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-protect\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-protect\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"return\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"return\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-unprotect\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-unprotect\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++up\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++up\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef20= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"term2carg2\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"term2carg2\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Term2C3_2( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5 , aterm * arg6 , aterm * arg7) {
{
aterm * tmp[10];
PROF( prof_lf_AUX_MuASF_Term2C3_2);
if( check_sym( arg0 , ef1sym)) {
if( check_sym( arg7 , lf_AUX_MuASF_Term2C3_1sym)) {
{
aterm * atmp70= arg_0( arg7);
tmp[ 0]= ( * ef4)( ( * ef6)( ( * ef7)( lf4( cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 108)) , make_list( make_char( 116)))))))))));
t_protect( arg5);
t_protect( tmp[ 0]);
if( ! term_equal( arg5 , tmp[ 0])) {
t_protect( arg1);
tmp[ 1]= ( * ef8)( arg1);
if( m_term_equal( tmp[ 1] , arg0)) {
t_protect( arg1);
t_protect( arg3);
t_protect( arg0);
if( term_equal( ( * ef10)( arg1 , arg3) , arg0)) {
t_protect( arg1);
t_protect( arg3);
tmp[ 2]= ( * ef11)( arg1 , arg3);
if( check_sym( tmp[ 2] , ef12sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
t_protect( tmp[ 3]);
tmp[ 4]= ( * ef13)( tmp[ 3]);
t_protect( tmp[ 3]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg5);
t_unprotect( arg6);
t_unprotect( arg7);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( lf3( make_list( tmp[ 3]))) , tmp[ 4] , arg4);
}
t_unprotect( tmp[ 2]);
}
}
t_protect( tmp[ 1]);
if( term_equal( tmp[ 1] , ( * ef9)( ))) {
t_protect( arg1);
t_protect( arg3);
t_protect( arg0);
if( term_equal( ( * ef10)( arg1 , arg3) , arg0)) {
t_protect( arg1);
t_protect( arg3);
tmp[ 2]= ( * ef11)( arg1 , arg3);
if( check_sym( tmp[ 2] , ef12sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
t_protect( tmp[ 3]);
tmp[ 4]= ( * ef13)( tmp[ 3]);
t_protect( tmp[ 3]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg5);
t_unprotect( arg6);
t_unprotect( arg7);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef3)( lf3( make_list( ( * ef4)( ( * ef5)( ( * ef6)( ( * ef7)( lf4( cons( make_list( make_char( 109)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 107)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116))))))))))))) , ( * ef3)( lf3( make_list( tmp[ 3])))))))) , tmp[ 4] , arg4);
}
t_unprotect( tmp[ 2]);
}
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
}
}
if( check_sym( arg0 , ef9sym)) {
if( check_sym( arg5 , ef4sym)) {
{
aterm * atmp50= arg_0( arg5);
if( check_sym( atmp50 , ef6sym)) {
{
aterm * atmp500= arg_0( atmp50);
if( check_sym( atmp500 , ef7sym)) {
{
aterm * atmp5000= arg_0( atmp500);
if( check_sym( atmp5000 , lf4sym)) {
{
aterm * atmp50000= arg_0( atmp5000);
if( check_sym( arg7 , lf_AUX_MuASF_Term2C3_1sym)) {
{
aterm * atmp70= arg_0( arg7);
if( m_not_empty_list( atmp50000)) {
t_protect( atmp50000);
if( term_equal( list_head( atmp50000) , make_char( 114))) {
tmp[ 0]= m_list_tail( atmp50000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 101))) {
tmp[ 1]= m_list_tail( tmp[ 0]);
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_head( tmp[ 1]) , make_char( 115))) {
tmp[ 2]= m_list_tail( tmp[ 1]);
if( m_not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
if( term_equal( list_head( tmp[ 2]) , make_char( 117))) {
tmp[ 3]= m_list_tail( tmp[ 2]);
if( m_not_empty_list( tmp[ 3])) {
t_protect( tmp[ 3]);
if( term_equal( list_head( tmp[ 3]) , make_char( 108))) {
tmp[ 4]= m_list_tail( tmp[ 3]);
if( m_is_single_element( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 116))) {
t_protect( arg1);
t_protect( arg3);
if( term_equal( ( * ef10)( arg1 , arg3) , ( * ef1)( ))) {
t_protect( arg1);
t_protect( arg3);
tmp[ 5]= ( * ef11)( arg1 , arg3);
if( check_sym( tmp[ 5] , ef12sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
t_protect( tmp[ 6]);
tmp[ 7]= ( * ef13)( tmp[ 6]);
t_protect( arg6);
tmp[ 8]= ( * ef18)( arg6);
t_protect( tmp[ 7]);
t_protect( tmp[ 8]);
tmp[ 9]= ( * ef19)( tmp[ 7] , tmp[ 8]);
t_protect( tmp[ 6]);
t_protect( tmp[ 6]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg5);
t_unprotect( arg6);
t_unprotect( arg7);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
return ( * ef2)( ( * ef3)( lf3( make_list( tmp[ 6]))) , ( * ef14)( tmp[ 9] , ( * ef15)( ( * ef16)( ( * ef17)( tmp[ 6])))) , arg4);
}
t_unprotect( tmp[ 5]);
}
}
}
t_unprotect( tmp[ 4]);
}
}
t_unprotect( tmp[ 3]);
}
}
t_unprotect( tmp[ 2]);
}
}
t_unprotect( tmp[ 1]);
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
}
}
}
}
}
}
}
if( check_sym( arg7 , lf_AUX_MuASF_Term2C3_1sym)) {
{
aterm * atmp70= arg_0( arg7);
t_protect( arg5);
if( ! term_equal( arg5 , ( * ef4)( ( * ef6)( ( * ef7)( lf4( cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 108)) , make_list( make_char( 116))))))))))))) {
t_protect( arg1);
t_protect( arg3);
if( term_equal( ( * ef10)( arg1 , arg3) , ( * ef1)( ))) {
t_protect( arg1);
t_protect( arg3);
tmp[ 0]= ( * ef11)( arg1 , arg3);
if( check_sym( tmp[ 0] , ef12sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
t_protect( tmp[ 1]);
tmp[ 2]= ( * ef13)( tmp[ 1]);
t_protect( tmp[ 1]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg5);
t_unprotect( arg6);
t_unprotect( arg7);
t_unprotect( tmp[ 0]);
return ( * ef2)( ( * ef3)( lf3( make_list( tmp[ 1]))) , tmp[ 2] , arg4);
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
if( check_sym( arg7 , lf_AUX_MuASF_Term2C3_1sym)) {
{
aterm * atmp70= arg_0( arg7);
t_protect( atmp70);
t_unprotect( arg7);
return ( * ef20)( arg0 , arg1 , arg2 , arg3 , arg4 , arg5 , arg6 , lf_AUX_MuASF_Term2C3_1( make_list( atmp70)));
}
}
return make_nf8( lf_AUX_MuASF_Term2C3_2sym , arg0 , arg1 , arg2 , arg3 , arg4 , arg5 , arg6 , arg7);
}
}
aterm * lf_AUX_MuASF_Term2C3_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Term2C3_1);
return make_nf1( lf_AUX_MuASF_Term2C3_1sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}

