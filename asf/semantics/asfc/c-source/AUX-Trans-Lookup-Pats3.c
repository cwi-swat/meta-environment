#include "support.h"
static asymbol * lf_AUX_Trans_Lookup_Pats3_2sym;
static aterm * lf_AUX_Trans_Lookup_Pats3_2( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * lf_AUX_Trans_Lookup_Pats3_1sym;
static aterm * lf_AUX_Trans_Lookup_Pats3_1( aterm * arg1);
static asymbol * lf6sym;
static aterm * lf6( aterm * arg1);
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
void register_AUX_Trans_Lookup_Pats3( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Trans_Lookup_Pats3_2sym= TmkSymbol( "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[l(\"transform-lhs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , SYM_STRING);
lf_AUX_Trans_Lookup_Pats3_1sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf6sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_Trans_Lookup_Pats3_1 , lf_AUX_Trans_Lookup_Pats3_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[l(\"transform-lhs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Lookup_Pats3_2 , lf_AUX_Trans_Lookup_Pats3_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Rule\"),ql(\";\"))") , lf5 , lf5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf6 , lf6sym);
}
void resolve_AUX_Trans_Lookup_Pats3( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[l(\"lookup-pattern\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"PatType\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[l(\"lookup-pattern\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"PatType\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-cond\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-cond\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-new\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-new\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"newvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"newvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-new-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-new-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"def-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"def-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"def-rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"def-rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Trans_Lookup_Pats3_2( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4) {
{
aterm * tmp[19];
PROF( prof_lf_AUX_Trans_Lookup_Pats3_2);
if( check_sym( arg1 , lf_AUX_Trans_Lookup_Pats3_1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( arg2 , ef1sym)) {
{
aterm * atmp20= arg_0( arg2);
{
aterm * atmp21= arg_1( arg2);
if( check_sym( atmp21 , lf3sym)) {
{
aterm * atmp210= arg_0( atmp21);
t_protect( atmp10);
if( not_empty_list( atmp10)) {
t_protect( atmp210);
if( not_empty_list( atmp210)) {
t_protect( atmp210);
t_protect( arg4);
tmp[ 0]= ( * ef11)( ( * ef12)( ) , ( * ef13)( lf3( make_list( atmp210))) , arg4);
if( check_sym( tmp[ 0] , ef13sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf3sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
t_protect( tmp[ 2]);
if( not_empty_list( tmp[ 2])) {
t_protect( atmp210);
t_protect( arg4);
tmp[ 3]= ( * ef11)( ( * ef14)( ) , ( * ef13)( lf3( make_list( atmp210))) , arg4);
if( check_sym( tmp[ 3] , ef13sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf3sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
t_protect( tmp[ 5]);
if( not_empty_list( tmp[ 5])) {
t_protect( atmp210);
t_protect( arg4);
tmp[ 6]= ( * ef11)( ( * ef15)( ) , ( * ef13)( lf3( make_list( atmp210))) , arg4);
if( check_sym( tmp[ 6] , ef13sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
if( check_sym( tmp[ 7] , lf3sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
t_protect( tmp[ 8]);
if( not_empty_list( tmp[ 8])) {
t_protect( arg4);
tmp[ 9]= ( * ef16)( ( * ef10)( arg4));
if( check_sym( tmp[ 9] , ef7sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
if( check_sym( tmp[ 10] , ef8sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
t_protect( atmp20);
t_protect( atmp210);
t_protect( tmp[ 11]);
t_protect( arg0);
tmp[ 12]= ( * ef17)( ( * ef1)( atmp20 , lf3( cons( make_list( atmp210) , make_list( ( * ef7)( ( * ef8)( tmp[ 11])))))) , arg0);
t_protect( atmp210);
t_protect( arg4);
tmp[ 13]= ( * ef11)( ( * ef18)( ) , ( * ef13)( lf3( make_list( atmp210))) , arg4);
if( check_sym( tmp[ 13] , ef13sym)) {
tmp[ 14]= arg_0( tmp[ 13]);
if( check_sym( tmp[ 14] , lf3sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
t_protect( tmp[ 15]);
if( not_empty_list( tmp[ 15])) {
t_protect( atmp210);
t_protect( arg4);
tmp[ 16]= ( * ef11)( ( * ef19)( ) , ( * ef13)( lf3( make_list( atmp210))) , arg4);
if( check_sym( tmp[ 16] , ef13sym)) {
tmp[ 17]= arg_0( tmp[ 16]);
if( check_sym( tmp[ 17] , lf3sym)) {
tmp[ 18]= arg_0( tmp[ 17]);
t_protect( tmp[ 18]);
if( not_empty_list( tmp[ 18])) {
t_protect( arg0);
t_protect( tmp[ 5]);
t_protect( tmp[ 11]);
t_protect( atmp20);
t_protect( tmp[ 2]);
t_protect( tmp[ 11]);
t_protect( arg0);
t_protect( tmp[ 8]);
t_protect( arg0);
t_protect( tmp[ 15]);
t_protect( tmp[ 18]);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 16]);
return ( * ef2)( lf4( make_list( tmp[ 12])) , lf5( cons( make_list( ( * ef3)( ( * ef4)( lf_AUX_Trans_Lookup_Pats3_1( make_list( ( * ef5)( ( * ef1)( arg0 , lf3( make_list( tmp[ 5]))) , ( * ef1)( ( * ef6)( lf6( cons( make_list( make_char( 111)) , make_list( make_char( 107))))) , lf3( make_list( ( * ef7)( ( * ef8)( tmp[ 11]))))))))) , ( * ef1)( atmp20 , lf3( make_list( tmp[ 2]))) , ( * ef7)( ( * ef8)( tmp[ 11])))) , cons( make_list( ( * ef3)( ( * ef4)( arg1) , ( * ef1)( arg0 , lf3( make_list( tmp[ 8]))) , ( * ef1)( ( * ef6)( lf6( cons( make_list( make_char( 111)) , make_list( make_char( 107))))) , lf3( make_list( arg3))))) , make_list( ( * ef9)( ( * ef1)( arg0 , lf3( make_list( tmp[ 15]))) , ( * ef1)( arg0 , lf3( make_list( tmp[ 18])))))))) , ( * ef10)( ( * ef10)( arg4)));
}
}
}
t_unprotect( tmp[ 16]);
}
}
}
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 12]);
}
}
t_unprotect( tmp[ 9]);
}
}
}
t_unprotect( tmp[ 6]);
}
}
}
t_unprotect( tmp[ 3]);
}
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
return make_nf5( lf_AUX_Trans_Lookup_Pats3_2sym , arg0 , arg1 , arg2 , arg3 , arg4);
}
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf6( aterm * arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}
aterm * lf_AUX_Trans_Lookup_Pats3_1( aterm * arg0) {
PROF( prof_lf_AUX_Trans_Lookup_Pats3_1);
return make_nf1( lf_AUX_Trans_Lookup_Pats3_1sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}

