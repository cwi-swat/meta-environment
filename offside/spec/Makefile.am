SUBDIRS=offside asfix utils
EXTRA_DIST=meta.conf

noinst_DATA = Offside.eqs
data_DATA = OffSide.trm.tbl

%.trm.tbl:
	pt-dump -m $*
	mv */$@ $@

%.eqs:
	eqs-dump -m $*


