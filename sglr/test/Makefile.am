# $Id$

SUBDIRS    = erroneous first grammars tables terms

EXTRA_DIST = lang-types regress-lang regress-terms trmdiff trmdiff.in

TESTS      = regress-terms regress-lang

regress-lang regress-terms: dummy
	@chmod +x $@

dummy:
