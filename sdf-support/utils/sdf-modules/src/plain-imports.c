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
    ATerm value = ATelementAt(pair, 1);
    ATtablePut(importsTable, key, value);
  }
}

static void destroyImportsTable()
{
  ATtableDestroy(importsTable);
  importsTable = NULL;
}

static ATermList merge(ATermList l1, ATermList l2)
{
  for (; !ATisEmpty(l1); l1 = ATgetNext(l1)) {
    ATerm elem = ATgetFirst(l1);
    if (ATindexOf(l1, elem, 0) < 0) {
      l2 = ATinsert(l2, elem);
    }
  }

  return l2;
}

ATermList PI_getTransitiveImports(ATermList idImportPairs, ATerm id)
{
  ATermList todo = ATmakeList1(id);
  ATermList result = ATempty;
  initImportsTable(idImportPairs);

  while (!ATisEmpty(todo)) {
    ATerm module = ATgetFirst(todo);
    ATermList imports = (ATermList) ATtableGet(importsTable, module);

    todo = merge(imports, ATgetNext(todo));
    result = merge(ATmakeList1(module), result);
  }

  destroyImportsTable();
  return result; 
}
