SUBDIRS=offside asfix utils
EXTRA_DIST=meta.conf $(wildcard *.eqs) $(wildcard *.tbl)

pkgdata_DATA = $(wildcard *.tbl)

%.trm.tbl:
	cd ${srcdir} ; \
	${ASF}/bin/pt-dump -m $* -C ${srcdir}/meta.conf -o $@ 

%.eqs:
	cd ${srcdir} ; \
	${ASF}/bin/eqs-dump -m $* -C ${srcdir}/meta.conf -o $@


