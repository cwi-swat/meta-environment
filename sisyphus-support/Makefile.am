
include $(top_srcdir)/Makefile.top.meta

SUBDIRS = src schemas script

ACLOCAL_AMFLAGS = -I .

gems = activerecord-1.13.2 activesupport-1.2.5 postgres-pr-0.4.0

install-data-hook: 
	(RUBYLIB=${RUBYGEMS_PREFIX}/lib/ruby/site_ruby/1.8:${RUBY_PREFIX}/lib/ruby/site_ruby/1.8 ;\
	export RUBYLIB ; \
	PATH=${RUBYGEMS_PREFIX}/bin:${RUBY_PREFIX}/bin:/bin:/usr/bin ; \
	export PATH ; \
	install_dir=`echo ${DESTDIR}/${pkgdatadir} | tr -s /` ; \
	for g in $(gems) ; do \
		name=`echo $$g | sed -e 's/\(.*\)-\(.*\)/\1/'` ; \
		version=`echo $$g | sed -e 's/\(.*\)-\(.*\)/\2/'` ; \
		${RUBYGEMS_PREFIX}/bin/gem install \
			--remote \
			--no-rdoc \
			--install-dir $$install_dir \
			--include-dependencies \
			--version $$version $$name ; \
	done)

uninstall-hook:
	install_dir=`echo ${DESTDIR}/${pkgdatadir} | tr -s /` ; \
	rm -rf $$install_dir

if MAINTAINER_MODE

.PHONY: doc

doc:
	(cd src; make doc)

endif



