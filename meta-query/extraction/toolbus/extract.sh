sglr -p Tscript.trm.tbl -i refactor.trm | addPosInfo -p refactor.trm | ./ExtractAll -f extractAll -r RSTORE -i - | unparsePT > refactor.rstore 
