# include $(top_srcdir)/make_rules

bin_SCRIPTS = extract-java

SOURCES = $(wildcard *.sh.src)
CLEANFILES=extract-java

pkgdata_DATA    = JavaAnalysis.eqs

EXTRA_DIST      = \
	$(wildcard *.sdf) \
	$(wildcard *.asf) \
	$(wildcard *.tbl) \
	$(wildcard *.eqs) \
	meta.buttons \
	meta.conf

% : %.sh.src Makefile
	sed 's@__PREFIX__@$(prefix)@g;\
	     s@__BINDIR__@$(bindir)@g;\
	     s@__DATADIR__@$(pkgdatadir)@g;\
	     s@__VERSION__@$(VERSION)@g;' < $< > $@ && \
	chmod +x $@

# ---- General Make rules

# ---- Generate term parse table from SDF module

%.trm.tbl:: %.sdf
	pt-dump -m $(*F) -o $@

# ---- Convert from .asf to .eqs

%.eqs :: %.asf
	eqs-dump -m $(*F) -o $@

# ---- Convert from .eqs to .c

%.c:: %.asf
	eqs-dump -m $(*F) -o $(*F).eqs
	asfc -i $(*F).eqs -o $(*F) -v


