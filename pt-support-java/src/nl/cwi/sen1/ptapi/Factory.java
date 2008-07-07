package nl.cwi.sen1.ptapi;

public class Factory {
  private aterm.pure.PureFactory factory;


  private aterm.AFun fun_ParseTree_Top;
  private aterm.ATerm pattern_ParseTree_Top;

  private aterm.AFun fun_Tree_Appl;
  private aterm.ATerm pattern_Tree_Appl;
  private aterm.AFun fun_Tree_Cycle;
  private aterm.ATerm pattern_Tree_Cycle;
  private aterm.AFun fun_Tree_Amb;
  private aterm.ATerm pattern_Tree_Amb;
  private aterm.AFun fun_Tree_Char;
  private aterm.ATerm pattern_Tree_Char;


  private aterm.AFun fun_Production_Default;
  private aterm.ATerm pattern_Production_Default;
  private aterm.AFun fun_Production_List;
  private aterm.ATerm pattern_Production_List;

  private aterm.AFun fun_Attributes_NoAttrs;
  private aterm.ATerm pattern_Attributes_NoAttrs;
  private aterm.AFun fun_Attributes_Attrs;
  private aterm.ATerm pattern_Attributes_Attrs;


  private aterm.AFun fun_Attr_Assoc;
  private aterm.ATerm pattern_Attr_Assoc;
  private aterm.AFun fun_Attr_Term;
  private aterm.ATerm pattern_Attr_Term;
  private aterm.AFun fun_Attr_Id;
  private aterm.ATerm pattern_Attr_Id;
  private aterm.AFun fun_Attr_Bracket;
  private aterm.ATerm pattern_Attr_Bracket;
  private aterm.AFun fun_Attr_Reject;
  private aterm.ATerm pattern_Attr_Reject;
  private aterm.AFun fun_Attr_Prefer;
  private aterm.ATerm pattern_Attr_Prefer;
  private aterm.AFun fun_Attr_Avoid;
  private aterm.ATerm pattern_Attr_Avoid;

  private aterm.AFun fun_Associativity_Left;
  private aterm.ATerm pattern_Associativity_Left;
  private aterm.AFun fun_Associativity_Right;
  private aterm.ATerm pattern_Associativity_Right;
  private aterm.AFun fun_Associativity_Assoc;
  private aterm.ATerm pattern_Associativity_Assoc;
  private aterm.AFun fun_Associativity_NonAssoc;
  private aterm.ATerm pattern_Associativity_NonAssoc;

  private aterm.AFun fun_Symbol_Lit;
  private aterm.ATerm pattern_Symbol_Lit;
  private aterm.AFun fun_Symbol_Cilit;
  private aterm.ATerm pattern_Symbol_Cilit;
  private aterm.AFun fun_Symbol_Cf;
  private aterm.ATerm pattern_Symbol_Cf;
  private aterm.AFun fun_Symbol_Lex;
  private aterm.ATerm pattern_Symbol_Lex;
  private aterm.AFun fun_Symbol_Empty;
  private aterm.ATerm pattern_Symbol_Empty;
  private aterm.AFun fun_Symbol_Seq;
  private aterm.ATerm pattern_Symbol_Seq;
  private aterm.AFun fun_Symbol_Opt;
  private aterm.ATerm pattern_Symbol_Opt;
  private aterm.AFun fun_Symbol_Alt;
  private aterm.ATerm pattern_Symbol_Alt;
  private aterm.AFun fun_Symbol_Tuple;
  private aterm.ATerm pattern_Symbol_Tuple;
  private aterm.AFun fun_Symbol_Sort;
  private aterm.ATerm pattern_Symbol_Sort;
  private aterm.AFun fun_Symbol_IterPlus;
  private aterm.ATerm pattern_Symbol_IterPlus;
  private aterm.AFun fun_Symbol_IterStar;
  private aterm.ATerm pattern_Symbol_IterStar;
  private aterm.AFun fun_Symbol_IterPlusSep;
  private aterm.ATerm pattern_Symbol_IterPlusSep;
  private aterm.AFun fun_Symbol_IterStarSep;
  private aterm.ATerm pattern_Symbol_IterStarSep;
  private aterm.AFun fun_Symbol_IterN;
  private aterm.ATerm pattern_Symbol_IterN;
  private aterm.AFun fun_Symbol_IterSepN;
  private aterm.ATerm pattern_Symbol_IterSepN;
  private aterm.AFun fun_Symbol_Func;
  private aterm.ATerm pattern_Symbol_Func;
  private aterm.AFun fun_Symbol_ParameterizedSort;
  private aterm.ATerm pattern_Symbol_ParameterizedSort;
  private aterm.AFun fun_Symbol_Strategy;
  private aterm.ATerm pattern_Symbol_Strategy;
  private aterm.AFun fun_Symbol_VarSym;
  private aterm.ATerm pattern_Symbol_VarSym;
  private aterm.AFun fun_Symbol_Layout;
  private aterm.ATerm pattern_Symbol_Layout;
  private aterm.AFun fun_Symbol_CharClass;
  private aterm.ATerm pattern_Symbol_CharClass;


  private aterm.AFun fun_CharRange_Character;
  private aterm.ATerm pattern_CharRange_Character;
  private aterm.AFun fun_CharRange_Range;
  private aterm.ATerm pattern_CharRange_Range;


  private nl.cwi.sen1.ptapi.types.Args empty_Args;
  private nl.cwi.sen1.ptapi.types.Attrs empty_Attrs;
  private nl.cwi.sen1.ptapi.types.Symbols empty_Symbols;
  private nl.cwi.sen1.ptapi.types.CharRanges empty_CharRanges;

  private Factory(aterm.pure.PureFactory factory) {
    this.factory = factory;
  }

  private static Factory instance = null;

  public synchronized static Factory getInstance(aterm.pure.PureFactory factory) {
    if (instance == null) {
        instance = new Factory(factory);
        instance.initialize();
    }
    if (instance.factory != factory) {
        throw new RuntimeException("Don't create two Factory factories with differents PureFactory ");
    }
    return instance;
  }

  public aterm.pure.PureFactory getPureFactory() {
    return factory;
  }

