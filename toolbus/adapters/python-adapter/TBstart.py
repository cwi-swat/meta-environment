
import string
import regsub
import traceback
import regex
import posix
import select
import sys
import time
import select
import socket
import tkinter
import Tkinter
import __main__

import TB 
import TBterm
def init():
	# Find the well-known ToolBus sockets:
        sock_out = connectsocket(TB.HOST, TB.INPORT)
        send_handshake(sock_out, "%s %s %d" %
                                (TB.TOOL_NAME, TB.HOST, TB.TOOL_ID))

        sock_in = sock_out
	# <PO> was: sock_in = connectsocket(TB.HOST, TB.OUTPORT)
        portin = getint(sock_in, TB.TOOL_NAME)
        toolid = getint(sock_in, TB.TOOL_NAME)

	# Check if this went alright
        if portin < 0: raise TB.connect, "Illegal port number: %d" % portin
        if toolid < 0: raise TB.connect, "Illegal tool-id: %d" % toolid

	# The well-known sockets are no longer in use by this tool
        sock_in.close()
        # <PO> was: sock_out.close()

	# The input/output ports are always consecutive
        portout = portin+1

	# Do we want global or local ports (AF_INET or AF_UNIX)
        if not TB.HOST:
                TB.HOST = TB.LOCAL_HOST
        if TB.HOST == TB.LOCAL_HOST:
                TB.output = connectsocket("", portin)
                TB.input = createsocket("", portout)
        else:
                TB.output = connectsocket(TB.HOST, portin)
                TB.input = createsocket(TB.LOCAL_HOST, portout)

	# Handshake with the ToolBus after a connection is established
        putint(TB.output, TB.TOOL_NAME, portin)
        n = getint(TB.input, TB.TOOL_NAME)

        if n != portin: raise TB.connect, "Illegal response from ToolBus"
	
	# Let the {\tt TB} module know we found the ToolBus
        TB.connected = 1

def send_handshake(sock, msg):
	sock.send('%-512s' % msg)
def getint(sock, tool):
        data = TB.mread(sock, 512)
        if not data:
                TB.msg("getint failed")
                raise TB.connect
        r = regex.compile("\([a-zA-Z_-]+\) \([0-9]+\)")
        if r.match(data) <= 0:
                TB.msg("getint got garbled data: %s" % data)
                raise TB.connect
        if r.group(1) != tool:
                TB.msg("getint received illegal tool-name: %s" % r.group(1))
                raise TB.connect
        return string.atoi(r.group(2))
def putint(sock, tool, n):
        send_handshake(sock, "%s %d" % (tool, n))
def connectsocket(host, port):
	if not host:
		sock = connect_UNIX_socket(port)
	else:
		sock = connect_INET_socket(host, port)
	#sock.setsockopt(socket.IPPROTO_TCP, TCP_NODELAY, sock.fileno())
	return sock

# Connect to a unix domain socket.

def connect_UNIX_socket(port):
    attempts = 0
    while attempts < 100:
	fname = "/usr/tmp/%d" % port
	try:
		sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
		# TB.msg("opening AF_UNIX socket: %s" % fname)

		sock.connect(fname)
		TB.files.append(fname);
	except socket.error, msg:
		# <PO>: socket.error: (2, 'No such file or directory')
		# print "Retry: ", msg
		attempts = attempts + 1
		time.sleep(1)
	else: break
    return sock
# Connect to a internet socket.

def connect_INET_socket(host, port):
    attempts = 0
    while attempts < 100:
	try:
		sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		adr = (socket.gethostbyname(host), port)
		sock.connect(adr)
	except socket.error, msg:
		attempts = attempts + 1
		time.sleep(1)
	else: break
    return sock
def createsocket(host, port):
        if not host:
                sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
                adr = "/usr/tmp/%d" % port
        else:
                sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                adr = (socket.gethostbyname(host), port)
        # Only use SO_REUSEPORT when present!
        if globals().has_key("SO_REUSEPORT"):
                sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEPORT, 1)
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        # Catch: address already in use
        sock.bind(adr)
        if not host:
                posix.chmod(adr, 0777)
        sock.listen(1)
        pair = sock.accept()
        return pair[0]
def eventloop():
	if TB.use_tk:
		tkinter.createfilehandler(TB.input,
		tkinter.__dict__["READABLE"], tkhandle_term)
		try:
			if TB.root == None:
				Tkinter.Tk().mainloop()
			else:
				TB.root.mainloop()
			TB.send("snd-disconnect")
			TB.connected = 0
		except KeyboardInterrupt:
			sys.exit(0)
		except SystemExit:
			sys.exit(0)
		except:
			if TB.connected:
				TB.msg("Something went wrong in Tk mainloop.")
				traceback.print_exc()
				TB.connected = 0
	else:
		while 1:
			try:
				select.select([TB.input],[],[])
			except select.error, e:
				(n, msg) = e
				TB.connected = 0
				return
			else:
				handle_term()

