#include  "support.h"
static Symbol lf_AUX_Sdf2_Parse_Table1_1sym ;
static ATerm lf_AUX_Sdf2_Parse_Table1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_Sdf2_Parse_Table1_2sym ;
static ATerm lf_AUX_Sdf2_Parse_Table1_2 ( ATerm arg1 ) ;
void register_AUX_Sdf2_Parse_Table1 ( ) {
lf_AUX_Sdf2_Parse_Table1_1sym = ATmakeSymbol ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[ql(\"table\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ParseTable\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Sdf2_Parse_Table1_1sym ) ;
lf_AUX_Sdf2_Parse_Table1_2sym = ATmakeSymbol ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[ql(\"grammar\"),w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"OutputGrammar\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Sdf2_Parse_Table1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[ql(\"table\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ParseTable\"),w(\"\"),no-attrs)" ) , lf_AUX_Sdf2_Parse_Table1_1 , lf_AUX_Sdf2_Parse_Table1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[ql(\"grammar\"),w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"OutputGrammar\"),w(\"\"),no-attrs)" ) , lf_AUX_Sdf2_Parse_Table1_2 , lf_AUX_Sdf2_Parse_Table1_2sym ) ;
}
void resolve_AUX_Sdf2_Parse_Table1 ( ) {
}
void init_AUX_Sdf2_Parse_Table1 ( ) {
}
ATerm lf_AUX_Sdf2_Parse_Table1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Sdf2_Parse_Table1_2sym , ATmakeAppl ( lf_AUX_Sdf2_Parse_Table1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Sdf2_Parse_Table1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_Sdf2_Parse_Table1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Sdf2_Parse_Table1_1sym , ATmakeAppl ( lf_AUX_Sdf2_Parse_Table1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Sdf2_Parse_Table1_1sym , arg0 ) ) ;
}

