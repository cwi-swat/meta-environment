/*
 * Generated at Sun Nov  9 17:22:01 2003
 */

#include "ASFME_dict.h"

AFun ASF_afun0;
AFun ASF_afun1;
AFun ASF_afun2;
AFun ASF_afun3;
AFun ASF_afun4;
AFun ASF_afun5;
AFun ASF_afun6;
AFun ASF_afun7;
AFun ASF_afun8;
AFun ASF_afun9;
AFun ASF_afun10;
AFun ASF_afun11;
AFun ASF_afun12;
AFun ASF_afun13;
AFun ASF_afun14;
AFun ASF_afun15;
AFun ASF_afun16;
AFun ASF_afun17;
AFun ASF_afun18;
AFun ASF_afun19;
AFun ASF_afun20;
AFun ASF_afun21;
AFun ASF_afun22;
AFun ASF_afun23;
AFun ASF_afun24;
AFun ASF_afun25;
AFun ASF_afun26;
AFun ASF_afun27;
AFun ASF_afun28;
AFun ASF_afun29;
AFun ASF_afun30;
AFun ASF_afun31;
AFun ASF_afun32;
AFun ASF_afun33;
AFun ASF_afun34;
AFun ASF_afun35;
AFun ASF_afun36;
AFun ASF_afun37;
AFun ASF_afun38;
AFun ASF_afun39;
AFun ASF_afun40;
AFun ASF_afun41;
AFun ASF_afun42;
AFun ASF_afun43;
AFun ASF_afun44;
AFun ASF_afun45;
AFun ASF_afun46;
AFun ASF_afun47;
AFun ASF_afun48;
AFun ASF_afun49;
AFun ASF_afun50;
AFun ASF_afun51;
AFun ASF_afun52;
AFun ASF_afun53;
AFun ASF_afun54;
AFun ASF_afun55;
AFun ASF_afun56;
AFun ASF_afun57;

ATerm ASF_patternOptLayoutPresent = NULL;
ATerm ASF_patternOptLayoutAbsent = NULL;
ATerm ASF_patternStartASFCondition = NULL;
ATerm ASF_patternStartASFConditions = NULL;
ATerm ASF_patternStartTree = NULL;
ATerm ASF_patternStartASFImplies = NULL;
ATerm ASF_patternStartASFEquation = NULL;
ATerm ASF_patternStartASFConditionalEquation = NULL;
ATerm ASF_patternStartASFModule = NULL;
ATerm ASF_patternStartASFSection = NULL;
ATerm ASF_patternStartASFTagId = NULL;
ATerm ASF_patternStartASFTag = NULL;
ATerm ASF_patternStartASFTestEquation = NULL;
ATerm ASF_patternASFTestEquationWhen = NULL;
ATerm ASF_patternASFTestEquationImplies = NULL;
ATerm ASF_patternASFTestEquationSimple = NULL;
ATerm ASF_patternASFTagNotEmpty = NULL;
ATerm ASF_patternASFTagEmpty = NULL;
ATerm ASF_patternASFTagIdManyChars = NULL;
ATerm ASF_patternASFTagIdOneChar = NULL;
ATerm ASF_patternASFTestEquationTestListMany = NULL;
ATerm ASF_patternASFTestEquationTestListSingle = NULL;
ATerm ASF_patternASFTestEquationTestListEmpty = NULL;
ATerm ASF_patternASFConditionalEquationListMany = NULL;
ATerm ASF_patternASFConditionalEquationListSingle = NULL;
ATerm ASF_patternASFConditionalEquationListEmpty = NULL;
ATerm ASF_patternASFSectionTests = NULL;
ATerm ASF_patternASFSectionEquations = NULL;
ATerm ASF_patternASFSectionListMany = NULL;
ATerm ASF_patternASFSectionListSingle = NULL;
ATerm ASF_patternASFSectionListEmpty = NULL;
ATerm ASF_patternASFModuleDefault = NULL;
ATerm ASF_patternASFEquationDefault = NULL;
ATerm ASF_patternASFConditionalEquationWhen = NULL;
ATerm ASF_patternASFConditionalEquationImplies = NULL;
ATerm ASF_patternASFConditionalEquationSimple = NULL;
ATerm ASF_patternASFImpliesDefault = NULL;
ATerm ASF_patternCHARListMany = NULL;
ATerm ASF_patternCHARListSingle = NULL;
ATerm ASF_patternCHARListEmpty = NULL;
ATerm ASF_patternTreeAmbsMany = NULL;
ATerm ASF_patternTreeAmbsSingle = NULL;
ATerm ASF_patternTreeAmbsEmpty = NULL;
ATerm ASF_patternTreeLexicalConstructor = NULL;
ATerm ASF_patternTreeAmbiguityConstructor = NULL;
ATerm ASF_patternASFConditionListMany = NULL;
ATerm ASF_patternASFConditionListSingle = NULL;
ATerm ASF_patternASFConditionsDefault = NULL;
ATerm ASF_patternASFConditionNoMatch = NULL;
ATerm ASF_patternASFConditionMatch = NULL;
ATerm ASF_patternASFConditionEquality = NULL;
ATerm ASF_patternASFConditionNegative = NULL;
ATerm ASF_patternASFConditionPositive = NULL;
ATerm ASF_patternCHARDefault = NULL;
ATerm ASF_patternProductionLexicalConstructor = NULL;

