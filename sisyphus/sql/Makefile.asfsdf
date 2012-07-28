

HOST=sjofar.sen.cwi.nl
USER=sisyphusdev
DB=sisyphusdev
PSQL=psql
SGLR=sglr
PT_DUMP=pt-dump
EQS_DUMP=eqs-dump
APPLY_FUNCTION=apply-function
ASFE=asfe
ASFC=asfc
UNPARSEPT=unparsePT
PANDORA=pandora
RSCRIPT=rscript

DUMP_PARSER=PSQL-Output.trm.tbl
DUMP_TO_RSTORE_EQS=PSQL-to-RStore.eqs
DUMP_TO_RSTORE=PSQL-to-RStore
DUMP_TO_RSTORE_BIN=PSQL-to-RStore.bin
DUMP_TO_RSTORE_C=PSQL-to-RStore.c
FUNCTION=psql-to-rstore
RESULT_SORT=RSTORE
SANITIZE=sanitize.rscript

GRAMMARS=$(wildcard *.sdf)

.PRECIOUS: $(DUMP_TO_RSTORE) $(DUMP_TO_RSTORE_EQS) $(DUMP_PARSER) $(DUMP_TO_RSTORE_C) %.dump.pt %.rstore.pt %.dump.trafo.pt %.rstore.pp.pt %.dump %.rstore.sanitized.pt

all: relations.rstore

%.trm.tbl: %.sdf $(GRAMMARS)
	$(PT_DUMP) -m $*

%.eqs: %.sdf %.asf $(GRAMMARS)
	$(EQS_DUMP) -m $*

% : %.eqs
	$(ASFC) -c -i $< -o $*.c

%.dump: %.sql
	$(PSQL) -h $(HOST) -U $(USER) $(DB) --quiet < $< > $@

%.dump.pt: %.dump $(DUMP_PARSER)
	$(SGLR) -p $(DUMP_PARSER) -v -i $< -o $@

%.dump.trafo.pt: %.dump.pt
	$(APPLY_FUNCTION) -f $(FUNCTION) -s $(RESULT_SORT) -i $< -o $@

%.rstore.pt: %.dump.trafo.pt $(DUMP_TO_RSTORE)
	$(DUMP_TO_RSTORE) -i $< -o $@

%.rstore.sanitized.pt: %.rstore.pt
	$(RSCRIPT) -i $(SANITIZE) -s $< -o $@

%.rstore: %.rstore.sanitized.pt
	$(UNPARSEPT) -i $< -o $@

clean:
	rm -rf *.pt *.dump *.rstore *.eqs *.c *.pt.pos *.trm.tbl *.checker.feedback
