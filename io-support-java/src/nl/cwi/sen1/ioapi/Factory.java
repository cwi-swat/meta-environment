package nl.cwi.sen1.ioapi;

public class Factory {
  private aterm.pure.PureFactory factory;


  private aterm.AFun fun_File_File;
  private aterm.ATerm pattern_File_File;

  private aterm.AFun fun_Path_Absolute;
  private aterm.ATerm pattern_Path_Absolute;
  private aterm.AFun fun_Path_Relative;
  private aterm.ATerm pattern_Path_Relative;

  private aterm.AFun fun_Segment_Segment;
  private aterm.ATerm pattern_Segment_Segment;


  private aterm.AFun fun_StrChar_StrChar;
  private aterm.ATerm pattern_StrChar_StrChar;

  private aterm.AFun fun_StrCon_StrCon;
  private aterm.ATerm pattern_StrCon_StrCon;

  private nl.cwi.sen1.ioapi.types.SegmentList empty_SegmentList;

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

    pattern_File_File = factory.parse("file(<term>,<str>,<str>)");
    fun_File_File = factory.makeAFun("_File_file", 3, false);

    pattern_Path_Absolute = factory.parse("absolute(<term>)");
    fun_Path_Absolute = factory.makeAFun("_Path_absolute", 1, false);

    pattern_Path_Relative = factory.parse("relative(<term>)");
    fun_Path_Relative = factory.makeAFun("_Path_relative", 1, false);

    pattern_Segment_Segment = factory.parse("segment(<str>)");
    fun_Segment_Segment = factory.makeAFun("_Segment_segment", 1, false);

    empty_SegmentList = (nl.cwi.sen1.ioapi.types.SegmentList) factory.build(new nl.cwi.sen1.ioapi.types.SegmentList(this, factory.getEmpty(), null, null));
    pattern_StrChar_StrChar = factory.parse("<str>");
    fun_StrChar_StrChar = factory.makeAFun("_StrChar_StrChar", 1, false);

    pattern_StrCon_StrCon = factory.parse("<str>");
    fun_StrCon_StrCon = factory.makeAFun("_StrCon_StrCon", 1, false);

  }

