SUBDIRS=offside asfix utils
EXTRA_DIST=meta.conf

noinst_DATA = OffSide.eqs
data_DATA = OffSide.trm.tbl

%.trm.tbl:
	${META}/bin/pt-dump -m $*
	mv */$@ $@

%.eqs:
	${META}/bin/eqs-dump -m $*


