#ifndef _ASFME_H
#define _ASFME_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "ASFME_dict.h"

typedef struct _ASF_OptLayout *ASF_OptLayout;
typedef struct _ASF_Layout *ASF_Layout;
typedef struct _ASF_LexLayoutList *ASF_LexLayoutList;
typedef struct _ASF_Tree *ASF_Tree;
typedef struct _ASF_LexCHAR *ASF_LexCHAR;
typedef struct _ASF_CHAR *ASF_CHAR;
typedef struct _ASF_ASFCondition *ASF_ASFCondition;
typedef struct _ASF_ASFConditions *ASF_ASFConditions;
typedef struct _ASF_ASFConditionList *ASF_ASFConditionList;
typedef struct _ASF_TreeAmbs *ASF_TreeAmbs;
typedef struct _ASF_CHARList *ASF_CHARList;
typedef struct _ASF_LexASFBarEnd *ASF_LexASFBarEnd;
typedef struct _ASF_ASFBarEnd *ASF_ASFBarEnd;
typedef struct _ASF_LexASFImplies *ASF_LexASFImplies;
typedef struct _ASF_ASFImplies *ASF_ASFImplies;
typedef struct _ASF_ASFConditionalEquation *ASF_ASFConditionalEquation;
typedef struct _ASF_ASFEquation *ASF_ASFEquation;
typedef struct _ASF_Start *ASF_Start;
typedef struct _ASF_ASFModule *ASF_ASFModule;
typedef struct _ASF_ASFSection *ASF_ASFSection;
typedef struct _ASF_ASFSectionList *ASF_ASFSectionList;
typedef struct _ASF_ASFConditionalEquationList *ASF_ASFConditionalEquationList;
typedef struct _ASF_ASFTestEquationTestList *ASF_ASFTestEquationTestList;
typedef struct _ASF_LexASFTagId *ASF_LexASFTagId;
typedef struct _ASF_ASFTagId *ASF_ASFTagId;
typedef struct _ASF_ASFTag *ASF_ASFTag;
typedef struct _ASF_ASFTestEquation *ASF_ASFTestEquation;
typedef struct _ASF_LexLayout *ASF_LexLayout;
typedef struct _ASF_LexNumChar *ASF_LexNumChar;
typedef struct _ASF_NumChar *ASF_NumChar;
typedef struct _ASF_LexShortChar *ASF_LexShortChar;
typedef struct _ASF_ShortChar *ASF_ShortChar;
typedef struct _ASF_Character *ASF_Character;

#ifdef FAST_API
#define ASF_initASFMEApi() (init_ASFME_dict())
#else
void _ASF_initASFMEApi(void);
#define ASF_initASFMEApi() (_ASF_initASFMEApi())
#endif

