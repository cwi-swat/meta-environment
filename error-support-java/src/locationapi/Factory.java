package locationapi;

public class Factory {
  private aterm.pure.PureFactory factory;


  private aterm.AFun fun_StrChar_StrChar;
  private aterm.ATerm pattern_StrChar_StrChar;

  private aterm.AFun fun_StrCon_StrCon;
  private aterm.ATerm pattern_StrCon_StrCon;

  private aterm.AFun fun_NatCon_NatCon;
  private aterm.ATerm pattern_NatCon_NatCon;

  private aterm.AFun fun_Location_File;
  private aterm.ATerm pattern_Location_File;
  private aterm.AFun fun_Location_Area;
  private aterm.ATerm pattern_Location_Area;
  private aterm.AFun fun_Location_AreaInFile;
  private aterm.ATerm pattern_Location_AreaInFile;

  private aterm.AFun fun_Area_Area;
  private aterm.ATerm pattern_Area_Area;

  private aterm.AFun fun_Slice_Slice;
  private aterm.ATerm pattern_Slice_Slice;


  private locationapi.types.AreaAreas empty_AreaAreas;

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

    pattern_StrChar_StrChar = factory.parse("<str>");
    fun_StrChar_StrChar = factory.makeAFun("_StrChar_StrChar", 1, false);

    pattern_StrCon_StrCon = factory.parse("<str>");
    fun_StrCon_StrCon = factory.makeAFun("_StrCon_StrCon", 1, false);

    pattern_NatCon_NatCon = factory.parse("<str>");
    fun_NatCon_NatCon = factory.makeAFun("_NatCon_NatCon", 1, false);

    pattern_Location_File = factory.parse("file(<str>)");
    fun_Location_File = factory.makeAFun("_Location_file", 1, false);

    pattern_Location_Area = factory.parse("area(<term>)");
    fun_Location_Area = factory.makeAFun("_Location_area", 1, false);

    pattern_Location_AreaInFile = factory.parse("area-in-file(<str>,<term>)");
    fun_Location_AreaInFile = factory.makeAFun("_Location_area-in-file", 2, false);

    pattern_Area_Area = factory.parse("area(<int>,<int>,<int>,<int>,<int>,<int>)");
    fun_Area_Area = factory.makeAFun("_Area_area", 6, false);

    pattern_Slice_Slice = factory.parse("slice(<str>,<term>)");
    fun_Slice_Slice = factory.makeAFun("_Slice_slice", 2, false);

    empty_AreaAreas = (locationapi.types.AreaAreas) factory.build(new locationapi.types.AreaAreas(this, factory.getEmpty(), null, null));
  }

