#include "support.h"
static asymbol * lf_AUX_AsFix2muASF_C7_1sym;
static aterm * lf_AUX_AsFix2muASF_C7_1( aterm * arg1 , aterm * arg2);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef20sym;
static funcptr ef20;
static asymbol * ef4sym;
static funcptr ef4;
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
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_AsFix2muASF_C7( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_AsFix2muASF_C7_1sym= TmkSymbol( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"cond2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"cond2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)") , lf_AUX_AsFix2muASF_C7_1 , lf_AUX_AsFix2muASF_C7_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf5 , lf5sym);
}
void resolve_AUX_AsFix2muASF_C7( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"cop\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"cop\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"aterm2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"aterm2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef20= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"!=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"!=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_AsFix2muASF_C7_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[22];
PROF( prof_lf_AUX_AsFix2muASF_C7_1);
t_protect( arg0);
tmp[ 0]= ( * ef3)( arg0 , ( * ef4)( ));
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , ( * ef5)( ( * ef6)( ) , ( * ef7)( ( * ef8)( ( * ef9)( ( * ef10)( lf4( cons( make_list( make_char( 34)) , cons( make_list( make_char( 61)) , cons( make_list( make_char( 58)) , make_list( make_char( 34))))))))))))) {
t_protect( arg0);
tmp[ 1]= ( * ef3)( arg0 , ( * ef11)( ));
t_protect( tmp[ 1]);
t_protect( tmp[ 1]);
t_protect( arg1);
tmp[ 2]= ( * ef12)( ( * ef13)( tmp[ 1]) , tmp[ 1] , arg1);
if( check_sym( tmp[ 2] , ef14sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
tmp[ 5]= arg_2( tmp[ 2]);
if( check_sym( tmp[ 3] , lf2sym)) {
tmp[ 6]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , ef15sym)) {
tmp[ 7]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 7] , lf5sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
t_protect( tmp[ 8]);
if( is_single_element( tmp[ 8])) {
t_protect( tmp[ 8]);
tmp[ 9]= list_head( tmp[ 8]);
t_protect( arg0);
tmp[ 10]= ( * ef3)( arg0 , ( * ef16)( ));
t_protect( tmp[ 10]);
t_protect( tmp[ 10]);
t_protect( tmp[ 5]);
tmp[ 11]= ( * ef12)( ( * ef13)( tmp[ 10]) , tmp[ 10] , tmp[ 5]);
if( check_sym( tmp[ 11] , ef14sym)) {
tmp[ 12]= arg_0( tmp[ 11]);
tmp[ 13]= arg_1( tmp[ 11]);
tmp[ 14]= arg_2( tmp[ 11]);
if( check_sym( tmp[ 12] , lf2sym)) {
tmp[ 15]= arg_0( tmp[ 12]);
if( check_sym( tmp[ 13] , ef15sym)) {
tmp[ 16]= arg_0( tmp[ 13]);
if( check_sym( tmp[ 16] , lf5sym)) {
tmp[ 17]= arg_0( tmp[ 16]);
t_protect( tmp[ 17]);
if( is_single_element( tmp[ 17])) {
t_protect( tmp[ 17]);
tmp[ 18]= list_head( tmp[ 17]);
t_protect( tmp[ 6]);
t_protect( tmp[ 15]);
tmp[ 19]= ( * ef17)( ( * ef18)( lf2( make_list( tmp[ 6]))) , ( * ef18)( lf2( make_list( tmp[ 15]))));
if( check_sym( tmp[ 19] , ef18sym)) {
tmp[ 20]= arg_0( tmp[ 19]);
if( check_sym( tmp[ 20] , lf2sym)) {
tmp[ 21]= arg_0( tmp[ 20]);
t_protect( tmp[ 21]);
t_protect( tmp[ 14]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 19]);
return ( * ef1)( lf2( make_list( tmp[ 21])) , lf3( make_list( ( * ef2)( tmp[ 9] , tmp[ 18]))) , tmp[ 14]);
}
}
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 18]);
}
}
}
}
}
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 9]);
}
}
}
}
}
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 1]);
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , ( * ef5)( ( * ef6)( ) , ( * ef7)( ( * ef8)( ( * ef9)( ( * ef10)( lf4( cons( make_list( make_char( 34)) , cons( make_list( make_char( 61)) , make_list( make_char( 34)))))))))))) {
t_protect( arg0);
tmp[ 1]= ( * ef3)( arg0 , ( * ef11)( ));
t_protect( tmp[ 1]);
t_protect( tmp[ 1]);
t_protect( arg1);
tmp[ 2]= ( * ef12)( ( * ef13)( tmp[ 1]) , tmp[ 1] , arg1);
if( check_sym( tmp[ 2] , ef14sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
tmp[ 5]= arg_2( tmp[ 2]);
if( check_sym( tmp[ 3] , lf2sym)) {
tmp[ 6]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , ef15sym)) {
tmp[ 7]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 7] , lf5sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
t_protect( tmp[ 8]);
if( is_single_element( tmp[ 8])) {
t_protect( tmp[ 8]);
tmp[ 9]= list_head( tmp[ 8]);
t_protect( arg0);
tmp[ 10]= ( * ef3)( arg0 , ( * ef16)( ));
t_protect( tmp[ 10]);
t_protect( tmp[ 10]);
t_protect( tmp[ 5]);
tmp[ 11]= ( * ef12)( ( * ef13)( tmp[ 10]) , tmp[ 10] , tmp[ 5]);
if( check_sym( tmp[ 11] , ef14sym)) {
tmp[ 12]= arg_0( tmp[ 11]);
tmp[ 13]= arg_1( tmp[ 11]);
tmp[ 14]= arg_2( tmp[ 11]);
if( check_sym( tmp[ 12] , lf2sym)) {
tmp[ 15]= arg_0( tmp[ 12]);
if( check_sym( tmp[ 13] , ef15sym)) {
tmp[ 16]= arg_0( tmp[ 13]);
if( check_sym( tmp[ 16] , lf5sym)) {
tmp[ 17]= arg_0( tmp[ 16]);
t_protect( tmp[ 17]);
if( is_single_element( tmp[ 17])) {
t_protect( tmp[ 17]);
tmp[ 18]= list_head( tmp[ 17]);
t_protect( tmp[ 6]);
t_protect( tmp[ 15]);
tmp[ 19]= ( * ef17)( ( * ef18)( lf2( make_list( tmp[ 6]))) , ( * ef18)( lf2( make_list( tmp[ 15]))));
if( check_sym( tmp[ 19] , ef18sym)) {
tmp[ 20]= arg_0( tmp[ 19]);
if( check_sym( tmp[ 20] , lf2sym)) {
tmp[ 21]= arg_0( tmp[ 20]);
t_protect( tmp[ 21]);
t_protect( tmp[ 14]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 19]);
return ( * ef1)( lf2( make_list( tmp[ 21])) , lf3( make_list( ( * ef19)( tmp[ 9] , tmp[ 18]))) , tmp[ 14]);
}
}
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 18]);
}
}
}
}
}
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 9]);
}
}
}
}
}
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 1]);
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , ( * ef5)( ( * ef6)( ) , ( * ef7)( ( * ef8)( ( * ef9)( ( * ef10)( lf4( cons( make_list( make_char( 34)) , cons( make_list( make_char( 33)) , cons( make_list( make_char( 61)) , make_list( make_char( 34))))))))))))) {
t_protect( arg0);
tmp[ 1]= ( * ef3)( arg0 , ( * ef11)( ));
t_protect( tmp[ 1]);
t_protect( tmp[ 1]);
t_protect( arg1);
tmp[ 2]= ( * ef12)( ( * ef13)( tmp[ 1]) , tmp[ 1] , arg1);
if( check_sym( tmp[ 2] , ef14sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
tmp[ 5]= arg_2( tmp[ 2]);
if( check_sym( tmp[ 3] , lf2sym)) {
tmp[ 6]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , ef15sym)) {
tmp[ 7]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 7] , lf5sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
t_protect( tmp[ 8]);
if( is_single_element( tmp[ 8])) {
t_protect( tmp[ 8]);
tmp[ 9]= list_head( tmp[ 8]);
t_protect( arg0);
tmp[ 10]= ( * ef3)( arg0 , ( * ef16)( ));
t_protect( tmp[ 10]);
t_protect( tmp[ 10]);
t_protect( tmp[ 5]);
tmp[ 11]= ( * ef12)( ( * ef13)( tmp[ 10]) , tmp[ 10] , tmp[ 5]);
if( check_sym( tmp[ 11] , ef14sym)) {
tmp[ 12]= arg_0( tmp[ 11]);
tmp[ 13]= arg_1( tmp[ 11]);
tmp[ 14]= arg_2( tmp[ 11]);
if( check_sym( tmp[ 12] , lf2sym)) {
tmp[ 15]= arg_0( tmp[ 12]);
if( check_sym( tmp[ 13] , ef15sym)) {
tmp[ 16]= arg_0( tmp[ 13]);
if( check_sym( tmp[ 16] , lf5sym)) {
tmp[ 17]= arg_0( tmp[ 16]);
t_protect( tmp[ 17]);
if( is_single_element( tmp[ 17])) {
t_protect( tmp[ 17]);
tmp[ 18]= list_head( tmp[ 17]);
t_protect( tmp[ 6]);
t_protect( tmp[ 15]);
tmp[ 19]= ( * ef17)( ( * ef18)( lf2( make_list( tmp[ 6]))) , ( * ef18)( lf2( make_list( tmp[ 15]))));
if( check_sym( tmp[ 19] , ef18sym)) {
tmp[ 20]= arg_0( tmp[ 19]);
if( check_sym( tmp[ 20] , lf2sym)) {
tmp[ 21]= arg_0( tmp[ 20]);
t_protect( tmp[ 21]);
t_protect( tmp[ 14]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 19]);
return ( * ef1)( lf2( make_list( tmp[ 21])) , lf3( make_list( ( * ef20)( tmp[ 9] , tmp[ 18]))) , tmp[ 14]);
}
}
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 18]);
}
}
}
}
}
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 9]);
}
}
}
}
}
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
return make_nf2( lf_AUX_AsFix2muASF_C7_1sym , arg0 , arg1);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

