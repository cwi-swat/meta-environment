#include  "support.h"
static Symbol lf_AUX_MuASF_Rules2C7_3sym ;
static ATerm lf_AUX_MuASF_Rules2C7_3 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef36sym ;
static funcptr ef36 ;
static Symbol ef37sym ;
static funcptr ef37 ;
static Symbol ef38sym ;
static funcptr ef38 ;
static Symbol ef39sym ;
static funcptr ef39 ;
static Symbol ef40sym ;
static funcptr ef40 ;
static Symbol ef41sym ;
static funcptr ef41 ;
static Symbol ef42sym ;
static funcptr ef42 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef43sym ;
static funcptr ef43 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol ef19sym ;
static funcptr ef19 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef44sym ;
static funcptr ef44 ;
static Symbol lf8sym ;
static ATerm lf8 ( ATerm arg1 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol lf6sym ;
static ATerm lf6 ( ATerm arg1 ) ;
static Symbol ef20sym ;
static funcptr ef20 ;
static Symbol lf_AUX_MuASF_Rules2C7_1sym ;
static ATerm lf_AUX_MuASF_Rules2C7_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_MuASF_Rules2C7_2sym ;
static ATerm lf_AUX_MuASF_Rules2C7_2 ( ATerm arg1 ) ;
static Symbol ef22sym ;
static funcptr ef22 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef21sym ;
static funcptr ef21 ;
static Symbol ef23sym ;
static funcptr ef23 ;
static Symbol ef24sym ;
static funcptr ef24 ;
static Symbol ef26sym ;
static funcptr ef26 ;
static Symbol ef25sym ;
static funcptr ef25 ;
static Symbol ef27sym ;
static funcptr ef27 ;
static Symbol ef28sym ;
static funcptr ef28 ;
static Symbol ef29sym ;
static funcptr ef29 ;
static Symbol ef32sym ;
static funcptr ef32 ;
static Symbol ef34sym ;
static funcptr ef34 ;
static Symbol lf7sym ;
static ATerm lf7 ( ATerm arg1 ) ;
static Symbol ef30sym ;
static funcptr ef30 ;
static Symbol ef31sym ;
static funcptr ef31 ;
static Symbol ef33sym ;
static funcptr ef33 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef35sym ;
static funcptr ef35 ;
void register_AUX_MuASF_Rules2C7 ( ) {
lf_AUX_MuASF_Rules2C7_3sym = ATmakeSymbol ( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cfunc\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Rules2C7_3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Type-specifier\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf8sym = ATmakeSymbol ( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf8sym ) ;
lf6sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf6sym ) ;
lf_AUX_MuASF_Rules2C7_1sym = ATmakeSymbol ( "listtype(sort(\"Rule\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Rules2C7_1sym ) ;
lf_AUX_MuASF_Rules2C7_2sym = ATmakeSymbol ( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Rules2C7_2sym ) ;
lf7sym = ATmakeSymbol ( "listtype(sort(\"Expression\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf7sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Rule\"),ql(\";\"))" ) , lf_AUX_MuASF_Rules2C7_1 , lf_AUX_MuASF_Rules2C7_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"NamePair\"),ql(\",\"))" ) , lf_AUX_MuASF_Rules2C7_2 , lf_AUX_MuASF_Rules2C7_2sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cfunc\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Rules2C7_3 , lf_AUX_MuASF_Rules2C7_3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Type-specifier\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf5 , lf5sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf6 , lf6sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Expression\"),ql(\",\"))" ) , lf7 , lf7sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))" ) , lf8 , lf8sym ) ;
}
void resolve_AUX_MuASF_Rules2C7 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"is-memo\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"is-memo\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"funargs2cargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PA-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"funargs2cargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PA-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PA-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PA-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-defaults\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-defaults\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef20 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef20sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef21 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef21sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef22 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"funargs2cstats\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef22sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"funargs2cstats\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef23 = lookup_func ( ATreadFromString ( "prod(id(\"ANumerals\"),w(\"\"),[l(\"gtr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef23sym = lookup_sym ( ATreadFromString ( "prod(id(\"ANumerals\"),w(\"\"),[l(\"gtr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef24 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-tmp-array\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef24sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-tmp-array\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef25 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef25sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef26 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++r\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef26sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++r\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef27 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef27sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef28 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef28sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef29 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef29sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef30 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef30sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef31 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef31sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef32 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef32sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef33 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef33sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef34 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef34sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef35 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++d\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef35sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++d\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef36 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef36sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef37 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\"),w(\"\"),sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" ) ) ;
ef37sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\"),w(\"\"),sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" ) ) ;
ef38 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" ) ) ;
ef38sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" ) ) ;
ef39 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" ) ) ;
ef39sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" ) ) ;
ef40 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" ) ) ;
ef40sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" ) ) ;
ef41 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef41sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef42 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"return\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef42sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"return\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef43 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef43sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef44 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)" ) ) ;
ef44sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)" ) ) ;
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
static ATerm constant10 = NULL ;
static ATerm constant11 = NULL ;
static ATerm constant12 = NULL ;
static ATerm constant13 = NULL ;
static ATerm constant14 = NULL ;
static ATerm constant15 = NULL ;
static ATerm constant16 = NULL ;
static ATerm constant17 = NULL ;
static ATerm constant18 = NULL ;
static ATerm constant19 = NULL ;
static ATerm constant20 = NULL ;
static ATerm constant21 = NULL ;
static ATerm constant22 = NULL ;
static ATerm constant23 = NULL ;
static ATerm constant24 = NULL ;
static ATerm constant25 = NULL ;
static ATerm constant26 = NULL ;
static ATerm constant27 = NULL ;
static ATerm constant28 = NULL ;
static ATerm constant29 = NULL ;
static ATerm constant30 = NULL ;
void init_AUX_MuASF_Rules2C7 ( ) {
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
ATprotect ( & constant10 ) ;
ATprotect ( & constant11 ) ;
ATprotect ( & constant12 ) ;
ATprotect ( & constant13 ) ;
ATprotect ( & constant14 ) ;
ATprotect ( & constant15 ) ;
ATprotect ( & constant16 ) ;
ATprotect ( & constant17 ) ;
ATprotect ( & constant18 ) ;
ATprotect ( & constant19 ) ;
ATprotect ( & constant20 ) ;
ATprotect ( & constant21 ) ;
ATprotect ( & constant22 ) ;
ATprotect ( & constant23 ) ;
ATprotect ( & constant24 ) ;
ATprotect ( & constant25 ) ;
ATprotect ( & constant26 ) ;
ATprotect ( & constant27 ) ;
ATprotect ( & constant28 ) ;
ATprotect ( & constant29 ) ;
ATprotect ( & constant30 ) ;
}
ATerm lf_AUX_MuASF_Rules2C7_3 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 37 ] ;
PROF ( prof_lf_AUX_MuASF_Rules2C7_3 ) ;
if ( check_sym ( arg0 , lf_AUX_MuASF_Rules2C7_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( arg1 , lf_AUX_MuASF_Rules2C7_2sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
tmp [ 1 ] = list_tail ( atmp00 ) ;
tmp [ 2 ] = ( * ef8 ) ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 2 ] , ef9sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
{
if ( check_sym ( tmp [ 3 ] , lf5sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = ( * ef10 ) ( ( * ef9 ) ( lf5 ( make_list ( tmp [ 4 ] ) ) ) , lf_AUX_MuASF_Rules2C7_2 ( make_list ( atmp10 ) ) ) ;
if ( term_equal ( tmp [ 5 ] , ( constant0 ? constant0 : ( constant0 = ( * ef43 ) ( ) ) ) ) ) {
tmp [ 6 ] = ( * ef12 ) ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 6 ] , ef13sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf6sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
tmp [ 9 ] = ( * ef14 ) ( lf6 ( make_list ( tmp [ 8 ] ) ) , ( constant1 ? constant1 : ( constant1 = ( * ef15 ) ( ( * ef16 ) ( lf5 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 9 ] , ef17sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
tmp [ 11 ] = arg_1 ( tmp [ 9 ] ) ;
tmp [ 12 ] = arg_2 ( tmp [ 9 ] ) ;
tmp [ 13 ] = ( * ef18 ) ( lf_AUX_MuASF_Rules2C7_1 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 13 ] , ef19sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 13 ] ) ;
tmp [ 15 ] = arg_1 ( tmp [ 13 ] ) ;
if ( check_sym ( tmp [ 14 ] , lf_AUX_MuASF_Rules2C7_1sym ) ) {
tmp [ 16 ] = arg_0 ( tmp [ 14 ] ) ;
if ( check_sym ( tmp [ 15 ] , lf_AUX_MuASF_Rules2C7_1sym ) ) {
tmp [ 17 ] = arg_0 ( tmp [ 15 ] ) ;
tmp [ 18 ] = ( * ef20 ) ( lf_AUX_MuASF_Rules2C7_1 ( make_list ( tmp [ 17 ] ) ) , lf_AUX_MuASF_Rules2C7_2 ( make_list ( atmp10 ) ) ) ;
if ( check_sym ( tmp [ 18 ] , ef21sym ) ) {
tmp [ 19 ] = arg_0 ( tmp [ 18 ] ) ;
tmp [ 20 ] = arg_1 ( tmp [ 18 ] ) ;
tmp [ 21 ] = ( * ef20 ) ( lf_AUX_MuASF_Rules2C7_1 ( make_list ( tmp [ 16 ] ) ) , lf_AUX_MuASF_Rules2C7_2 ( make_list ( atmp10 ) ) ) ;
if ( check_sym ( tmp [ 21 ] , ef21sym ) ) {
tmp [ 22 ] = arg_0 ( tmp [ 21 ] ) ;
tmp [ 23 ] = arg_1 ( tmp [ 21 ] ) ;
tmp [ 24 ] = ( * ef22 ) ( ( * ef9 ) ( lf5 ( make_list ( tmp [ 4 ] ) ) ) , tmp [ 11 ] , tmp [ 12 ] ) ;
if ( check_sym ( tmp [ 24 ] , ef21sym ) ) {
tmp [ 25 ] = arg_0 ( tmp [ 24 ] ) ;
tmp [ 26 ] = arg_1 ( tmp [ 24 ] ) ;
tmp [ 27 ] = ( * ef23 ) ( tmp [ 20 ] , tmp [ 23 ] ) ;
tmp [ 28 ] = ( * ef23 ) ( tmp [ 26 ] , tmp [ 27 ] ) ;
tmp [ 29 ] = ( * ef24 ) ( tmp [ 28 ] ) ;
tmp [ 30 ] = ( * ef25 ) ( tmp [ 19 ] , tmp [ 22 ] ) ;
tmp [ 31 ] = ( * ef26 ) ( tmp [ 30 ] , tmp [ 25 ] ) ;
tmp [ 32 ] = ( * ef25 ) ( ( * ef27 ) ( ( * ef28 ) ( ( * ef29 ) ( ( * ef30 ) ( ( * ef31 ) ( ( * ef32 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef33 ) ( ( * ef4 ) ( lf5 ( cons ( make_list ( make_char ( 80 ) ) , cons ( make_list ( make_char ( 82 ) ) , cons ( make_list ( make_char ( 79 ) ) , make_list ( make_char ( 70 ) ) ) ) ) ) ) ) ) ) , ( * ef34 ) ( lf7 ( make_list ( ( * ef30 ) ( ( * ef31 ) ( ( * ef33 ) ( ( * ef4 ) ( lf5 ( cons ( ( constant3 ? constant3 : ( constant3 = make_list ( make_char ( 112 ) ) ) ) , cons ( ( constant4 ? constant4 : ( constant4 = make_list ( make_char ( 114 ) ) ) ) , cons ( ( constant5 ? constant5 : ( constant5 = make_list ( make_char ( 111 ) ) ) ) , cons ( ( constant6 ? constant6 : ( constant6 = make_list ( make_char ( 102 ) ) ) ) , cons ( ( constant7 ? constant7 : ( constant7 = make_list ( make_char ( 95 ) ) ) ) , make_list ( tmp [ 4 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , tmp [ 31 ] ) ;
tmp [ 33 ] = ( * ef35 ) ( tmp [ 29 ] , tmp [ 32 ] ) ;
if ( check_sym ( tmp [ 12 ] , ef15sym ) ) {
tmp [ 34 ] = arg_0 ( tmp [ 12 ] ) ;
if ( check_sym ( tmp [ 34 ] , ef16sym ) ) {
tmp [ 35 ] = arg_0 ( tmp [ 34 ] ) ;
if ( check_sym ( tmp [ 35 ] , lf5sym ) ) {
tmp [ 36 ] = arg_0 ( tmp [ 35 ] ) ;
return ( * ef1 ) ( ( constant8 ? constant8 : ( constant8 = ( * ef2 ) ( lf4 ( make_list ( ( * ef3 ) ( ( * ef4 ) ( lf5 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] ) ) ) ) ) ) ) ) ) , ( * ef5 ) ( ( * ef4 ) ( lf5 ( make_list ( tmp [ 4 ] ) ) ) , tmp [ 10 ] ) , ( * ef6 ) ( ( * ef36 ) ( ( * ef37 ) ( ( * ef37 ) ( ( * ef38 ) ( ( * ef39 ) ( ( constant8 ? constant8 : ( constant8 = ( * ef2 ) ( lf4 ( make_list ( ( * ef3 ) ( ( * ef4 ) ( lf5 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] ) ) ) ) ) ) ) ) ) , ( constant9 ? constant9 : ( constant9 = ( * ef40 ) ( ( * ef4 ) ( lf5 ( ( ATerm ) ATmakeList ( 6 , char_table [ 105 ] , char_table [ 110 ] , char_table [ 116 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] ) ) ) ) ) ) , ( * ef30 ) ( ( * ef31 ) ( ( * ef32 ) ( ( * ef33 ) ( ( * ef4 ) ( lf5 ( cons ( ( constant10 ? constant10 : ( constant10 = make_list_char ( 109 ) ) ) , cons ( ( constant11 ? constant11 : ( constant11 = make_list_char ( 97 ) ) ) , cons ( ( constant12 ? constant12 : ( constant12 = make_list_char ( 107 ) ) ) , cons ( ( constant13 ? constant13 : ( constant13 = make_list_char ( 101 ) ) ) , cons ( ( constant14 ? constant14 : ( constant14 = make_list_char ( 95 ) ) ) , cons ( ( constant15 ? constant15 : ( constant15 = make_list_char ( 116 ) ) ) , cons ( ( constant16 ? constant16 : ( constant16 = make_list_char ( 117 ) ) ) , cons ( ( constant17 ? constant17 : ( constant17 = make_list_char ( 112 ) ) ) , cons ( ( constant18 ? constant18 : ( constant18 = make_list_char ( 108 ) ) ) , cons ( ( constant13 ? constant13 : ( constant13 = make_list_char ( 101 ) ) ) , make_list ( tmp [ 36 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ) , tmp [ 11 ] ) ) ) ) ) , ( * ef39 ) ( ( constant19 ? constant19 : ( constant19 = ( * ef2 ) ( lf4 ( make_list ( ( * ef3 ) ( ( * ef4 ) ( lf5 ( ( ATerm ) ATmakeList ( 10 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] , char_table [ 84 ] , char_table [ 97 ] , char_table [ 98 ] , char_table [ 108 ] , char_table [ 101 ] ) ) ) ) ) ) ) ) ) , ( constant20 ? constant20 : ( constant20 = ( * ef40 ) ( ( * ef4 ) ( lf5 ( ( ATerm ) ATmakeList ( 5 , char_table [ 116 ] , char_table [ 97 ] , char_table [ 98 ] , char_table [ 108 ] , char_table [ 101 ] ) ) ) ) ) ) , ( * ef30 ) ( ( * ef31 ) ( ( * ef32 ) ( ( constant21 ? constant21 : ( constant21 = ( * ef33 ) ( ( * ef4 ) ( lf5 ( ( ATerm ) ATmakeList ( 9 , char_table [ 103 ] , char_table [ 101 ] , char_table [ 116 ] , char_table [ 95 ] , char_table [ 116 ] , char_table [ 97 ] , char_table [ 98 ] , char_table [ 108 ] , char_table [ 101 ] ) ) ) ) ) ) , ( * ef34 ) ( lf7 ( make_list ( ( * ef30 ) ( ( * ef31 ) ( ( * ef33 ) ( ( * ef4 ) ( lf5 ( cons ( ( constant15 ? constant15 : ( constant15 = make_list_char ( 116 ) ) ) , cons ( ( constant11 ? constant11 : ( constant11 = make_list_char ( 97 ) ) ) , cons ( ( constant22 ? constant22 : ( constant22 = make_list_char ( 98 ) ) ) , cons ( ( constant18 ? constant18 : ( constant18 = make_list_char ( 108 ) ) ) , cons ( ( constant13 ? constant13 : ( constant13 = make_list_char ( 101 ) ) ) , cons ( ( constant14 ? constant14 : ( constant14 = make_list_char ( 95 ) ) ) , make_list ( tmp [ 4 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( constant23 ? constant23 : ( constant23 = ( * ef39 ) ( ( * ef2 ) ( lf4 ( make_list ( ( * ef3 ) ( ( * ef4 ) ( lf5 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] ) ) ) ) ) ) ) , ( * ef40 ) ( ( * ef4 ) ( lf5 ( ( ATerm ) ATmakeList ( 6 , char_table [ 114 ] , char_table [ 101 ] , char_table [ 115 ] , char_table [ 117 ] , char_table [ 108 ] , char_table [ 116 ] ) ) ) ) , ( * ef30 ) ( ( * ef31 ) ( ( * ef32 ) ( ( * ef33 ) ( ( * ef4 ) ( lf5 ( ( ATerm ) ATmakeList ( 10 , char_table [ 103 ] , char_table [ 101 ] , char_table [ 116 ] , char_table [ 95 ] , char_table [ 114 ] , char_table [ 101 ] , char_table [ 115 ] , char_table [ 117 ] , char_table [ 108 ] , char_table [ 116 ] ) ) ) ) , ( * ef34 ) ( lf7 ( cons ( make_list ( ( * ef30 ) ( ( * ef31 ) ( ( * ef33 ) ( ( * ef4 ) ( lf5 ( ( ATerm ) ATmakeList ( 5 , char_table [ 116 ] , char_table [ 97 ] , char_table [ 98 ] , char_table [ 108 ] , char_table [ 101 ] ) ) ) ) ) ) ) , make_list ( ( * ef30 ) ( ( * ef31 ) ( ( * ef33 ) ( ( * ef4 ) ( lf5 ( ( ATerm ) ATmakeList ( 6 , char_table [ 105 ] , char_table [ 110 ] , char_table [ 116 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef27 ) ( ( * ef28 ) ( ( * ef41 ) ( ( constant24 ? constant24 : ( constant24 = ( * ef30 ) ( ( * ef31 ) ( ( * ef33 ) ( ( * ef4 ) ( lf5 ( ( ATerm ) ATmakeList ( 6 , char_table [ 114 ] , char_table [ 101 ] , char_table [ 115 ] , char_table [ 117 ] , char_table [ 108 ] , char_table [ 116 ] ) ) ) ) ) ) ) ) , ( constant25 ? constant25 : ( constant25 = ( * ef42 ) ( ( * ef30 ) ( ( * ef31 ) ( ( * ef33 ) ( ( * ef4 ) ( lf5 ( ( ATerm ) ATmakeList ( 6 , char_table [ 114 ] , char_table [ 101 ] , char_table [ 115 ] , char_table [ 117 ] , char_table [ 108 ] , char_table [ 116 ] ) ) ) ) ) ) ) ) ) , ( * ef6 ) ( ( constant26 ? constant26 : ( constant26 = ( * ef7 ) ( ) ) ) , tmp [ 33 ] ) ) ) ) ) ) ;
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
if ( term_equal ( tmp [ 5 ] , ( constant27 ? constant27 : ( constant27 = ( * ef11 ) ( ) ) ) ) ) {
tmp [ 6 ] = ( * ef12 ) ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 6 ] , ef13sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf6sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
tmp [ 9 ] = ( * ef14 ) ( lf6 ( make_list ( tmp [ 8 ] ) ) , ( constant1 ? constant1 : ( constant1 = ( * ef15 ) ( ( * ef16 ) ( lf5 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 9 ] , ef17sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
tmp [ 11 ] = arg_1 ( tmp [ 9 ] ) ;
tmp [ 12 ] = arg_2 ( tmp [ 9 ] ) ;
tmp [ 13 ] = ( * ef18 ) ( lf_AUX_MuASF_Rules2C7_1 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 13 ] , ef19sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 13 ] ) ;
tmp [ 15 ] = arg_1 ( tmp [ 13 ] ) ;
if ( check_sym ( tmp [ 14 ] , lf_AUX_MuASF_Rules2C7_1sym ) ) {
tmp [ 16 ] = arg_0 ( tmp [ 14 ] ) ;
if ( check_sym ( tmp [ 15 ] , lf_AUX_MuASF_Rules2C7_1sym ) ) {
tmp [ 17 ] = arg_0 ( tmp [ 15 ] ) ;
tmp [ 18 ] = ( * ef20 ) ( lf_AUX_MuASF_Rules2C7_1 ( make_list ( tmp [ 17 ] ) ) , lf_AUX_MuASF_Rules2C7_2 ( make_list ( atmp10 ) ) ) ;
if ( check_sym ( tmp [ 18 ] , ef21sym ) ) {
tmp [ 19 ] = arg_0 ( tmp [ 18 ] ) ;
tmp [ 20 ] = arg_1 ( tmp [ 18 ] ) ;
tmp [ 21 ] = ( * ef20 ) ( lf_AUX_MuASF_Rules2C7_1 ( make_list ( tmp [ 16 ] ) ) , lf_AUX_MuASF_Rules2C7_2 ( make_list ( atmp10 ) ) ) ;
if ( check_sym ( tmp [ 21 ] , ef21sym ) ) {
tmp [ 22 ] = arg_0 ( tmp [ 21 ] ) ;
tmp [ 23 ] = arg_1 ( tmp [ 21 ] ) ;
tmp [ 24 ] = ( * ef22 ) ( ( * ef9 ) ( lf5 ( make_list ( tmp [ 4 ] ) ) ) , tmp [ 11 ] , tmp [ 12 ] ) ;
if ( check_sym ( tmp [ 24 ] , ef21sym ) ) {
tmp [ 25 ] = arg_0 ( tmp [ 24 ] ) ;
tmp [ 26 ] = arg_1 ( tmp [ 24 ] ) ;
tmp [ 27 ] = ( * ef23 ) ( tmp [ 20 ] , tmp [ 23 ] ) ;
tmp [ 28 ] = ( * ef23 ) ( tmp [ 26 ] , tmp [ 27 ] ) ;
tmp [ 29 ] = ( * ef24 ) ( tmp [ 28 ] ) ;
tmp [ 30 ] = ( * ef25 ) ( tmp [ 19 ] , tmp [ 22 ] ) ;
tmp [ 31 ] = ( * ef26 ) ( tmp [ 30 ] , tmp [ 25 ] ) ;
tmp [ 32 ] = ( * ef25 ) ( ( * ef27 ) ( ( * ef28 ) ( ( * ef29 ) ( ( * ef30 ) ( ( * ef31 ) ( ( * ef32 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef33 ) ( ( * ef4 ) ( lf5 ( cons ( make_list ( make_char ( 80 ) ) , cons ( make_list ( make_char ( 82 ) ) , cons ( make_list ( make_char ( 79 ) ) , make_list ( make_char ( 70 ) ) ) ) ) ) ) ) ) ) , ( * ef34 ) ( lf7 ( make_list ( ( * ef30 ) ( ( * ef31 ) ( ( * ef33 ) ( ( * ef4 ) ( lf5 ( cons ( ( constant3 ? constant3 : ( constant3 = make_list ( make_char ( 112 ) ) ) ) , cons ( ( constant4 ? constant4 : ( constant4 = make_list ( make_char ( 114 ) ) ) ) , cons ( ( constant5 ? constant5 : ( constant5 = make_list ( make_char ( 111 ) ) ) ) , cons ( ( constant6 ? constant6 : ( constant6 = make_list ( make_char ( 102 ) ) ) ) , cons ( ( constant7 ? constant7 : ( constant7 = make_list ( make_char ( 95 ) ) ) ) , make_list ( tmp [ 4 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , tmp [ 31 ] ) ;
tmp [ 33 ] = ( * ef35 ) ( tmp [ 29 ] , tmp [ 32 ] ) ;
return ( * ef1 ) ( ( constant8 ? constant8 : ( constant8 = ( * ef2 ) ( lf4 ( make_list ( ( * ef3 ) ( ( * ef4 ) ( lf5 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] ) ) ) ) ) ) ) ) ) , ( * ef5 ) ( ( * ef4 ) ( lf5 ( make_list ( tmp [ 4 ] ) ) ) , tmp [ 10 ] ) , ( * ef6 ) ( ( constant26 ? constant26 : ( constant26 = ( * ef7 ) ( ) ) ) , tmp [ 33 ] ) ) ;
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
if ( term_equal ( ( * ef12 ) ( tmp [ 0 ] ) , ( constant28 ? constant28 : ( constant28 = ( * ef13 ) ( lf6 ( make_list ( null ( ) ) ) ) ) ) ) ) {
tmp [ 6 ] = ( * ef20 ) ( lf_AUX_MuASF_Rules2C7_1 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( tmp [ 1 ] ) ) ) , lf_AUX_MuASF_Rules2C7_2 ( make_list ( atmp10 ) ) ) ;
if ( check_sym ( tmp [ 6 ] , ef21sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
tmp [ 8 ] = arg_1 ( tmp [ 6 ] ) ;
tmp [ 9 ] = ( * ef22 ) ( ( * ef9 ) ( lf5 ( make_list ( tmp [ 4 ] ) ) ) , ( constant29 ? constant29 : ( constant29 = ( * ef34 ) ( lf7 ( make_list ( null ( ) ) ) ) ) ) , ( constant1 ? constant1 : ( constant1 = ( * ef15 ) ( ( * ef16 ) ( lf5 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 9 ] , ef21sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
tmp [ 11 ] = arg_1 ( tmp [ 9 ] ) ;
tmp [ 12 ] = ( * ef23 ) ( tmp [ 8 ] , tmp [ 11 ] ) ;
tmp [ 13 ] = ( * ef24 ) ( tmp [ 12 ] ) ;
tmp [ 14 ] = ( * ef26 ) ( tmp [ 7 ] , tmp [ 10 ] ) ;
tmp [ 15 ] = ( * ef25 ) ( ( * ef27 ) ( ( * ef28 ) ( ( * ef29 ) ( ( * ef30 ) ( ( * ef31 ) ( ( * ef32 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef33 ) ( ( * ef4 ) ( lf5 ( cons ( make_list ( make_char ( 80 ) ) , cons ( make_list ( make_char ( 82 ) ) , cons ( make_list ( make_char ( 79 ) ) , make_list ( make_char ( 70 ) ) ) ) ) ) ) ) ) ) , ( * ef34 ) ( lf7 ( make_list ( ( * ef30 ) ( ( * ef31 ) ( ( * ef33 ) ( ( * ef4 ) ( lf5 ( cons ( ( constant3 ? constant3 : ( constant3 = make_list ( make_char ( 112 ) ) ) ) , cons ( ( constant4 ? constant4 : ( constant4 = make_list ( make_char ( 114 ) ) ) ) , cons ( ( constant5 ? constant5 : ( constant5 = make_list ( make_char ( 111 ) ) ) ) , cons ( ( constant6 ? constant6 : ( constant6 = make_list ( make_char ( 102 ) ) ) ) , cons ( ( constant7 ? constant7 : ( constant7 = make_list ( make_char ( 95 ) ) ) ) , make_list ( tmp [ 4 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , tmp [ 14 ] ) ;
tmp [ 16 ] = ( * ef35 ) ( tmp [ 13 ] , tmp [ 15 ] ) ;
return ( * ef1 ) ( ( constant8 ? constant8 : ( constant8 = ( * ef2 ) ( lf4 ( make_list ( ( * ef3 ) ( ( * ef4 ) ( lf5 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] ) ) ) ) ) ) ) ) ) , ( * ef5 ) ( ( * ef4 ) ( lf5 ( make_list ( tmp [ 4 ] ) ) ) , ( constant30 ? constant30 : ( constant30 = ( * ef44 ) ( lf8 ( make_list ( null ( ) ) ) ) ) ) ) , ( * ef6 ) ( ( constant26 ? constant26 : ( constant26 = ( * ef7 ) ( ) ) ) , tmp [ 16 ] ) ) ;
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
return make_nf2 ( lf_AUX_MuASF_Rules2C7_3sym , arg0 , arg1 ) ;
}
}
ATerm lf5 ( ATerm arg0 ) {
PROF ( prof_lf5 ) ;
return make_nf1 ( lf5sym , arg0 ) ;
}
ATerm lf7 ( ATerm arg0 ) {
PROF ( prof_lf7 ) ;
return make_nf1 ( lf7sym , arg0 ) ;
}
ATerm lf_AUX_MuASF_Rules2C7_2 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_MuASF_Rules2C7_2 ) ;
return make_nf1 ( lf_AUX_MuASF_Rules2C7_2sym , arg0 ) ;
}
ATerm lf_AUX_MuASF_Rules2C7_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_MuASF_Rules2C7_1 ) ;
return make_nf1 ( lf_AUX_MuASF_Rules2C7_1sym , arg0 ) ;
}
ATerm lf6 ( ATerm arg0 ) {
PROF ( prof_lf6 ) ;
return make_nf1 ( lf6sym , arg0 ) ;
}
ATerm lf8 ( ATerm arg0 ) {
PROF ( prof_lf8 ) ;
return make_nf1 ( lf8sym , arg0 ) ;
}
ATerm lf4 ( ATerm arg0 ) {
PROF ( prof_lf4 ) ;
return make_nf1 ( lf4sym , arg0 ) ;
}

