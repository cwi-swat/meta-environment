#include  "support.h"
static Symbol lf_AUX_Priority_Sdf_Projection3_1sym ;
static ATerm lf_AUX_Priority_Sdf_Projection3_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
void register_AUX_Priority_Sdf_Projection3 ( ) {
lf_AUX_Priority_Sdf_Projection3_1sym = ATmakeSymbol ( "prod(id(\"Priority-Sdf-Projection\"),w(\"\"),[ql(\"Pr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Projection3_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Sdf-Projection\"),w(\"\"),[ql(\"Pr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Priority_Sdf_Projection3_1 , lf_AUX_Priority_Sdf_Projection3_1sym ) ;
}
void resolve_AUX_Priority_Sdf_Projection3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Projection\"),w(\"\"),[ql(\"nm-Pr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Projection\"),w(\"\"),[ql(\"nm-Pr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
}
static ATermTable table_lf_AUX_Priority_Sdf_Projection3_1 ;
void init_AUX_Priority_Sdf_Projection3 ( ) {
create_table ( table_lf_AUX_Priority_Sdf_Projection3_1 , 0 ) ;
}
ATerm lf_AUX_Priority_Sdf_Projection3_1 ( ATerm arg0 ) {
ATerm interm = make_tuple1 ( arg0 ) ;
ATermTable table = get_table ( table_lf_AUX_Priority_Sdf_Projection3_1 ) ;
ATerm result = get_result ( table , interm ) ;
if ( result ) return result ;
else {
result = ( * ef1 ) ( arg0 ) ;
put_result ( table , interm , result ) ;
return result ;
}
}

