#include  "support.h"
static Symbol lf_AUX_AsFix2Sign_C1_1sym ;
static ATerm lf_AUX_AsFix2Sign_C1_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_AsFix2Sign_C1_2sym ;
static ATerm lf_AUX_AsFix2Sign_C1_2 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
void register_AUX_AsFix2Sign_C1 ( ) {
lf_AUX_AsFix2Sign_C1_1sym = ATmakeSymbol ( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix2Sign_C1_1sym ) ;
lf_AUX_AsFix2Sign_C1_2sym = ATmakeSymbol ( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"SortList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncSortStruct\"),w(\"\"),no-attrs)" , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix2Sign_C1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFix2Sign_C1_1 , lf_AUX_AsFix2Sign_C1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"SortList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncSortStruct\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFix2Sign_C1_2 , lf_AUX_AsFix2Sign_C1_2sym ) ;
}
void resolve_AUX_AsFix2Sign_C1 ( ) {
}
void init_AUX_AsFix2Sign_C1 ( ) {
}
ATerm lf_AUX_AsFix2Sign_C1_2 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
PROF ( prof_lf_AUX_AsFix2Sign_C1_2 ) ;
return make_nf3 ( lf_AUX_AsFix2Sign_C1_2sym , arg0 , arg1 , arg2 ) ;
}
ATerm lf_AUX_AsFix2Sign_C1_1 ( ATerm arg0 , ATerm arg1 ) {
PROF ( prof_lf_AUX_AsFix2Sign_C1_1 ) ;
return make_nf2 ( lf_AUX_AsFix2Sign_C1_1sym , arg0 , arg1 ) ;
}

