#include  "support.h"
static Symbol lf_AUX_MuASF_Signs9_1sym ;
static ATerm lf_AUX_MuASF_Signs9_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
void register_AUX_MuASF_Signs9 ( ) {
lf_AUX_MuASF_Signs9_1sym = ATmakeSymbol ( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-external-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Signs9_1sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"SigArg\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-external-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Signs9_1 , lf_AUX_MuASF_Signs9_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"SigArg\"),ql(\",\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_MuASF_Signs9 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),sort(\"Annotations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),sort(\"Annotations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Annotations\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Annotations\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\"),w(\"\"),sort(\"Annotations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\"),w(\"\"),sort(\"Annotations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"_\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SigArg\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"_\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SigArg\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
void init_AUX_MuASF_Signs9 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
}
ATerm lf_AUX_MuASF_Signs9_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 20 ] ;
PROF ( prof_lf_AUX_MuASF_Signs9_1 ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( not_empty_list ( atmp100 ) ) {
tmp [ 0 ] = list_head ( atmp100 ) ;
tmp [ 1 ] = list_tail ( atmp100 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
tmp [ 2 ] = lf_AUX_MuASF_Signs9_1 ( arg0 , ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 2 ] , ef6sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
tmp [ 5 ] = arg_2 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf4sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 5 ] , ef3sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf2sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( not_empty_list ( tmp [ 6 ] ) ) {
if ( is_single_element ( tmp [ 8 ] ) ) {
tmp [ 9 ] = list_head ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , ef4sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 10 ] , ef5sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 10 ] ) ;
if ( check_sym ( tmp [ 11 ] , lf3sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ;
if ( not_empty_list ( tmp [ 12 ] ) ) {
if ( term_equal ( list_head ( tmp [ 12 ] ) , make_char ( 101 ) ) ) {
tmp [ 13 ] = list_tail ( tmp [ 12 ] ) ;
if ( not_empty_list ( tmp [ 13 ] ) ) {
if ( term_equal ( list_head ( tmp [ 13 ] ) , make_char ( 120 ) ) ) {
tmp [ 14 ] = list_tail ( tmp [ 13 ] ) ;
if ( not_empty_list ( tmp [ 14 ] ) ) {
if ( term_equal ( list_head ( tmp [ 14 ] ) , make_char ( 116 ) ) ) {
tmp [ 15 ] = list_tail ( tmp [ 14 ] ) ;
if ( not_empty_list ( tmp [ 15 ] ) ) {
if ( term_equal ( list_head ( tmp [ 15 ] ) , make_char ( 101 ) ) ) {
tmp [ 16 ] = list_tail ( tmp [ 15 ] ) ;
if ( not_empty_list ( tmp [ 16 ] ) ) {
if ( term_equal ( list_head ( tmp [ 16 ] ) , make_char ( 114 ) ) ) {
tmp [ 17 ] = list_tail ( tmp [ 16 ] ) ;
if ( not_empty_list ( tmp [ 17 ] ) ) {
if ( term_equal ( list_head ( tmp [ 17 ] ) , make_char ( 110 ) ) ) {
tmp [ 18 ] = list_tail ( tmp [ 17 ] ) ;
if ( not_empty_list ( tmp [ 18 ] ) ) {
if ( term_equal ( list_head ( tmp [ 18 ] ) , make_char ( 97 ) ) ) {
tmp [ 19 ] = list_tail ( tmp [ 18 ] ) ;
if ( is_single_element ( tmp [ 19 ] ) ) {
if ( term_equal ( list_head ( tmp [ 19 ] ) , make_char ( 108 ) ) ) {
return ( * ef6 ) ( tmp [ 3 ] , lf4 ( cons ( ( constant0 ? constant0 : ( constant0 = make_list ( ( * ef7 ) ( ) ) ) ) , make_list ( tmp [ 6 ] ) ) ) , ( constant1 ? constant1 : ( constant1 = ( * ef3 ) ( lf2 ( make_list ( ( * ef4 ) ( ( * ef5 ) ( lf3 ( ( ATerm ) ATmakeList ( 8 , char_table [ 101 ] , char_table [ 120 ] , char_table [ 116 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 110 ] , char_table [ 97 ] , char_table [ 108 ] ) ) ) ) ) ) ) ) ) ) ;
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
}
}
}
}
}
else {
return ( * ef2 ) ( arg0 , ( constant1 ? constant1 : ( constant1 = ( * ef3 ) ( lf2 ( make_list ( ( * ef4 ) ( ( * ef5 ) ( lf3 ( ( ATerm ) ATmakeList ( 8 , char_table [ 101 ] , char_table [ 120 ] , char_table [ 116 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 110 ] , char_table [ 97 ] , char_table [ 108 ] ) ) ) ) ) ) ) ) ) ) ;
}
if ( is_single_element ( atmp100 ) ) {
tmp [ 0 ] = list_head ( atmp100 ) ;
return ( * ef6 ) ( arg0 , ( constant2 ? constant2 : ( constant2 = lf4 ( make_list ( ( * ef7 ) ( ) ) ) ) ) , ( constant1 ? constant1 : ( constant1 = ( * ef3 ) ( lf2 ( make_list ( ( * ef4 ) ( ( * ef5 ) ( lf3 ( ( ATerm ) ATmakeList ( 8 , char_table [ 101 ] , char_table [ 120 ] , char_table [ 116 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 110 ] , char_table [ 97 ] , char_table [ 108 ] ) ) ) ) ) ) ) ) ) ) ;
}
}
}
}
}
return make_nf2 ( lf_AUX_MuASF_Signs9_1sym , arg0 , arg1 ) ;
}
}
ATerm lf3 ( ATerm arg0 ) {
PROF ( prof_lf3 ) ;
return make_nf1 ( lf3sym , arg0 ) ;
}
ATerm lf2 ( ATerm arg0 ) {
PROF ( prof_lf2 ) ;
return make_nf1 ( lf2sym , arg0 ) ;
}
ATerm lf4 ( ATerm arg0 ) {
PROF ( prof_lf4 ) ;
return make_nf1 ( lf4sym , arg0 ) ;
}

