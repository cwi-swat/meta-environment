#include  "asc-support.h"
static Symbol lf_AUX_Action_PCC2_1sym ;
static ATerm lf_AUX_Action_PCC2_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
void register_AUX_Action_PCC2 ( ) {
lf_AUX_Action_PCC2_1sym = ATmakeSymbol ( "prod(id(\"Action-PCC\"),w(\"\"),[l(\"union\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Action_PCC2_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Action-PCC\"),w(\"\"),[l(\"union\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Action_PCC2_1 , lf_AUX_Action_PCC2_1sym ) ;
}
void resolve_AUX_Action_PCC2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Action-PCC\"),w(\"\"),[l(\"nm-union\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Action-PCC\"),w(\"\"),[l(\"nm-union\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) ) ;
}
static ATermTable table_lf_AUX_Action_PCC2_1 ;
void init_AUX_Action_PCC2 ( ) {
create_table ( table_lf_AUX_Action_PCC2_1 , 0 ) ;
}
ATerm lf_AUX_Action_PCC2_1 ( ATerm arg0 ) {
ATerm interm = make_tuple1 ( arg0 ) ;
ATermTable table = get_table ( table_lf_AUX_Action_PCC2_1 ) ;
ATerm result = get_result ( table , interm ) ;
if ( result ) return result ;
else {
result = ( * ef1 ) ( arg0 ) ;
put_result ( table , interm , result ) ;
return result ;
}
}

