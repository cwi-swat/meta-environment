#include  "asc-support.h"
static Symbol lf_AUX_Sdf2_Parse_Table4_1sym ;
static ATerm lf_AUX_Sdf2_Parse_Table4_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_Sdf2_Parse_Table4 ( ) {
lf_AUX_Sdf2_Parse_Table4_1sym = ATmakeSymbol ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[l(\"parse-table\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Sdf2_Parse_Table4_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[l(\"parse-table\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) , lf_AUX_Sdf2_Parse_Table4_1 , lf_AUX_Sdf2_Parse_Table4_1sym ) ;
}
void resolve_AUX_Sdf2_Parse_Table4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Table-To-ATerm\"),w(\"\"),[l(\"aterm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Table-To-ATerm\"),w(\"\"),[l(\"aterm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"table\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"table\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Sdf2_Parse_Table4 ( ) {
}
ATerm lf_AUX_Sdf2_Parse_Table4_1 ( ATerm arg0 ) {
{
ATerm tmp [ 1 ] ;
FUNC_ENTRY ( lf_AUX_Sdf2_Parse_Table4_1sym , ATmakeAppl ( lf_AUX_Sdf2_Parse_Table4_1sym , arg0 ) ) ;
tmp [ 0 ] = ( * ef2 ) ( arg0 ) ;
FUNC_EXIT ( ( * ef1 ) ( tmp [ 0 ] ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_Sdf2_Parse_Table4_1sym , arg0 ) ) ;
}
}

