
import string
TermParseError	= "TermParseError"
SyntaxError	= "LexicalSyntaxError"
CCstart_appl	= string.lowercase
CCappl		= string.letters + string.digits + '-' + '_'
CCstart_var	= string.uppercase
CCvar		= CCappl
CCstart_int	= string.digits + '-'
CCint		= string.digits

def parse(Str):
	global S, i

	S = Str+"$"
	i = 0
	l = len(S)
	Stack = []
	while S[i] != '$':
		(Token, Word, Skip) = lex(S, i)
		#print "lex(%s,%d) = " % (S,i), (Token, Word, Skip), \
			#	"stack = ", Stack
		i = i + Skip
		if Token == 'appl':
			Stack.append(['appl', Word, []])
		if Token == 'int':
			Stack.append(['int', Word])
		elif Token == 'var':
			Stack.append(['var', Word, 'value', []])
		elif Token == 'push':
			Stack.append(Word)
		elif Token == ')':
			drop_application(Stack)
		elif Token == ']':
			drop_list(Stack)
		elif Token == '>':
			drop_placeholder(Stack)
		elif Token == '?':
			drop_result_var(Stack)
		elif Token == 'str':
			Stack.append(['str', Word])
		elif Token == 'bstr':
			Stack.append(['bstr', Word])
		elif Token == 'bool':
			Stack.append(['bool', Word])

	if len(Stack) > 1:
		raise TermParseError, "unexpected end of string %s" % S

	return Stack[0]
def drop_application(Stack):
	Args = []
	# print 'dropping application from: ', Stack
	# First, get the list of arguments
	El = Stack[-1]
	Stack[-1:] = []
	if El != '(':
		Args.insert(0, El)
		while Stack[-1] == ',':
			El = Stack[-2]
			Stack[-2:] = []
			Args.insert(0, El)
		El = Stack[-1]
		Stack[-1:] = []
	if El != '(':
		raise TermParseError, "( expected: %s - %s" % \
						(str(Stack), Str[i:])
	El = Stack[-1]
	if len(El) != 3 or El[0] != 'appl':
		raise TermParseError, "function symbol expected: %s - %s" % \
						(str(Stack), Str[i:])
	Stack[-1][2] = Args
def drop_list(Stack):
	Elems = []
	# print 'dropping list from: ', Stack
	# Get all the elements of the stack
	El = Stack[-1]
	Stack[-1:] = []
	if El != '[':
		Args.insert(0, El)
		while Stack[-1] == ',':
			El = Stack[-2]
			Stack[-2:] = []
			Elems.insert(0, El)
		El = Stack[-1]
		Stack[-1:] = []
	if El != '[':
		raise TermParseError, "[ expected: %s - %s" % \
						(str(Stack), Str[i:])
	Stack.append(['list', Elems])

