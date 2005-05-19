#ifndef __PARTNERS_H__
#define __PARTNERS_H__

#include "toolbus.h"
#include "terms.h"
#include "procs.h"

void CPC_initCommunicationPartnerCache(); 
void CPC_destroyCommunicationPartnerCache();
void CPC_storeSend(term *processName, atom *Atom);
void CPC_storeReceive(term *processName, atom *Atom);
term_list *CPC_lookupSend(atom *Atom); 
term_list *CPC_lookupReceive(atom *Atom);
void CPC_join(sym_idx processNameFrom, sym_idx processNameTo);

void CPC_storeInstance(sym_idx processName, proc_inst *instance);
void CPC_removeInstance(proc_inst *instance);
term_list *CPC_lookupInstances(sym_idx processName);

#endif
