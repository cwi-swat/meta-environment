#include "support.h"
static Symbol lf_AUX_AsFix2muASF_C4_1sym;
static ATerm lf_AUX_AsFix2muASF_C4_1( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef12sym;
static funcptr ef12;
static Symbol ef15sym;
static funcptr ef15;
static Symbol ef21sym;
static funcptr ef21;
static Symbol ef2sym;
static funcptr ef2;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef9sym;
static funcptr ef9;
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef6sym;
static funcptr ef6;
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef8sym;
static funcptr ef8;
static Symbol lf4sym;
static ATerm lf4( ATerm arg1);
static Symbol ef16sym;
static funcptr ef16;
static Symbol ef17sym;
static funcptr ef17;
static Symbol ef18sym;
static funcptr ef18;
static Symbol ef19sym;
static funcptr ef19;
static Symbol ef10sym;
static funcptr ef10;
static Symbol ef11sym;
static funcptr ef11;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
static Symbol ef20sym;
static funcptr ef20;
static Symbol ef13sym;
static funcptr ef13;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef14sym;
static funcptr ef14;
static Symbol lf5sym;
static ATerm lf5( ATerm arg1);
void register_AUX_AsFix2muASF_C4( ) {
lf_AUX_AsFix2muASF_C4_1sym= ATmakeSymbol( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"ceqeq2rules\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)"
 , 3 , ATtrue);
ATprotectSymbol( lf_AUX_AsFix2muASF_C4_1sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
lf4sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf4sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
lf5sym= ATmakeSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue);
ATprotectSymbol( lf5sym);
register_prod( ATparse( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"ceqeq2rules\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)") , lf_AUX_AsFix2muASF_C4_1 , lf_AUX_AsFix2muASF_C4_1sym);
register_prod( ATparse( "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf2 , lf2sym);
register_prod( ATparse( "listtype(sort(\"Rule\"),ql(\";\"))") , lf3 , lf3sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( ATparse( "listtype(sort(\"Cond\"),ql(\"&\"))") , lf5 , lf5sym);
}
void resolve_AUX_AsFix2muASF_C4( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-equ\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-equ\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"aterm2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"aterm2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef9= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef10= lookup_func( ATreadFromString( "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef10sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef11= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef12= lookup_func( ATreadFromString( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"make-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( ATreadFromString( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"make-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef13= lookup_func( ATreadFromString( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"is-default\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( ATreadFromString( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"is-default\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef14= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"tag\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"tag\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef15= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-when\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-when\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef16= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"conditions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"conditions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef17= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef18= lookup_func( ATreadFromString( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"conds2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( ATreadFromString( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"conds2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)"));
ef19= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)"));
ef20= lookup_func( ATreadFromString( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"make-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( ATreadFromString( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"make-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef21= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-impl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-impl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
static ATerm constant3= NULL;
void init_AUX_AsFix2muASF_C4( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
ATprotect( & constant3);
}
ATerm lf_AUX_AsFix2muASF_C4_1( ATerm arg0 , ATerm arg1 , ATerm arg2) {
{
ATerm tmp[30];
PROF( prof_lf_AUX_AsFix2muASF_C4_1);
if( check_sym( arg0 , ef1sym)) {
tmp[ 0]= ( * ef3)( arg1 , ( constant0? constant0: ( constant0= ( * ef4)( ))));
tmp[ 1]= ( * ef5)( ( * ef6)( tmp[ 0]) , tmp[ 0] , arg2);
if( check_sym( tmp[ 1] , ef7sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
tmp[ 3]= arg_1( tmp[ 1]);
tmp[ 4]= arg_2( tmp[ 1]);
if( check_sym( tmp[ 2] , lf2sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , ef8sym)) {
tmp[ 6]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 6] , lf4sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
if( is_single_element( tmp[ 7])) {
tmp[ 8]= list_head( tmp[ 7]);
tmp[ 9]= ( * ef3)( arg1 , ( constant1? constant1: ( constant1= ( * ef9)( ))));
tmp[ 10]= ( * ef5)( ( * ef6)( tmp[ 9]) , tmp[ 9] , tmp[ 4]);
if( check_sym( tmp[ 10] , ef7sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
tmp[ 12]= arg_1( tmp[ 10]);
tmp[ 13]= arg_2( tmp[ 10]);
if( check_sym( tmp[ 11] , lf2sym)) {
tmp[ 14]= arg_0( tmp[ 11]);
if( check_sym( tmp[ 12] , ef8sym)) {
tmp[ 15]= arg_0( tmp[ 12]);
if( check_sym( tmp[ 15] , lf4sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
if( is_single_element( tmp[ 16])) {
tmp[ 17]= list_head( tmp[ 16]);
tmp[ 18]= ( * ef10)( ( * ef11)( lf2( make_list( tmp[ 5]))) , ( * ef11)( lf2( make_list( tmp[ 14]))));
if( check_sym( tmp[ 18] , ef11sym)) {
tmp[ 19]= arg_0( tmp[ 18]);
if( check_sym( tmp[ 19] , lf2sym)) {
tmp[ 20]= arg_0( tmp[ 19]);
tmp[ 21]= ( * ef12)( ( * ef13)( ( * ef3)( arg1 , ( constant2? constant2: ( constant2= ( * ef14)( ))))) , tmp[ 8] , tmp[ 17]);
return ( * ef2)( lf2( make_list( tmp[ 20])) , lf3( make_list( tmp[ 21])) , tmp[ 13]);
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
if( check_sym( arg0 , ef15sym)) {
tmp[ 0]= ( * ef3)( arg1 , ( constant0? constant0: ( constant0= ( * ef4)( ))));
tmp[ 1]= ( * ef5)( ( * ef6)( tmp[ 0]) , tmp[ 0] , arg2);
if( check_sym( tmp[ 1] , ef7sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
tmp[ 3]= arg_1( tmp[ 1]);
tmp[ 4]= arg_2( tmp[ 1]);
if( check_sym( tmp[ 2] , lf2sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , ef8sym)) {
tmp[ 6]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 6] , lf4sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
if( is_single_element( tmp[ 7])) {
tmp[ 8]= list_head( tmp[ 7]);
tmp[ 9]= ( * ef3)( arg1 , ( constant1? constant1: ( constant1= ( * ef9)( ))));
tmp[ 10]= ( * ef5)( ( * ef6)( tmp[ 9]) , tmp[ 9] , tmp[ 4]);
if( check_sym( tmp[ 10] , ef7sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
tmp[ 12]= arg_1( tmp[ 10]);
tmp[ 13]= arg_2( tmp[ 10]);
if( check_sym( tmp[ 11] , lf2sym)) {
tmp[ 14]= arg_0( tmp[ 11]);
if( check_sym( tmp[ 12] , ef8sym)) {
tmp[ 15]= arg_0( tmp[ 12]);
if( check_sym( tmp[ 15] , lf4sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
if( is_single_element( tmp[ 16])) {
tmp[ 17]= list_head( tmp[ 16]);
tmp[ 18]= ( * ef3)( arg1 , ( constant3? constant3: ( constant3= ( * ef16)( ))));
if( check_sym( tmp[ 18] , ef17sym)) {
tmp[ 19]= arg_0( tmp[ 18]);
tmp[ 20]= ( * ef18)( tmp[ 19] , tmp[ 13]);
if( check_sym( tmp[ 20] , ef19sym)) {
tmp[ 21]= arg_0( tmp[ 20]);
tmp[ 22]= arg_1( tmp[ 20]);
tmp[ 23]= arg_2( tmp[ 20]);
if( check_sym( tmp[ 21] , lf2sym)) {
tmp[ 24]= arg_0( tmp[ 21]);
if( check_sym( tmp[ 22] , lf5sym)) {
tmp[ 25]= arg_0( tmp[ 22]);
if( not_empty_list( tmp[ 25])) {
tmp[ 26]= ( * ef10)( ( * ef10)( ( * ef11)( lf2( make_list( tmp[ 5]))) , ( * ef11)( lf2( make_list( tmp[ 14])))) , ( * ef11)( lf2( make_list( tmp[ 24]))));
if( check_sym( tmp[ 26] , ef11sym)) {
tmp[ 27]= arg_0( tmp[ 26]);
if( check_sym( tmp[ 27] , lf2sym)) {
tmp[ 28]= arg_0( tmp[ 27]);
tmp[ 29]= ( * ef20)( ( * ef13)( ( * ef3)( arg1 , ( constant2? constant2: ( constant2= ( * ef14)( ))))) , lf5( make_list( tmp[ 25])) , tmp[ 8] , tmp[ 17]);
return ( * ef2)( lf2( make_list( tmp[ 28])) , lf3( make_list( tmp[ 29])) , tmp[ 23]);
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
if( check_sym( arg0 , ef21sym)) {
tmp[ 0]= ( * ef3)( arg1 , ( constant0? constant0: ( constant0= ( * ef4)( ))));
tmp[ 1]= ( * ef5)( ( * ef6)( tmp[ 0]) , tmp[ 0] , arg2);
if( check_sym( tmp[ 1] , ef7sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
tmp[ 3]= arg_1( tmp[ 1]);
tmp[ 4]= arg_2( tmp[ 1]);
if( check_sym( tmp[ 2] , lf2sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , ef8sym)) {
tmp[ 6]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 6] , lf4sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
if( is_single_element( tmp[ 7])) {
tmp[ 8]= list_head( tmp[ 7]);
tmp[ 9]= ( * ef3)( arg1 , ( constant1? constant1: ( constant1= ( * ef9)( ))));
tmp[ 10]= ( * ef5)( ( * ef6)( tmp[ 9]) , tmp[ 9] , tmp[ 4]);
if( check_sym( tmp[ 10] , ef7sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
tmp[ 12]= arg_1( tmp[ 10]);
tmp[ 13]= arg_2( tmp[ 10]);
if( check_sym( tmp[ 11] , lf2sym)) {
tmp[ 14]= arg_0( tmp[ 11]);
if( check_sym( tmp[ 12] , ef8sym)) {
tmp[ 15]= arg_0( tmp[ 12]);
if( check_sym( tmp[ 15] , lf4sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
if( is_single_element( tmp[ 16])) {
tmp[ 17]= list_head( tmp[ 16]);
tmp[ 18]= ( * ef3)( arg1 , ( constant3? constant3: ( constant3= ( * ef16)( ))));
if( check_sym( tmp[ 18] , ef17sym)) {
tmp[ 19]= arg_0( tmp[ 18]);
tmp[ 20]= ( * ef18)( tmp[ 19] , tmp[ 13]);
if( check_sym( tmp[ 20] , ef19sym)) {
tmp[ 21]= arg_0( tmp[ 20]);
tmp[ 22]= arg_1( tmp[ 20]);
tmp[ 23]= arg_2( tmp[ 20]);
if( check_sym( tmp[ 21] , lf2sym)) {
tmp[ 24]= arg_0( tmp[ 21]);
if( check_sym( tmp[ 22] , lf5sym)) {
tmp[ 25]= arg_0( tmp[ 22]);
if( not_empty_list( tmp[ 25])) {
tmp[ 26]= ( * ef10)( ( * ef10)( ( * ef11)( lf2( make_list( tmp[ 5]))) , ( * ef11)( lf2( make_list( tmp[ 14])))) , ( * ef11)( lf2( make_list( tmp[ 24]))));
if( check_sym( tmp[ 26] , ef11sym)) {
tmp[ 27]= arg_0( tmp[ 26]);
if( check_sym( tmp[ 27] , lf2sym)) {
tmp[ 28]= arg_0( tmp[ 27]);
tmp[ 29]= ( * ef20)( ( * ef13)( ( * ef3)( arg1 , ( constant2? constant2: ( constant2= ( * ef14)( ))))) , lf5( make_list( tmp[ 25])) , tmp[ 8] , tmp[ 17]);
return ( * ef2)( lf2( make_list( tmp[ 28])) , lf3( make_list( tmp[ 29])) , tmp[ 23]);
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
return make_nf3( lf_AUX_AsFix2muASF_C4_1sym , arg0 , arg1 , arg2);
}
}
ATerm lf5( ATerm arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}
ATerm lf4( ATerm arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

