#include "support.h"
static Symbol lf_AUX_MuASF_Term2C7_3sym;
static ATerm lf_AUX_MuASF_Term2C7_3( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol ef8sym;
static funcptr ef8;
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef12sym;
static funcptr ef12;
static Symbol ef13sym;
static funcptr ef13;
static Symbol ef14sym;
static funcptr ef14;
static Symbol ef15sym;
static funcptr ef15;
static Symbol ef16sym;
static funcptr ef16;
static Symbol ef6sym;
static funcptr ef6;
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef10sym;
static funcptr ef10;
static Symbol ef11sym;
static funcptr ef11;
static Symbol ef17sym;
static funcptr ef17;
static Symbol ef18sym;
static funcptr ef18;
static Symbol ef19sym;
static funcptr ef19;
static Symbol ef20sym;
static funcptr ef20;
static Symbol ef9sym;
static funcptr ef9;
static Symbol ef21sym;
static funcptr ef21;
static Symbol lf_AUX_MuASF_Term2C7_2sym;
static ATerm lf_AUX_MuASF_Term2C7_2( ATerm arg1);
static Symbol ef22sym;
static funcptr ef22;
static Symbol ef23sym;
static funcptr ef23;
static Symbol lf8sym;
static ATerm lf8( ATerm arg1);
static Symbol ef24sym;
static funcptr ef24;
static Symbol ef25sym;
static funcptr ef25;
static Symbol ef26sym;
static funcptr ef26;
static Symbol ef27sym;
static funcptr ef27;
static Symbol ef28sym;
static funcptr ef28;
static Symbol ef29sym;
static funcptr ef29;
static Symbol lf9sym;
static ATerm lf9( ATerm arg1);
static Symbol ef30sym;
static funcptr ef30;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf4sym;
static ATerm lf4( ATerm arg1);
static Symbol lf5sym;
static ATerm lf5( ATerm arg1);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef3sym;
static funcptr ef3;
static Symbol lf6sym;
static ATerm lf6( ATerm arg1);
static Symbol ef4sym;
static funcptr ef4;
static Symbol lf7sym;
static ATerm lf7( ATerm arg1);
static Symbol ef31sym;
static funcptr ef31;
static Symbol lf_AUX_MuASF_Term2C7_1sym;
static ATerm lf_AUX_MuASF_Term2C7_1( ATerm arg1);
void register_AUX_MuASF_Term2C7( ) {
lf_AUX_MuASF_Term2C7_3sym= ATmakeSymbol( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"second-term-common\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)"
 , 3 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Term2C7_3sym);
lf_AUX_MuASF_Term2C7_2sym= ATmakeSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Term2C7_2sym);
lf8sym= ATmakeSymbol( "listtype(sort(\"Expression\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf8sym);
lf9sym= ATmakeSymbol( "listtype(sort(\"TE-pair\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf9sym);
lf4sym= ATmakeSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf4sym);
lf5sym= ATmakeSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue);
ATprotectSymbol( lf5sym);
lf6sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf6sym);
lf7sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf7sym);
lf_AUX_MuASF_Term2C7_1sym= ATmakeSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Term2C7_1sym);
register_prod( ATparse( "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_MuASF_Term2C7_1 , lf_AUX_MuASF_Term2C7_1sym);
register_prod( ATparse( "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Term2C7_2 , lf_AUX_MuASF_Term2C7_2sym);
register_prod( ATparse( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"second-term-common\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Term2C7_3 , lf_AUX_MuASF_Term2C7_3sym);
register_prod( ATparse( "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( ATparse( "listtype(sort(\"Cond\"),ql(\"&\"))") , lf5 , lf5sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf6 , lf6sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf7 , lf7sym);
register_prod( ATparse( "listtype(sort(\"Expression\"),ql(\",\"))") , lf8 , lf8sym);
register_prod( ATparse( "listtype(sort(\"TE-pair\"),ql(\",\"))") , lf9 , lf9sym);
}
void resolve_AUX_MuASF_Term2C7( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef9= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef10= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-conds-on-second-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-conds-on-second-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef11= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef12= lookup_func( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef12sym= lookup_sym( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef13= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef14= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef15= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef16= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef17= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef18= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)"));
ef19= lookup_func( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-temp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-temp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef20= lookup_func( ATreadFromString( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"term2carg\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"term2carg\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"));
ef21= lookup_func( ATreadFromString( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( ATreadFromString( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef22= lookup_func( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"));
ef22sym= lookup_sym( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)"));
ef23= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef23sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef24= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef24sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef25= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef25sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef26= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef26sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef27= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"varid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)"));
ef27sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"varid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)"));
ef28= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"replace-second-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef28sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"replace-second-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef29= lookup_func( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef29sym= lookup_sym( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)"));
ef30= lookup_func( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)"));
ef30sym= lookup_sym( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)"));
ef31= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef31sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
static ATerm constant3= NULL;
static ATerm constant4= NULL;
static ATerm constant5= NULL;
static ATerm constant6= NULL;
void init_AUX_MuASF_Term2C7( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
ATprotect( & constant3);
ATprotect( & constant4);
ATprotect( & constant5);
ATprotect( & constant6);
}
ATerm lf_AUX_MuASF_Term2C7_3( ATerm arg0 , ATerm arg1 , ATerm arg2) {
{
ATerm tmp[60];
PROF( prof_lf_AUX_MuASF_Term2C7_3);
if( check_sym( arg0 , lf_AUX_MuASF_Term2C7_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( arg1 , lf_AUX_MuASF_Term2C7_2sym)) {
{
ATerm atmp10= arg_0( arg1);
if( not_empty_list( atmp00)) {
tmp[ 0]= list_head( atmp00);
{
tmp[ 1]= list_tail( atmp00);
{
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
tmp[ 4]= arg_2( tmp[ 0]);
tmp[ 5]= arg_3( tmp[ 0]);
tmp[ 6]= arg_4( tmp[ 0]);
{
if( check_sym( tmp[ 2] , lf4sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
{
if( check_sym( tmp[ 3] , lf5sym)) {
tmp[ 8]= arg_0( tmp[ 3]);
{
if( not_empty_list( tmp[ 8])) {
tmp[ 9]= list_head( tmp[ 8]);
{
tmp[ 10]= list_tail( tmp[ 8]);
{
if( check_sym( tmp[ 9] , ef2sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
tmp[ 12]= arg_1( tmp[ 9]);
{
if( check_sym( tmp[ 11] , ef3sym)) {
tmp[ 13]= arg_0( tmp[ 11]);
tmp[ 14]= arg_1( tmp[ 11]);
{
if( check_sym( tmp[ 13] , ef4sym)) {
tmp[ 15]= arg_0( tmp[ 13]);
{
if( check_sym( tmp[ 15] , lf6sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
{
if( check_sym( tmp[ 14] , lf7sym)) {
tmp[ 17]= arg_0( tmp[ 14]);
{
if( not_empty_list( tmp[ 16])) {
tmp[ 18]= list_head( tmp[ 16]);
if( term_equal( tmp[ 18] , make_char( 116))) {
tmp[ 19]= list_tail( tmp[ 16]);
{
if( not_empty_list( tmp[ 19])) {
tmp[ 20]= list_head( tmp[ 19]);
if( term_equal( tmp[ 20] , make_char( 101))) {
tmp[ 21]= list_tail( tmp[ 19]);
{
if( not_empty_list( tmp[ 21])) {
tmp[ 22]= list_head( tmp[ 21]);
if( term_equal( tmp[ 22] , make_char( 114))) {
tmp[ 23]= list_tail( tmp[ 21]);
{
if( not_empty_list( tmp[ 23])) {
tmp[ 24]= list_head( tmp[ 23]);
if( term_equal( tmp[ 24] , make_char( 109))) {
tmp[ 25]= list_tail( tmp[ 23]);
{
if( not_empty_list( tmp[ 25])) {
tmp[ 26]= list_head( tmp[ 25]);
if( term_equal( tmp[ 26] , make_char( 45))) {
tmp[ 27]= list_tail( tmp[ 25]);
{
if( not_empty_list( tmp[ 27])) {
tmp[ 28]= list_head( tmp[ 27]);
if( term_equal( tmp[ 28] , make_char( 101))) {
tmp[ 29]= list_tail( tmp[ 27]);
{
if( not_empty_list( tmp[ 29])) {
tmp[ 30]= list_head( tmp[ 29]);
if( term_equal( tmp[ 30] , make_char( 113))) {
tmp[ 31]= list_tail( tmp[ 29]);
{
if( not_empty_list( tmp[ 31])) {
tmp[ 32]= list_head( tmp[ 31]);
if( term_equal( tmp[ 32] , make_char( 117))) {
tmp[ 33]= list_tail( tmp[ 31]);
{
if( not_empty_list( tmp[ 33])) {
tmp[ 34]= list_head( tmp[ 33]);
if( term_equal( tmp[ 34] , make_char( 97))) {
tmp[ 35]= list_tail( tmp[ 33]);
{
if( is_single_element( tmp[ 35])) {
tmp[ 36]= list_head( tmp[ 35]);
if( term_equal( tmp[ 36] , make_char( 108))) {
if( not_empty_list( tmp[ 17])) {
tmp[ 37]= list_head( tmp[ 17]);
{
tmp[ 38]= list_tail( tmp[ 17]);
{
if( is_single_element( tmp[ 38])) {
tmp[ 39]= list_head( tmp[ 38]);
tmp[ 40]= ( * ef7)( tmp[ 39]);
if( term_equal( tmp[ 40] , ( constant0? constant0: ( constant0= ( * ef9)( ))))) {
tmp[ 41]= ( * ef10)( tmp[ 39] , lf_AUX_MuASF_Term2C7_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 41] , ef11sym)) {
tmp[ 42]= arg_0( tmp[ 41]);
tmp[ 43]= arg_1( tmp[ 41]);
{
if( check_sym( tmp[ 42] , lf_AUX_MuASF_Term2C7_1sym)) {
tmp[ 44]= arg_0( tmp[ 42]);
{
if( check_sym( tmp[ 43] , lf_AUX_MuASF_Term2C7_1sym)) {
tmp[ 45]= arg_0( tmp[ 43]);
{
if( not_empty_list( tmp[ 44])) {
tmp[ 46]= ( * ef17)( ( * ef18)( ( * ef19)( arg2)));
tmp[ 47]= ( * ef20)( ( constant0? constant0: ( constant0= ( * ef9)( ))) , tmp[ 39] , tmp[ 5] , tmp[ 6] , ( * ef21)( arg2) , tmp[ 46] , lf_AUX_MuASF_Term2C7_2( make_list( atmp10)));
if( check_sym( tmp[ 47] , ef22sym)) {
tmp[ 48]= arg_0( tmp[ 47]);
tmp[ 49]= arg_1( tmp[ 47]);
tmp[ 50]= arg_2( tmp[ 47]);
if( check_sym( tmp[ 48] , ef23sym)) {
tmp[ 51]= arg_0( tmp[ 48]);
if( check_sym( tmp[ 51] , lf8sym)) {
tmp[ 52]= arg_0( tmp[ 51]);
if( is_single_element( tmp[ 52])) {
tmp[ 53]= list_head( tmp[ 52]);
if( check_sym( arg2 , ef24sym)) {
tmp[ 54]= arg_0( arg2);
if( check_sym( tmp[ 54] , lf6sym)) {
tmp[ 55]= arg_0( tmp[ 54]);
tmp[ 56]= ( * ef25)( ( * ef26)( ( * ef27)( lf6( cons( ( constant1? constant1: ( constant1= make_list( make_char( 67)))) , cons( ( constant2? constant2: ( constant2= make_list( make_char( 86)))) , make_list( tmp[ 55])))))));
tmp[ 57]= ( * ef28)( tmp[ 56] , ( * ef29)( lf9( make_list( ( * ef30)( tmp[ 56] , tmp[ 46])))) , lf_AUX_MuASF_Term2C7_1( cons( make_list( ( * ef1)( lf4( make_list( tmp[ 7])) , lf5( cons( make_list( ( * ef2)( ( * ef3)( ( constant3? constant3: ( constant3= ( * ef4)( lf6( cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))))) , lf7( cons( make_list( tmp[ 37]) , make_list( tmp[ 39])))) , tmp[ 12])) , make_list( tmp[ 10]))) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 44]))));
if( check_sym( tmp[ 57] , ef31sym)) {
tmp[ 58]= arg_0( tmp[ 57]);
if( check_sym( tmp[ 58] , lf_AUX_MuASF_Term2C7_1sym)) {
tmp[ 59]= arg_0( tmp[ 58]);
if( not_empty_list( tmp[ 59])) {
return ( * ef5)( ( * ef12)( tmp[ 49] , ( * ef13)( ( * ef14)( ( * ef15)( ( * ef16)( tmp[ 46] , tmp[ 53]))))) , ( constant4? constant4: ( constant4= ( * ef6)( ))) , lf_AUX_MuASF_Term2C7_1( cons( make_list( tmp[ 59]) , make_list( tmp[ 45]))) , tmp[ 50]);
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
return ( * ef5)( ( constant4? constant4: ( constant4= ( * ef6)( ))) , ( constant4? constant4: ( constant4= ( * ef6)( ))) , lf_AUX_MuASF_Term2C7_1( cons( make_list( ( * ef1)( lf4( make_list( tmp[ 7])) , lf5( cons( make_list( ( * ef2)( ( * ef3)( ( constant5? constant5: ( constant5= ( * ef4)( lf6( (ATerm) ATmakeList( 10 , char_table[ 116] , char_table[ 101] , char_table[ 114] , char_table[ 109] , char_table[ 45] , char_table[ 101] , char_table[ 113] , char_table[ 117] , char_table[ 97] , char_table[ 108]))))) , lf7( cons( make_list( tmp[ 37]) , make_list( tmp[ 39])))) , tmp[ 12])) , make_list( tmp[ 10]))) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 1]))) , arg2);
}
}
}
}
}
}
}
}
if( term_equal( tmp[ 40] , ( constant6? constant6: ( constant6= ( * ef8)( ))))) {
return ( * ef5)( ( constant4? constant4: ( constant4= ( * ef6)( ))) , ( constant4? constant4: ( constant4= ( * ef6)( ))) , lf_AUX_MuASF_Term2C7_1( cons( make_list( ( * ef1)( lf4( make_list( tmp[ 7])) , lf5( cons( make_list( ( * ef2)( ( * ef3)( ( constant5? constant5: ( constant5= ( * ef4)( lf6( (ATerm) ATmakeList( 10 , char_table[ 116] , char_table[ 101] , char_table[ 114] , char_table[ 109] , char_table[ 45] , char_table[ 101] , char_table[ 113] , char_table[ 117] , char_table[ 97] , char_table[ 108]))))) , lf7( cons( make_list( tmp[ 37]) , make_list( tmp[ 39])))) , tmp[ 12])) , make_list( tmp[ 10]))) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 1]))) , arg2);
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
return make_nf3( lf_AUX_MuASF_Term2C7_3sym , arg0 , arg1 , arg2);
}
}
ATerm lf_AUX_MuASF_Term2C7_1( ATerm arg0) {
PROF( prof_lf_AUX_MuASF_Term2C7_1);
return make_nf1( lf_AUX_MuASF_Term2C7_1sym , arg0);
}
ATerm lf7( ATerm arg0) {
PROF( prof_lf7);
return make_nf1( lf7sym , arg0);
}
ATerm lf6( ATerm arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}
ATerm lf5( ATerm arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
ATerm lf4( ATerm arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
ATerm lf9( ATerm arg0) {
PROF( prof_lf9);
return make_nf1( lf9sym , arg0);
}
ATerm lf8( ATerm arg0) {
PROF( prof_lf8);
return make_nf1( lf8sym , arg0);
}
ATerm lf_AUX_MuASF_Term2C7_2( ATerm arg0) {
PROF( prof_lf_AUX_MuASF_Term2C7_2);
return make_nf1( lf_AUX_MuASF_Term2C7_2sym , arg0);
}

