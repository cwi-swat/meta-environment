/*
  $Id$
 */

#include <stdlib.h>
#include <aterm2.h>
#include <atb-tool.h>

#include "table-store.h"
#include "term-store.tif.h"

static char myversion[] = "1.0";

/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */
/*{{{  static void usage(char *prg, ATbool is_err) */

static void usage(char *prg, ATbool is_err)
{
    ATwarning("term-store: generic ATerm storage tool.\n"
	      "This tool can only be executed on the ToolBus platform.\n");
    exit(is_err ? 1 : 0);
}

/*}}}  */
/*{{{  static void version(const char *msg) */

static void version(const char *msg)
{
    ATwarning("%s v%s\n", msg, myversion);
    exit(1);
}

/*}}}  */

#define RESULT(t) (ATmake("snd-value(result(<term>))",t))
#define RESULT_TERM(t) (ATmake("snd-value(result(<term>))",t))
#define RESULT_STR(s) (ATmake("snd-value(result(<str>))",s))
#define NO_RESULT (ATmake("snd-value(no-result)"))
#ifndef streq
#define streq(s1,s2) (strcmp(s1,s2) == 0)
#endif

/*{{{  ATerm get_str_value(int conn, char *table, ATerm key) */

ATerm get_str_value(int conn, char *table, ATerm key)
{
  ATerm value = TS_getValue(table, key);
  char *valueType = TS_getTableValueType(table);

  if (!streq(valueType, TS_STR_TYPE)) {
    ATwarning("Warning: trying to obtain string from a term table");
    return NO_RESULT;
  }
  else {
    if (value != NULL) {
      return RESULT_STR(ATgetName(ATgetAFun((ATermAppl) value)));
    }
    else {
      return NO_RESULT;
    }
  }
}

/*}}}  */
/*{{{  ATerm get_term_value(int conn, char *table, ATerm key) */

ATerm get_term_value(int conn, char *table, ATerm key)
{
  ATerm value = TS_getValue(table, key);
  char *valueType = TS_getTableValueType(table);

  if (!streq(valueType, TS_TERM_TYPE)) {
    ATwarning("Warning: trying to obtain term from a string table");
    return NO_RESULT;
  }
  else {
    if (value != NULL) {
      return RESULT_TERM(value);
    }
    else {
      return NO_RESULT;
    }
  }
}

/*}}}  */
/*{{{  void remove_value(int conn, char *table, ATerm key) */

void remove_value(int conn, char *table, ATerm key)
{
  TS_removeValue(table, key);
}

/*}}}  */
/*{{{  void put_value(int conn, char *table, ATerm key, ATerm value) */

void put_term_value(int conn, char *table, ATerm key, ATerm value)
{
  TS_putValue(table, key, value);
}

/*}}}  */
/*{{{  void put_str_value(int conn, char *table, ATerm key, char* value) */

void put_str_value(int conn, char *table, ATerm key, char* value)
{
  TS_putValue(table, key, ATmake("<str>", value));
}

/*}}}  */
/*{{{  ATerm contains_key(int conn, char *table, ATerm key) */

ATerm contains_key(int conn, char *table, ATerm key)
{
  return TS_containsKey(table,key) ?
    RESULT(ATmake("yes")) :
    RESULT(ATmake("no"));
}

/*}}}  */
/*{{{  void clear_table(int conn, char *table) */

void clear_table(int conn, char *table)
{
  TS_clearTable(table);
}

/*}}}  */
/*{{{  ATerm get_all_keys(int conn, char *table) */

ATerm get_all_keys(int conn, char *table)
{
  return RESULT((ATerm) TS_getAllKeys(table));
}

/*}}}  */
/*{{{  ATerm get_all_values(int conn, char *table) */

ATerm get_all_values(int conn, char *table)
{
  return RESULT((ATerm) TS_getAllValues(table));
}

/*}}}  */
/*{{{  ATerm get_values(int conn, char *table, ATerm keys) */

ATerm get_values(int conn, char *table, ATerm keys)
{
  return RESULT((ATerm) TS_getValues(table, (ATermList) keys));
}

/*}}}  */
/*{{{  ATerm get_key_value_pairs(int conn, char *table) */

ATerm get_key_value_pairs(int conn, char *table)
{
  return RESULT((ATerm) TS_getAllKeyValuePairs(table));
}

/*}}}  */
/*{{{  void remove_table(int conn, char *table) */

void remove_table(int conn, char *table)
{
  TS_removeTable(table);
}

/*}}}  */
/*{{{  void add_table(int conn, char *table) */

void add_table(int conn, char *table, char *valueType)
{
  TS_addTable(table, valueType);
}

/*}}}  */
/*{{{  void remove_value_from_all_tables(int conn, ATerm key) */

void remove_value_from_all_tables(int conn, ATerm key)
{
  TS_removeValueFromAllTables(key);
}

/*}}}  */

/*{{{  ATerm filter_keys(int conn, char *table, ATerm keys) */

ATerm filter_keys(int conn, char *table, ATerm keys)
{
  return RESULT((ATerm) TS_filterKeys(table, (ATermList) keys));
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int i, cid;
  ATerm bottomOfStack;

  for (i=1; i<argc; i++) {
      if (strcmp(argv[i], "-h") == 0) {
	  usage(argv[0], ATfalse);
      } else if (strcmp(argv[i], "-V") == 0) {
	  version(argv[0]);
      }
  }

  ATBinit(argc, argv, &bottomOfStack);
  TS_initTableStore();

  cid = ATBconnect(NULL, NULL, -1, term_store_handler);

  ATBeventloop();

  return 0;
}

/*}}}  */