#ifdef FAST_API
#define ASF_protectOptLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectOptLayout(ASF_OptLayout *arg);
#define ASF_protectOptLayout(arg) (_ASF_protectOptLayout(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectOptLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectOptLayout(ASF_OptLayout *arg);
#define ASF_unprotectOptLayout(arg) (_ASF_unprotectOptLayout(arg))
#endif
#ifdef FAST_API
#define ASF_protectLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectLayout(ASF_Layout *arg);
#define ASF_protectLayout(arg) (_ASF_protectLayout(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectLayout(ASF_Layout *arg);
#define ASF_unprotectLayout(arg) (_ASF_unprotectLayout(arg))
#endif
#ifdef FAST_API
#define ASF_protectLexLayoutList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectLexLayoutList(ASF_LexLayoutList *arg);
#define ASF_protectLexLayoutList(arg) (_ASF_protectLexLayoutList(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectLexLayoutList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectLexLayoutList(ASF_LexLayoutList *arg);
#define ASF_unprotectLexLayoutList(arg) (_ASF_unprotectLexLayoutList(arg))
#endif
#ifdef FAST_API
#define ASF_protectTree(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectTree(ASF_Tree *arg);
#define ASF_protectTree(arg) (_ASF_protectTree(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectTree(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectTree(ASF_Tree *arg);
#define ASF_unprotectTree(arg) (_ASF_unprotectTree(arg))
#endif
#ifdef FAST_API
#define ASF_protectLexCHAR(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectLexCHAR(ASF_LexCHAR *arg);
#define ASF_protectLexCHAR(arg) (_ASF_protectLexCHAR(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectLexCHAR(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectLexCHAR(ASF_LexCHAR *arg);
#define ASF_unprotectLexCHAR(arg) (_ASF_unprotectLexCHAR(arg))
#endif
#ifdef FAST_API
#define ASF_protectCHAR(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectCHAR(ASF_CHAR *arg);
#define ASF_protectCHAR(arg) (_ASF_protectCHAR(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectCHAR(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectCHAR(ASF_CHAR *arg);
#define ASF_unprotectCHAR(arg) (_ASF_unprotectCHAR(arg))
#endif
#ifdef FAST_API
#define ASF_protectASFCondition(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectASFCondition(ASF_ASFCondition *arg);
#define ASF_protectASFCondition(arg) (_ASF_protectASFCondition(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectASFCondition(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectASFCondition(ASF_ASFCondition *arg);
#define ASF_unprotectASFCondition(arg) (_ASF_unprotectASFCondition(arg))
#endif
#ifdef FAST_API
#define ASF_protectASFConditions(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectASFConditions(ASF_ASFConditions *arg);
#define ASF_protectASFConditions(arg) (_ASF_protectASFConditions(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectASFConditions(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectASFConditions(ASF_ASFConditions *arg);
#define ASF_unprotectASFConditions(arg) (_ASF_unprotectASFConditions(arg))
#endif
#ifdef FAST_API
#define ASF_protectASFConditionList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectASFConditionList(ASF_ASFConditionList *arg);
#define ASF_protectASFConditionList(arg) (_ASF_protectASFConditionList(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectASFConditionList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectASFConditionList(ASF_ASFConditionList *arg);
#define ASF_unprotectASFConditionList(arg) (_ASF_unprotectASFConditionList(arg))
#endif
#ifdef FAST_API
#define ASF_protectTreeAmbs(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectTreeAmbs(ASF_TreeAmbs *arg);
#define ASF_protectTreeAmbs(arg) (_ASF_protectTreeAmbs(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectTreeAmbs(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectTreeAmbs(ASF_TreeAmbs *arg);
#define ASF_unprotectTreeAmbs(arg) (_ASF_unprotectTreeAmbs(arg))
#endif
#ifdef FAST_API
#define ASF_protectCHARList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectCHARList(ASF_CHARList *arg);
#define ASF_protectCHARList(arg) (_ASF_protectCHARList(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectCHARList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectCHARList(ASF_CHARList *arg);
#define ASF_unprotectCHARList(arg) (_ASF_unprotectCHARList(arg))
#endif
#ifdef FAST_API
#define ASF_protectLexASFBarEnd(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectLexASFBarEnd(ASF_LexASFBarEnd *arg);
#define ASF_protectLexASFBarEnd(arg) (_ASF_protectLexASFBarEnd(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectLexASFBarEnd(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectLexASFBarEnd(ASF_LexASFBarEnd *arg);
#define ASF_unprotectLexASFBarEnd(arg) (_ASF_unprotectLexASFBarEnd(arg))
#endif
#ifdef FAST_API
#define ASF_protectASFBarEnd(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectASFBarEnd(ASF_ASFBarEnd *arg);
#define ASF_protectASFBarEnd(arg) (_ASF_protectASFBarEnd(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectASFBarEnd(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectASFBarEnd(ASF_ASFBarEnd *arg);
#define ASF_unprotectASFBarEnd(arg) (_ASF_unprotectASFBarEnd(arg))
#endif
#ifdef FAST_API
#define ASF_protectLexASFImplies(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectLexASFImplies(ASF_LexASFImplies *arg);
#define ASF_protectLexASFImplies(arg) (_ASF_protectLexASFImplies(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectLexASFImplies(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectLexASFImplies(ASF_LexASFImplies *arg);
#define ASF_unprotectLexASFImplies(arg) (_ASF_unprotectLexASFImplies(arg))
#endif
#ifdef FAST_API
#define ASF_protectASFImplies(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectASFImplies(ASF_ASFImplies *arg);
#define ASF_protectASFImplies(arg) (_ASF_protectASFImplies(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectASFImplies(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectASFImplies(ASF_ASFImplies *arg);
#define ASF_unprotectASFImplies(arg) (_ASF_unprotectASFImplies(arg))
#endif
#ifdef FAST_API
#define ASF_protectASFConditionalEquation(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectASFConditionalEquation(ASF_ASFConditionalEquation *arg);
#define ASF_protectASFConditionalEquation(arg) (_ASF_protectASFConditionalEquation(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectASFConditionalEquation(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectASFConditionalEquation(ASF_ASFConditionalEquation *arg);
#define ASF_unprotectASFConditionalEquation(arg) (_ASF_unprotectASFConditionalEquation(arg))
#endif
#ifdef FAST_API
#define ASF_protectASFEquation(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectASFEquation(ASF_ASFEquation *arg);
#define ASF_protectASFEquation(arg) (_ASF_protectASFEquation(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectASFEquation(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectASFEquation(ASF_ASFEquation *arg);
#define ASF_unprotectASFEquation(arg) (_ASF_unprotectASFEquation(arg))
#endif
#ifdef FAST_API
#define ASF_protectStart(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectStart(ASF_Start *arg);
#define ASF_protectStart(arg) (_ASF_protectStart(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectStart(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectStart(ASF_Start *arg);
#define ASF_unprotectStart(arg) (_ASF_unprotectStart(arg))
#endif
#ifdef FAST_API
#define ASF_protectASFModule(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectASFModule(ASF_ASFModule *arg);
#define ASF_protectASFModule(arg) (_ASF_protectASFModule(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectASFModule(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectASFModule(ASF_ASFModule *arg);
#define ASF_unprotectASFModule(arg) (_ASF_unprotectASFModule(arg))
#endif
#ifdef FAST_API
#define ASF_protectASFSection(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectASFSection(ASF_ASFSection *arg);
#define ASF_protectASFSection(arg) (_ASF_protectASFSection(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectASFSection(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectASFSection(ASF_ASFSection *arg);
#define ASF_unprotectASFSection(arg) (_ASF_unprotectASFSection(arg))
#endif
#ifdef FAST_API
#define ASF_protectASFSectionList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectASFSectionList(ASF_ASFSectionList *arg);
#define ASF_protectASFSectionList(arg) (_ASF_protectASFSectionList(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectASFSectionList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectASFSectionList(ASF_ASFSectionList *arg);
#define ASF_unprotectASFSectionList(arg) (_ASF_unprotectASFSectionList(arg))
#endif
#ifdef FAST_API
#define ASF_protectASFConditionalEquationList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectASFConditionalEquationList(ASF_ASFConditionalEquationList *arg);
#define ASF_protectASFConditionalEquationList(arg) (_ASF_protectASFConditionalEquationList(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectASFConditionalEquationList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectASFConditionalEquationList(ASF_ASFConditionalEquationList *arg);
#define ASF_unprotectASFConditionalEquationList(arg) (_ASF_unprotectASFConditionalEquationList(arg))
#endif
#ifdef FAST_API
#define ASF_protectASFTestEquationTestList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectASFTestEquationTestList(ASF_ASFTestEquationTestList *arg);
#define ASF_protectASFTestEquationTestList(arg) (_ASF_protectASFTestEquationTestList(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectASFTestEquationTestList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectASFTestEquationTestList(ASF_ASFTestEquationTestList *arg);
#define ASF_unprotectASFTestEquationTestList(arg) (_ASF_unprotectASFTestEquationTestList(arg))
#endif
#ifdef FAST_API
#define ASF_protectLexASFTagId(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectLexASFTagId(ASF_LexASFTagId *arg);
#define ASF_protectLexASFTagId(arg) (_ASF_protectLexASFTagId(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectLexASFTagId(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectLexASFTagId(ASF_LexASFTagId *arg);
#define ASF_unprotectLexASFTagId(arg) (_ASF_unprotectLexASFTagId(arg))
#endif
#ifdef FAST_API
#define ASF_protectASFTagId(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectASFTagId(ASF_ASFTagId *arg);
#define ASF_protectASFTagId(arg) (_ASF_protectASFTagId(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectASFTagId(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectASFTagId(ASF_ASFTagId *arg);
#define ASF_unprotectASFTagId(arg) (_ASF_unprotectASFTagId(arg))
#endif
#ifdef FAST_API
#define ASF_protectASFTag(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectASFTag(ASF_ASFTag *arg);
#define ASF_protectASFTag(arg) (_ASF_protectASFTag(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectASFTag(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectASFTag(ASF_ASFTag *arg);
#define ASF_unprotectASFTag(arg) (_ASF_unprotectASFTag(arg))
#endif
#ifdef FAST_API
#define ASF_protectASFTestEquation(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectASFTestEquation(ASF_ASFTestEquation *arg);
#define ASF_protectASFTestEquation(arg) (_ASF_protectASFTestEquation(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectASFTestEquation(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectASFTestEquation(ASF_ASFTestEquation *arg);
#define ASF_unprotectASFTestEquation(arg) (_ASF_unprotectASFTestEquation(arg))
#endif
#ifdef FAST_API
#define ASF_protectLexLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectLexLayout(ASF_LexLayout *arg);
#define ASF_protectLexLayout(arg) (_ASF_protectLexLayout(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectLexLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectLexLayout(ASF_LexLayout *arg);
#define ASF_unprotectLexLayout(arg) (_ASF_unprotectLexLayout(arg))
#endif
#ifdef FAST_API
#define ASF_protectLexNumChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectLexNumChar(ASF_LexNumChar *arg);
#define ASF_protectLexNumChar(arg) (_ASF_protectLexNumChar(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectLexNumChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectLexNumChar(ASF_LexNumChar *arg);
#define ASF_unprotectLexNumChar(arg) (_ASF_unprotectLexNumChar(arg))
#endif
#ifdef FAST_API
#define ASF_protectNumChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectNumChar(ASF_NumChar *arg);
#define ASF_protectNumChar(arg) (_ASF_protectNumChar(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectNumChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectNumChar(ASF_NumChar *arg);
#define ASF_unprotectNumChar(arg) (_ASF_unprotectNumChar(arg))
#endif
#ifdef FAST_API
#define ASF_protectLexShortChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectLexShortChar(ASF_LexShortChar *arg);
#define ASF_protectLexShortChar(arg) (_ASF_protectLexShortChar(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectLexShortChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectLexShortChar(ASF_LexShortChar *arg);
#define ASF_unprotectLexShortChar(arg) (_ASF_unprotectLexShortChar(arg))
#endif
#ifdef FAST_API
#define ASF_protectShortChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectShortChar(ASF_ShortChar *arg);
#define ASF_protectShortChar(arg) (_ASF_protectShortChar(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectShortChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectShortChar(ASF_ShortChar *arg);
#define ASF_unprotectShortChar(arg) (_ASF_unprotectShortChar(arg))
#endif
#ifdef FAST_API
#define ASF_protectCharacter(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _ASF_protectCharacter(ASF_Character *arg);
#define ASF_protectCharacter(arg) (_ASF_protectCharacter(arg))
#endif
#ifdef FAST_API
#define ASF_unprotectCharacter(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _ASF_unprotectCharacter(ASF_Character *arg);
#define ASF_unprotectCharacter(arg) (_ASF_unprotectCharacter(arg))
#endif
#ifdef FAST_API
#define ASF_OptLayoutFromTerm(t) ((((union {ASF_OptLayout target; ATerm source; })(t)).target))
#else
ASF_OptLayout _ASF_OptLayoutFromTerm(ATerm t);
#define ASF_OptLayoutFromTerm(t) (_ASF_OptLayoutFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_OptLayoutToTerm(arg) ((((union {ASF_OptLayout source; ATerm target; })(arg)).target))
#else
ATerm _ASF_OptLayoutToTerm(ASF_OptLayout arg);
#define ASF_OptLayoutToTerm(arg) (_ASF_OptLayoutToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_LayoutFromTerm(t) ((((union {ASF_Layout target; ATerm source; })(t)).target))
#else
ASF_Layout _ASF_LayoutFromTerm(ATerm t);
#define ASF_LayoutFromTerm(t) (_ASF_LayoutFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_LayoutToTerm(arg) ((((union {ASF_Layout source; ATerm target; })(arg)).target))
#else
ATerm _ASF_LayoutToTerm(ASF_Layout arg);
#define ASF_LayoutToTerm(arg) (_ASF_LayoutToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_LexLayoutListFromTerm(t) ((((union {ASF_LexLayoutList target; ATerm source; })(t)).target))
#else
ASF_LexLayoutList _ASF_LexLayoutListFromTerm(ATerm t);
#define ASF_LexLayoutListFromTerm(t) (_ASF_LexLayoutListFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_LexLayoutListToTerm(arg) ((((union {ASF_LexLayoutList source; ATerm target; })(arg)).target))
#else
ATerm _ASF_LexLayoutListToTerm(ASF_LexLayoutList arg);
#define ASF_LexLayoutListToTerm(arg) (_ASF_LexLayoutListToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_TreeFromTerm(t) ((((union {ASF_Tree target; ATerm source; })(t)).target))
#else
ASF_Tree _ASF_TreeFromTerm(ATerm t);
#define ASF_TreeFromTerm(t) (_ASF_TreeFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_TreeToTerm(arg) ((((union {ASF_Tree source; ATerm target; })(arg)).target))
#else
ATerm _ASF_TreeToTerm(ASF_Tree arg);
#define ASF_TreeToTerm(arg) (_ASF_TreeToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_LexCHARFromTerm(t) ((((union {ASF_LexCHAR target; ATerm source; })(t)).target))
#else
ASF_LexCHAR _ASF_LexCHARFromTerm(ATerm t);
#define ASF_LexCHARFromTerm(t) (_ASF_LexCHARFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_LexCHARToTerm(arg) ((((union {ASF_LexCHAR source; ATerm target; })(arg)).target))
#else
ATerm _ASF_LexCHARToTerm(ASF_LexCHAR arg);
#define ASF_LexCHARToTerm(arg) (_ASF_LexCHARToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_CHARFromTerm(t) ((((union {ASF_CHAR target; ATerm source; })(t)).target))
#else
ASF_CHAR _ASF_CHARFromTerm(ATerm t);
#define ASF_CHARFromTerm(t) (_ASF_CHARFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_CHARToTerm(arg) ((((union {ASF_CHAR source; ATerm target; })(arg)).target))
#else
ATerm _ASF_CHARToTerm(ASF_CHAR arg);
#define ASF_CHARToTerm(arg) (_ASF_CHARToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_ASFConditionFromTerm(t) ((((union {ASF_ASFCondition target; ATerm source; })(t)).target))
#else
ASF_ASFCondition _ASF_ASFConditionFromTerm(ATerm t);
#define ASF_ASFConditionFromTerm(t) (_ASF_ASFConditionFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_ASFConditionToTerm(arg) ((((union {ASF_ASFCondition source; ATerm target; })(arg)).target))
#else
ATerm _ASF_ASFConditionToTerm(ASF_ASFCondition arg);
#define ASF_ASFConditionToTerm(arg) (_ASF_ASFConditionToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_ASFConditionsFromTerm(t) ((((union {ASF_ASFConditions target; ATerm source; })(t)).target))
#else
ASF_ASFConditions _ASF_ASFConditionsFromTerm(ATerm t);
#define ASF_ASFConditionsFromTerm(t) (_ASF_ASFConditionsFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_ASFConditionsToTerm(arg) ((((union {ASF_ASFConditions source; ATerm target; })(arg)).target))
#else
ATerm _ASF_ASFConditionsToTerm(ASF_ASFConditions arg);
#define ASF_ASFConditionsToTerm(arg) (_ASF_ASFConditionsToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_ASFConditionListFromTerm(t) ((((union {ASF_ASFConditionList target; ATerm source; })(t)).target))
#else
ASF_ASFConditionList _ASF_ASFConditionListFromTerm(ATerm t);
#define ASF_ASFConditionListFromTerm(t) (_ASF_ASFConditionListFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_ASFConditionListToTerm(arg) ((((union {ASF_ASFConditionList source; ATerm target; })(arg)).target))
#else
ATerm _ASF_ASFConditionListToTerm(ASF_ASFConditionList arg);
#define ASF_ASFConditionListToTerm(arg) (_ASF_ASFConditionListToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_TreeAmbsFromTerm(t) ((((union {ASF_TreeAmbs target; ATerm source; })(t)).target))
#else
ASF_TreeAmbs _ASF_TreeAmbsFromTerm(ATerm t);
#define ASF_TreeAmbsFromTerm(t) (_ASF_TreeAmbsFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_TreeAmbsToTerm(arg) ((((union {ASF_TreeAmbs source; ATerm target; })(arg)).target))
#else
ATerm _ASF_TreeAmbsToTerm(ASF_TreeAmbs arg);
#define ASF_TreeAmbsToTerm(arg) (_ASF_TreeAmbsToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_CHARListFromTerm(t) ((((union {ASF_CHARList target; ATerm source; })(t)).target))
#else
ASF_CHARList _ASF_CHARListFromTerm(ATerm t);
#define ASF_CHARListFromTerm(t) (_ASF_CHARListFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_CHARListToTerm(arg) ((((union {ASF_CHARList source; ATerm target; })(arg)).target))
#else
ATerm _ASF_CHARListToTerm(ASF_CHARList arg);
#define ASF_CHARListToTerm(arg) (_ASF_CHARListToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_LexASFBarEndFromTerm(t) ((((union {ASF_LexASFBarEnd target; ATerm source; })(t)).target))
#else
ASF_LexASFBarEnd _ASF_LexASFBarEndFromTerm(ATerm t);
#define ASF_LexASFBarEndFromTerm(t) (_ASF_LexASFBarEndFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_LexASFBarEndToTerm(arg) ((((union {ASF_LexASFBarEnd source; ATerm target; })(arg)).target))
#else
ATerm _ASF_LexASFBarEndToTerm(ASF_LexASFBarEnd arg);
#define ASF_LexASFBarEndToTerm(arg) (_ASF_LexASFBarEndToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_ASFBarEndFromTerm(t) ((((union {ASF_ASFBarEnd target; ATerm source; })(t)).target))
#else
ASF_ASFBarEnd _ASF_ASFBarEndFromTerm(ATerm t);
#define ASF_ASFBarEndFromTerm(t) (_ASF_ASFBarEndFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_ASFBarEndToTerm(arg) ((((union {ASF_ASFBarEnd source; ATerm target; })(arg)).target))
#else
ATerm _ASF_ASFBarEndToTerm(ASF_ASFBarEnd arg);
#define ASF_ASFBarEndToTerm(arg) (_ASF_ASFBarEndToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_LexASFImpliesFromTerm(t) ((((union {ASF_LexASFImplies target; ATerm source; })(t)).target))
#else
ASF_LexASFImplies _ASF_LexASFImpliesFromTerm(ATerm t);
#define ASF_LexASFImpliesFromTerm(t) (_ASF_LexASFImpliesFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_LexASFImpliesToTerm(arg) ((((union {ASF_LexASFImplies source; ATerm target; })(arg)).target))
#else
ATerm _ASF_LexASFImpliesToTerm(ASF_LexASFImplies arg);
#define ASF_LexASFImpliesToTerm(arg) (_ASF_LexASFImpliesToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_ASFImpliesFromTerm(t) ((((union {ASF_ASFImplies target; ATerm source; })(t)).target))
#else
ASF_ASFImplies _ASF_ASFImpliesFromTerm(ATerm t);
#define ASF_ASFImpliesFromTerm(t) (_ASF_ASFImpliesFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_ASFImpliesToTerm(arg) ((((union {ASF_ASFImplies source; ATerm target; })(arg)).target))
#else
ATerm _ASF_ASFImpliesToTerm(ASF_ASFImplies arg);
#define ASF_ASFImpliesToTerm(arg) (_ASF_ASFImpliesToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_ASFConditionalEquationFromTerm(t) ((((union {ASF_ASFConditionalEquation target; ATerm source; })(t)).target))
#else
ASF_ASFConditionalEquation _ASF_ASFConditionalEquationFromTerm(ATerm t);
#define ASF_ASFConditionalEquationFromTerm(t) (_ASF_ASFConditionalEquationFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_ASFConditionalEquationToTerm(arg) ((((union {ASF_ASFConditionalEquation source; ATerm target; })(arg)).target))
#else
ATerm _ASF_ASFConditionalEquationToTerm(ASF_ASFConditionalEquation arg);
#define ASF_ASFConditionalEquationToTerm(arg) (_ASF_ASFConditionalEquationToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_ASFEquationFromTerm(t) ((((union {ASF_ASFEquation target; ATerm source; })(t)).target))
#else
ASF_ASFEquation _ASF_ASFEquationFromTerm(ATerm t);
#define ASF_ASFEquationFromTerm(t) (_ASF_ASFEquationFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_ASFEquationToTerm(arg) ((((union {ASF_ASFEquation source; ATerm target; })(arg)).target))
#else
ATerm _ASF_ASFEquationToTerm(ASF_ASFEquation arg);
#define ASF_ASFEquationToTerm(arg) (_ASF_ASFEquationToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_StartFromTerm(t) ((((union {ASF_Start target; ATerm source; })(t)).target))
#else
ASF_Start _ASF_StartFromTerm(ATerm t);
#define ASF_StartFromTerm(t) (_ASF_StartFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_StartToTerm(arg) ((((union {ASF_Start source; ATerm target; })(arg)).target))
#else
ATerm _ASF_StartToTerm(ASF_Start arg);
#define ASF_StartToTerm(arg) (_ASF_StartToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_ASFModuleFromTerm(t) ((((union {ASF_ASFModule target; ATerm source; })(t)).target))
#else
ASF_ASFModule _ASF_ASFModuleFromTerm(ATerm t);
#define ASF_ASFModuleFromTerm(t) (_ASF_ASFModuleFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_ASFModuleToTerm(arg) ((((union {ASF_ASFModule source; ATerm target; })(arg)).target))
#else
ATerm _ASF_ASFModuleToTerm(ASF_ASFModule arg);
#define ASF_ASFModuleToTerm(arg) (_ASF_ASFModuleToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_ASFSectionFromTerm(t) ((((union {ASF_ASFSection target; ATerm source; })(t)).target))
#else
ASF_ASFSection _ASF_ASFSectionFromTerm(ATerm t);
#define ASF_ASFSectionFromTerm(t) (_ASF_ASFSectionFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_ASFSectionToTerm(arg) ((((union {ASF_ASFSection source; ATerm target; })(arg)).target))
#else
ATerm _ASF_ASFSectionToTerm(ASF_ASFSection arg);
#define ASF_ASFSectionToTerm(arg) (_ASF_ASFSectionToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_ASFSectionListFromTerm(t) ((((union {ASF_ASFSectionList target; ATerm source; })(t)).target))
#else
ASF_ASFSectionList _ASF_ASFSectionListFromTerm(ATerm t);
#define ASF_ASFSectionListFromTerm(t) (_ASF_ASFSectionListFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_ASFSectionListToTerm(arg) ((((union {ASF_ASFSectionList source; ATerm target; })(arg)).target))
#else
ATerm _ASF_ASFSectionListToTerm(ASF_ASFSectionList arg);
#define ASF_ASFSectionListToTerm(arg) (_ASF_ASFSectionListToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_ASFConditionalEquationListFromTerm(t) ((((union {ASF_ASFConditionalEquationList target; ATerm source; })(t)).target))
#else
ASF_ASFConditionalEquationList _ASF_ASFConditionalEquationListFromTerm(ATerm t);
#define ASF_ASFConditionalEquationListFromTerm(t) (_ASF_ASFConditionalEquationListFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_ASFConditionalEquationListToTerm(arg) ((((union {ASF_ASFConditionalEquationList source; ATerm target; })(arg)).target))
#else
ATerm _ASF_ASFConditionalEquationListToTerm(ASF_ASFConditionalEquationList arg);
#define ASF_ASFConditionalEquationListToTerm(arg) (_ASF_ASFConditionalEquationListToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_ASFTestEquationTestListFromTerm(t) ((((union {ASF_ASFTestEquationTestList target; ATerm source; })(t)).target))
#else
ASF_ASFTestEquationTestList _ASF_ASFTestEquationTestListFromTerm(ATerm t);
#define ASF_ASFTestEquationTestListFromTerm(t) (_ASF_ASFTestEquationTestListFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_ASFTestEquationTestListToTerm(arg) ((((union {ASF_ASFTestEquationTestList source; ATerm target; })(arg)).target))
#else
ATerm _ASF_ASFTestEquationTestListToTerm(ASF_ASFTestEquationTestList arg);
#define ASF_ASFTestEquationTestListToTerm(arg) (_ASF_ASFTestEquationTestListToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_LexASFTagIdFromTerm(t) ((((union {ASF_LexASFTagId target; ATerm source; })(t)).target))
#else
ASF_LexASFTagId _ASF_LexASFTagIdFromTerm(ATerm t);
#define ASF_LexASFTagIdFromTerm(t) (_ASF_LexASFTagIdFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_LexASFTagIdToTerm(arg) ((((union {ASF_LexASFTagId source; ATerm target; })(arg)).target))
#else
ATerm _ASF_LexASFTagIdToTerm(ASF_LexASFTagId arg);
#define ASF_LexASFTagIdToTerm(arg) (_ASF_LexASFTagIdToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_ASFTagIdFromTerm(t) ((((union {ASF_ASFTagId target; ATerm source; })(t)).target))
#else
ASF_ASFTagId _ASF_ASFTagIdFromTerm(ATerm t);
#define ASF_ASFTagIdFromTerm(t) (_ASF_ASFTagIdFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_ASFTagIdToTerm(arg) ((((union {ASF_ASFTagId source; ATerm target; })(arg)).target))
#else
ATerm _ASF_ASFTagIdToTerm(ASF_ASFTagId arg);
#define ASF_ASFTagIdToTerm(arg) (_ASF_ASFTagIdToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_ASFTagFromTerm(t) ((((union {ASF_ASFTag target; ATerm source; })(t)).target))
#else
ASF_ASFTag _ASF_ASFTagFromTerm(ATerm t);
#define ASF_ASFTagFromTerm(t) (_ASF_ASFTagFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_ASFTagToTerm(arg) ((((union {ASF_ASFTag source; ATerm target; })(arg)).target))
#else
ATerm _ASF_ASFTagToTerm(ASF_ASFTag arg);
#define ASF_ASFTagToTerm(arg) (_ASF_ASFTagToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_ASFTestEquationFromTerm(t) ((((union {ASF_ASFTestEquation target; ATerm source; })(t)).target))
#else
ASF_ASFTestEquation _ASF_ASFTestEquationFromTerm(ATerm t);
#define ASF_ASFTestEquationFromTerm(t) (_ASF_ASFTestEquationFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_ASFTestEquationToTerm(arg) ((((union {ASF_ASFTestEquation source; ATerm target; })(arg)).target))
#else
ATerm _ASF_ASFTestEquationToTerm(ASF_ASFTestEquation arg);
#define ASF_ASFTestEquationToTerm(arg) (_ASF_ASFTestEquationToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_LexLayoutFromTerm(t) ((((union {ASF_LexLayout target; ATerm source; })(t)).target))
#else
ASF_LexLayout _ASF_LexLayoutFromTerm(ATerm t);
#define ASF_LexLayoutFromTerm(t) (_ASF_LexLayoutFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_LexLayoutToTerm(arg) ((((union {ASF_LexLayout source; ATerm target; })(arg)).target))
#else
ATerm _ASF_LexLayoutToTerm(ASF_LexLayout arg);
#define ASF_LexLayoutToTerm(arg) (_ASF_LexLayoutToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_LexNumCharFromTerm(t) ((((union {ASF_LexNumChar target; ATerm source; })(t)).target))
#else
ASF_LexNumChar _ASF_LexNumCharFromTerm(ATerm t);
#define ASF_LexNumCharFromTerm(t) (_ASF_LexNumCharFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_LexNumCharToTerm(arg) ((((union {ASF_LexNumChar source; ATerm target; })(arg)).target))
#else
ATerm _ASF_LexNumCharToTerm(ASF_LexNumChar arg);
#define ASF_LexNumCharToTerm(arg) (_ASF_LexNumCharToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_NumCharFromTerm(t) ((((union {ASF_NumChar target; ATerm source; })(t)).target))
#else
ASF_NumChar _ASF_NumCharFromTerm(ATerm t);
#define ASF_NumCharFromTerm(t) (_ASF_NumCharFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_NumCharToTerm(arg) ((((union {ASF_NumChar source; ATerm target; })(arg)).target))
#else
ATerm _ASF_NumCharToTerm(ASF_NumChar arg);
#define ASF_NumCharToTerm(arg) (_ASF_NumCharToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_LexShortCharFromTerm(t) ((((union {ASF_LexShortChar target; ATerm source; })(t)).target))
#else
ASF_LexShortChar _ASF_LexShortCharFromTerm(ATerm t);
#define ASF_LexShortCharFromTerm(t) (_ASF_LexShortCharFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_LexShortCharToTerm(arg) ((((union {ASF_LexShortChar source; ATerm target; })(arg)).target))
#else
ATerm _ASF_LexShortCharToTerm(ASF_LexShortChar arg);
#define ASF_LexShortCharToTerm(arg) (_ASF_LexShortCharToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_ShortCharFromTerm(t) ((((union {ASF_ShortChar target; ATerm source; })(t)).target))
#else
ASF_ShortChar _ASF_ShortCharFromTerm(ATerm t);
#define ASF_ShortCharFromTerm(t) (_ASF_ShortCharFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_ShortCharToTerm(arg) ((((union {ASF_ShortChar source; ATerm target; })(arg)).target))
#else
ATerm _ASF_ShortCharToTerm(ASF_ShortChar arg);
#define ASF_ShortCharToTerm(arg) (_ASF_ShortCharToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_CharacterFromTerm(t) ((((union {ASF_Character target; ATerm source; })(t)).target))
#else
ASF_Character _ASF_CharacterFromTerm(ATerm t);
#define ASF_CharacterFromTerm(t) (_ASF_CharacterFromTerm(t))
#endif
#ifdef FAST_API
#define ASF_CharacterToTerm(arg) ((((union {ASF_Character source; ATerm target; })(arg)).target))
#else
ATerm _ASF_CharacterToTerm(ASF_Character arg);
#define ASF_CharacterToTerm(arg) (_ASF_CharacterToTerm(arg))
#endif
#ifdef FAST_API
#define ASF_getLexLayoutListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _ASF_getLexLayoutListLength(ASF_LexLayoutList arg);
#define ASF_getLexLayoutListLength(arg) (_ASF_getLexLayoutListLength(arg))
#endif
#ifdef FAST_API
#define ASF_reverseLexLayoutList(arg) ((ASF_LexLayoutList) ATreverse((ATermList) (arg)))
#else
ASF_LexLayoutList _ASF_reverseLexLayoutList(ASF_LexLayoutList arg);
#define ASF_reverseLexLayoutList(arg) (_ASF_reverseLexLayoutList(arg))
#endif
#ifdef FAST_API
#define ASF_appendLexLayoutList(arg, elem) ((ASF_LexLayoutList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
ASF_LexLayoutList _ASF_appendLexLayoutList(ASF_LexLayoutList arg, ASF_LexLayout elem);
#define ASF_appendLexLayoutList(arg, elem) (_ASF_appendLexLayoutList(arg, elem))
#endif
#ifdef FAST_API
#define ASF_concatLexLayoutList(arg0, arg1) ((ASF_LexLayoutList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
ASF_LexLayoutList _ASF_concatLexLayoutList(ASF_LexLayoutList arg0, ASF_LexLayoutList arg1);
#define ASF_concatLexLayoutList(arg0, arg1) (_ASF_concatLexLayoutList(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_sliceLexLayoutList(arg, start, end) ((ASF_LexLayoutList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
ASF_LexLayoutList _ASF_sliceLexLayoutList(ASF_LexLayoutList arg, int start, int end);
#define ASF_sliceLexLayoutList(arg, start, end) (_ASF_sliceLexLayoutList(arg, start, end))
#endif
#ifdef FAST_API
#define ASF_getLexLayoutListLexLayoutAt(arg, index) ((ASF_LexLayout) (ATelementAt((ATermList) arg,index)))
#else
ASF_LexLayout _ASF_getLexLayoutListLexLayoutAt(ASF_LexLayoutList arg, int index);
#define ASF_getLexLayoutListLexLayoutAt(arg, index) (_ASF_getLexLayoutListLexLayoutAt(arg, index))
#endif
#ifdef FAST_API
#define ASF_replaceLexLayoutListLexLayoutAt(arg, elem, index) ((ASF_LexLayoutList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
ASF_LexLayoutList _ASF_replaceLexLayoutListLexLayoutAt(ASF_LexLayoutList arg, ASF_LexLayout elem, int index);
#define ASF_replaceLexLayoutListLexLayoutAt(arg, elem, index) (_ASF_replaceLexLayoutListLexLayoutAt(arg, elem, index))
#endif
#ifdef FAST_API
#define ASF_makeLexLayoutList2(elem1,  elem2) ((ASF_LexLayoutList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
ASF_LexLayoutList _ASF_makeLexLayoutList2(ASF_LexLayout elem1, ASF_LexLayout elem2);
#define ASF_makeLexLayoutList2(elem1,  elem2) (_ASF_makeLexLayoutList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define ASF_makeLexLayoutList3(elem1, elem2,  elem3) ((ASF_LexLayoutList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
ASF_LexLayoutList _ASF_makeLexLayoutList3(ASF_LexLayout elem1, ASF_LexLayout elem2, ASF_LexLayout elem3);
#define ASF_makeLexLayoutList3(elem1, elem2,  elem3) (_ASF_makeLexLayoutList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define ASF_makeLexLayoutList4(elem1, elem2, elem3,  elem4) ((ASF_LexLayoutList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
ASF_LexLayoutList _ASF_makeLexLayoutList4(ASF_LexLayout elem1, ASF_LexLayout elem2, ASF_LexLayout elem3, ASF_LexLayout elem4);
#define ASF_makeLexLayoutList4(elem1, elem2, elem3,  elem4) (_ASF_makeLexLayoutList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define ASF_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5) ((ASF_LexLayoutList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
ASF_LexLayoutList _ASF_makeLexLayoutList5(ASF_LexLayout elem1, ASF_LexLayout elem2, ASF_LexLayout elem3, ASF_LexLayout elem4, ASF_LexLayout elem5);
#define ASF_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5) (_ASF_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define ASF_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((ASF_LexLayoutList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
ASF_LexLayoutList _ASF_makeLexLayoutList6(ASF_LexLayout elem1, ASF_LexLayout elem2, ASF_LexLayout elem3, ASF_LexLayout elem4, ASF_LexLayout elem5, ASF_LexLayout elem6);
#define ASF_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_ASF_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define ASF_getASFConditionListLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 4) + 1))
#else
int _ASF_getASFConditionListLength(ASF_ASFConditionList arg);
#define ASF_getASFConditionListLength(arg) (_ASF_getASFConditionListLength(arg))
#endif
ASF_ASFConditionList ASF_reverseASFConditionList(ASF_ASFConditionList arg);
ASF_ASFConditionList ASF_appendASFConditionList(ASF_ASFConditionList arg0, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition arg1);
ASF_ASFConditionList ASF_concatASFConditionList(ASF_ASFConditionList arg0, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFConditionList arg1);
#ifdef FAST_API
#define ASF_sliceASFConditionList(arg, start, end) ((ASF_ASFConditionList) ATgetSlice((ATermList) (arg), (start * 4), (end * 4)))
#else
ASF_ASFConditionList _ASF_sliceASFConditionList(ASF_ASFConditionList arg, int start, int end);
#define ASF_sliceASFConditionList(arg, start, end) (_ASF_sliceASFConditionList(arg, start, end))
#endif
#ifdef FAST_API
#define ASF_getASFConditionListASFConditionAt(arg, index) ((ASF_ASFCondition) (ATelementAt((ATermList) arg,index * 4)))
#else
ASF_ASFCondition _ASF_getASFConditionListASFConditionAt(ASF_ASFConditionList arg, int index);
#define ASF_getASFConditionListASFConditionAt(arg, index) (_ASF_getASFConditionListASFConditionAt(arg, index))
#endif
#ifdef FAST_API
#define ASF_replaceASFConditionListASFConditionAt(arg, elem, index) ((ASF_ASFConditionList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 4)))
#else
ASF_ASFConditionList _ASF_replaceASFConditionListASFConditionAt(ASF_ASFConditionList arg, ASF_ASFCondition elem, int index);
#define ASF_replaceASFConditionListASFConditionAt(arg, elem, index) (_ASF_replaceASFConditionListASFConditionAt(arg, elem, index))
#endif
ASF_ASFConditionList ASF_makeASFConditionList2(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition elem1, ASF_ASFCondition elem2);
ASF_ASFConditionList ASF_makeASFConditionList3(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition elem1, ASF_ASFCondition elem2, ASF_ASFCondition elem3);
ASF_ASFConditionList ASF_makeASFConditionList4(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition elem1, ASF_ASFCondition elem2, ASF_ASFCondition elem3, ASF_ASFCondition elem4);
ASF_ASFConditionList ASF_makeASFConditionList5(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition elem1, ASF_ASFCondition elem2, ASF_ASFCondition elem3, ASF_ASFCondition elem4, ASF_ASFCondition elem5);
ASF_ASFConditionList ASF_makeASFConditionList6(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFCondition elem1, ASF_ASFCondition elem2, ASF_ASFCondition elem3, ASF_ASFCondition elem4, ASF_ASFCondition elem5, ASF_ASFCondition elem6);
#ifdef FAST_API
#define ASF_getTreeAmbsLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 4) + 1))
#else
int _ASF_getTreeAmbsLength(ASF_TreeAmbs arg);
#define ASF_getTreeAmbsLength(arg) (_ASF_getTreeAmbsLength(arg))
#endif
ASF_TreeAmbs ASF_reverseTreeAmbs(ASF_TreeAmbs arg);
ASF_TreeAmbs ASF_appendTreeAmbs(ASF_TreeAmbs arg0, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_Tree arg1);
ASF_TreeAmbs ASF_concatTreeAmbs(ASF_TreeAmbs arg0, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_TreeAmbs arg1);
#ifdef FAST_API
#define ASF_sliceTreeAmbs(arg, start, end) ((ASF_TreeAmbs) ATgetSlice((ATermList) (arg), (start * 4), (end * 4)))
#else
ASF_TreeAmbs _ASF_sliceTreeAmbs(ASF_TreeAmbs arg, int start, int end);
#define ASF_sliceTreeAmbs(arg, start, end) (_ASF_sliceTreeAmbs(arg, start, end))
#endif
#ifdef FAST_API
#define ASF_getTreeAmbsTreeAt(arg, index) ((ASF_Tree) (ATelementAt((ATermList) arg,index * 4)))
#else
ASF_Tree _ASF_getTreeAmbsTreeAt(ASF_TreeAmbs arg, int index);
#define ASF_getTreeAmbsTreeAt(arg, index) (_ASF_getTreeAmbsTreeAt(arg, index))
#endif
#ifdef FAST_API
#define ASF_replaceTreeAmbsTreeAt(arg, elem, index) ((ASF_TreeAmbs) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 4)))
#else
ASF_TreeAmbs _ASF_replaceTreeAmbsTreeAt(ASF_TreeAmbs arg, ASF_Tree elem, int index);
#define ASF_replaceTreeAmbsTreeAt(arg, elem, index) (_ASF_replaceTreeAmbsTreeAt(arg, elem, index))
#endif
ASF_TreeAmbs ASF_makeTreeAmbs2(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_Tree elem1, ASF_Tree elem2);
ASF_TreeAmbs ASF_makeTreeAmbs3(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_Tree elem1, ASF_Tree elem2, ASF_Tree elem3);
ASF_TreeAmbs ASF_makeTreeAmbs4(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_Tree elem1, ASF_Tree elem2, ASF_Tree elem3, ASF_Tree elem4);
ASF_TreeAmbs ASF_makeTreeAmbs5(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_Tree elem1, ASF_Tree elem2, ASF_Tree elem3, ASF_Tree elem4, ASF_Tree elem5);
ASF_TreeAmbs ASF_makeTreeAmbs6(ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_Tree elem1, ASF_Tree elem2, ASF_Tree elem3, ASF_Tree elem4, ASF_Tree elem5, ASF_Tree elem6);
#ifdef FAST_API
#define ASF_getCHARListLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 2) + 1))
#else
int _ASF_getCHARListLength(ASF_CHARList arg);
#define ASF_getCHARListLength(arg) (_ASF_getCHARListLength(arg))
#endif
ASF_CHARList ASF_reverseCHARList(ASF_CHARList arg);
ASF_CHARList ASF_appendCHARList(ASF_CHARList arg0, ASF_OptLayout wsAfterHead, ASF_CHAR arg1);
ASF_CHARList ASF_concatCHARList(ASF_CHARList arg0, ASF_OptLayout wsAfterHead, ASF_CHARList arg1);
#ifdef FAST_API
#define ASF_sliceCHARList(arg, start, end) ((ASF_CHARList) ATgetSlice((ATermList) (arg), (start * 2), (end * 2)))
#else
ASF_CHARList _ASF_sliceCHARList(ASF_CHARList arg, int start, int end);
#define ASF_sliceCHARList(arg, start, end) (_ASF_sliceCHARList(arg, start, end))
#endif
#ifdef FAST_API
#define ASF_getCHARListCHARAt(arg, index) ((ASF_CHAR) (ATelementAt((ATermList) arg,index * 2)))
#else
ASF_CHAR _ASF_getCHARListCHARAt(ASF_CHARList arg, int index);
#define ASF_getCHARListCHARAt(arg, index) (_ASF_getCHARListCHARAt(arg, index))
#endif
#ifdef FAST_API
#define ASF_replaceCHARListCHARAt(arg, elem, index) ((ASF_CHARList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 2)))
#else
ASF_CHARList _ASF_replaceCHARListCHARAt(ASF_CHARList arg, ASF_CHAR elem, int index);
#define ASF_replaceCHARListCHARAt(arg, elem, index) (_ASF_replaceCHARListCHARAt(arg, elem, index))
#endif
ASF_CHARList ASF_makeCHARList2(ASF_OptLayout wsAfterHead, ASF_CHAR elem1, ASF_CHAR elem2);
ASF_CHARList ASF_makeCHARList3(ASF_OptLayout wsAfterHead, ASF_CHAR elem1, ASF_CHAR elem2, ASF_CHAR elem3);
ASF_CHARList ASF_makeCHARList4(ASF_OptLayout wsAfterHead, ASF_CHAR elem1, ASF_CHAR elem2, ASF_CHAR elem3, ASF_CHAR elem4);
ASF_CHARList ASF_makeCHARList5(ASF_OptLayout wsAfterHead, ASF_CHAR elem1, ASF_CHAR elem2, ASF_CHAR elem3, ASF_CHAR elem4, ASF_CHAR elem5);
ASF_CHARList ASF_makeCHARList6(ASF_OptLayout wsAfterHead, ASF_CHAR elem1, ASF_CHAR elem2, ASF_CHAR elem3, ASF_CHAR elem4, ASF_CHAR elem5, ASF_CHAR elem6);
#ifdef FAST_API
#define ASF_getASFSectionListLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 2) + 1))
#else
int _ASF_getASFSectionListLength(ASF_ASFSectionList arg);
#define ASF_getASFSectionListLength(arg) (_ASF_getASFSectionListLength(arg))
#endif
ASF_ASFSectionList ASF_reverseASFSectionList(ASF_ASFSectionList arg);
ASF_ASFSectionList ASF_appendASFSectionList(ASF_ASFSectionList arg0, ASF_OptLayout wsAfterHead, ASF_ASFSection arg1);
ASF_ASFSectionList ASF_concatASFSectionList(ASF_ASFSectionList arg0, ASF_OptLayout wsAfterHead, ASF_ASFSectionList arg1);
#ifdef FAST_API
#define ASF_sliceASFSectionList(arg, start, end) ((ASF_ASFSectionList) ATgetSlice((ATermList) (arg), (start * 2), (end * 2)))
#else
ASF_ASFSectionList _ASF_sliceASFSectionList(ASF_ASFSectionList arg, int start, int end);
#define ASF_sliceASFSectionList(arg, start, end) (_ASF_sliceASFSectionList(arg, start, end))
#endif
#ifdef FAST_API
#define ASF_getASFSectionListASFSectionAt(arg, index) ((ASF_ASFSection) (ATelementAt((ATermList) arg,index * 2)))
#else
ASF_ASFSection _ASF_getASFSectionListASFSectionAt(ASF_ASFSectionList arg, int index);
#define ASF_getASFSectionListASFSectionAt(arg, index) (_ASF_getASFSectionListASFSectionAt(arg, index))
#endif
#ifdef FAST_API
#define ASF_replaceASFSectionListASFSectionAt(arg, elem, index) ((ASF_ASFSectionList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 2)))
#else
ASF_ASFSectionList _ASF_replaceASFSectionListASFSectionAt(ASF_ASFSectionList arg, ASF_ASFSection elem, int index);
#define ASF_replaceASFSectionListASFSectionAt(arg, elem, index) (_ASF_replaceASFSectionListASFSectionAt(arg, elem, index))
#endif
ASF_ASFSectionList ASF_makeASFSectionList2(ASF_OptLayout wsAfterHead, ASF_ASFSection elem1, ASF_ASFSection elem2);
ASF_ASFSectionList ASF_makeASFSectionList3(ASF_OptLayout wsAfterHead, ASF_ASFSection elem1, ASF_ASFSection elem2, ASF_ASFSection elem3);
ASF_ASFSectionList ASF_makeASFSectionList4(ASF_OptLayout wsAfterHead, ASF_ASFSection elem1, ASF_ASFSection elem2, ASF_ASFSection elem3, ASF_ASFSection elem4);
ASF_ASFSectionList ASF_makeASFSectionList5(ASF_OptLayout wsAfterHead, ASF_ASFSection elem1, ASF_ASFSection elem2, ASF_ASFSection elem3, ASF_ASFSection elem4, ASF_ASFSection elem5);
ASF_ASFSectionList ASF_makeASFSectionList6(ASF_OptLayout wsAfterHead, ASF_ASFSection elem1, ASF_ASFSection elem2, ASF_ASFSection elem3, ASF_ASFSection elem4, ASF_ASFSection elem5, ASF_ASFSection elem6);
#ifdef FAST_API
#define ASF_getASFConditionalEquationListLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 2) + 1))
#else
int _ASF_getASFConditionalEquationListLength(ASF_ASFConditionalEquationList arg);
#define ASF_getASFConditionalEquationListLength(arg) (_ASF_getASFConditionalEquationListLength(arg))
#endif
ASF_ASFConditionalEquationList ASF_reverseASFConditionalEquationList(ASF_ASFConditionalEquationList arg);
ASF_ASFConditionalEquationList ASF_appendASFConditionalEquationList(ASF_ASFConditionalEquationList arg0, ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation arg1);
ASF_ASFConditionalEquationList ASF_concatASFConditionalEquationList(ASF_ASFConditionalEquationList arg0, ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquationList arg1);
#ifdef FAST_API
#define ASF_sliceASFConditionalEquationList(arg, start, end) ((ASF_ASFConditionalEquationList) ATgetSlice((ATermList) (arg), (start * 2), (end * 2)))
#else
ASF_ASFConditionalEquationList _ASF_sliceASFConditionalEquationList(ASF_ASFConditionalEquationList arg, int start, int end);
#define ASF_sliceASFConditionalEquationList(arg, start, end) (_ASF_sliceASFConditionalEquationList(arg, start, end))
#endif
#ifdef FAST_API
#define ASF_getASFConditionalEquationListASFConditionalEquationAt(arg, index) ((ASF_ASFConditionalEquation) (ATelementAt((ATermList) arg,index * 2)))
#else
ASF_ASFConditionalEquation _ASF_getASFConditionalEquationListASFConditionalEquationAt(ASF_ASFConditionalEquationList arg, int index);
#define ASF_getASFConditionalEquationListASFConditionalEquationAt(arg, index) (_ASF_getASFConditionalEquationListASFConditionalEquationAt(arg, index))
#endif
#ifdef FAST_API
#define ASF_replaceASFConditionalEquationListASFConditionalEquationAt(arg, elem, index) ((ASF_ASFConditionalEquationList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 2)))
#else
ASF_ASFConditionalEquationList _ASF_replaceASFConditionalEquationListASFConditionalEquationAt(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation elem, int index);
#define ASF_replaceASFConditionalEquationListASFConditionalEquationAt(arg, elem, index) (_ASF_replaceASFConditionalEquationListASFConditionalEquationAt(arg, elem, index))
#endif
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList2(ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation elem1, ASF_ASFConditionalEquation elem2);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList3(ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation elem1, ASF_ASFConditionalEquation elem2, ASF_ASFConditionalEquation elem3);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList4(ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation elem1, ASF_ASFConditionalEquation elem2, ASF_ASFConditionalEquation elem3, ASF_ASFConditionalEquation elem4);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList5(ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation elem1, ASF_ASFConditionalEquation elem2, ASF_ASFConditionalEquation elem3, ASF_ASFConditionalEquation elem4, ASF_ASFConditionalEquation elem5);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList6(ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquation elem1, ASF_ASFConditionalEquation elem2, ASF_ASFConditionalEquation elem3, ASF_ASFConditionalEquation elem4, ASF_ASFConditionalEquation elem5, ASF_ASFConditionalEquation elem6);
#ifdef FAST_API
#define ASF_getASFTestEquationTestListLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 2) + 1))
#else
int _ASF_getASFTestEquationTestListLength(ASF_ASFTestEquationTestList arg);
#define ASF_getASFTestEquationTestListLength(arg) (_ASF_getASFTestEquationTestListLength(arg))
#endif
ASF_ASFTestEquationTestList ASF_reverseASFTestEquationTestList(ASF_ASFTestEquationTestList arg);
ASF_ASFTestEquationTestList ASF_appendASFTestEquationTestList(ASF_ASFTestEquationTestList arg0, ASF_OptLayout wsAfterHead, ASF_ASFTestEquation arg1);
ASF_ASFTestEquationTestList ASF_concatASFTestEquationTestList(ASF_ASFTestEquationTestList arg0, ASF_OptLayout wsAfterHead, ASF_ASFTestEquationTestList arg1);
#ifdef FAST_API
#define ASF_sliceASFTestEquationTestList(arg, start, end) ((ASF_ASFTestEquationTestList) ATgetSlice((ATermList) (arg), (start * 2), (end * 2)))
#else
ASF_ASFTestEquationTestList _ASF_sliceASFTestEquationTestList(ASF_ASFTestEquationTestList arg, int start, int end);
#define ASF_sliceASFTestEquationTestList(arg, start, end) (_ASF_sliceASFTestEquationTestList(arg, start, end))
#endif
#ifdef FAST_API
#define ASF_getASFTestEquationTestListASFTestEquationAt(arg, index) ((ASF_ASFTestEquation) (ATelementAt((ATermList) arg,index * 2)))
#else
ASF_ASFTestEquation _ASF_getASFTestEquationTestListASFTestEquationAt(ASF_ASFTestEquationTestList arg, int index);
#define ASF_getASFTestEquationTestListASFTestEquationAt(arg, index) (_ASF_getASFTestEquationTestListASFTestEquationAt(arg, index))
#endif
#ifdef FAST_API
#define ASF_replaceASFTestEquationTestListASFTestEquationAt(arg, elem, index) ((ASF_ASFTestEquationTestList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 2)))
#else
ASF_ASFTestEquationTestList _ASF_replaceASFTestEquationTestListASFTestEquationAt(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquation elem, int index);
#define ASF_replaceASFTestEquationTestListASFTestEquationAt(arg, elem, index) (_ASF_replaceASFTestEquationTestListASFTestEquationAt(arg, elem, index))
#endif
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestList2(ASF_OptLayout wsAfterHead, ASF_ASFTestEquation elem1, ASF_ASFTestEquation elem2);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestList3(ASF_OptLayout wsAfterHead, ASF_ASFTestEquation elem1, ASF_ASFTestEquation elem2, ASF_ASFTestEquation elem3);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestList4(ASF_OptLayout wsAfterHead, ASF_ASFTestEquation elem1, ASF_ASFTestEquation elem2, ASF_ASFTestEquation elem3, ASF_ASFTestEquation elem4);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestList5(ASF_OptLayout wsAfterHead, ASF_ASFTestEquation elem1, ASF_ASFTestEquation elem2, ASF_ASFTestEquation elem3, ASF_ASFTestEquation elem4, ASF_ASFTestEquation elem5);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestList6(ASF_OptLayout wsAfterHead, ASF_ASFTestEquation elem1, ASF_ASFTestEquation elem2, ASF_ASFTestEquation elem3, ASF_ASFTestEquation elem4, ASF_ASFTestEquation elem5, ASF_ASFTestEquation elem6);
ASF_OptLayout ASF_makeOptLayoutAbsent(void);
ASF_OptLayout ASF_makeOptLayoutPresent(ASF_Layout layout);
ASF_Layout ASF_makeLayoutLexToCf(ASF_LexLayoutList list);
ASF_LexLayoutList ASF_makeLexLayoutListEmpty(void);
ASF_LexLayoutList ASF_makeLexLayoutListSingle(ASF_LexLayout head);
ASF_LexLayoutList ASF_makeLexLayoutListMany(ASF_LexLayout head, ASF_LexLayoutList tail);
ASF_Tree ASF_makeTreeCast(ATerm Tree);
ASF_Tree ASF_makeTreeAmbiguityConstructor(ASF_OptLayout wsAfterAmb, ASF_OptLayout wsAfterParenOpen, ASF_TreeAmbs ambs, ASF_OptLayout wsAfterAmbs);
ASF_Tree ASF_makeTreeLexicalConstructor(ASF_Tree name, ASF_OptLayout wsAfterName, ASF_OptLayout wsAfterParenOpen, ASF_CHARList list, ASF_OptLayout wsAfterList);
ASF_LexCHAR ASF_makeLexCHARDefault(char value);
ASF_CHAR ASF_makeCHARLexToCf(ASF_LexCHAR CHAR);
ASF_ASFCondition ASF_makeASFConditionNegative(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterUnequal, ASF_Tree rhs);
ASF_ASFCondition ASF_makeASFConditionEquality(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquality, ASF_Tree rhs);
ASF_ASFCondition ASF_makeASFConditionMatch(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterMatch, ASF_Tree rhs);
ASF_ASFCondition ASF_makeASFConditionNoMatch(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterMatch, ASF_Tree rhs);
ASF_ASFConditions ASF_makeASFConditionsDefault(ASF_ASFConditionList list);
ASF_ASFConditionList ASF_makeASFConditionListEmpty(void);
ASF_ASFConditionList ASF_makeASFConditionListSingle(ASF_ASFCondition head);
ASF_ASFConditionList ASF_makeASFConditionListMany(ASF_ASFCondition head, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_ASFConditionList tail);
ASF_TreeAmbs ASF_makeTreeAmbsEmpty(void);
ASF_TreeAmbs ASF_makeTreeAmbsSingle(ASF_Tree head);
ASF_TreeAmbs ASF_makeTreeAmbsMany(ASF_Tree head, ASF_OptLayout wsAfterHead, ASF_OptLayout wsAfterSep, ASF_TreeAmbs tail);
ASF_CHARList ASF_makeCHARListEmpty(void);
ASF_CHARList ASF_makeCHARListSingle(ASF_CHAR head);
ASF_CHARList ASF_makeCHARListMany(ASF_CHAR head, ASF_OptLayout wsAfterHead, ASF_CHARList tail);
ASF_LexASFBarEnd ASF_makeLexASFBarEndAbsent(void);
ASF_LexASFBarEnd ASF_makeLexASFBarEndPresent(void);
ASF_ASFBarEnd ASF_makeASFBarEndLexToCf(ASF_LexASFBarEnd ASFBarEnd);
ASF_LexASFImplies ASF_makeLexASFImpliesDefault(const char* bar, ASF_LexASFBarEnd end);
ASF_ASFImplies ASF_makeASFImpliesLexToCf(ASF_LexASFImplies ASFImplies);
ASF_ASFConditionalEquation ASF_makeASFConditionalEquationSimple(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation);
ASF_ASFConditionalEquation ASF_makeASFConditionalEquationImplies(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFConditions ASFConditions, ASF_OptLayout wsAfterASFConditions, ASF_ASFImplies ASFImplies, ASF_OptLayout wsAfterASFImplies, ASF_ASFEquation ASFEquation);
ASF_ASFConditionalEquation ASF_makeASFConditionalEquationWhen(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation, ASF_OptLayout wsAfterASFEquation, ASF_OptLayout wsAfterWhen, ASF_ASFConditions ASFConditions);
ASF_ASFEquation ASF_makeASFEquationDefault(ATerm typeOfLhs, ATerm typeOfRhs, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquality, ASF_Tree rhs);
ASF_Start ASF_makeStartASFModule(ASF_OptLayout wsBefore, ASF_ASFModule topASFModule, ASF_OptLayout wsAfter, int ambCnt);
ASF_Start ASF_makeStartASFSection(ASF_OptLayout wsBefore, ASF_ASFSection topASFSection, ASF_OptLayout wsAfter, int ambCnt);
ASF_ASFModule ASF_makeASFModuleDefault(ASF_ASFSectionList list);
ASF_ASFSection ASF_makeASFSectionEquations(ASF_OptLayout wsAfterEquations, ASF_ASFConditionalEquationList list);
ASF_ASFSection ASF_makeASFSectionTests(ASF_OptLayout wsAfterTests, ASF_ASFTestEquationTestList testList);
ASF_ASFSectionList ASF_makeASFSectionListEmpty(void);
ASF_ASFSectionList ASF_makeASFSectionListSingle(ASF_ASFSection head);
ASF_ASFSectionList ASF_makeASFSectionListMany(ASF_ASFSection head, ASF_OptLayout wsAfterHead, ASF_ASFSectionList tail);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListEmpty(void);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListSingle(ASF_ASFConditionalEquation head);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListMany(ASF_ASFConditionalEquation head, ASF_OptLayout wsAfterHead, ASF_ASFConditionalEquationList tail);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestListEmpty(void);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestListSingle(ASF_ASFTestEquation head);
ASF_ASFTestEquationTestList ASF_makeASFTestEquationTestListMany(ASF_ASFTestEquation head, ASF_OptLayout wsAfterHead, ASF_ASFTestEquationTestList tail);
ASF_LexASFTagId ASF_makeLexASFTagIdOneChar(char head);
ASF_LexASFTagId ASF_makeLexASFTagIdManyChars(char head, const char* middle, char last);
ASF_ASFTagId ASF_makeASFTagIdLexToCf(ASF_LexASFTagId ASFTagId);
ASF_ASFTag ASF_makeASFTagEmpty(ASF_OptLayout wsAfterBracketOpen);
ASF_ASFTag ASF_makeASFTagNotEmpty(ASF_OptLayout wsAfterBracketOpen, ASF_ASFTagId ASFTagId, ASF_OptLayout wsAfterASFTagId);
ASF_ASFTestEquation ASF_makeASFTestEquationSimple(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFCondition ASFCondition);
ASF_ASFTestEquation ASF_makeASFTestEquationImplies(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFConditions ASFConditions, ASF_OptLayout wsAfterASFConditions, ASF_ASFImplies ASFImplies, ASF_OptLayout wsAfterASFImplies, ASF_ASFCondition ASFCondition);
ASF_ASFTestEquation ASF_makeASFTestEquationWhen(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFCondition ASFCondition, ASF_OptLayout wsAfterASFCondition, ASF_OptLayout wsAfterWhen, ASF_ASFConditions ASFConditions);
ASF_LexLayout ASF_makeLexLayoutWhitespace(char ch);
ASF_LexNumChar ASF_makeLexNumCharDigits(const char* number);
ASF_NumChar ASF_makeNumCharLexToCf(ASF_LexNumChar NumChar);
ASF_LexShortChar ASF_makeLexShortCharRegular(char character);
ASF_LexShortChar ASF_makeLexShortCharEscaped(char escape);
ASF_ShortChar ASF_makeShortCharLexToCf(ASF_LexShortChar ShortChar);
ASF_Character ASF_makeCharacterNumeric(ASF_NumChar NumChar);
ASF_Character ASF_makeCharacterShort(ASF_ShortChar ShortChar);
ASF_Character ASF_makeCharacterTop(void);
ASF_Character ASF_makeCharacterEof(void);
ASF_Character ASF_makeCharacterBot(void);
ASF_Character ASF_makeCharacterLabelUnderscoreStart(void);
#ifdef FAST_API
#define ASF_isEqualOptLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualOptLayout(ASF_OptLayout arg0, ASF_OptLayout arg1);
#define ASF_isEqualOptLayout(arg0, arg1) (_ASF_isEqualOptLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualLayout(ASF_Layout arg0, ASF_Layout arg1);
#define ASF_isEqualLayout(arg0, arg1) (_ASF_isEqualLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualLexLayoutList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualLexLayoutList(ASF_LexLayoutList arg0, ASF_LexLayoutList arg1);
#define ASF_isEqualLexLayoutList(arg0, arg1) (_ASF_isEqualLexLayoutList(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualTree(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualTree(ASF_Tree arg0, ASF_Tree arg1);
#define ASF_isEqualTree(arg0, arg1) (_ASF_isEqualTree(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualLexCHAR(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualLexCHAR(ASF_LexCHAR arg0, ASF_LexCHAR arg1);
#define ASF_isEqualLexCHAR(arg0, arg1) (_ASF_isEqualLexCHAR(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualCHAR(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualCHAR(ASF_CHAR arg0, ASF_CHAR arg1);
#define ASF_isEqualCHAR(arg0, arg1) (_ASF_isEqualCHAR(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualASFCondition(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualASFCondition(ASF_ASFCondition arg0, ASF_ASFCondition arg1);
#define ASF_isEqualASFCondition(arg0, arg1) (_ASF_isEqualASFCondition(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualASFConditions(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualASFConditions(ASF_ASFConditions arg0, ASF_ASFConditions arg1);
#define ASF_isEqualASFConditions(arg0, arg1) (_ASF_isEqualASFConditions(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualASFConditionList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualASFConditionList(ASF_ASFConditionList arg0, ASF_ASFConditionList arg1);
#define ASF_isEqualASFConditionList(arg0, arg1) (_ASF_isEqualASFConditionList(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualTreeAmbs(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualTreeAmbs(ASF_TreeAmbs arg0, ASF_TreeAmbs arg1);
#define ASF_isEqualTreeAmbs(arg0, arg1) (_ASF_isEqualTreeAmbs(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualCHARList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualCHARList(ASF_CHARList arg0, ASF_CHARList arg1);
#define ASF_isEqualCHARList(arg0, arg1) (_ASF_isEqualCHARList(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualLexASFBarEnd(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualLexASFBarEnd(ASF_LexASFBarEnd arg0, ASF_LexASFBarEnd arg1);
#define ASF_isEqualLexASFBarEnd(arg0, arg1) (_ASF_isEqualLexASFBarEnd(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualASFBarEnd(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualASFBarEnd(ASF_ASFBarEnd arg0, ASF_ASFBarEnd arg1);
#define ASF_isEqualASFBarEnd(arg0, arg1) (_ASF_isEqualASFBarEnd(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualLexASFImplies(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualLexASFImplies(ASF_LexASFImplies arg0, ASF_LexASFImplies arg1);
#define ASF_isEqualLexASFImplies(arg0, arg1) (_ASF_isEqualLexASFImplies(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualASFImplies(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualASFImplies(ASF_ASFImplies arg0, ASF_ASFImplies arg1);
#define ASF_isEqualASFImplies(arg0, arg1) (_ASF_isEqualASFImplies(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualASFConditionalEquation(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualASFConditionalEquation(ASF_ASFConditionalEquation arg0, ASF_ASFConditionalEquation arg1);
#define ASF_isEqualASFConditionalEquation(arg0, arg1) (_ASF_isEqualASFConditionalEquation(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualASFEquation(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualASFEquation(ASF_ASFEquation arg0, ASF_ASFEquation arg1);
#define ASF_isEqualASFEquation(arg0, arg1) (_ASF_isEqualASFEquation(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualStart(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualStart(ASF_Start arg0, ASF_Start arg1);
#define ASF_isEqualStart(arg0, arg1) (_ASF_isEqualStart(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualASFModule(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualASFModule(ASF_ASFModule arg0, ASF_ASFModule arg1);
#define ASF_isEqualASFModule(arg0, arg1) (_ASF_isEqualASFModule(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualASFSection(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualASFSection(ASF_ASFSection arg0, ASF_ASFSection arg1);
#define ASF_isEqualASFSection(arg0, arg1) (_ASF_isEqualASFSection(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualASFSectionList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualASFSectionList(ASF_ASFSectionList arg0, ASF_ASFSectionList arg1);
#define ASF_isEqualASFSectionList(arg0, arg1) (_ASF_isEqualASFSectionList(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualASFConditionalEquationList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualASFConditionalEquationList(ASF_ASFConditionalEquationList arg0, ASF_ASFConditionalEquationList arg1);
#define ASF_isEqualASFConditionalEquationList(arg0, arg1) (_ASF_isEqualASFConditionalEquationList(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualASFTestEquationTestList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualASFTestEquationTestList(ASF_ASFTestEquationTestList arg0, ASF_ASFTestEquationTestList arg1);
#define ASF_isEqualASFTestEquationTestList(arg0, arg1) (_ASF_isEqualASFTestEquationTestList(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualLexASFTagId(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualLexASFTagId(ASF_LexASFTagId arg0, ASF_LexASFTagId arg1);
#define ASF_isEqualLexASFTagId(arg0, arg1) (_ASF_isEqualLexASFTagId(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualASFTagId(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualASFTagId(ASF_ASFTagId arg0, ASF_ASFTagId arg1);
#define ASF_isEqualASFTagId(arg0, arg1) (_ASF_isEqualASFTagId(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualASFTag(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualASFTag(ASF_ASFTag arg0, ASF_ASFTag arg1);
#define ASF_isEqualASFTag(arg0, arg1) (_ASF_isEqualASFTag(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualASFTestEquation(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualASFTestEquation(ASF_ASFTestEquation arg0, ASF_ASFTestEquation arg1);
#define ASF_isEqualASFTestEquation(arg0, arg1) (_ASF_isEqualASFTestEquation(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualLexLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualLexLayout(ASF_LexLayout arg0, ASF_LexLayout arg1);
#define ASF_isEqualLexLayout(arg0, arg1) (_ASF_isEqualLexLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualLexNumChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualLexNumChar(ASF_LexNumChar arg0, ASF_LexNumChar arg1);
#define ASF_isEqualLexNumChar(arg0, arg1) (_ASF_isEqualLexNumChar(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualNumChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualNumChar(ASF_NumChar arg0, ASF_NumChar arg1);
#define ASF_isEqualNumChar(arg0, arg1) (_ASF_isEqualNumChar(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualLexShortChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualLexShortChar(ASF_LexShortChar arg0, ASF_LexShortChar arg1);
#define ASF_isEqualLexShortChar(arg0, arg1) (_ASF_isEqualLexShortChar(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualShortChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualShortChar(ASF_ShortChar arg0, ASF_ShortChar arg1);
#define ASF_isEqualShortChar(arg0, arg1) (_ASF_isEqualShortChar(arg0, arg1))
#endif
#ifdef FAST_API
#define ASF_isEqualCharacter(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _ASF_isEqualCharacter(ASF_Character arg0, ASF_Character arg1);
#define ASF_isEqualCharacter(arg0, arg1) (_ASF_isEqualCharacter(arg0, arg1))
#endif
ATbool ASF_isValidOptLayout(ASF_OptLayout arg);
inline ATbool ASF_isOptLayoutAbsent(ASF_OptLayout arg);
inline ATbool ASF_isOptLayoutPresent(ASF_OptLayout arg);
ATbool ASF_hasOptLayoutLayout(ASF_OptLayout arg);
ASF_Layout ASF_getOptLayoutLayout(ASF_OptLayout arg);
ASF_OptLayout ASF_setOptLayoutLayout(ASF_OptLayout arg, ASF_Layout layout);
ATbool ASF_isValidLayout(ASF_Layout arg);
inline ATbool ASF_isLayoutLexToCf(ASF_Layout arg);
ATbool ASF_hasLayoutList(ASF_Layout arg);
ASF_LexLayoutList ASF_getLayoutList(ASF_Layout arg);
ASF_Layout ASF_setLayoutList(ASF_Layout arg, ASF_LexLayoutList list);
ATbool ASF_isValidLexLayoutList(ASF_LexLayoutList arg);
inline ATbool ASF_isLexLayoutListEmpty(ASF_LexLayoutList arg);
inline ATbool ASF_isLexLayoutListSingle(ASF_LexLayoutList arg);
inline ATbool ASF_isLexLayoutListMany(ASF_LexLayoutList arg);
ATbool ASF_hasLexLayoutListHead(ASF_LexLayoutList arg);
ATbool ASF_hasLexLayoutListTail(ASF_LexLayoutList arg);
ASF_LexLayout ASF_getLexLayoutListHead(ASF_LexLayoutList arg);
ASF_LexLayoutList ASF_getLexLayoutListTail(ASF_LexLayoutList arg);
ASF_LexLayoutList ASF_setLexLayoutListHead(ASF_LexLayoutList arg, ASF_LexLayout head);
ASF_LexLayoutList ASF_setLexLayoutListTail(ASF_LexLayoutList arg, ASF_LexLayoutList tail);
ATbool ASF_isValidTree(ASF_Tree arg);
inline ATbool ASF_isTreeCast(ASF_Tree arg);
inline ATbool ASF_isTreeAmbiguityConstructor(ASF_Tree arg);
inline ATbool ASF_isTreeLexicalConstructor(ASF_Tree arg);
ATbool ASF_hasTreeTree(ASF_Tree arg);
ATbool ASF_hasTreeWsAfterAmb(ASF_Tree arg);
ATbool ASF_hasTreeWsAfterParenOpen(ASF_Tree arg);
ATbool ASF_hasTreeAmbs(ASF_Tree arg);
ATbool ASF_hasTreeWsAfterAmbs(ASF_Tree arg);
ATbool ASF_hasTreeName(ASF_Tree arg);
ATbool ASF_hasTreeWsAfterName(ASF_Tree arg);
ATbool ASF_hasTreeList(ASF_Tree arg);
ATbool ASF_hasTreeWsAfterList(ASF_Tree arg);
ATerm ASF_getTreeTree(ASF_Tree arg);
ASF_OptLayout ASF_getTreeWsAfterAmb(ASF_Tree arg);
ASF_OptLayout ASF_getTreeWsAfterParenOpen(ASF_Tree arg);
ASF_TreeAmbs ASF_getTreeAmbs(ASF_Tree arg);
ASF_OptLayout ASF_getTreeWsAfterAmbs(ASF_Tree arg);
ASF_Tree ASF_getTreeName(ASF_Tree arg);
ASF_OptLayout ASF_getTreeWsAfterName(ASF_Tree arg);
ASF_CHARList ASF_getTreeList(ASF_Tree arg);
ASF_OptLayout ASF_getTreeWsAfterList(ASF_Tree arg);
ASF_Tree ASF_setTreeTree(ASF_Tree arg, ATerm Tree);
ASF_Tree ASF_setTreeWsAfterAmb(ASF_Tree arg, ASF_OptLayout wsAfterAmb);
ASF_Tree ASF_setTreeWsAfterParenOpen(ASF_Tree arg, ASF_OptLayout wsAfterParenOpen);
ASF_Tree ASF_setTreeAmbs(ASF_Tree arg, ASF_TreeAmbs ambs);
ASF_Tree ASF_setTreeWsAfterAmbs(ASF_Tree arg, ASF_OptLayout wsAfterAmbs);
ASF_Tree ASF_setTreeName(ASF_Tree arg, ASF_Tree name);
ASF_Tree ASF_setTreeWsAfterName(ASF_Tree arg, ASF_OptLayout wsAfterName);
ASF_Tree ASF_setTreeList(ASF_Tree arg, ASF_CHARList list);
ASF_Tree ASF_setTreeWsAfterList(ASF_Tree arg, ASF_OptLayout wsAfterList);
ATbool ASF_isValidLexCHAR(ASF_LexCHAR arg);
inline ATbool ASF_isLexCHARDefault(ASF_LexCHAR arg);
ATbool ASF_hasLexCHARValue(ASF_LexCHAR arg);
char ASF_getLexCHARValue(ASF_LexCHAR arg);
ASF_LexCHAR ASF_setLexCHARValue(ASF_LexCHAR arg, char value);
ATbool ASF_isValidCHAR(ASF_CHAR arg);
inline ATbool ASF_isCHARLexToCf(ASF_CHAR arg);
ATbool ASF_hasCHARCHAR(ASF_CHAR arg);
ASF_LexCHAR ASF_getCHARCHAR(ASF_CHAR arg);
ASF_CHAR ASF_setCHARCHAR(ASF_CHAR arg, ASF_LexCHAR CHAR);
ATbool ASF_isValidASFCondition(ASF_ASFCondition arg);
inline ATbool ASF_isASFConditionNegative(ASF_ASFCondition arg);
inline ATbool ASF_isASFConditionEquality(ASF_ASFCondition arg);
inline ATbool ASF_isASFConditionMatch(ASF_ASFCondition arg);
inline ATbool ASF_isASFConditionNoMatch(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionTypeOfLhs(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionTypeOfRhs(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionLhs(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionWsAfterLhs(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionWsAfterUnequal(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionRhs(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionWsAfterEquality(ASF_ASFCondition arg);
ATbool ASF_hasASFConditionWsAfterMatch(ASF_ASFCondition arg);
ATerm ASF_getASFConditionTypeOfLhs(ASF_ASFCondition arg);
ATerm ASF_getASFConditionTypeOfRhs(ASF_ASFCondition arg);
ASF_Tree ASF_getASFConditionLhs(ASF_ASFCondition arg);
ASF_OptLayout ASF_getASFConditionWsAfterLhs(ASF_ASFCondition arg);
ASF_OptLayout ASF_getASFConditionWsAfterUnequal(ASF_ASFCondition arg);
ASF_Tree ASF_getASFConditionRhs(ASF_ASFCondition arg);
ASF_OptLayout ASF_getASFConditionWsAfterEquality(ASF_ASFCondition arg);
ASF_OptLayout ASF_getASFConditionWsAfterMatch(ASF_ASFCondition arg);
ASF_ASFCondition ASF_setASFConditionTypeOfLhs(ASF_ASFCondition arg, ATerm typeOfLhs);
ASF_ASFCondition ASF_setASFConditionTypeOfRhs(ASF_ASFCondition arg, ATerm typeOfRhs);
ASF_ASFCondition ASF_setASFConditionLhs(ASF_ASFCondition arg, ASF_Tree lhs);
ASF_ASFCondition ASF_setASFConditionWsAfterLhs(ASF_ASFCondition arg, ASF_OptLayout wsAfterLhs);
ASF_ASFCondition ASF_setASFConditionWsAfterUnequal(ASF_ASFCondition arg, ASF_OptLayout wsAfterUnequal);
ASF_ASFCondition ASF_setASFConditionRhs(ASF_ASFCondition arg, ASF_Tree rhs);
ASF_ASFCondition ASF_setASFConditionWsAfterEquality(ASF_ASFCondition arg, ASF_OptLayout wsAfterEquality);
ASF_ASFCondition ASF_setASFConditionWsAfterMatch(ASF_ASFCondition arg, ASF_OptLayout wsAfterMatch);
ATbool ASF_isValidASFConditions(ASF_ASFConditions arg);
inline ATbool ASF_isASFConditionsDefault(ASF_ASFConditions arg);
ATbool ASF_hasASFConditionsList(ASF_ASFConditions arg);
ASF_ASFConditionList ASF_getASFConditionsList(ASF_ASFConditions arg);
ASF_ASFConditions ASF_setASFConditionsList(ASF_ASFConditions arg, ASF_ASFConditionList list);
ATbool ASF_isValidASFConditionList(ASF_ASFConditionList arg);
inline ATbool ASF_isASFConditionListEmpty(ASF_ASFConditionList arg);
inline ATbool ASF_isASFConditionListSingle(ASF_ASFConditionList arg);
inline ATbool ASF_isASFConditionListMany(ASF_ASFConditionList arg);
ATbool ASF_hasASFConditionListHead(ASF_ASFConditionList arg);
ATbool ASF_hasASFConditionListWsAfterHead(ASF_ASFConditionList arg);
ATbool ASF_hasASFConditionListWsAfterSep(ASF_ASFConditionList arg);
ATbool ASF_hasASFConditionListTail(ASF_ASFConditionList arg);
ASF_ASFConditionList ASF_getASFConditionListTail(ASF_ASFConditionList arg);
ASF_ASFCondition ASF_getASFConditionListHead(ASF_ASFConditionList arg);
ASF_OptLayout ASF_getASFConditionListWsAfterHead(ASF_ASFConditionList arg);
ASF_OptLayout ASF_getASFConditionListWsAfterSep(ASF_ASFConditionList arg);
ASF_ASFConditionList ASF_setASFConditionListHead(ASF_ASFConditionList arg, ASF_ASFCondition head);
ASF_ASFConditionList ASF_setASFConditionListWsAfterHead(ASF_ASFConditionList arg, ASF_OptLayout wsAfterHead);
ASF_ASFConditionList ASF_setASFConditionListWsAfterSep(ASF_ASFConditionList arg, ASF_OptLayout wsAfterSep);
ASF_ASFConditionList ASF_setASFConditionListTail(ASF_ASFConditionList arg, ASF_ASFConditionList tail);
ATbool ASF_isValidTreeAmbs(ASF_TreeAmbs arg);
inline ATbool ASF_isTreeAmbsEmpty(ASF_TreeAmbs arg);
inline ATbool ASF_isTreeAmbsSingle(ASF_TreeAmbs arg);
inline ATbool ASF_isTreeAmbsMany(ASF_TreeAmbs arg);
ATbool ASF_hasTreeAmbsHead(ASF_TreeAmbs arg);
ATbool ASF_hasTreeAmbsWsAfterHead(ASF_TreeAmbs arg);
ATbool ASF_hasTreeAmbsWsAfterSep(ASF_TreeAmbs arg);
ATbool ASF_hasTreeAmbsTail(ASF_TreeAmbs arg);
ASF_TreeAmbs ASF_getTreeAmbsTail(ASF_TreeAmbs arg);
ASF_Tree ASF_getTreeAmbsHead(ASF_TreeAmbs arg);
ASF_OptLayout ASF_getTreeAmbsWsAfterHead(ASF_TreeAmbs arg);
ASF_OptLayout ASF_getTreeAmbsWsAfterSep(ASF_TreeAmbs arg);
ASF_TreeAmbs ASF_setTreeAmbsHead(ASF_TreeAmbs arg, ASF_Tree head);
ASF_TreeAmbs ASF_setTreeAmbsWsAfterHead(ASF_TreeAmbs arg, ASF_OptLayout wsAfterHead);
ASF_TreeAmbs ASF_setTreeAmbsWsAfterSep(ASF_TreeAmbs arg, ASF_OptLayout wsAfterSep);
ASF_TreeAmbs ASF_setTreeAmbsTail(ASF_TreeAmbs arg, ASF_TreeAmbs tail);
ATbool ASF_isValidCHARList(ASF_CHARList arg);
inline ATbool ASF_isCHARListEmpty(ASF_CHARList arg);
inline ATbool ASF_isCHARListSingle(ASF_CHARList arg);
inline ATbool ASF_isCHARListMany(ASF_CHARList arg);
ATbool ASF_hasCHARListHead(ASF_CHARList arg);
ATbool ASF_hasCHARListWsAfterHead(ASF_CHARList arg);
ATbool ASF_hasCHARListTail(ASF_CHARList arg);
ASF_CHARList ASF_getCHARListTail(ASF_CHARList arg);
ASF_CHAR ASF_getCHARListHead(ASF_CHARList arg);
ASF_OptLayout ASF_getCHARListWsAfterHead(ASF_CHARList arg);
ASF_CHARList ASF_setCHARListHead(ASF_CHARList arg, ASF_CHAR head);
ASF_CHARList ASF_setCHARListWsAfterHead(ASF_CHARList arg, ASF_OptLayout wsAfterHead);
ASF_CHARList ASF_setCHARListTail(ASF_CHARList arg, ASF_CHARList tail);
ATbool ASF_isValidLexASFBarEnd(ASF_LexASFBarEnd arg);
inline ATbool ASF_isLexASFBarEndAbsent(ASF_LexASFBarEnd arg);
inline ATbool ASF_isLexASFBarEndPresent(ASF_LexASFBarEnd arg);
ATbool ASF_isValidASFBarEnd(ASF_ASFBarEnd arg);
inline ATbool ASF_isASFBarEndLexToCf(ASF_ASFBarEnd arg);
ATbool ASF_hasASFBarEndASFBarEnd(ASF_ASFBarEnd arg);
ASF_LexASFBarEnd ASF_getASFBarEndASFBarEnd(ASF_ASFBarEnd arg);
ASF_ASFBarEnd ASF_setASFBarEndASFBarEnd(ASF_ASFBarEnd arg, ASF_LexASFBarEnd ASFBarEnd);
ATbool ASF_isValidLexASFImplies(ASF_LexASFImplies arg);
inline ATbool ASF_isLexASFImpliesDefault(ASF_LexASFImplies arg);
ATbool ASF_hasLexASFImpliesBar(ASF_LexASFImplies arg);
ATbool ASF_hasLexASFImpliesEnd(ASF_LexASFImplies arg);
char* ASF_getLexASFImpliesBar(ASF_LexASFImplies arg);
ASF_LexASFBarEnd ASF_getLexASFImpliesEnd(ASF_LexASFImplies arg);
ASF_LexASFImplies ASF_setLexASFImpliesBar(ASF_LexASFImplies arg, const char* bar);
ASF_LexASFImplies ASF_setLexASFImpliesEnd(ASF_LexASFImplies arg, ASF_LexASFBarEnd end);
ATbool ASF_isValidASFImplies(ASF_ASFImplies arg);
inline ATbool ASF_isASFImpliesLexToCf(ASF_ASFImplies arg);
ATbool ASF_hasASFImpliesASFImplies(ASF_ASFImplies arg);
ASF_LexASFImplies ASF_getASFImpliesASFImplies(ASF_ASFImplies arg);
ASF_ASFImplies ASF_setASFImpliesASFImplies(ASF_ASFImplies arg, ASF_LexASFImplies ASFImplies);
ATbool ASF_isValidASFConditionalEquation(ASF_ASFConditionalEquation arg);
inline ATbool ASF_isASFConditionalEquationSimple(ASF_ASFConditionalEquation arg);
inline ATbool ASF_isASFConditionalEquationImplies(ASF_ASFConditionalEquation arg);
inline ATbool ASF_isASFConditionalEquationWhen(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg);
ATbool ASF_hasASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg);
ASF_ASFTag ASF_getASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg);
ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg);
ASF_ASFEquation ASF_getASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg);
ASF_ASFConditions ASF_getASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg);
ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg);
ASF_ASFImplies ASF_getASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg);
ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg);
ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg);
ASF_OptLayout ASF_getASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg, ASF_ASFTag ASFTag);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFTag);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg, ASF_ASFEquation ASFEquation);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg, ASF_ASFConditions ASFConditions);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFConditions);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg, ASF_ASFImplies ASFImplies);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFImplies);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFEquation);
ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterWhen);
ATbool ASF_isValidASFEquation(ASF_ASFEquation arg);
inline ATbool ASF_isASFEquationDefault(ASF_ASFEquation arg);
ATbool ASF_hasASFEquationTypeOfLhs(ASF_ASFEquation arg);
ATbool ASF_hasASFEquationTypeOfRhs(ASF_ASFEquation arg);
ATbool ASF_hasASFEquationLhs(ASF_ASFEquation arg);
ATbool ASF_hasASFEquationWsAfterLhs(ASF_ASFEquation arg);
ATbool ASF_hasASFEquationWsAfterEquality(ASF_ASFEquation arg);
ATbool ASF_hasASFEquationRhs(ASF_ASFEquation arg);
ATerm ASF_getASFEquationTypeOfLhs(ASF_ASFEquation arg);
ATerm ASF_getASFEquationTypeOfRhs(ASF_ASFEquation arg);
ASF_Tree ASF_getASFEquationLhs(ASF_ASFEquation arg);
ASF_OptLayout ASF_getASFEquationWsAfterLhs(ASF_ASFEquation arg);
ASF_OptLayout ASF_getASFEquationWsAfterEquality(ASF_ASFEquation arg);
ASF_Tree ASF_getASFEquationRhs(ASF_ASFEquation arg);
ASF_ASFEquation ASF_setASFEquationTypeOfLhs(ASF_ASFEquation arg, ATerm typeOfLhs);
ASF_ASFEquation ASF_setASFEquationTypeOfRhs(ASF_ASFEquation arg, ATerm typeOfRhs);
ASF_ASFEquation ASF_setASFEquationLhs(ASF_ASFEquation arg, ASF_Tree lhs);
ASF_ASFEquation ASF_setASFEquationWsAfterLhs(ASF_ASFEquation arg, ASF_OptLayout wsAfterLhs);
ASF_ASFEquation ASF_setASFEquationWsAfterEquality(ASF_ASFEquation arg, ASF_OptLayout wsAfterEquality);
ASF_ASFEquation ASF_setASFEquationRhs(ASF_ASFEquation arg, ASF_Tree rhs);
ATbool ASF_isValidStart(ASF_Start arg);
inline ATbool ASF_isStartASFModule(ASF_Start arg);
inline ATbool ASF_isStartASFSection(ASF_Start arg);
ATbool ASF_hasStartWsBefore(ASF_Start arg);
ATbool ASF_hasStartTopASFModule(ASF_Start arg);
ATbool ASF_hasStartWsAfter(ASF_Start arg);
ATbool ASF_hasStartAmbCnt(ASF_Start arg);
ATbool ASF_hasStartTopASFSection(ASF_Start arg);
ASF_OptLayout ASF_getStartWsBefore(ASF_Start arg);
ASF_ASFModule ASF_getStartTopASFModule(ASF_Start arg);
ASF_OptLayout ASF_getStartWsAfter(ASF_Start arg);
int ASF_getStartAmbCnt(ASF_Start arg);
ASF_ASFSection ASF_getStartTopASFSection(ASF_Start arg);
ASF_Start ASF_setStartWsBefore(ASF_Start arg, ASF_OptLayout wsBefore);
ASF_Start ASF_setStartTopASFModule(ASF_Start arg, ASF_ASFModule topASFModule);
ASF_Start ASF_setStartWsAfter(ASF_Start arg, ASF_OptLayout wsAfter);
ASF_Start ASF_setStartAmbCnt(ASF_Start arg, int ambCnt);
ASF_Start ASF_setStartTopASFSection(ASF_Start arg, ASF_ASFSection topASFSection);
ATbool ASF_isValidASFModule(ASF_ASFModule arg);
inline ATbool ASF_isASFModuleDefault(ASF_ASFModule arg);
ATbool ASF_hasASFModuleList(ASF_ASFModule arg);
ASF_ASFSectionList ASF_getASFModuleList(ASF_ASFModule arg);
ASF_ASFModule ASF_setASFModuleList(ASF_ASFModule arg, ASF_ASFSectionList list);
ATbool ASF_isValidASFSection(ASF_ASFSection arg);
inline ATbool ASF_isASFSectionEquations(ASF_ASFSection arg);
inline ATbool ASF_isASFSectionTests(ASF_ASFSection arg);
ATbool ASF_hasASFSectionWsAfterEquations(ASF_ASFSection arg);
ATbool ASF_hasASFSectionList(ASF_ASFSection arg);
ATbool ASF_hasASFSectionWsAfterTests(ASF_ASFSection arg);
ATbool ASF_hasASFSectionTestList(ASF_ASFSection arg);
ASF_OptLayout ASF_getASFSectionWsAfterEquations(ASF_ASFSection arg);
ASF_ASFConditionalEquationList ASF_getASFSectionList(ASF_ASFSection arg);
ASF_OptLayout ASF_getASFSectionWsAfterTests(ASF_ASFSection arg);
ASF_ASFTestEquationTestList ASF_getASFSectionTestList(ASF_ASFSection arg);
ASF_ASFSection ASF_setASFSectionWsAfterEquations(ASF_ASFSection arg, ASF_OptLayout wsAfterEquations);
ASF_ASFSection ASF_setASFSectionList(ASF_ASFSection arg, ASF_ASFConditionalEquationList list);
ASF_ASFSection ASF_setASFSectionWsAfterTests(ASF_ASFSection arg, ASF_OptLayout wsAfterTests);
ASF_ASFSection ASF_setASFSectionTestList(ASF_ASFSection arg, ASF_ASFTestEquationTestList testList);
ATbool ASF_isValidASFSectionList(ASF_ASFSectionList arg);
inline ATbool ASF_isASFSectionListEmpty(ASF_ASFSectionList arg);
inline ATbool ASF_isASFSectionListSingle(ASF_ASFSectionList arg);
inline ATbool ASF_isASFSectionListMany(ASF_ASFSectionList arg);
ATbool ASF_hasASFSectionListHead(ASF_ASFSectionList arg);
ATbool ASF_hasASFSectionListWsAfterHead(ASF_ASFSectionList arg);
ATbool ASF_hasASFSectionListTail(ASF_ASFSectionList arg);
ASF_ASFSectionList ASF_getASFSectionListTail(ASF_ASFSectionList arg);
ASF_ASFSection ASF_getASFSectionListHead(ASF_ASFSectionList arg);
ASF_OptLayout ASF_getASFSectionListWsAfterHead(ASF_ASFSectionList arg);
ASF_ASFSectionList ASF_setASFSectionListHead(ASF_ASFSectionList arg, ASF_ASFSection head);
ASF_ASFSectionList ASF_setASFSectionListWsAfterHead(ASF_ASFSectionList arg, ASF_OptLayout wsAfterHead);
ASF_ASFSectionList ASF_setASFSectionListTail(ASF_ASFSectionList arg, ASF_ASFSectionList tail);
ATbool ASF_isValidASFConditionalEquationList(ASF_ASFConditionalEquationList arg);
inline ATbool ASF_isASFConditionalEquationListEmpty(ASF_ASFConditionalEquationList arg);
inline ATbool ASF_isASFConditionalEquationListSingle(ASF_ASFConditionalEquationList arg);
inline ATbool ASF_isASFConditionalEquationListMany(ASF_ASFConditionalEquationList arg);
ATbool ASF_hasASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg);
ATbool ASF_hasASFConditionalEquationListWsAfterHead(ASF_ASFConditionalEquationList arg);
ATbool ASF_hasASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg);
ASF_ASFConditionalEquationList ASF_getASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg);
ASF_ASFConditionalEquation ASF_getASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg);
ASF_OptLayout ASF_getASFConditionalEquationListWsAfterHead(ASF_ASFConditionalEquationList arg);
ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation head);
ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListWsAfterHead(ASF_ASFConditionalEquationList arg, ASF_OptLayout wsAfterHead);
ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquationList tail);
ATbool ASF_isValidASFTestEquationTestList(ASF_ASFTestEquationTestList arg);
inline ATbool ASF_isASFTestEquationTestListEmpty(ASF_ASFTestEquationTestList arg);
inline ATbool ASF_isASFTestEquationTestListSingle(ASF_ASFTestEquationTestList arg);
inline ATbool ASF_isASFTestEquationTestListMany(ASF_ASFTestEquationTestList arg);
ATbool ASF_hasASFTestEquationTestListHead(ASF_ASFTestEquationTestList arg);
ATbool ASF_hasASFTestEquationTestListWsAfterHead(ASF_ASFTestEquationTestList arg);
ATbool ASF_hasASFTestEquationTestListTail(ASF_ASFTestEquationTestList arg);
ASF_ASFTestEquationTestList ASF_getASFTestEquationTestListTail(ASF_ASFTestEquationTestList arg);
ASF_ASFTestEquation ASF_getASFTestEquationTestListHead(ASF_ASFTestEquationTestList arg);
ASF_OptLayout ASF_getASFTestEquationTestListWsAfterHead(ASF_ASFTestEquationTestList arg);
ASF_ASFTestEquationTestList ASF_setASFTestEquationTestListHead(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquation head);
ASF_ASFTestEquationTestList ASF_setASFTestEquationTestListWsAfterHead(ASF_ASFTestEquationTestList arg, ASF_OptLayout wsAfterHead);
ASF_ASFTestEquationTestList ASF_setASFTestEquationTestListTail(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquationTestList tail);
ATbool ASF_isValidLexASFTagId(ASF_LexASFTagId arg);
inline ATbool ASF_isLexASFTagIdOneChar(ASF_LexASFTagId arg);
inline ATbool ASF_isLexASFTagIdManyChars(ASF_LexASFTagId arg);
ATbool ASF_hasLexASFTagIdHead(ASF_LexASFTagId arg);
ATbool ASF_hasLexASFTagIdMiddle(ASF_LexASFTagId arg);
ATbool ASF_hasLexASFTagIdLast(ASF_LexASFTagId arg);
char ASF_getLexASFTagIdHead(ASF_LexASFTagId arg);
char* ASF_getLexASFTagIdMiddle(ASF_LexASFTagId arg);
char ASF_getLexASFTagIdLast(ASF_LexASFTagId arg);
ASF_LexASFTagId ASF_setLexASFTagIdHead(ASF_LexASFTagId arg, char head);
ASF_LexASFTagId ASF_setLexASFTagIdMiddle(ASF_LexASFTagId arg, const char* middle);
ASF_LexASFTagId ASF_setLexASFTagIdLast(ASF_LexASFTagId arg, char last);
ATbool ASF_isValidASFTagId(ASF_ASFTagId arg);
inline ATbool ASF_isASFTagIdLexToCf(ASF_ASFTagId arg);
ATbool ASF_hasASFTagIdASFTagId(ASF_ASFTagId arg);
ASF_LexASFTagId ASF_getASFTagIdASFTagId(ASF_ASFTagId arg);
ASF_ASFTagId ASF_setASFTagIdASFTagId(ASF_ASFTagId arg, ASF_LexASFTagId ASFTagId);
ATbool ASF_isValidASFTag(ASF_ASFTag arg);
inline ATbool ASF_isASFTagEmpty(ASF_ASFTag arg);
inline ATbool ASF_isASFTagNotEmpty(ASF_ASFTag arg);
ATbool ASF_hasASFTagWsAfterBracketOpen(ASF_ASFTag arg);
ATbool ASF_hasASFTagASFTagId(ASF_ASFTag arg);
ATbool ASF_hasASFTagWsAfterASFTagId(ASF_ASFTag arg);
ASF_OptLayout ASF_getASFTagWsAfterBracketOpen(ASF_ASFTag arg);
ASF_ASFTagId ASF_getASFTagASFTagId(ASF_ASFTag arg);
ASF_OptLayout ASF_getASFTagWsAfterASFTagId(ASF_ASFTag arg);
ASF_ASFTag ASF_setASFTagWsAfterBracketOpen(ASF_ASFTag arg, ASF_OptLayout wsAfterBracketOpen);
ASF_ASFTag ASF_setASFTagASFTagId(ASF_ASFTag arg, ASF_ASFTagId ASFTagId);
ASF_ASFTag ASF_setASFTagWsAfterASFTagId(ASF_ASFTag arg, ASF_OptLayout wsAfterASFTagId);
ATbool ASF_isValidASFTestEquation(ASF_ASFTestEquation arg);
inline ATbool ASF_isASFTestEquationSimple(ASF_ASFTestEquation arg);
inline ATbool ASF_isASFTestEquationImplies(ASF_ASFTestEquation arg);
inline ATbool ASF_isASFTestEquationWhen(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationASFTag(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationWsAfterASFTag(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationASFCondition(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationASFConditions(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationWsAfterASFConditions(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationASFImplies(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationWsAfterASFImplies(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationWsAfterASFCondition(ASF_ASFTestEquation arg);
ATbool ASF_hasASFTestEquationWsAfterWhen(ASF_ASFTestEquation arg);
ASF_ASFTag ASF_getASFTestEquationASFTag(ASF_ASFTestEquation arg);
ASF_OptLayout ASF_getASFTestEquationWsAfterASFTag(ASF_ASFTestEquation arg);
ASF_ASFCondition ASF_getASFTestEquationASFCondition(ASF_ASFTestEquation arg);
ASF_ASFConditions ASF_getASFTestEquationASFConditions(ASF_ASFTestEquation arg);
ASF_OptLayout ASF_getASFTestEquationWsAfterASFConditions(ASF_ASFTestEquation arg);
ASF_ASFImplies ASF_getASFTestEquationASFImplies(ASF_ASFTestEquation arg);
ASF_OptLayout ASF_getASFTestEquationWsAfterASFImplies(ASF_ASFTestEquation arg);
ASF_OptLayout ASF_getASFTestEquationWsAfterASFCondition(ASF_ASFTestEquation arg);
ASF_OptLayout ASF_getASFTestEquationWsAfterWhen(ASF_ASFTestEquation arg);
ASF_ASFTestEquation ASF_setASFTestEquationASFTag(ASF_ASFTestEquation arg, ASF_ASFTag ASFTag);
ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFTag(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFTag);
ASF_ASFTestEquation ASF_setASFTestEquationASFCondition(ASF_ASFTestEquation arg, ASF_ASFCondition ASFCondition);
ASF_ASFTestEquation ASF_setASFTestEquationASFConditions(ASF_ASFTestEquation arg, ASF_ASFConditions ASFConditions);
ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFConditions(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFConditions);
ASF_ASFTestEquation ASF_setASFTestEquationASFImplies(ASF_ASFTestEquation arg, ASF_ASFImplies ASFImplies);
ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFImplies(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFImplies);
ASF_ASFTestEquation ASF_setASFTestEquationWsAfterASFCondition(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterASFCondition);
ASF_ASFTestEquation ASF_setASFTestEquationWsAfterWhen(ASF_ASFTestEquation arg, ASF_OptLayout wsAfterWhen);
ATbool ASF_isValidLexLayout(ASF_LexLayout arg);
inline ATbool ASF_isLexLayoutWhitespace(ASF_LexLayout arg);
ATbool ASF_hasLexLayoutCh(ASF_LexLayout arg);
char ASF_getLexLayoutCh(ASF_LexLayout arg);
ASF_LexLayout ASF_setLexLayoutCh(ASF_LexLayout arg, char ch);
ATbool ASF_isValidLexNumChar(ASF_LexNumChar arg);
inline ATbool ASF_isLexNumCharDigits(ASF_LexNumChar arg);
ATbool ASF_hasLexNumCharNumber(ASF_LexNumChar arg);
char* ASF_getLexNumCharNumber(ASF_LexNumChar arg);
ASF_LexNumChar ASF_setLexNumCharNumber(ASF_LexNumChar arg, const char* number);
ATbool ASF_isValidNumChar(ASF_NumChar arg);
inline ATbool ASF_isNumCharLexToCf(ASF_NumChar arg);
ATbool ASF_hasNumCharNumChar(ASF_NumChar arg);
ASF_LexNumChar ASF_getNumCharNumChar(ASF_NumChar arg);
ASF_NumChar ASF_setNumCharNumChar(ASF_NumChar arg, ASF_LexNumChar NumChar);
ATbool ASF_isValidLexShortChar(ASF_LexShortChar arg);
inline ATbool ASF_isLexShortCharRegular(ASF_LexShortChar arg);
inline ATbool ASF_isLexShortCharEscaped(ASF_LexShortChar arg);
ATbool ASF_hasLexShortCharCharacter(ASF_LexShortChar arg);
ATbool ASF_hasLexShortCharEscape(ASF_LexShortChar arg);
char ASF_getLexShortCharCharacter(ASF_LexShortChar arg);
char ASF_getLexShortCharEscape(ASF_LexShortChar arg);
ASF_LexShortChar ASF_setLexShortCharCharacter(ASF_LexShortChar arg, char character);
ASF_LexShortChar ASF_setLexShortCharEscape(ASF_LexShortChar arg, char escape);
ATbool ASF_isValidShortChar(ASF_ShortChar arg);
inline ATbool ASF_isShortCharLexToCf(ASF_ShortChar arg);
ATbool ASF_hasShortCharShortChar(ASF_ShortChar arg);
ASF_LexShortChar ASF_getShortCharShortChar(ASF_ShortChar arg);
ASF_ShortChar ASF_setShortCharShortChar(ASF_ShortChar arg, ASF_LexShortChar ShortChar);
ATbool ASF_isValidCharacter(ASF_Character arg);
inline ATbool ASF_isCharacterNumeric(ASF_Character arg);
inline ATbool ASF_isCharacterShort(ASF_Character arg);
inline ATbool ASF_isCharacterTop(ASF_Character arg);
inline ATbool ASF_isCharacterEof(ASF_Character arg);
inline ATbool ASF_isCharacterBot(ASF_Character arg);
inline ATbool ASF_isCharacterLabelUnderscoreStart(ASF_Character arg);
ATbool ASF_hasCharacterNumChar(ASF_Character arg);
ATbool ASF_hasCharacterShortChar(ASF_Character arg);
ASF_NumChar ASF_getCharacterNumChar(ASF_Character arg);
ASF_ShortChar ASF_getCharacterShortChar(ASF_Character arg);
ASF_Character ASF_setCharacterNumChar(ASF_Character arg, ASF_NumChar NumChar);
ASF_Character ASF_setCharacterShortChar(ASF_Character arg, ASF_ShortChar ShortChar);
ASF_OptLayout ASF_visitOptLayout(ASF_OptLayout arg, ASF_Layout (*acceptLayout)(ASF_Layout));
ASF_Layout ASF_visitLayout(ASF_Layout arg, ASF_LexLayoutList (*acceptList)(ASF_LexLayoutList));
ASF_LexLayoutList ASF_visitLexLayoutList(ASF_LexLayoutList arg, ASF_LexLayout (*acceptHead)(ASF_LexLayout));
ASF_Tree ASF_visitTree(ASF_Tree arg, ATerm (*acceptTree)(ATerm), ASF_OptLayout (*acceptWsAfterAmb)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterParenOpen)(ASF_OptLayout), ASF_TreeAmbs (*acceptAmbs)(ASF_TreeAmbs), ASF_OptLayout (*acceptWsAfterAmbs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterName)(ASF_OptLayout), ASF_CHARList (*acceptList)(ASF_CHARList), ASF_OptLayout (*acceptWsAfterList)(ASF_OptLayout));
ASF_LexCHAR ASF_visitLexCHAR(ASF_LexCHAR arg, char (*acceptValue)(char));
ASF_CHAR ASF_visitCHAR(ASF_CHAR arg, ASF_LexCHAR (*acceptCHAR)(ASF_LexCHAR));
ASF_ASFCondition ASF_visitASFCondition(ASF_ASFCondition arg, ATerm (*acceptTypeOfLhs)(ATerm), ATerm (*acceptTypeOfRhs)(ATerm), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterUnequal)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterEquality)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterMatch)(ASF_OptLayout));
ASF_ASFConditions ASF_visitASFConditions(ASF_ASFConditions arg, ASF_ASFConditionList (*acceptList)(ASF_ASFConditionList));
ASF_ASFConditionList ASF_visitASFConditionList(ASF_ASFConditionList arg, ASF_ASFCondition (*acceptHead)(ASF_ASFCondition), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterSep)(ASF_OptLayout));
ASF_TreeAmbs ASF_visitTreeAmbs(ASF_TreeAmbs arg, ASF_Tree (*acceptHead)(ASF_Tree), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterSep)(ASF_OptLayout));
ASF_CHARList ASF_visitCHARList(ASF_CHARList arg, ASF_CHAR (*acceptHead)(ASF_CHAR), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout));
ASF_LexASFBarEnd ASF_visitLexASFBarEnd(ASF_LexASFBarEnd arg);
ASF_ASFBarEnd ASF_visitASFBarEnd(ASF_ASFBarEnd arg, ASF_LexASFBarEnd (*acceptASFBarEnd)(ASF_LexASFBarEnd));
ASF_LexASFImplies ASF_visitLexASFImplies(ASF_LexASFImplies arg, char* (*acceptBar)(char*), ASF_LexASFBarEnd (*acceptEnd)(ASF_LexASFBarEnd));
ASF_ASFImplies ASF_visitASFImplies(ASF_ASFImplies arg, ASF_LexASFImplies (*acceptASFImplies)(ASF_LexASFImplies));
ASF_ASFConditionalEquation ASF_visitASFConditionalEquation(ASF_ASFConditionalEquation arg, ASF_ASFTag (*acceptASFTag)(ASF_ASFTag), ASF_OptLayout (*acceptWsAfterASFTag)(ASF_OptLayout), ASF_ASFEquation (*acceptASFEquation)(ASF_ASFEquation), ASF_ASFConditions (*acceptASFConditions)(ASF_ASFConditions), ASF_OptLayout (*acceptWsAfterASFConditions)(ASF_OptLayout), ASF_ASFImplies (*acceptASFImplies)(ASF_ASFImplies), ASF_OptLayout (*acceptWsAfterASFImplies)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterASFEquation)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterWhen)(ASF_OptLayout));
ASF_ASFEquation ASF_visitASFEquation(ASF_ASFEquation arg, ATerm (*acceptTypeOfLhs)(ATerm), ATerm (*acceptTypeOfRhs)(ATerm), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquality)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree));
ASF_Start ASF_visitStart(ASF_Start arg, ASF_OptLayout (*acceptWsBefore)(ASF_OptLayout), ASF_ASFModule (*acceptTopASFModule)(ASF_ASFModule), ASF_OptLayout (*acceptWsAfter)(ASF_OptLayout), int (*acceptAmbCnt)(int), ASF_ASFSection (*acceptTopASFSection)(ASF_ASFSection));
ASF_ASFModule ASF_visitASFModule(ASF_ASFModule arg, ASF_ASFSectionList (*acceptList)(ASF_ASFSectionList));
ASF_ASFSection ASF_visitASFSection(ASF_ASFSection arg, ASF_OptLayout (*acceptWsAfterEquations)(ASF_OptLayout), ASF_ASFConditionalEquationList (*acceptList)(ASF_ASFConditionalEquationList), ASF_OptLayout (*acceptWsAfterTests)(ASF_OptLayout), ASF_ASFTestEquationTestList (*acceptTestList)(ASF_ASFTestEquationTestList));
ASF_ASFSectionList ASF_visitASFSectionList(ASF_ASFSectionList arg, ASF_ASFSection (*acceptHead)(ASF_ASFSection), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout));
ASF_ASFConditionalEquationList ASF_visitASFConditionalEquationList(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation (*acceptHead)(ASF_ASFConditionalEquation), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout));
ASF_ASFTestEquationTestList ASF_visitASFTestEquationTestList(ASF_ASFTestEquationTestList arg, ASF_ASFTestEquation (*acceptHead)(ASF_ASFTestEquation), ASF_OptLayout (*acceptWsAfterHead)(ASF_OptLayout));
ASF_LexASFTagId ASF_visitLexASFTagId(ASF_LexASFTagId arg, char (*acceptHead)(char), char* (*acceptMiddle)(char*), char (*acceptLast)(char));
ASF_ASFTagId ASF_visitASFTagId(ASF_ASFTagId arg, ASF_LexASFTagId (*acceptASFTagId)(ASF_LexASFTagId));
ASF_ASFTag ASF_visitASFTag(ASF_ASFTag arg, ASF_OptLayout (*acceptWsAfterBracketOpen)(ASF_OptLayout), ASF_ASFTagId (*acceptASFTagId)(ASF_ASFTagId), ASF_OptLayout (*acceptWsAfterASFTagId)(ASF_OptLayout));
ASF_ASFTestEquation ASF_visitASFTestEquation(ASF_ASFTestEquation arg, ASF_ASFTag (*acceptASFTag)(ASF_ASFTag), ASF_OptLayout (*acceptWsAfterASFTag)(ASF_OptLayout), ASF_ASFCondition (*acceptASFCondition)(ASF_ASFCondition), ASF_ASFConditions (*acceptASFConditions)(ASF_ASFConditions), ASF_OptLayout (*acceptWsAfterASFConditions)(ASF_OptLayout), ASF_ASFImplies (*acceptASFImplies)(ASF_ASFImplies), ASF_OptLayout (*acceptWsAfterASFImplies)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterASFCondition)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterWhen)(ASF_OptLayout));
ASF_LexLayout ASF_visitLexLayout(ASF_LexLayout arg, char (*acceptCh)(char));
ASF_LexNumChar ASF_visitLexNumChar(ASF_LexNumChar arg, char* (*acceptNumber)(char*));
ASF_NumChar ASF_visitNumChar(ASF_NumChar arg, ASF_LexNumChar (*acceptNumChar)(ASF_LexNumChar));
ASF_LexShortChar ASF_visitLexShortChar(ASF_LexShortChar arg, char (*acceptCharacter)(char), char (*acceptEscape)(char));
ASF_ShortChar ASF_visitShortChar(ASF_ShortChar arg, ASF_LexShortChar (*acceptShortChar)(ASF_LexShortChar));
ASF_Character ASF_visitCharacter(ASF_Character arg, ASF_NumChar (*acceptNumChar)(ASF_NumChar), ASF_ShortChar (*acceptShortChar)(ASF_ShortChar));

#endif /* _ASFME_H */