/*genAlternativeMethods*/
  public nl.cwi.sen1.ioapi.types.file.File makeFile_File(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ioapi.types.file.File) factory.build( new nl.cwi.sen1.ioapi.types.file.File(this, annos, fun, args));
  }

  public nl.cwi.sen1.ioapi.types.file.File makeFile_File(nl.cwi.sen1.ioapi.types.Path _path, String _name, String _extension) {
    aterm.ATerm[] args = new aterm.ATerm[] {_path, factory.makeAppl(factory.makeAFun(_name, 0, true)), factory.makeAppl(factory.makeAFun(_extension, 0, true))};
    return makeFile_File(fun_File_File, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ioapi.types.File File_FileFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_File_File);

    if (children != null) {
      return makeFile_File(
        PathFromTerm((aterm.ATerm) children.get(0)),
        (String) children.get(1),
        (String) children.get(2)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ioapi.types.file.File arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getPath().toTerm());
    args.add(arg.getName());
    args.add(arg.getExtension());
    return factory.make(pattern_File_File, args);
  }

  public nl.cwi.sen1.ioapi.types.path.Absolute makePath_Absolute(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ioapi.types.path.Absolute) factory.build( new nl.cwi.sen1.ioapi.types.path.Absolute(this, annos, fun, args));
  }

  public nl.cwi.sen1.ioapi.types.path.Absolute makePath_Absolute(nl.cwi.sen1.ioapi.types.SegmentList _list) {
    aterm.ATerm[] args = new aterm.ATerm[] {_list};
    return makePath_Absolute(fun_Path_Absolute, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ioapi.types.Path Path_AbsoluteFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Path_Absolute);

    if (children != null) {
      return makePath_Absolute(
        SegmentListFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ioapi.types.path.Absolute arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getList().toTerm());
    return factory.make(pattern_Path_Absolute, args);
  }

  public nl.cwi.sen1.ioapi.types.path.Relative makePath_Relative(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ioapi.types.path.Relative) factory.build( new nl.cwi.sen1.ioapi.types.path.Relative(this, annos, fun, args));
  }

  public nl.cwi.sen1.ioapi.types.path.Relative makePath_Relative(nl.cwi.sen1.ioapi.types.SegmentList _list) {
    aterm.ATerm[] args = new aterm.ATerm[] {_list};
    return makePath_Relative(fun_Path_Relative, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ioapi.types.Path Path_RelativeFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Path_Relative);

    if (children != null) {
      return makePath_Relative(
        SegmentListFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ioapi.types.path.Relative arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getList().toTerm());
    return factory.make(pattern_Path_Relative, args);
  }

  public nl.cwi.sen1.ioapi.types.segment.Segment makeSegment_Segment(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ioapi.types.segment.Segment) factory.build( new nl.cwi.sen1.ioapi.types.segment.Segment(this, annos, fun, args));
  }

  public nl.cwi.sen1.ioapi.types.segment.Segment makeSegment_Segment(String _name) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_name, 0, true))};
    return makeSegment_Segment(fun_Segment_Segment, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ioapi.types.Segment Segment_SegmentFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Segment_Segment);

    if (children != null) {
      return makeSegment_Segment(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ioapi.types.segment.Segment arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getName());
    return factory.make(pattern_Segment_Segment, args);
  }

  public nl.cwi.sen1.ioapi.types.strchar.StrChar makeStrChar_StrChar(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ioapi.types.strchar.StrChar) factory.build( new nl.cwi.sen1.ioapi.types.strchar.StrChar(this, annos, fun, args));
  }

  public nl.cwi.sen1.ioapi.types.strchar.StrChar makeStrChar_StrChar(String _string) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_string, 0, true))};
    return makeStrChar_StrChar(fun_StrChar_StrChar, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ioapi.types.StrChar StrChar_StrCharFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_StrChar_StrChar);

    if (children != null) {
      return makeStrChar_StrChar(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ioapi.types.strchar.StrChar arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getString());
    return factory.make(pattern_StrChar_StrChar, args);
  }

  public nl.cwi.sen1.ioapi.types.strcon.StrCon makeStrCon_StrCon(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.ioapi.types.strcon.StrCon) factory.build( new nl.cwi.sen1.ioapi.types.strcon.StrCon(this, annos, fun, args));
  }

  public nl.cwi.sen1.ioapi.types.strcon.StrCon makeStrCon_StrCon(String _string) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_string, 0, true))};
    return makeStrCon_StrCon(fun_StrCon_StrCon, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.ioapi.types.StrCon StrCon_StrConFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_StrCon_StrCon);

    if (children != null) {
      return makeStrCon_StrCon(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.ioapi.types.strcon.StrCon arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getString());
    return factory.make(pattern_StrCon_StrCon, args);
  }

