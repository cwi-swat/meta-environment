#include <MEPT-utils.h>
#include <ASF-utils.h>
#include <SDF-utils.h>
#include <MuASF.h>

#include "sdf2pt.h"
#include "chars.h"

typedef enum { WITH_LAYOUT, WITHOUT_LAYOUT } LayoutOption;

static char* prodToEscapedString(PT_Production prod)
{
  char *strProd = ATwriteToString(ptProd);
  return escape(strProd,"\\\"");
}

static getProdArity(PT_Production prod, ATbool withLayout)
{
  PT_Symbols symbols = PT_getProductionSymbols(prod);
  int arity = 0;

  for (; PT_hasSymbolsHead(symbols); symbols = PT_getSymbolsTail(symbols)) {
    PT_Symbol symbol = PT_getSymbolsHead(symbols);

    if (!PT_isSymbolLiteral(symbol) &&
        (withLayout || !PT_isSymbolLayout(symbol))) {
      arity++;
    }
  }

  return arity;  
}

static MA_FuncDef productionToFuncDef(SDF_Production prod)
{
  PT_Production ptProd = flattenSdfProduction(prod)
  char *strProd = prodToEscapedString(ptProd);
  int arity = getProdArity(ptProd, WITHOUT_LAYOUT);
  
  return MA_makeFuncDefConstantNoAnnos(
	   MA_makeFunId());
}

static MA_SignatureOpt productionListToSignature(SDF_ProductionList list)
{
  SDF_Production sdfProd;
  PT_Production ptProd;
  MA_FuncDefs maFuncDefs = MA_makeFuncDefsEmpty();
  MA_FuncDef maFuncDef;

  for(;SDF_hasProductionListHead(list);list = SDF_getProductionListTail(list)) {
    sdfProd = SDF_getProductionListHead(list);
    maFuncDef = productionToFuncDef(sdfProd);
    maFuncDefs = MA_makeFuncDefsMany(maFuncDef,l,";",l,maFuncDefs);
  }

  return MA_makeSignatureOptPresent(l,
				    MA_makeFuncDefListDefault(maFuncDefs),
				    l);
}

static MA_RulesOpt     EquationsToRules(ASF_CondEquationList list);
static MA_ModId        NameToMuASFName(PT_ModuleName name);

MA_Module 
asFix2MuASF(PT_ModuleName name, SDF_ProductionList signature, 
	    ASF_CondEquationList equations)
{
  MA_SignatureOpt muSignature = productionListToSignature(signature);
  MA_RulesOpt muRules = equationsToRules(equations);
  MA_ModId muName = nameToMuASFName(name);
  MA_Layout l; 

  return MA_makeModuleDefault(l,muName,l,muSignature,l,muRules);
}