/*genAlternativeMethods*/
  public locationapi.types.strchar.StrChar makeStrChar_StrChar(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (locationapi.types.strchar.StrChar) factory.build( new locationapi.types.strchar.StrChar(this, annos, fun, args));
  }

  public locationapi.types.strchar.StrChar makeStrChar_StrChar(String _string) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_string, 0, true))};
    return makeStrChar_StrChar(fun_StrChar_StrChar, args, factory.getEmpty());
  }

  protected locationapi.types.StrChar StrChar_StrCharFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_StrChar_StrChar);

    if (children != null) {
      return makeStrChar_StrChar(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(locationapi.types.strchar.StrChar arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getString());
    return factory.make(pattern_StrChar_StrChar, args);
  }

  public locationapi.types.strcon.StrCon makeStrCon_StrCon(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (locationapi.types.strcon.StrCon) factory.build( new locationapi.types.strcon.StrCon(this, annos, fun, args));
  }

  public locationapi.types.strcon.StrCon makeStrCon_StrCon(String _string) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_string, 0, true))};
    return makeStrCon_StrCon(fun_StrCon_StrCon, args, factory.getEmpty());
  }

  protected locationapi.types.StrCon StrCon_StrConFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_StrCon_StrCon);

    if (children != null) {
      return makeStrCon_StrCon(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(locationapi.types.strcon.StrCon arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getString());
    return factory.make(pattern_StrCon_StrCon, args);
  }

  public locationapi.types.natcon.NatCon makeNatCon_NatCon(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (locationapi.types.natcon.NatCon) factory.build( new locationapi.types.natcon.NatCon(this, annos, fun, args));
  }

  public locationapi.types.natcon.NatCon makeNatCon_NatCon(String _string) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_string, 0, true))};
    return makeNatCon_NatCon(fun_NatCon_NatCon, args, factory.getEmpty());
  }

  protected locationapi.types.NatCon NatCon_NatConFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_NatCon_NatCon);

    if (children != null) {
      return makeNatCon_NatCon(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(locationapi.types.natcon.NatCon arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getString());
    return factory.make(pattern_NatCon_NatCon, args);
  }

  public locationapi.types.location.File makeLocation_File(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (locationapi.types.location.File) factory.build( new locationapi.types.location.File(this, annos, fun, args));
  }

  public locationapi.types.location.File makeLocation_File(String _filename) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_filename, 0, true))};
    return makeLocation_File(fun_Location_File, args, factory.getEmpty());
  }

  protected locationapi.types.Location Location_FileFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Location_File);

    if (children != null) {
      return makeLocation_File(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(locationapi.types.location.File arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getFilename());
    return factory.make(pattern_Location_File, args);
  }

  public locationapi.types.location.Area makeLocation_Area(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (locationapi.types.location.Area) factory.build( new locationapi.types.location.Area(this, annos, fun, args));
  }

  public locationapi.types.location.Area makeLocation_Area(locationapi.types.Area _Area) {
    aterm.ATerm[] args = new aterm.ATerm[] {_Area};
    return makeLocation_Area(fun_Location_Area, args, factory.getEmpty());
  }

  protected locationapi.types.Location Location_AreaFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Location_Area);

    if (children != null) {
      return makeLocation_Area(
        AreaFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(locationapi.types.location.Area arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getArea().toTerm());
    return factory.make(pattern_Location_Area, args);
  }

  public locationapi.types.location.AreaInFile makeLocation_AreaInFile(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (locationapi.types.location.AreaInFile) factory.build( new locationapi.types.location.AreaInFile(this, annos, fun, args));
  }

  public locationapi.types.location.AreaInFile makeLocation_AreaInFile(String _filename, locationapi.types.Area _Area) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_filename, 0, true)), _Area};
    return makeLocation_AreaInFile(fun_Location_AreaInFile, args, factory.getEmpty());
  }

  protected locationapi.types.Location Location_AreaInFileFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Location_AreaInFile);

    if (children != null) {
      return makeLocation_AreaInFile(
        (String) children.get(0),
        AreaFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(locationapi.types.location.AreaInFile arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getFilename());
    args.add(arg.getArea().toTerm());
    return factory.make(pattern_Location_AreaInFile, args);
  }

  public locationapi.types.area.Area makeArea_Area(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (locationapi.types.area.Area) factory.build( new locationapi.types.area.Area(this, annos, fun, args));
  }

  public locationapi.types.area.Area makeArea_Area(int _beginLine, int _beginColumn, int _endLine, int _endColumn, int _offset, int _length) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeInt(_beginLine), factory.makeInt(_beginColumn), factory.makeInt(_endLine), factory.makeInt(_endColumn), factory.makeInt(_offset), factory.makeInt(_length)};
    return makeArea_Area(fun_Area_Area, args, factory.getEmpty());
  }

  protected locationapi.types.Area Area_AreaFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Area_Area);

    if (children != null) {
      return makeArea_Area(
        ((Integer) children.get(0)).intValue(),
        ((Integer) children.get(1)).intValue(),
        ((Integer) children.get(2)).intValue(),
        ((Integer) children.get(3)).intValue(),
        ((Integer) children.get(4)).intValue(),
        ((Integer) children.get(5)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(locationapi.types.area.Area arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(new Integer(arg.getBeginLine()));
    args.add(new Integer(arg.getBeginColumn()));
    args.add(new Integer(arg.getEndLine()));
    args.add(new Integer(arg.getEndColumn()));
    args.add(new Integer(arg.getOffset()));
    args.add(new Integer(arg.getLength()));
    return factory.make(pattern_Area_Area, args);
  }

  public locationapi.types.slice.Slice makeSlice_Slice(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (locationapi.types.slice.Slice) factory.build( new locationapi.types.slice.Slice(this, annos, fun, args));
  }

  public locationapi.types.slice.Slice makeSlice_Slice(String _id, locationapi.types.AreaAreas _areas) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_id, 0, true)), _areas};
    return makeSlice_Slice(fun_Slice_Slice, args, factory.getEmpty());
  }

  protected locationapi.types.Slice Slice_SliceFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Slice_Slice);

    if (children != null) {
      return makeSlice_Slice(
        (String) children.get(0),
        AreaAreasFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(locationapi.types.slice.Slice arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getId());
    args.add(arg.getAreas().toTerm());
    return factory.make(pattern_Slice_Slice, args);
  }

/*genMakeLists*/
  public locationapi.types.AreaAreas makeAreaAreas() {
    return empty_AreaAreas;
  }

  public locationapi.types.AreaAreas makeAreaAreas(locationapi.types.Area elem) {
    return makeAreaAreas(elem, empty_AreaAreas);
  }

  public locationapi.types.AreaAreas makeAreaAreas(locationapi.types.Area head, locationapi.types.AreaAreas tail) {
    return makeAreaAreas(head, tail, factory.getEmpty());
  }

  public locationapi.types.AreaAreas makeAreaAreas(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (locationapi.types.AreaAreas) factory.build(new locationapi.types.AreaAreas(this, annos, head, tail));
  }

  public locationapi.types.AreaAreas makeAreaAreas(locationapi.types.Area elem0, locationapi.types.Area elem1) {
    return makeAreaAreas(elem0, makeAreaAreas(elem1));
  }

  public locationapi.types.AreaAreas makeAreaAreas(locationapi.types.Area elem0, locationapi.types.Area elem1, locationapi.types.Area elem2) {
    return makeAreaAreas(elem0, makeAreaAreas(elem1, elem2));
  }

  public locationapi.types.AreaAreas makeAreaAreas(locationapi.types.Area elem0, locationapi.types.Area elem1, locationapi.types.Area elem2, locationapi.types.Area elem3) {
    return makeAreaAreas(elem0, makeAreaAreas(elem1, elem2, elem3));
  }

  public locationapi.types.AreaAreas makeAreaAreas(locationapi.types.Area elem0, locationapi.types.Area elem1, locationapi.types.Area elem2, locationapi.types.Area elem3, locationapi.types.Area elem4) {
    return makeAreaAreas(elem0, makeAreaAreas(elem1, elem2, elem3, elem4));
  }

  public locationapi.types.AreaAreas makeAreaAreas(locationapi.types.Area elem0, locationapi.types.Area elem1, locationapi.types.Area elem2, locationapi.types.Area elem3, locationapi.types.Area elem4, locationapi.types.Area elem5) {
    return makeAreaAreas(elem0, makeAreaAreas(elem1, elem2, elem3, elem4, elem5));
  }

  public locationapi.types.AreaAreas reverse(locationapi.types.AreaAreas arg) {
    locationapi.types.AreaAreas reversed = makeAreaAreas();
    while (!arg.isEmpty()) {
      reversed = makeAreaAreas(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public locationapi.types.AreaAreas concat(locationapi.types.AreaAreas arg0, locationapi.types.AreaAreas arg1) {
    locationapi.types.AreaAreas result = arg1;

    for (locationapi.types.AreaAreas list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeAreaAreas(list.getHead(), result);
    }

    return result;
  }

  public locationapi.types.AreaAreas append(locationapi.types.AreaAreas list, locationapi.types.Area elem) {
    return concat(list, makeAreaAreas(elem));
  }

/*genTypeFromTermMethods*/
  public locationapi.types.StrChar StrCharFromTerm(aterm.ATerm trm) {
    locationapi.types.StrChar tmp;
    tmp = StrChar_StrCharFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a StrChar: " + trm);
  }

  public locationapi.types.StrCon StrConFromTerm(aterm.ATerm trm) {
    locationapi.types.StrCon tmp;
    tmp = StrCon_StrConFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a StrCon: " + trm);
  }

  public locationapi.types.NatCon NatConFromTerm(aterm.ATerm trm) {
    locationapi.types.NatCon tmp;
    tmp = NatCon_NatConFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a NatCon: " + trm);
  }

  public locationapi.types.Location LocationFromTerm(aterm.ATerm trm) {
    locationapi.types.Location tmp;
    tmp = Location_FileFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Location_AreaFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Location_AreaInFileFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Location: " + trm);
  }

  public locationapi.types.Area AreaFromTerm(aterm.ATerm trm) {
    locationapi.types.Area tmp;
    tmp = Area_AreaFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Area: " + trm);
  }

  public locationapi.types.Slice SliceFromTerm(aterm.ATerm trm) {
    locationapi.types.Slice tmp;
    tmp = Slice_SliceFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Slice: " + trm);
  }

  public locationapi.types.AreaAreas AreaAreasFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        locationapi.types.AreaAreas result = makeAreaAreas();
        for (; !list.isEmpty(); list = list.getNext()) {
           locationapi.types.Area elem = AreaFromTerm(list.getFirst());
            result = makeAreaAreas(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a AreaAreas: " + trm);
  }

/*genTypeFromMethods*/
  public locationapi.types.StrChar StrCharFromString(String str) {
    return StrCharFromTerm(factory.parse(str));
  }

  public locationapi.types.StrChar StrCharFromFile(java.io.InputStream stream) throws java.io.IOException {
    return StrCharFromTerm(factory.readFromFile(stream));
  }

  public locationapi.types.StrCon StrConFromString(String str) {
    return StrConFromTerm(factory.parse(str));
  }

  public locationapi.types.StrCon StrConFromFile(java.io.InputStream stream) throws java.io.IOException {
    return StrConFromTerm(factory.readFromFile(stream));
  }

  public locationapi.types.NatCon NatConFromString(String str) {
    return NatConFromTerm(factory.parse(str));
  }

  public locationapi.types.NatCon NatConFromFile(java.io.InputStream stream) throws java.io.IOException {
    return NatConFromTerm(factory.readFromFile(stream));
  }

  public locationapi.types.Location LocationFromString(String str) {
    return LocationFromTerm(factory.parse(str));
  }

  public locationapi.types.Location LocationFromFile(java.io.InputStream stream) throws java.io.IOException {
    return LocationFromTerm(factory.readFromFile(stream));
  }

  public locationapi.types.Area AreaFromString(String str) {
    return AreaFromTerm(factory.parse(str));
  }

  public locationapi.types.Area AreaFromFile(java.io.InputStream stream) throws java.io.IOException {
    return AreaFromTerm(factory.readFromFile(stream));
  }

  public locationapi.types.Slice SliceFromString(String str) {
    return SliceFromTerm(factory.parse(str));
  }

  public locationapi.types.Slice SliceFromFile(java.io.InputStream stream) throws java.io.IOException {
    return SliceFromTerm(factory.readFromFile(stream));
  }

  public locationapi.types.AreaAreas AreaAreasFromString(String str) {
    return AreaAreasFromTerm(factory.parse(str));
  }

  public locationapi.types.AreaAreas AreaAreasFromFile(java.io.InputStream stream) throws java.io.IOException {
    return AreaAreasFromTerm(factory.readFromFile(stream));
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
