#include  "support.h"
static Symbol lf_AUX_ParseTrees3_1sym ;
static ATerm lf_AUX_ParseTrees3_1 ( ATerm arg1 ) ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol ef19sym ;
static funcptr ef19 ;
static Symbol ef20sym ;
static funcptr ef20 ;
static Symbol ef21sym ;
static funcptr ef21 ;
static Symbol ef24sym ;
static funcptr ef24 ;
static Symbol ef25sym ;
static funcptr ef25 ;
static Symbol ef27sym ;
static funcptr ef27 ;
static Symbol ef30sym ;
static funcptr ef30 ;
static Symbol ef31sym ;
static funcptr ef31 ;
static Symbol ef32sym ;
static funcptr ef32 ;
static Symbol ef34sym ;
static funcptr ef34 ;
static Symbol ef33sym ;
static funcptr ef33 ;
static Symbol ef35sym ;
static funcptr ef35 ;
static Symbol ef36sym ;
static funcptr ef36 ;
static Symbol ef38sym ;
static funcptr ef38 ;
static Symbol ef39sym ;
static funcptr ef39 ;
static Symbol ef40sym ;
static funcptr ef40 ;
static Symbol ef37sym ;
static funcptr ef37 ;
static Symbol ef44sym ;
static funcptr ef44 ;
static Symbol ef47sym ;
static funcptr ef47 ;
static Symbol ef48sym ;
static funcptr ef48 ;
static Symbol ef43sym ;
static funcptr ef43 ;
static Symbol ef49sym ;
static funcptr ef49 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef50sym ;
static funcptr ef50 ;
static Symbol ef51sym ;
static funcptr ef51 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef52sym ;
static funcptr ef52 ;
static Symbol ef53sym ;
static funcptr ef53 ;
static Symbol ef42sym ;
static funcptr ef42 ;
static Symbol ef54sym ;
static funcptr ef54 ;
static Symbol ef56sym ;
static funcptr ef56 ;
static Symbol ef55sym ;
static funcptr ef55 ;
static Symbol ef58sym ;
static funcptr ef58 ;
static Symbol ef60sym ;
static funcptr ef60 ;
static Symbol ef59sym ;
static funcptr ef59 ;
static Symbol ef61sym ;
static funcptr ef61 ;
static Symbol ef57sym ;
static funcptr ef57 ;
static Symbol ef64sym ;
static funcptr ef64 ;
static Symbol ef45sym ;
static funcptr ef45 ;
static Symbol ef46sym ;
static funcptr ef46 ;
static Symbol ef28sym ;
static funcptr ef28 ;
static Symbol ef65sym ;
static funcptr ef65 ;
static Symbol ef66sym ;
static funcptr ef66 ;
static Symbol ef67sym ;
static funcptr ef67 ;
static Symbol ef68sym ;
static funcptr ef68 ;
static Symbol ef70sym ;
static funcptr ef70 ;
static Symbol ef72sym ;
static funcptr ef72 ;
static Symbol ef69sym ;
static funcptr ef69 ;
static Symbol ef71sym ;
static funcptr ef71 ;
static Symbol ef73sym ;
static funcptr ef73 ;
static Symbol ef62sym ;
static funcptr ef62 ;
static Symbol ef63sym ;
static funcptr ef63 ;
static Symbol ef74sym ;
static funcptr ef74 ;
static Symbol ef41sym ;
static funcptr ef41 ;
static Symbol ef75sym ;
static funcptr ef75 ;
static Symbol ef76sym ;
static funcptr ef76 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef77sym ;
static funcptr ef77 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef26sym ;
static funcptr ef26 ;
static Symbol ef78sym ;
static funcptr ef78 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef22sym ;
static funcptr ef22 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef23sym ;
static funcptr ef23 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef29sym ;
static funcptr ef29 ;
void register_AUX_ParseTrees3 ( ) {
lf_AUX_ParseTrees3_1sym = ATmakeSymbol ( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"init\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ParseTrees3_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"init\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) , lf_AUX_ParseTrees3_1 , lf_AUX_ParseTrees3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_ParseTrees3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"chars\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"chars\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"ql\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"ql\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"char-class\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"char-class\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"name\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"name\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"sym\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"sym\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"lex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"lex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"aprod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"aprod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"abbreviations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"abbreviations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"pairs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"pairs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef20 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"asfix\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef20sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"asfix\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef21 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"modules\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef21sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"modules\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef22 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef22sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef23 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef23sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef24 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"terms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef24sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"terms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef25 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"module\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef25sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"module\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef26 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"module-name\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef26sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"module-name\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef27 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"sections\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef27sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"sections\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef28 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef28sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef29 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"abbrevs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef29sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"abbrevs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef30 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"imports\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef30sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"imports\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef31 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"ids\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef31sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"ids\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef32 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"exports\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef32sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"exports\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef33 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"grammars\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef33sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"grammars\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef34 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"hiddens\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef34sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"hiddens\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef35 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"sorts\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef35sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"sorts\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef36 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"lexical-syntax\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef36sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"lexical-syntax\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef37 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef37sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef38 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"context-free-syntax\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef38sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"context-free-syntax\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef39 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef39sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef40 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"variables\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef40sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"variables\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef41 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"prod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef41sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"prod\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef42 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"syms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef42sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"syms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef43 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef43sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef44 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"no-attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef44sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"no-attrs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef45 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef45sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef46 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef46sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef47 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"attr\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef47sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"attr\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef48 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"fun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef48sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"fun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef49 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef49sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef50 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef50sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef51 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"neg\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef51sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"neg\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef52 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"label\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef52sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"label\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef53 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"prod-skel\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef53sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"prod-skel\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef54 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef54sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef55 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"prods\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef55sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"prods\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef56 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"agroup\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef56sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"agroup\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef57 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef57sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef58 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"decr-chain\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef58sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"decr-chain\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef59 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"groups\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef59sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"groups\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef60 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"incr-chain\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef60sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"incr-chain\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef61 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"prio-assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef61sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"prio-assoc\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef62 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef62sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef63 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef63sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef64 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"no-equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef64sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"no-equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef65 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"cond-equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef65sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"cond-equations\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef66 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"condition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef66sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"condition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef67 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"cop\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef67sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"cop\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef68 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"ceq-equ\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef68sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"ceq-equ\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef69 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"tag\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef69sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"tag\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef70 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"ceq-when\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef70sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"ceq-when\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef71 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"conditions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef71sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"conditions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef72 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"ceq-impl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef72sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"ceq-impl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef73 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"impl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef73sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"impl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef74 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef74sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef75 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"args\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef75sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"args\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef76 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef76sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef77 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"elems\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef77sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"elems\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef78 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef78sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
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
static ATerm constant31 = NULL ;
static ATerm constant32 = NULL ;
static ATerm constant33 = NULL ;
static ATerm constant34 = NULL ;
static ATerm constant35 = NULL ;
static ATerm constant36 = NULL ;
static ATerm constant37 = NULL ;
static ATerm constant38 = NULL ;
void init_AUX_ParseTrees3 ( ) {
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
ATprotect ( & constant31 ) ;
ATprotect ( & constant32 ) ;
ATprotect ( & constant33 ) ;
ATprotect ( & constant34 ) ;
ATprotect ( & constant35 ) ;
ATprotect ( & constant36 ) ;
ATprotect ( & constant37 ) ;
ATprotect ( & constant38 ) ;
}
ATerm lf_AUX_ParseTrees3_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_ParseTrees3_1 ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
return ( * ef2 ) ( arg0 , ( constant0 ? constant0 : ( constant0 = ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef6sym ) ) {
return ( * ef2 ) ( arg0 , ( constant0 ? constant0 : ( constant0 = ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef7sym ) ) {
return ( * ef2 ) ( arg0 , ( constant0 ? constant0 : ( constant0 = ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef8sym ) ) {
return ( * ef2 ) ( arg0 , ( constant0 ? constant0 : ( constant0 = ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef9sym ) ) {
return ( * ef2 ) ( arg0 , ( constant0 ? constant0 : ( constant0 = ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef10sym ) ) {
return ( * ef2 ) ( arg0 , ( constant0 ? constant0 : ( constant0 = ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef11sym ) ) {
return ( * ef2 ) ( arg0 , ( constant0 ? constant0 : ( constant0 = ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef12sym ) ) {
return ( * ef2 ) ( arg0 , ( constant1 ? constant1 : ( constant1 = ( * ef13 ) ( ( * ef4 ) ( ( * ef14 ) ( ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef15 ) ( ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef16sym ) ) {
return ( * ef2 ) ( arg0 , ( constant1 ? constant1 : ( constant1 = ( * ef13 ) ( ( * ef4 ) ( ( * ef14 ) ( ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef15 ) ( ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef17sym ) ) {
return ( * ef2 ) ( arg0 , ( constant0 ? constant0 : ( constant0 = ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef18sym ) ) {
return ( * ef2 ) ( arg0 , ( constant2 ? constant2 : ( constant2 = ( * ef3 ) ( ( * ef4 ) ( ( * ef19 ) ( ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef20sym ) ) {
return ( * ef2 ) ( arg0 , ( constant3 ? constant3 : ( constant3 = ( * ef13 ) ( ( * ef4 ) ( ( * ef21 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef24 ) ( ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef25sym ) ) {
return ( * ef2 ) ( arg0 , ( constant4 ? constant4 : ( constant4 = ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 8 , char_table [ 34 ] , char_table [ 109 ] , char_table [ 111 ] , char_table [ 100 ] , char_table [ 117 ] , char_table [ 108 ] , char_table [ 101 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef26 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef27 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef28 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef29 ) ( ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef30sym ) ) {
return ( * ef2 ) ( arg0 , ( constant5 ? constant5 : ( constant5 = ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 9 , char_table [ 34 ] , char_table [ 105 ] , char_table [ 109 ] , char_table [ 112 ] , char_table [ 111 ] , char_table [ 114 ] , char_table [ 116 ] , char_table [ 115 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef31 ) ( ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef32sym ) ) {
return ( * ef2 ) ( arg0 , ( constant6 ? constant6 : ( constant6 = ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 9 , char_table [ 34 ] , char_table [ 101 ] , char_table [ 120 ] , char_table [ 112 ] , char_table [ 111 ] , char_table [ 114 ] , char_table [ 116 ] , char_table [ 115 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef33 ) ( ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef34sym ) ) {
return ( * ef2 ) ( arg0 , ( constant7 ? constant7 : ( constant7 = ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 9 , char_table [ 34 ] , char_table [ 104 ] , char_table [ 105 ] , char_table [ 100 ] , char_table [ 100 ] , char_table [ 101 ] , char_table [ 110 ] , char_table [ 115 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef33 ) ( ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef35sym ) ) {
return ( * ef2 ) ( arg0 , ( * ef13 ) ( ( constant8 ? constant8 : ( constant8 = ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 7 , char_table [ 34 ] , char_table [ 115 ] , char_table [ 111 ] , char_table [ 114 ] , char_table [ 116 ] , char_table [ 115 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) , ( * ef13 ) ( ( constant9 ? constant9 : ( constant9 = ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( arg0 ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef36sym ) ) {
return ( * ef2 ) ( arg0 , ( constant10 ? constant10 : ( constant10 = ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 16 , char_table [ 34 ] , char_table [ 108 ] , char_table [ 101 ] , char_table [ 120 ] , char_table [ 105 ] , char_table [ 99 ] , char_table [ 97 ] , char_table [ 108 ] , char_table [ 32 ] , char_table [ 115 ] , char_table [ 121 ] , char_table [ 110 ] , char_table [ 116 ] , char_table [ 97 ] , char_table [ 120 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef37 ) ( ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef38sym ) ) {
return ( * ef2 ) ( arg0 , ( constant11 ? constant11 : ( constant11 = ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 21 , char_table [ 34 ] , char_table [ 99 ] , char_table [ 111 ] , char_table [ 110 ] , char_table [ 116 ] , char_table [ 101 ] , char_table [ 120 ] , char_table [ 116 ] , char_table [ 45 ] , char_table [ 102 ] , char_table [ 114 ] , char_table [ 101 ] , char_table [ 101 ] , char_table [ 32 ] , char_table [ 115 ] , char_table [ 121 ] , char_table [ 110 ] , char_table [ 116 ] , char_table [ 97 ] , char_table [ 120 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef37 ) ( ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef39sym ) ) {
return ( * ef2 ) ( arg0 , ( * ef13 ) ( ( constant12 ? constant12 : ( constant12 = ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 12 , char_table [ 34 ] , char_table [ 112 ] , char_table [ 114 ] , char_table [ 105 ] , char_table [ 111 ] , char_table [ 114 ] , char_table [ 105 ] , char_table [ 116 ] , char_table [ 105 ] , char_table [ 101 ] , char_table [ 115 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) , ( * ef13 ) ( ( constant9 ? constant9 : ( constant9 = ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( arg0 ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef40sym ) ) {
return ( * ef2 ) ( arg0 , ( constant13 ? constant13 : ( constant13 = ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 11 , char_table [ 34 ] , char_table [ 118 ] , char_table [ 97 ] , char_table [ 114 ] , char_table [ 105 ] , char_table [ 97 ] , char_table [ 98 ] , char_table [ 108 ] , char_table [ 101 ] , char_table [ 115 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef37 ) ( ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef41sym ) ) {
return ( * ef2 ) ( arg0 , ( constant14 ? constant14 : ( constant14 = ( * ef13 ) ( ( * ef4 ) ( ( * ef26 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef42 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 34 ] , char_table [ 45 ] , char_table [ 62 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef15 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef43 ) ( ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef44sym ) ) {
return ( * ef2 ) ( arg0 , ( constant15 ? constant15 : ( constant15 = ( * ef3 ) ( ( * ef45 ) ( ( * ef46 ) ( ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef43sym ) ) {
return ( * ef2 ) ( arg0 , ( * ef13 ) ( ( constant16 ? constant16 : ( constant16 = ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 123 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) , ( * ef13 ) ( ( constant9 ? constant9 : ( constant9 = ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( arg0 ) , ( constant17 ? constant17 : ( constant17 = ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 125 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef47sym ) ) {
return ( * ef2 ) ( arg0 , ( constant18 ? constant18 : ( constant18 = ( * ef13 ) ( ( * ef4 ) ( ( * ef48 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 40 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef43 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 41 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef49sym ) ) {
return ( * ef2 ) ( arg0 , ( constant19 ? constant19 : ( constant19 = ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 123 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef15 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef10 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 125 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef50 ) ( ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef50sym ) ) {
return ( * ef2 ) ( arg0 , ( * ef13 ) ( ( constant20 ? constant20 : ( constant20 = ( * ef4 ) ( ( * ef15 ) ( ) ) ) ) , ( * ef13 ) ( ( constant9 ? constant9 : ( constant9 = ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( arg0 ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef51sym ) ) {
return ( * ef2 ) ( arg0 , ( constant21 ? constant21 : ( constant21 = ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 126 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef11 ) ( ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef52sym ) ) {
return ( * ef2 ) ( arg0 , ( * ef13 ) ( ( * ef4 ) ( arg0 ) , ( constant22 ? constant22 : ( constant22 = ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 58 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef15 ) ( ) ) ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef53sym ) ) {
return ( * ef2 ) ( arg0 , ( constant23 ? constant23 : ( constant23 = ( * ef13 ) ( ( * ef4 ) ( ( * ef42 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef41 ) ( ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef54sym ) ) {
return ( * ef2 ) ( arg0 , ( constant24 ? constant24 : ( constant24 = ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 123 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef55 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 125 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef56sym ) ) {
return ( * ef2 ) ( arg0 , ( constant25 ? constant25 : ( constant25 = ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 123 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef57 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 58 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef55 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 125 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef58sym ) ) {
return ( * ef2 ) ( arg0 , ( constant26 ? constant26 : ( constant26 = ( * ef3 ) ( ( * ef4 ) ( ( * ef59 ) ( ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef60sym ) ) {
return ( * ef2 ) ( arg0 , ( constant26 ? constant26 : ( constant26 = ( * ef3 ) ( ( * ef4 ) ( ( * ef59 ) ( ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef61sym ) ) {
return ( * ef2 ) ( arg0 , ( constant27 ? constant27 : ( constant27 = ( * ef13 ) ( ( * ef4 ) ( ( * ef62 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef57 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef63 ) ( ) ) ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef64sym ) ) {
return ( * ef2 ) ( arg0 , ( constant15 ? constant15 : ( constant15 = ( * ef3 ) ( ( * ef45 ) ( ( * ef46 ) ( ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef28sym ) ) {
return ( * ef2 ) ( arg0 , ( constant28 ? constant28 : ( constant28 = ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 11 , char_table [ 34 ] , char_table [ 101 ] , char_table [ 113 ] , char_table [ 117 ] , char_table [ 97 ] , char_table [ 116 ] , char_table [ 105 ] , char_table [ 111 ] , char_table [ 110 ] , char_table [ 115 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef65 ) ( ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef66sym ) ) {
return ( * ef2 ) ( arg0 , ( constant29 ? constant29 : ( constant29 = ( * ef13 ) ( ( * ef4 ) ( ( * ef62 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef67 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef63 ) ( ) ) ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef68sym ) ) {
return ( * ef2 ) ( arg0 , ( constant30 ? constant30 : ( constant30 = ( * ef13 ) ( ( * ef4 ) ( ( * ef26 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef69 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef62 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 61 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef63 ) ( ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef70sym ) ) {
return ( * ef2 ) ( arg0 , ( constant31 ? constant31 : ( constant31 = ( * ef13 ) ( ( * ef4 ) ( ( * ef26 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef69 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef62 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 61 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef63 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 6 , char_table [ 34 ] , char_table [ 119 ] , char_table [ 104 ] , char_table [ 101 ] , char_table [ 110 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef71 ) ( ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef72sym ) ) {
return ( * ef2 ) ( arg0 , ( constant32 ? constant32 : ( constant32 = ( * ef13 ) ( ( * ef4 ) ( ( * ef26 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef69 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef71 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef73 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( ( * ef62 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 61 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef63 ) ( ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef74sym ) ) {
return ( * ef2 ) ( arg0 , ( constant33 ? constant33 : ( constant33 = ( * ef13 ) ( ( * ef4 ) ( ( * ef41 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef75 ) ( ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef76sym ) ) {
return ( * ef2 ) ( arg0 , ( constant34 ? constant34 : ( constant34 = ( * ef13 ) ( ( * ef4 ) ( ( * ef15 ) ( ) ) , ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef77 ) ( ) ) ) ) ) ) ) ) ;
}
if ( check_sym ( arg0 , ef78sym ) ) {
return ( * ef2 ) ( arg0 , ( * ef13 ) ( ( constant35 ? constant35 : ( constant35 = ( * ef2 ) ( ( * ef6 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 6 , char_table [ 34 ] , char_table [ 116 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) , ( * ef13 ) ( ( constant9 ? constant9 : ( constant9 = ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) , ( * ef13 ) ( ( constant36 ? constant36 : ( constant36 = ( * ef4 ) ( ( * ef14 ) ( ) ) ) ) , ( * ef13 ) ( ( constant9 ? constant9 : ( constant9 = ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) , ( * ef13 ) ( ( constant37 ? constant37 : ( constant37 = ( * ef4 ) ( ( * ef26 ) ( ) ) ) ) , ( * ef13 ) ( ( constant9 ? constant9 : ( constant9 = ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) , ( * ef13 ) ( ( * ef4 ) ( arg0 ) , ( constant38 ? constant38 : ( constant38 = ( * ef13 ) ( ( * ef2 ) ( ( * ef1 ) ( ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef22 ) ( ( * ef23 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef29 ) ( ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
}
return make_nf1 ( lf_AUX_ParseTrees3_1sym , arg0 ) ;
}
ATerm lf2 ( ATerm arg0 ) {
PROF ( prof_lf2 ) ;
return make_nf1 ( lf2sym , arg0 ) ;
}

