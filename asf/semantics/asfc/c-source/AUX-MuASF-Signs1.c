#include "support.h"
static asymbol * lf_AUX_MuASF_Signs1_1sym;
static aterm * lf_AUX_MuASF_Signs1_1( aterm * arg1 , aterm * arg2);
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_MuASF_Signs1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Signs1_1sym= TmkSymbol( "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))") , lf_AUX_MuASF_Signs1_1 , lf_AUX_MuASF_Signs1_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf2 , lf2sym);
}
void resolve_AUX_MuASF_Signs1( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"is-external-ssfuncdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"is-external-ssfuncdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"remove-external-ssfuncdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"remove-external-ssfuncdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDef\"),w(\"\"),ql(\"in_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDef\"),w(\"\"),ql(\"in_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"add-external-ssfuncdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"add-external-ssfuncdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"remove-ssfuncdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"remove-ssfuncdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Signs1_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[13];
PROF( prof_lf_AUX_MuASF_Signs1_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( atmp000);
if( not_empty_list( atmp000)) {
t_protect( atmp000);
tmp[ 0]= list_head( atmp000);
{
t_protect( atmp000);
tmp[ 1]= list_tail( atmp000);
t_protect( tmp[ 0]);
tmp[ 2]= ( * ef2)( tmp[ 0]);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , ( * ef6)( ))) {
t_protect( tmp[ 0]);
t_protect( atmp100);
tmp[ 3]= ( * ef5)( tmp[ 0] , ( * ef1)( lf2( make_list( atmp100))));
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , ( * ef3)( ))) {
t_protect( atmp100);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return lf_AUX_MuASF_Signs1_1( ( * ef1)( lf2( make_list( tmp[ 1]))) , ( * ef1)( lf2( make_list( atmp100))));
}
tmp[ 4]= ( * ef6)( );
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
if( term_equal( tmp[ 3] , tmp[ 4])) {
t_protect( tmp[ 0]);
tmp[ 5]= ( * ef7)( tmp[ 0]);
t_protect( tmp[ 5]);
t_protect( atmp100);
tmp[ 6]= ( * ef5)( tmp[ 5] , ( * ef1)( lf2( make_list( atmp100))));
t_protect( tmp[ 6]);
if( term_equal( tmp[ 6] , ( * ef6)( ))) {
t_protect( tmp[ 1]);
t_protect( atmp100);
tmp[ 7]= lf_AUX_MuASF_Signs1_1( ( * ef1)( lf2( make_list( tmp[ 1]))) , ( * ef1)( lf2( make_list( atmp100))));
if( check_sym( tmp[ 7] , ef1sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
if( check_sym( tmp[ 8] , lf2sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
t_protect( tmp[ 9]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
return ( * ef1)( lf2( cons( make_list( tmp[ 0]) , make_list( tmp[ 9]))));
}
}
t_unprotect( tmp[ 7]);
}
t_protect( tmp[ 6]);
if( term_equal( tmp[ 6] , ( * ef3)( ))) {
t_protect( tmp[ 5]);
t_protect( atmp100);
tmp[ 7]= ( * ef8)( tmp[ 5] , ( * ef1)( lf2( make_list( atmp100))));
if( check_sym( tmp[ 7] , ef1sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
if( check_sym( tmp[ 8] , lf2sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
t_protect( tmp[ 1]);
t_protect( tmp[ 9]);
tmp[ 10]= lf_AUX_MuASF_Signs1_1( ( * ef1)( lf2( make_list( tmp[ 1]))) , ( * ef1)( lf2( make_list( tmp[ 9]))));
if( check_sym( tmp[ 10] , ef1sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
if( check_sym( tmp[ 11] , lf2sym)) {
tmp[ 12]= arg_0( tmp[ 11]);
t_protect( tmp[ 12]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 10]);
return ( * ef1)( lf2( cons( make_list( tmp[ 0]) , make_list( tmp[ 12]))));
}
}
t_unprotect( tmp[ 10]);
}
}
t_unprotect( tmp[ 7]);
}
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 3]);
}
tmp[ 3]= ( * ef3)( );
t_protect( tmp[ 2]);
t_protect( tmp[ 3]);
if( term_equal( tmp[ 2] , tmp[ 3])) {
t_protect( tmp[ 0]);
tmp[ 4]= ( * ef4)( tmp[ 0]);
t_protect( tmp[ 4]);
t_protect( atmp100);
tmp[ 5]= ( * ef5)( tmp[ 4] , ( * ef1)( lf2( make_list( atmp100))));
t_protect( tmp[ 5]);
if( term_equal( tmp[ 5] , ( * ef3)( ))) {
t_protect( atmp100);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
return lf_AUX_MuASF_Signs1_1( ( * ef1)( lf2( make_list( tmp[ 1]))) , ( * ef1)( lf2( make_list( atmp100))));
}
t_protect( tmp[ 5]);
if( term_equal( tmp[ 5] , ( * ef6)( ))) {
t_protect( tmp[ 0]);
t_protect( atmp100);
if( term_equal( ( * ef5)( tmp[ 0] , ( * ef1)( lf2( make_list( atmp100)))) , ( * ef3)( ))) {
t_protect( atmp100);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
return lf_AUX_MuASF_Signs1_1( ( * ef1)( lf2( make_list( tmp[ 1]))) , ( * ef1)( lf2( make_list( atmp100))));
}
}
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 4]);
t_protect( tmp[ 0]);
t_protect( atmp100);
if( term_equal( ( * ef5)( tmp[ 0] , ( * ef1)( lf2( make_list( atmp100)))) , ( * ef6)( ))) {
t_protect( tmp[ 0]);
tmp[ 4]= ( * ef4)( tmp[ 0]);
t_protect( tmp[ 4]);
t_protect( atmp100);
if( term_equal( ( * ef5)( tmp[ 4] , ( * ef1)( lf2( make_list( atmp100)))) , ( * ef6)( ))) {
t_protect( tmp[ 1]);
t_protect( atmp100);
tmp[ 5]= lf_AUX_MuASF_Signs1_1( ( * ef1)( lf2( make_list( tmp[ 1]))) , ( * ef1)( lf2( make_list( atmp100))));
if( check_sym( tmp[ 5] , ef1sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
t_protect( tmp[ 7]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
return ( * ef1)( lf2( cons( make_list( tmp[ 0]) , make_list( tmp[ 7]))));
}
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 4]);
}
}
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
else {
t_protect( atmp100);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( lf2( make_list( atmp100)));
}
}
}
}
}
}
}
}
}
return make_nf2( lf_AUX_MuASF_Signs1_1sym , arg0 , arg1);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

