#include <SDFME-utils.h>

SDF_Renamings SDF_makeRenamingsFromParameters(SDF_Symbols formals,
					      SDF_Symbols actuals)
{
  SDF_OptLayout layout = SDF_makeLayoutEmpty();
  SDF_RenamingList renamingList;
  SDF_SymbolList formalList;
  SDF_SymbolList actualList;

  formalList = SDF_getSymbolsList(formals);
  actualList = SDF_getSymbolsList(actuals);

  renamingList = SDF_makeRenamingListEmpty();

  while (SDF_hasSymbolListHead(actualList) &&
	 SDF_hasSymbolListHead(formalList)) {
    SDF_Symbol formal = SDF_getSymbolListHead(formalList);
    SDF_Symbol actual = SDF_getSymbolListHead(actualList);
    SDF_Renaming renaming = SDF_makeRenamingSymbol(formal,layout,layout,actual);
    
    renamingList = SDF_makeRenamingListMany(renaming,layout,renamingList);

    if (SDF_hasSymbolListTail(actualList)) {
      actualList = SDF_getSymbolListTail(actualList);
    }
    else {
      break;
    }

    if (SDF_hasSymbolListTail(formalList)) {
      formalList = SDF_getSymbolListTail(formalList);
    }
    else {
      ATwarning("WARNING: less formal parameters than actual parameters!");
      break;
    }
  }

  return SDF_makeRenamingsRenamings(layout,renamingList,layout);
}

SDF_Renamings SDF_makeRenamingsFromModuleNames(SDF_ModuleName formal,
					       SDF_ModuleName actual)
{
  SDF_Symbols actualParams = SDF_getModuleNameParams(actual);
  SDF_Symbols formalParams = SDF_getModuleNameParams(formal);
  
  return SDF_makeRenamingsFromParameters(formalParams, actualParams);
}
