#include "support.h"
static Symbol lf_AUX_MuASF2C2_1sym;
static ATerm lf_AUX_MuASF2C2_1( ATerm arg1);
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
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
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
static Symbol ef8sym;
static funcptr ef8;
void register_AUX_MuASF2C2( ) {
lf_AUX_MuASF2C2_1sym= ATmakeSymbol( "prod(id(\"MuASF2C\"),w(\"\"),[l(\"muASF2C\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CProgram\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF2C2_1sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"MuASF2C\"),w(\"\"),[l(\"muASF2C\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CProgram\"),w(\"\"),no-attrs)") , lf_AUX_MuASF2C2_1 , lf_AUX_MuASF2C2_1sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
register_prod( ATparse( "listtype(sort(\"NamePair\"),ql(\",\"))") , lf3 , lf3sym);
}
void resolve_AUX_MuASF2C2( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"module\"),w(\"\"),sort(\"ModId\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),sort(\"RulesOpt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"module\"),w(\"\"),sort(\"ModId\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),sort(\"RulesOpt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"modid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"modid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModId\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"MuASF2C\"),w(\"\"),[l(\"muASF2C-internal\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CProgram\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF2C\"),w(\"\"),[l(\"muASF2C-internal\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CProgram\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"MuASF2C\"),w(\"\"),[l(\"create-name-table\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF2C\"),w(\"\"),[l(\"create-name-table\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
static ATerm constant3= NULL;
static ATerm constant4= NULL;
void init_AUX_MuASF2C2( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
ATprotect( & constant3);
ATprotect( & constant4);
}
ATerm lf_AUX_MuASF2C2_1( ATerm arg0) {
{
ATerm tmp[1];
PROF( prof_lf_AUX_MuASF2C2_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf2sym)) {
{
ATerm atmp0000= arg_0( atmp000);
{
ATerm atmp01= arg_1( arg0);
{
ATerm atmp02= arg_2( arg0);
tmp[ 0]= ( * ef4)( atmp01 , ( * ef5)( ( constant0? constant0: ( constant0= lf3( make_list( null( ))))) , ( * ef6)( lf2( cons( ( constant1? constant1: ( constant1= make_list( make_char( 108)))) , cons( ( constant2? constant2: ( constant2= make_list( make_char( 102)))) , cons( ( constant3? constant3: ( constant3= make_list( make_char( 95)))) , make_list( atmp0000)))))) , ( constant4? constant4: ( constant4= ( * ef7)( ( * ef8)( lf2( make_list( make_char( 49))))))) , ( constant4? constant4: ( constant4= ( * ef7)( ( * ef8)( lf2( make_list( make_char( 49)))))))));
return ( * ef3)( ( * ef1)( ( * ef2)( lf2( make_list( atmp0000))) , atmp01 , atmp02) , tmp[ 0]);
}
}
}
}
}
}
}
}
return make_nf1( lf_AUX_MuASF2C2_1sym , arg0);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

