#include  "asc-support.h"
static Symbol lf_AUX_Labels4_1sym ;
static ATerm lf_AUX_Labels4_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
void register_AUX_Labels4 ( ) {
lf_AUX_Labels4_1sym = ATmakeSymbol ( "prod(id(\"Labels\"),w(\"\"),[sort(\"LabelSet\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Labels4_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Labels\"),w(\"\"),[sort(\"LabelSet\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Labels4_1 , lf_AUX_Labels4_1sym ) ;
}
void resolve_AUX_Labels4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[sort(\"LabelSet\"),w(\"\"),ql(\"nm-+\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[sort(\"LabelSet\"),w(\"\"),ql(\"nm-+\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
}
static ATermTable table_lf_AUX_Labels4_1 ;
void init_AUX_Labels4 ( ) {
create_table ( table_lf_AUX_Labels4_1 , 0 ) ;
}
ATerm lf_AUX_Labels4_1 ( ATerm arg0 , ATerm arg1 ) {
ATerm interm = make_tuple2 ( arg0 , arg1 ) ;
ATermTable table = get_table ( table_lf_AUX_Labels4_1 ) ;
ATerm result = get_result ( table , interm ) ;
if ( result ) return result ;
else {
result = ( * ef1 ) ( arg0 , arg1 ) ;
put_result ( table , interm , result ) ;
return result ;
}
}