  private void initialize() {

    pattern_ParseTree_Top = factory.parse("parsetree(<term>,<int>)");
    fun_ParseTree_Top = factory.makeAFun("_ParseTree_top", 2, false);

    pattern_Tree_Appl = factory.parse("appl(<term>,<term>)");
    fun_Tree_Appl = factory.makeAFun("_Tree_appl", 2, false);

    pattern_Tree_Cycle = factory.parse("cycle(<term>,<int>)");
    fun_Tree_Cycle = factory.makeAFun("_Tree_cycle", 2, false);

    pattern_Tree_Amb = factory.parse("amb(<term>)");
    fun_Tree_Amb = factory.makeAFun("_Tree_amb", 1, false);

    pattern_Tree_Char = factory.parse("<int>");
    fun_Tree_Char = factory.makeAFun("_Tree_char", 1, false);

    empty_Args = (nl.cwi.sen1.ptapi.types.Args) factory.build(new nl.cwi.sen1.ptapi.types.Args(this, factory.getEmpty(), null, null));
    pattern_Production_Default = factory.parse("prod(<term>,<term>,<term>)");
    fun_Production_Default = factory.makeAFun("_Production_Default", 3, false);

    pattern_Production_List = factory.parse("list(<term>)");
    fun_Production_List = factory.makeAFun("_Production_List", 1, false);

    pattern_Attributes_NoAttrs = factory.parse("no-attrs");
    fun_Attributes_NoAttrs = factory.makeAFun("_Attributes_no-attrs", 0, false);

    pattern_Attributes_Attrs = factory.parse("attrs(<term>)");
    fun_Attributes_Attrs = factory.makeAFun("_Attributes_attrs", 1, false);

    empty_Attrs = (nl.cwi.sen1.ptapi.types.Attrs) factory.build(new nl.cwi.sen1.ptapi.types.Attrs(this, factory.getEmpty(), null, null));
    pattern_Attr_Assoc = factory.parse("assoc(<term>)");
    fun_Attr_Assoc = factory.makeAFun("_Attr_assoc", 1, false);

    pattern_Attr_Term = factory.parse("term(<term>)");
    fun_Attr_Term = factory.makeAFun("_Attr_term", 1, false);

    pattern_Attr_Id = factory.parse("id(<str>)");
    fun_Attr_Id = factory.makeAFun("_Attr_id", 1, false);

    pattern_Attr_Bracket = factory.parse("bracket");
    fun_Attr_Bracket = factory.makeAFun("_Attr_bracket", 0, false);

    pattern_Attr_Reject = factory.parse("reject");
    fun_Attr_Reject = factory.makeAFun("_Attr_reject", 0, false);

    pattern_Attr_Prefer = factory.parse("prefer");
    fun_Attr_Prefer = factory.makeAFun("_Attr_prefer", 0, false);

    pattern_Attr_Avoid = factory.parse("avoid");
    fun_Attr_Avoid = factory.makeAFun("_Attr_avoid", 0, false);

    pattern_Associativity_Left = factory.parse("left");
    fun_Associativity_Left = factory.makeAFun("_Associativity_left", 0, false);

    pattern_Associativity_Right = factory.parse("right");
    fun_Associativity_Right = factory.makeAFun("_Associativity_right", 0, false);

    pattern_Associativity_Assoc = factory.parse("assoc");
    fun_Associativity_Assoc = factory.makeAFun("_Associativity_assoc", 0, false);

    pattern_Associativity_NonAssoc = factory.parse("non-assoc");
    fun_Associativity_NonAssoc = factory.makeAFun("_Associativity_non-assoc", 0, false);

    pattern_Symbol_Lit = factory.parse("lit(<str>)");
    fun_Symbol_Lit = factory.makeAFun("_Symbol_lit", 1, false);

    pattern_Symbol_Cilit = factory.parse("cilit(<str>)");
    fun_Symbol_Cilit = factory.makeAFun("_Symbol_cilit", 1, false);

    pattern_Symbol_Cf = factory.parse("cf(<term>)");
    fun_Symbol_Cf = factory.makeAFun("_Symbol_cf", 1, false);

    pattern_Symbol_Lex = factory.parse("lex(<term>)");
    fun_Symbol_Lex = factory.makeAFun("_Symbol_lex", 1, false);

    pattern_Symbol_Empty = factory.parse("empty");
    fun_Symbol_Empty = factory.makeAFun("_Symbol_empty", 0, false);

    pattern_Symbol_Seq = factory.parse("seq(<term>)");
    fun_Symbol_Seq = factory.makeAFun("_Symbol_seq", 1, false);

    pattern_Symbol_Opt = factory.parse("opt(<term>)");
    fun_Symbol_Opt = factory.makeAFun("_Symbol_opt", 1, false);

    pattern_Symbol_Alt = factory.parse("alt(<term>,<term>)");
    fun_Symbol_Alt = factory.makeAFun("_Symbol_alt", 2, false);

    pattern_Symbol_Tuple = factory.parse("tuple(<term>,<term>)");
    fun_Symbol_Tuple = factory.makeAFun("_Symbol_tuple", 2, false);

    pattern_Symbol_Sort = factory.parse("sort(<str>)");
    fun_Symbol_Sort = factory.makeAFun("_Symbol_sort", 1, false);

    pattern_Symbol_IterPlus = factory.parse("iter(<term>)");
    fun_Symbol_IterPlus = factory.makeAFun("_Symbol_iter-plus", 1, false);

    pattern_Symbol_IterStar = factory.parse("iter-star(<term>)");
    fun_Symbol_IterStar = factory.makeAFun("_Symbol_iter-star", 1, false);

    pattern_Symbol_IterPlusSep = factory.parse("iter-sep(<term>,<term>)");
    fun_Symbol_IterPlusSep = factory.makeAFun("_Symbol_iter-plus-sep", 2, false);

    pattern_Symbol_IterStarSep = factory.parse("iter-star-sep(<term>,<term>)");
    fun_Symbol_IterStarSep = factory.makeAFun("_Symbol_iter-star-sep", 2, false);

    pattern_Symbol_IterN = factory.parse("iter-n(<term>,<int>)");
    fun_Symbol_IterN = factory.makeAFun("_Symbol_iter-n", 2, false);

    pattern_Symbol_IterSepN = factory.parse("iter-sep-n(<term>,<term>,<int>)");
    fun_Symbol_IterSepN = factory.makeAFun("_Symbol_iter-sep-n", 3, false);

    pattern_Symbol_Func = factory.parse("func(<term>,<term>)");
    fun_Symbol_Func = factory.makeAFun("_Symbol_func", 2, false);

    pattern_Symbol_ParameterizedSort = factory.parse("parameterized-sort(<str>,<term>)");
    fun_Symbol_ParameterizedSort = factory.makeAFun("_Symbol_parameterized-sort", 2, false);

    pattern_Symbol_Strategy = factory.parse("strategy(<term>,<term>)");
    fun_Symbol_Strategy = factory.makeAFun("_Symbol_strategy", 2, false);

    pattern_Symbol_VarSym = factory.parse("varsym(<term>)");
    fun_Symbol_VarSym = factory.makeAFun("_Symbol_var-sym", 1, false);

    pattern_Symbol_Layout = factory.parse("layout");
    fun_Symbol_Layout = factory.makeAFun("_Symbol_layout", 0, false);

    pattern_Symbol_CharClass = factory.parse("char-class(<term>)");
    fun_Symbol_CharClass = factory.makeAFun("_Symbol_char-class", 1, false);

    empty_Symbols = (nl.cwi.sen1.ptapi.types.Symbols) factory.build(new nl.cwi.sen1.ptapi.types.Symbols(this, factory.getEmpty(), null, null));
    pattern_CharRange_Character = factory.parse("<int>");
    fun_CharRange_Character = factory.makeAFun("_CharRange_character", 1, false);

    pattern_CharRange_Range = factory.parse("range(<int>,<int>)");
    fun_CharRange_Range = factory.makeAFun("_CharRange_range", 2, false);

    empty_CharRanges = (nl.cwi.sen1.ptapi.types.CharRanges) factory.build(new nl.cwi.sen1.ptapi.types.CharRanges(this, factory.getEmpty(), null, null));
  }

/*genAlternativeMethods*/
  public nl.cwi.sen1.ptapi.types.parsetree.Top makeParseTree_Top(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.parsetree.Top) factory.build( new nl.cwi.sen1.ptapi.types.parsetree.Top(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.parsetree.Top makeParseTree_Top(nl.cwi.sen1.ptapi.types.Tree _top, int _ambCnt) {
    aterm.ATerm[] args = new aterm.ATerm[] {_top, factory.makeInt(_ambCnt)};
    return makeParseTree_Top(fun_ParseTree_Top, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.ParseTree ParseTree_TopFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_ParseTree_Top);

    if (children != null) {
      return makeParseTree_Top(
        TreeFromTerm((aterm.ATerm) children.get(0)),
        ((Integer) children.get(1)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.parsetree.Top arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getTop().toTerm());
    args.add(new Integer(arg.getAmbCnt()));
    return factory.make(pattern_ParseTree_Top, args);
  }

  public nl.cwi.sen1.ptapi.types.tree.Appl makeTree_Appl(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.tree.Appl) factory.build( new nl.cwi.sen1.ptapi.types.tree.Appl(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.tree.Appl makeTree_Appl(nl.cwi.sen1.ptapi.types.Production _prod, nl.cwi.sen1.ptapi.types.Args _args) {
    aterm.ATerm[] args = new aterm.ATerm[] {_prod, _args};
    return makeTree_Appl(fun_Tree_Appl, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Tree Tree_ApplFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Tree_Appl);

    if (children != null) {
      return makeTree_Appl(
        ProductionFromTerm((aterm.ATerm) children.get(0)),
        ArgsFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.tree.Appl arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getProd().toTerm());
    args.add(arg.getArgs().toTerm());
    return factory.make(pattern_Tree_Appl, args);
  }

  public nl.cwi.sen1.ptapi.types.tree.Cycle makeTree_Cycle(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.tree.Cycle) factory.build( new nl.cwi.sen1.ptapi.types.tree.Cycle(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.tree.Cycle makeTree_Cycle(nl.cwi.sen1.ptapi.types.Symbol _symbol, int _cycleLength) {
    aterm.ATerm[] args = new aterm.ATerm[] {_symbol, factory.makeInt(_cycleLength)};
    return makeTree_Cycle(fun_Tree_Cycle, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Tree Tree_CycleFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Tree_Cycle);

    if (children != null) {
      return makeTree_Cycle(
        SymbolFromTerm((aterm.ATerm) children.get(0)),
        ((Integer) children.get(1)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.tree.Cycle arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getSymbol().toTerm());
    args.add(new Integer(arg.getCycleLength()));
    return factory.make(pattern_Tree_Cycle, args);
  }

  public nl.cwi.sen1.ptapi.types.tree.Amb makeTree_Amb(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.tree.Amb) factory.build( new nl.cwi.sen1.ptapi.types.tree.Amb(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.tree.Amb makeTree_Amb(nl.cwi.sen1.ptapi.types.Args _args) {
    aterm.ATerm[] args = new aterm.ATerm[] {_args};
    return makeTree_Amb(fun_Tree_Amb, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Tree Tree_AmbFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Tree_Amb);

    if (children != null) {
      return makeTree_Amb(
        ArgsFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.tree.Amb arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getArgs().toTerm());
    return factory.make(pattern_Tree_Amb, args);
  }

  public nl.cwi.sen1.ptapi.types.tree.Char makeTree_Char(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.tree.Char) factory.build( new nl.cwi.sen1.ptapi.types.tree.Char(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.tree.Char makeTree_Char(int _character) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeInt(_character)};
    return makeTree_Char(fun_Tree_Char, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Tree Tree_CharFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Tree_Char);

    if (children != null) {
      return makeTree_Char(
        ((Integer) children.get(0)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.tree.Char arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(new Integer(arg.getCharacter()));
    return factory.make(pattern_Tree_Char, args);
  }

  public nl.cwi.sen1.ptapi.types.production.Default makeProduction_Default(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.production.Default) factory.build( new nl.cwi.sen1.ptapi.types.production.Default(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.production.Default makeProduction_Default(nl.cwi.sen1.ptapi.types.Symbols _lhs, nl.cwi.sen1.ptapi.types.Symbol _rhs, nl.cwi.sen1.ptapi.types.Attributes _attributes) {
    aterm.ATerm[] args = new aterm.ATerm[] {_lhs, _rhs, _attributes};
    return makeProduction_Default(fun_Production_Default, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Production Production_DefaultFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Production_Default);

    if (children != null) {
      return makeProduction_Default(
        SymbolsFromTerm((aterm.ATerm) children.get(0)),
        SymbolFromTerm((aterm.ATerm) children.get(1)),
        AttributesFromTerm((aterm.ATerm) children.get(2))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.production.Default arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getLhs().toTerm());
    args.add(arg.getRhs().toTerm());
    args.add(arg.getAttributes().toTerm());
    return factory.make(pattern_Production_Default, args);
  }

  public nl.cwi.sen1.ptapi.types.production.List makeProduction_List(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.production.List) factory.build( new nl.cwi.sen1.ptapi.types.production.List(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.production.List makeProduction_List(nl.cwi.sen1.ptapi.types.Symbol _rhs) {
    aterm.ATerm[] args = new aterm.ATerm[] {_rhs};
    return makeProduction_List(fun_Production_List, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Production Production_ListFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Production_List);

    if (children != null) {
      return makeProduction_List(
        SymbolFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.production.List arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getRhs().toTerm());
    return factory.make(pattern_Production_List, args);
  }

  public nl.cwi.sen1.ptapi.types.attributes.NoAttrs makeAttributes_NoAttrs(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.attributes.NoAttrs) factory.build( new nl.cwi.sen1.ptapi.types.attributes.NoAttrs(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.attributes.NoAttrs makeAttributes_NoAttrs() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeAttributes_NoAttrs(fun_Attributes_NoAttrs, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Attributes Attributes_NoAttrsFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attributes_NoAttrs);

    if (children != null) {
      return makeAttributes_NoAttrs(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.attributes.NoAttrs arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Attributes_NoAttrs, args);
  }

  public nl.cwi.sen1.ptapi.types.attributes.Attrs makeAttributes_Attrs(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.attributes.Attrs) factory.build( new nl.cwi.sen1.ptapi.types.attributes.Attrs(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.attributes.Attrs makeAttributes_Attrs(nl.cwi.sen1.ptapi.types.Attrs _attrs) {
    aterm.ATerm[] args = new aterm.ATerm[] {_attrs};
    return makeAttributes_Attrs(fun_Attributes_Attrs, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Attributes Attributes_AttrsFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attributes_Attrs);

    if (children != null) {
      return makeAttributes_Attrs(
        AttrsFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.attributes.Attrs arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getAttrs().toTerm());
    return factory.make(pattern_Attributes_Attrs, args);
  }

  public nl.cwi.sen1.ptapi.types.attr.Assoc makeAttr_Assoc(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.attr.Assoc) factory.build( new nl.cwi.sen1.ptapi.types.attr.Assoc(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.attr.Assoc makeAttr_Assoc(nl.cwi.sen1.ptapi.types.Associativity _assoc) {
    aterm.ATerm[] args = new aterm.ATerm[] {_assoc};
    return makeAttr_Assoc(fun_Attr_Assoc, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Attr Attr_AssocFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attr_Assoc);

    if (children != null) {
      return makeAttr_Assoc(
        AssociativityFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.attr.Assoc arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getAssoc().toTerm());
    return factory.make(pattern_Attr_Assoc, args);
  }

  public nl.cwi.sen1.ptapi.types.attr.Term makeAttr_Term(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.attr.Term) factory.build( new nl.cwi.sen1.ptapi.types.attr.Term(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.attr.Term makeAttr_Term(aterm.ATerm _value) {
    aterm.ATerm[] args = new aterm.ATerm[] {_value};
    return makeAttr_Term(fun_Attr_Term, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Attr Attr_TermFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attr_Term);

    if (children != null) {
      return makeAttr_Term(
        (aterm.ATerm) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.attr.Term arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getValue());
    return factory.make(pattern_Attr_Term, args);
  }

  public nl.cwi.sen1.ptapi.types.attr.Id makeAttr_Id(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.attr.Id) factory.build( new nl.cwi.sen1.ptapi.types.attr.Id(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.attr.Id makeAttr_Id(String _moduleName) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_moduleName, 0, true))};
    return makeAttr_Id(fun_Attr_Id, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Attr Attr_IdFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attr_Id);

    if (children != null) {
      return makeAttr_Id(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.attr.Id arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getModuleName());
    return factory.make(pattern_Attr_Id, args);
  }

  public nl.cwi.sen1.ptapi.types.attr.Bracket makeAttr_Bracket(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.attr.Bracket) factory.build( new nl.cwi.sen1.ptapi.types.attr.Bracket(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.attr.Bracket makeAttr_Bracket() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeAttr_Bracket(fun_Attr_Bracket, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Attr Attr_BracketFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attr_Bracket);

    if (children != null) {
      return makeAttr_Bracket(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.attr.Bracket arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Attr_Bracket, args);
  }

  public nl.cwi.sen1.ptapi.types.attr.Reject makeAttr_Reject(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.attr.Reject) factory.build( new nl.cwi.sen1.ptapi.types.attr.Reject(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.attr.Reject makeAttr_Reject() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeAttr_Reject(fun_Attr_Reject, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Attr Attr_RejectFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attr_Reject);

    if (children != null) {
      return makeAttr_Reject(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.attr.Reject arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Attr_Reject, args);
  }

  public nl.cwi.sen1.ptapi.types.attr.Prefer makeAttr_Prefer(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.attr.Prefer) factory.build( new nl.cwi.sen1.ptapi.types.attr.Prefer(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.attr.Prefer makeAttr_Prefer() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeAttr_Prefer(fun_Attr_Prefer, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Attr Attr_PreferFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attr_Prefer);

    if (children != null) {
      return makeAttr_Prefer(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.attr.Prefer arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Attr_Prefer, args);
  }

  public nl.cwi.sen1.ptapi.types.attr.Avoid makeAttr_Avoid(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.attr.Avoid) factory.build( new nl.cwi.sen1.ptapi.types.attr.Avoid(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.attr.Avoid makeAttr_Avoid() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeAttr_Avoid(fun_Attr_Avoid, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Attr Attr_AvoidFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attr_Avoid);

    if (children != null) {
      return makeAttr_Avoid(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.attr.Avoid arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Attr_Avoid, args);
  }

  public nl.cwi.sen1.ptapi.types.associativity.Left makeAssociativity_Left(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.associativity.Left) factory.build( new nl.cwi.sen1.ptapi.types.associativity.Left(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.associativity.Left makeAssociativity_Left() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeAssociativity_Left(fun_Associativity_Left, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Associativity Associativity_LeftFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Associativity_Left);

    if (children != null) {
      return makeAssociativity_Left(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.associativity.Left arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Associativity_Left, args);
  }

  public nl.cwi.sen1.ptapi.types.associativity.Right makeAssociativity_Right(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.associativity.Right) factory.build( new nl.cwi.sen1.ptapi.types.associativity.Right(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.associativity.Right makeAssociativity_Right() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeAssociativity_Right(fun_Associativity_Right, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Associativity Associativity_RightFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Associativity_Right);

    if (children != null) {
      return makeAssociativity_Right(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.associativity.Right arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Associativity_Right, args);
  }

  public nl.cwi.sen1.ptapi.types.associativity.Assoc makeAssociativity_Assoc(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.associativity.Assoc) factory.build( new nl.cwi.sen1.ptapi.types.associativity.Assoc(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.associativity.Assoc makeAssociativity_Assoc() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeAssociativity_Assoc(fun_Associativity_Assoc, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Associativity Associativity_AssocFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Associativity_Assoc);

    if (children != null) {
      return makeAssociativity_Assoc(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.associativity.Assoc arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Associativity_Assoc, args);
  }

  public nl.cwi.sen1.ptapi.types.associativity.NonAssoc makeAssociativity_NonAssoc(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.associativity.NonAssoc) factory.build( new nl.cwi.sen1.ptapi.types.associativity.NonAssoc(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.associativity.NonAssoc makeAssociativity_NonAssoc() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeAssociativity_NonAssoc(fun_Associativity_NonAssoc, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Associativity Associativity_NonAssocFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Associativity_NonAssoc);

    if (children != null) {
      return makeAssociativity_NonAssoc(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.associativity.NonAssoc arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Associativity_NonAssoc, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.Lit makeSymbol_Lit(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.Lit) factory.build( new nl.cwi.sen1.ptapi.types.symbol.Lit(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.Lit makeSymbol_Lit(String _string) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_string, 0, true))};
    return makeSymbol_Lit(fun_Symbol_Lit, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_LitFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_Lit);

    if (children != null) {
      return makeSymbol_Lit(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.Lit arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getString());
    return factory.make(pattern_Symbol_Lit, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.Cilit makeSymbol_Cilit(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.Cilit) factory.build( new nl.cwi.sen1.ptapi.types.symbol.Cilit(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.Cilit makeSymbol_Cilit(String _string) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_string, 0, true))};
    return makeSymbol_Cilit(fun_Symbol_Cilit, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_CilitFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_Cilit);

    if (children != null) {
      return makeSymbol_Cilit(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.Cilit arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getString());
    return factory.make(pattern_Symbol_Cilit, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.Cf makeSymbol_Cf(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.Cf) factory.build( new nl.cwi.sen1.ptapi.types.symbol.Cf(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.Cf makeSymbol_Cf(nl.cwi.sen1.ptapi.types.Symbol _symbol) {
    aterm.ATerm[] args = new aterm.ATerm[] {_symbol};
    return makeSymbol_Cf(fun_Symbol_Cf, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_CfFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_Cf);

    if (children != null) {
      return makeSymbol_Cf(
        SymbolFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.Cf arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getSymbol().toTerm());
    return factory.make(pattern_Symbol_Cf, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.Lex makeSymbol_Lex(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.Lex) factory.build( new nl.cwi.sen1.ptapi.types.symbol.Lex(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.Lex makeSymbol_Lex(nl.cwi.sen1.ptapi.types.Symbol _symbol) {
    aterm.ATerm[] args = new aterm.ATerm[] {_symbol};
    return makeSymbol_Lex(fun_Symbol_Lex, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_LexFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_Lex);

    if (children != null) {
      return makeSymbol_Lex(
        SymbolFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.Lex arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getSymbol().toTerm());
    return factory.make(pattern_Symbol_Lex, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.Empty makeSymbol_Empty(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.Empty) factory.build( new nl.cwi.sen1.ptapi.types.symbol.Empty(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.Empty makeSymbol_Empty() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeSymbol_Empty(fun_Symbol_Empty, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_EmptyFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_Empty);

    if (children != null) {
      return makeSymbol_Empty(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.Empty arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Symbol_Empty, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.Seq makeSymbol_Seq(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.Seq) factory.build( new nl.cwi.sen1.ptapi.types.symbol.Seq(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.Seq makeSymbol_Seq(nl.cwi.sen1.ptapi.types.Symbols _symbols) {
    aterm.ATerm[] args = new aterm.ATerm[] {_symbols};
    return makeSymbol_Seq(fun_Symbol_Seq, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_SeqFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_Seq);

    if (children != null) {
      return makeSymbol_Seq(
        SymbolsFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.Seq arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getSymbols().toTerm());
    return factory.make(pattern_Symbol_Seq, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.Opt makeSymbol_Opt(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.Opt) factory.build( new nl.cwi.sen1.ptapi.types.symbol.Opt(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.Opt makeSymbol_Opt(nl.cwi.sen1.ptapi.types.Symbol _symbol) {
    aterm.ATerm[] args = new aterm.ATerm[] {_symbol};
    return makeSymbol_Opt(fun_Symbol_Opt, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_OptFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_Opt);

    if (children != null) {
      return makeSymbol_Opt(
        SymbolFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.Opt arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getSymbol().toTerm());
    return factory.make(pattern_Symbol_Opt, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.Alt makeSymbol_Alt(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.Alt) factory.build( new nl.cwi.sen1.ptapi.types.symbol.Alt(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.Alt makeSymbol_Alt(nl.cwi.sen1.ptapi.types.Symbol _lhs, nl.cwi.sen1.ptapi.types.Symbol _rhs) {
    aterm.ATerm[] args = new aterm.ATerm[] {_lhs, _rhs};
    return makeSymbol_Alt(fun_Symbol_Alt, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_AltFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_Alt);

    if (children != null) {
      return makeSymbol_Alt(
        SymbolFromTerm((aterm.ATerm) children.get(0)),
        SymbolFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.Alt arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getLhs().toTerm());
    args.add(arg.getRhs().toTerm());
    return factory.make(pattern_Symbol_Alt, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.Tuple makeSymbol_Tuple(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.Tuple) factory.build( new nl.cwi.sen1.ptapi.types.symbol.Tuple(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.Tuple makeSymbol_Tuple(nl.cwi.sen1.ptapi.types.Symbol _head, nl.cwi.sen1.ptapi.types.Symbols _rest) {
    aterm.ATerm[] args = new aterm.ATerm[] {_head, _rest};
    return makeSymbol_Tuple(fun_Symbol_Tuple, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_TupleFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_Tuple);

    if (children != null) {
      return makeSymbol_Tuple(
        SymbolFromTerm((aterm.ATerm) children.get(0)),
        SymbolsFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.Tuple arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getHead().toTerm());
    args.add(arg.getRest().toTerm());
    return factory.make(pattern_Symbol_Tuple, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.Sort makeSymbol_Sort(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.Sort) factory.build( new nl.cwi.sen1.ptapi.types.symbol.Sort(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.Sort makeSymbol_Sort(String _string) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_string, 0, true))};
    return makeSymbol_Sort(fun_Symbol_Sort, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_SortFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_Sort);

    if (children != null) {
      return makeSymbol_Sort(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.Sort arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getString());
    return factory.make(pattern_Symbol_Sort, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.IterPlus makeSymbol_IterPlus(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.IterPlus) factory.build( new nl.cwi.sen1.ptapi.types.symbol.IterPlus(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.IterPlus makeSymbol_IterPlus(nl.cwi.sen1.ptapi.types.Symbol _symbol) {
    aterm.ATerm[] args = new aterm.ATerm[] {_symbol};
    return makeSymbol_IterPlus(fun_Symbol_IterPlus, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_IterPlusFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_IterPlus);

    if (children != null) {
      return makeSymbol_IterPlus(
        SymbolFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.IterPlus arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getSymbol().toTerm());
    return factory.make(pattern_Symbol_IterPlus, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.IterStar makeSymbol_IterStar(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.IterStar) factory.build( new nl.cwi.sen1.ptapi.types.symbol.IterStar(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.IterStar makeSymbol_IterStar(nl.cwi.sen1.ptapi.types.Symbol _symbol) {
    aterm.ATerm[] args = new aterm.ATerm[] {_symbol};
    return makeSymbol_IterStar(fun_Symbol_IterStar, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_IterStarFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_IterStar);

    if (children != null) {
      return makeSymbol_IterStar(
        SymbolFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.IterStar arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getSymbol().toTerm());
    return factory.make(pattern_Symbol_IterStar, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.IterPlusSep makeSymbol_IterPlusSep(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.IterPlusSep) factory.build( new nl.cwi.sen1.ptapi.types.symbol.IterPlusSep(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.IterPlusSep makeSymbol_IterPlusSep(nl.cwi.sen1.ptapi.types.Symbol _symbol, nl.cwi.sen1.ptapi.types.Symbol _separator) {
    aterm.ATerm[] args = new aterm.ATerm[] {_symbol, _separator};
    return makeSymbol_IterPlusSep(fun_Symbol_IterPlusSep, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_IterPlusSepFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_IterPlusSep);

    if (children != null) {
      return makeSymbol_IterPlusSep(
        SymbolFromTerm((aterm.ATerm) children.get(0)),
        SymbolFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.IterPlusSep arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getSymbol().toTerm());
    args.add(arg.getSeparator().toTerm());
    return factory.make(pattern_Symbol_IterPlusSep, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.IterStarSep makeSymbol_IterStarSep(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.IterStarSep) factory.build( new nl.cwi.sen1.ptapi.types.symbol.IterStarSep(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.IterStarSep makeSymbol_IterStarSep(nl.cwi.sen1.ptapi.types.Symbol _symbol, nl.cwi.sen1.ptapi.types.Symbol _separator) {
    aterm.ATerm[] args = new aterm.ATerm[] {_symbol, _separator};
    return makeSymbol_IterStarSep(fun_Symbol_IterStarSep, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_IterStarSepFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_IterStarSep);

    if (children != null) {
      return makeSymbol_IterStarSep(
        SymbolFromTerm((aterm.ATerm) children.get(0)),
        SymbolFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.IterStarSep arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getSymbol().toTerm());
    args.add(arg.getSeparator().toTerm());
    return factory.make(pattern_Symbol_IterStarSep, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.IterN makeSymbol_IterN(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.IterN) factory.build( new nl.cwi.sen1.ptapi.types.symbol.IterN(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.IterN makeSymbol_IterN(nl.cwi.sen1.ptapi.types.Symbol _symbol, int _number) {
    aterm.ATerm[] args = new aterm.ATerm[] {_symbol, factory.makeInt(_number)};
    return makeSymbol_IterN(fun_Symbol_IterN, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_IterNFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_IterN);

    if (children != null) {
      return makeSymbol_IterN(
        SymbolFromTerm((aterm.ATerm) children.get(0)),
        ((Integer) children.get(1)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.IterN arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getSymbol().toTerm());
    args.add(new Integer(arg.getNumber()));
    return factory.make(pattern_Symbol_IterN, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.IterSepN makeSymbol_IterSepN(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.IterSepN) factory.build( new nl.cwi.sen1.ptapi.types.symbol.IterSepN(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.IterSepN makeSymbol_IterSepN(nl.cwi.sen1.ptapi.types.Symbol _symbol, nl.cwi.sen1.ptapi.types.Symbol _separator, int _number) {
    aterm.ATerm[] args = new aterm.ATerm[] {_symbol, _separator, factory.makeInt(_number)};
    return makeSymbol_IterSepN(fun_Symbol_IterSepN, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_IterSepNFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_IterSepN);

    if (children != null) {
      return makeSymbol_IterSepN(
        SymbolFromTerm((aterm.ATerm) children.get(0)),
        SymbolFromTerm((aterm.ATerm) children.get(1)),
        ((Integer) children.get(2)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.IterSepN arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getSymbol().toTerm());
    args.add(arg.getSeparator().toTerm());
    args.add(new Integer(arg.getNumber()));
    return factory.make(pattern_Symbol_IterSepN, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.Func makeSymbol_Func(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.Func) factory.build( new nl.cwi.sen1.ptapi.types.symbol.Func(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.Func makeSymbol_Func(nl.cwi.sen1.ptapi.types.Symbols _symbols, nl.cwi.sen1.ptapi.types.Symbol _symbol) {
    aterm.ATerm[] args = new aterm.ATerm[] {_symbols, _symbol};
    return makeSymbol_Func(fun_Symbol_Func, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_FuncFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_Func);

    if (children != null) {
      return makeSymbol_Func(
        SymbolsFromTerm((aterm.ATerm) children.get(0)),
        SymbolFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.Func arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getSymbols().toTerm());
    args.add(arg.getSymbol().toTerm());
    return factory.make(pattern_Symbol_Func, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.ParameterizedSort makeSymbol_ParameterizedSort(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.ParameterizedSort) factory.build( new nl.cwi.sen1.ptapi.types.symbol.ParameterizedSort(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.ParameterizedSort makeSymbol_ParameterizedSort(String _sort, nl.cwi.sen1.ptapi.types.Symbols _parameters) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_sort, 0, true)), _parameters};
    return makeSymbol_ParameterizedSort(fun_Symbol_ParameterizedSort, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_ParameterizedSortFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_ParameterizedSort);

    if (children != null) {
      return makeSymbol_ParameterizedSort(
        (String) children.get(0),
        SymbolsFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.ParameterizedSort arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getSort());
    args.add(arg.getParameters().toTerm());
    return factory.make(pattern_Symbol_ParameterizedSort, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.Strategy makeSymbol_Strategy(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.Strategy) factory.build( new nl.cwi.sen1.ptapi.types.symbol.Strategy(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.Strategy makeSymbol_Strategy(nl.cwi.sen1.ptapi.types.Symbol _lhs, nl.cwi.sen1.ptapi.types.Symbol _rhs) {
    aterm.ATerm[] args = new aterm.ATerm[] {_lhs, _rhs};
    return makeSymbol_Strategy(fun_Symbol_Strategy, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_StrategyFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_Strategy);

    if (children != null) {
      return makeSymbol_Strategy(
        SymbolFromTerm((aterm.ATerm) children.get(0)),
        SymbolFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.Strategy arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getLhs().toTerm());
    args.add(arg.getRhs().toTerm());
    return factory.make(pattern_Symbol_Strategy, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.VarSym makeSymbol_VarSym(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.VarSym) factory.build( new nl.cwi.sen1.ptapi.types.symbol.VarSym(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.VarSym makeSymbol_VarSym(nl.cwi.sen1.ptapi.types.Symbol _symbol) {
    aterm.ATerm[] args = new aterm.ATerm[] {_symbol};
    return makeSymbol_VarSym(fun_Symbol_VarSym, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_VarSymFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_VarSym);

    if (children != null) {
      return makeSymbol_VarSym(
        SymbolFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.VarSym arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getSymbol().toTerm());
    return factory.make(pattern_Symbol_VarSym, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.Layout makeSymbol_Layout(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.Layout) factory.build( new nl.cwi.sen1.ptapi.types.symbol.Layout(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.Layout makeSymbol_Layout() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeSymbol_Layout(fun_Symbol_Layout, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_LayoutFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_Layout);

    if (children != null) {
      return makeSymbol_Layout(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.Layout arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Symbol_Layout, args);
  }

  public nl.cwi.sen1.ptapi.types.symbol.CharClass makeSymbol_CharClass(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.symbol.CharClass) factory.build( new nl.cwi.sen1.ptapi.types.symbol.CharClass(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.symbol.CharClass makeSymbol_CharClass(nl.cwi.sen1.ptapi.types.CharRanges _ranges) {
    aterm.ATerm[] args = new aterm.ATerm[] {_ranges};
    return makeSymbol_CharClass(fun_Symbol_CharClass, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.Symbol Symbol_CharClassFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Symbol_CharClass);

    if (children != null) {
      return makeSymbol_CharClass(
        CharRangesFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.symbol.CharClass arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getRanges().toTerm());
    return factory.make(pattern_Symbol_CharClass, args);
  }

  public nl.cwi.sen1.ptapi.types.charrange.Character makeCharRange_Character(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.charrange.Character) factory.build( new nl.cwi.sen1.ptapi.types.charrange.Character(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.charrange.Character makeCharRange_Character(int _start) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeInt(_start)};
    return makeCharRange_Character(fun_CharRange_Character, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.CharRange CharRange_CharacterFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_CharRange_Character);

    if (children != null) {
      return makeCharRange_Character(
        ((Integer) children.get(0)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.charrange.Character arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(new Integer(arg.getStart()));
    return factory.make(pattern_CharRange_Character, args);
  }

  public nl.cwi.sen1.ptapi.types.charrange.Range makeCharRange_Range(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ptapi.types.charrange.Range) factory.build( new nl.cwi.sen1.ptapi.types.charrange.Range(this, annos, fun, args));
  }

  public nl.cwi.sen1.ptapi.types.charrange.Range makeCharRange_Range(int _start, int _end) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeInt(_start), factory.makeInt(_end)};
    return makeCharRange_Range(fun_CharRange_Range, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ptapi.types.CharRange CharRange_RangeFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_CharRange_Range);

    if (children != null) {
      return makeCharRange_Range(
        ((Integer) children.get(0)).intValue(),
        ((Integer) children.get(1)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ptapi.types.charrange.Range arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(new Integer(arg.getStart()));
    args.add(new Integer(arg.getEnd()));
    return factory.make(pattern_CharRange_Range, args);
  }

/*genMakeLists*/
  public nl.cwi.sen1.ptapi.types.Args makeArgs() {
    return empty_Args;
  }

  public nl.cwi.sen1.ptapi.types.Args makeArgs(nl.cwi.sen1.ptapi.types.Tree elem) {
    return makeArgs(elem, empty_Args);
  }

  public nl.cwi.sen1.ptapi.types.Args makeArgs(nl.cwi.sen1.ptapi.types.Tree head, nl.cwi.sen1.ptapi.types.Args tail) {
    return makeArgs(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.ptapi.types.Args makeArgs(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.ptapi.types.Args) factory.build(new nl.cwi.sen1.ptapi.types.Args(this, annos, head, tail));
  }

  public nl.cwi.sen1.ptapi.types.Args makeArgs(nl.cwi.sen1.ptapi.types.Tree elem0, nl.cwi.sen1.ptapi.types.Tree elem1) {
    return makeArgs(elem0, makeArgs(elem1));
  }

  public nl.cwi.sen1.ptapi.types.Args makeArgs(nl.cwi.sen1.ptapi.types.Tree elem0, nl.cwi.sen1.ptapi.types.Tree elem1, nl.cwi.sen1.ptapi.types.Tree elem2) {
    return makeArgs(elem0, makeArgs(elem1, elem2));
  }

  public nl.cwi.sen1.ptapi.types.Args makeArgs(nl.cwi.sen1.ptapi.types.Tree elem0, nl.cwi.sen1.ptapi.types.Tree elem1, nl.cwi.sen1.ptapi.types.Tree elem2, nl.cwi.sen1.ptapi.types.Tree elem3) {
    return makeArgs(elem0, makeArgs(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.ptapi.types.Args makeArgs(nl.cwi.sen1.ptapi.types.Tree elem0, nl.cwi.sen1.ptapi.types.Tree elem1, nl.cwi.sen1.ptapi.types.Tree elem2, nl.cwi.sen1.ptapi.types.Tree elem3, nl.cwi.sen1.ptapi.types.Tree elem4) {
    return makeArgs(elem0, makeArgs(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.ptapi.types.Args makeArgs(nl.cwi.sen1.ptapi.types.Tree elem0, nl.cwi.sen1.ptapi.types.Tree elem1, nl.cwi.sen1.ptapi.types.Tree elem2, nl.cwi.sen1.ptapi.types.Tree elem3, nl.cwi.sen1.ptapi.types.Tree elem4, nl.cwi.sen1.ptapi.types.Tree elem5) {
    return makeArgs(elem0, makeArgs(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.ptapi.types.Args reverse(nl.cwi.sen1.ptapi.types.Args arg) {
    nl.cwi.sen1.ptapi.types.Args reversed = makeArgs();
    while (!arg.isEmpty()) {
      reversed = makeArgs(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.ptapi.types.Args concat(nl.cwi.sen1.ptapi.types.Args arg0, nl.cwi.sen1.ptapi.types.Args arg1) {
    nl.cwi.sen1.ptapi.types.Args result = arg1;

    for (nl.cwi.sen1.ptapi.types.Args list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeArgs(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.ptapi.types.Args append(nl.cwi.sen1.ptapi.types.Args list, nl.cwi.sen1.ptapi.types.Tree elem) {
    return concat(list, makeArgs(elem));
  }

  public nl.cwi.sen1.ptapi.types.Attrs makeAttrs() {
    return empty_Attrs;
  }

  public nl.cwi.sen1.ptapi.types.Attrs makeAttrs(nl.cwi.sen1.ptapi.types.Attr elem) {
    return makeAttrs(elem, empty_Attrs);
  }

  public nl.cwi.sen1.ptapi.types.Attrs makeAttrs(nl.cwi.sen1.ptapi.types.Attr head, nl.cwi.sen1.ptapi.types.Attrs tail) {
    return makeAttrs(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.ptapi.types.Attrs makeAttrs(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.ptapi.types.Attrs) factory.build(new nl.cwi.sen1.ptapi.types.Attrs(this, annos, head, tail));
  }

  public nl.cwi.sen1.ptapi.types.Attrs makeAttrs(nl.cwi.sen1.ptapi.types.Attr elem0, nl.cwi.sen1.ptapi.types.Attr elem1) {
    return makeAttrs(elem0, makeAttrs(elem1));
  }

  public nl.cwi.sen1.ptapi.types.Attrs makeAttrs(nl.cwi.sen1.ptapi.types.Attr elem0, nl.cwi.sen1.ptapi.types.Attr elem1, nl.cwi.sen1.ptapi.types.Attr elem2) {
    return makeAttrs(elem0, makeAttrs(elem1, elem2));
  }

  public nl.cwi.sen1.ptapi.types.Attrs makeAttrs(nl.cwi.sen1.ptapi.types.Attr elem0, nl.cwi.sen1.ptapi.types.Attr elem1, nl.cwi.sen1.ptapi.types.Attr elem2, nl.cwi.sen1.ptapi.types.Attr elem3) {
    return makeAttrs(elem0, makeAttrs(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.ptapi.types.Attrs makeAttrs(nl.cwi.sen1.ptapi.types.Attr elem0, nl.cwi.sen1.ptapi.types.Attr elem1, nl.cwi.sen1.ptapi.types.Attr elem2, nl.cwi.sen1.ptapi.types.Attr elem3, nl.cwi.sen1.ptapi.types.Attr elem4) {
    return makeAttrs(elem0, makeAttrs(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.ptapi.types.Attrs makeAttrs(nl.cwi.sen1.ptapi.types.Attr elem0, nl.cwi.sen1.ptapi.types.Attr elem1, nl.cwi.sen1.ptapi.types.Attr elem2, nl.cwi.sen1.ptapi.types.Attr elem3, nl.cwi.sen1.ptapi.types.Attr elem4, nl.cwi.sen1.ptapi.types.Attr elem5) {
    return makeAttrs(elem0, makeAttrs(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.ptapi.types.Attrs reverse(nl.cwi.sen1.ptapi.types.Attrs arg) {
    nl.cwi.sen1.ptapi.types.Attrs reversed = makeAttrs();
    while (!arg.isEmpty()) {
      reversed = makeAttrs(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.ptapi.types.Attrs concat(nl.cwi.sen1.ptapi.types.Attrs arg0, nl.cwi.sen1.ptapi.types.Attrs arg1) {
    nl.cwi.sen1.ptapi.types.Attrs result = arg1;

    for (nl.cwi.sen1.ptapi.types.Attrs list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeAttrs(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.ptapi.types.Attrs append(nl.cwi.sen1.ptapi.types.Attrs list, nl.cwi.sen1.ptapi.types.Attr elem) {
    return concat(list, makeAttrs(elem));
  }

  public nl.cwi.sen1.ptapi.types.Symbols makeSymbols() {
    return empty_Symbols;
  }

  public nl.cwi.sen1.ptapi.types.Symbols makeSymbols(nl.cwi.sen1.ptapi.types.Symbol elem) {
    return makeSymbols(elem, empty_Symbols);
  }

  public nl.cwi.sen1.ptapi.types.Symbols makeSymbols(nl.cwi.sen1.ptapi.types.Symbol head, nl.cwi.sen1.ptapi.types.Symbols tail) {
    return makeSymbols(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.ptapi.types.Symbols makeSymbols(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.ptapi.types.Symbols) factory.build(new nl.cwi.sen1.ptapi.types.Symbols(this, annos, head, tail));
  }

  public nl.cwi.sen1.ptapi.types.Symbols makeSymbols(nl.cwi.sen1.ptapi.types.Symbol elem0, nl.cwi.sen1.ptapi.types.Symbol elem1) {
    return makeSymbols(elem0, makeSymbols(elem1));
  }

  public nl.cwi.sen1.ptapi.types.Symbols makeSymbols(nl.cwi.sen1.ptapi.types.Symbol elem0, nl.cwi.sen1.ptapi.types.Symbol elem1, nl.cwi.sen1.ptapi.types.Symbol elem2) {
    return makeSymbols(elem0, makeSymbols(elem1, elem2));
  }

  public nl.cwi.sen1.ptapi.types.Symbols makeSymbols(nl.cwi.sen1.ptapi.types.Symbol elem0, nl.cwi.sen1.ptapi.types.Symbol elem1, nl.cwi.sen1.ptapi.types.Symbol elem2, nl.cwi.sen1.ptapi.types.Symbol elem3) {
    return makeSymbols(elem0, makeSymbols(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.ptapi.types.Symbols makeSymbols(nl.cwi.sen1.ptapi.types.Symbol elem0, nl.cwi.sen1.ptapi.types.Symbol elem1, nl.cwi.sen1.ptapi.types.Symbol elem2, nl.cwi.sen1.ptapi.types.Symbol elem3, nl.cwi.sen1.ptapi.types.Symbol elem4) {
    return makeSymbols(elem0, makeSymbols(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.ptapi.types.Symbols makeSymbols(nl.cwi.sen1.ptapi.types.Symbol elem0, nl.cwi.sen1.ptapi.types.Symbol elem1, nl.cwi.sen1.ptapi.types.Symbol elem2, nl.cwi.sen1.ptapi.types.Symbol elem3, nl.cwi.sen1.ptapi.types.Symbol elem4, nl.cwi.sen1.ptapi.types.Symbol elem5) {
    return makeSymbols(elem0, makeSymbols(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.ptapi.types.Symbols reverse(nl.cwi.sen1.ptapi.types.Symbols arg) {
    nl.cwi.sen1.ptapi.types.Symbols reversed = makeSymbols();
    while (!arg.isEmpty()) {
      reversed = makeSymbols(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.ptapi.types.Symbols concat(nl.cwi.sen1.ptapi.types.Symbols arg0, nl.cwi.sen1.ptapi.types.Symbols arg1) {
    nl.cwi.sen1.ptapi.types.Symbols result = arg1;

    for (nl.cwi.sen1.ptapi.types.Symbols list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeSymbols(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.ptapi.types.Symbols append(nl.cwi.sen1.ptapi.types.Symbols list, nl.cwi.sen1.ptapi.types.Symbol elem) {
    return concat(list, makeSymbols(elem));
  }

  public nl.cwi.sen1.ptapi.types.CharRanges makeCharRanges() {
    return empty_CharRanges;
  }

  public nl.cwi.sen1.ptapi.types.CharRanges makeCharRanges(nl.cwi.sen1.ptapi.types.CharRange elem) {
    return makeCharRanges(elem, empty_CharRanges);
  }

  public nl.cwi.sen1.ptapi.types.CharRanges makeCharRanges(nl.cwi.sen1.ptapi.types.CharRange head, nl.cwi.sen1.ptapi.types.CharRanges tail) {
    return makeCharRanges(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.ptapi.types.CharRanges makeCharRanges(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.ptapi.types.CharRanges) factory.build(new nl.cwi.sen1.ptapi.types.CharRanges(this, annos, head, tail));
  }

  public nl.cwi.sen1.ptapi.types.CharRanges makeCharRanges(nl.cwi.sen1.ptapi.types.CharRange elem0, nl.cwi.sen1.ptapi.types.CharRange elem1) {
    return makeCharRanges(elem0, makeCharRanges(elem1));
  }

  public nl.cwi.sen1.ptapi.types.CharRanges makeCharRanges(nl.cwi.sen1.ptapi.types.CharRange elem0, nl.cwi.sen1.ptapi.types.CharRange elem1, nl.cwi.sen1.ptapi.types.CharRange elem2) {
    return makeCharRanges(elem0, makeCharRanges(elem1, elem2));
  }

  public nl.cwi.sen1.ptapi.types.CharRanges makeCharRanges(nl.cwi.sen1.ptapi.types.CharRange elem0, nl.cwi.sen1.ptapi.types.CharRange elem1, nl.cwi.sen1.ptapi.types.CharRange elem2, nl.cwi.sen1.ptapi.types.CharRange elem3) {
    return makeCharRanges(elem0, makeCharRanges(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.ptapi.types.CharRanges makeCharRanges(nl.cwi.sen1.ptapi.types.CharRange elem0, nl.cwi.sen1.ptapi.types.CharRange elem1, nl.cwi.sen1.ptapi.types.CharRange elem2, nl.cwi.sen1.ptapi.types.CharRange elem3, nl.cwi.sen1.ptapi.types.CharRange elem4) {
    return makeCharRanges(elem0, makeCharRanges(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.ptapi.types.CharRanges makeCharRanges(nl.cwi.sen1.ptapi.types.CharRange elem0, nl.cwi.sen1.ptapi.types.CharRange elem1, nl.cwi.sen1.ptapi.types.CharRange elem2, nl.cwi.sen1.ptapi.types.CharRange elem3, nl.cwi.sen1.ptapi.types.CharRange elem4, nl.cwi.sen1.ptapi.types.CharRange elem5) {
    return makeCharRanges(elem0, makeCharRanges(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.ptapi.types.CharRanges reverse(nl.cwi.sen1.ptapi.types.CharRanges arg) {
    nl.cwi.sen1.ptapi.types.CharRanges reversed = makeCharRanges();
    while (!arg.isEmpty()) {
      reversed = makeCharRanges(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.ptapi.types.CharRanges concat(nl.cwi.sen1.ptapi.types.CharRanges arg0, nl.cwi.sen1.ptapi.types.CharRanges arg1) {
    nl.cwi.sen1.ptapi.types.CharRanges result = arg1;

    for (nl.cwi.sen1.ptapi.types.CharRanges list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeCharRanges(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.ptapi.types.CharRanges append(nl.cwi.sen1.ptapi.types.CharRanges list, nl.cwi.sen1.ptapi.types.CharRange elem) {
    return concat(list, makeCharRanges(elem));
  }

/*genTypeFromTermMethods*/
  public nl.cwi.sen1.ptapi.types.ParseTree ParseTreeFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.ptapi.types.ParseTree tmp;
    tmp = ParseTree_TopFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a ParseTree: " + trm);
  }

  public nl.cwi.sen1.ptapi.types.Tree TreeFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.ptapi.types.Tree tmp;
    tmp = Tree_ApplFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Tree_CycleFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Tree_AmbFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Tree_CharFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Tree: " + trm);
  }

  public nl.cwi.sen1.ptapi.types.Args ArgsFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.ptapi.types.Args result = makeArgs();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.ptapi.types.Tree elem = TreeFromTerm(list.getFirst());
            result = makeArgs(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a Args: " + trm);
  }

  public nl.cwi.sen1.ptapi.types.Production ProductionFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.ptapi.types.Production tmp;
    tmp = Production_DefaultFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Production_ListFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Production: " + trm);
  }

  public nl.cwi.sen1.ptapi.types.Attributes AttributesFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.ptapi.types.Attributes tmp;
    tmp = Attributes_NoAttrsFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attributes_AttrsFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Attributes: " + trm);
  }

  public nl.cwi.sen1.ptapi.types.Attrs AttrsFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.ptapi.types.Attrs result = makeAttrs();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.ptapi.types.Attr elem = AttrFromTerm(list.getFirst());
            result = makeAttrs(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a Attrs: " + trm);
  }

  public nl.cwi.sen1.ptapi.types.Attr AttrFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.ptapi.types.Attr tmp;
    tmp = Attr_AssocFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attr_TermFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attr_IdFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attr_BracketFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attr_RejectFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attr_PreferFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Attr_AvoidFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Attr: " + trm);
  }

  public nl.cwi.sen1.ptapi.types.Associativity AssociativityFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.ptapi.types.Associativity tmp;
    tmp = Associativity_LeftFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Associativity_RightFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Associativity_AssocFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Associativity_NonAssocFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Associativity: " + trm);
  }

  public nl.cwi.sen1.ptapi.types.Symbol SymbolFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.ptapi.types.Symbol tmp;
    tmp = Symbol_LitFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_CilitFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_CfFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_LexFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_EmptyFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_SeqFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_OptFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_AltFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_TupleFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_SortFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_IterPlusFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_IterStarFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_IterPlusSepFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_IterStarSepFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_IterNFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_IterSepNFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_FuncFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_ParameterizedSortFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_StrategyFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_VarSymFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_LayoutFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Symbol_CharClassFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Symbol: " + trm);
  }

  public nl.cwi.sen1.ptapi.types.Symbols SymbolsFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.ptapi.types.Symbols result = makeSymbols();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.ptapi.types.Symbol elem = SymbolFromTerm(list.getFirst());
            result = makeSymbols(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a Symbols: " + trm);
  }

  public nl.cwi.sen1.ptapi.types.CharRange CharRangeFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.ptapi.types.CharRange tmp;
    tmp = CharRange_CharacterFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = CharRange_RangeFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a CharRange: " + trm);
  }

  public nl.cwi.sen1.ptapi.types.CharRanges CharRangesFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.ptapi.types.CharRanges result = makeCharRanges();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.ptapi.types.CharRange elem = CharRangeFromTerm(list.getFirst());
            result = makeCharRanges(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a CharRanges: " + trm);
  }

/*genTypeFromMethods*/
  public nl.cwi.sen1.ptapi.types.ParseTree ParseTreeFromString(String str) {
    return ParseTreeFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ptapi.types.ParseTree ParseTreeFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ParseTreeFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.ptapi.types.Tree TreeFromString(String str) {
    return TreeFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ptapi.types.Tree TreeFromFile(java.io.InputStream stream) throws java.io.IOException {
    return TreeFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.ptapi.types.Args ArgsFromString(String str) {
    return ArgsFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ptapi.types.Args ArgsFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ArgsFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.ptapi.types.Production ProductionFromString(String str) {
    return ProductionFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ptapi.types.Production ProductionFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ProductionFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.ptapi.types.Attributes AttributesFromString(String str) {
    return AttributesFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ptapi.types.Attributes AttributesFromFile(java.io.InputStream stream) throws java.io.IOException {
    return AttributesFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.ptapi.types.Attrs AttrsFromString(String str) {
    return AttrsFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ptapi.types.Attrs AttrsFromFile(java.io.InputStream stream) throws java.io.IOException {
    return AttrsFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.ptapi.types.Attr AttrFromString(String str) {
    return AttrFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ptapi.types.Attr AttrFromFile(java.io.InputStream stream) throws java.io.IOException {
    return AttrFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.ptapi.types.Associativity AssociativityFromString(String str) {
    return AssociativityFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ptapi.types.Associativity AssociativityFromFile(java.io.InputStream stream) throws java.io.IOException {
    return AssociativityFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.ptapi.types.Symbol SymbolFromString(String str) {
    return SymbolFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ptapi.types.Symbol SymbolFromFile(java.io.InputStream stream) throws java.io.IOException {
    return SymbolFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.ptapi.types.Symbols SymbolsFromString(String str) {
    return SymbolsFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ptapi.types.Symbols SymbolsFromFile(java.io.InputStream stream) throws java.io.IOException {
    return SymbolsFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.ptapi.types.CharRange CharRangeFromString(String str) {
    return CharRangeFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ptapi.types.CharRange CharRangeFromFile(java.io.InputStream stream) throws java.io.IOException {
    return CharRangeFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.ptapi.types.CharRanges CharRangesFromString(String str) {
    return CharRangesFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ptapi.types.CharRanges CharRangesFromFile(java.io.InputStream stream) throws java.io.IOException {
    return CharRangesFromTerm(factory.readFromFile(stream));
  }

/*genForwardingAlternativeMethods*/
/*genForwardingMakeLists*/
/*genForwardingTypeFromTermMethods*/
/*TODOgenForwardingTypeFromMethods*/
  public static String charsToString(aterm.ATerm arg) {
    aterm.ATermList list = (aterm.ATermList) arg;
    StringBuffer str = new StringBuffer();

    for ( ; !list.isEmpty(); list = list.getNext()) {
      str.append((char) ((aterm.ATermInt) list.getFirst()).getInt());
    }

    return str.toString();
  }

  public static char charToByte(aterm.ATerm arg) {

      return((char) ((aterm.ATermInt) arg).getInt());
  }

  public aterm.ATerm stringToChars(String str) {
    int len = str.length();
    byte chars[] = str.getBytes();
    aterm.ATermList result = getPureFactory().makeList();

    for (int i = len - 1; i >= 0; i--) {
      result = result.insert(getPureFactory().makeInt(chars[i]));
    }

    return result;
  }

  public aterm.ATerm byteToChar(char ch) {
      return getPureFactory().makeInt(ch);
  }

}
