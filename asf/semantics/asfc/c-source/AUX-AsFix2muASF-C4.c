#include "support.h"
static asymbol * lf_AUX_AsFix2muASF_C4_1sym;
static aterm * lf_AUX_AsFix2muASF_C4_1( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef21sym;
static funcptr ef21;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef20sym;
static funcptr ef20;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
void register_AUX_AsFix2muASF_C4( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_AsFix2muASF_C4_1sym= TmkSymbol( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"ceqeq2rules\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"ceqeq2rules\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)") , lf_AUX_AsFix2muASF_C4_1 , lf_AUX_AsFix2muASF_C4_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Rule\"),ql(\";\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf5 , lf5sym);
}
void resolve_AUX_AsFix2muASF_C4( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-equ\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-equ\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"aterm2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"aterm2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"make-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"make-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"is-default\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"is-default\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"tag\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"tag\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-when\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-when\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"conditions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"conditions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"conds2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"conds2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)"));
ef20= lookup_func( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"make-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"make-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef21= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-impl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ceq-impl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_AsFix2muASF_C4_1( aterm * arg0 , aterm * arg1 , aterm * arg2) {
{
aterm * tmp[30];
PROF( prof_lf_AUX_AsFix2muASF_C4_1);
if( check_sym( arg0 , ef1sym)) {
t_protect( arg1);
tmp[ 0]= ( * ef3)( arg1 , ( * ef4)( ));
t_protect( tmp[ 0]);
t_protect( tmp[ 0]);
t_protect( arg2);
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
if( m_is_single_element( tmp[ 7])) {
tmp[ 8]= m_list_head( tmp[ 7]);
t_protect( arg1);
tmp[ 9]= ( * ef3)( arg1 , ( * ef9)( ));
t_protect( tmp[ 9]);
t_protect( tmp[ 9]);
t_protect( tmp[ 4]);
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
if( m_is_single_element( tmp[ 16])) {
tmp[ 17]= m_list_head( tmp[ 16]);
t_protect( tmp[ 5]);
t_protect( tmp[ 14]);
tmp[ 18]= ( * ef10)( ( * ef11)( lf2( make_list( tmp[ 5]))) , ( * ef11)( lf2( make_list( tmp[ 14]))));
if( check_sym( tmp[ 18] , ef11sym)) {
tmp[ 19]= arg_0( tmp[ 18]);
if( check_sym( tmp[ 19] , lf2sym)) {
tmp[ 20]= arg_0( tmp[ 19]);
t_protect( arg1);
t_protect( tmp[ 8]);
t_protect( tmp[ 17]);
tmp[ 21]= ( * ef12)( ( * ef13)( ( * ef3)( arg1 , ( * ef14)( ))) , tmp[ 8] , tmp[ 17]);
t_protect( tmp[ 20]);
t_protect( tmp[ 13]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
return ( * ef2)( lf2( make_list( tmp[ 20])) , lf3( make_list( tmp[ 21])) , tmp[ 13]);
}
}
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 17]);
}
}
}
}
}
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 8]);
}
}
}
}
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
if( check_sym( arg0 , ef15sym)) {
t_protect( arg1);
tmp[ 0]= ( * ef3)( arg1 , ( * ef4)( ));
t_protect( tmp[ 0]);
t_protect( tmp[ 0]);
t_protect( arg2);
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
if( m_is_single_element( tmp[ 7])) {
tmp[ 8]= m_list_head( tmp[ 7]);
t_protect( arg1);
tmp[ 9]= ( * ef3)( arg1 , ( * ef9)( ));
t_protect( tmp[ 9]);
t_protect( tmp[ 9]);
t_protect( tmp[ 4]);
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
if( m_is_single_element( tmp[ 16])) {
tmp[ 17]= m_list_head( tmp[ 16]);
t_protect( arg1);
tmp[ 18]= ( * ef3)( arg1 , ( * ef16)( ));
if( check_sym( tmp[ 18] , ef17sym)) {
tmp[ 19]= arg_0( tmp[ 18]);
t_protect( tmp[ 19]);
t_protect( tmp[ 13]);
tmp[ 20]= ( * ef18)( tmp[ 19] , tmp[ 13]);
if( check_sym( tmp[ 20] , ef19sym)) {
tmp[ 21]= arg_0( tmp[ 20]);
tmp[ 22]= arg_1( tmp[ 20]);
tmp[ 23]= arg_2( tmp[ 20]);
if( check_sym( tmp[ 21] , lf2sym)) {
tmp[ 24]= arg_0( tmp[ 21]);
if( check_sym( tmp[ 22] , lf5sym)) {
tmp[ 25]= arg_0( tmp[ 22]);
if( m_not_empty_list( tmp[ 25])) {
t_protect( tmp[ 5]);
t_protect( tmp[ 14]);
t_protect( tmp[ 24]);
tmp[ 26]= ( * ef10)( ( * ef10)( ( * ef11)( lf2( make_list( tmp[ 5]))) , ( * ef11)( lf2( make_list( tmp[ 14])))) , ( * ef11)( lf2( make_list( tmp[ 24]))));
if( check_sym( tmp[ 26] , ef11sym)) {
tmp[ 27]= arg_0( tmp[ 26]);
if( check_sym( tmp[ 27] , lf2sym)) {
tmp[ 28]= arg_0( tmp[ 27]);
t_protect( arg1);
t_protect( tmp[ 25]);
t_protect( tmp[ 8]);
t_protect( tmp[ 17]);
tmp[ 29]= ( * ef20)( ( * ef13)( ( * ef3)( arg1 , ( * ef14)( ))) , lf5( make_list( tmp[ 25])) , tmp[ 8] , tmp[ 17]);
t_protect( tmp[ 28]);
t_protect( tmp[ 23]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 26]);
return ( * ef2)( lf2( make_list( tmp[ 28])) , lf3( make_list( tmp[ 29])) , tmp[ 23]);
}
}
t_unprotect( tmp[ 26]);
}
}
}
}
t_unprotect( tmp[ 20]);
}
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 17]);
}
}
}
}
}
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 8]);
}
}
}
}
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
if( check_sym( arg0 , ef21sym)) {
t_protect( arg1);
tmp[ 0]= ( * ef3)( arg1 , ( * ef4)( ));
t_protect( tmp[ 0]);
t_protect( tmp[ 0]);
t_protect( arg2);
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
if( m_is_single_element( tmp[ 7])) {
tmp[ 8]= m_list_head( tmp[ 7]);
t_protect( arg1);
tmp[ 9]= ( * ef3)( arg1 , ( * ef9)( ));
t_protect( tmp[ 9]);
t_protect( tmp[ 9]);
t_protect( tmp[ 4]);
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
if( m_is_single_element( tmp[ 16])) {
tmp[ 17]= m_list_head( tmp[ 16]);
t_protect( arg1);
tmp[ 18]= ( * ef3)( arg1 , ( * ef16)( ));
if( check_sym( tmp[ 18] , ef17sym)) {
tmp[ 19]= arg_0( tmp[ 18]);
t_protect( tmp[ 19]);
t_protect( tmp[ 13]);
tmp[ 20]= ( * ef18)( tmp[ 19] , tmp[ 13]);
if( check_sym( tmp[ 20] , ef19sym)) {
tmp[ 21]= arg_0( tmp[ 20]);
tmp[ 22]= arg_1( tmp[ 20]);
tmp[ 23]= arg_2( tmp[ 20]);
if( check_sym( tmp[ 21] , lf2sym)) {
tmp[ 24]= arg_0( tmp[ 21]);
if( check_sym( tmp[ 22] , lf5sym)) {
tmp[ 25]= arg_0( tmp[ 22]);
if( m_not_empty_list( tmp[ 25])) {
t_protect( tmp[ 5]);
t_protect( tmp[ 14]);
t_protect( tmp[ 24]);
tmp[ 26]= ( * ef10)( ( * ef10)( ( * ef11)( lf2( make_list( tmp[ 5]))) , ( * ef11)( lf2( make_list( tmp[ 14])))) , ( * ef11)( lf2( make_list( tmp[ 24]))));
if( check_sym( tmp[ 26] , ef11sym)) {
tmp[ 27]= arg_0( tmp[ 26]);
if( check_sym( tmp[ 27] , lf2sym)) {
tmp[ 28]= arg_0( tmp[ 27]);
t_protect( arg1);
t_protect( tmp[ 25]);
t_protect( tmp[ 8]);
t_protect( tmp[ 17]);
tmp[ 29]= ( * ef20)( ( * ef13)( ( * ef3)( arg1 , ( * ef14)( ))) , lf5( make_list( tmp[ 25])) , tmp[ 8] , tmp[ 17]);
t_protect( tmp[ 28]);
t_protect( tmp[ 23]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 26]);
return ( * ef2)( lf2( make_list( tmp[ 28])) , lf3( make_list( tmp[ 29])) , tmp[ 23]);
}
}
t_unprotect( tmp[ 26]);
}
}
}
}
t_unprotect( tmp[ 20]);
}
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 17]);
}
}
}
}
}
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 8]);
}
}
}
}
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
return make_nf3( lf_AUX_AsFix2muASF_C4_1sym , arg0 , arg1 , arg2);
}
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

