
import TB
import sys

from Tkinter import *

def doit(A,B):
	print "doit: ", A, ", ", B

def evalit(B):
	print "evalit: ", B
	return "snd-value(evalit(uvw))"

def rec_terminate(A):
	print "rec-terminate: ", A
	sys.exit(0)

print "Arguments: ", TB.argv

class Application(Frame):
	def say_hi(self):
		print "Hello everybody!"

	def createWidgets(self):
		self.QUIT = Button(self)
		self.QUIT["text"]	= "Quit"
		self.QUIT["fg"]		= "red"
		self.QUIT["command"]	= self.quit
		self.QUIT.pack({"side" : "left"})

		self.hi_there = Button(self)
		self.hi_there["text"]	= "hi there!"
		self.hi_there["command"] = self.say_hi
		self.hi_there.pack({"side" : "left"})

	def __init__(self, master = None):
		Frame.__init__(self, master)
		self.pack()
		self.createWidgets()

def startup():
	App = Application()	

TB.enable_tk()
startup()

