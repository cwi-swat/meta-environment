#include  "support.h"
static Symbol lf_AUX_Sdf2_Parse_Table2_1sym ;
static ATerm lf_AUX_Sdf2_Parse_Table2_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
void register_AUX_Sdf2_Parse_Table2 ( ) {
lf_AUX_Sdf2_Parse_Table2_1sym = ATmakeSymbol ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[l(\"parse-table\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),l(\",\"),w(\"\"),sort(\"SDF\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Sdf2_Parse_Table2_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[l(\"parse-table\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),l(\",\"),w(\"\"),sort(\"SDF\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) , lf_AUX_Sdf2_Parse_Table2_1 , lf_AUX_Sdf2_Parse_Table2_1sym ) ;
}
void resolve_AUX_Sdf2_Parse_Table2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"definition\"),w(\"\"),sort(\"Definition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SDF\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"definition\"),w(\"\"),sort(\"Definition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SDF\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Table-To-ATerm\"),w(\"\"),[l(\"aterm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Table-To-ATerm\"),w(\"\"),[l(\"aterm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Sdf2-Normalization\"),w(\"\"),[l(\"normalize\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"SDF\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Sdf2-Normalization\"),w(\"\"),[l(\"normalize\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"SDF\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"<START>\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"<START>\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"table\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"table\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Sdf2_Parse_Table2 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Sdf2_Parse_Table2_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Sdf2_Parse_Table2_1sym , ATmakeAppl ( lf_AUX_Sdf2_Parse_Table2_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
tmp [ 0 ] = ( * ef3 ) ( arg1 , arg0 , ( constant0 ? constant0 : ( constant0 = ( * ef4 ) ( ) ) ) ) ;
tmp [ 1 ] = ( * ef5 ) ( tmp [ 0 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( tmp [ 1 ] ) ) ;
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Sdf2_Parse_Table2_1sym , arg0 , arg1 ) ) ;
}
}

