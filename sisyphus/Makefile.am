
SUBDIRS = src script doc

ACLOCAL_FLAGS = -I .

CLEANFILES = ${PACKAGE}-${VERSION}.pkg

EXTRA_DIST = reconf package

noinst_SCRIPTS = ${PACKAGE}-${VERSION}.pkg

${PACKAGE}-${VERSION}.pkg: package Makefile
	cp $< $@


gems		= activerecord-1.13.2 activesupport-1.2.5 postgres-pr-0.4.0

install-data-hook: 
	(RUBYLIB=${RUBYGEMS}/lib/ruby/site_ruby/1.8:${RUBY}/lib/ruby/site_ruby/1.8 ;\
	export RUBYLIB ; \
	PATH=${RUBYGEMS}/bin:${RUBY}/bin:/bin:/usr/bin ; \
	export PATH ; \
	install_dir=`echo ${DESTDIR}/${pkgdatadir} | tr -s /` ; \
	for g in $(gems) ; do \
		name=`echo $$g | sed -e 's/\(.*\)-\(.*\)/\1/'` ; \
		version=`echo $$g | sed -e 's/\(.*\)-\(.*\)/\2/'` ; \
		${RUBYGEMS}/bin/gem install \
			--remote \
			--no-rdoc \
			--install-dir $$install_dir \
			--include-dependencies \
			--version $$version $$name ; \
	done)

uninstall-hook:
	install_dir=`echo ${DESTDIR}/${pkgdatadir} | tr -s /` ; \
	rm -rf $$install_dir


