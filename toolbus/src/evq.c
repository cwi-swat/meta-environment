#line 58 "evq.c.nw"
#include "evq.h"

#line 74 "evq.c.nw"
event_queue *TBevq_create(int max_size, int cid)
{
  event_queue *q;

  q = malloc(sizeof(event_queue));
  if(!q) {
    return NULL;
  }
  q->max_size = max_size;
  q->cid = cid;
  q->events = NULL;
  q->pending = NULL;
  TBprotect(&q->events);
  TBprotect(&q->pending);

  return q;
}
#line 99 "evq.c.nw"
void TBevq_destroy(event_queue *q)
{
  assert(q);
  TBunprotect(&q->events);
  TBunprotect(&q->pending);
  free(q);
}
#line 115 "evq.c.nw"
void TBevq_post(event_queue *q, term *event)
{
  /* First check for a queue overrun */
  if(TBevq_length(q) == q->max_size)
    TBmsg("event queue overrun, 'forgetting' event %t\n", event);
  else {
    /* If an event was already pending, put the event at the end
       of the event list. */
    if(q->pending)
      q->events = list_concat_term(q->events, event);
    else {
      /* No events where pending. Send this one immediately. */
      if(q->cid >= 0)
        TB_send(q->cid, TB_make("snd-event(<term>)", event));
      else
        TBsend(TB_make("snd-event(<term>)", event));
      q->pending = event;
    }
  }
}
#line 143 "evq.c.nw"
TBbool TBevq_is_full(event_queue *q)
{
  return TBevq_length(q) >= q->max_size;
}
#line 155 "evq.c.nw"
TBbool TBevq_is_empty(event_queue *q)
{
  return !q->pending;
}
#line 167 "evq.c.nw"
int TBevq_length(event_queue *q)
{
  return list_length(q->events);
}
#line 181 "evq.c.nw"
TBbool TBevq_ack_event(event_queue *q, term *ev)
{
  term *event;

  if(q->pending && term_equal(q->pending, ev)) {
    /* Send the next event */
    if(q->events == NULL) {
      q->pending = NULL;
    } else {
      event = first(q->events);
      if(q->cid >= 0)
        TB_send(q->cid, TB_make("snd-event(<term>)", event));
      else
        TBsend(TB_make("snd-event(<term>)", event));
      q->pending = event;
      q->events  = next(q->events);
    }
    return TBtrue;
  }
  return TBfalse;
}
