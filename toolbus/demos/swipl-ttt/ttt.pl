match(circle, circle, circle).
match(cross , cross , cross ).

won([X1,X2,X3,_,_,_,_,_,_],[1,2,3]) :- match(X1, X2, X3).
won([_,_,_,X4,X5,X6,_,_,_],[4,5,6]) :- match(X4, X5, X6).
won([_,_,_,_,_,_,X7,X8,X9],[7,8,9]) :- match(X7, X8, X9).
won([X1,_,_,X4,_,_,X7,_,_],[1,4,7]) :- match(X1, X4, X7).
won([_,X2,_,_,X5,_,_,X8,_],[2,5,8]) :- match(X2, X5, X8).
won([_,_,X3,_,_,X6,_,_,X9],[3,6,9]) :- match(X3, X6, X9).
won([X1,_,_,_,X5,_,_,_,X9],[1,5,9]) :- match(X1, X5, X9).
won([_,_,X3,_,X5,_,X7,_,_],[3,5,7]) :- match(X3, X5, X7).

toolbus :- tb_tool(Tool), tb_host(Host), tb_port(Port), tb_tid(Tid),
           tb_new_connection(Tool, Host, Port, Tid, Cid),
           tb_connect(Cid), tb_eventloop.
