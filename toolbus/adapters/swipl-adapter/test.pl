

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
