
EXTRA_DIST	= sisyphus.sql

sql_DATA	= sisyphus.postgresql

sqldir		= $(pkgdatadir)/sql

CLEANFILES 	= sisyphus.postgresql

%.postgresql : %.sql
	cat $< > $@



