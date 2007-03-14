/* $Id$ */

#include "parseTable-stats.h"
#include "parseTable-data.h"
#include <logging.h>

static int nr_of_actions; /* Total number of X in parse table. */
static int nr_of_gotos; 
static int nr_of_items;

static int max_nr_actions; /* Max number of X in one state. */
static int max_nr_gotos;
static int max_nr_items;

void PGEN_initParseTableStats() {
  nr_of_actions = 0;
  nr_of_gotos = 0;
  nr_of_items = 0;
  max_nr_actions = 0;
  max_nr_gotos = 0;
  max_nr_items = 0;
}

int PGEN_getNumberOfActions() {
  return nr_of_actions;
}

void PGEN_increaseNumberOfActions(int value) {
  nr_of_actions += value;
  if (value > max_nr_actions) {
    max_nr_actions = value;
  }
}

int PGEN_getNumberOfGotos() {
  return nr_of_gotos;
}

void PGEN_increaseNumberOfGotos(int value) {
  nr_of_gotos += value;
  if (value > max_nr_gotos) {
    max_nr_gotos = value;
  }
}

int PGEN_getNumberOfItems() {
  return nr_of_items;
}

void PGEN_increaseNumberOfItems(int value) {
  nr_of_items += value;
  if (value > max_nr_items) {
    max_nr_items = value;
  }
}

void PGEN_printStats() {
  int numberOfStates = PGEN_getNumberOfStates();
  
  fprintf(LOG_log(), "Number of states is %d\n", numberOfStates);
  fprintf(LOG_log(), "Maximum number of items per state is %d\n", max_nr_items);
  fprintf(LOG_log(), "Average number of items per state is %d\n", (nr_of_items/numberOfStates));

  fprintf(LOG_log(), "Maximum number of gotos per state is %d\n", max_nr_gotos);
  fprintf(LOG_log(), "Average number of gotos per state is %d\n", (nr_of_gotos/numberOfStates));
  fprintf(LOG_log(), "Maximum number of actions per state is %d\n", max_nr_actions);
  fprintf(LOG_log(), "Average number of actions per state is %d\n", (nr_of_actions/numberOfStates));

}

