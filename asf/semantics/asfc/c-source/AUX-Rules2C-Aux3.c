#include "support.h"
static asymbol * lf_AUX_Rules2C_Aux3_3sym;
static aterm * lf_AUX_Rules2C_Aux3_3( aterm * arg1 , aterm * arg2);
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * lf6sym;
static aterm * lf6( aterm * arg1);
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * lf_AUX_Rules2C_Aux3_1sym;
static aterm * lf_AUX_Rules2C_Aux3_1( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux3_2sym;
static aterm * lf_AUX_Rules2C_Aux3_2( aterm * arg1);
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
void register_AUX_Rules2C_Aux3( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Rules2C_Aux3_3sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"code-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"TE-pair\"),ql(\",\"))" , SYM_STRING);
lf6sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux3_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux3_2sym= TmkSymbol( "listtype(sort(\"AInt\"),ql(\",\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_Rules2C_Aux3_1 , lf_AUX_Rules2C_Aux3_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"AInt\"),ql(\",\"))") , lf_AUX_Rules2C_Aux3_2 , lf_AUX_Rules2C_Aux3_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"code-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux3_3 , lf_AUX_Rules2C_Aux3_3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"TE-pair\"),ql(\",\"))") , lf5 , lf5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf6 , lf6sym);
}
void resolve_AUX_Rules2C_Aux3( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-atmp\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-atmp\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"C-env\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"C-env\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"C-env\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"C-env\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Rules2C_Aux3_3( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[19];
PROF( prof_lf_AUX_Rules2C_Aux3_3);
if( check_sym( arg0 , lf_AUX_Rules2C_Aux3_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , lf_AUX_Rules2C_Aux3_2sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
{
t_protect( atmp00);
tmp[ 1]= list_tail( atmp00);
t_protect( atmp10);
if( not_empty_list( atmp10)) {
t_protect( atmp10);
tmp[ 2]= list_prefix( atmp10);
{
t_protect( atmp10);
tmp[ 3]= list_last( atmp10);
t_protect( tmp[ 0]);
tmp[ 4]= ( * ef5)( tmp[ 0]);
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , ( * ef13)( ))) {
t_protect( tmp[ 0]);
if( term_equal( ( * ef14)( tmp[ 0]) , ( * ef15)( lf_AUX_Rules2C_Aux3_1( make_list( null( )))))) {
t_protect( tmp[ 1]);
t_protect( tmp[ 2]);
t_protect( tmp[ 3]);
tmp[ 5]= lf_AUX_Rules2C_Aux3_3( lf_AUX_Rules2C_Aux3_1( make_list( tmp[ 1])) , lf_AUX_Rules2C_Aux3_2( cons( make_list( tmp[ 2]) , make_list( ( * ef7)( tmp[ 3])))));
if( check_sym( tmp[ 5] , ef1sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
tmp[ 7]= arg_1( tmp[ 5]);
if( check_sym( tmp[ 6] , ef2sym)) {
tmp[ 8]= arg_0( tmp[ 6]);
if( check_sym( tmp[ 8] , lf4sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
t_protect( tmp[ 9]);
t_protect( tmp[ 7]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
return ( * ef1)( ( * ef2)( lf4( cons( make_list( ( * ef4)( tmp[ 0] , lf_AUX_Rules2C_Aux3_2( cons( make_list( tmp[ 2]) , make_list( tmp[ 3]))))) , make_list( tmp[ 9])))) , tmp[ 7]);
}
}
}
t_unprotect( tmp[ 5]);
}
t_protect( tmp[ 0]);
tmp[ 5]= ( * ef14)( tmp[ 0]);
if( check_sym( tmp[ 5] , ef15sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , lf_AUX_Rules2C_Aux3_1sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 0]);
tmp[ 8]= ( * ef18)( tmp[ 0]);
t_protect( tmp[ 7]);
t_protect( tmp[ 2]);
t_protect( tmp[ 3]);
tmp[ 9]= lf_AUX_Rules2C_Aux3_3( lf_AUX_Rules2C_Aux3_1( make_list( tmp[ 7])) , lf_AUX_Rules2C_Aux3_2( cons( make_list( tmp[ 2]) , cons( make_list( tmp[ 3]) , make_list( ( * ef19)( lf6( make_list( make_char( 48)))))))));
if( check_sym( tmp[ 9] , ef1sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
tmp[ 11]= arg_1( tmp[ 9]);
if( check_sym( tmp[ 10] , ef2sym)) {
tmp[ 12]= arg_0( tmp[ 10]);
if( check_sym( tmp[ 12] , lf4sym)) {
tmp[ 13]= arg_0( tmp[ 12]);
t_protect( tmp[ 1]);
t_protect( tmp[ 2]);
t_protect( tmp[ 3]);
tmp[ 14]= lf_AUX_Rules2C_Aux3_3( lf_AUX_Rules2C_Aux3_1( make_list( tmp[ 1])) , lf_AUX_Rules2C_Aux3_2( cons( make_list( tmp[ 2]) , make_list( ( * ef7)( tmp[ 3])))));
if( check_sym( tmp[ 14] , ef1sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
tmp[ 16]= arg_1( tmp[ 14]);
if( check_sym( tmp[ 15] , ef2sym)) {
tmp[ 17]= arg_0( tmp[ 15]);
if( check_sym( tmp[ 17] , lf4sym)) {
tmp[ 18]= arg_0( tmp[ 17]);
t_protect( tmp[ 13]);
t_protect( tmp[ 18]);
t_protect( tmp[ 11]);
t_protect( tmp[ 16]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 14]);
return ( * ef1)( ( * ef2)( lf4( cons( make_list( ( * ef16)( lf4( cons( make_list( ( * ef4)( ( * ef17)( tmp[ 8]) , lf_AUX_Rules2C_Aux3_2( cons( make_list( tmp[ 2]) , make_list( tmp[ 3]))))) , make_list( tmp[ 13]))))) , make_list( tmp[ 18])))) , ( * ef9)( tmp[ 11] , tmp[ 16]));
}
}
}
t_unprotect( tmp[ 14]);
}
}
}
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 8]);
}
}
}
t_unprotect( tmp[ 5]);
}
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , ( * ef6)( ))) {
t_protect( tmp[ 1]);
t_protect( tmp[ 2]);
t_protect( tmp[ 3]);
tmp[ 5]= lf_AUX_Rules2C_Aux3_3( lf_AUX_Rules2C_Aux3_1( make_list( tmp[ 1])) , lf_AUX_Rules2C_Aux3_2( cons( make_list( tmp[ 2]) , make_list( ( * ef7)( tmp[ 3])))));
if( check_sym( tmp[ 5] , ef1sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
tmp[ 7]= arg_1( tmp[ 5]);
if( check_sym( tmp[ 6] , ef2sym)) {
tmp[ 8]= arg_0( tmp[ 6]);
if( check_sym( tmp[ 8] , lf4sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
t_protect( tmp[ 2]);
t_protect( tmp[ 3]);
tmp[ 10]= ( * ef8)( lf_AUX_Rules2C_Aux3_2( cons( make_list( tmp[ 2]) , make_list( tmp[ 3]))));
t_protect( tmp[ 7]);
t_protect( tmp[ 0]);
t_protect( tmp[ 10]);
tmp[ 11]= ( * ef9)( tmp[ 7] , ( * ef3)( lf5( make_list( ( * ef10)( tmp[ 0] , ( * ef11)( ( * ef12)( tmp[ 10])))))));
t_protect( tmp[ 9]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 10]);
return ( * ef1)( ( * ef2)( lf4( cons( make_list( ( * ef4)( tmp[ 0] , lf_AUX_Rules2C_Aux3_2( cons( make_list( tmp[ 2]) , make_list( tmp[ 3]))))) , make_list( tmp[ 9])))) , tmp[ 11]);
}
}
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( ( * ef2)( lf4( make_list( null( )))) , ( * ef3)( lf5( make_list( null( )))));
}
}
}
}
}
return make_nf2( lf_AUX_Rules2C_Aux3_3sym , arg0 , arg1);
}
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux3_2( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux3_2);
return make_nf1( lf_AUX_Rules2C_Aux3_2sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux3_1( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux3_1);
return make_nf1( lf_AUX_Rules2C_Aux3_1sym , arg0);
}
aterm * lf6( aterm * arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}

