/*

    ToolBus -- The ToolBus Application Architecture
    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
                             The  Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
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
    if(q->pending) {
      q->events = list_concat_term(q->events, event);
      /*TBprintf(stderr, "%t is pending, queueing %t\n", q->pending, event);*/
    } else {
      /* No events where pending. Send this one immediately. */
      if(q->cid >= 0)
        TB_send(q->cid, TB_make("snd-event(<term>)", event));
      else
        TBsend(TB_make("snd-event(<term>)", event));
      q->pending = event;
      /*TBprintf(stderr, "no events pending, sending %t\n", event);*/
    }
  }
}
#line 145 "evq.c.nw"
TBbool TBevq_is_full(event_queue *q)
{
  return TBevq_length(q) >= q->max_size;
}
#line 157 "evq.c.nw"
TBbool TBevq_is_empty(event_queue *q)
{
  return !q->pending;
}
#line 169 "evq.c.nw"
int TBevq_length(event_queue *q)
{
  return list_length(q->events);
}
#line 183 "evq.c.nw"
TBbool TBevq_ack_event(event_queue *q, term *ev)
{
  term *event;

  if(q->pending && fun_sym(q->pending) == fun_sym(ev)) {
    /* Send the next event */
    if(q->events == NULL) {
      /*TBprintf(stderr, "ack of last pending event: %t\n", ev);*/
      q->pending = NULL;
    } else {
      event = first(q->events);
      if(q->cid >= 0)
        TB_send(q->cid, TB_make("snd-event(<term>)", event));
      else
        TBsend(TB_make("snd-event(<term>)", event));
      q->pending = event;
      q->events  = next(q->events);
      /*TBprintf(stderr, "sending next event from queue: %t\n", event);*/
    }
    return TBtrue;
  }
  /*if(q->pending)
    TBprintf(stderr, "pending term:\n  %t\n  !=\n  %t\n", q->pending, ev);
  */
  return TBfalse;
}
