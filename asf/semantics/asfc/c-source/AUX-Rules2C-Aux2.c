#include "support.h"
static asymbol * lf_AUX_Rules2C_Aux2_1sym;
static aterm * lf_AUX_Rules2C_Aux2_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * lf6sym;
static aterm * lf6( aterm * arg1);
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * lf7sym;
static aterm * lf7( aterm * arg1);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
void register_AUX_Rules2C_Aux2( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Rules2C_Aux2_1sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"AInt\"),ql(\",\"))" , SYM_STRING);
lf6sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf7sym= TmkSymbol( "listtype(sort(\"TE-pair\"),ql(\",\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux2_1 , lf_AUX_Rules2C_Aux2_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"AInt\"),ql(\",\"))") , lf5 , lf5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf6 , lf6sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"TE-pair\"),ql(\",\"))") , lf7 , lf7sym);
}
void resolve_AUX_Rules2C_Aux2( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"code-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"code-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"funargs2cexp\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"funargs2cexp\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Rules2C_Aux2_1( aterm * arg0) {
{
aterm * tmp[9];
PROF( prof_lf_AUX_Rules2C_Aux2_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
t_protect( atmp00);
tmp[ 0]= ( * ef3)( atmp00);
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf4sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( m_not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
tmp[ 3]= ( * ef5)( lf4( make_list( tmp[ 2])) , lf5( make_list( ( * ef6)( lf6( make_list( make_char( 48)))))));
if( check_sym( tmp[ 3] , ef7sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
tmp[ 5]= arg_1( tmp[ 3]);
if( check_sym( tmp[ 4] , ef8sym)) {
tmp[ 6]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
t_protect( tmp[ 2]);
tmp[ 8]= ( * ef9)( lf4( make_list( tmp[ 2])) , ( * ef6)( lf6( make_list( make_char( 48)))));
t_protect( tmp[ 7]);
t_protect( atmp01);
t_protect( tmp[ 5]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 3]);
return ( * ef2)( lf2( make_list( tmp[ 7])) , lf3( make_list( null( ))) , atmp01 , tmp[ 5] , tmp[ 8]);
}
}
}
t_unprotect( tmp[ 3]);
}
}
}
t_unprotect( tmp[ 0]);
t_protect( atmp00);
if( term_equal( ( * ef3)( atmp00) , ( * ef4)( lf4( make_list( null( )))))) {
t_protect( atmp01);
t_unprotect( arg0);
return ( * ef2)( lf2( make_list( null( ))) , lf3( make_list( null( ))) , atmp01 , ( * ef10)( lf7( make_list( null( )))) , ( * ef10)( lf7( make_list( null( )))));
}
}
}
}
if( check_sym( arg0 , ef11sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef12sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf3sym)) {
{
aterm * atmp0000= arg_0( atmp000);
{
aterm * atmp01= arg_1( arg0);
{
aterm * atmp02= arg_2( arg0);
t_protect( atmp01);
tmp[ 0]= ( * ef3)( atmp01);
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf4sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( m_not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
tmp[ 3]= ( * ef5)( lf4( make_list( tmp[ 2])) , lf5( make_list( ( * ef6)( lf6( make_list( make_char( 48)))))));
if( check_sym( tmp[ 3] , ef7sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
tmp[ 5]= arg_1( tmp[ 3]);
if( check_sym( tmp[ 4] , ef8sym)) {
tmp[ 6]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
t_protect( tmp[ 2]);
tmp[ 8]= ( * ef9)( lf4( make_list( tmp[ 2])) , ( * ef6)( lf6( make_list( make_char( 48)))));
t_protect( tmp[ 7]);
t_protect( atmp0000);
t_protect( atmp02);
t_protect( tmp[ 5]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 3]);
return ( * ef2)( lf2( make_list( tmp[ 7])) , lf3( make_list( atmp0000)) , atmp02 , tmp[ 5] , tmp[ 8]);
}
}
}
t_unprotect( tmp[ 3]);
}
}
}
t_unprotect( tmp[ 0]);
t_protect( atmp01);
if( term_equal( ( * ef3)( atmp01) , ( * ef4)( lf4( make_list( null( )))))) {
t_protect( atmp0000);
t_protect( atmp02);
t_unprotect( arg0);
return ( * ef2)( lf2( make_list( null( ))) , lf3( make_list( atmp0000)) , atmp02 , ( * ef10)( lf7( make_list( null( )))) , ( * ef10)( lf7( make_list( null( )))));
}
}
}
}
}
}
}
}
}
if( check_sym( arg0 , ef13sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
t_protect( atmp00);
tmp[ 0]= ( * ef3)( atmp00);
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf4sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( m_not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
tmp[ 3]= ( * ef5)( lf4( make_list( tmp[ 2])) , lf5( make_list( ( * ef6)( lf6( make_list( make_char( 48)))))));
if( check_sym( tmp[ 3] , ef7sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
tmp[ 5]= arg_1( tmp[ 3]);
if( check_sym( tmp[ 4] , ef8sym)) {
tmp[ 6]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
t_protect( tmp[ 2]);
tmp[ 8]= ( * ef9)( lf4( make_list( tmp[ 2])) , ( * ef6)( lf6( make_list( make_char( 48)))));
t_protect( tmp[ 7]);
t_protect( atmp01);
t_protect( tmp[ 5]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 3]);
return ( * ef2)( lf2( make_list( tmp[ 7])) , lf3( make_list( null( ))) , atmp01 , tmp[ 5] , tmp[ 8]);
}
}
}
t_unprotect( tmp[ 3]);
}
}
}
t_unprotect( tmp[ 0]);
t_protect( atmp00);
if( term_equal( ( * ef3)( atmp00) , ( * ef4)( lf4( make_list( null( )))))) {
t_protect( atmp01);
t_unprotect( arg0);
return ( * ef2)( lf2( make_list( null( ))) , lf3( make_list( null( ))) , atmp01 , ( * ef10)( lf7( make_list( null( )))) , ( * ef10)( lf7( make_list( null( )))));
}
}
}
}
if( check_sym( arg0 , ef14sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef12sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf3sym)) {
{
aterm * atmp0000= arg_0( atmp000);
{
aterm * atmp01= arg_1( arg0);
{
aterm * atmp02= arg_2( arg0);
t_protect( atmp01);
tmp[ 0]= ( * ef3)( atmp01);
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf4sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( m_not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
tmp[ 3]= ( * ef5)( lf4( make_list( tmp[ 2])) , lf5( make_list( ( * ef6)( lf6( make_list( make_char( 48)))))));
if( check_sym( tmp[ 3] , ef7sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
tmp[ 5]= arg_1( tmp[ 3]);
if( check_sym( tmp[ 4] , ef8sym)) {
tmp[ 6]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
t_protect( tmp[ 2]);
tmp[ 8]= ( * ef9)( lf4( make_list( tmp[ 2])) , ( * ef6)( lf6( make_list( make_char( 48)))));
t_protect( tmp[ 7]);
t_protect( atmp0000);
t_protect( atmp02);
t_protect( tmp[ 5]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 3]);
return ( * ef2)( lf2( make_list( tmp[ 7])) , lf3( make_list( atmp0000)) , atmp02 , tmp[ 5] , tmp[ 8]);
}
}
}
t_unprotect( tmp[ 3]);
}
}
}
t_unprotect( tmp[ 0]);
t_protect( atmp01);
if( term_equal( ( * ef3)( atmp01) , ( * ef4)( lf4( make_list( null( )))))) {
t_protect( atmp0000);
t_protect( atmp02);
t_unprotect( arg0);
return ( * ef2)( lf2( make_list( null( ))) , lf3( make_list( atmp0000)) , atmp02 , ( * ef10)( lf7( make_list( null( )))) , ( * ef10)( lf7( make_list( null( )))));
}
}
}
}
}
}
}
}
}
return make_nf1( lf_AUX_Rules2C_Aux2_1sym , arg0);
}
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf7( aterm * arg0) {
PROF( prof_lf7);
return make_nf1( lf7sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}
aterm * lf6( aterm * arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}

