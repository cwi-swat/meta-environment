
import string
import kjParseBuild
import kjParser

# some regular expressions
INTREGEX	= "[+\-]?[0-9]+"
REALREGEX	= "[+\-]?[0-9]+[.][0-9]+[eE][+\-]?[0-9]+" 
BSTRINGREGEX	= '"\377[0-9][0-9][0-9][0-9][0-9][0-9]\377'
STRINGREGEX	= '"[^\377]'
IDREGEX		= "[a-z][A-Za-z0-9\-]*"
VNAMEREGEX	= "[A-Z][A-Za-z0-9\-]*"

def TermGrammarBuild():
	# The grammar rules
	TERM_GRAMMAR = """
		TERM :: ## TERM is the root nonterminal for the grammar
			@R IDRule1 :: TERM >> ID ( TermTail1 
			@R IDRule2 :: TERM >> ID
			@R Tail1Full :: TermTail1 >> TERM TermTail1b
			@R Tail1Empty :: TermTail1 >> )
			@R Tail1bFull :: TermTail1b >> , TERM TermTail1b
			@R Tail1bEmpty :: TermTail1b >> )
			@R BOOLRule1 :: TERM >> BOOL
			@R BOOL1 :: BOOL >> true
			@R BOOL2 :: BOOL >> false
			@R INTRule :: TERM >> INT
			@R REALRule :: TERM >> REAL
			@R BSTRINGRule :: TERM >> BSTRING
			@R STRINGRule :: TERM >> STRING
			@R LISTRule :: TERM >> [ TermTail2
			@R Tail2Full :: TermTail2 >> TERM TermTail2b
			@R Tail2Empty :: TermTail2 >> ]
			@R Tail2bFull :: TermTail2b >> , TERM TermTail2b
			@R Tail2bEmpty :: TermTail2b >> ]
			@R VNAME1Rule :: VAR >> VNAME
			@R VNAME2Rule :: VAR >> VNAME : TERM
			@R VARRule1 :: TERM >> VAR
			@R VARRule2 :: TERM >> VAR ?
			@R AngledRule :: TERM >> < TERM >
	"""
	# kjParsing complains about one shift/reduce conflict,
	# regarding the VAR / VAR? construction.
	# A shift is assumed here (correctly).
	# I do not really understand why no complaint is given
	# about the 'ID' vs. 'ID ( Tail' construct, but it seems
	# to work out.

	TermG = kjParseBuild.NullCGrammar()
	TermG.Keywords("true false")
	TermG.Nonterms("BOOL GEN-VAR TERM VAR")
	TermG.Nonterms("TermTail1 TermTail1b TermTail2 TermTail2b")
	TermG.punct("()[],:?<>")
	declare_terminals(TermG)
	TermG.Declarerules(TERM_GRAMMAR)
	TermG.Compile()
	outfile = open("TBterm.mar", "w")
	TermG.MarshalDump(outfile)
	outfile.close()
	bindrules(TermG)
	return TermG

def declare_terminals(TermG):
	TermG.Addterm("REAL", REALREGEX, scan_real)
	TermG.Addterm("INT", INTREGEX, scan_int)
	TermG.Addterm("BSTRING", BSTRINGREGEX, scan_bstring)
	TermG.Addterm("STRING", STRINGREGEX, scan_string)
	TermG.Addterm("ID", IDREGEX, scan_id)
	TermG.Addterm("VNAME", VNAMEREGEX, scan_vname)

def unmarshal_term_parser(file):
	infile = open(file, "r")
	G = kjParser.UnMarshalGram(infile)
	infile.close()
	declare_terminals(G)
	bindrules(G)
	return G

# Functions bound to terminals

def scan_int(str, size):
	return (string.atoi(str[:size]), size)

def scan_real(str, size):
	return (string.atof(str[:size]), size)

def scan_string(str, size):
	state = 0
	result = ""
	len = 0
	for c in str:
		len = len + 1
		if state == 1:
			if c == '"':
				return (result, len)
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
	raise "LexTokenError", "Lexical parse failure in string"

def scan_bstring(str, size):
	len = string.atoi(str[2:8])
	return (str[9:len], len+1)

def scan_id(str, size):
	return (str[:size], size)

def scan_vname(str, size):
	return (str[:size], size)


# Functions bound to rules

def handle_application(list, C):
	R = ["appl", list[0], list[2]]
	#print "handle_application: ", list, " -> ", R
	return R

