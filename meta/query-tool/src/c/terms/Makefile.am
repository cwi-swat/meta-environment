term: Bool.sdf.pt boollist.pt boolseplist.pt booland.pt boolor.pt id.pt

TERM_FILES = $(wildcard *.pt *.trm.tbl)

term-clean:
	rm -f $(TERM_FILES)

%.sdf.pt: %.sdf
	sglr -p $(PGEN)/share/pgen/Sdf2.baf -i $< \
	| addPosInfo -p Test -o $@

%.trm.tbl: %.sdf
	pt-dump -m `basename $< .sdf`

boollist.pt: Bool.trm.tbl boollist.trm
	sglr -p Bool.trm.tbl -i boollist.trm -o boollist.pt

boolseplist.pt: Bool.trm.tbl boolseplist.trm
	sglr -p Bool.trm.tbl -i boolseplist.trm -o boolseplist.pt

booland.pt: Bool.trm.tbl booland.trm
	sglr -p Bool.trm.tbl -i booland.trm -o booland.pt

boolor.pt: Bool.trm.tbl boolor.trm
	sglr -p Bool.trm.tbl -i boolor.trm -o boolor.pt

id.pt: Bool.trm.tbl id.trm
	sglr -p Bool.trm.tbl -i id.trm -o id.pt
