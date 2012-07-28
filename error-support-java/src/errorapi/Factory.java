package errorapi;

public class Factory {
  private aterm.pure.PureFactory factory;


  private aterm.AFun fun_StrChar_StrChar;
  private aterm.ATerm pattern_StrChar_StrChar;

  private aterm.AFun fun_StrCon_StrCon;
  private aterm.ATerm pattern_StrCon_StrCon;

  private aterm.AFun fun_NatCon_NatCon;
  private aterm.ATerm pattern_NatCon_NatCon;

  private aterm.AFun fun_Subject_Subject;
  private aterm.ATerm pattern_Subject_Subject;
  private aterm.AFun fun_Subject_Localized;
  private aterm.ATerm pattern_Subject_Localized;

  private aterm.AFun fun_Error_Info;
  private aterm.ATerm pattern_Error_Info;
  private aterm.AFun fun_Error_Warning;
  private aterm.ATerm pattern_Error_Warning;
  private aterm.AFun fun_Error_Error;
  private aterm.ATerm pattern_Error_Error;
  private aterm.AFun fun_Error_Fatal;
  private aterm.ATerm pattern_Error_Fatal;

  private aterm.AFun fun_Summary_Summary;
  private aterm.ATerm pattern_Summary_Summary;



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


  private errorapi.types.SubjectList empty_SubjectList;
  private errorapi.types.ErrorList empty_ErrorList;
  private errorapi.types.AreaAreas empty_AreaAreas;

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

    pattern_Subject_Subject = factory.parse("subject(<str>)");
    fun_Subject_Subject = factory.makeAFun("_Subject_subject", 1, false);

    pattern_Subject_Localized = factory.parse("localized(<str>,<term>)");
    fun_Subject_Localized = factory.makeAFun("_Subject_localized", 2, false);

    pattern_Error_Info = factory.parse("info(<str>,<term>)");
    fun_Error_Info = factory.makeAFun("_Error_info", 2, false);

    pattern_Error_Warning = factory.parse("warning(<str>,<term>)");
    fun_Error_Warning = factory.makeAFun("_Error_warning", 2, false);

    pattern_Error_Error = factory.parse("error(<str>,<term>)");
    fun_Error_Error = factory.makeAFun("_Error_error", 2, false);

    pattern_Error_Fatal = factory.parse("fatal(<str>,<term>)");
    fun_Error_Fatal = factory.makeAFun("_Error_fatal", 2, false);

    pattern_Summary_Summary = factory.parse("summary(<str>,<str>,<term>)");
    fun_Summary_Summary = factory.makeAFun("_Summary_summary", 3, false);

    empty_SubjectList = (errorapi.types.SubjectList) factory.build(new errorapi.types.SubjectList(this, factory.getEmpty(), null, null));
    empty_ErrorList = (errorapi.types.ErrorList) factory.build(new errorapi.types.ErrorList(this, factory.getEmpty(), null, null));
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

    empty_AreaAreas = (errorapi.types.AreaAreas) factory.build(new errorapi.types.AreaAreas(this, factory.getEmpty(), null, null));
  }

