#include "support.h"
static asymbol * lf_AUX_Normalize_Conds1_1sym;
static aterm * lf_AUX_Normalize_Conds1_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
void register_AUX_Normalize_Conds1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Normalize_Conds1_1sym= TmkSymbol( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-conditions\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-conditions\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)") , lf_AUX_Normalize_Conds1_1 , lf_AUX_Normalize_Conds1_1sym);
}
void resolve_AUX_Normalize_Conds1( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"module\"),w(\"\"),sort(\"ModId\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),sort(\"RulesOpt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"module\"),w(\"\"),sort(\"ModId\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),sort(\"RulesOpt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-rulesopt\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-rulesopt\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Normalize_Conds1_1( aterm * arg0) {
{
aterm * tmp[1];
PROF( prof_lf_AUX_Normalize_Conds1_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
{
aterm * atmp02= arg_2( arg0);
t_protect( atmp02);
tmp[ 0]= ( * ef2)( atmp02);
t_protect( atmp00);
t_protect( atmp01);
t_unprotect( arg0);
return ( * ef1)( atmp00 , atmp01 , tmp[ 0]);
}
}
}
}
return make_nf1( lf_AUX_Normalize_Conds1_1sym , arg0);
}
}

