#include  "asc-support.h"
static Symbol lf_AUX_Grammar_Tree_Constructors1_1sym ;
static ATerm lf_AUX_Grammar_Tree_Constructors1_1 ( ) ;
static Symbol lf_AUX_Grammar_Tree_Constructors1_2sym ;
static ATerm lf_AUX_Grammar_Tree_Constructors1_2 ( ) ;
void register_AUX_Grammar_Tree_Constructors1 ( ) {
lf_AUX_Grammar_Tree_Constructors1_1sym = ATmakeSymbol ( "prod(id(\"Grammar-Tree-Constructors\"),w(\"\"),[ql(\"empty-grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Grammar_Tree_Constructors1_1sym ) ;
lf_AUX_Grammar_Tree_Constructors1_2sym = ATmakeSymbol ( "prod(id(\"Grammar-Tree-Constructors\"),w(\"\"),[ql(\"conc-grammars\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Grammar_Tree_Constructors1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Grammar-Tree-Constructors\"),w(\"\"),[ql(\"empty-grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_Grammar_Tree_Constructors1_1 , lf_AUX_Grammar_Tree_Constructors1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Grammar-Tree-Constructors\"),w(\"\"),[ql(\"conc-grammars\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_Grammar_Tree_Constructors1_2 , lf_AUX_Grammar_Tree_Constructors1_2sym ) ;
}
void resolve_AUX_Grammar_Tree_Constructors1 ( ) {
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_Grammar_Tree_Constructors1 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_Grammar_Tree_Constructors1_2 ( ) {
CONS_ENTRY ( lf_AUX_Grammar_Tree_Constructors1_2sym , ATmakeAppl0 ( lf_AUX_Grammar_Tree_Constructors1_2sym ) ) ;
CONS_EXIT_CONST ( constant0 , make_nf0 ( lf_AUX_Grammar_Tree_Constructors1_2sym ) ) ;
}
ATerm lf_AUX_Grammar_Tree_Constructors1_1 ( ) {
CONS_ENTRY ( lf_AUX_Grammar_Tree_Constructors1_1sym , ATmakeAppl0 ( lf_AUX_Grammar_Tree_Constructors1_1sym ) ) ;
CONS_EXIT_CONST ( constant1 , make_nf0 ( lf_AUX_Grammar_Tree_Constructors1_1sym ) ) ;
}

