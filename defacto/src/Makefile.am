EXTRA_DIST = SortsToIds.trm.tbl SortsToIds.eqs

pkgdata_DATA = SortsToIds.trm.tbl SortsToIds.eqs

dump_tbl : 
	pt-dump -m SortsToIds -o SortsToIds.trm.tbl

dump_eqs : 
	eqs-dump -m DeFacto -o DeFacto.eqs
	eqs-dump -m SortsToIds -o SortsToIds.eqs
