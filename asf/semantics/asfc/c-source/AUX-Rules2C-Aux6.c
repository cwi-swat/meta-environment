#include "support.h"
static asymbol * lf_AUX_Rules2C_Aux6_2sym;
static aterm * lf_AUX_Rules2C_Aux6_2( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf_AUX_Rules2C_Aux6_1sym;
static aterm * lf_AUX_Rules2C_Aux6_1( aterm * arg1);
void register_AUX_Rules2C_Aux6( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Rules2C_Aux6_2sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-defaults\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux6_1sym= TmkSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Rule\"),ql(\";\"))") , lf_AUX_Rules2C_Aux6_1 , lf_AUX_Rules2C_Aux6_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-defaults\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux6_2 , lf_AUX_Rules2C_Aux6_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf3 , lf3sym);
}
void resolve_AUX_Rules2C_Aux6( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Rules2C_Aux6_2( aterm * arg0) {
{
aterm * tmp[12];
PROF( prof_lf_AUX_Rules2C_Aux6_2);
if( check_sym( arg0 , lf_AUX_Rules2C_Aux6_1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
if( check_sym( tmp[ 1] , ef5sym)) {
tmp[ 4]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 4] , lf3sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
t_protect( tmp[ 5]);
if( not_empty_list( tmp[ 5])) {
t_protect( atmp00);
tmp[ 6]= list_tail( atmp00);
t_protect( tmp[ 6]);
tmp[ 7]= lf_AUX_Rules2C_Aux6_2( lf_AUX_Rules2C_Aux6_1( make_list( tmp[ 6])));
if( check_sym( tmp[ 7] , ef1sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
tmp[ 9]= arg_1( tmp[ 7]);
if( check_sym( tmp[ 8] , lf_AUX_Rules2C_Aux6_1sym)) {
tmp[ 10]= arg_0( tmp[ 8]);
if( check_sym( tmp[ 9] , lf_AUX_Rules2C_Aux6_1sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
t_protect( tmp[ 10]);
t_protect( tmp[ 5]);
t_protect( tmp[ 2]);
t_protect( tmp[ 3]);
t_protect( tmp[ 11]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
return ( * ef1)( lf_AUX_Rules2C_Aux6_1( make_list( tmp[ 10])) , lf_AUX_Rules2C_Aux6_1( cons( make_list( ( * ef4)( ( * ef5)( lf3( make_list( tmp[ 5]))) , tmp[ 2] , tmp[ 3])) , make_list( tmp[ 11]))));
}
}
}
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 6]);
}
}
}
}
if( check_sym( tmp[ 0] , ef6sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
if( check_sym( tmp[ 1] , ef5sym)) {
tmp[ 4]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 4] , lf3sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
t_protect( tmp[ 5]);
if( not_empty_list( tmp[ 5])) {
t_protect( atmp00);
tmp[ 6]= list_tail( atmp00);
t_protect( tmp[ 6]);
tmp[ 7]= lf_AUX_Rules2C_Aux6_2( lf_AUX_Rules2C_Aux6_1( make_list( tmp[ 6])));
if( check_sym( tmp[ 7] , ef1sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
tmp[ 9]= arg_1( tmp[ 7]);
if( check_sym( tmp[ 8] , lf_AUX_Rules2C_Aux6_1sym)) {
tmp[ 10]= arg_0( tmp[ 8]);
if( check_sym( tmp[ 9] , lf_AUX_Rules2C_Aux6_1sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
t_protect( tmp[ 5]);
t_protect( tmp[ 2]);
t_protect( tmp[ 3]);
t_protect( tmp[ 10]);
t_protect( tmp[ 11]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
return ( * ef1)( lf_AUX_Rules2C_Aux6_1( cons( make_list( ( * ef6)( ( * ef5)( lf3( make_list( tmp[ 5]))) , tmp[ 2] , tmp[ 3])) , make_list( tmp[ 10]))) , lf_AUX_Rules2C_Aux6_1( make_list( tmp[ 11])));
}
}
}
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 6]);
}
}
}
}
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
t_protect( atmp00);
tmp[ 3]= list_tail( atmp00);
t_protect( tmp[ 3]);
tmp[ 4]= lf_AUX_Rules2C_Aux6_2( lf_AUX_Rules2C_Aux6_1( make_list( tmp[ 3])));
if( check_sym( tmp[ 4] , ef1sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
if( check_sym( tmp[ 5] , lf_AUX_Rules2C_Aux6_1sym)) {
tmp[ 7]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , lf_AUX_Rules2C_Aux6_1sym)) {
tmp[ 8]= arg_0( tmp[ 6]);
t_protect( tmp[ 7]);
t_protect( tmp[ 1]);
t_protect( tmp[ 2]);
t_protect( tmp[ 8]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
return ( * ef1)( lf_AUX_Rules2C_Aux6_1( make_list( tmp[ 7])) , lf_AUX_Rules2C_Aux6_1( cons( make_list( ( * ef2)( tmp[ 1] , tmp[ 2])) , make_list( tmp[ 8]))));
}
}
}
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 3]);
}
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
t_protect( atmp00);
tmp[ 3]= list_tail( atmp00);
t_protect( tmp[ 3]);
tmp[ 4]= lf_AUX_Rules2C_Aux6_2( lf_AUX_Rules2C_Aux6_1( make_list( tmp[ 3])));
if( check_sym( tmp[ 4] , ef1sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
if( check_sym( tmp[ 5] , lf_AUX_Rules2C_Aux6_1sym)) {
tmp[ 7]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , lf_AUX_Rules2C_Aux6_1sym)) {
tmp[ 8]= arg_0( tmp[ 6]);
t_protect( tmp[ 1]);
t_protect( tmp[ 2]);
t_protect( tmp[ 7]);
t_protect( tmp[ 8]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
return ( * ef1)( lf_AUX_Rules2C_Aux6_1( cons( make_list( ( * ef3)( tmp[ 1] , tmp[ 2])) , make_list( tmp[ 7]))) , lf_AUX_Rules2C_Aux6_1( make_list( tmp[ 8])));
}
}
}
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 0]);
}
else {
t_unprotect( arg0);
return ( * ef1)( lf_AUX_Rules2C_Aux6_1( make_list( null( ))) , lf_AUX_Rules2C_Aux6_1( make_list( null( ))));
}
}
}
return make_nf1( lf_AUX_Rules2C_Aux6_2sym , arg0);
}
}
aterm * lf_AUX_Rules2C_Aux6_1( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux6_1);
return make_nf1( lf_AUX_Rules2C_Aux6_1sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

