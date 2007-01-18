
include $(top_srcdir)/Makefile.top.meta

SUBDIRS = src script doc

ACLOCAL_AMFLAGS = -I .

gems = activerecord-1.13.2 activesupport-1.2.5 postgres-pr-0.4.0

GEM_DIR := $(shell pwd)/gems

install-data-hook: 
	(RUBYLIB=${RUBYGEMS_PREFIX}/lib/ruby/site_ruby/1.8:${RUBY_PREFIX}/lib/ruby/site_ruby/1.8 ;\
	export RUBYLIB ; \
	PATH=${RUBYGEMS_PREFIX}/bin:${RUBY_PREFIX}/bin:/bin:/usr/bin ; \
	export PATH ; \
	install_dir=`echo ${DESTDIR}/${pkgdatadir} | tr -s /` ; \
	for g in $(gems) ; do \
		${RUBYGEMS_PREFIX}/bin/gem install \
			--no-rdoc \
			--install-dir $$install_dir \
			--include-dependencies \
			${GEM_DIR}/$(g) ; \
	done)

uninstall-hook:
	install_dir=`echo ${DESTDIR}/${pkgdatadir} | tr -s /` ; \
	rm -rf $$install_dir


#.PHONY: doc
#doc:
#	(cd src && $(MAKE) $(AM_MAKE_FLAGS) doc)
