#include  "asc-support.h"
static Symbol lf_AUX_TermAsFix2Sign21_1sym ;
static ATerm lf_AUX_TermAsFix2Sign21_1 ( ATerm arg1 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef7sym ;
static funcptr ef7 ;
void register_AUX_TermAsFix2Sign21 ( ) {
lf_AUX_TermAsFix2Sign21_1sym = ATmakeSymbol ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"associativity-attr2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_TermAsFix2Sign21_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"associativity-attr2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) , lf_AUX_TermAsFix2Sign21_1 , lf_AUX_TermAsFix2Sign21_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_TermAsFix2Sign21 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-left-assoc-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-left-assoc-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-right-assoc-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-right-assoc-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-assoc-assoc-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-assoc-assoc-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-nonassoc-assoc-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-nonassoc-assoc-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
static ATerm constant3 = NULL ;
void init_AUX_TermAsFix2Sign21 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
ATprotect ( & constant3 ) ;
}
ATerm lf_AUX_TermAsFix2Sign21_1 ( ATerm arg0 ) {
{
ATerm tmp [ 1 ] ;
FUNC_ENTRY ( lf_AUX_TermAsFix2Sign21_1sym , ATmakeAppl ( lf_AUX_TermAsFix2Sign21_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef3sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
{
ATerm atmp011 = arg_1 ( atmp01 ) ;
if ( check_sym ( atmp011 , ef3sym ) ) {
{
ATerm atmp0110 = arg_0 ( atmp011 ) ;
{
ATerm atmp0111 = arg_1 ( atmp011 ) ;
if ( check_sym ( atmp0111 , ef4sym ) ) {
{
ATerm atmp01110 = arg_0 ( atmp0111 ) ;
( tmp [ 0 ] = ( * ef7 ) ( ) ) ;
if ( term_equal ( ( * ef6 ) ( atmp010 ) , tmp [ 0 ] ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 13 , char_table [ 34 ] , char_table [ 108 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 108 ] , char_table [ 101 ] , char_table [ 102 ] , char_table [ 116 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 34 ] ) ) ) ) ;
}
if ( term_equal ( ( * ef8 ) ( atmp010 ) , tmp [ 0 ] ) ) {
FUNC_EXIT_CONST ( constant1 , ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 14 , char_table [ 34 ] , char_table [ 108 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 114 ] , char_table [ 105 ] , char_table [ 103 ] , char_table [ 104 ] , char_table [ 116 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 34 ] ) ) ) ) ;
}
if ( term_equal ( ( * ef9 ) ( atmp010 ) , tmp [ 0 ] ) ) {
FUNC_EXIT_CONST ( constant2 , ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 14 , char_table [ 34 ] , char_table [ 108 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 97 ] , char_table [ 115 ] , char_table [ 115 ] , char_table [ 111 ] , char_table [ 99 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 34 ] ) ) ) ) ;
}
if ( term_equal ( ( * ef10 ) ( atmp010 ) , tmp [ 0 ] ) ) {
FUNC_EXIT_CONST ( constant3 , ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 18 , char_table [ 34 ] , char_table [ 108 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 110 ] , char_table [ 111 ] , char_table [ 110 ] , char_table [ 45 ] , char_table [ 97 ] , char_table [ 115 ] , char_table [ 115 ] , char_table [ 111 ] , char_table [ 99 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 34 ] ) ) ) ) ;
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
FUNC_EXIT ( make_nf1 ( lf_AUX_TermAsFix2Sign21_1sym , arg0 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

