#include "support.h"
static Symbol lf_AUX_Locate_Constants15_2sym;
static ATerm lf_AUX_Locate_Constants15_2( ATerm arg1 , ATerm arg2);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef5sym;
static funcptr ef5;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol ef6sym;
static funcptr ef6;
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef8sym;
static funcptr ef8;
static Symbol lf4sym;
static ATerm lf4( ATerm arg1);
static Symbol ef9sym;
static funcptr ef9;
static Symbol ef10sym;
static funcptr ef10;
static Symbol ef11sym;
static funcptr ef11;
static Symbol ef12sym;
static funcptr ef12;
static Symbol lf_AUX_Locate_Constants15_1sym;
static ATerm lf_AUX_Locate_Constants15_1( ATerm arg1);
static Symbol ef13sym;
static funcptr ef13;
static Symbol lf5sym;
static ATerm lf5( ATerm arg1);
void register_AUX_Locate_Constants15( ) {
lf_AUX_Locate_Constants15_2sym= ATmakeSymbol( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"make-init-function\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Locate_Constants15_2sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"Type-specifier\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
lf4sym= ATmakeSymbol( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf4sym);
lf_AUX_Locate_Constants15_1sym= ATmakeSymbol( "listtype(sort(\"CE-pair\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Locate_Constants15_1sym);
lf5sym= ATmakeSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf5sym);
register_prod( ATparse( "listtype(sort(\"CE-pair\"),ql(\",\"))") , lf_AUX_Locate_Constants15_1 , lf_AUX_Locate_Constants15_1sym);
register_prod( ATparse( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"make-init-function\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)") , lf_AUX_Locate_Constants15_2 , lf_AUX_Locate_Constants15_2sym);
register_prod( ATparse( "listtype(sort(\"Type-specifier\"))") , lf3 , lf3sym);
register_prod( ATparse( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( ATparse( "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf5 , lf5sym);
}
void resolve_AUX_Locate_Constants15( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[l(\"void\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[l(\"void\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef9= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef10= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef11= lookup_func( ATreadFromString( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"modname2iname\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( ATreadFromString( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"modname2iname\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef12= lookup_func( ATreadFromString( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"make-statements-function\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( ATreadFromString( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"make-statements-function\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"));
ef13= lookup_func( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
void init_AUX_Locate_Constants15( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
}
ATerm lf_AUX_Locate_Constants15_2( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[6];
PROF( prof_lf_AUX_Locate_Constants15_2);
if( check_sym( arg1 , lf_AUX_Locate_Constants15_1sym)) {
{
ATerm atmp10= arg_0( arg1);
tmp[ 0]= ( * ef11)( arg0);
tmp[ 1]= ( * ef12)( lf_AUX_Locate_Constants15_1( make_list( atmp10)));
if( check_sym( tmp[ 1] , ef13sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
tmp[ 3]= arg_1( tmp[ 1]);
tmp[ 4]= arg_2( tmp[ 1]);
if( check_sym( tmp[ 2] , lf5sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
if( ! not_empty_list( tmp[ 5])) {
return ( * ef1)( tmp[ 3] , ( * ef2)( ( * ef3)( ( * ef4)( ( constant0? constant0: ( constant0= ( * ef5)( lf3( make_list( ( * ef6)( )))))) , ( * ef7)( tmp[ 0] , ( constant1? constant1: ( constant1= ( * ef8)( lf4( make_list( null( ))))))) , ( * ef9)( ( constant2? constant2: ( constant2= ( * ef10)( ))) , tmp[ 4])))));
}
}
}
}
}
return make_nf2( lf_AUX_Locate_Constants15_2sym , arg0 , arg1);
}
}
ATerm lf5( ATerm arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
ATerm lf_AUX_Locate_Constants15_1( ATerm arg0) {
PROF( prof_lf_AUX_Locate_Constants15_1);
return make_nf1( lf_AUX_Locate_Constants15_1sym , arg0);
}
ATerm lf4( ATerm arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

