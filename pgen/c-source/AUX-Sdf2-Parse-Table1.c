#include  "support.h"
static Symbol lf_AUX_Sdf2_Parse_Table1_1sym ;
static ATerm lf_AUX_Sdf2_Parse_Table1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_Sdf2_Parse_Table1_2sym ;
static ATerm lf_AUX_Sdf2_Parse_Table1_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_Sdf2_Parse_Table1_3sym ;
static ATerm lf_AUX_Sdf2_Parse_Table1_3 ( ATerm arg1 ) ;
static Symbol lf_AUX_Sdf2_Parse_Table1_4sym ;
static ATerm lf_AUX_Sdf2_Parse_Table1_4 ( ATerm arg1 ) ;
void register_AUX_Sdf2_Parse_Table1 ( ) {
lf_AUX_Sdf2_Parse_Table1_1sym = ATmakeSymbol ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[ql(\"table\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ParseTable\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Sdf2_Parse_Table1_1sym ) ;
lf_AUX_Sdf2_Parse_Table1_2sym = ATmakeSymbol ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[ql(\"grammar\"),w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"OutputGrammar\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Sdf2_Parse_Table1_2sym ) ;
lf_AUX_Sdf2_Parse_Table1_3sym = ATmakeSymbol ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[l(\"explode\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"SDF\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SDF\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Sdf2_Parse_Table1_3sym ) ;
lf_AUX_Sdf2_Parse_Table1_4sym = ATmakeSymbol ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[l(\"explode\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Definition\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Definition\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Sdf2_Parse_Table1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[ql(\"table\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ParseTable\"),w(\"\"),no-attrs)" ) , lf_AUX_Sdf2_Parse_Table1_1 , lf_AUX_Sdf2_Parse_Table1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[ql(\"grammar\"),w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"OutputGrammar\"),w(\"\"),no-attrs)" ) , lf_AUX_Sdf2_Parse_Table1_2 , lf_AUX_Sdf2_Parse_Table1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[l(\"explode\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"SDF\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SDF\"),w(\"\"),no-attrs)" ) , lf_AUX_Sdf2_Parse_Table1_3 , lf_AUX_Sdf2_Parse_Table1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[l(\"explode\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Definition\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Definition\"),w(\"\"),no-attrs)" ) , lf_AUX_Sdf2_Parse_Table1_4 , lf_AUX_Sdf2_Parse_Table1_4sym ) ;
}
void resolve_AUX_Sdf2_Parse_Table1 ( ) {
}
void init_AUX_Sdf2_Parse_Table1 ( ) {
}
ATerm lf_AUX_Sdf2_Parse_Table1_4 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Sdf2_Parse_Table1_4sym , ATmakeAppl ( lf_AUX_Sdf2_Parse_Table1_4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Sdf2_Parse_Table1_4sym , arg0 ) ) ;
}
ATerm lf_AUX_Sdf2_Parse_Table1_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Sdf2_Parse_Table1_3sym , ATmakeAppl ( lf_AUX_Sdf2_Parse_Table1_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Sdf2_Parse_Table1_3sym , arg0 ) ) ;
}
ATerm lf_AUX_Sdf2_Parse_Table1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Sdf2_Parse_Table1_2sym , ATmakeAppl ( lf_AUX_Sdf2_Parse_Table1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Sdf2_Parse_Table1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_Sdf2_Parse_Table1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Sdf2_Parse_Table1_1sym , ATmakeAppl ( lf_AUX_Sdf2_Parse_Table1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Sdf2_Parse_Table1_1sym , arg0 ) ) ;
}

