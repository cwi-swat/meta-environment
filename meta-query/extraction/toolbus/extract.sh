sglr -p Tscript.trm.tbl -i meta-1.6.tb | addPosInfo -p meta-1.6.tb | ./ExtractAll -f extractAll -r RSTORE -i - | unparsePT > meta-1.6.rstore 
