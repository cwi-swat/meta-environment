#include "support.h"
static asymbol * lf_AUX_AsFix_Basics4_1sym;
static aterm * lf_AUX_AsFix_Basics4_1( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef10sym;
static funcptr ef10;
void register_AUX_AsFix_Basics4( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_AsFix_Basics4_1sym= TmkSymbol( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"get-itersep-tail\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"get-itersep-tail\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)") , lf_AUX_AsFix_Basics4_1 , lf_AUX_AsFix_Basics4_1sym);
}
void resolve_AUX_AsFix_Basics4( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-list-tail\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-list-tail\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-list-tail-with-sep\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-list-tail-with-sep\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_AsFix_Basics4_1( aterm * arg0) {
{
aterm * tmp[24];
PROF( prof_lf_AUX_AsFix_Basics4_1);
tmp[ 0]= ( * ef1)( );
t_protect( arg0);
t_protect( tmp[ 0]);
if( ! term_equal( arg0 , tmp[ 0])) {
t_protect( arg0);
tmp[ 1]= ( * ef4)( arg0);
if( check_sym( tmp[ 1] , ef3sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , ef5sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
if( check_sym( tmp[ 3] , ef6sym)) {
tmp[ 5]= arg_0( tmp[ 3]);
tmp[ 6]= arg_1( tmp[ 3]);
t_protect( tmp[ 5]);
if( term_equal( tmp[ 5] , ( * ef7)( ))) {
if( check_sym( tmp[ 6] , ef8sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
if( check_sym( tmp[ 7] , ef9sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
if( check_sym( tmp[ 8] , ef10sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
if( check_sym( tmp[ 4] , ef5sym)) {
tmp[ 10]= arg_0( tmp[ 4]);
tmp[ 11]= arg_1( tmp[ 4]);
if( check_sym( tmp[ 10] , ef6sym)) {
tmp[ 12]= arg_0( tmp[ 10]);
tmp[ 13]= arg_1( tmp[ 10]);
t_protect( tmp[ 12]);
if( term_equal( tmp[ 12] , ( * ef11)( ))) {
if( check_sym( tmp[ 13] , ef8sym)) {
tmp[ 14]= arg_0( tmp[ 13]);
if( check_sym( tmp[ 14] , ef9sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
if( check_sym( tmp[ 15] , ef10sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
if( check_sym( tmp[ 11] , ef5sym)) {
tmp[ 17]= arg_0( tmp[ 11]);
tmp[ 18]= arg_1( tmp[ 11]);
if( check_sym( tmp[ 17] , ef6sym)) {
tmp[ 19]= arg_0( tmp[ 17]);
tmp[ 20]= arg_1( tmp[ 17]);
t_protect( tmp[ 19]);
if( term_equal( tmp[ 19] , ( * ef7)( ))) {
if( check_sym( tmp[ 20] , ef8sym)) {
tmp[ 21]= arg_0( tmp[ 20]);
if( check_sym( tmp[ 21] , ef9sym)) {
tmp[ 22]= arg_0( tmp[ 21]);
if( check_sym( tmp[ 22] , ef10sym)) {
tmp[ 23]= arg_0( tmp[ 22]);
t_protect( tmp[ 18]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
return ( * ef3)( tmp[ 18]);
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
}
}
}
}
}
}
}
t_unprotect( tmp[ 1]);
t_protect( arg0);
if( term_equal( ( * ef2)( arg0) , ( * ef1)( ))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( );
}
}
t_unprotect( tmp[ 0]);
return make_nf1( lf_AUX_AsFix_Basics4_1sym , arg0);
}
}

