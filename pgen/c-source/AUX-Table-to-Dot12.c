#include  "asc-support.h"
static Symbol lf_AUX_Table_to_Dot12_1sym ;
static ATerm lf_AUX_Table_to_Dot12_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef18sym ;
static funcptr ef18 ;
void register_AUX_Table_to_Dot12 ( ) {
lf_AUX_Table_to_Dot12_1sym = ATmakeSymbol ( "prod(id(\"Table-to-Dot\"),w(\"\"),[l(\"stmts\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Id\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Goto-Entries\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Stmt-List\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Table_to_Dot12_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Stmt\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Goto-Entry\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Attr\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"Symbol\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
register_prod ( ATparse ( "prod(id(\"Table-to-Dot\"),w(\"\"),[l(\"stmts\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Id\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Goto-Entries\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Stmt-List\"),w(\"\"),no-attrs)" ) , lf_AUX_Table_to_Dot12_1 , lf_AUX_Table_to_Dot12_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Goto-Entry\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Stmt\"),ql(\";\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Attr\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Symbol\"))" ) , lf5 , lf5sym ) ;
}
void resolve_AUX_Table_to_Dot12 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Goto-Entry\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Entries\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Goto-Entry\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Entries\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Stmt\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Stmt-List\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Stmt\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Stmt-List\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"goto\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"CharClass\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Entry\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"goto\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"CharClass\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Entry\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Table-to-Dot\"),w(\"\"),[sort(\"Stmt-List\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Stmt-List\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Stmt-List\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Table-to-Dot\"),w(\"\"),[sort(\"Stmt-List\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Stmt-List\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Stmt-List\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[sort(\"Edge-Stmt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Stmt\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[sort(\"Edge-Stmt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Stmt\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[sort(\"Node-Id\"),w(\"\"),sort(\"EdgeRHS\"),w(\"\"),sort(\"Opt-Attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Edge-Stmt\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[sort(\"Node-Id\"),w(\"\"),sort(\"EdgeRHS\"),w(\"\"),sort(\"Opt-Attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Edge-Stmt\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[sort(\"Id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Node-Id\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[sort(\"Id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Node-Id\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[sort(\"EdgeOp\"),w(\"\"),sort(\"Node-Id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EdgeRHS\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[sort(\"EdgeOp\"),w(\"\"),sort(\"Node-Id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EdgeRHS\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[ql(\"->\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EdgeOp\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[ql(\"->\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EdgeOp\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Table-to-Dot\"),w(\"\"),[l(\"id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Id\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Table-to-Dot\"),w(\"\"),[l(\"id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Id\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Attr-List\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Opt-Attrs\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Attr-List\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Opt-Attrs\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[iter(sort(\"Attr\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attr-List\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[iter(sort(\"Attr\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attr-List\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[sort(\"Id\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attr\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"Dot-Graphs\"),w(\"\"),[sort(\"Id\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attr\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"Table-to-Dot\"),w(\"\"),[ql(\"label\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Id\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"Table-to-Dot\"),w(\"\"),[ql(\"label\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Id\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"Table-to-Dot\"),w(\"\"),[l(\"label\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbols\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Id\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"Table-to-Dot\"),w(\"\"),[l(\"label\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbols\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Id\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"CC-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"CC-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
void init_AUX_Table_to_Dot12 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
}
ATerm lf_AUX_Table_to_Dot12_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 6 ] ;
FUNC_ENTRY ( lf_AUX_Table_to_Dot12_1sym , ATmakeAppl ( lf_AUX_Table_to_Dot12_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( not_empty_list ( atmp100 ) ) {
tmp [ 0 ] = list_head ( atmp100 ) ;
tmp [ 1 ] = list_tail ( atmp100 ) ;
if ( check_sym ( tmp [ 0 ] , ef3sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef4sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = ( * ef6 ) ( ( * ef7 ) ( ( * ef8 ) ( arg0 ) , ( * ef9 ) ( ( constant0 ? constant0 : ( constant0 = ( * ef10 ) ( ) ) ) , ( * ef8 ) ( ( * ef11 ) ( ( * ef4 ) ( tmp [ 4 ] ) ) ) ) , ( * ef12 ) ( ( * ef13 ) ( lf4 ( make_list ( ( * ef14 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef15 ) ( ) ) ) , ( * ef16 ) ( ( * ef17 ) ( lf5 ( make_list ( ( * ef18 ) ( tmp [ 2 ] ) ) ) ) ) ) ) ) ) ) ) ) ;
FUNC_EXIT ( ( * ef5 ) ( ( * ef2 ) ( lf3 ( make_list ( tmp [ 5 ] ) ) ) , lf_AUX_Table_to_Dot12_1 ( arg0 , ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ) ) ;
}
}
}
else {
FUNC_EXIT_CONST ( constant2 , ( * ef2 ) ( lf3 ( make_list ( null ( ) ) ) ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Table_to_Dot12_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf5 ( ATerm arg0 ) {
CONS_ENTRY ( lf5sym , ATmakeAppl ( lf5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf5sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

