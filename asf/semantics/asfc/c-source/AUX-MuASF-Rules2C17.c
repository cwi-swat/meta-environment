#include  "asc-support.h"
static Symbol lf_AUX_MuASF_Rules2C17_4sym ;
static ATerm lf_AUX_MuASF_Rules2C17_4 ( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4 , ATerm arg5 , ATerm arg6 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf6sym ;
static ATerm lf6 ( ATerm arg1 ) ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef36sym ;
static funcptr ef36 ;
static Symbol ef37sym ;
static funcptr ef37 ;
static Symbol ef33sym ;
static funcptr ef33 ;
static Symbol ef34sym ;
static funcptr ef34 ;
static Symbol ef35sym ;
static funcptr ef35 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef32sym ;
static funcptr ef32 ;
static Symbol ef38sym ;
static funcptr ef38 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol lf7sym ;
static ATerm lf7 ( ATerm arg1 ) ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol ef19sym ;
static funcptr ef19 ;
static Symbol ef20sym ;
static funcptr ef20 ;
static Symbol lf_AUX_MuASF_Rules2C17_1sym ;
static ATerm lf_AUX_MuASF_Rules2C17_1 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef39sym ;
static funcptr ef39 ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef40sym ;
static funcptr ef40 ;
static Symbol ef41sym ;
static funcptr ef41 ;
static Symbol ef43sym ;
static funcptr ef43 ;
static Symbol lf_AUX_MuASF_Rules2C17_2sym ;
static ATerm lf_AUX_MuASF_Rules2C17_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_MuASF_Rules2C17_3sym ;
static ATerm lf_AUX_MuASF_Rules2C17_3 ( ATerm arg1 ) ;
static Symbol ef42sym ;
static funcptr ef42 ;
static Symbol ef44sym ;
static funcptr ef44 ;
static Symbol ef29sym ;
static funcptr ef29 ;
static Symbol ef30sym ;
static funcptr ef30 ;
static Symbol ef31sym ;
static funcptr ef31 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef24sym ;
static funcptr ef24 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol lf9sym ;
static ATerm lf9 ( ATerm arg1 ) ;
static Symbol ef25sym ;
static funcptr ef25 ;
static Symbol ef26sym ;
static funcptr ef26 ;
static Symbol lf10sym ;
static ATerm lf10 ( ATerm arg1 ) ;
static Symbol ef21sym ;
static funcptr ef21 ;
static Symbol ef22sym ;
static funcptr ef22 ;
static Symbol lf8sym ;
static ATerm lf8 ( ATerm arg1 ) ;
static Symbol ef23sym ;
static funcptr ef23 ;
static Symbol ef27sym ;
static funcptr ef27 ;
static Symbol ef28sym ;
static funcptr ef28 ;
void register_AUX_MuASF_Rules2C17 ( ) {
lf_AUX_MuASF_Rules2C17_4sym = ATmakeSymbol ( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"listpattern2cstats\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)"
 , 6 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Rules2C17_4sym ) ;
lf6sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf6sym ) ;
lf7sym = ATmakeSymbol ( "listtype(sort(\"TE-pair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf7sym ) ;
lf_AUX_MuASF_Rules2C17_1sym = ATmakeSymbol ( "listtype(sort(\"FV-Path\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Rules2C17_1sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"IntCon\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf_AUX_MuASF_Rules2C17_2sym = ATmakeSymbol ( "listtype(sort(\"C-Rule\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Rules2C17_2sym ) ;
lf_AUX_MuASF_Rules2C17_3sym = ATmakeSymbol ( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Rules2C17_3sym ) ;
lf9sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf9sym ) ;
lf10sym = ATmakeSymbol ( "listtype(sort(\"Expression\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf10sym ) ;
lf8sym = ATmakeSymbol ( "listtype(sort(\"Statement\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf8sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FV-Path\"),ql(\",\"))" ) , lf_AUX_MuASF_Rules2C17_1 , lf_AUX_MuASF_Rules2C17_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"C-Rule\"),ql(\";\"))" ) , lf_AUX_MuASF_Rules2C17_2 , lf_AUX_MuASF_Rules2C17_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"NamePair\"),ql(\",\"))" ) , lf_AUX_MuASF_Rules2C17_3 , lf_AUX_MuASF_Rules2C17_3sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"listpattern2cstats\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Rules2C17_4 , lf_AUX_MuASF_Rules2C17_4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"IntCon\"),ql(\",\"))" ) , lf5 , lf5sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf6 , lf6sym ) ;
register_prod ( ATparse ( "listtype(sort(\"TE-pair\"),ql(\",\"))" ) , lf7 , lf7sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Statement\"))" ) , lf8 , lf8sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf9 , lf9sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Expression\"),ql(\",\"))" ) , lf10 , lf10sym ) ;
}
void resolve_AUX_MuASF_Rules2C17 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-atmp\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-atmp\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"add-env\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"add-env\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef20 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-decl\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" ) ) ;
ef20sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-decl\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" ) ) ;
ef21 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef21sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef22 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Statement\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef22sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Statement\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef23 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef23sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef24 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef24sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef25 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef25sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef26 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef26sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef27 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef27sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef28 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef28sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef29 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef29sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef30 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef30sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef31 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef31sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef32 = lookup_func ( ATreadFromString ( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-star-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef32sym = lookup_sym ( ATreadFromString ( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-star-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef33 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef33sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef34 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef34sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef35 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)" ) ) ;
ef35sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)" ) ) ;
ef36 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-array-decl\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" ) ) ;
ef36sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-array-decl\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" ) ) ;
ef37 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"while\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef37sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"while\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef38 = lookup_func ( ATreadFromString ( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-plus-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef38sym = lookup_sym ( ATreadFromString ( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-plus-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef39 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef39sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef40 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-temp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef40sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-temp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef41 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-expression\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef41sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-expression\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef42 = lookup_func ( ATreadFromString ( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef42sym = lookup_sym ( ATreadFromString ( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef43 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cstats2\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef43sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cstats2\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef44 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef44sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
static ATerm constant3 = NULL ;
static ATerm constant4 = NULL ;
static ATerm constant5 = NULL ;
static ATerm constant6 = NULL ;
static ATerm constant7 = NULL ;
static ATerm constant8 = NULL ;
static ATerm constant9 = NULL ;
void init_AUX_MuASF_Rules2C17 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
ATprotect ( & constant3 ) ;
ATprotect ( & constant4 ) ;
ATprotect ( & constant5 ) ;
ATprotect ( & constant6 ) ;
ATprotect ( & constant7 ) ;
ATprotect ( & constant8 ) ;
ATprotect ( & constant9 ) ;
}
ATerm lf_AUX_MuASF_Rules2C17_4 ( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4 , ATerm arg5 ) {
{
ATerm tmp [ 18 ] ;
FUNC_ENTRY ( lf_AUX_MuASF_Rules2C17_4sym , ATmakeAppl ( lf_AUX_MuASF_Rules2C17_4sym , arg0 , arg1 , arg2 , arg3 , arg4 , arg5 ) ) ;
{
ATerm ltmp [ 6 ] ;
lbl_lf_AUX_MuASF_Rules2C17_4 : ltmp [ 0 ] = arg0 ;
ltmp [ 1 ] = arg1 ;
ltmp [ 2 ] = arg2 ;
ltmp [ 3 ] = arg3 ;
ltmp [ 4 ] = arg4 ;
ltmp [ 5 ] = arg5 ;
if ( check_sym ( ltmp [ 0 ] , ef6sym ) ) {
if ( check_sym ( ltmp [ 1 ] , lf_AUX_MuASF_Rules2C17_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( ltmp [ 2 ] , lf_AUX_MuASF_Rules2C17_2sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( ltmp [ 4 ] , lf_AUX_MuASF_Rules2C17_3sym ) ) {
{
ATerm atmp40 = arg_0 ( arg4 ) ;
if ( not_empty_list ( atmp10 ) ) {
tmp [ 0 ] = list_head ( atmp10 ) ;
{
tmp [ 1 ] = list_tail ( atmp10 ) ;
{
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( not_empty_list ( atmp20 ) ) {
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
{
if ( check_sym ( tmp [ 3 ] , lf5sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
if ( term_equal ( ( * ef9 ) ( tmp [ 2 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( ) ) ) ) ) {
if ( term_equal ( ( * ef10 ) ( tmp [ 2 ] ) , ltmp [ 0 ] ) ) {
tmp [ 5 ] = ( * ef11 ) ( ( * ef12 ) ( ( * ef13 ) ( ( * ef14 ) ( lf5 ( make_list ( tmp [ 4 ] ) ) ) ) ) ) ;
tmp [ 6 ] = ( * ef15 ) ( lf_AUX_MuASF_Rules2C17_2 ( make_list ( atmp20 ) ) , ( * ef16 ) ( lf7 ( make_list ( ( * ef17 ) ( tmp [ 2 ] , tmp [ 5 ] ) ) ) ) ) ;
if ( check_sym ( tmp [ 6 ] , ef18sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf_AUX_MuASF_Rules2C17_2sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
tmp [ 9 ] = lf_AUX_MuASF_Rules2C17_4 ( ltmp [ 0 ] , lf_AUX_MuASF_Rules2C17_1 ( make_list ( tmp [ 1 ] ) ) , lf_AUX_MuASF_Rules2C17_2 ( make_list ( tmp [ 8 ] ) ) , ltmp [ 3 ] , lf_AUX_MuASF_Rules2C17_3 ( make_list ( atmp40 ) ) , ltmp [ 5 ] ) ;
if ( check_sym ( tmp [ 9 ] , ef7sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
tmp [ 11 ] = arg_1 ( tmp [ 9 ] ) ;
tmp [ 12 ] = arg_2 ( tmp [ 9 ] ) ;
tmp [ 13 ] = ( * ef19 ) ( ( * ef20 ) ( lf5 ( make_list ( tmp [ 4 ] ) ) ) ) ;
tmp [ 14 ] = ( * ef21 ) ( ( * ef22 ) ( lf8 ( make_list ( ( * ef23 ) ( ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 110 ) ) , cons ( make_list ( make_char ( 111 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 109 ) ) , cons ( make_list ( make_char ( 112 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 121 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , make_list ( make_char ( 116 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) , ( * ef27 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef28 ) ( ) ) ) , ( * ef29 ) ( ( * ef21 ) ( ( * ef22 ) ( lf8 ( cons ( make_list ( ( * ef30 ) ( ( * ef31 ) ( tmp [ 5 ] , ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant3 ? constant3 : ( constant3 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 104 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 97 ) ) , make_list ( make_char ( 100 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) ) ) ) , make_list ( ( * ef30 ) ( ( * ef31 ) ( ltmp [ 3 ] , ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant4 ? constant4 : ( constant4 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 97 ) ) , cons ( make_list ( make_char ( 105 ) ) , make_list ( make_char ( 108 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) ) ) ) ) ) ) ) , tmp [ 11 ] ) ) ) ) ) ) ) ;
FUNC_EXIT ( ( * ef7 ) ( ( * ef8 ) ( tmp [ 10 ] , tmp [ 13 ] ) , tmp [ 14 ] , tmp [ 12 ] ) ) ;
}
}
}
}
}
}
}
if ( check_sym ( tmp [ 2 ] , ef39sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf5sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 3 ] ) ;
if ( term_equal ( ( * ef4 ) ( ( * ef39 ) ( tmp [ 4 ] ) ) , ltmp [ 0 ] ) ) {
tmp [ 6 ] = ( * ef11 ) ( ( * ef12 ) ( ( * ef40 ) ( ltmp [ 5 ] ) ) ) ;
tmp [ 7 ] = ( * ef41 ) ( tmp [ 4 ] , tmp [ 6 ] , lf_AUX_MuASF_Rules2C17_3 ( make_list ( atmp40 ) ) ) ;
tmp [ 8 ] = lf_AUX_MuASF_Rules2C17_4 ( ltmp [ 0 ] , lf_AUX_MuASF_Rules2C17_1 ( make_list ( tmp [ 1 ] ) ) , lf_AUX_MuASF_Rules2C17_2 ( make_list ( atmp20 ) ) , ltmp [ 3 ] , lf_AUX_MuASF_Rules2C17_3 ( make_list ( atmp40 ) ) , ( * ef42 ) ( ltmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 8 ] , ef7sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
tmp [ 10 ] = arg_1 ( tmp [ 8 ] ) ;
tmp [ 11 ] = arg_2 ( tmp [ 8 ] ) ;
tmp [ 12 ] = ( * ef21 ) ( ( * ef22 ) ( lf8 ( make_list ( ( * ef23 ) ( ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 110 ) ) , cons ( make_list ( make_char ( 111 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 109 ) ) , cons ( make_list ( make_char ( 112 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 121 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , make_list ( make_char ( 116 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) , ( * ef27 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef28 ) ( ) ) ) , ( * ef29 ) ( ( * ef21 ) ( ( * ef22 ) ( lf8 ( cons ( make_list ( ( * ef30 ) ( ( * ef31 ) ( tmp [ 6 ] , ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant3 ? constant3 : ( constant3 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 104 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 97 ) ) , make_list ( make_char ( 100 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) ) ) ) , make_list ( ( * ef30 ) ( ( * ef31 ) ( ltmp [ 3 ] , ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant4 ? constant4 : ( constant4 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 97 ) ) , cons ( make_list ( make_char ( 105 ) ) , make_list ( make_char ( 108 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef21 ) ( ( * ef22 ) ( lf8 ( make_list ( ( * ef23 ) ( tmp [ 7 ] , ( * ef27 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef28 ) ( ) ) ) , tmp [ 10 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ;
FUNC_EXIT ( ( * ef7 ) ( tmp [ 9 ] , tmp [ 12 ] , tmp [ 11 ] ) ) ;
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
if ( check_sym ( ltmp [ 0 ] , ef5sym ) ) {
if ( check_sym ( ltmp [ 1 ] , lf_AUX_MuASF_Rules2C17_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( ltmp [ 2 ] , lf_AUX_MuASF_Rules2C17_2sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( ltmp [ 4 ] , lf_AUX_MuASF_Rules2C17_3sym ) ) {
{
ATerm atmp40 = arg_0 ( arg4 ) ;
if ( not_empty_list ( atmp10 ) ) {
tmp [ 0 ] = list_head ( atmp10 ) ;
{
tmp [ 1 ] = list_tail ( atmp10 ) ;
{
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( not_empty_list ( atmp20 ) ) {
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
{
if ( check_sym ( tmp [ 3 ] , lf5sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
if ( term_equal ( ( * ef9 ) ( tmp [ 2 ] ) , ltmp [ 0 ] ) ) {
if ( term_equal ( ( * ef10 ) ( tmp [ 2 ] ) , ( constant5 ? constant5 : ( constant5 = ( * ef6 ) ( ) ) ) ) ) {
tmp [ 5 ] = ( * ef11 ) ( ( * ef12 ) ( ( * ef13 ) ( ( * ef14 ) ( lf5 ( make_list ( tmp [ 4 ] ) ) ) ) ) ) ;
tmp [ 6 ] = ( * ef15 ) ( lf_AUX_MuASF_Rules2C17_2 ( make_list ( atmp20 ) ) , ( * ef16 ) ( lf7 ( make_list ( ( * ef17 ) ( tmp [ 2 ] , tmp [ 5 ] ) ) ) ) ) ;
if ( check_sym ( tmp [ 6 ] , ef18sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf_AUX_MuASF_Rules2C17_2sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
tmp [ 9 ] = lf_AUX_MuASF_Rules2C17_4 ( ( constant5 ? constant5 : ( constant5 = ( * ef6 ) ( ) ) ) , lf_AUX_MuASF_Rules2C17_1 ( make_list ( tmp [ 1 ] ) ) , lf_AUX_MuASF_Rules2C17_2 ( make_list ( tmp [ 8 ] ) ) , ltmp [ 3 ] , lf_AUX_MuASF_Rules2C17_3 ( make_list ( atmp40 ) ) , ltmp [ 5 ] ) ;
if ( check_sym ( tmp [ 9 ] , ef7sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
tmp [ 11 ] = arg_1 ( tmp [ 9 ] ) ;
tmp [ 12 ] = arg_2 ( tmp [ 9 ] ) ;
tmp [ 13 ] = ( * ef19 ) ( ( * ef20 ) ( lf5 ( make_list ( tmp [ 4 ] ) ) ) ) ;
tmp [ 14 ] = ( * ef29 ) ( ( * ef21 ) ( ( * ef22 ) ( lf8 ( cons ( make_list ( ( * ef30 ) ( ( * ef31 ) ( tmp [ 5 ] , ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant3 ? constant3 : ( constant3 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 104 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 97 ) ) , make_list ( make_char ( 100 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) ) ) ) , make_list ( ( * ef30 ) ( ( * ef31 ) ( ltmp [ 3 ] , ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant4 ? constant4 : ( constant4 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 97 ) ) , cons ( make_list ( make_char ( 105 ) ) , make_list ( make_char ( 108 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) ) ) ) ) ) ) ) , tmp [ 11 ] ) ;
FUNC_EXIT ( ( * ef7 ) ( ( * ef8 ) ( tmp [ 10 ] , tmp [ 13 ] ) , tmp [ 14 ] , tmp [ 12 ] ) ) ;
}
}
}
}
}
}
}
if ( check_sym ( tmp [ 2 ] , ef39sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf5sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 3 ] ) ;
if ( term_equal ( ( * ef4 ) ( ( * ef39 ) ( tmp [ 4 ] ) ) , ( constant5 ? constant5 : ( constant5 = ( * ef6 ) ( ) ) ) ) ) {
tmp [ 6 ] = ( * ef11 ) ( ( * ef12 ) ( ( * ef40 ) ( ltmp [ 5 ] ) ) ) ;
tmp [ 7 ] = ( * ef41 ) ( tmp [ 4 ] , tmp [ 6 ] , lf_AUX_MuASF_Rules2C17_3 ( make_list ( atmp40 ) ) ) ;
tmp [ 8 ] = lf_AUX_MuASF_Rules2C17_4 ( ( constant5 ? constant5 : ( constant5 = ( * ef6 ) ( ) ) ) , lf_AUX_MuASF_Rules2C17_1 ( make_list ( tmp [ 1 ] ) ) , lf_AUX_MuASF_Rules2C17_2 ( make_list ( atmp20 ) ) , ltmp [ 3 ] , lf_AUX_MuASF_Rules2C17_3 ( make_list ( atmp40 ) ) , ( * ef42 ) ( ltmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 8 ] , ef7sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
tmp [ 10 ] = arg_1 ( tmp [ 8 ] ) ;
tmp [ 11 ] = arg_2 ( tmp [ 8 ] ) ;
tmp [ 12 ] = ( * ef29 ) ( ( * ef21 ) ( ( * ef22 ) ( lf8 ( cons ( make_list ( ( * ef30 ) ( ( * ef31 ) ( tmp [ 6 ] , ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant3 ? constant3 : ( constant3 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 104 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 97 ) ) , make_list ( make_char ( 100 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) ) ) ) , make_list ( ( * ef30 ) ( ( * ef31 ) ( ltmp [ 3 ] , ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant4 ? constant4 : ( constant4 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 97 ) ) , cons ( make_list ( make_char ( 105 ) ) , make_list ( make_char ( 108 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef21 ) ( ( * ef22 ) ( lf8 ( make_list ( ( * ef23 ) ( tmp [ 7 ] , ( * ef27 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef28 ) ( ) ) ) , tmp [ 10 ] ) ) ) ) ) ) ) ;
FUNC_EXIT ( ( * ef7 ) ( tmp [ 9 ] , tmp [ 12 ] , tmp [ 11 ] ) ) ;
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
if ( check_sym ( ltmp [ 1 ] , lf_AUX_MuASF_Rules2C17_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( ltmp [ 2 ] , lf_AUX_MuASF_Rules2C17_2sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( ltmp [ 4 ] , lf_AUX_MuASF_Rules2C17_3sym ) ) {
{
ATerm atmp40 = arg_0 ( arg4 ) ;
if ( is_single_element ( atmp10 ) ) {
tmp [ 0 ] = list_head ( atmp10 ) ;
{
if ( not_empty_list ( atmp20 ) ) {
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
{
if ( check_sym ( tmp [ 2 ] , lf5sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = ( * ef9 ) ( tmp [ 1 ] ) ;
if ( term_equal ( tmp [ 4 ] , ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( ) ) ) ) ) {
if ( term_equal ( ( * ef10 ) ( tmp [ 1 ] ) , ( constant5 ? constant5 : ( constant5 = ( * ef6 ) ( ) ) ) ) ) {
tmp [ 5 ] = ( * ef11 ) ( ( * ef12 ) ( ( * ef13 ) ( ( * ef14 ) ( lf5 ( make_list ( tmp [ 3 ] ) ) ) ) ) ) ;
tmp [ 6 ] = ( * ef15 ) ( lf_AUX_MuASF_Rules2C17_2 ( make_list ( atmp20 ) ) , ( * ef16 ) ( lf7 ( make_list ( ( * ef17 ) ( tmp [ 1 ] , tmp [ 5 ] ) ) ) ) ) ;
if ( check_sym ( tmp [ 6 ] , ef18sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf_AUX_MuASF_Rules2C17_2sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
tmp [ 9 ] = ( * ef43 ) ( lf_AUX_MuASF_Rules2C17_2 ( make_list ( tmp [ 8 ] ) ) , lf_AUX_MuASF_Rules2C17_3 ( make_list ( atmp40 ) ) , ltmp [ 5 ] ) ;
if ( check_sym ( tmp [ 9 ] , ef44sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
tmp [ 11 ] = arg_1 ( tmp [ 9 ] ) ;
tmp [ 12 ] = ( * ef21 ) ( ( * ef22 ) ( lf8 ( make_list ( ( * ef23 ) ( ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant6 ? constant6 : ( constant6 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 110 ) ) , cons ( make_list ( make_char ( 103 ) ) , cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 109 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 110 ) ) , make_list ( make_char ( 116 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) , ( * ef27 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef28 ) ( ) ) ) , ( * ef29 ) ( ( * ef21 ) ( ( * ef22 ) ( lf8 ( make_list ( ( * ef30 ) ( ( * ef31 ) ( tmp [ 5 ] , ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant3 ? constant3 : ( constant3 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 104 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 97 ) ) , make_list ( make_char ( 100 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) ) ) ) ) ) ) , tmp [ 10 ] ) ) ) ) ) ) ) ;
tmp [ 13 ] = ( * ef19 ) ( ( * ef20 ) ( lf5 ( make_list ( tmp [ 3 ] ) ) ) ) ;
FUNC_EXIT ( ( * ef7 ) ( tmp [ 13 ] , tmp [ 12 ] , tmp [ 11 ] ) ) ;
}
}
}
}
}
tmp [ 5 ] = ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( ) ) ) ;
if ( term_equal ( ( * ef32 ) ( tmp [ 1 ] ) , tmp [ 5 ] ) ) {
tmp [ 6 ] = ( * ef15 ) ( lf_AUX_MuASF_Rules2C17_2 ( make_list ( atmp20 ) ) , ( * ef16 ) ( lf7 ( make_list ( ( * ef17 ) ( tmp [ 1 ] , ltmp [ 3 ] ) ) ) ) ) ;
if ( check_sym ( tmp [ 6 ] , ef18sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf_AUX_MuASF_Rules2C17_2sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
tmp [ 9 ] = ( * ef43 ) ( lf_AUX_MuASF_Rules2C17_2 ( make_list ( tmp [ 8 ] ) ) , lf_AUX_MuASF_Rules2C17_3 ( make_list ( atmp40 ) ) , ltmp [ 5 ] ) ;
if ( check_sym ( tmp [ 9 ] , ef44sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
tmp [ 11 ] = arg_1 ( tmp [ 9 ] ) ;
FUNC_EXIT ( ( * ef7 ) ( ( * ef28 ) ( ) , tmp [ 10 ] , tmp [ 11 ] ) ) ;
}
}
}
}
}
if ( term_equal ( ( * ef38 ) ( tmp [ 1 ] ) , tmp [ 5 ] ) ) {
tmp [ 6 ] = ( * ef15 ) ( lf_AUX_MuASF_Rules2C17_2 ( make_list ( atmp20 ) ) , ( * ef16 ) ( lf7 ( make_list ( ( * ef17 ) ( tmp [ 1 ] , ltmp [ 3 ] ) ) ) ) ) ;
if ( check_sym ( tmp [ 6 ] , ef18sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf_AUX_MuASF_Rules2C17_2sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
tmp [ 9 ] = ( * ef43 ) ( lf_AUX_MuASF_Rules2C17_2 ( make_list ( tmp [ 8 ] ) ) , lf_AUX_MuASF_Rules2C17_3 ( make_list ( atmp40 ) ) , ltmp [ 5 ] ) ;
if ( check_sym ( tmp [ 9 ] , ef44sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
tmp [ 11 ] = arg_1 ( tmp [ 9 ] ) ;
tmp [ 12 ] = ( * ef21 ) ( ( * ef22 ) ( lf8 ( make_list ( ( * ef23 ) ( ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 110 ) ) , cons ( make_list ( make_char ( 111 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 109 ) ) , cons ( make_list ( make_char ( 112 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 121 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , make_list ( make_char ( 116 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) , ( * ef27 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef28 ) ( ) ) ) , tmp [ 10 ] ) ) ) ) ) ) ;
FUNC_EXIT ( ( * ef7 ) ( ( * ef28 ) ( ) , tmp [ 12 ] , tmp [ 11 ] ) ) ;
}
}
}
}
}
}
}
if ( check_sym ( tmp [ 1 ] , ef39sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 2 ] , lf5sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 5 ] = ( * ef11 ) ( ( * ef12 ) ( ( * ef40 ) ( ltmp [ 5 ] ) ) ) ;
tmp [ 6 ] = ( * ef41 ) ( tmp [ 3 ] , tmp [ 5 ] , lf_AUX_MuASF_Rules2C17_3 ( make_list ( atmp40 ) ) ) ;
tmp [ 7 ] = ( * ef43 ) ( lf_AUX_MuASF_Rules2C17_2 ( make_list ( atmp20 ) ) , lf_AUX_MuASF_Rules2C17_3 ( make_list ( atmp40 ) ) , ( * ef42 ) ( ltmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , ef44sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
tmp [ 9 ] = arg_1 ( tmp [ 7 ] ) ;
tmp [ 10 ] = ( * ef21 ) ( ( * ef22 ) ( lf8 ( make_list ( ( * ef23 ) ( ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant6 ? constant6 : ( constant6 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 110 ) ) , cons ( make_list ( make_char ( 103 ) ) , cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 109 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 110 ) ) , make_list ( make_char ( 116 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) , ( * ef27 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef28 ) ( ) ) ) , ( * ef29 ) ( ( * ef21 ) ( ( * ef22 ) ( lf8 ( make_list ( ( * ef30 ) ( ( * ef31 ) ( tmp [ 5 ] , ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant3 ? constant3 : ( constant3 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 104 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 97 ) ) , make_list ( make_char ( 100 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef21 ) ( ( * ef22 ) ( lf8 ( make_list ( ( * ef23 ) ( tmp [ 6 ] , ( * ef27 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef28 ) ( ) ) ) , tmp [ 8 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ;
FUNC_EXIT ( ( * ef7 ) ( ( * ef28 ) ( ) , tmp [ 10 ] , tmp [ 9 ] ) ) ;
}
}
}
}
}
tmp [ 1 ] = list_head ( atmp20 ) ;
tmp [ 2 ] = list_tail ( atmp20 ) ;
if ( check_sym ( tmp [ 0 ] , ef1sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf_AUX_MuASF_Rules2C17_1sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
tmp [ 5 ] = list_head ( tmp [ 4 ] ) ;
tmp [ 6 ] = list_tail ( tmp [ 4 ] ) ;
if ( not_empty_list ( tmp [ 6 ] ) ) {
if ( check_sym ( tmp [ 5 ] , ef2sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 5 ] ) ;
tmp [ 8 ] = arg_1 ( tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 8 ] , lf5sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef3sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 1 ] ) ;
tmp [ 11 ] = arg_1 ( tmp [ 1 ] ) ;
tmp [ 12 ] = arg_2 ( tmp [ 1 ] ) ;
tmp [ 13 ] = arg_3 ( tmp [ 1 ] ) ;
tmp [ 14 ] = arg_4 ( tmp [ 1 ] ) ;
tmp [ 15 ] = arg_5 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 10 ] , lf_AUX_MuASF_Rules2C17_1sym ) ) {
tmp [ 16 ] = arg_0 ( tmp [ 10 ] ) ;
if ( check_sym ( tmp [ 11 ] , lf6sym ) ) {
tmp [ 17 ] = arg_0 ( tmp [ 11 ] ) ;
if ( term_equal ( ( * ef4 ) ( tmp [ 7 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( ) ) ) ) ) {
arg1 = lf_AUX_MuASF_Rules2C17_1 ( make_list ( tmp [ 6 ] ) ) ;
arg2 = lf_AUX_MuASF_Rules2C17_2 ( cons ( make_list ( ( * ef3 ) ( lf_AUX_MuASF_Rules2C17_1 ( make_list ( tmp [ 16 ] ) ) , lf6 ( make_list ( tmp [ 17 ] ) ) , tmp [ 12 ] , tmp [ 13 ] , tmp [ 14 ] , tmp [ 15 ] ) ) , make_list ( tmp [ 2 ] ) ) ) ;
arg4 = lf_AUX_MuASF_Rules2C17_3 ( make_list ( atmp40 ) ) ;
goto lbl_lf_AUX_MuASF_Rules2C17_4 ;
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
{
if ( not_empty_list ( atmp10 ) ) {
tmp [ 0 ] = list_head ( atmp10 ) ;
{
tmp [ 1 ] = list_tail ( atmp10 ) ;
{
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( not_empty_list ( atmp20 ) ) {
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
{
if ( check_sym ( tmp [ 3 ] , lf5sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = ( * ef9 ) ( tmp [ 2 ] ) ;
if ( term_equal ( tmp [ 5 ] , ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( ) ) ) ) ) {
tmp [ 6 ] = ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( ) ) ) ;
if ( term_equal ( ( * ef38 ) ( tmp [ 2 ] ) , tmp [ 6 ] ) ) {
tmp [ 7 ] = ( * ef14 ) ( lf5 ( make_list ( tmp [ 4 ] ) ) ) ;
tmp [ 8 ] = ( * ef15 ) ( lf_AUX_MuASF_Rules2C17_2 ( make_list ( atmp20 ) ) , ( * ef16 ) ( lf7 ( make_list ( ( * ef17 ) ( tmp [ 2 ] , ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant7 ? constant7 : ( constant7 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 99 ) ) , make_list ( make_char ( 101 ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( cons ( make_list ( ( * ef11 ) ( ( * ef12 ) ( ( * ef33 ) ( ( * ef13 ) ( tmp [ 7 ] ) , ( constant8 ? constant8 : ( constant8 = ( * ef11 ) ( ( * ef12 ) ( ( * ef34 ) ( ( * ef35 ) ( lf9 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ) ) ) ) ) ) , make_list ( ( * ef11 ) ( ( * ef12 ) ( ( * ef33 ) ( ( * ef13 ) ( tmp [ 7 ] ) , ( constant9 ? constant9 : ( constant9 = ( * ef11 ) ( ( * ef12 ) ( ( * ef34 ) ( ( * ef35 ) ( lf9 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 8 ] , ef18sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , lf_AUX_MuASF_Rules2C17_2sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
if ( not_empty_list ( tmp [ 10 ] ) ) {
tmp [ 11 ] = lf_AUX_MuASF_Rules2C17_4 ( ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( ) ) ) , lf_AUX_MuASF_Rules2C17_1 ( make_list ( tmp [ 1 ] ) ) , lf_AUX_MuASF_Rules2C17_2 ( make_list ( tmp [ 10 ] ) ) , ltmp [ 3 ] , lf_AUX_MuASF_Rules2C17_3 ( make_list ( atmp40 ) ) , ltmp [ 5 ] ) ;
if ( check_sym ( tmp [ 11 ] , ef7sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ;
tmp [ 13 ] = arg_1 ( tmp [ 11 ] ) ;
tmp [ 14 ] = arg_2 ( tmp [ 11 ] ) ;
tmp [ 15 ] = ( * ef19 ) ( ( * ef36 ) ( lf5 ( make_list ( tmp [ 4 ] ) ) ) ) ;
tmp [ 16 ] = ( * ef21 ) ( ( * ef22 ) ( lf8 ( cons ( make_list ( ( * ef30 ) ( ( * ef31 ) ( ( * ef11 ) ( ( * ef12 ) ( ( * ef33 ) ( ( * ef13 ) ( tmp [ 7 ] ) , ( constant8 ? constant8 : ( constant8 = ( * ef11 ) ( ( * ef12 ) ( ( * ef34 ) ( ( * ef35 ) ( lf9 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ) ) ) ) ) , ltmp [ 3 ] ) ) ) , make_list ( ( * ef23 ) ( ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 110 ) ) , cons ( make_list ( make_char ( 111 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 109 ) ) , cons ( make_list ( make_char ( 112 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 121 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , make_list ( make_char ( 116 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) , ( * ef27 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef28 ) ( ) ) ) , ( * ef21 ) ( ( * ef22 ) ( lf8 ( cons ( make_list ( ( * ef30 ) ( ( * ef31 ) ( ltmp [ 3 ] , ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant4 ? constant4 : ( constant4 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 97 ) ) , cons ( make_list ( make_char ( 105 ) ) , make_list ( make_char ( 108 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) ) ) ) , cons ( make_list ( ( * ef30 ) ( ( * ef31 ) ( ( * ef11 ) ( ( * ef12 ) ( ( * ef33 ) ( ( * ef13 ) ( tmp [ 7 ] ) , ( constant9 ? constant9 : ( constant9 = ( * ef11 ) ( ( * ef12 ) ( ( * ef34 ) ( ( * ef35 ) ( lf9 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) ) ) ) ) , ltmp [ 3 ] ) ) ) , make_list ( ( * ef37 ) ( ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 110 ) ) , cons ( make_list ( make_char ( 111 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 109 ) ) , cons ( make_list ( make_char ( 112 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 121 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , make_list ( make_char ( 116 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) , ( * ef27 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef28 ) ( ) ) ) , ( * ef29 ) ( tmp [ 13 ] , ( * ef21 ) ( ( * ef22 ) ( lf8 ( cons ( make_list ( ( * ef30 ) ( ( * ef31 ) ( ( * ef11 ) ( ( * ef12 ) ( ( * ef33 ) ( ( * ef13 ) ( tmp [ 7 ] ) , ( constant9 ? constant9 : ( constant9 = ( * ef11 ) ( ( * ef12 ) ( ( * ef34 ) ( ( * ef35 ) ( lf9 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant4 ? constant4 : ( constant4 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 97 ) ) , cons ( make_list ( make_char ( 105 ) ) , make_list ( make_char ( 108 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ( * ef11 ) ( ( * ef12 ) ( ( * ef33 ) ( ( * ef13 ) ( tmp [ 7 ] ) , ( constant9 ? constant9 : ( constant9 = ( * ef11 ) ( ( * ef12 ) ( ( * ef34 ) ( ( * ef35 ) ( lf9 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , make_list ( ( * ef30 ) ( ( * ef31 ) ( ltmp [ 3 ] , ( * ef11 ) ( ( * ef12 ) ( ( * ef33 ) ( ( * ef13 ) ( tmp [ 7 ] ) , ( constant9 ? constant9 : ( constant9 = ( * ef11 ) ( ( * ef12 ) ( ( * ef34 ) ( ( * ef35 ) ( lf9 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
FUNC_EXIT ( ( * ef7 ) ( ( * ef8 ) ( tmp [ 12 ] , tmp [ 15 ] ) , tmp [ 16 ] , tmp [ 14 ] ) ) ;
}
}
}
}
}
if ( term_equal ( ( * ef32 ) ( tmp [ 2 ] ) , tmp [ 6 ] ) ) {
tmp [ 7 ] = ( * ef14 ) ( lf5 ( make_list ( tmp [ 4 ] ) ) ) ;
tmp [ 8 ] = ( * ef15 ) ( lf_AUX_MuASF_Rules2C17_2 ( make_list ( atmp20 ) ) , ( * ef16 ) ( lf7 ( make_list ( ( * ef17 ) ( tmp [ 2 ] , ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant7 ? constant7 : ( constant7 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 99 ) ) , make_list ( make_char ( 101 ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( cons ( make_list ( ( * ef11 ) ( ( * ef12 ) ( ( * ef33 ) ( ( * ef13 ) ( tmp [ 7 ] ) , ( constant8 ? constant8 : ( constant8 = ( * ef11 ) ( ( * ef12 ) ( ( * ef34 ) ( ( * ef35 ) ( lf9 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ) ) ) ) ) ) , make_list ( ( * ef11 ) ( ( * ef12 ) ( ( * ef33 ) ( ( * ef13 ) ( tmp [ 7 ] ) , ( constant9 ? constant9 : ( constant9 = ( * ef11 ) ( ( * ef12 ) ( ( * ef34 ) ( ( * ef35 ) ( lf9 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 8 ] , ef18sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , lf_AUX_MuASF_Rules2C17_2sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
if ( not_empty_list ( tmp [ 10 ] ) ) {
tmp [ 11 ] = lf_AUX_MuASF_Rules2C17_4 ( ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( ) ) ) , lf_AUX_MuASF_Rules2C17_1 ( make_list ( tmp [ 1 ] ) ) , lf_AUX_MuASF_Rules2C17_2 ( make_list ( tmp [ 10 ] ) ) , ltmp [ 3 ] , lf_AUX_MuASF_Rules2C17_3 ( make_list ( atmp40 ) ) , ltmp [ 5 ] ) ;
if ( check_sym ( tmp [ 11 ] , ef7sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ;
tmp [ 13 ] = arg_1 ( tmp [ 11 ] ) ;
tmp [ 14 ] = arg_2 ( tmp [ 11 ] ) ;
tmp [ 15 ] = ( * ef19 ) ( ( * ef36 ) ( lf5 ( make_list ( tmp [ 4 ] ) ) ) ) ;
tmp [ 16 ] = ( * ef21 ) ( ( * ef22 ) ( lf8 ( cons ( make_list ( ( * ef30 ) ( ( * ef31 ) ( ( * ef11 ) ( ( * ef12 ) ( ( * ef33 ) ( ( * ef13 ) ( tmp [ 7 ] ) , ( constant8 ? constant8 : ( constant8 = ( * ef11 ) ( ( * ef12 ) ( ( * ef34 ) ( ( * ef35 ) ( lf9 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ) ) ) ) ) , ltmp [ 3 ] ) ) ) , cons ( make_list ( ( * ef30 ) ( ( * ef31 ) ( ( * ef11 ) ( ( * ef12 ) ( ( * ef33 ) ( ( * ef13 ) ( tmp [ 7 ] ) , ( constant9 ? constant9 : ( constant9 = ( * ef11 ) ( ( * ef12 ) ( ( * ef34 ) ( ( * ef35 ) ( lf9 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) ) ) ) ) , ltmp [ 3 ] ) ) ) , make_list ( ( * ef37 ) ( ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 110 ) ) , cons ( make_list ( make_char ( 111 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 101 ) ) , cons ( make_list ( make_char ( 109 ) ) , cons ( make_list ( make_char ( 112 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 121 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , make_list ( make_char ( 116 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ltmp [ 3 ] ) ) ) ) ) ) , ( * ef27 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef28 ) ( ) ) ) , ( * ef29 ) ( tmp [ 13 ] , ( * ef21 ) ( ( * ef22 ) ( lf8 ( cons ( make_list ( ( * ef30 ) ( ( * ef31 ) ( ( * ef11 ) ( ( * ef12 ) ( ( * ef33 ) ( ( * ef13 ) ( tmp [ 7 ] ) , ( constant9 ? constant9 : ( constant9 = ( * ef11 ) ( ( * ef12 ) ( ( * ef34 ) ( ( * ef35 ) ( lf9 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef11 ) ( ( * ef12 ) ( ( * ef24 ) ( ( constant4 ? constant4 : ( constant4 = ( * ef13 ) ( ( * ef25 ) ( lf9 ( cons ( make_list ( make_char ( 108 ) ) , cons ( make_list ( make_char ( 105 ) ) , cons ( make_list ( make_char ( 115 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 116 ) ) , cons ( make_list ( make_char ( 97 ) ) , cons ( make_list ( make_char ( 105 ) ) , make_list ( make_char ( 108 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( lf10 ( make_list ( ( * ef11 ) ( ( * ef12 ) ( ( * ef33 ) ( ( * ef13 ) ( tmp [ 7 ] ) , ( constant9 ? constant9 : ( constant9 = ( * ef11 ) ( ( * ef12 ) ( ( * ef34 ) ( ( * ef35 ) ( lf9 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , make_list ( ( * ef30 ) ( ( * ef31 ) ( ltmp [ 3 ] , ( * ef11 ) ( ( * ef12 ) ( ( * ef33 ) ( ( * ef13 ) ( tmp [ 7 ] ) , ( constant9 ? constant9 : ( constant9 = ( * ef11 ) ( ( * ef12 ) ( ( * ef34 ) ( ( * ef35 ) ( lf9 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
FUNC_EXIT ( ( * ef7 ) ( ( * ef8 ) ( tmp [ 12 ] , tmp [ 15 ] ) , tmp [ 16 ] , tmp [ 14 ] ) ) ;
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
}
FUNC_EXIT ( make_nf6 ( lf_AUX_MuASF_Rules2C17_4sym , ltmp [ 0 ] , ltmp [ 1 ] , ltmp [ 2 ] , ltmp [ 3 ] , ltmp [ 4 ] , ltmp [ 5 ] ) ) ;
}
}
}
ATerm lf8 ( ATerm arg0 ) {
CONS_ENTRY ( lf8sym , ATmakeAppl ( lf8sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf8sym , arg0 ) ) ;
}
ATerm lf10 ( ATerm arg0 ) {
CONS_ENTRY ( lf10sym , ATmakeAppl ( lf10sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf10sym , arg0 ) ) ;
}
ATerm lf9 ( ATerm arg0 ) {
CONS_ENTRY ( lf9sym , ATmakeAppl ( lf9sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf9sym , arg0 ) ) ;
}
ATerm lf_AUX_MuASF_Rules2C17_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuASF_Rules2C17_3sym , ATmakeAppl ( lf_AUX_MuASF_Rules2C17_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuASF_Rules2C17_3sym , arg0 ) ) ;
}
ATerm lf_AUX_MuASF_Rules2C17_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuASF_Rules2C17_2sym , ATmakeAppl ( lf_AUX_MuASF_Rules2C17_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuASF_Rules2C17_2sym , arg0 ) ) ;
}
ATerm lf5 ( ATerm arg0 ) {
CONS_ENTRY ( lf5sym , ATmakeAppl ( lf5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf5sym , arg0 ) ) ;
}
ATerm lf_AUX_MuASF_Rules2C17_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuASF_Rules2C17_1sym , ATmakeAppl ( lf_AUX_MuASF_Rules2C17_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuASF_Rules2C17_1sym , arg0 ) ) ;
}
ATerm lf7 ( ATerm arg0 ) {
CONS_ENTRY ( lf7sym , ATmakeAppl ( lf7sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf7sym , arg0 ) ) ;
}
ATerm lf6 ( ATerm arg0 ) {
CONS_ENTRY ( lf6sym , ATmakeAppl ( lf6sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf6sym , arg0 ) ) ;
}

