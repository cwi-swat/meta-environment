#ifndef __EditorManager_dict_H
#define __EditorManager_dict_H

#include <aterm2.h>

extern AFun EM_afun0;
extern AFun EM_afun2;
extern AFun EM_afun3;
extern AFun EM_afun1;

extern ATerm EM_patternEditorTypeListMany;
extern ATerm EM_patternEditorTypeListSingle;
extern ATerm EM_patternEditorTypeListEmpty;
extern ATerm EM_patternSessionDefault;
extern ATerm EM_patternSessionStatusZombie;
extern ATerm EM_patternSessionStatusRunning;
extern ATerm EM_patternEditorTypeDefault;
extern ATerm EM_patternSidDefault;

extern void init_EditorManager_dict();

#endif /* __EditorManager_dict_H */
