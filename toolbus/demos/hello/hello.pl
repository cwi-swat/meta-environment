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

rec_terminate(_,_) :- halt.

get_text(Result,_) :-
  Result = get_text('Hello World, my first ToolBus tool in SWI-Prolog!\n').

toolbus :-	tb_tool(Tool), tb_host(Host), tb_port(Port), tb_tid(Tid),
		tb_new_connection(Tool, Host, Port, Tid, Cid),
		tb_connect(Cid), tb_eventloop.

