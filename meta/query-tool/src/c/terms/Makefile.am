terms: Bool.sdf.pt boollist.pt boolseplist.pt booland.pt boolor.pt

SDF2TABLE = $(PGEN)/bin/sdf2table

%.sdf.pt: %.sdf
	sglr -p $(PGEN)/share/pgen/Sdf2.baf -i $< \
	| addPosInfo -p Test -o $@

%.trm.tbl: %.sdf
	$(SDF2TABLE) -i $< -o $@

boollist.pt: Bool.trm.tbl boollist.trm
	sglr -p Bool.trm.tbl -i boollist.trm -o boollist.pt

boolseplist.pt: Bool.trm.tbl boolseplist.trm
	sglr -p Bool.trm.tbl -i boolseplist.trm -o boolseplist.pt

booland.pt: Bool.trm.tbl booland.trm
	sglr -p Bool.trm.tbl -i booland.trm -o booland.pt

boolor.pt: Bool.trm.tbl boolor.trm
	sglr -p Bool.trm.tbl -i boolor.trm -o boolor.pt

CLEANFILES = $(wildcard *.pt *.trm.tbl)
