#line 20 "evq.c.nw"
#ifndef EVQ_H
#define EVQ_H

#include "TB.h"

typedef struct {
  int cid;
  int max_size;
  term_list *events;
  term *pending;
} event_queue;

event_queue *TBevq_create(int max_size, int cid);
void TBevq_destroy(event_queue *q);
void TBevq_post(event_queue *q, term *event);
TBbool TBevq_is_full(event_queue *q);
TBbool TBevq_is_empty(event_queue *q);
int TBevq_length(event_queue *q);
TBbool TBevq_ack_event(event_queue *q, term *event);

#endif