/*genMakeLists*/
  public nl.cwi.sen1.ioapi.types.SegmentList makeSegmentList() {
    return empty_SegmentList;
  }

  public nl.cwi.sen1.ioapi.types.SegmentList makeSegmentList(nl.cwi.sen1.ioapi.types.Segment elem) {
    return makeSegmentList(elem, empty_SegmentList);
  }

  public nl.cwi.sen1.ioapi.types.SegmentList makeSegmentList(nl.cwi.sen1.ioapi.types.Segment head, nl.cwi.sen1.ioapi.types.SegmentList tail) {
    return makeSegmentList(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.ioapi.types.SegmentList makeSegmentList(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.ioapi.types.SegmentList) factory.build(new nl.cwi.sen1.ioapi.types.SegmentList(this, annos, head, tail));
  }

  public nl.cwi.sen1.ioapi.types.SegmentList makeSegmentList(nl.cwi.sen1.ioapi.types.Segment elem0, nl.cwi.sen1.ioapi.types.Segment elem1) {
    return makeSegmentList(elem0, makeSegmentList(elem1));
  }

  public nl.cwi.sen1.ioapi.types.SegmentList makeSegmentList(nl.cwi.sen1.ioapi.types.Segment elem0, nl.cwi.sen1.ioapi.types.Segment elem1, nl.cwi.sen1.ioapi.types.Segment elem2) {
    return makeSegmentList(elem0, makeSegmentList(elem1, elem2));
  }

  public nl.cwi.sen1.ioapi.types.SegmentList makeSegmentList(nl.cwi.sen1.ioapi.types.Segment elem0, nl.cwi.sen1.ioapi.types.Segment elem1, nl.cwi.sen1.ioapi.types.Segment elem2, nl.cwi.sen1.ioapi.types.Segment elem3) {
    return makeSegmentList(elem0, makeSegmentList(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.ioapi.types.SegmentList makeSegmentList(nl.cwi.sen1.ioapi.types.Segment elem0, nl.cwi.sen1.ioapi.types.Segment elem1, nl.cwi.sen1.ioapi.types.Segment elem2, nl.cwi.sen1.ioapi.types.Segment elem3, nl.cwi.sen1.ioapi.types.Segment elem4) {
    return makeSegmentList(elem0, makeSegmentList(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.ioapi.types.SegmentList makeSegmentList(nl.cwi.sen1.ioapi.types.Segment elem0, nl.cwi.sen1.ioapi.types.Segment elem1, nl.cwi.sen1.ioapi.types.Segment elem2, nl.cwi.sen1.ioapi.types.Segment elem3, nl.cwi.sen1.ioapi.types.Segment elem4, nl.cwi.sen1.ioapi.types.Segment elem5) {
    return makeSegmentList(elem0, makeSegmentList(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.ioapi.types.SegmentList reverse(nl.cwi.sen1.ioapi.types.SegmentList arg) {
    nl.cwi.sen1.ioapi.types.SegmentList reversed = makeSegmentList();
    while (!arg.isEmpty()) {
      reversed = makeSegmentList(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.ioapi.types.SegmentList concat(nl.cwi.sen1.ioapi.types.SegmentList arg0, nl.cwi.sen1.ioapi.types.SegmentList arg1) {
    nl.cwi.sen1.ioapi.types.SegmentList result = arg1;

    for (nl.cwi.sen1.ioapi.types.SegmentList list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeSegmentList(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.ioapi.types.SegmentList append(nl.cwi.sen1.ioapi.types.SegmentList list, nl.cwi.sen1.ioapi.types.Segment elem) {
    return concat(list, makeSegmentList(elem));
  }

/*genTypeFromTermMethods*/
  public nl.cwi.sen1.ioapi.types.File FileFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.ioapi.types.File tmp;
    tmp = File_FileFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a File: " + trm);
  }

  public nl.cwi.sen1.ioapi.types.Path PathFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.ioapi.types.Path tmp;
    tmp = Path_AbsoluteFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Path_RelativeFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Path: " + trm);
  }

  public nl.cwi.sen1.ioapi.types.Segment SegmentFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.ioapi.types.Segment tmp;
    tmp = Segment_SegmentFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Segment: " + trm);
  }

  public nl.cwi.sen1.ioapi.types.SegmentList SegmentListFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.ioapi.types.SegmentList result = makeSegmentList();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.ioapi.types.Segment elem = SegmentFromTerm(list.getFirst());
            result = makeSegmentList(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a SegmentList: " + trm);
  }

  public nl.cwi.sen1.ioapi.types.StrChar StrCharFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.ioapi.types.StrChar tmp;
    tmp = StrChar_StrCharFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a StrChar: " + trm);
  }

  public nl.cwi.sen1.ioapi.types.StrCon StrConFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.ioapi.types.StrCon tmp;
    tmp = StrCon_StrConFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a StrCon: " + trm);
  }

/*genTypeFromMethods*/
  public nl.cwi.sen1.ioapi.types.File FileFromString(String str) {
    return FileFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ioapi.types.File FileFromFile(java.io.InputStream stream) throws java.io.IOException {
    return FileFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.ioapi.types.Path PathFromString(String str) {
    return PathFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ioapi.types.Path PathFromFile(java.io.InputStream stream) throws java.io.IOException {
    return PathFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.ioapi.types.Segment SegmentFromString(String str) {
    return SegmentFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ioapi.types.Segment SegmentFromFile(java.io.InputStream stream) throws java.io.IOException {
    return SegmentFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.ioapi.types.SegmentList SegmentListFromString(String str) {
    return SegmentListFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ioapi.types.SegmentList SegmentListFromFile(java.io.InputStream stream) throws java.io.IOException {
    return SegmentListFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.ioapi.types.StrChar StrCharFromString(String str) {
    return StrCharFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ioapi.types.StrChar StrCharFromFile(java.io.InputStream stream) throws java.io.IOException {
    return StrCharFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.ioapi.types.StrCon StrConFromString(String str) {
    return StrConFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.ioapi.types.StrCon StrConFromFile(java.io.InputStream stream) throws java.io.IOException {
    return StrConFromTerm(factory.readFromFile(stream));
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