/*genAlternativeMethods*/
  public errorapi.types.strchar.StrChar makeStrChar_StrChar(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (errorapi.types.strchar.StrChar) factory.build( new errorapi.types.strchar.StrChar(this, annos, fun, args));
  }

  public errorapi.types.strchar.StrChar makeStrChar_StrChar(String _string) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_string, 0, true))};
    return makeStrChar_StrChar(fun_StrChar_StrChar, args, factory.getEmpty());
  }

  protected errorapi.types.StrChar StrChar_StrCharFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_StrChar_StrChar);

    if (children != null) {
      return makeStrChar_StrChar(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(errorapi.types.strchar.StrChar arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getString());
    return factory.make(pattern_StrChar_StrChar, args);
  }

  public errorapi.types.strcon.StrCon makeStrCon_StrCon(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (errorapi.types.strcon.StrCon) factory.build( new errorapi.types.strcon.StrCon(this, annos, fun, args));
  }

  public errorapi.types.strcon.StrCon makeStrCon_StrCon(String _string) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_string, 0, true))};
    return makeStrCon_StrCon(fun_StrCon_StrCon, args, factory.getEmpty());
  }

  protected errorapi.types.StrCon StrCon_StrConFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_StrCon_StrCon);

    if (children != null) {
      return makeStrCon_StrCon(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(errorapi.types.strcon.StrCon arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getString());
    return factory.make(pattern_StrCon_StrCon, args);
  }

  public errorapi.types.natcon.NatCon makeNatCon_NatCon(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (errorapi.types.natcon.NatCon) factory.build( new errorapi.types.natcon.NatCon(this, annos, fun, args));
  }

  public errorapi.types.natcon.NatCon makeNatCon_NatCon(String _string) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_string, 0, true))};
    return makeNatCon_NatCon(fun_NatCon_NatCon, args, factory.getEmpty());
  }

  protected errorapi.types.NatCon NatCon_NatConFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_NatCon_NatCon);

    if (children != null) {
      return makeNatCon_NatCon(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(errorapi.types.natcon.NatCon arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getString());
    return factory.make(pattern_NatCon_NatCon, args);
  }

  public errorapi.types.subject.Subject makeSubject_Subject(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (errorapi.types.subject.Subject) factory.build( new errorapi.types.subject.Subject(this, annos, fun, args));
  }

  public errorapi.types.subject.Subject makeSubject_Subject(String _description) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_description, 0, true))};
    return makeSubject_Subject(fun_Subject_Subject, args, factory.getEmpty());
  }

  protected errorapi.types.Subject Subject_SubjectFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Subject_Subject);

    if (children != null) {
      return makeSubject_Subject(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(errorapi.types.subject.Subject arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getDescription());
    return factory.make(pattern_Subject_Subject, args);
  }

  public errorapi.types.subject.Localized makeSubject_Localized(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (errorapi.types.subject.Localized) factory.build( new errorapi.types.subject.Localized(this, annos, fun, args));
  }

  public errorapi.types.subject.Localized makeSubject_Localized(String _description, errorapi.types.Location _Location) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_description, 0, true)), _Location};
    return makeSubject_Localized(fun_Subject_Localized, args, factory.getEmpty());
  }

  protected errorapi.types.Subject Subject_LocalizedFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Subject_Localized);

    if (children != null) {
      return makeSubject_Localized(
        (String) children.get(0),
        LocationFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(errorapi.types.subject.Localized arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getDescription());
    args.add(arg.getLocation().toTerm());
    return factory.make(pattern_Subject_Localized, args);
  }

  public errorapi.types.error.Info makeError_Info(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (errorapi.types.error.Info) factory.build( new errorapi.types.error.Info(this, annos, fun, args));
  }

  public errorapi.types.error.Info makeError_Info(String _description, errorapi.types.SubjectList _list) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_description, 0, true)), _list};
    return makeError_Info(fun_Error_Info, args, factory.getEmpty());
  }

  protected errorapi.types.Error Error_InfoFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Error_Info);

    if (children != null) {
      return makeError_Info(
        (String) children.get(0),
        SubjectListFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(errorapi.types.error.Info arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getDescription());
    args.add(arg.getList().toTerm());
    return factory.make(pattern_Error_Info, args);
  }

  public errorapi.types.error.Warning makeError_Warning(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (errorapi.types.error.Warning) factory.build( new errorapi.types.error.Warning(this, annos, fun, args));
  }

  public errorapi.types.error.Warning makeError_Warning(String _description, errorapi.types.SubjectList _list) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_description, 0, true)), _list};
    return makeError_Warning(fun_Error_Warning, args, factory.getEmpty());
  }

  protected errorapi.types.Error Error_WarningFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Error_Warning);

    if (children != null) {
      return makeError_Warning(
        (String) children.get(0),
        SubjectListFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(errorapi.types.error.Warning arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getDescription());
    args.add(arg.getList().toTerm());
    return factory.make(pattern_Error_Warning, args);
  }

  public errorapi.types.error.Error makeError_Error(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (errorapi.types.error.Error) factory.build( new errorapi.types.error.Error(this, annos, fun, args));
  }

  public errorapi.types.error.Error makeError_Error(String _description, errorapi.types.SubjectList _list) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_description, 0, true)), _list};
    return makeError_Error(fun_Error_Error, args, factory.getEmpty());
  }

  protected errorapi.types.Error Error_ErrorFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Error_Error);

    if (children != null) {
      return makeError_Error(
        (String) children.get(0),
        SubjectListFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(errorapi.types.error.Error arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getDescription());
    args.add(arg.getList().toTerm());
    return factory.make(pattern_Error_Error, args);
  }

  public errorapi.types.error.Fatal makeError_Fatal(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (errorapi.types.error.Fatal) factory.build( new errorapi.types.error.Fatal(this, annos, fun, args));
  }

  public errorapi.types.error.Fatal makeError_Fatal(String _description, errorapi.types.SubjectList _list) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_description, 0, true)), _list};
    return makeError_Fatal(fun_Error_Fatal, args, factory.getEmpty());
  }

  protected errorapi.types.Error Error_FatalFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Error_Fatal);

    if (children != null) {
      return makeError_Fatal(
        (String) children.get(0),
        SubjectListFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(errorapi.types.error.Fatal arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getDescription());
    args.add(arg.getList().toTerm());
    return factory.make(pattern_Error_Fatal, args);
  }

  public errorapi.types.summary.Summary makeSummary_Summary(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (errorapi.types.summary.Summary) factory.build( new errorapi.types.summary.Summary(this, annos, fun, args));
  }

  public errorapi.types.summary.Summary makeSummary_Summary(String _producer, String _id, errorapi.types.ErrorList _list) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_producer, 0, true)), factory.makeAppl(factory.makeAFun(_id, 0, true)), _list};
    return makeSummary_Summary(fun_Summary_Summary, args, factory.getEmpty());
  }

  protected errorapi.types.Summary Summary_SummaryFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Summary_Summary);

    if (children != null) {
      return makeSummary_Summary(
        (String) children.get(0),
        (String) children.get(1),
        ErrorListFromTerm((aterm.ATerm) children.get(2))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(errorapi.types.summary.Summary arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getProducer());
    args.add(arg.getId());
    args.add(arg.getList().toTerm());
    return factory.make(pattern_Summary_Summary, args);
  }

  public errorapi.types.location.File makeLocation_File(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (errorapi.types.location.File) factory.build( new errorapi.types.location.File(this, annos, fun, args));
  }

  public errorapi.types.location.File makeLocation_File(String _filename) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_filename, 0, true))};
    return makeLocation_File(fun_Location_File, args, factory.getEmpty());
  }

  protected errorapi.types.Location Location_FileFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Location_File);

    if (children != null) {
      return makeLocation_File(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(errorapi.types.location.File arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getFilename());
    return factory.make(pattern_Location_File, args);
  }

  public errorapi.types.location.Area makeLocation_Area(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (errorapi.types.location.Area) factory.build( new errorapi.types.location.Area(this, annos, fun, args));
  }

  public errorapi.types.location.Area makeLocation_Area(errorapi.types.Area _Area) {
    aterm.ATerm[] args = new aterm.ATerm[] {_Area};
    return makeLocation_Area(fun_Location_Area, args, factory.getEmpty());
  }

  protected errorapi.types.Location Location_AreaFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Location_Area);

    if (children != null) {
      return makeLocation_Area(
        AreaFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(errorapi.types.location.Area arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getArea().toTerm());
    return factory.make(pattern_Location_Area, args);
  }

  public errorapi.types.location.AreaInFile makeLocation_AreaInFile(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (errorapi.types.location.AreaInFile) factory.build( new errorapi.types.location.AreaInFile(this, annos, fun, args));
  }

  public errorapi.types.location.AreaInFile makeLocation_AreaInFile(String _filename, errorapi.types.Area _Area) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_filename, 0, true)), _Area};
    return makeLocation_AreaInFile(fun_Location_AreaInFile, args, factory.getEmpty());
  }

  protected errorapi.types.Location Location_AreaInFileFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Location_AreaInFile);

    if (children != null) {
      return makeLocation_AreaInFile(
        (String) children.get(0),
        AreaFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(errorapi.types.location.AreaInFile arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getFilename());
    args.add(arg.getArea().toTerm());
    return factory.make(pattern_Location_AreaInFile, args);
  }

  public errorapi.types.area.Area makeArea_Area(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (errorapi.types.area.Area) factory.build( new errorapi.types.area.Area(this, annos, fun, args));
  }

  public errorapi.types.area.Area makeArea_Area(int _beginLine, int _beginColumn, int _endLine, int _endColumn, int _offset, int _length) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeInt(_beginLine), factory.makeInt(_beginColumn), factory.makeInt(_endLine), factory.makeInt(_endColumn), factory.makeInt(_offset), factory.makeInt(_length)};
    return makeArea_Area(fun_Area_Area, args, factory.getEmpty());
  }

  protected errorapi.types.Area Area_AreaFromTerm(aterm.ATerm trm) {
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

  public aterm.ATerm toTerm(errorapi.types.area.Area arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(new Integer(arg.getBeginLine()));
    args.add(new Integer(arg.getBeginColumn()));
    args.add(new Integer(arg.getEndLine()));
    args.add(new Integer(arg.getEndColumn()));
    args.add(new Integer(arg.getOffset()));
    args.add(new Integer(arg.getLength()));
    return factory.make(pattern_Area_Area, args);
  }

  public errorapi.types.slice.Slice makeSlice_Slice(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (errorapi.types.slice.Slice) factory.build( new errorapi.types.slice.Slice(this, annos, fun, args));
  }

  public errorapi.types.slice.Slice makeSlice_Slice(String _id, errorapi.types.AreaAreas _areas) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_id, 0, true)), _areas};
    return makeSlice_Slice(fun_Slice_Slice, args, factory.getEmpty());
  }

  protected errorapi.types.Slice Slice_SliceFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Slice_Slice);

    if (children != null) {
      return makeSlice_Slice(
        (String) children.get(0),
        AreaAreasFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(errorapi.types.slice.Slice arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getId());
    args.add(arg.getAreas().toTerm());
    return factory.make(pattern_Slice_Slice, args);
  }

/*genMakeLists*/
  public errorapi.types.SubjectList makeSubjectList() {
    return empty_SubjectList;
  }

  public errorapi.types.SubjectList makeSubjectList(errorapi.types.Subject elem) {
    return makeSubjectList(elem, empty_SubjectList);
  }

  public errorapi.types.SubjectList makeSubjectList(errorapi.types.Subject head, errorapi.types.SubjectList tail) {
    return makeSubjectList(head, tail, factory.getEmpty());
  }

  public errorapi.types.SubjectList makeSubjectList(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (errorapi.types.SubjectList) factory.build(new errorapi.types.SubjectList(this, annos, head, tail));
  }

  public errorapi.types.SubjectList makeSubjectList(errorapi.types.Subject elem0, errorapi.types.Subject elem1) {
    return makeSubjectList(elem0, makeSubjectList(elem1));
  }

  public errorapi.types.SubjectList makeSubjectList(errorapi.types.Subject elem0, errorapi.types.Subject elem1, errorapi.types.Subject elem2) {
    return makeSubjectList(elem0, makeSubjectList(elem1, elem2));
  }

  public errorapi.types.SubjectList makeSubjectList(errorapi.types.Subject elem0, errorapi.types.Subject elem1, errorapi.types.Subject elem2, errorapi.types.Subject elem3) {
    return makeSubjectList(elem0, makeSubjectList(elem1, elem2, elem3));
  }

  public errorapi.types.SubjectList makeSubjectList(errorapi.types.Subject elem0, errorapi.types.Subject elem1, errorapi.types.Subject elem2, errorapi.types.Subject elem3, errorapi.types.Subject elem4) {
    return makeSubjectList(elem0, makeSubjectList(elem1, elem2, elem3, elem4));
  }

  public errorapi.types.SubjectList makeSubjectList(errorapi.types.Subject elem0, errorapi.types.Subject elem1, errorapi.types.Subject elem2, errorapi.types.Subject elem3, errorapi.types.Subject elem4, errorapi.types.Subject elem5) {
    return makeSubjectList(elem0, makeSubjectList(elem1, elem2, elem3, elem4, elem5));
  }

  public errorapi.types.SubjectList reverse(errorapi.types.SubjectList arg) {
    errorapi.types.SubjectList reversed = makeSubjectList();
    while (!arg.isEmpty()) {
      reversed = makeSubjectList(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public errorapi.types.SubjectList concat(errorapi.types.SubjectList arg0, errorapi.types.SubjectList arg1) {
    errorapi.types.SubjectList result = arg1;

    for (errorapi.types.SubjectList list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeSubjectList(list.getHead(), result);
    }

    return result;
  }

  public errorapi.types.SubjectList append(errorapi.types.SubjectList list, errorapi.types.Subject elem) {
    return concat(list, makeSubjectList(elem));
  }

  public errorapi.types.ErrorList makeErrorList() {
    return empty_ErrorList;
  }

  public errorapi.types.ErrorList makeErrorList(errorapi.types.Error elem) {
    return makeErrorList(elem, empty_ErrorList);
  }

  public errorapi.types.ErrorList makeErrorList(errorapi.types.Error head, errorapi.types.ErrorList tail) {
    return makeErrorList(head, tail, factory.getEmpty());
  }

  public errorapi.types.ErrorList makeErrorList(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (errorapi.types.ErrorList) factory.build(new errorapi.types.ErrorList(this, annos, head, tail));
  }

  public errorapi.types.ErrorList makeErrorList(errorapi.types.Error elem0, errorapi.types.Error elem1) {
    return makeErrorList(elem0, makeErrorList(elem1));
  }

  public errorapi.types.ErrorList makeErrorList(errorapi.types.Error elem0, errorapi.types.Error elem1, errorapi.types.Error elem2) {
    return makeErrorList(elem0, makeErrorList(elem1, elem2));
  }

  public errorapi.types.ErrorList makeErrorList(errorapi.types.Error elem0, errorapi.types.Error elem1, errorapi.types.Error elem2, errorapi.types.Error elem3) {
    return makeErrorList(elem0, makeErrorList(elem1, elem2, elem3));
  }

  public errorapi.types.ErrorList makeErrorList(errorapi.types.Error elem0, errorapi.types.Error elem1, errorapi.types.Error elem2, errorapi.types.Error elem3, errorapi.types.Error elem4) {
    return makeErrorList(elem0, makeErrorList(elem1, elem2, elem3, elem4));
  }

  public errorapi.types.ErrorList makeErrorList(errorapi.types.Error elem0, errorapi.types.Error elem1, errorapi.types.Error elem2, errorapi.types.Error elem3, errorapi.types.Error elem4, errorapi.types.Error elem5) {
    return makeErrorList(elem0, makeErrorList(elem1, elem2, elem3, elem4, elem5));
  }

  public errorapi.types.ErrorList reverse(errorapi.types.ErrorList arg) {
    errorapi.types.ErrorList reversed = makeErrorList();
    while (!arg.isEmpty()) {
      reversed = makeErrorList(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public errorapi.types.ErrorList concat(errorapi.types.ErrorList arg0, errorapi.types.ErrorList arg1) {
    errorapi.types.ErrorList result = arg1;

    for (errorapi.types.ErrorList list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeErrorList(list.getHead(), result);
    }

    return result;
  }

  public errorapi.types.ErrorList append(errorapi.types.ErrorList list, errorapi.types.Error elem) {
    return concat(list, makeErrorList(elem));
  }

  public errorapi.types.AreaAreas makeAreaAreas() {
    return empty_AreaAreas;
  }

  public errorapi.types.AreaAreas makeAreaAreas(errorapi.types.Area elem) {
    return makeAreaAreas(elem, empty_AreaAreas);
  }

  public errorapi.types.AreaAreas makeAreaAreas(errorapi.types.Area head, errorapi.types.AreaAreas tail) {
    return makeAreaAreas(head, tail, factory.getEmpty());
  }

  public errorapi.types.AreaAreas makeAreaAreas(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (errorapi.types.AreaAreas) factory.build(new errorapi.types.AreaAreas(this, annos, head, tail));
  }

  public errorapi.types.AreaAreas makeAreaAreas(errorapi.types.Area elem0, errorapi.types.Area elem1) {
    return makeAreaAreas(elem0, makeAreaAreas(elem1));
  }

  public errorapi.types.AreaAreas makeAreaAreas(errorapi.types.Area elem0, errorapi.types.Area elem1, errorapi.types.Area elem2) {
    return makeAreaAreas(elem0, makeAreaAreas(elem1, elem2));
  }

  public errorapi.types.AreaAreas makeAreaAreas(errorapi.types.Area elem0, errorapi.types.Area elem1, errorapi.types.Area elem2, errorapi.types.Area elem3) {
    return makeAreaAreas(elem0, makeAreaAreas(elem1, elem2, elem3));
  }

  public errorapi.types.AreaAreas makeAreaAreas(errorapi.types.Area elem0, errorapi.types.Area elem1, errorapi.types.Area elem2, errorapi.types.Area elem3, errorapi.types.Area elem4) {
    return makeAreaAreas(elem0, makeAreaAreas(elem1, elem2, elem3, elem4));
  }

  public errorapi.types.AreaAreas makeAreaAreas(errorapi.types.Area elem0, errorapi.types.Area elem1, errorapi.types.Area elem2, errorapi.types.Area elem3, errorapi.types.Area elem4, errorapi.types.Area elem5) {
    return makeAreaAreas(elem0, makeAreaAreas(elem1, elem2, elem3, elem4, elem5));
  }

  public errorapi.types.AreaAreas reverse(errorapi.types.AreaAreas arg) {
    errorapi.types.AreaAreas reversed = makeAreaAreas();
    while (!arg.isEmpty()) {
      reversed = makeAreaAreas(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public errorapi.types.AreaAreas concat(errorapi.types.AreaAreas arg0, errorapi.types.AreaAreas arg1) {
    errorapi.types.AreaAreas result = arg1;

    for (errorapi.types.AreaAreas list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeAreaAreas(list.getHead(), result);
    }

    return result;
  }

  public errorapi.types.AreaAreas append(errorapi.types.AreaAreas list, errorapi.types.Area elem) {
    return concat(list, makeAreaAreas(elem));
  }

/*genTypeFromTermMethods*/
  public errorapi.types.StrChar StrCharFromTerm(aterm.ATerm trm) {
    errorapi.types.StrChar tmp;
    tmp = StrChar_StrCharFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a StrChar: " + trm);
  }

  public errorapi.types.StrCon StrConFromTerm(aterm.ATerm trm) {
    errorapi.types.StrCon tmp;
    tmp = StrCon_StrConFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a StrCon: " + trm);
  }

  public errorapi.types.NatCon NatConFromTerm(aterm.ATerm trm) {
    errorapi.types.NatCon tmp;
    tmp = NatCon_NatConFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a NatCon: " + trm);
  }

  public errorapi.types.Subject SubjectFromTerm(aterm.ATerm trm) {
    errorapi.types.Subject tmp;
    tmp = Subject_SubjectFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Subject_LocalizedFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Subject: " + trm);
  }

  public errorapi.types.Error ErrorFromTerm(aterm.ATerm trm) {
    errorapi.types.Error tmp;
    tmp = Error_InfoFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Error_WarningFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Error_ErrorFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Error_FatalFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Error: " + trm);
  }

  public errorapi.types.Summary SummaryFromTerm(aterm.ATerm trm) {
    errorapi.types.Summary tmp;
    tmp = Summary_SummaryFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Summary: " + trm);
  }

  public errorapi.types.SubjectList SubjectListFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        errorapi.types.SubjectList result = makeSubjectList();
        for (; !list.isEmpty(); list = list.getNext()) {
           errorapi.types.Subject elem = SubjectFromTerm(list.getFirst());
            result = makeSubjectList(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a SubjectList: " + trm);
  }

  public errorapi.types.ErrorList ErrorListFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        errorapi.types.ErrorList result = makeErrorList();
        for (; !list.isEmpty(); list = list.getNext()) {
           errorapi.types.Error elem = ErrorFromTerm(list.getFirst());
            result = makeErrorList(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a ErrorList: " + trm);
  }

  public errorapi.types.Location LocationFromTerm(aterm.ATerm trm) {
    errorapi.types.Location tmp;
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

  public errorapi.types.Area AreaFromTerm(aterm.ATerm trm) {
    errorapi.types.Area tmp;
    tmp = Area_AreaFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Area: " + trm);
  }

  public errorapi.types.Slice SliceFromTerm(aterm.ATerm trm) {
    errorapi.types.Slice tmp;
    tmp = Slice_SliceFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Slice: " + trm);
  }

  public errorapi.types.AreaAreas AreaAreasFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        errorapi.types.AreaAreas result = makeAreaAreas();
        for (; !list.isEmpty(); list = list.getNext()) {
           errorapi.types.Area elem = AreaFromTerm(list.getFirst());
            result = makeAreaAreas(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a AreaAreas: " + trm);
  }

/*genTypeFromMethods*/
  public errorapi.types.StrChar StrCharFromString(String str) {
    return StrCharFromTerm(factory.parse(str));
  }

  public errorapi.types.StrChar StrCharFromFile(java.io.InputStream stream) throws java.io.IOException {
    return StrCharFromTerm(factory.readFromFile(stream));
  }

  public errorapi.types.StrCon StrConFromString(String str) {
    return StrConFromTerm(factory.parse(str));
  }

  public errorapi.types.StrCon StrConFromFile(java.io.InputStream stream) throws java.io.IOException {
    return StrConFromTerm(factory.readFromFile(stream));
  }

  public errorapi.types.NatCon NatConFromString(String str) {
    return NatConFromTerm(factory.parse(str));
  }

  public errorapi.types.NatCon NatConFromFile(java.io.InputStream stream) throws java.io.IOException {
    return NatConFromTerm(factory.readFromFile(stream));
  }

  public errorapi.types.Subject SubjectFromString(String str) {
    return SubjectFromTerm(factory.parse(str));
  }

  public errorapi.types.Subject SubjectFromFile(java.io.InputStream stream) throws java.io.IOException {
    return SubjectFromTerm(factory.readFromFile(stream));
  }

  public errorapi.types.Error ErrorFromString(String str) {
    return ErrorFromTerm(factory.parse(str));
  }

  public errorapi.types.Error ErrorFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ErrorFromTerm(factory.readFromFile(stream));
  }

  public errorapi.types.Summary SummaryFromString(String str) {
    return SummaryFromTerm(factory.parse(str));
  }

  public errorapi.types.Summary SummaryFromFile(java.io.InputStream stream) throws java.io.IOException {
    return SummaryFromTerm(factory.readFromFile(stream));
  }

  public errorapi.types.SubjectList SubjectListFromString(String str) {
    return SubjectListFromTerm(factory.parse(str));
  }

  public errorapi.types.SubjectList SubjectListFromFile(java.io.InputStream stream) throws java.io.IOException {
    return SubjectListFromTerm(factory.readFromFile(stream));
  }

  public errorapi.types.ErrorList ErrorListFromString(String str) {
    return ErrorListFromTerm(factory.parse(str));
  }

  public errorapi.types.ErrorList ErrorListFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ErrorListFromTerm(factory.readFromFile(stream));
  }

  public errorapi.types.Location LocationFromString(String str) {
    return LocationFromTerm(factory.parse(str));
  }

  public errorapi.types.Location LocationFromFile(java.io.InputStream stream) throws java.io.IOException {
    return LocationFromTerm(factory.readFromFile(stream));
  }

  public errorapi.types.Area AreaFromString(String str) {
    return AreaFromTerm(factory.parse(str));
  }

  public errorapi.types.Area AreaFromFile(java.io.InputStream stream) throws java.io.IOException {
    return AreaFromTerm(factory.readFromFile(stream));
  }

  public errorapi.types.Slice SliceFromString(String str) {
    return SliceFromTerm(factory.parse(str));
  }

  public errorapi.types.Slice SliceFromFile(java.io.InputStream stream) throws java.io.IOException {
    return SliceFromTerm(factory.readFromFile(stream));
  }

  public errorapi.types.AreaAreas AreaAreasFromString(String str) {
    return AreaAreasFromTerm(factory.parse(str));
  }

  public errorapi.types.AreaAreas AreaAreasFromFile(java.io.InputStream stream) throws java.io.IOException {
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
