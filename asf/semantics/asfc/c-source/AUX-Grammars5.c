#include "support.h"
static Symbol lf_AUX_Grammars5_1sym;
static ATerm lf_AUX_Grammars5_1( ATerm arg1);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
void register_AUX_Grammars5( ) {
lf_AUX_Grammars5_1sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[l(\"norm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbols\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars5_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"Symbol\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[l(\"norm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbols\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)") , lf_AUX_Grammars5_1 , lf_AUX_Grammars5_1sym);
register_prod( ATparse( "listtype(sort(\"Symbol\"))") , lf2 , lf2sym);
}
void resolve_AUX_Grammars5( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef3= lookup_func( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[ql(\"Layout\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"Grammars\"),w(\"\"),[ql(\"Layout\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
void init_AUX_Grammars5( ) {
ATprotect( & constant0);
ATprotect( & constant1);
}
ATerm lf_AUX_Grammars5_1( ATerm arg0) {
{
ATerm tmp[1];
PROF( prof_lf_AUX_Grammars5_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
tmp[ 0]= arg_0( atmp00);
{
ATerm atmp0000[2];
atmp0000[ 0]= tmp[ 0];
if( not_empty_list( tmp[ 0])) {
tmp[ 0]= list_tail( tmp[ 0]);
atmp0000[ 1]= tmp[ 0];
while( not_empty_list( tmp[ 0])) {
if( not_empty_list( tmp[ 0])) {
return ( * ef2)( lf_AUX_Grammars5_1( ( * ef1)( lf2( slice( atmp0000[ 0] , atmp0000[ 1])))) , ( * ef2)( ( constant0? constant0: ( constant0= ( * ef1)( lf2( make_list( ( * ef3)( ( * ef4)( ))))))) , lf_AUX_Grammars5_1( ( * ef1)( lf2( tmp[ 0])))));
}
atmp0000[ 1]= list_tail( atmp0000[ 1]);
tmp[ 0]= atmp0000[ 1];
}
}
}
}
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( ! not_empty_list( atmp000)) {
return ( constant1? constant1: ( constant1= ( * ef1)( lf2( make_list( null( ))))));
}
if( is_single_element( atmp000)) {
tmp[ 0]= list_head( atmp000);
return ( * ef1)( lf2( make_list( tmp[ 0])));
}
}
}
}
}
return make_nf1( lf_AUX_Grammars5_1sym , arg0);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

