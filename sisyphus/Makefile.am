
include $(top_srcdir)/Makefile.top.meta

SUBDIRS = src sql script www demo doc gems

ACLOCAL_AMFLAGS = -I .

gems = \
	activesupport-1.4.2 \
	activerecord-1.15.3 \
	actionpack-1.13.3 \
	actionmailer-1.3.3 \
	actionwebservice-1.2.3 \
	rake-0.7.2 \
	rails-1.2.3 \
	postgres-pr-0.4.0 \
	daemons-1.0.5 \
	fastthread-0.6.4.1 \
	cgi_multipart_eof_fix-2.1 \
	gem_plugin-0.2.2 \
	mongrel-1.0.1 \
	sqlite3-ruby-1.2.1



GEM_DIR = $(top_srcdir)/gems

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
			${GEM_DIR}/$$g.gem ; \
	done)

uninstall-hook:
	install_dir=`echo ${DESTDIR}/${pkgdatadir} | tr -s /` ; \
	rm -rf $$install_dir


#.PHONY: doc
#doc:
#	(cd src && $(MAKE) $(AM_MAKE_FLAGS) doc)
