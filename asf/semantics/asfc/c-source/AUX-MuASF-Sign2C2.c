#include "support.h"
static Symbol lf_AUX_MuASF_Sign2C2_2sym;
static ATerm lf_AUX_MuASF_Sign2C2_2( ATerm arg1 , ATerm arg2);
static Symbol ef2sym;
static funcptr ef2;
static Symbol lf4sym;
static ATerm lf4( ATerm arg1);
static Symbol ef8sym;
static funcptr ef8;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef4sym;
static funcptr ef4;
static Symbol lf5sym;
static ATerm lf5( ATerm arg1);
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef6sym;
static funcptr ef6;
static Symbol lf_AUX_MuASF_Sign2C2_1sym;
static ATerm lf_AUX_MuASF_Sign2C2_1( ATerm arg1);
static Symbol ef9sym;
static funcptr ef9;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
void register_AUX_MuASF_Sign2C2( ) {
lf_AUX_MuASF_Sign2C2_2sym= ATmakeSymbol( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"sigargs2cargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Sign2C2_2sym);
lf4sym= ATmakeSymbol( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf4sym);
lf5sym= ATmakeSymbol( "listtype(sort(\"Type-specifier\"))" , 1 , ATtrue);
ATprotectSymbol( lf5sym);
lf_AUX_MuASF_Sign2C2_1sym= ATmakeSymbol( "listtype(sort(\"SigArg\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Sign2C2_1sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
register_prod( ATparse( "listtype(sort(\"SigArg\"),ql(\",\"))") , lf_AUX_MuASF_Sign2C2_1 , lf_AUX_MuASF_Sign2C2_1sym);
register_prod( ATparse( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"sigargs2cargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Sign2C2_2 , lf_AUX_MuASF_Sign2C2_2sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
register_prod( ATparse( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( ATparse( "listtype(sort(\"Type-specifier\"))") , lf5 , lf5sym);
}
void resolve_AUX_MuASF_Sign2C2( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Parameter-declaration\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Parameter-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Parameter-declaration\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Parameter-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"));
ef9= lookup_func( ATreadFromString( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( ATreadFromString( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
static ATerm constant3= NULL;
void init_AUX_MuASF_Sign2C2( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
ATprotect( & constant3);
}
ATerm lf_AUX_MuASF_Sign2C2_2( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[5];
PROF( prof_lf_AUX_MuASF_Sign2C2_2);
if( check_sym( arg0 , lf_AUX_MuASF_Sign2C2_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( arg1 , ef1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf3sym)) {
{
ATerm atmp100= arg_0( atmp10);
if( is_single_element( atmp00)) {
tmp[ 0]= list_head( atmp00);
return ( * ef2)( lf4( make_list( ( * ef3)( ( constant0? constant0: ( constant0= ( * ef4)( lf5( make_list( ( * ef5)( ( * ef6)( lf3( (ATerm) ATmakeList( 5 , char_table[ 65] , char_table[ 84] , char_table[ 101] , char_table[ 114] , char_table[ 109]))))))))) , ( * ef7)( ( * ef6)( lf3( cons( ( constant1? constant1: ( constant1= make_list_char( 97))) , cons( ( constant2? constant2: ( constant2= make_list_char( 114))) , cons( ( constant3? constant3: ( constant3= make_list_char( 103))) , make_list( atmp100)))))))))));
}
}
}
}
}
if( not_empty_list( atmp00)) {
tmp[ 0]= list_head( atmp00);
tmp[ 1]= list_tail( atmp00);
if( not_empty_list( tmp[ 1])) {
tmp[ 2]= lf_AUX_MuASF_Sign2C2_2( lf_AUX_MuASF_Sign2C2_1( make_list( tmp[ 1])) , ( * ef9)( arg1));
if( check_sym( arg1 , ef1sym)) {
tmp[ 3]= arg_0( arg1);
if( check_sym( tmp[ 3] , lf3sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
return ( * ef8)( ( * ef3)( ( constant0? constant0: ( constant0= ( * ef4)( lf5( make_list( ( * ef5)( ( * ef6)( lf3( (ATerm) ATmakeList( 5 , char_table[ 65] , char_table[ 84] , char_table[ 101] , char_table[ 114] , char_table[ 109]))))))))) , ( * ef7)( ( * ef6)( lf3( cons( ( constant1? constant1: ( constant1= make_list_char( 97))) , cons( ( constant2? constant2: ( constant2= make_list_char( 114))) , cons( ( constant3? constant3: ( constant3= make_list_char( 103))) , make_list( tmp[ 4])))))))) , tmp[ 2]);
}
}
}
}
}
}
return make_nf2( lf_AUX_MuASF_Sign2C2_2sym , arg0 , arg1);
}
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
ATerm lf_AUX_MuASF_Sign2C2_1( ATerm arg0) {
PROF( prof_lf_AUX_MuASF_Sign2C2_1);
return make_nf1( lf_AUX_MuASF_Sign2C2_1sym , arg0);
}
ATerm lf5( ATerm arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
ATerm lf4( ATerm arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}

