SUBDIRS=offside asfix utils
EXTRA_DIST=meta.conf $(wildcard *.eqs) $(wildcard *.tbl)

%.trm.tbl:
	cd ${srcdir} ; \
	${META}/bin/pt-dump -m $* -C ${srcdir}/meta.conf -o $@ 

%.eqs:
	cd ${srcdir} ; \
	${META}/bin/eqs-dump -m $* -C ${srcdir}/meta.conf -o $@


