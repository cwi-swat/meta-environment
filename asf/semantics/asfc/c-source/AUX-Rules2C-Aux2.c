#include "support.h"
static Symbol lf_AUX_Rules2C_Aux2_1sym;
static ATerm lf_AUX_Rules2C_Aux2_1( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef11sym;
static funcptr ef11;
static Symbol ef13sym;
static funcptr ef13;
static Symbol ef5sym;
static funcptr ef5;
static Symbol lf5sym;
static ATerm lf5( ATerm arg1);
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef8sym;
static funcptr ef8;
static Symbol ef9sym;
static funcptr ef9;
static Symbol lf6sym;
static ATerm lf6( ATerm arg1);
static Symbol ef6sym;
static funcptr ef6;
static Symbol ef14sym;
static funcptr ef14;
static Symbol ef12sym;
static funcptr ef12;
static Symbol ef2sym;
static funcptr ef2;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol ef10sym;
static funcptr ef10;
static Symbol lf7sym;
static ATerm lf7( ATerm arg1);
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef4sym;
static funcptr ef4;
static Symbol lf4sym;
static ATerm lf4( ATerm arg1);
void register_AUX_Rules2C_Aux2( ) {
lf_AUX_Rules2C_Aux2_1sym= ATmakeSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux2_1sym);
lf5sym= ATmakeSymbol( "listtype(sort(\"AInt\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf5sym);
lf6sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf6sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
lf7sym= ATmakeSymbol( "listtype(sort(\"TE-pair\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf7sym);
lf4sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf4sym);
register_prod( ATparse( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux2_1 , lf_AUX_Rules2C_Aux2_1sym);
register_prod( ATparse( "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf2 , lf2sym);
register_prod( ATparse( "listtype(sort(\"Cond\"),ql(\"&\"))") , lf3 , lf3sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( ATparse( "listtype(sort(\"AInt\"),ql(\",\"))") , lf5 , lf5sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf6 , lf6sym);
register_prod( ATparse( "listtype(sort(\"TE-pair\"),ql(\",\"))") , lf7 , lf7sym);
}
void resolve_AUX_Rules2C_Aux2( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"code-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"code-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)"));
ef9= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"funargs2cexp\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"funargs2cexp\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef10= lookup_func( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef11= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef12= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef13= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef14= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
static ATerm constant3= NULL;
static ATerm constant4= NULL;
static ATerm constant5= NULL;
void init_AUX_Rules2C_Aux2( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
ATprotect( & constant3);
ATprotect( & constant4);
ATprotect( & constant5);
}
ATerm lf_AUX_Rules2C_Aux2_1( ATerm arg0) {
{
ATerm tmp[9];
PROF( prof_lf_AUX_Rules2C_Aux2_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
{
ATerm atmp01= arg_1( arg0);
tmp[ 0]= ( * ef3)( atmp00);
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf4sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( not_empty_list( tmp[ 2])) {
tmp[ 3]= ( * ef5)( lf4( make_list( tmp[ 2])) , ( constant0? constant0: ( constant0= lf5( make_list( ( * ef6)( lf6( make_list( make_char( 48)))))))));
if( check_sym( tmp[ 3] , ef7sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
tmp[ 5]= arg_1( tmp[ 3]);
if( check_sym( tmp[ 4] , ef8sym)) {
tmp[ 6]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
tmp[ 8]= ( * ef9)( lf4( make_list( tmp[ 2])) , ( constant1? constant1: ( constant1= ( * ef6)( lf6( make_list( make_char( 48)))))));
return ( * ef2)( lf2( make_list( tmp[ 7])) , ( constant2? constant2: ( constant2= lf3( make_list( null( ))))) , atmp01 , tmp[ 5] , tmp[ 8]);
}
}
}
}
}
}
if( term_equal( ( * ef3)( atmp00) , ( constant3? constant3: ( constant3= ( * ef4)( lf4( make_list( null( )))))))) {
return ( * ef2)( ( constant4? constant4: ( constant4= lf2( make_list( null( ))))) , ( constant2? constant2: ( constant2= lf3( make_list( null( ))))) , atmp01 , ( constant5? constant5: ( constant5= ( * ef10)( lf7( make_list( null( )))))) , ( constant5? constant5: ( constant5= ( * ef10)( lf7( make_list( null( )))))));
}
}
}
}
if( check_sym( arg0 , ef11sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef12sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf3sym)) {
{
ATerm atmp0000= arg_0( atmp000);
{
ATerm atmp01= arg_1( arg0);
{
ATerm atmp02= arg_2( arg0);
tmp[ 0]= ( * ef3)( atmp01);
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf4sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( not_empty_list( tmp[ 2])) {
tmp[ 3]= ( * ef5)( lf4( make_list( tmp[ 2])) , ( constant0? constant0: ( constant0= lf5( make_list( ( * ef6)( lf6( make_list( make_char( 48)))))))));
if( check_sym( tmp[ 3] , ef7sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
tmp[ 5]= arg_1( tmp[ 3]);
if( check_sym( tmp[ 4] , ef8sym)) {
tmp[ 6]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
tmp[ 8]= ( * ef9)( lf4( make_list( tmp[ 2])) , ( constant1? constant1: ( constant1= ( * ef6)( lf6( make_list( make_char( 48)))))));
return ( * ef2)( lf2( make_list( tmp[ 7])) , lf3( make_list( atmp0000)) , atmp02 , tmp[ 5] , tmp[ 8]);
}
}
}
}
}
}
if( term_equal( ( * ef3)( atmp01) , ( constant3? constant3: ( constant3= ( * ef4)( lf4( make_list( null( )))))))) {
return ( * ef2)( ( constant4? constant4: ( constant4= lf2( make_list( null( ))))) , lf3( make_list( atmp0000)) , atmp02 , ( constant5? constant5: ( constant5= ( * ef10)( lf7( make_list( null( )))))) , ( constant5? constant5: ( constant5= ( * ef10)( lf7( make_list( null( )))))));
}
}
}
}
}
}
}
}
}
if( check_sym( arg0 , ef13sym)) {
{
ATerm atmp00= arg_0( arg0);
{
ATerm atmp01= arg_1( arg0);
tmp[ 0]= ( * ef3)( atmp00);
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf4sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( not_empty_list( tmp[ 2])) {
tmp[ 3]= ( * ef5)( lf4( make_list( tmp[ 2])) , ( constant0? constant0: ( constant0= lf5( make_list( ( * ef6)( lf6( make_list( make_char( 48)))))))));
if( check_sym( tmp[ 3] , ef7sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
tmp[ 5]= arg_1( tmp[ 3]);
if( check_sym( tmp[ 4] , ef8sym)) {
tmp[ 6]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
tmp[ 8]= ( * ef9)( lf4( make_list( tmp[ 2])) , ( constant1? constant1: ( constant1= ( * ef6)( lf6( make_list( make_char( 48)))))));
return ( * ef2)( lf2( make_list( tmp[ 7])) , ( constant2? constant2: ( constant2= lf3( make_list( null( ))))) , atmp01 , tmp[ 5] , tmp[ 8]);
}
}
}
}
}
}
if( term_equal( ( * ef3)( atmp00) , ( constant3? constant3: ( constant3= ( * ef4)( lf4( make_list( null( )))))))) {
return ( * ef2)( ( constant4? constant4: ( constant4= lf2( make_list( null( ))))) , ( constant2? constant2: ( constant2= lf3( make_list( null( ))))) , atmp01 , ( constant5? constant5: ( constant5= ( * ef10)( lf7( make_list( null( )))))) , ( constant5? constant5: ( constant5= ( * ef10)( lf7( make_list( null( )))))));
}
}
}
}
if( check_sym( arg0 , ef14sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef12sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf3sym)) {
{
ATerm atmp0000= arg_0( atmp000);
{
ATerm atmp01= arg_1( arg0);
{
ATerm atmp02= arg_2( arg0);
tmp[ 0]= ( * ef3)( atmp01);
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf4sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( not_empty_list( tmp[ 2])) {
tmp[ 3]= ( * ef5)( lf4( make_list( tmp[ 2])) , ( constant0? constant0: ( constant0= lf5( make_list( ( * ef6)( lf6( make_list( make_char( 48)))))))));
if( check_sym( tmp[ 3] , ef7sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
tmp[ 5]= arg_1( tmp[ 3]);
if( check_sym( tmp[ 4] , ef8sym)) {
tmp[ 6]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
tmp[ 8]= ( * ef9)( lf4( make_list( tmp[ 2])) , ( constant1? constant1: ( constant1= ( * ef6)( lf6( make_list( make_char( 48)))))));
return ( * ef2)( lf2( make_list( tmp[ 7])) , lf3( make_list( atmp0000)) , atmp02 , tmp[ 5] , tmp[ 8]);
}
}
}
}
}
}
if( term_equal( ( * ef3)( atmp01) , ( constant3? constant3: ( constant3= ( * ef4)( lf4( make_list( null( )))))))) {
return ( * ef2)( ( constant4? constant4: ( constant4= lf2( make_list( null( ))))) , lf3( make_list( atmp0000)) , atmp02 , ( constant5? constant5: ( constant5= ( * ef10)( lf7( make_list( null( )))))) , ( constant5? constant5: ( constant5= ( * ef10)( lf7( make_list( null( )))))));
}
}
}
}
}
}
}
}
}
return make_nf1( lf_AUX_Rules2C_Aux2_1sym , arg0);
}
}
ATerm lf4( ATerm arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
ATerm lf7( ATerm arg0) {
PROF( prof_lf7);
return make_nf1( lf7sym , arg0);
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}
ATerm lf6( ATerm arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}
ATerm lf5( ATerm arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}

