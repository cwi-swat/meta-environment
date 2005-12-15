#include "toolbus.h"
#include "partners.h"
#include "tools.h"
#include "utils.h"

#define INITIAL_SIZE 4096

static term_list **receives_funs_to_procs;
static term_list **receives_procs_to_funs;
static term_list **sends_funs_to_procs;
static term_list **sends_procs_to_funs;
static term_list **proc_instances;
static size_t currentSize = INITIAL_SIZE;

/*{{{  void CPC_initCommunicationPartnerCache()  */

void CPC_initCommunicationPartnerCache() 
{
  receives_funs_to_procs = (term_list**) calloc(currentSize, sizeof(term_list*));
  if (receives_funs_to_procs == NULL) {
    err_fatal("could not allocate memory for partner cache\n");
  }

  sends_funs_to_procs = (term_list**) calloc(currentSize, sizeof(term_list*));
  if (sends_funs_to_procs == NULL) {
    err_fatal("could not allocate memory for partner cache\n");
  }

  receives_procs_to_funs = (term_list**) calloc(currentSize, sizeof(term_list*));
  if (receives_procs_to_funs == NULL) {
    err_fatal("could not allocate memory for partner cache\n");
  }

  sends_procs_to_funs = (term_list**) calloc(currentSize, sizeof(term_list*));
  if (sends_procs_to_funs == NULL) {
    err_fatal("could not allocate memory for partner cache\n");
  }

  proc_instances = (term_list**) calloc(currentSize, sizeof(term_list*));
  if (proc_instances == NULL) {
    err_fatal("could not allocate memory for partner cache\n");
  }
}

/*}}}  */
/*{{{  void CPC_destroyCommunicationPartnerCache() */

void CPC_destroyCommunicationPartnerCache()
{
  free(receives_funs_to_procs);
  receives_funs_to_procs = NULL;
  free(sends_funs_to_procs);
  sends_funs_to_procs = NULL;
  free(receives_procs_to_funs);
  receives_procs_to_funs = NULL;
  free(sends_procs_to_funs);
  sends_procs_to_funs = NULL;
}

/*}}}  */

/*{{{  static void resize(size_t oldSize, size_t newSize, term_list ***array) */

static void recalloc(size_t oldSize, size_t newSize, term_list ***array)
{
  
  *array = realloc(*array, newSize);
  if (*array == NULL) {
    err_fatal("recalloc: could not allocate memory");
  }
  else {
    memset(*array+oldSize, 0, newSize - oldSize);
  }
}

/*}}}  */
/*{{{  static void resize()  */

static void resize() 
{
  size_t oldSize = currentSize;

  currentSize += INITIAL_SIZE;

  recalloc(oldSize, currentSize, &sends_funs_to_procs);
  recalloc(oldSize, currentSize, &receives_funs_to_procs);
  recalloc(oldSize, currentSize, &sends_procs_to_funs);
  recalloc(oldSize, currentSize, &receives_procs_to_funs);
  recalloc(oldSize, currentSize, &proc_instances);
}

/*}}}  */

/*{{{  static void storeItem(term *item, sym_idx index, term_list** store) */

static void storeItem(term *item, sym_idx index, term_list** store)
{
  term_list *bucket;
  
  while (index >= currentSize) {
    resize();
  }

  bucket = store[index];

  if (bucket == NULL) {
    store[index] = (term_list*) mk_list1(item);
    TBprotect(&store[index]);
  }
  else {
    store[index] = list_union(mk_list1(item), store[index]);
  }
}

/*}}}  */

/*{{{  static void storeSend(term *processName, sym_idx Atom)  */

static void storeSend(term *processName, sym_idx Atom) 
{
  storeItem(processName, Atom, sends_funs_to_procs);
  storeItem(mk_int(Atom), fun_sym(processName), sends_procs_to_funs);
}

/*}}}  */
/*{{{  void CPC_storeSend(term *processName, atom *Atom) */

void CPC_storeSend(term *processName, atom *Atom)
{
  term_list *kids = at_args(Atom);
  term *first = first(kids);
  sym_idx idx;

  assert(is_appl(first) && "first arg of snd-msg is not an appl");

  idx = fun_sym(first);

  assert(at_fun(Atom) == a_snd_msg);

  storeSend(processName, idx);
}

/*}}}  */

/*{{{  static void storeReceive(term *processName, sym_idx Atom)  */

static void storeReceive(term *processName, sym_idx Atom) 
{
  storeItem(processName, Atom, receives_funs_to_procs);
  storeItem(mk_int(Atom), fun_sym(processName), receives_procs_to_funs);
}

/*}}}  */
/*{{{  void CPC_storeReceive(term *processName, atom *Atom) */

void CPC_storeReceive(term *processName, atom *Atom)
{
  term_list *kids = at_args(Atom);
  term *first = first(kids);
  sym_idx idx;

  assert(is_appl(first) && "first arg of rec-msg is not an appl");

  idx = fun_sym(first);

  assert(at_fun(Atom) == a_rec_msg);

  storeReceive(processName, idx);
}

/*}}}  */

/*{{{  term_list *CPC_lookupSend(atom *Atom)  */

term_list *CPC_lookupSend(atom *Atom) 
{
  term_list *kids = at_args(Atom);
  term *first = first(kids);
  sym_idx idx = fun_sym(first);

  assert(at_fun(Atom) == a_rec_msg);
  assert(idx <= currentSize);

  return sends_funs_to_procs[idx];
}

/*}}}  */
/*{{{  term_list *CPC_lookupReceive(atom *Atom)  */

term_list *CPC_lookupReceive(atom *Atom) 
{
  term_list *kids = at_args(Atom);
  term *first = first(kids);
  sym_idx idx = fun_sym(first);

  assert(at_fun(Atom) == a_snd_msg);
  assert(idx <= currentSize);

  return receives_funs_to_procs[idx];
}

/*}}}  */

/*{{{  void CPC_join(sym_idx processNameFrom, sym_idx processNameTo) */

void CPC_join(sym_idx processNameFrom, sym_idx processNameTo)
{
  term_list *funs = sends_procs_to_funs[processNameFrom]; 
  for ( ; funs; funs = next(funs)) {
    term *first = first(funs);

    storeSend(mk_appl(processNameTo, NULL), int_val(first));
  }

  funs = receives_procs_to_funs[processNameFrom]; 
  for ( ; funs; funs = next(funs)) {
    term *first = first(funs);
    storeReceive(mk_appl(processNameTo, NULL), int_val(first));
  }
}

/*}}}  */

/*{{{  void CPC_storeInstance(term *processName, proc_inst instance) */

void CPC_storeInstance(sym_idx processName, proc_inst *instance)
{
  storeItem((term*) instance, processName, proc_instances);
}

/*}}}  */
/*{{{  void CPC_removeInstance(proc_inst *instance) */

void CPC_removeInstance(proc_inst *instance)
{
  sym_idx processName = TBlookup(str_val(pi_name(instance)));
  assert(processName <= currentSize);

  proc_instances[processName] = list_delete(proc_instances[processName],
					    instance);
}

/*}}}  */

/*{{{  term_list *CPC_lookupInstances(sym_idx processName) */

term_list *CPC_lookupInstances(sym_idx processName)
{
  assert(processName <= currentSize);

  return proc_instances[processName];
}

/*}}}  */
