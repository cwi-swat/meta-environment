
FST = ../../bin/fst

INSTALL_DIR = ../../grammars

.PHONY: all
.PHONY: install

all:
	@echo "Choose which grammar to make:"
	@echo "  - make VS-COBOL-II-REF.sdf"
	@echo "  - make VS-COBOL-II-DA.sdf"
	@echo "  - make VS-COBOL-II-FLAT.sdf"

install: ref.sdf da.sdf flat.sdf VS-COBOL-II-RAW.sdf VS-COBOL-II-REF.sdf VS-COBOL-II-DA.sdf VS-COBOL-II-FLAT.sdf
	cp ref.sdf $(INSTALL_DIR)
	cp da.sdf $(INSTALL_DIR)
	cp flat.sdf $(INSTALL_DIR)
	cp VS-COBOL-II-RAW.sdf $(INSTALL_DIR)
	cp VS-COBOL-II-REF.sdf $(INSTALL_DIR)
	cp VS-COBOL-II-DA.sdf $(INSTALL_DIR)
	cp VS-COBOL-II-FLAT.sdf $(INSTALL_DIR)

VS-COBOL-II-REF.sdf: ref.sdf
	$(FST) \
	Lexicals.trafo \
	Layout.trafo \
	MainREF.trafo \
	Linebreaks-removal.trafo \
	< $< > $@

VS-COBOL-II-DA.sdf: da.sdf
	$(FST) \
	Lexicals.trafo \
	Layout.trafo \
	MainDA.trafo \
	Linebreaks-removal.trafo \
	< $< > $@

VS-COBOL-II-FLAT.sdf: flat.sdf
	$(FST) \
	Lexicals.trafo \
	Layout.trafo \
	MainDA.trafo \
	Linebreaks-removal.trafo \
	< $< > $@

ref.sdf: VS-COBOL-II-RAW.sdf
	$(FST) \
	Preparation.trafo \
	Identification-division.trafo \
	Environment-division.trafo \
	Configuration-section.trafo \
	Input-output-section.trafo \
	Data-division.trafo \
	Data-description-entry.trafo \
	File-and-sort-description-entry.trafo \
	Procedure-division.trafo \
	Statements.trafo \
	Arithmetic-expressions.trafo \
	Conditions.trafo \
	Data-reference.trafo \
	Names.trafo \
	Modularisation.trafo \
	< $< > $@

da.sdf: ref.sdf
	$(FST) \
	Generalisation.trafo \
	DA-data-reference.trafo \
	DA-conditions.trafo \
	DA-statements.trafo \
	DA-misc.trafo \
	Depermutation.trafo \
	< $< > $@

flat.sdf: da.sdf
	$(FST) \
	Flattening.trafo \
	< $< > $@

test: da.sdf
	$(FST) \
	Test.trafo \
	< $< > test.sdf

cleanish:
	rm -f \
	ref.sdf \
	da.sdf \
	flat.sdf

# NOTE: the *~ is for getting rid of Emacs temporaries.
clean:
	rm -f \
	ref.sdf \
	da.sdf \
	flat.sdf \
	VS-COBOL-II-REF.sdf \
	VS-COBOL-II-DA.sdf \
	VS-COBOL-II-FLAT.sdf \
	temp.tmp \
	*.tbl \
	*~

