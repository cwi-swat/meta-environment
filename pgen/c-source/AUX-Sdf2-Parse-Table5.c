#include  "support.h"
static Symbol lf_AUX_Sdf2_Parse_Table5_1sym ;
static ATerm lf_AUX_Sdf2_Parse_Table5_1 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
void register_AUX_Sdf2_Parse_Table5 ( ) {
lf_AUX_Sdf2_Parse_Table5_1sym = ATmakeSymbol ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[l(\"normalize\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"SDF\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Sdf2_Parse_Table5_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[l(\"normalize\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"SDF\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) , lf_AUX_Sdf2_Parse_Table5_1 , lf_AUX_Sdf2_Parse_Table5_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Sdf2_Parse_Table5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"definition\"),w(\"\"),sort(\"Definition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SDF\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"definition\"),w(\"\"),sort(\"Definition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SDF\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Sdf2-Normalization\"),w(\"\"),[l(\"normalize\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"SDF\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Sdf2-Normalization\"),w(\"\"),[l(\"normalize\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"SDF\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"moduleid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModuleId\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"moduleid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModuleId\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"<START>\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"<START>\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Sdf2_Parse_Table5 ( ) {
}
ATerm lf_AUX_Sdf2_Parse_Table5_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_Sdf2_Parse_Table5_1sym , ATmakeAppl ( lf_AUX_Sdf2_Parse_Table5_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
FUNC_EXIT ( ( * ef2 ) ( arg0 , ( * ef3 ) ( ( * ef4 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 77 ] , char_table [ 97 ] , char_table [ 105 ] , char_table [ 110 ] ) ) ) ) , ( * ef5 ) ( ) ) ) ;
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Sdf2_Parse_Table5_1sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