/*
 * ASF_afun0 = prod(x,x,x)
 * ASF_afun1 = lit(x)
 * ASF_afun2 = ")"
 * ASF_afun3 = cf(x)
 * ASF_afun4 = opt(x)
 * ASF_afun5 = layout
 * ASF_afun6 = iter-star(x)
 * ASF_afun7 = sort(x)
 * ASF_afun8 = "CHAR"
 * ASF_afun9 = "("
 * ASF_afun10 = attrs(x)
 * ASF_afun11 = term(x)
 * ASF_afun12 = cons(x)
 * ASF_afun13 = "lexical-constructor"
 * ASF_afun14 = appl(x,x)
 * ASF_afun15 = lex(x)
 * ASF_afun16 = no-attrs
 * ASF_afun17 = list(x)
 * ASF_afun18 = char-class(x)
 * ASF_afun19 = range(x,x)
 * ASF_afun20 = "="
 * ASF_afun21 = "ASF-Condition"
 * ASF_afun22 = "positive"
 * ASF_afun23 = "!="
 * ASF_afun24 = "negative"
 * ASF_afun25 = "=="
 * ASF_afun26 = "equality"
 * ASF_afun27 = ":="
 * ASF_afun28 = "match"
 * ASF_afun29 = "!:="
 * ASF_afun30 = "no-match"
 * ASF_afun31 = iter-sep(x,x)
 * ASF_afun32 = ","
 * ASF_afun33 = "ASF-Conditions"
 * ASF_afun34 = iter-star-sep(x,x)
 * ASF_afun35 = "amb"
 * ASF_afun36 = "ambiguity-constructor"
 * ASF_afun37 = "ASF-Implies"
 * ASF_afun38 = "ASF-Equation"
 * ASF_afun39 = "ASF-Tag"
 * ASF_afun40 = "ASF-ConditionalEquation"
 * ASF_afun41 = "simple"
 * ASF_afun42 = "implies"
 * ASF_afun43 = "when"
 * ASF_afun44 = "ASF-Section"
 * ASF_afun45 = "ASF-Module"
 * ASF_afun46 = "default"
 * ASF_afun47 = "equations"
 * ASF_afun48 = "ASF-TestEquation"
 * ASF_afun49 = "tests"
 * ASF_afun50 = "ASF-TagId"
 * ASF_afun51 = "]"
 * ASF_afun52 = "["
 * ASF_afun53 = "empty"
 * ASF_afun54 = "not-empty"
 * ASF_afun55 = parsetree(x,x)
 * ASF_afun56 = "<START>"
 * ASF_afun57 = "Tree"
 *
 * ASF_patternOptLayoutPresent = appl(prod([cf(layout)],cf(opt(layout)),no-attrs),<term>)
 * ASF_patternOptLayoutAbsent = appl(prod([],cf(opt(layout)),no-attrs),[])
 * ASF_patternStartASFCondition = parsetree(appl(prod([cf(opt(layout)),cf(sort("ASF-Condition")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * ASF_patternStartASFConditions = parsetree(appl(prod([cf(opt(layout)),cf(sort("ASF-Conditions")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * ASF_patternStartTree = parsetree(appl(prod([cf(opt(layout)),cf(sort("Tree")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * ASF_patternStartASFImplies = parsetree(appl(prod([cf(opt(layout)),cf(sort("ASF-Implies")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * ASF_patternStartASFEquation = parsetree(appl(prod([cf(opt(layout)),cf(sort("ASF-Equation")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * ASF_patternStartASFConditionalEquation = parsetree(appl(prod([cf(opt(layout)),cf(sort("ASF-ConditionalEquation")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * ASF_patternStartASFModule = parsetree(appl(prod([cf(opt(layout)),cf(sort("ASF-Module")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * ASF_patternStartASFSection = parsetree(appl(prod([cf(opt(layout)),cf(sort("ASF-Section")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * ASF_patternStartASFTagId = parsetree(appl(prod([cf(opt(layout)),cf(sort("ASF-TagId")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * ASF_patternStartASFTag = parsetree(appl(prod([cf(opt(layout)),cf(sort("ASF-Tag")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * ASF_patternStartASFTestEquation = parsetree(appl(prod([cf(opt(layout)),cf(sort("ASF-TestEquation")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * ASF_patternASFTestEquationWhen = appl(prod([cf(sort("ASF-Tag")),cf(opt(layout)),cf(sort("ASF-Condition")),cf(opt(layout)),lit("when"),cf(opt(layout)),cf(sort("ASF-Conditions"))],cf(sort("ASF-TestEquation")),attrs([term(cons("when"))])),[<term>,<term>,<term>,<term>,lit("when"),<term>,<term>])
 * ASF_patternASFTestEquationImplies = appl(prod([cf(sort("ASF-Tag")),cf(opt(layout)),cf(sort("ASF-Conditions")),cf(opt(layout)),cf(sort("ASF-Implies")),cf(opt(layout)),cf(sort("ASF-Condition"))],cf(sort("ASF-TestEquation")),attrs([term(cons("implies"))])),[<term>,<term>,<term>,<term>,<term>,<term>,<term>])
 * ASF_patternASFTestEquationSimple = appl(prod([cf(sort("ASF-Tag")),cf(opt(layout)),cf(sort("ASF-Condition"))],cf(sort("ASF-TestEquation")),attrs([term(cons("simple"))])),[<term>,<term>,<term>])
 * ASF_patternASFTagNotEmpty = appl(prod([lit("["),cf(opt(layout)),cf(sort("ASF-TagId")),cf(opt(layout)),lit("]")],cf(sort("ASF-Tag")),attrs([term(cons("not-empty"))])),[lit("["),<term>,<term>,<term>,lit("]")])
 * ASF_patternASFTagEmpty = appl(prod([lit("["),cf(opt(layout)),lit("]")],cf(sort("ASF-Tag")),attrs([term(cons("empty"))])),[lit("["),<term>,lit("]")])
 * ASF_patternASFTagIdManyChars = appl(prod([lex(sort("ASF-TagId"))],cf(sort("ASF-TagId")),no-attrs),[appl(list(iter-star(char-class([range(0,255)]))),<term>)])
 * ASF_patternASFTagIdOneChar = appl(prod([lex(sort("ASF-TagId"))],cf(sort("ASF-TagId")),no-attrs),[appl(list(iter-star(char-class([range(0,255)]))),<term>)])
 * ASF_patternASFTestEquationTestListMany = [<term>,<term>,<list>]
 * ASF_patternASFTestEquationTestListSingle = [<term>]
 * ASF_patternASFTestEquationTestListEmpty = []
 * ASF_patternASFConditionalEquationListMany = [<term>,<term>,<list>]
 * ASF_patternASFConditionalEquationListSingle = [<term>]
 * ASF_patternASFConditionalEquationListEmpty = []
 * ASF_patternASFSectionTests = appl(prod([lit("tests"),cf(opt(layout)),cf(iter-star(sort("ASF-TestEquation")))],cf(sort("ASF-Section")),attrs([term(cons("tests"))])),[lit("tests"),<term>,appl(list(cf(iter-star(sort("ASF-TestEquation")))),<term>)])
 * ASF_patternASFSectionEquations = appl(prod([lit("equations"),cf(opt(layout)),cf(iter-star(sort("ASF-ConditionalEquation")))],cf(sort("ASF-Section")),attrs([term(cons("equations"))])),[lit("equations"),<term>,appl(list(cf(iter-star(sort("ASF-ConditionalEquation")))),<term>)])
 * ASF_patternASFSectionListMany = [<term>,<term>,<list>]
 * ASF_patternASFSectionListSingle = [<term>]
 * ASF_patternASFSectionListEmpty = []
 * ASF_patternASFModuleDefault = appl(prod([cf(iter-star(sort("ASF-Section")))],cf(sort("ASF-Module")),attrs([term(cons("default"))])),[appl(list(cf(iter-star(sort("ASF-Section")))),<term>)])
 * ASF_patternASFEquationDefault = appl(prod([<term>,cf(opt(layout)),lit("="),cf(opt(layout)),<term>],cf(sort("ASF-Equation")),no-attrs),[<term>,<term>,lit("="),<term>,<term>])
 * ASF_patternASFConditionalEquationWhen = appl(prod([cf(sort("ASF-Tag")),cf(opt(layout)),cf(sort("ASF-Equation")),cf(opt(layout)),lit("when"),cf(opt(layout)),cf(sort("ASF-Conditions"))],cf(sort("ASF-ConditionalEquation")),attrs([term(cons("when"))])),[<term>,<term>,<term>,<term>,lit("when"),<term>,<term>])
 * ASF_patternASFConditionalEquationImplies = appl(prod([cf(sort("ASF-Tag")),cf(opt(layout)),cf(sort("ASF-Conditions")),cf(opt(layout)),cf(sort("ASF-Implies")),cf(opt(layout)),cf(sort("ASF-Equation"))],cf(sort("ASF-ConditionalEquation")),attrs([term(cons("implies"))])),[<term>,<term>,<term>,<term>,<term>,<term>,<term>])
 * ASF_patternASFConditionalEquationSimple = appl(prod([cf(sort("ASF-Tag")),cf(opt(layout)),cf(sort("ASF-Equation"))],cf(sort("ASF-ConditionalEquation")),attrs([term(cons("simple"))])),[<term>,<term>,<term>])
 * ASF_patternASFImpliesDefault = appl(prod([lex(sort("ASF-Implies"))],cf(sort("ASF-Implies")),no-attrs),[appl(list(iter-star(char-class([range(0,255)]))),<term>)])
 * ASF_patternCHARListMany = [<term>,<term>,<list>]
 * ASF_patternCHARListSingle = [<term>]
 * ASF_patternCHARListEmpty = []
 * ASF_patternTreeAmbsMany = [<term>,<term>,lit(<str>),<term>,<list>]
 * ASF_patternTreeAmbsSingle = [<term>]
 * ASF_patternTreeAmbsEmpty = []
 * ASF_patternTreeLexicalConstructor = appl(prod([lit(<str>),cf(opt(layout)),lit("("),cf(opt(layout)),cf(iter-star(sort("CHAR"))),cf(opt(layout)),lit(")")],<term>,attrs([term(cons("lexical-constructor"))])),[<term>,<term>,lit("("),<term>,appl(list(cf(iter-star(sort("CHAR")))),<term>),<term>,lit(")")])
 * ASF_patternTreeAmbiguityConstructor = appl(prod([lit("amb"),cf(opt(layout)),lit("("),cf(opt(layout)),cf(iter-star-sep(<term>,lit(","))),cf(opt(layout)),lit(")")],cf(<term>),attrs([term(cons("ambiguity-constructor"))])),[lit("amb"),<term>,lit("("),<term>,appl(list(cf(iter-star-sep(<term>,lit(",")))),<term>),<term>,lit(")")])
 * ASF_patternASFConditionListMany = [<term>,<term>,lit(<str>),<term>,<list>]
 * ASF_patternASFConditionListSingle = [<term>]
 * ASF_patternASFConditionsDefault = appl(prod([cf(iter-sep(sort("ASF-Condition"),lit(",")))],cf(sort("ASF-Conditions")),no-attrs),[appl(list(cf(iter-sep(sort("ASF-Condition"),lit(",")))),<term>)])
 * ASF_patternASFConditionNoMatch = appl(prod([<term>,cf(opt(layout)),lit("!:="),cf(opt(layout)),<term>],cf(sort("ASF-Condition")),attrs([term(cons("no-match"))])),[<term>,<term>,lit("!:="),<term>,<term>])
 * ASF_patternASFConditionMatch = appl(prod([<term>,cf(opt(layout)),lit(":="),cf(opt(layout)),<term>],cf(sort("ASF-Condition")),attrs([term(cons("match"))])),[<term>,<term>,lit(":="),<term>,<term>])
 * ASF_patternASFConditionEquality = appl(prod([<term>,cf(opt(layout)),lit("=="),cf(opt(layout)),<term>],cf(sort("ASF-Condition")),attrs([term(cons("equality"))])),[<term>,<term>,lit("=="),<term>,<term>])
 * ASF_patternASFConditionNegative = appl(prod([<term>,cf(opt(layout)),lit("!="),cf(opt(layout)),<term>],cf(sort("ASF-Condition")),attrs([term(cons("negative"))])),[<term>,<term>,lit("!="),<term>,<term>])
 * ASF_patternASFConditionPositive = appl(prod([<term>,cf(opt(layout)),lit("="),cf(opt(layout)),<term>],cf(sort("ASF-Condition")),attrs([term(cons("positive"))])),[<term>,<term>,lit("="),<term>,<term>])
 * ASF_patternCHARDefault = appl(prod([lex(sort("CHAR"))],cf(sort("CHAR")),no-attrs),[appl(list(iter-star(char-class([range(0,255)]))),<term>)])
 * ASF_patternProductionLexicalConstructor = prod([lit(<str>),cf(opt(layout)),lit("("),cf(opt(layout)),cf(iter-star(sort("CHAR"))),cf(opt(layout)),lit(")")],<term>,attrs([term(cons("lexical-constructor"))]))
 *
 */

