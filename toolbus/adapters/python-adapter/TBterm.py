
import string
TermParseError	= "TermParseError"
SyntaxError	= "LexicalSyntaxError"
CCstart_appl	= string.lowercase
CCappl		= string.letters + string.digits + '-' + '_'
CCstart_var	= string.uppercase
CCvar		= CCappl
CCstart_int	= string.digits + '-'
CCint		= string.digits
CCreal		= CCint + '.E' + '-'

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
		elif Token == 'real':
			Stack.append(['real', Word])

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
		Elems.insert(0, El)
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
def drop_placeholder(Stack):
	T = Stack[-1]
	left = Stack[-2]
	Stack[-2:] = []
	if left != '<':
		raise TermParseError, "< expected: %s - %s" % \
						(str(Stack), str[i:])
	# <PO>: We might want to check if it is a valid term 
	# before placing a 'placeholder' around it!
	Stack.append(['placeholder', T])
def drop_result_var(Stack):
	V = Stack[-1]
	if len(V) != 4 or V[0] != 'var':
		raise TermParseError, "? can only follow a variable: %s - %s"\
						(str(Stack), str[i:])
	Stack[-1][2] = 'result'
def lex(S, i):
	start = i
	while S[i] in string.whitespace:
		i = i + 1
	if S[i] in CCstart_int:
		j = i
		while S[j] in CCint:
			j = j + 1
		if S[j] in CCreal:
			while S[j] in CCreal:
				j = j + 1
			return ('real', string.atof(S[i:j]), j-start)
		else:				
			return ('int', string.atoi(S[i:j]), j-start)
        if S[i:i+4] == 'true' and S[i+4] not in CCappl:
                return ('bool', 'true', i+4-start)
        if S[i:i+5] == 'false' and S[i+5] not in CCappl:
                return ('bool', 'false', i+5-start)
	if S[i] in CCstart_appl:
		j = i
		while S[j] in CCappl:
			j = j + 1
		return ('appl', S[i:j], j-start)
	if S[i] == '"':
		if S[i+1] == '\377':
			# Binary string
			return scan_bstring(S[i:], i-start+1)
		else:
			# Normal string
			return scan_string(S[i:], i-start)
	if S[i] in ",([<":
		return ('push', S[i], i-start+1)
	if S[i] in ")]>?":
		return (S[i], S[i], i-start+1)
	if S[i] in CCstart_var:
		j = i
		while S[j] in CCvar:
			j = j + 1
		return ('var', S[i:j], j-start)
def scan_string(str, xtra):
        state = 0
        result = ""
        len = 0
        for c in str:
                len = len + 1
                if state == 1:
                        if c == '"':
                                return ('str', result, len+xtra)
                        elif c == '\\':
                                state = 2
                                continue
                        else:
                                result = result + c
                if state == 2:
                        if c == '"':
                                result = result + c
                        elif c == '\\':
                                result = result + '\\'
                        else:
                                result = result + '\\' + c
                        state = 1
                if state == 0:
                        state = 1
        raise SyntaxError, "Lexical parse failure in string: %s" % str
def scan_bstring(str, xtra):
        len = string.atoi(str[2:8])
        return ('bstr', str[9:len], len+xtra)

def test_parser(str):
        R = parse(str)
        print "Parsing '%s' results in: " % str, R
def test_it():
        test_parser("abc")
        test_parser("justTesting")
        test_parser("xyz(abc)")
	test_parser("xyz(abc,def)")
	test_parser("true")
	test_parser("false")
	test_parser("xyz(abc, true)")
	test_parser("def(true, false)")
	test_parser("Abc")
	test_parser("f(A, true, B)")
	test_parser('"abc"')
	test_parser('"\377000023\377Binary String!"')
	test_parser("Var?")
	test_parser('f(true, Var ?, "abc")')
	test_parser("<123>")
	test_parser("f(<term>,true, V?)")
	test_parser("[]")
	test_parser("[a]")
	test_parser("[a,b,c]")
	test_parser('["abc", true, 356]')
	test_parser("234.56E-5")
def bench_it(count):
        start = time.time()
        print 'start timing at: ', start
        for i in range(1,count):
                DoParse('abc(1,def)')
        end = time.time()
        print 'end timing at: ', end
        print 'difference: ', end-start
def bench_it2(count):
        start = time.time()
        print 'start timing at: ', start
        for i in range(1,count):
                DoParse('abc(1,def)')
        	DoParse("abc")
        	DoParse("justTesting")
        	DoParse("xyz(abc)")
		DoParse("xyz(abc,def,3456,123)")
		DoParse("true")
		DoParse("false")
		DoParse("xyz(abc, true)")
		DoParse("def(true, false)")
		DoParse("Abc")
		DoParse("f(A, true, B)")
		DoParse('"abc"')
		DoParse('"\377000023\377Binary String!"')
		DoParse("Var?")
		DoParse('f(true, Var ?, "abc")')
		DoParse("<123>")
		DoParse("f(<term>,true, V?)")
        end = time.time()
        print 'end timing at: ', end
        print 'difference: ', end-start
def doprof():
	import profile

	profile.run("bench_it(1000)", "bench_it")
	profile.run("bench_it2(100)", "bench_it2")

	import pstats

	b1 = pstats.Stats("bench_it")
	b2 = pstats.Stats("bench_it2")

	b1.strip_dirs()
	b1.sort_stats("cumulative")
	b1.print_stats(10)

	print "\n\n"

	b2.strip_dirs()
	b2.sort_stats("cumulative")
	b2.print_stats(10)

test_it()
# bench_it(5000)
# bench_it2(600)
