#ifndef RENAMING_SYMBOLS_H
#define RENAMING_SYMBOLS_H

ASF_CondEquationList renameParametersInEquations(SDF_ModuleName moduleName,
                                                 ASF_CondEquationList asfTree,
                                                 SDF_Symbols actualParams);
ASF_CondEquationList renameSymbolsInEquations(ASF_CondEquationList asfTree,
                                              SDF_Renamings renamings);
#endif
