#include "support.h"
static Symbol lf_AUX_ATypes2_1sym;
static ATerm lf_AUX_ATypes2_1( ATerm arg1);
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef6sym;
static funcptr ef6;
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef9sym;
static funcptr ef9;
static Symbol ef8sym;
static funcptr ef8;
static Symbol ef10sym;
static funcptr ef10;
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef11sym;
static funcptr ef11;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef13sym;
static funcptr ef13;
static Symbol ef15sym;
static funcptr ef15;
static Symbol ef14sym;
static funcptr ef14;
static Symbol ef17sym;
static funcptr ef17;
static Symbol ef19sym;
static funcptr ef19;
static Symbol ef20sym;
static funcptr ef20;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef21sym;
static funcptr ef21;
static Symbol ef16sym;
static funcptr ef16;
static Symbol ef22sym;
static funcptr ef22;
static Symbol ef18sym;
static funcptr ef18;
static Symbol ef12sym;
static funcptr ef12;
void register_AUX_ATypes2( ) {
lf_AUX_ATypes2_1sym= ATmakeSymbol( "prod(id(\"ATypes\"),w(\"\"),[l(\"type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATypes2_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"ATypes\"),w(\"\"),[l(\"type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ATypes2_1 , lf_AUX_ATypes2_1sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_ATypes2( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"AVars\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"AVars\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aname\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aname\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"ATypes\"),w(\"\"),[l(\"int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"ATypes\"),w(\"\"),[l(\"int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"ATypes\"),w(\"\"),[l(\"str\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"ATypes\"),w(\"\"),[l(\"str\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef9= lookup_func( ATreadFromString( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( ATreadFromString( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)"));
ef10= lookup_func( ATreadFromString( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( ATreadFromString( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)"));
ef11= lookup_func( ATreadFromString( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( ATreadFromString( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)"));
ef12= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef13= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef14= lookup_func( ATreadFromString( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( ATreadFromString( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef15= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef16= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef17= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef18= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Ann\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Ann\"),w(\"\"),no-attrs)"));
ef19= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef20= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef21= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef22= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef22sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
static ATerm constant3= NULL;
void init_AUX_ATypes2( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
ATprotect( & constant3);
}
ATerm lf_AUX_ATypes2_1( ATerm arg0) {
{
ATerm tmp[6];
PROF( prof_lf_AUX_ATypes2_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef3sym)) {
{
ATerm atmp0000= arg_0( atmp000);
if( check_sym( atmp0000 , lf2sym)) {
{
ATerm atmp00000= arg_0( atmp0000);
if( not_empty_list( atmp00000)) {
tmp[ 0]= list_head( atmp00000);
if( term_equal( tmp[ 0] , make_char( 65))) {
tmp[ 1]= list_tail( atmp00000);
{
if( not_empty_list( tmp[ 1])) {
tmp[ 2]= list_head( tmp[ 1]);
if( term_equal( tmp[ 2] , make_char( 78))) {
tmp[ 3]= list_tail( tmp[ 1]);
if( not_empty_list( tmp[ 3])) {
if( term_equal( list_head( tmp[ 3]) , make_char( 97))) {
tmp[ 4]= list_tail( tmp[ 3]);
if( not_empty_list( tmp[ 4])) {
if( term_equal( list_head( tmp[ 4]) , make_char( 109))) {
tmp[ 5]= list_tail( tmp[ 4]);
if( is_single_element( tmp[ 5])) {
if( term_equal( list_head( tmp[ 5]) , make_char( 101))) {
return ( constant0? constant0: ( constant0= ( * ef4)( ( * ef8)( ))));
}
}
}
}
}
}
}
if( term_equal( tmp[ 2] , make_char( 73))) {
tmp[ 3]= list_tail( tmp[ 1]);
if( not_empty_list( tmp[ 3])) {
if( term_equal( list_head( tmp[ 3]) , make_char( 110))) {
tmp[ 4]= list_tail( tmp[ 3]);
if( is_single_element( tmp[ 4])) {
if( term_equal( list_head( tmp[ 4]) , make_char( 116))) {
return ( constant1? constant1: ( constant1= ( * ef4)( ( * ef5)( ))));
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
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef9sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef3sym)) {
{
ATerm atmp0000= arg_0( atmp000);
if( check_sym( atmp0000 , lf2sym)) {
{
ATerm atmp00000= arg_0( atmp0000);
if( not_empty_list( atmp00000)) {
if( term_equal( list_head( atmp00000) , make_char( 65))) {
tmp[ 0]= list_tail( atmp00000);
if( not_empty_list( tmp[ 0])) {
if( term_equal( list_head( tmp[ 0]) , make_char( 78))) {
tmp[ 1]= list_tail( tmp[ 0]);
if( not_empty_list( tmp[ 1])) {
if( term_equal( list_head( tmp[ 1]) , make_char( 97))) {
tmp[ 2]= list_tail( tmp[ 1]);
if( not_empty_list( tmp[ 2])) {
if( term_equal( list_head( tmp[ 2]) , make_char( 109))) {
tmp[ 3]= list_tail( tmp[ 2]);
if( is_single_element( tmp[ 3])) {
if( term_equal( list_head( tmp[ 3]) , make_char( 101))) {
return ( constant0? constant0: ( constant0= ( * ef4)( ( * ef8)( ))));
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
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef10sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef3sym)) {
{
ATerm atmp0000= arg_0( atmp000);
if( check_sym( atmp0000 , lf2sym)) {
{
ATerm atmp00000= arg_0( atmp0000);
{
ATerm atmp001= arg_1( atmp00);
if( not_empty_list( atmp00000)) {
if( term_equal( list_head( atmp00000) , make_char( 65))) {
tmp[ 0]= list_tail( atmp00000);
if( not_empty_list( tmp[ 0])) {
if( term_equal( list_head( tmp[ 0]) , make_char( 78))) {
tmp[ 1]= list_tail( tmp[ 0]);
if( not_empty_list( tmp[ 1])) {
if( term_equal( list_head( tmp[ 1]) , make_char( 97))) {
tmp[ 2]= list_tail( tmp[ 1]);
if( not_empty_list( tmp[ 2])) {
if( term_equal( list_head( tmp[ 2]) , make_char( 109))) {
tmp[ 3]= list_tail( tmp[ 2]);
if( is_single_element( tmp[ 3])) {
if( term_equal( list_head( tmp[ 3]) , make_char( 101))) {
return atmp001;
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
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef11sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef3sym)) {
{
ATerm atmp0000= arg_0( atmp000);
if( check_sym( atmp0000 , lf2sym)) {
{
ATerm atmp00000= arg_0( atmp0000);
{
ATerm atmp001= arg_1( atmp00);
if( not_empty_list( atmp00000)) {
if( term_equal( list_head( atmp00000) , make_char( 65))) {
tmp[ 0]= list_tail( atmp00000);
if( not_empty_list( tmp[ 0])) {
if( term_equal( list_head( tmp[ 0]) , make_char( 78))) {
tmp[ 1]= list_tail( tmp[ 0]);
if( not_empty_list( tmp[ 1])) {
if( term_equal( list_head( tmp[ 1]) , make_char( 97))) {
tmp[ 2]= list_tail( tmp[ 1]);
if( not_empty_list( tmp[ 2])) {
if( term_equal( list_head( tmp[ 2]) , make_char( 109))) {
tmp[ 3]= list_tail( tmp[ 2]);
if( is_single_element( tmp[ 3])) {
if( term_equal( list_head( tmp[ 3]) , make_char( 101))) {
return atmp001;
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
}
}
}
if( check_sym( arg0 , ef4sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef6sym)) {
{
ATerm atmp000= arg_0( atmp00);
return ( constant2? constant2: ( constant2= ( * ef4)( ( * ef7)( ))));
}
}
{
ATerm atmp00= arg_0( arg0);
return arg0;
}
}
}
if( check_sym( arg0 , ef12sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef13sym)) {
return ( constant3? constant3: ( constant3= ( * ef4)( ( * ef14)( ))));
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef15sym)) {
{
ATerm atmp000= arg_0( atmp00);
return ( constant3? constant3: ( constant3= ( * ef4)( ( * ef14)( ))));
}
}
}
}
}
if( check_sym( arg0 , ef16sym)) {
{
ATerm atmp00= arg_0( arg0);
{
ATerm atmp01= arg_1( arg0);
return ( * ef4)( atmp00);
}
}
}
if( check_sym( arg0 , ef17sym)) {
{
ATerm atmp00= arg_0( arg0);
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef18sym)) {
{
ATerm atmp010= arg_0( atmp01);
return lf_AUX_ATypes2_1( ( * ef19)( atmp00));
}
}
}
}
}
if( check_sym( arg0 , ef20sym)) {
{
ATerm atmp00= arg_0( arg0);
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef18sym)) {
{
ATerm atmp010= arg_0( atmp01);
return lf_AUX_ATypes2_1( ( * ef4)( atmp00));
}
}
}
}
}
if( check_sym( arg0 , ef21sym)) {
{
ATerm atmp00= arg_0( arg0);
{
ATerm atmp01= arg_1( arg0);
{
ATerm atmp02= arg_2( arg0);
if( check_sym( atmp02 , ef18sym)) {
{
ATerm atmp020= arg_0( atmp02);
return lf_AUX_ATypes2_1( ( * ef16)( atmp00 , atmp01));
}
}
}
}
}
}
if( check_sym( arg0 , ef22sym)) {
{
ATerm atmp00= arg_0( arg0);
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef18sym)) {
{
ATerm atmp010= arg_0( atmp01);
return lf_AUX_ATypes2_1( ( * ef12)( atmp00));
}
}
}
}
}
return make_nf1( lf_AUX_ATypes2_1sym , arg0);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

