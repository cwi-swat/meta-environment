#include <aterm2.h>
#include <assert.h>

ATermTable importsTable = NULL;

static void initImportsTable(ATermList pairs)
{
  importsTable = ATtableCreate(1500,75);

  assert(importsTable != NULL && "out of memory\n");

  for( ; !ATisEmpty(pairs); pairs = ATgetNext(pairs)) {
    ATermList pair = (ATermList) ATgetFirst(pairs);
    ATerm key = ATgetFirst(pair);
    ATerm value = ATgetFirst(ATgetNext(pair));
    ATtablePut(importsTable, key, value);
  }
}

static void destroyImportsTable()
{
  ATtableDestroy(importsTable);
  importsTable = NULL;
}

static ATbool isElem(ATerm e, ATermList l)
{
  return (ATindexOf(l, e, 0) != -1);
}

static ATermList merge(ATermList l1, ATermList l2)
{
  for (; !ATisEmpty(l1); l1 = ATgetNext(l1)) {
    ATerm elem = ATgetFirst(l1);

    if (!isElem(elem, l2)) {
      l2 = ATinsert(l2, elem);
    }
  }

  return l2;
}

static ATermList getTransitiveImports(ATerm id)
{
  ATermList result = ATempty;
  ATermList todo = ATmakeList1(id);

  assert(importsTable != NULL && "importsTable should be initialized");

  while (!ATisEmpty(todo)) {
    ATermList imports;
    ATerm module;

    module = ATgetFirst(todo);
    todo = ATgetNext(todo);

    if (!isElem(module, result)) {
      imports = (ATermList) ATtableGet(importsTable, module);
      if (imports != NULL) {
        todo = merge(imports, todo);
      }
    }

    result = merge(ATmakeList1(module), result);
  }

  return result;
}
  
static ATermList getDependingModules(ATerm id)
{
  ATermList modules;
  ATermList result = ATempty;

  assert(importsTable != NULL && "importsTable should be initialized");
  
  modules = ATtableKeys(importsTable);

  for( ;!ATisEmpty(modules); modules = ATgetNext(modules)) {
    ATerm module = ATgetFirst(modules);

    if (!ATisEqual(id, module)) {
      ATermList imports = getTransitiveImports(module);

      if (isElem(id, imports)) {
        result = ATinsert(result, module);
      }
    }
  }

  return result;
}

ATermList PI_getTransitiveImports(ATermList idImportPairs, ATerm id)
{
  ATermList result;

  initImportsTable(idImportPairs);
  result = getTransitiveImports(id);

  destroyImportsTable();
  return result; 
}

ATermList PI_getDependingModules(ATermList idImportPairs, ATerm id)
{
  ATermList result;
  
  initImportsTable(idImportPairs);
  result = getDependingModules(id);
  destroyImportsTable();
  return result;
}

static ATermList filterDirectDependingModules(ATermList dependingModules,  ATerm id)
{
  ATermList result = ATempty;

  for( ;!ATisEmpty(dependingModules); dependingModules = ATgetNext(dependingModules)) {
    ATerm module = ATgetFirst(dependingModules);
    ATermList imports = (ATermList) ATtableGet(importsTable, module);

    if (isElem(id, imports)) {
       result = ATinsert(result, module);
    }
  }

  return result;
}

ATermList PI_getDirectDependingModules(ATermList idImportPairs, ATerm id)
{
  ATermList result;

  initImportsTable(idImportPairs);
  result = filterDirectDependingModules(getDependingModules(id), id);
  destroyImportsTable();

  return result;
}
