#include  "support.h"
static Symbol lf_AUX_Regular_Sdf_Normalization3_1sym ;
static ATerm lf_AUX_Regular_Sdf_Normalization3_1 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef21sym ;
static funcptr ef21 ;
static Symbol ef23sym ;
static funcptr ef23 ;
static Symbol ef22sym ;
static funcptr ef22 ;
static Symbol ef24sym ;
static funcptr ef24 ;
static Symbol ef32sym ;
static funcptr ef32 ;
static Symbol ef25sym ;
static funcptr ef25 ;
static Symbol ef26sym ;
static funcptr ef26 ;
static Symbol ef27sym ;
static funcptr ef27 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef28sym ;
static funcptr ef28 ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef29sym ;
static funcptr ef29 ;
static Symbol ef31sym ;
static funcptr ef31 ;
static Symbol ef33sym ;
static funcptr ef33 ;
static Symbol lf6sym ;
static ATerm lf6 ( ATerm arg1 ) ;
static Symbol ef34sym ;
static funcptr ef34 ;
static Symbol ef30sym ;
static funcptr ef30 ;
static Symbol ef36sym ;
static funcptr ef36 ;
static Symbol ef37sym ;
static funcptr ef37 ;
static Symbol ef38sym ;
static funcptr ef38 ;
static Symbol ef42sym ;
static funcptr ef42 ;
static Symbol ef43sym ;
static funcptr ef43 ;
static Symbol ef41sym ;
static funcptr ef41 ;
static Symbol ef39sym ;
static funcptr ef39 ;
static Symbol ef40sym ;
static funcptr ef40 ;
static Symbol ef44sym ;
static funcptr ef44 ;
static Symbol ef46sym ;
static funcptr ef46 ;
static Symbol ef48sym ;
static funcptr ef48 ;
static Symbol ef45sym ;
static funcptr ef45 ;
static Symbol ef35sym ;
static funcptr ef35 ;
static Symbol ef49sym ;
static funcptr ef49 ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef19sym ;
static funcptr ef19 ;
static Symbol ef50sym ;
static funcptr ef50 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol lf7sym ;
static ATerm lf7 ( ATerm arg1 ) ;
static Symbol ef47sym ;
static funcptr ef47 ;
static Symbol ef20sym ;
static funcptr ef20 ;
static Symbol ef51sym ;
static funcptr ef51 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol ef52sym ;
static funcptr ef52 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Regular_Sdf_Normalization3 ( ) {
lf_AUX_Regular_Sdf_Normalization3_1sym = ATmakeSymbol ( "prod(id(\"Regular-Sdf-Normalization\"),w(\"\"),[ql(\"r[[\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Regular_Sdf_Normalization3_1sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Priority\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"Group\"),ql(\">\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf6sym = ATmakeSymbol ( "listtype(sort(\"Attribute\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf6sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Production\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf7sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf7sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Symbol\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Regular-Sdf-Normalization\"),w(\"\"),[ql(\"r[[\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) , lf_AUX_Regular_Sdf_Normalization3_1 , lf_AUX_Regular_Sdf_Normalization3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Symbol\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Production\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Priority\"),ql(\",\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Group\"),ql(\">\"))" ) , lf5 , lf5sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Attribute\"),ql(\",\"))" ) , lf6 , lf6sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf7 , lf7sym ) ;
}
void resolve_AUX_Regular_Sdf_Normalization3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Sorts-Sdf-Syntax\"),w(\"\"),[sort(\"Sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Sorts-Sdf-Syntax\"),w(\"\"),[sort(\"Sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[ql(\"(/)\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[ql(\"(/)\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Sdf-Syntax\"),w(\"\"),[ql(\"LAYOUT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Sdf-Syntax\"),w(\"\"),[ql(\"LAYOUT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"CC-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"CC-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"<START>\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"<START>\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Literals-Sdf-Syntax\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Literals-Sdf-Syntax\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"<Start>\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"<Start>\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Sdf-Syntax\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"-LEX\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Sdf-Syntax\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"-LEX\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Sdf-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"-LEX\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Sdf-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"-LEX\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Sdf-Syntax\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"-CF\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Sdf-Syntax\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"-CF\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Sdf-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"-CF\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Sdf-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"-CF\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Sdf-Syntax\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"-VAR\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Sdf-Syntax\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"-VAR\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"Label-Sdf-Syntax\"),w(\"\"),[sort(\"Literal\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"Label-Sdf-Syntax\"),w(\"\"),[sort(\"Literal\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[sort(\"Grammar\"),w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[sort(\"Grammar\"),w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[ql(\"syntax\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[ql(\"syntax\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef20 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)" ) ) ;
ef20sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)" ) ) ;
ef21 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),iter(sort(\"Symbol\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef21sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),iter(sort(\"Symbol\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef22 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef22sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef23 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Normalization\"),w(\"\"),[l(\"alt\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef23sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Normalization\"),w(\"\"),[l(\"alt\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef24 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef24sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef25 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef25sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef26 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"priorities\"),w(\"\"),sort(\"Priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef26sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"priorities\"),w(\"\"),sort(\"Priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef27 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef27sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef28 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Group\"),w(\"\"),ql(\">\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef28sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Group\"),w(\"\"),ql(\">\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef29 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Associativity\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) ) ;
ef29sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Associativity\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) ) ;
ef30 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"left\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" ) ) ;
ef30sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"left\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),w(\"\"),no-attrs)" ) ) ;
ef31 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) ) ;
ef31sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) ) ;
ef32 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef32sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef33 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Attribute\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)" ) ) ;
ef33sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Attribute\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)" ) ) ;
ef34 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Associativity\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),w(\"\"),no-attrs)" ) ) ;
ef34sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Associativity\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),w(\"\"),no-attrs)" ) ) ;
ef35 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef35sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef36 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef36sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef37 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),sort(\"NatCon\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef37sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),sort(\"NatCon\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef38 = lookup_func ( ATreadFromString ( "prod(id(\"Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\">=\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef38sym = lookup_sym ( ATreadFromString ( "prod(id(\"Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\">=\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef39 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef39sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef40 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef40sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef41 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef41sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef42 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef42sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef43 = lookup_func ( ATreadFromString ( "prod(id(\"Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\"-\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef43sym = lookup_sym ( ATreadFromString ( "prod(id(\"Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\"-\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef44 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),sort(\"NatCon\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef44sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),sort(\"NatCon\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef45 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"#\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef45sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"#\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef46 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols-Projection\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef46sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols-Projection\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef47 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef47sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef48 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Normalization\"),w(\"\"),[l(\"tup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef48sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Normalization\"),w(\"\"),[l(\"tup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef49 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"Set\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef49sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"Set\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef50 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\"=>\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef50sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\"=>\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef51 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"<<\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\">>\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef51sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"<<\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\">>\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef52 = lookup_func ( ATreadFromString ( "prod(id(\"Regular-Sdf-Normalization\"),w(\"\"),[l(\"perm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbols\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef52sym = lookup_sym ( ATreadFromString ( "prod(id(\"Regular-Sdf-Normalization\"),w(\"\"),[l(\"perm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbols\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
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
void init_AUX_Regular_Sdf_Normalization3 ( ) {
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
}
ATerm lf_AUX_Regular_Sdf_Normalization3_1 ( ATerm arg0 ) {
{
ATerm tmp [ 10 ] ;
FUNC_ENTRY ( lf_AUX_Regular_Sdf_Normalization3_1sym , ATmakeAppl ( lf_AUX_Regular_Sdf_Normalization3_1sym , arg0 ) ) ;
{
ATerm ltmp [ 1 ] ;
lbl_lf_AUX_Regular_Sdf_Normalization3_1 : ltmp [ 0 ] = arg0 ;
if ( check_sym ( ltmp [ 0 ] , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( is_single_element ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
if ( check_sym ( tmp [ 0 ] , ef11sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
FUNC_EXIT ( ( * ef12 ) ( lf_AUX_Regular_Sdf_Normalization3_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ) ) ;
}
if ( check_sym ( tmp [ 0 ] , ef13sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
arg0 = ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ;
goto lbl_lf_AUX_Regular_Sdf_Normalization3_1 ;
}
if ( check_sym ( tmp [ 0 ] , ef14sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
arg0 = ( * ef1 ) ( lf2 ( make_list ( tmp [ 2 ] ) ) ) ;
goto lbl_lf_AUX_Regular_Sdf_Normalization3_1 ;
}
if ( check_sym ( tmp [ 0 ] , ef21sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 2 ] , lf2sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
tmp [ 4 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( cons ( make_list ( tmp [ 1 ] ) , make_list ( tmp [ 3 ] ) ) ) ) , ( * ef21 ) ( tmp [ 1 ] , lf2 ( make_list ( tmp [ 3 ] ) ) ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
FUNC_EXIT ( ( * ef15 ) ( ( * ef17 ) ( ( * ef18 ) ( lf3 ( make_list ( tmp [ 4 ] ) ) ) ) , lf_AUX_Regular_Sdf_Normalization3_1 ( ( * ef1 ) ( lf2 ( cons ( make_list ( tmp [ 1 ] ) , make_list ( tmp [ 3 ] ) ) ) ) ) ) ) ;
}
}
}
if ( check_sym ( tmp [ 0 ] , ef22sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
FUNC_EXIT ( ( * ef23 ) ( ( * ef22 ) ( tmp [ 1 ] , tmp [ 2 ] ) , ( * ef22 ) ( tmp [ 1 ] , tmp [ 2 ] ) ) ) ;
}
if ( check_sym ( tmp [ 0 ] , ef24sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = ( * ef19 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) ) ) ) , ( * ef24 ) ( tmp [ 1 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
tmp [ 3 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) , ( * ef24 ) ( tmp [ 1 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
FUNC_EXIT ( ( * ef15 ) ( ( * ef17 ) ( ( * ef18 ) ( lf3 ( cons ( make_list ( tmp [ 2 ] ) , make_list ( tmp [ 3 ] ) ) ) ) ) , lf_AUX_Regular_Sdf_Normalization3_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ) ) ;
}
if ( check_sym ( tmp [ 0 ] , ef25sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) , ( * ef32 ) ( tmp [ 1 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
tmp [ 3 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef32 ) ( tmp [ 1 ] ) ) , make_list ( ( * ef32 ) ( tmp [ 1 ] ) ) ) ) ) , ( * ef32 ) ( tmp [ 1 ] ) , ( constant2 ? constant2 : ( constant2 = ( * ef33 ) ( lf6 ( make_list ( ( * ef34 ) ( ( * ef30 ) ( ) ) ) ) ) ) ) ) ;
tmp [ 4 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef32 ) ( tmp [ 1 ] ) ) , make_list ( ( * ef25 ) ( tmp [ 1 ] ) ) ) ) ) , ( * ef32 ) ( tmp [ 1 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
tmp [ 5 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef25 ) ( tmp [ 1 ] ) ) , make_list ( ( * ef32 ) ( tmp [ 1 ] ) ) ) ) ) , ( * ef32 ) ( tmp [ 1 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
tmp [ 6 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef25 ) ( tmp [ 1 ] ) ) , make_list ( ( * ef25 ) ( tmp [ 1 ] ) ) ) ) ) , ( * ef25 ) ( tmp [ 1 ] ) , ( constant2 ? constant2 : ( constant2 = ( * ef33 ) ( lf6 ( make_list ( ( * ef34 ) ( ( * ef30 ) ( ) ) ) ) ) ) ) ) ;
tmp [ 7 ] = ( * ef19 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) ) ) ) , ( * ef25 ) ( tmp [ 1 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
tmp [ 8 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( make_list ( ( * ef32 ) ( tmp [ 1 ] ) ) ) ) , ( * ef25 ) ( tmp [ 1 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
FUNC_EXIT ( ( * ef15 ) ( ( * ef15 ) ( ( * ef17 ) ( ( * ef18 ) ( lf3 ( cons ( make_list ( tmp [ 2 ] ) , cons ( make_list ( tmp [ 3 ] ) , cons ( make_list ( tmp [ 4 ] ) , cons ( make_list ( tmp [ 5 ] ) , cons ( make_list ( tmp [ 6 ] ) , cons ( make_list ( tmp [ 7 ] ) , make_list ( tmp [ 8 ] ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( ( * ef27 ) ( lf4 ( make_list ( ( * ef28 ) ( lf5 ( cons ( make_list ( ( * ef29 ) ( ( * ef30 ) ( ) , ( * ef18 ) ( lf3 ( cons ( make_list ( tmp [ 3 ] ) , cons ( make_list ( tmp [ 4 ] ) , cons ( make_list ( tmp [ 5 ] ) , make_list ( tmp [ 6 ] ) ) ) ) ) ) ) ) , make_list ( ( * ef31 ) ( ( * ef18 ) ( lf3 ( cons ( make_list ( tmp [ 7 ] ) , make_list ( tmp [ 8 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ) , lf_AUX_Regular_Sdf_Normalization3_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ) ) ;
}
if ( check_sym ( tmp [ 0 ] , ef32sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
arg0 = ( * ef1 ) ( lf2 ( make_list ( ( * ef25 ) ( tmp [ 1 ] ) ) ) ) ;
goto lbl_lf_AUX_Regular_Sdf_Normalization3_1 ;
}
if ( check_sym ( tmp [ 0 ] , ef35sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 3 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) , ( * ef36 ) ( tmp [ 1 ] , tmp [ 2 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
tmp [ 4 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef36 ) ( tmp [ 1 ] , tmp [ 2 ] ) ) , cons ( make_list ( tmp [ 2 ] ) , make_list ( ( * ef36 ) ( tmp [ 1 ] , tmp [ 2 ] ) ) ) ) ) ) , ( * ef36 ) ( tmp [ 1 ] , tmp [ 2 ] ) , ( constant2 ? constant2 : ( constant2 = ( * ef33 ) ( lf6 ( make_list ( ( * ef34 ) ( ( * ef30 ) ( ) ) ) ) ) ) ) ) ;
tmp [ 5 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef36 ) ( tmp [ 1 ] , tmp [ 2 ] ) ) , cons ( make_list ( tmp [ 2 ] ) , make_list ( ( * ef35 ) ( tmp [ 1 ] , tmp [ 2 ] ) ) ) ) ) ) , ( * ef36 ) ( tmp [ 1 ] , tmp [ 2 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
tmp [ 6 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef35 ) ( tmp [ 1 ] , tmp [ 2 ] ) ) , cons ( make_list ( tmp [ 2 ] ) , make_list ( ( * ef36 ) ( tmp [ 1 ] , tmp [ 2 ] ) ) ) ) ) ) , ( * ef36 ) ( tmp [ 1 ] , tmp [ 2 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
tmp [ 7 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef35 ) ( tmp [ 1 ] , tmp [ 2 ] ) ) , cons ( make_list ( tmp [ 2 ] ) , make_list ( ( * ef35 ) ( tmp [ 1 ] , tmp [ 2 ] ) ) ) ) ) ) , ( * ef35 ) ( tmp [ 1 ] , tmp [ 2 ] ) , ( constant2 ? constant2 : ( constant2 = ( * ef33 ) ( lf6 ( make_list ( ( * ef34 ) ( ( * ef30 ) ( ) ) ) ) ) ) ) ) ;
tmp [ 8 ] = ( * ef19 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) ) ) ) , ( * ef35 ) ( tmp [ 1 ] , tmp [ 2 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
tmp [ 9 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( make_list ( ( * ef36 ) ( tmp [ 1 ] , tmp [ 2 ] ) ) ) ) , ( * ef35 ) ( tmp [ 1 ] , tmp [ 2 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
FUNC_EXIT ( ( * ef15 ) ( ( * ef15 ) ( ( * ef17 ) ( ( * ef18 ) ( lf3 ( cons ( make_list ( tmp [ 3 ] ) , cons ( make_list ( tmp [ 4 ] ) , cons ( make_list ( tmp [ 5 ] ) , cons ( make_list ( tmp [ 6 ] ) , cons ( make_list ( tmp [ 7 ] ) , cons ( make_list ( tmp [ 8 ] ) , make_list ( tmp [ 9 ] ) ) ) ) ) ) ) ) ) ) , ( * ef26 ) ( ( * ef27 ) ( lf4 ( make_list ( ( * ef28 ) ( lf5 ( cons ( make_list ( ( * ef29 ) ( ( * ef30 ) ( ) , ( * ef18 ) ( lf3 ( cons ( make_list ( tmp [ 4 ] ) , cons ( make_list ( tmp [ 5 ] ) , cons ( make_list ( tmp [ 6 ] ) , make_list ( tmp [ 7 ] ) ) ) ) ) ) ) ) , make_list ( ( * ef31 ) ( ( * ef18 ) ( lf3 ( cons ( make_list ( tmp [ 8 ] ) , make_list ( tmp [ 9 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ) , lf_AUX_Regular_Sdf_Normalization3_1 ( ( * ef1 ) ( lf2 ( cons ( make_list ( tmp [ 1 ] ) , make_list ( tmp [ 2 ] ) ) ) ) ) ) ) ;
}
if ( check_sym ( tmp [ 0 ] , ef36sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
arg0 = ( * ef1 ) ( lf2 ( make_list ( ( * ef35 ) ( tmp [ 1 ] , tmp [ 2 ] ) ) ) ) ;
goto lbl_lf_AUX_Regular_Sdf_Normalization3_1 ;
}
if ( check_sym ( tmp [ 0 ] , ef37sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
if ( term_equal ( ( * ef38 ) ( ( * ef39 ) ( ( * ef40 ) ( tmp [ 2 ] ) ) , ( constant3 ? constant3 : ( constant3 = ( * ef39 ) ( ( * ef40 ) ( ( * ef41 ) ( lf7 ( make_list ( make_char ( 50 ) ) ) ) ) ) ) ) ) , ( constant4 ? constant4 : ( constant4 = ( * ef42 ) ( ) ) ) ) ) {
tmp [ 3 ] = ( * ef43 ) ( ( * ef39 ) ( ( * ef40 ) ( tmp [ 2 ] ) ) , ( constant5 ? constant5 : ( constant5 = ( * ef39 ) ( ( * ef40 ) ( ( * ef41 ) ( lf7 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 3 ] , ef39sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef40sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
tmp [ 6 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( cons ( make_list ( tmp [ 1 ] ) , make_list ( ( * ef37 ) ( tmp [ 1 ] , tmp [ 5 ] ) ) ) ) ) , ( * ef37 ) ( tmp [ 1 ] , tmp [ 2 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
FUNC_EXIT ( ( * ef15 ) ( ( * ef17 ) ( ( * ef18 ) ( lf3 ( make_list ( tmp [ 6 ] ) ) ) ) , lf_AUX_Regular_Sdf_Normalization3_1 ( ( * ef1 ) ( lf2 ( make_list ( ( * ef37 ) ( tmp [ 1 ] , tmp [ 5 ] ) ) ) ) ) ) ) ;
}
}
}
}
if ( check_sym ( tmp [ 0 ] , ef44sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_2 ( tmp [ 0 ] ) ;
if ( term_equal ( ( * ef38 ) ( ( * ef39 ) ( ( * ef40 ) ( tmp [ 3 ] ) ) , ( constant3 ? constant3 : ( constant3 = ( * ef39 ) ( ( * ef40 ) ( ( * ef41 ) ( lf7 ( make_list ( make_char ( 50 ) ) ) ) ) ) ) ) ) , ( constant4 ? constant4 : ( constant4 = ( * ef42 ) ( ) ) ) ) ) {
tmp [ 4 ] = ( * ef43 ) ( ( * ef39 ) ( ( * ef40 ) ( tmp [ 3 ] ) ) , ( constant5 ? constant5 : ( constant5 = ( * ef39 ) ( ( * ef40 ) ( ( * ef41 ) ( lf7 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 4 ] , ef39sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 5 ] , ef40sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
tmp [ 7 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( cons ( make_list ( tmp [ 1 ] ) , cons ( make_list ( tmp [ 2 ] ) , make_list ( ( * ef44 ) ( tmp [ 1 ] , tmp [ 2 ] , tmp [ 6 ] ) ) ) ) ) ) , ( * ef44 ) ( tmp [ 1 ] , tmp [ 2 ] , tmp [ 3 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
FUNC_EXIT ( ( * ef15 ) ( ( * ef17 ) ( ( * ef18 ) ( lf3 ( make_list ( tmp [ 7 ] ) ) ) ) , lf_AUX_Regular_Sdf_Normalization3_1 ( ( * ef1 ) ( lf2 ( make_list ( ( * ef44 ) ( tmp [ 1 ] , tmp [ 2 ] , tmp [ 6 ] ) ) ) ) ) ) ) ;
}
}
}
}
if ( check_sym ( tmp [ 0 ] , ef45sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 3 ] = ( * ef46 ) ( ( * ef46 ) ( ( constant6 ? constant6 : ( constant6 = ( * ef1 ) ( lf2 ( make_list ( ( * ef7 ) ( ( * ef47 ) ( lf7 ( cons ( make_list ( make_char ( 34 ) ) , cons ( make_list ( make_char ( 60 ) ) , make_list ( make_char ( 34 ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef48 ) ( ( * ef45 ) ( tmp [ 1 ] , tmp [ 2 ] ) ) ) , ( constant7 ? constant7 : ( constant7 = ( * ef1 ) ( lf2 ( make_list ( ( * ef7 ) ( ( * ef47 ) ( lf7 ( cons ( make_list ( make_char ( 34 ) ) , cons ( make_list ( make_char ( 62 ) ) , make_list ( make_char ( 34 ) ) ) ) ) ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 3 ] , ef1sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf2sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
tmp [ 6 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 5 ] ) ) ) , ( * ef45 ) ( tmp [ 1 ] , tmp [ 2 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
FUNC_EXIT ( ( * ef15 ) ( ( * ef17 ) ( ( * ef18 ) ( lf3 ( make_list ( tmp [ 6 ] ) ) ) ) , lf_AUX_Regular_Sdf_Normalization3_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 5 ] ) ) ) ) ) ) ;
}
}
}
if ( check_sym ( tmp [ 0 ] , ef49sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = ( * ef1 ) ( lf2 ( cons ( ( constant8 ? constant8 : ( constant8 = make_list ( ( * ef7 ) ( ( * ef47 ) ( lf7 ( cons ( make_list ( make_char ( 34 ) ) , cons ( make_list ( make_char ( 123 ) ) , make_list ( make_char ( 34 ) ) ) ) ) ) ) ) ) ) , cons ( make_list ( ( * ef35 ) ( tmp [ 1 ] , ( constant9 ? constant9 : ( constant9 = ( * ef7 ) ( ( * ef47 ) ( lf7 ( cons ( make_list ( make_char ( 34 ) ) , cons ( make_list ( make_char ( 44 ) ) , make_list ( make_char ( 34 ) ) ) ) ) ) ) ) ) ) ) , ( constant10 ? constant10 : ( constant10 = make_list ( ( * ef7 ) ( ( * ef47 ) ( lf7 ( cons ( make_list ( make_char ( 34 ) ) , cons ( make_list ( make_char ( 125 ) ) , make_list ( make_char ( 34 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 2 ] , ef1sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf2sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 4 ] ) ) ) , ( * ef49 ) ( tmp [ 1 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
FUNC_EXIT ( ( * ef15 ) ( lf_AUX_Regular_Sdf_Normalization3_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 4 ] ) ) ) ) , ( * ef17 ) ( ( * ef18 ) ( lf3 ( make_list ( tmp [ 5 ] ) ) ) ) ) ) ;
}
}
}
if ( check_sym ( tmp [ 0 ] , ef50sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef1sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf2sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = ( * ef19 ) ( ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef50 ) ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 4 ] ) ) ) , tmp [ 2 ] ) ) , cons ( ( constant11 ? constant11 : ( constant11 = make_list ( ( * ef7 ) ( ( * ef47 ) ( lf7 ( cons ( make_list ( make_char ( 34 ) ) , cons ( make_list ( make_char ( 40 ) ) , make_list ( make_char ( 34 ) ) ) ) ) ) ) ) ) ) , cons ( make_list ( tmp [ 4 ] ) , ( constant12 ? constant12 : ( constant12 = make_list ( ( * ef7 ) ( ( * ef47 ) ( lf7 ( cons ( make_list ( make_char ( 34 ) ) , cons ( make_list ( make_char ( 41 ) ) , make_list ( make_char ( 34 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , tmp [ 2 ] , ( constant0 ? constant0 : ( constant0 = ( * ef20 ) ( ) ) ) ) ;
FUNC_EXIT ( ( * ef15 ) ( ( * ef17 ) ( ( * ef18 ) ( lf3 ( make_list ( tmp [ 5 ] ) ) ) ) , lf_AUX_Regular_Sdf_Normalization3_1 ( ( * ef1 ) ( lf2 ( cons ( make_list ( tmp [ 4 ] ) , make_list ( tmp [ 2 ] ) ) ) ) ) ) ) ;
}
}
}
if ( check_sym ( tmp [ 0 ] , ef51sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef1sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 2 ] , lf2sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
FUNC_EXIT ( ( * ef15 ) ( ( * ef17 ) ( ( * ef52 ) ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 3 ] ) ) ) ) ) , lf_AUX_Regular_Sdf_Normalization3_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 3 ] ) ) ) ) ) ) ;
}
}
}
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
FUNC_EXIT_CONST ( constant13 , ( * ef3 ) ( ) ) ;
}
if ( check_sym ( tmp [ 0 ] , ef5sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
FUNC_EXIT_CONST ( constant13 , ( * ef3 ) ( ) ) ;
}
if ( check_sym ( tmp [ 0 ] , ef7sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
FUNC_EXIT_CONST ( constant13 , ( * ef3 ) ( ) ) ;
}
if ( check_sym ( tmp [ 0 ] , ef9sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
FUNC_EXIT ( ( * ef10 ) ( lf_AUX_Regular_Sdf_Normalization3_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ) ) ;
}
tmp [ 0 ] = list_head ( atmp000 ) ;
if ( term_equal ( tmp [ 0 ] , ( constant14 ? constant14 : ( constant14 = ( * ef6 ) ( ) ) ) ) ) {
FUNC_EXIT_CONST ( constant13 , ( * ef3 ) ( ) ) ;
}
if ( term_equal ( tmp [ 0 ] , ( constant15 ? constant15 : ( constant15 = ( * ef8 ) ( ) ) ) ) ) {
FUNC_EXIT_CONST ( constant13 , ( * ef3 ) ( ) ) ;
}
if ( term_equal ( tmp [ 0 ] , ( constant16 ? constant16 : ( constant16 = ( * ef16 ) ( ) ) ) ) ) {
FUNC_EXIT_CONST ( constant17 , ( * ef17 ) ( ( * ef18 ) ( lf3 ( make_list ( ( * ef19 ) ( ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) ) , ( * ef16 ) ( ) , ( * ef20 ) ( ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , ( constant18 ? constant18 : ( constant18 = ( * ef4 ) ( ) ) ) ) ) {
FUNC_EXIT_CONST ( constant13 , ( * ef3 ) ( ) ) ;
}
}
if ( ! not_empty_list ( atmp000 ) ) {
FUNC_EXIT_CONST ( constant13 , ( * ef3 ) ( ) ) ;
}
}
}
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
tmp [ 0 ] = arg_0 ( atmp00 ) ;
{
ATerm atmp0000 [ 2 ] ;
atmp0000 [ 0 ] = tmp [ 0 ] ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
atmp0000 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
if ( not_empty_list ( tmp [ 0 ] ) ) {
FUNC_EXIT ( ( * ef15 ) ( lf_AUX_Regular_Sdf_Normalization3_1 ( ( * ef1 ) ( lf2 ( slice ( atmp0000 [ 0 ] , atmp0000 [ 1 ] ) ) ) ) , lf_AUX_Regular_Sdf_Normalization3_1 ( ( * ef1 ) ( lf2 ( tmp [ 0 ] ) ) ) ) ) ;
}
atmp0000 [ 1 ] = list_tail ( atmp0000 [ 1 ] ) ;
tmp [ 0 ] = atmp0000 [ 1 ] ;
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Regular_Sdf_Normalization3_1sym , ltmp [ 0 ] ) ) ;
}
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}
ATerm lf7 ( ATerm arg0 ) {
CONS_ENTRY ( lf7sym , ATmakeAppl ( lf7sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf7sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf6 ( ATerm arg0 ) {
CONS_ENTRY ( lf6sym , ATmakeAppl ( lf6sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf6sym , arg0 ) ) ;
}
ATerm lf5 ( ATerm arg0 ) {
CONS_ENTRY ( lf5sym , ATmakeAppl ( lf5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf5sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}

