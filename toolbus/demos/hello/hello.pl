
rec_terminate(_,_) :- halt.

get_text(_, 'Hello World, my first ToolBus tool in SWI-Prolog!\n').

toolbus :-	tb_tool(Tool), tb_host(Host), tb_port(Port), tb_tid(Tid),
		tb_new_connection(Tool, Host, Port, Tid, Cid),
		tb_connect(Cid), tb_eventloop.

