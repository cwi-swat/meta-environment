# include $(top_srcdir)/make_rules

pkgdata_DATA    = JavaAnalysis.eqs

EXTRA_DIST      = \
	$(wildcard *.sdf) \
	$(wildcard *.asf) \
	$(wildcard *.tbl) \
	$(wildcard *.eqs) \
	meta.buttons \
	meta.conf

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


