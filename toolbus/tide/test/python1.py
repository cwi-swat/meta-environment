
import TB
import sys
import __main__

def rec_terminate(cid, A):
	sys.exit(0)

def testing(cid, C):
	print "testing called: %d" % C

cid = TB.parseArgs(sys.argv, __main__)
TB.connect(cid)

# Enable debugging.
dbcid = TB.newConnection("debug-nub", None, 9500, __main__)
TB.enableDebugging(dbcid)

TB.eventloop()