static ATermList _ASFME_dict = NULL;

#define _ASFME_dict_LEN 1937

static char _ASFME_dict_baf[_ASFME_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x43,0x82,0x2E,0x05,0x3C,0x69,0x6E,0x74,0x3E,0x00,0x00,
0x02,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x04,0x04,0x05,0x06,0x04,0x07,0x05,0x5B,0x5F,
0x2C,0x5F,0x5D,0x02,0x00,0x81,0x1C,0x3D,0x03,0x02,0x01,0x09,0x0A,0x0B,0x0C,0x0D,
0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,
0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,
0x2E,0x2F,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,
0x3E,0x3F,0x40,0x41,0x42,0x02,0x02,0x03,0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,0x69,
0x6E,0x74,0x00,0x00,0x01,0x03,0x73,0x74,0x72,0x00,0x00,0x01,0x04,0x6C,0x69,0x73,
0x74,0x00,0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,0x01,0x01,0x78,0x00,0x00,
0x01,0x04,0x70,0x72,0x6F,0x64,0x03,0x00,0x25,0x03,0x03,0x02,0x08,0x04,0x01,0x10,
0x0C,0x08,0x03,0x13,0x19,0x08,0x03,0x6C,0x69,0x74,0x01,0x00,0x10,0x10,0x20,0x22,
0x24,0x26,0x29,0x2C,0x0B,0x12,0x01,0x1D,0x38,0x3A,0x3C,0x3D,0x34,0x08,0x01,0x29,
0x00,0x01,0x01,0x02,0x63,0x66,0x01,0x00,0x16,0x08,0x28,0x01,0x2B,0x0F,0x10,0x0D,
0x0E,0x08,0x03,0x6F,0x70,0x74,0x01,0x00,0x02,0x02,0x0E,0x08,0x06,0x6C,0x61,0x79,
0x6F,0x75,0x74,0x00,0x00,0x01,0x09,0x69,0x74,0x65,0x72,0x2D,0x73,0x74,0x61,0x72,
0x01,0x00,0x06,0x03,0x10,0x1B,0x08,0x04,0x73,0x6F,0x72,0x74,0x01,0x00,0x0E,0x0E,
0x11,0x39,0x30,0x3B,0x35,0x36,0x31,0x2F,0x2E,0x42,0x2A,0x41,0x1E,0x08,0x04,0x43,
0x48,0x41,0x52,0x00,0x01,0x01,0x01,0x28,0x00,0x01,0x01,0x05,0x61,0x74,0x74,0x72,
0x73,0x01,0x00,0x10,0x02,0x02,0x08,0x04,0x74,0x65,0x72,0x6D,0x01,0x00,0x10,0x02,
0x15,0x08,0x04,0x63,0x6F,0x6E,0x73,0x01,0x00,0x10,0x10,0x1F,0x21,0x23,0x25,0x27,
0x2D,0x16,0x37,0x38,0x3A,0x3E,0x3F,0x32,0x33,0x34,0x08,0x13,0x6C,0x65,0x78,0x69,
0x63,0x61,0x6C,0x2D,0x63,0x6F,0x6E,0x73,0x74,0x72,0x75,0x63,0x74,0x6F,0x72,0x00,
0x01,0x01,0x04,0x61,0x70,0x70,0x6C,0x02,0x00,0x2C,0x03,0x1A,0x09,0x08,0x04,0x02,
0x03,0x01,0x08,0x03,0x6C,0x65,0x78,0x01,0x00,0x04,0x02,0x10,0x08,0x08,0x6E,0x6F,
0x2D,0x61,0x74,0x74,0x72,0x73,0x00,0x00,0x01,0x04,0x6C,0x69,0x73,0x74,0x01,0x00,
0x08,0x03,0x0C,0x0F,0x08,0x0A,0x63,0x68,0x61,0x72,0x2D,0x63,0x6C,0x61,0x73,0x73,
0x01,0x00,0x02,0x02,0x02,0x08,0x05,0x72,0x61,0x6E,0x67,0x65,0x02,0x00,0x02,0x02,
0x00,0x08,0x02,0x00,0x08,0x01,0x3D,0x00,0x01,0x01,0x0D,0x41,0x53,0x46,0x2D,0x43,
0x6F,0x6E,0x64,0x69,0x74,0x69,0x6F,0x6E,0x00,0x01,0x01,0x08,0x70,0x6F,0x73,0x69,
0x74,0x69,0x76,0x65,0x00,0x01,0x01,0x02,0x21,0x3D,0x00,0x01,0x01,0x08,0x6E,0x65,
0x67,0x61,0x74,0x69,0x76,0x65,0x00,0x01,0x01,0x02,0x3D,0x3D,0x00,0x01,0x01,0x08,
0x65,0x71,0x75,0x61,0x6C,0x69,0x74,0x79,0x00,0x01,0x01,0x02,0x3A,0x3D,0x00,0x01,
0x01,0x05,0x6D,0x61,0x74,0x63,0x68,0x00,0x01,0x01,0x03,0x21,0x3A,0x3D,0x00,0x01,
0x01,0x08,0x6E,0x6F,0x2D,0x6D,0x61,0x74,0x63,0x68,0x00,0x01,0x01,0x08,0x69,0x74,
0x65,0x72,0x2D,0x73,0x65,0x70,0x02,0x00,0x02,0x02,0x10,0x08,0x02,0x0A,0x08,0x01,
0x2C,0x00,0x01,0x01,0x0E,0x41,0x53,0x46,0x2D,0x43,0x6F,0x6E,0x64,0x69,0x74,0x69,
0x6F,0x6E,0x73,0x00,0x01,0x01,0x0D,0x69,0x74,0x65,0x72,0x2D,0x73,0x74,0x61,0x72,
0x2D,0x73,0x65,0x70,0x02,0x00,0x02,0x02,0x01,0x08,0x02,0x0A,0x08,0x03,0x61,0x6D,
0x62,0x00,0x01,0x01,0x15,0x61,0x6D,0x62,0x69,0x67,0x75,0x69,0x74,0x79,0x2D,0x63,
0x6F,0x6E,0x73,0x74,0x72,0x75,0x63,0x74,0x6F,0x72,0x00,0x01,0x01,0x0B,0x41,0x53,
0x46,0x2D,0x49,0x6D,0x70,0x6C,0x69,0x65,0x73,0x00,0x01,0x01,0x0C,0x41,0x53,0x46,
0x2D,0x45,0x71,0x75,0x61,0x74,0x69,0x6F,0x6E,0x00,0x01,0x01,0x07,0x41,0x53,0x46,
0x2D,0x54,0x61,0x67,0x00,0x01,0x01,0x17,0x41,0x53,0x46,0x2D,0x43,0x6F,0x6E,0x64,
0x69,0x74,0x69,0x6F,0x6E,0x61,0x6C,0x45,0x71,0x75,0x61,0x74,0x69,0x6F,0x6E,0x00,
0x01,0x01,0x06,0x73,0x69,0x6D,0x70,0x6C,0x65,0x00,0x01,0x01,0x07,0x69,0x6D,0x70,
0x6C,0x69,0x65,0x73,0x00,0x01,0x01,0x04,0x77,0x68,0x65,0x6E,0x00,0x01,0x01,0x0B,
0x41,0x53,0x46,0x2D,0x53,0x65,0x63,0x74,0x69,0x6F,0x6E,0x00,0x01,0x01,0x0A,0x41,
0x53,0x46,0x2D,0x4D,0x6F,0x64,0x75,0x6C,0x65,0x00,0x01,0x01,0x07,0x64,0x65,0x66,
0x61,0x75,0x6C,0x74,0x00,0x01,0x01,0x09,0x65,0x71,0x75,0x61,0x74,0x69,0x6F,0x6E,
0x73,0x00,0x01,0x01,0x10,0x41,0x53,0x46,0x2D,0x54,0x65,0x73,0x74,0x45,0x71,0x75,
0x61,0x74,0x69,0x6F,0x6E,0x00,0x01,0x01,0x05,0x74,0x65,0x73,0x74,0x73,0x00,0x01,
0x01,0x09,0x41,0x53,0x46,0x2D,0x54,0x61,0x67,0x49,0x64,0x00,0x01,0x01,0x01,0x5D,
0x00,0x01,0x01,0x01,0x5B,0x00,0x01,0x01,0x05,0x65,0x6D,0x70,0x74,0x79,0x00,0x01,
0x01,0x09,0x6E,0x6F,0x74,0x2D,0x65,0x6D,0x70,0x74,0x79,0x00,0x01,0x01,0x09,0x70,
0x61,0x72,0x73,0x65,0x74,0x72,0x65,0x65,0x02,0x00,0x0C,0x02,0x17,0x08,0x02,0x01,
0x08,0x07,0x3C,0x53,0x54,0x41,0x52,0x54,0x3E,0x00,0x01,0x01,0x04,0x54,0x72,0x65,
0x65,0x00,0x01,0x01,0x02,0x82,0x71,0x80,0x0E,0x41,0xC1,0x00,0xF1,0xD8,0xA0,0x6C,
0x30,0x0E,0x2B,0x1C,0x10,0x58,0x10,0xCC,0x48,0x11,0x30,0xA0,0x59,0x18,0xD0,0x0C,
0x18,0x7A,0x2C,0x04,0x3A,0x1C,0x04,0x5A,0x3C,0x07,0x83,0x40,0x46,0xA2,0x20,0x1C,
0x2A,0x12,0x11,0x28,0xC8,0x14,0x14,0x09,0xC8,0xA8,0x86,0x43,0x45,0x14,0x8E,0x82,
0x40,0xC6,0x22,0x61,0x10,0xB1,0x08,0xD8,0x04,0x1C,0x7C,0x2E,0x1E,0x0F,0x17,0x0F,
0x83,0x80,0x26,0xC2,0x11,0x60,0x89,0x44,0xC3,0x10,0x60,0x49,0xD0,0xA4,0xA1,0xA0,
0xC9,0x50,0xE4,0x28,0x0A,0x64,0x25,0x12,0x0A,0x91,0x0D,0x40,0x81,0xA7,0x82,0xD1,
0xC0,0xE9,0x60,0xF4,0x30,0x06,0x68,0x23,0x14,0x09,0x92,0x0C,0xC1,0x01,0x67,0x02,
0xB1,0x80,0xD9,0x40,0xEC,0x20,0x0E,0x60,0x27,0x10,0x0B,0x85,0x10,0x0D,0xC0,0x01,
0xF0,0xB1,0x82,0x63,0x14,0x14,0x12,0xE1,0x88,0x34,0x91,0x51,0x21,0x81,0x8C,0x48,
0x48,0x09,0x14,0x3A,0x2B,0xC1,0x85,0x85,0x78,0x61,0x01,0xE1,0x8C,0x14,0x19,0xB8,
0x61,0x14,0x4D,0x80,0x11,0x00,0x7E,0x10,0x03,0xE1,0x01,0x11,0x0D,0x15,0xD0,0x22,
0x22,0x42,0x30,0x82,0x08,0xC1,0x0B,0x14,0xDC,0x44,0x80,0x10,0x85,0x45,0x7C,0x28,
0xA8,0x88,0x8C,0x20,0xC2,0x31,0x42,0x29,0x37,0x11,0x20,0x04,0x20,0x51,0x5C,0x86,
0x26,0x26,0x23,0x08,0x28,0x8C,0x30,0xA8,0x4D,0xC4,0x48,0x01,0x08,0x64,0x57,0xA3,
0x8B,0x88,0x48,0xC2,0x0E,0x23,0x1C,0x26,0xE3,0x71,0x12,0x00,0x42,0x09,0x15,0xD8,
0x12,0x12,0x52,0x30,0x82,0x48,0xC0,0x8B,0x98,0xDC,0x44,0x80,0x10,0x84,0x45,0x7E,
0x24,0xA4,0x8C,0x8C,0x20,0xD2,0x31,0x22,0x1A,0x37,0x11,0x20,0x04,0x20,0x11,0x5C,
0x45,0x25,0x27,0x23,0x08,0x2C,0x8C,0x28,0xA4,0x8D,0xC4,0x48,0x01,0x08,0x78,0x57,
0x93,0x4B,0x48,0x28,0xC2,0x0F,0x23,0x1A,0x25,0xC3,0x71,0x12,0x00,0x42,0x0E,0x15,
0xD4,0x32,0x32,0x4A,0x30,0x82,0x28,0xC1,0x8B,0x50,0xDC,0x44,0x80,0x10,0x85,0x85,
0x7D,0x2C,0xAC,0x8A,0x8C,0x20,0xCA,0x31,0x62,0x38,0x37,0x11,0x20,0x04,0x20,0x61,
0x89,0xC9,0xCB,0x68,0xC1,0x85,0xA3,0x08,0x26,0x8C,0x60,0x1A,0x30,0x83,0xA8,0x44,
0x1C,0x35,0x18,0x41,0x54,0x60,0x92,0xB1,0x00,0xE8,0xE4,0x08,0x3A,0x10,0xC4,0x00,
0x0C,0x40,0x1F,0x44,0x00,0xF4,0x40,0x17,0x42,0x20,0x7E,0x0D,0x0C,0x5E,0x5E,0x42,
0xC6,0x0C,0x73,0x18,0x40,0xCC,0x60,0x85,0x31,0x84,0x04,0xC6,0x18,0x63,0x18,0x40,
0x8C,0x63,0x12,0xB0,0x82,0x58,0xE2,0x04,0x5A,0x16,0xC4,0x00,0x6C,0x40,0x1A,0xC4,
0x00,0xAC,0x40,0x00,0x41,0x43,0x10,0x50,0x53,0xB1,0x83,0x18,0xC5,0x63,0x07,0xB1,
0xCC,0x18,0x34,0x00,0x84,0x86,0x28,0xA8,0xA2,0xE1,0x08,0xB1,0x9C,0x61,0x02,0x71,
0x8D,0x11,0xC6,0x10,0x07,0x08,0xC1,0xA4,0x60,0x85,0x71,0xC2,0x04,0xD4,0x27,0x84,
0x20,0x1E,0x20,0x0E,0xE2,0x00,0x6E,0x20,0x00,0xE0,0x21,0x89,0x29,0x29,0x78,0x42,
0x08,0xE2,0x31,0x43,0x78,0xE5,0x0A,0x2A,0x07,0xC2,0x10,0x37,0x0E,0x0C,0x45,0x59,
0x57,0xC4,0xA0,0xB2,0xD4,0x3F,0x91,0x64,0x45,0x28,0x7E,0x35,0x00,0x00,0x00,0x00,
0x01,0x7F,0x80,0x00,0x00,0x48,0x43,0x06,0x22,0x8A,0x0C,0x08,0x24,0x01,0x02,0x40,
0x00,0x24,0x14,0x82,0x0C,0x0F,0x83,0x02,0x00,0x81,0x81,0x04,0x40,0x60,0x7C,0x00,
0x10,0x0F,0xF4,0x4D,0x45,0x54,0x22,0x09,0xA0,0x84,0xC2,0x0C,0x13,0x0E,0xC4,0x1C,
0x94,0x30,0x61,0x38,0xC1,0x92,0x84,0x88,0x82,0x02,0x24,0x01,0xC2,0x8A,0xA1,0x07,
0x21,0x0F,0xE8,0x86,0xAA,0x8C,0x44,0x51,0x46,0x89,0x84,0x0A,0x26,0x3D,0x98,0xE9,
0x28,0xE1,0x62,0x73,0x87,0x05,0x00,0x91,0x14,0x3C,0x48,0x01,0xC5,0x17,0x46,0x1E,
0x42,0x2F,0xD0,0x20,0x83,0xF4,0x0F,0x83,0x7C,0x00,0xBE,0x89,0x69,0xAA,0x24,0xC0,
0x70,0x93,0x29,0x02,0x12,0x4E,0x08,0x17,0x21,0x92,0x8A,0x60,0x80,0xA1,0x13,0xE8,
0xB6,0xBA,0xBA,0x48,0x01,0xA4,0xC2,0x0A,0x91,0x0C,0x90,0x52,0x61,0x03,0xE1,0x72,
0x0B,0x24,0x01,0x32,0x40,0x03,0x22,0x18,0x7E,0x01,0xF4,0x47,0x43,0x57,0x26,0x0C,
0x1C,0x98,0x41,0xB2,0x63,0x80,0xD1,0x08,0x80,0x86,0x1D,0xE8,0xAE,0xA6,0x89,0x4C,
0x18,0xC5,0x30,0x81,0x14,0xC1,0x08,0x53,0x08,0x01,0x4C,0x30,0xF9,0x30,0x81,0xE4,
0xC7,0x24,0x21,0x02,0xD8,0x37,0xA2,0x7A,0x5A,0xA5,0x30,0x63,0xE4,0x84,0x60,0x01,
0x0A,0xF4,0x5F,0x5B,0x4C,0xA4,0x91,0x52,0x64,0x3F,0x81,0x7A,0x04,0x11,0x9E,0x81,
0xF0,0x27,0x80,0x23,0xD0,0x4A,0x90,0x00,0xA9,0x00,0x72,0x88,0xE0,0xB0,0x20,0x40,
0x7A,0x07,0xC1,0xEE,0x00,0x77,0x45,0x0C,0x74,0x1A,0x23,0x87,0xA9,0x84,0x0E,0xA2,
0x05,0xC2,0xD4,0xC2,0x03,0x53,0x11,0xCA,0x58,0x1A,0xA6,0x10,0x2A,0x88,0x93,0x20,
0x09,0x11,0xA7,0x24,0x49,0x90,0xED,0x20,0x06,0xD2,0x00,0xAD,0x10,0x20,0xB4,0x80,
0x33,0x51,0x02,0x51,0x14,0x04,0xD2,0x00,0x55,0x16,0xE8,0xB1,0xAE,0x8F,0x44,0x2A,
0x86,0xE9,0x84,0x0B,0xA2,0x04,0x4E,0x98,0x40,0x3A,0x61,0x29,0x00,0xD1,0x0D,0x52,
0xCC,0x01,0x45,0xE9,0xC5,0x0A,0xA4,0x10,0xC4,0x28,0x83,0x20,0x00,0x31,0x02,0x3F,
0x48,0x01,0xF5,0x12,0x23,0x09,0x40,0x4D,0x06,0xE8,0x25,0x46,0xBA,0x07,0xC0,0xAE,
0x8A,0x99,0xEB,0x0C,0xC1,0x42,0x20,0xD4,0x89,0x02,0x34,0x44,0x9C,0x15,0x08,0x97,
0x44,0xCD,0xF5,0xC6,0x40,0x0C,0x66,0x10,0x51,0x88,0x36,0x02,0x92,0xC1,0xA0,0x4C,
0xE6,0x8D,0x12,0x1A,0x64,0x00,0xA6,0x40,0x12,0x62,0x0C,0x7E,0x01,0x74,0x5C,0xC0,
0xCE,0x64,0x01,0x66,0x61,0x01,0x98,0x8B,0x20,0x29,0x2C,0x06,0x3C,0xCE,0x18,0x36,
0x20,0x96,0x40,0x11,0x64,0x00,0x16,0x22,0xC7,0xE0,0xE7,0x44,0x2D,0x0D,0x56,0x40,
0x05,0x66,0x10,0x65,0x88,0x74,0x02,0x92,0xC1,0x61,0xAC,0xE5,0x8B,0x22,0x13,0x64,
0x00,0x36,0x40,0x1D,0x62,0x1C,0x7E,0x06,0x74,0x52,0xC8,0xC7,0x64,0x01,0xB6,0x61,
0x02,0xD8,0x8F,0x00,0x29,0x2C,0x0E,0x2E,0xCE,0x38,0x74,0x20,0x0E,0x40,0x1F,0x64,
0x00,0xF6,0x23,0xC7,0xE0,0xA7,0x44,0xAD,0x8D,0xD2,0x58,0x3C,0x43,0x9C,0xF1,0xE0,
0x41,0x64,0x13,0xA2,0xD6,0x26,0x47,0x25,0x8B,0x95,0x4A,0xE1,0xFC,0x31,0xD8,0x1D,
0x40
};

