#include  "support.h"
static Symbol lf_AUX_Symbol_Tables2_1sym ;
static ATerm lf_AUX_Symbol_Tables2_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_Symbol_Tables2 ( ) {
lf_AUX_Symbol_Tables2_1sym = ATmakeSymbol ( "prod(id(\"Symbol-Tables\"),w(\"\"),[sort(\"Symbol-Table\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Symbol-Table\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Symbol_Tables2_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"STPair\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Symbol-Tables\"),w(\"\"),[sort(\"Symbol-Table\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Symbol-Table\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Symbol_Tables2_1 , lf_AUX_Symbol_Tables2_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"STPair\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Symbol_Tables2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Symbol-Tables\"),w(\"\"),[ql(\"[\"),w(\"\"),iter(sort(\"STPair\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbol-Tables\"),w(\"\"),[ql(\"[\"),w(\"\"),iter(sort(\"STPair\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Symbol-Tables\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Label\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"STPair\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbol-Tables\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Label\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"STPair\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[sort(\"LabelSet\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[sort(\"LabelSet\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_Symbol_Tables2 ( ) {
}
ATerm lf_AUX_Symbol_Tables2_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 7 ] ;
FUNC_ENTRY ( lf_AUX_Symbol_Tables2_1sym , ATmakeAppl ( lf_AUX_Symbol_Tables2_1sym , arg0 , arg1 ) ) ;
lbl_lf_AUX_Symbol_Tables2_1 : if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
tmp [ 0 ] = arg_0 ( atmp10 ) ;
{
ATerm atmp10010 ;
ATerm atmp1000 [ 2 ] ;
atmp1000 [ 0 ] = tmp [ 0 ] ;
atmp1000 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
atmp10010 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( not_empty_list ( atmp000 ) ) {
tmp [ 1 ] = list_head ( atmp000 ) ;
tmp [ 2 ] = list_tail ( atmp000 ) ;
if ( check_sym ( tmp [ 1 ] , ef2sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 1 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 1 ] ) ;
if ( check_sym ( atmp10010 , ef2sym ) ) {
tmp [ 5 ] = arg_0 ( atmp10010 ) ;
tmp [ 6 ] = arg_1 ( atmp10010 ) ;
if ( term_equal ( tmp [ 3 ] , tmp [ 5 ] ) ) {
arg0 = ( * ef1 ) ( lf2 ( make_list ( tmp [ 2 ] ) ) ) ;
arg1 = ( * ef1 ) ( lf2 ( cons ( slice ( atmp1000 [ 0 ] , atmp1000 [ 1 ] ) , cons ( make_list ( ( * ef2 ) ( tmp [ 3 ] , ( * ef3 ) ( tmp [ 4 ] , tmp [ 6 ] ) ) ) , tmp [ 0 ] ) ) ) ) ;
goto lbl_lf_AUX_Symbol_Tables2_1 ;
}
}
}
}
atmp1000 [ 1 ] = list_tail ( atmp1000 [ 1 ] ) ;
tmp [ 0 ] = atmp1000 [ 1 ] ;
}
}
}
}
}
if ( ! not_empty_list ( atmp000 ) ) {
FUNC_EXIT ( arg1 ) ;
}
}
}
}
}
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( not_empty_list ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
tmp [ 1 ] = list_tail ( atmp000 ) ;
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
arg0 = ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ;
arg1 = ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef2 ) ( tmp [ 2 ] , tmp [ 3 ] ) ) , make_list ( atmp100 ) ) ) ) ;
goto lbl_lf_AUX_Symbol_Tables2_1 ;
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
FUNC_EXIT ( make_nf2 ( lf_AUX_Symbol_Tables2_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