def handle_constant(list, C):
	R = ["appl", list[0], []]
	#print "handle_constant: ", list, " -> ", R
	return R

def handle_list1a(list, C):
	#print "handle_list1a: ", list
	list[1].insert(0, list[0])
	#print "handle_list1a: ", list, " -> ", list[1]
	return list[1]

def handle_list1b(list, C):
	list[2].insert(0, list[1])
	return list[2]

def handle_tail1(list, C):
	#print "handle_tail: ", list, " -> ", []
	return []

def handle_bool(list, C):
	return ["bool", list[0]]

def handle_true(list, C):
	return "true"

def handle_false(list, C):
	return "false"

def handle_int(list, C):
	return ["int", list[0]]

def handle_real(list, C):
	return ["real", list[0]]

def handle_string(list, C):
	return ["str", list[0]]

def handle_bstring(list, C):
	return ["bstr", list[0]]

def handle_list(list, C):
	return ["list", list[1]]

def handle_list2a(list, C):
	list[1].insert(0, list[0])
	return list[1]

def handle_list2b(list, C):
	list[2].insert(0, list[1])
	return list[2]

def handle_tail2(list, C):
	return []

def handle_vname1(list, C):
	return (list[0], [])

def handle_vname2(list, C):
	return (list[0], list[2])

def handle_value_var(list, C):
	V = list[0]
	return ["var", V[0], "value", V[1]] 

def handle_result_var(list, C):
	V = list[0]
	return ["var", V[0], "result", V[1]]

# def handle_var(list, C):
#	return list[0]

#def handle_result_var(list, C):
#	return list[0].append("?")

def handle_type_term(list, C):
	return ["placeholder", list[1]]

# Do the actual binding

def bindrules(G):
	G.Bind("IDRule1", handle_application)
	G.Bind("IDRule2", handle_constant)
	G.Bind("Tail1Full", handle_list1a)
	G.Bind("Tail1bEmpty", handle_tail1)
	G.Bind("Tail1bFull", handle_list1b)
	G.Bind("Tail1Empty", handle_tail1)
	G.Bind("BOOLRule1", handle_bool)
	G.Bind("BOOL1", handle_true)
	G.Bind("BOOL2", handle_false)
	G.Bind("INTRule", handle_int)
	G.Bind("REALRule", handle_real)
	G.Bind("BSTRINGRule", handle_bstring)
	G.Bind("STRINGRule", handle_string)
	G.Bind("LISTRule", handle_list)
	G.Bind("Tail2Full", handle_list2a)
	G.Bind("Tail2Empty", handle_tail2)
	G.Bind("Tail2bFull", handle_list2b)
	G.Bind("Tail2bEmpty", handle_tail2)
	G.Bind("VNAME1Rule", handle_vname1)
	G.Bind("VNAME2Rule", handle_vname2)
	G.Bind("VARRule1", handle_value_var)
	G.Bind("VARRule2", handle_result_var)
	G.Bind("AngledRule", handle_type_term)

# Testing the parser


def test_parser(G, str):
	R = G.DoParse1(str, [])
	print "Parsing '%s' results in: " % str, R

def build_term_parser():
	G = TermGrammarBuild()
	print "\n\n***** Testing the newly build parser *****"
	test_term_parser(G)
	H = unmarshal_term_parser("TBterm.mar")
	print "\n\n***** Testing the unmarshalled version *****"
	test_term_parser(H)

def test_term_parser(G):
	test_parser(G, "abc")
	test_parser(G, "just-Testing")
	test_parser(G, "123")
	test_parser(G, "34.456E-12")
	test_parser(G, "+1")
	test_parser(G, "-0")
	test_parser(G, "true")
	test_parser(G, "false")
	test_parser(G, "\"Just testing!\"")
	test_parser(G, "\"\377000023\377Binary string!\"")
	test_parser(G, "xyz(abc)")
	test_parser(G, "Abc")
	test_parser(G, "A1-34?")
	test_parser(G, "B:123")
	test_parser(G, "Xyz : true ?")
	test_parser(G, "<345>")
	test_parser(G, "[ 345, [], \" x y z\", [[[]]]]")
	test_parser(G, '"abc\\"def"')
	test_parser(G, 'abc("d\\\\ef","x\\\\\\"yz\\\\")')
	test_parser(G, 'rec-do(signature([rec-terminate(<p>,<term>),rec-do(<p>,doit(<str>))],[snd-connect(<p>)]))')
