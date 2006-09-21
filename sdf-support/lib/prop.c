#include "SDFME-utils.h"

static void
collect_kernel_props(SDF_Grammar grammar, SDF_PropertyList *props) {
  if (SDF_isGrammarSyntax(grammar)) {
    SDF_Properties grammarProps = SDF_getGrammarProperties(grammar);
    SDF_PropertyList propertyList = SDF_getPropertiesList(grammarProps);

    *props = SDF_concatPropertyList(*props,
				      SDF_makeLayoutSpace(),
				      propertyList);
  }
}

SDF_PropertyList
SDF_getGrammarKernelProperties(SDF_Grammar grammar) {
  SDF_PropertyList props = SDF_makePropertyListEmpty();

  SDFforeachGrammar(grammar,
		    (SDFGrammarFunc)collect_kernel_props,
		    (void *)&props);

  return props;
}
