#ifndef RENAMING_SYMBOLS_H
#define RENAMING_SYMBOLS_H

SDF_ImportList renameParametersInImportList(SDF_ModuleName moduleName,
                                            PT_Tree sdfTree,
                                            SDF_ImportList importList);
ASF_CondEquationList renameParametersInEquations(SDF_ModuleName moduleName,
                                                 ASF_CondEquationList asfTree,
                                                 SDF_Symbols actualParams);
ASF_CondEquationList renameSymbolsInEquations(ASF_CondEquationList asfTree,
                                              SDF_Renamings renamings);
#endif
