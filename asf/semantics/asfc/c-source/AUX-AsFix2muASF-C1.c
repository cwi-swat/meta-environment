#include  "support.h"
static Symbol lf_AUX_AsFix2muASF_C1_1sym ;
static ATerm lf_AUX_AsFix2muASF_C1_1 ( ATerm arg1 , ATerm arg2 ) ;
void register_AUX_AsFix2muASF_C1 ( ) {
lf_AUX_AsFix2muASF_C1_1sym = ATmakeSymbol ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"MN-struct\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix2muASF_C1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"MN-struct\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFix2muASF_C1_1 , lf_AUX_AsFix2muASF_C1_1sym ) ;
}
void resolve_AUX_AsFix2muASF_C1 ( ) {
}
void init_AUX_AsFix2muASF_C1 ( ) {
}
ATerm lf_AUX_AsFix2muASF_C1_1 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_AsFix2muASF_C1_1sym , ATmakeAppl ( lf_AUX_AsFix2muASF_C1_1sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_AsFix2muASF_C1_1sym , arg0 , arg1 ) ) ;
}