void init_ASFME_dict()
{
  ATermList afuns, terms;

  _ASFME_dict = (ATermList)ATreadFromBinaryString(_ASFME_dict_baf, _ASFME_dict_LEN);

  ATprotect((ATerm *)&_ASFME_dict);

  afuns = (ATermList)ATelementAt(_ASFME_dict, 0);

  ASF_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun16 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun17 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun18 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun19 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun20 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun21 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun22 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun23 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun24 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun25 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun26 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun27 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun28 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun29 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun30 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun31 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun32 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun33 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun34 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun35 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun36 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun37 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun38 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun39 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun40 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun41 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun42 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun43 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun44 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun45 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun46 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun47 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun48 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun49 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun50 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun51 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun52 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun53 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun54 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun55 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun56 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ASF_afun57 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt(_ASFME_dict, 1);

  ASF_patternOptLayoutPresent = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternOptLayoutAbsent = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternStartASFCondition = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternStartASFConditions = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternStartTree = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternStartASFImplies = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternStartASFEquation = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternStartASFConditionalEquation = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternStartASFModule = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternStartASFSection = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternStartASFTagId = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternStartASFTag = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternStartASFTestEquation = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFTestEquationWhen = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFTestEquationImplies = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFTestEquationSimple = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFTagNotEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFTagEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFTagIdManyChars = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFTagIdOneChar = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFTestEquationTestListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFTestEquationTestListSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFTestEquationTestListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFConditionalEquationListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFConditionalEquationListSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFConditionalEquationListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFSectionTests = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFSectionEquations = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFSectionListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFSectionListSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFSectionListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFModuleDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFEquationDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFConditionalEquationWhen = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFConditionalEquationImplies = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFConditionalEquationSimple = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFImpliesDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternCHARListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternCHARListSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternCHARListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternTreeAmbsMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternTreeAmbsSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternTreeAmbsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternTreeLexicalConstructor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternTreeAmbiguityConstructor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFConditionListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFConditionListSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFConditionsDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFConditionNoMatch = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFConditionMatch = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFConditionEquality = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFConditionNegative = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternASFConditionPositive = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternCHARDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  ASF_patternProductionLexicalConstructor = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
