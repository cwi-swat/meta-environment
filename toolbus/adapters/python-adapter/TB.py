
# -------------------------------------------------------------------------
# TB.py -- Python adapter library functions. Most of these functions are
#          based on the library code included with the first Python adapter
#          written by Leon Moonen.
#
# Author:       Pieter Olivier
# Date:         Wed Feb  7 15:57:26 MET 1996
# 
# Revised and nowebbed on:	Mon Mar  4 15:05:18 MET 1996
#
# --------------------------------------------------------------------------

import sys
import regsub
import regex
import select
import socket
import string
import regsub
import __main__
import tkinter
import Tkinter
 
connect = "TB-connect"		# ToolBus connection fails
illterm = "IllegalTerm"		# An illegal term was encountered
illsign = "IllegalSignature"	# Signature format was not legal

def TBstring(str):
        newstr = regsub.gsub('\"','\\\"',str)
        return('\"%s\"' % newstr)
def PYstring(str):
        comp = regex.compile('\"[0-9]+:\(.*\)\"')
        if (comp.match(str) != -1):
                return(comp.group(1))
        else:
                comp = regex.compile('\"\(.*\)\"')
                if (comp.match(str) != -1):
                        return(comp.group(1))
                else:
                        return(str)
# The following function depends on
# LENSPEC = 8 and MIN_MSG_SIZE = 128 (see utils.[ch])
# THIS SHOULD BE PARAMETERIZED !!!

def send(msg):
        length = len(msg) + 8
        msg = '%.7d:' % length + msg
        output.send('%-128s' % msg)
def msg(message):
        sys.stderr.write('%s - %s\n' % (TOOL_NAME, message))
        sys.stderr.flush()
def error(msg):
        send('python-adapter-error(%s)' % TBstring(msg))
def event(msg):
        send('snd-event(%s)' % msg)
def enable_tk():
        global use_tk
        use_tk = 1


def read_term(sock):
        global connected, use_tk, input
        try:
                buf = mread(sock, 128)
                len = string.atoi(buf[0:7])
                # msg("read_term: len = %d" % len)
                if len > 128:
                        extra = mread(sock, len - 128)
                        buf = buf + extra
                return buf[8:len]
        except:
                connected = 0
                if use_tk:
                        tkinter.deletefilehandler(input)
                raise "TBconnect"
        return ""

def mread(sock, size):
        count = 0
        buf = ""
        # msg("mread - start (size = %d)" % size)
        while len(buf) < size:
                # msg("mread - buf = %s, size = %d\n" % (buf, size))
                data = sock.recv(size-count)
                if not data: break
                buf = buf + data
        if len(buf) < size:
                msg("error while reading from socket")
                sys.exit(1)
        return buf

def register(mod, fun, args, result):
        global functions

        fun = regsub.gsub("-", "_", fun)
        #print "register: %s,%s,%s - " % (mod, fun, result), args

        if functions.has_key(fun):
                (mod2, fun2, singletons, args2, result2) = functions[fun]
                # <PO>: We might want some more consistency checks here!
                        # Possible candidates (at first glance):
                        # - mod == mod2
                        # - result compatible with result2 (or go to <term>)
                        # - check if arguments are still singletons
                # For now, the args part of a function is the
                # args part of the last time the function was registered!
                function = (mod, fun, singleton, args, result)
        else:
                singletons = []
                for arg in args:
                        if is_singleton(arg):
                                singletons.append(1)
                        else:
                                singletons.append(0)
                function = (mod, fun, singletons, args, result)
 
        functions[fun] = function

        #print "functions = ", functions

def is_singleton(args):
        if args[0] == 'placeholder':
                type = args[1][1]
                if type == 'int' or type == 'str' or type == 'bool' \
                                or type == 'real':
                        return 1
        if args[0] == 'appl' and args[2] == []:
                return 1
        return 0


def init(argvec):
        global TOOL_NAME, TOOL_ID, HOST, INPORT, OUTPORT
        global LOCAL_HOST, LIB, parser, module, argv
        global use_tk, in_shutdown, connected, functions
        global files

        # Fill in some default values
        use_tk = 0
        in_shutdown = 0
        functions = { }
        files = [ ]
        connected = 0

        # Determine local host and use this when no -TB_HOST option was present
        LOCAL_HOST = socket.gethostname()
        HOST = LOCAL_HOST
        INPORT = 8998
        OUTPORT = 8999

        # Interpret options
        # print "argvec = ", argvec
        argv = [argvec[0]]
        l = argvec[1:]
        while l:
                if l[0] == "-script":
                        idx = string.rfind(l[1],".")
                        if idx > 0:
                                module = l[1][:idx]
                        else:
                                module = l[1]
                        l = l[2:]
                elif l[0] == "-module":
                        module = l[1]
                        l = l[2:]
                elif l[0] == "-TB_LIB":
                        LIB = l[1]
                        l = l[2:]
                elif l[0] == "-TB_TOOL_NAME":
                        TOOL_NAME = l[1]
                        l = l[2:]
                elif l[0] == "-TB_TOOL_ID":
                        TOOL_ID = string.atoi(l[1])
                        l = l[2:]
                elif l[0] == "-TB_HOST":
                        HOST = l[1]
                        l = l[2:]
                elif l[0] == "-TB_INPORT":
                        INPORT = string.atoi(l[1])
                        l = l[2:]
                elif l[0] == "-TB_OUTPORT":
                        OUTPORT = string.atoi(l[1])
                        l = l[2:]
                elif l[0][0:8] == "-details":
                        l = l[1:]
                elif l[0] == "-script-args" or l[0] == "-args":
                        argv[1:1] = l[1:]
                        l = []
                else:
                        sys.stderr.write("python-adapter: " \
                                "unrecognized option %s" % l[0])
                        l = l[1:]

        # Print some debugging output:
        # print "MODULE         = ", module
        # print "LIB            = ", LIB
        # print "TOOL_NAME      = ", TOOL_NAME
        # print "TOOL_ID                = ", TOOL_ID
        # print "HOST           = ", HOST
        # print "LOCAL_HOST     = ", LOCAL_HOST
        # print "INPORT         = ", INPORT
        # print "OUTPORT                = ", OUTPORT
        # print "argv           = ", argv 

tool_name = sys.argv[0]
 
