#ifndef __MetaConfig_dict_H
#define __MetaConfig_dict_H

#include <aterm2.h>

extern AFun MC_afun8;
extern AFun MC_afun17;
extern AFun MC_afun0;
extern AFun MC_afun11;
extern AFun MC_afun5;
extern AFun MC_afun3;
extern AFun MC_afun9;
extern AFun MC_afun16;
extern AFun MC_afun10;
extern AFun MC_afun4;
extern AFun MC_afun13;
extern AFun MC_afun14;
extern AFun MC_afun19;
extern AFun MC_afun2;
extern AFun MC_afun7;
extern AFun MC_afun12;
extern AFun MC_afun15;
extern AFun MC_afun18;
extern AFun MC_afun6;
extern AFun MC_afun1;

extern ATerm MC_patternModuleNameWildcard;
extern ATerm MC_patternItemsMany;
extern ATerm MC_patternItemsSingle;
extern ATerm MC_patternItemsEmpty;
extern ATerm MC_patternEventShortcut;
extern ATerm MC_patternEventDefault;
extern ATerm MC_patternEventIcon;
extern ATerm MC_patternEventClick;
extern ATerm MC_patternActionTypeWildcard;
extern ATerm MC_patternActionTypeStudioToolbar;
extern ATerm MC_patternActionTypeStudioMenubar;
extern ATerm MC_patternActionTypeNewModulePopup;
extern ATerm MC_patternActionTypeModulePopup;
extern ATerm MC_patternActionTypeTreePanel;
extern ATerm MC_patternActionTypeFeedbackList;
extern ATerm MC_patternActionTypeSyntaxEditor;
extern ATerm MC_patternActionTypeEquationsEditor;
extern ATerm MC_patternActionTypeTermEditorForModule;
extern ATerm MC_patternActionTypeTermEditor;
extern ATerm MC_patternActionDescriptionListMany;
extern ATerm MC_patternActionDescriptionListSingle;
extern ATerm MC_patternActionDescriptionListEmpty;
extern ATerm MC_patternActionDescriptionDefault;
extern ATerm MC_patternPropertyModulePath;
extern ATerm MC_patternPropertyExtension;
extern ATerm MC_patternPropertyAction;
extern ATerm MC_patternPropertiesMany;
extern ATerm MC_patternPropertiesSingle;
extern ATerm MC_patternPropertiesEmpty;
extern ATerm MC_patternConfigurationList;

extern void init_MetaConfig_dict();

#endif /* __MetaConfig_dict_H */