def tkhandle_term(file, mask):
        handle_term()
def handle_term():
        t = TB.read_term(TB.input)
        if t:
                # Parse the term
                try:
                        T = TBterm.parse(t)
                except:
                        TB.msg("Malformed term %s ignored (%s)" % (t, sys.exc_value))
                else:
                        dispatch_term(T)
def dispatch_term(T):
        if T[0] == 'appl':
                if T[1] == 'rec-do':
                        dispatch_user(T[2][0])
                        TB.send("snd-void()")
                        return
                elif T[1] == 'rec-eval':
                        result = dispatch_user(T[2][0])
                        if result:
                                TB.send(result)
                        else:
                                # <PO>: print warning?
                                TB.send("snd-void()")
                        return
		elif T[1] == 'rec-monitor':
			result = dispatch_user(T[2][0])
			if result:
				TB.send(result)
			else:
				TB.send("snd-void()")
                elif T[1] == 'rec-ack-event':
                        result = dispatch_user(T)
                        return
                elif T[1] == 'rec-terminate':
                        result = dispatch_user(T)
			return

        print "python-adapter: Illegal term received", T
        TB.send("snd-void()")

def dispatch_user(T):
        global A, R

        A = []
        if T[0] == 'appl':
                fun = regsub.gsub("-", "_", T[1])
                if fun == 'signature':
                        check_signature(T[2][0])
                else:
                        (m, f, s, a, r) = TB.functions[fun]
                        # m = module
                        # f = function name
                        # s = which args are singleton
                        # a = argument types
                        # r = result type
                        # print "function = ", (m, f, s, a, r)
                         
			cmd = "R=" + TB.module + "." + fun + "("
                        i = 0
                        A = []
                        for Arg in T[2]:
                                if s[i]:
                                        # Arg is singleton
                                        A.append(Arg[1])
                                else:
                                        A.append(Arg)
                                if i == 0:
                                        cmd = cmd + "A[%d]" % i
                                else:
                                        cmd = cmd + ",A[%d]" % i
                                i = i + 1
                        cmd = cmd + ")"

                        try:
                                exec cmd in globals()
                        except SystemExit, arg:
                                sys.exit(arg)
			except:
				TB.error("error while calling %s in module %s:"\
                                        % (fun, TB.module))
				traceback.print_exc()
                        else:
				return R
	else:
		raise TBillterm, (T, "Term must be an application")



def check_signature(Sig):
        if Sig[0] == 'list':
                for F in Sig[1]:
                        check_sig(F)
        else:
                raise TBillsign, "Malformed signature list: %s" % Sig
def check_sig(F):
        if F[0] == 'appl':
                if F[1] == 'rec-do':
                        TB.register(TB.module, F[2][1][1], F[2][1][2], '')
                        require(TB.module, F[2][1][1], F[2][1][2])
                elif F[1] == 'rec-eval':
                        TB.register(TB.module, F[2][1][1], F[2][1][2], '<term>')
                        require(TB.module, F[2][1][1], F[2][1][2])
                elif F[1] == 'rec-ack-event':
                        TB.register(TB.module, 'rec-ack-event', F[2][1], '')
                        require(TB.module, 'rec-ack-event', F[2][1])
                elif F[1] == 'rec-terminate':
                        TB.register(TB.module, 'rec-terminate', F[2][1], '')
                        require(TB.module, 'rec-terminate', F[2][1])
        else:
                raise TBillsign, "Malformed signature: %s" % F
def require(mod, name, args):
        #print "require: %s,%s,%s", mod, name, str(args)
        name = regsub.gsub("-", "_", name)
        dict = globals()[mod].__dict__
        if not(dict.has_key(name) and callable(dict[name])):
                TB.error("%s: missing function '%s'" % (mod,name))

try:
	TB.init(sys.argv)	# init function of module TB.py
	init()		# init function of module TBstart.py
except socket.error, e:
	(n, msg) = e
	TB.msg("Cannot connect to ToolBus: %s" % msg)
except:
	TB.msg("Something went wrong while initializing module TB.")
	traceback.print_exc()
	sys.exit(1)
try:
        cmd = "import " + TB.module
        exec cmd
except:
        TB.msg("Could not import module %s" % TB.module)
	traceback.print_exc()
	sys.exit(1)

eventloop()

