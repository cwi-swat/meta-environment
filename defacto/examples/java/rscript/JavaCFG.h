
%%%%%% CFGJava.h
%%%%%% Extracted facts

set[node] METHOD

rel[node, node] METHOD-BODY %% rel METHOD -> STATEMENT
rel[node, node] CF-IN       %% rel STATEMENT -> STATEMENT
rel[node, node] CF-OUT      %% rel STATEMENT -> STATEMENT
rel[node, node] CF-NEXT     %% rel STATEMENT -> final STATEMENT

%% TODO these can be accessed from Sort
set[node] RETURN
set[node] BREAK
set[node] CONTINUE

rel[node, node] BREAK-LABEL
rel[node, node] CONTINUE-LABEL
rel[node, node] LABEL       %% rel STATEMENT -> LABEL
rel[node, node] LOOP        %% rel LOOP(BLOCK) -> CONT

rel[node, node] TRY-CATCH
rel[node, node] TRY-FINALLY
rel[node, node] CATCH
rel[node, node] THROW

