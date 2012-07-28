#
#    ToolBus -- The ToolBus Application Architecture
#    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
#                             The  Netherlands.
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#


abc(a).
abc(b).
abc(c).

xyz(abc(a),abc(c)).

just_a_test(Result, CID) :- Result = jat('Hello world!'),
	 print('just_a_test: '), print(CID), print('\n').
rec_terminate(CID,X) :- print(CID), print('\n'), print(X), print('\n'), halt.

gen_event(CID, Ev) :- print(['sending event: ',Ev,'\n']), tb_send(CID, snd_event(evt(Ev))).

rec_ack_event(_, X) :- print('rec-ack-event: '), print(X), print('\n').

run :-  tb_tool(Tool),
	tb_host(Host),
	tb_port(Port),
	tb_tid(Tid),
	tb_new_connection(Tool,Host,Port,Tid,Cid),
	tb_connect(Cid),
	tb_eventloop.
