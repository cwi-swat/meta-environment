#include  "asc-support.h"
static Symbol lf_AUX_MuASF_Conds2C5_3sym ;
static ATerm lf_AUX_MuASF_Conds2C5_3 ( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4 , ATerm arg5 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol lf6sym ;
static ATerm lf6 ( ATerm arg1 ) ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol ef19sym ;
static funcptr ef19 ;
static Symbol lf8sym ;
static ATerm lf8 ( ATerm arg1 ) ;
static Symbol ef20sym ;
static funcptr ef20 ;
static Symbol ef21sym ;
static funcptr ef21 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef22sym ;
static funcptr ef22 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol lf7sym ;
static ATerm lf7 ( ATerm arg1 ) ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef24sym ;
static funcptr ef24 ;
static Symbol lf_AUX_MuASF_Conds2C5_1sym ;
static ATerm lf_AUX_MuASF_Conds2C5_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_MuASF_Conds2C5_2sym ;
static ATerm lf_AUX_MuASF_Conds2C5_2 ( ATerm arg1 ) ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef23sym ;
static funcptr ef23 ;
void register_AUX_MuASF_Conds2C5 ( ) {
lf_AUX_MuASF_Conds2C5_3sym = ATmakeSymbol ( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"assign-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"
 , 5 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Conds2C5_3sym ) ;
lf6sym = ATmakeSymbol ( "listtype(sort(\"TE-pair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf6sym ) ;
lf8sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf8sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"FV-Path\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf7sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf7sym ) ;
lf_AUX_MuASF_Conds2C5_1sym = ATmakeSymbol ( "listtype(sort(\"C-Rule\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Conds2C5_1sym ) ;
lf_AUX_MuASF_Conds2C5_2sym = ATmakeSymbol ( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Conds2C5_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"C-Rule\"),ql(\";\"))" ) , lf_AUX_MuASF_Conds2C5_1 , lf_AUX_MuASF_Conds2C5_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"NamePair\"),ql(\",\"))" ) , lf_AUX_MuASF_Conds2C5_2 , lf_AUX_MuASF_Conds2C5_2sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"assign-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Conds2C5_3 , lf_AUX_MuASF_Conds2C5_3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FV-Path\"),ql(\",\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf5 , lf5sym ) ;
register_prod ( ATparse ( "listtype(sort(\"TE-pair\"),ql(\",\"))" ) , lf6 , lf6sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf7 , lf7sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf8 , lf8sym ) ;
}
void resolve_AUX_MuASF_Conds2C5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"conds2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"conds2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-same-rhs-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-same-rhs-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"remove-first-cond-and-add-env\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"remove-first-cond-and-add-env\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-expression\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-expression\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"cterms2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DCAS-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"cterms2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DCAS-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef20 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef20sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef21 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DCAS-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef21sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DCAS-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef22 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef22sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef23 = lookup_func ( ATreadFromString ( "prod(id(\"ANumerals\"),w(\"\"),[l(\"gtr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef23sym = lookup_sym ( ATreadFromString ( "prod(id(\"ANumerals\"),w(\"\"),[l(\"gtr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef24 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"listconds2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef24sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"listconds2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
void init_AUX_MuASF_Conds2C5 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
}
ATerm lf_AUX_MuASF_Conds2C5_3 ( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4 ) {
{
ATerm tmp [ 39 ] ;
FUNC_ENTRY ( lf_AUX_MuASF_Conds2C5_3sym , ATmakeAppl ( lf_AUX_MuASF_Conds2C5_3sym , arg0 , arg1 , arg2 , arg3 , arg4 ) ) ;
{
ATerm ltmp [ 5 ] ;
lbl_lf_AUX_MuASF_Conds2C5_3 : ltmp [ 0 ] = arg0 ;
ltmp [ 1 ] = arg1 ;
ltmp [ 2 ] = arg2 ;
ltmp [ 3 ] = arg3 ;
ltmp [ 4 ] = arg4 ;
if ( check_sym ( ltmp [ 0 ] , lf_AUX_MuASF_Conds2C5_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( ltmp [ 1 ] , lf_AUX_MuASF_Conds2C5_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( ltmp [ 2 ] , lf_AUX_MuASF_Conds2C5_2sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( not_empty_list ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
{
tmp [ 1 ] = list_tail ( atmp00 ) ;
{
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ;
tmp [ 5 ] = arg_3 ( tmp [ 0 ] ) ;
tmp [ 6 ] = arg_4 ( tmp [ 0 ] ) ;
tmp [ 7 ] = arg_5 ( tmp [ 0 ] ) ;
{
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 2 ] ) ;
{
if ( check_sym ( tmp [ 3 ] , lf5sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 3 ] ) ;
{
if ( not_empty_list ( tmp [ 9 ] ) ) {
tmp [ 10 ] = list_head ( tmp [ 9 ] ) ;
{
tmp [ 11 ] = list_tail ( tmp [ 9 ] ) ;
{
if ( check_sym ( tmp [ 10 ] , ef3sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 10 ] ) ;
tmp [ 13 ] = arg_1 ( tmp [ 10 ] ) ;
{
if ( check_sym ( tmp [ 13 ] , ef12sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 13 ] ) ;
tmp [ 15 ] = arg_1 ( tmp [ 13 ] ) ;
{
if ( check_sym ( tmp [ 15 ] , lf7sym ) ) {
tmp [ 16 ] = arg_0 ( tmp [ 15 ] ) ;
{
if ( not_empty_list ( tmp [ 16 ] ) ) {
tmp [ 17 ] = ( * ef15 ) ( tmp [ 14 ] ) ;
if ( term_equal ( tmp [ 17 ] , ( constant0 ? constant0 : ( constant0 = ( * ef16 ) ( ) ) ) ) ) {
tmp [ 18 ] = ( * ef17 ) ( tmp [ 14 ] , ltmp [ 4 ] , lf_AUX_MuASF_Conds2C5_2 ( make_list ( atmp20 ) ) ) ;
tmp [ 19 ] = ( * ef18 ) ( lf7 ( make_list ( tmp [ 16 ] ) ) , ltmp [ 4 ] , ltmp [ 3 ] , ( constant1 ? constant1 : ( constant1 = ( * ef19 ) ( ( * ef20 ) ( lf8 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 19 ] , ef21sym ) ) {
tmp [ 20 ] = arg_0 ( tmp [ 19 ] ) ;
tmp [ 21 ] = arg_1 ( tmp [ 19 ] ) ;
tmp [ 22 ] = arg_2 ( tmp [ 19 ] ) ;
tmp [ 23 ] = ( * ef6 ) ( ( * ef2 ) ( lf4 ( make_list ( tmp [ 8 ] ) ) , lf5 ( cons ( make_list ( ( * ef3 ) ( tmp [ 12 ] , ( * ef12 ) ( tmp [ 14 ] , lf7 ( make_list ( tmp [ 16 ] ) ) ) ) ) , make_list ( tmp [ 11 ] ) ) ) , tmp [ 4 ] , tmp [ 5 ] , tmp [ 6 ] , tmp [ 7 ] ) , lf_AUX_MuASF_Conds2C5_1 ( make_list ( tmp [ 1 ] ) ) ) ;
if ( check_sym ( tmp [ 23 ] , ef7sym ) ) {
tmp [ 24 ] = arg_0 ( tmp [ 23 ] ) ;
tmp [ 25 ] = arg_1 ( tmp [ 23 ] ) ;
if ( check_sym ( tmp [ 24 ] , lf_AUX_MuASF_Conds2C5_1sym ) ) {
tmp [ 26 ] = arg_0 ( tmp [ 24 ] ) ;
if ( check_sym ( tmp [ 25 ] , lf_AUX_MuASF_Conds2C5_1sym ) ) {
tmp [ 27 ] = arg_0 ( tmp [ 25 ] ) ;
tmp [ 28 ] = ( * ef8 ) ( lf_AUX_MuASF_Conds2C5_1 ( make_list ( tmp [ 26 ] ) ) , tmp [ 21 ] ) ;
if ( check_sym ( tmp [ 28 ] , ef11sym ) ) {
tmp [ 29 ] = arg_0 ( tmp [ 28 ] ) ;
if ( check_sym ( tmp [ 29 ] , lf_AUX_MuASF_Conds2C5_1sym ) ) {
tmp [ 30 ] = arg_0 ( tmp [ 29 ] ) ;
tmp [ 31 ] = ( * ef1 ) ( lf_AUX_MuASF_Conds2C5_1 ( make_list ( tmp [ 30 ] ) ) , lf_AUX_MuASF_Conds2C5_2 ( make_list ( atmp20 ) ) , tmp [ 22 ] ) ;
if ( check_sym ( tmp [ 31 ] , ef13sym ) ) {
tmp [ 32 ] = arg_0 ( tmp [ 31 ] ) ;
tmp [ 33 ] = arg_1 ( tmp [ 31 ] ) ;
tmp [ 34 ] = ( * ef22 ) ( tmp [ 18 ] , ( * ef14 ) ( tmp [ 20 ] , tmp [ 32 ] ) ) ;
tmp [ 35 ] = lf_AUX_MuASF_Conds2C5_3 ( lf_AUX_MuASF_Conds2C5_1 ( make_list ( tmp [ 27 ] ) ) , lf_AUX_MuASF_Conds2C5_1 ( make_list ( atmp10 ) ) , lf_AUX_MuASF_Conds2C5_2 ( make_list ( atmp20 ) ) , ltmp [ 3 ] , ltmp [ 4 ] ) ;
if ( check_sym ( tmp [ 35 ] , ef13sym ) ) {
tmp [ 36 ] = arg_0 ( tmp [ 35 ] ) ;
tmp [ 37 ] = arg_1 ( tmp [ 35 ] ) ;
tmp [ 38 ] = ( * ef23 ) ( tmp [ 33 ] , tmp [ 37 ] ) ;
FUNC_EXIT ( ( * ef13 ) ( ( * ef14 ) ( tmp [ 34 ] , tmp [ 36 ] ) , tmp [ 38 ] ) ) ;
}
}
}
}
}
}
}
}
}
if ( term_equal ( tmp [ 17 ] , ( constant2 ? constant2 : ( constant2 = ( * ef5 ) ( ) ) ) ) ) {
tmp [ 18 ] = ( * ef6 ) ( ( * ef2 ) ( lf4 ( make_list ( tmp [ 8 ] ) ) , lf5 ( cons ( make_list ( ( * ef3 ) ( tmp [ 12 ] , ( * ef12 ) ( tmp [ 14 ] , lf7 ( make_list ( tmp [ 16 ] ) ) ) ) ) , make_list ( tmp [ 11 ] ) ) ) , tmp [ 4 ] , tmp [ 5 ] , tmp [ 6 ] , tmp [ 7 ] ) , lf_AUX_MuASF_Conds2C5_1 ( make_list ( tmp [ 1 ] ) ) ) ;
if ( check_sym ( tmp [ 18 ] , ef7sym ) ) {
tmp [ 19 ] = arg_0 ( tmp [ 18 ] ) ;
tmp [ 20 ] = arg_1 ( tmp [ 18 ] ) ;
if ( check_sym ( tmp [ 19 ] , lf_AUX_MuASF_Conds2C5_1sym ) ) {
tmp [ 21 ] = arg_0 ( tmp [ 19 ] ) ;
if ( check_sym ( tmp [ 20 ] , lf_AUX_MuASF_Conds2C5_1sym ) ) {
tmp [ 22 ] = arg_0 ( tmp [ 20 ] ) ;
tmp [ 23 ] = ( * ef24 ) ( lf_AUX_MuASF_Conds2C5_1 ( make_list ( tmp [ 21 ] ) ) , lf_AUX_MuASF_Conds2C5_2 ( make_list ( atmp20 ) ) , ltmp [ 3 ] , ltmp [ 4 ] ) ;
if ( check_sym ( tmp [ 23 ] , ef13sym ) ) {
tmp [ 24 ] = arg_0 ( tmp [ 23 ] ) ;
tmp [ 25 ] = arg_1 ( tmp [ 23 ] ) ;
tmp [ 26 ] = lf_AUX_MuASF_Conds2C5_3 ( lf_AUX_MuASF_Conds2C5_1 ( make_list ( tmp [ 22 ] ) ) , lf_AUX_MuASF_Conds2C5_1 ( make_list ( atmp10 ) ) , lf_AUX_MuASF_Conds2C5_2 ( make_list ( atmp20 ) ) , ltmp [ 3 ] , ltmp [ 4 ] ) ;
if ( check_sym ( tmp [ 26 ] , ef13sym ) ) {
tmp [ 27 ] = arg_0 ( tmp [ 26 ] ) ;
tmp [ 28 ] = arg_1 ( tmp [ 26 ] ) ;
tmp [ 29 ] = ( * ef23 ) ( tmp [ 25 ] , tmp [ 28 ] ) ;
FUNC_EXIT ( ( * ef13 ) ( ( * ef14 ) ( tmp [ 24 ] , tmp [ 27 ] ) , tmp [ 29 ] ) ) ;
}
}
}
}
}
}
}
}
}
}
}
if ( term_equal ( ( * ef4 ) ( tmp [ 13 ] ) , ( constant2 ? constant2 : ( constant2 = ( * ef5 ) ( ) ) ) ) ) {
tmp [ 14 ] = ( * ef6 ) ( ( * ef2 ) ( lf4 ( make_list ( tmp [ 8 ] ) ) , lf5 ( cons ( make_list ( ( * ef3 ) ( tmp [ 12 ] , tmp [ 13 ] ) ) , make_list ( tmp [ 11 ] ) ) ) , tmp [ 4 ] , tmp [ 5 ] , tmp [ 6 ] , tmp [ 7 ] ) , lf_AUX_MuASF_Conds2C5_1 ( make_list ( tmp [ 1 ] ) ) ) ;
if ( check_sym ( tmp [ 14 ] , ef7sym ) ) {
tmp [ 15 ] = arg_0 ( tmp [ 14 ] ) ;
tmp [ 16 ] = arg_1 ( tmp [ 14 ] ) ;
if ( check_sym ( tmp [ 15 ] , lf_AUX_MuASF_Conds2C5_1sym ) ) {
tmp [ 17 ] = arg_0 ( tmp [ 15 ] ) ;
if ( check_sym ( tmp [ 16 ] , lf_AUX_MuASF_Conds2C5_1sym ) ) {
tmp [ 18 ] = arg_0 ( tmp [ 16 ] ) ;
tmp [ 19 ] = ( * ef8 ) ( lf_AUX_MuASF_Conds2C5_1 ( make_list ( tmp [ 17 ] ) ) , ( * ef9 ) ( lf6 ( make_list ( ( * ef10 ) ( tmp [ 13 ] , ltmp [ 4 ] ) ) ) ) ) ;
if ( check_sym ( tmp [ 19 ] , ef11sym ) ) {
tmp [ 20 ] = arg_0 ( tmp [ 19 ] ) ;
if ( check_sym ( tmp [ 20 ] , lf_AUX_MuASF_Conds2C5_1sym ) ) {
tmp [ 21 ] = arg_0 ( tmp [ 20 ] ) ;
arg0 = lf_AUX_MuASF_Conds2C5_1 ( make_list ( tmp [ 18 ] ) ) ;
arg1 = lf_AUX_MuASF_Conds2C5_1 ( cons ( make_list ( atmp10 ) , make_list ( tmp [ 21 ] ) ) ) ;
arg2 = lf_AUX_MuASF_Conds2C5_2 ( make_list ( atmp20 ) ) ;
goto lbl_lf_AUX_MuASF_Conds2C5_3 ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
else {
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_MuASF_Conds2C5_1 ( make_list ( atmp10 ) ) , lf_AUX_MuASF_Conds2C5_2 ( make_list ( atmp20 ) ) , ltmp [ 3 ] ) ) ;
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf5 ( lf_AUX_MuASF_Conds2C5_3sym , ltmp [ 0 ] , ltmp [ 1 ] , ltmp [ 2 ] , ltmp [ 3 ] , ltmp [ 4 ] ) ) ;
}
}
}
ATerm lf_AUX_MuASF_Conds2C5_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuASF_Conds2C5_2sym , ATmakeAppl ( lf_AUX_MuASF_Conds2C5_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuASF_Conds2C5_2sym , arg0 ) ) ;
}
ATerm lf_AUX_MuASF_Conds2C5_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuASF_Conds2C5_1sym , ATmakeAppl ( lf_AUX_MuASF_Conds2C5_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuASF_Conds2C5_1sym , arg0 ) ) ;
}
ATerm lf7 ( ATerm arg0 ) {
CONS_ENTRY ( lf7sym , ATmakeAppl ( lf7sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf7sym , arg0 ) ) ;
}
ATerm lf5 ( ATerm arg0 ) {
CONS_ENTRY ( lf5sym , ATmakeAppl ( lf5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf5sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf8 ( ATerm arg0 ) {
CONS_ENTRY ( lf8sym , ATmakeAppl ( lf8sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf8sym , arg0 ) ) ;
}
ATerm lf6 ( ATerm arg0 ) {
CONS_ENTRY ( lf6sym , ATmakeAppl ( lf6sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf6sym , arg0 ) ) ;
}

