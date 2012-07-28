package nl.cwi.sen1.moduleapi;

public class Factory {
  private aterm.pure.PureFactory factory;


  private aterm.AFun fun_Modules_Default;
  private aterm.ATerm pattern_Modules_Default;

  private aterm.AFun fun_Module_Module;
  private aterm.ATerm pattern_Module_Module;

  private aterm.AFun fun_ModuleId_ModuleId;
  private aterm.ATerm pattern_ModuleId_ModuleId;

  private aterm.AFun fun_Attribute_Attribute;
  private aterm.ATerm pattern_Attribute_Attribute;

  private aterm.AFun fun_TableEntry_TableEntry;
  private aterm.ATerm pattern_TableEntry_TableEntry;

  private aterm.AFun fun_Dependencies_Dependencies;
  private aterm.ATerm pattern_Dependencies_Dependencies;

  private aterm.AFun fun_Dependency_Dependency;
  private aterm.ATerm pattern_Dependency_Dependency;

  private aterm.AFun fun_AttributeMap_AttributeMap;
  private aterm.ATerm pattern_AttributeMap_AttributeMap;

  private aterm.AFun fun_ModuleAttribute_ModuleAttribute;
  private aterm.ATerm pattern_ModuleAttribute_ModuleAttribute;







  private aterm.AFun fun_NatCon_NatCon;
  private aterm.ATerm pattern_NatCon_NatCon;

  private nl.cwi.sen1.moduleapi.types.ModuleList empty_ModuleList;
  private nl.cwi.sen1.moduleapi.types.AttributeStore empty_AttributeStore;
  private nl.cwi.sen1.moduleapi.types.TableEntryTable empty_TableEntryTable;
  private nl.cwi.sen1.moduleapi.types.DependencyList empty_DependencyList;
  private nl.cwi.sen1.moduleapi.types.ModuleIdList empty_ModuleIdList;
  private nl.cwi.sen1.moduleapi.types.ModuleAttributeList empty_ModuleAttributeList;

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

    pattern_Modules_Default = factory.parse("Default(<term>)");
    fun_Modules_Default = factory.makeAFun("_Modules_Default", 1, false);

    pattern_Module_Module = factory.parse("module(<term>,<term>)");
    fun_Module_Module = factory.makeAFun("_Module_module", 2, false);

    pattern_ModuleId_ModuleId = factory.parse("module-id(<int>)");
    fun_ModuleId_ModuleId = factory.makeAFun("_ModuleId_module-id", 1, false);

    pattern_Attribute_Attribute = factory.parse("attribute(<term>,<term>)");
    fun_Attribute_Attribute = factory.makeAFun("_Attribute_attribute", 2, false);

    pattern_TableEntry_TableEntry = factory.parse("table-entry(<term>,<term>)");
    fun_TableEntry_TableEntry = factory.makeAFun("_TableEntry_table-entry", 2, false);

    pattern_Dependencies_Dependencies = factory.parse("dependencies(<term>)");
    fun_Dependencies_Dependencies = factory.makeAFun("_Dependencies_dependencies", 1, false);

    pattern_Dependency_Dependency = factory.parse("dependency(<term>,<term>)");
    fun_Dependency_Dependency = factory.makeAFun("_Dependency_dependency", 2, false);

    pattern_AttributeMap_AttributeMap = factory.parse("attribute-map(<term>)");
    fun_AttributeMap_AttributeMap = factory.makeAFun("_AttributeMap_attribute-map", 1, false);

    pattern_ModuleAttribute_ModuleAttribute = factory.parse("module-attribute(<term>,<term>)");
    fun_ModuleAttribute_ModuleAttribute = factory.makeAFun("_ModuleAttribute_module-attribute", 2, false);

    empty_ModuleList = (nl.cwi.sen1.moduleapi.types.ModuleList) factory.build(new nl.cwi.sen1.moduleapi.types.ModuleList(this, factory.getEmpty(), null, null));
    empty_AttributeStore = (nl.cwi.sen1.moduleapi.types.AttributeStore) factory.build(new nl.cwi.sen1.moduleapi.types.AttributeStore(this, factory.getEmpty(), null, null));
    empty_TableEntryTable = (nl.cwi.sen1.moduleapi.types.TableEntryTable) factory.build(new nl.cwi.sen1.moduleapi.types.TableEntryTable(this, factory.getEmpty(), null, null));
    empty_DependencyList = (nl.cwi.sen1.moduleapi.types.DependencyList) factory.build(new nl.cwi.sen1.moduleapi.types.DependencyList(this, factory.getEmpty(), null, null));
    empty_ModuleIdList = (nl.cwi.sen1.moduleapi.types.ModuleIdList) factory.build(new nl.cwi.sen1.moduleapi.types.ModuleIdList(this, factory.getEmpty(), null, null));
    empty_ModuleAttributeList = (nl.cwi.sen1.moduleapi.types.ModuleAttributeList) factory.build(new nl.cwi.sen1.moduleapi.types.ModuleAttributeList(this, factory.getEmpty(), null, null));
    pattern_NatCon_NatCon = factory.parse("<str>");
    fun_NatCon_NatCon = factory.makeAFun("_NatCon_NatCon", 1, false);

  }

/*genAlternativeMethods*/
  public nl.cwi.sen1.moduleapi.types.modules.Default makeModules_Default(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.moduleapi.types.modules.Default) factory.build( new nl.cwi.sen1.moduleapi.types.modules.Default(this, annos, fun, args));
  }

  public nl.cwi.sen1.moduleapi.types.modules.Default makeModules_Default(nl.cwi.sen1.moduleapi.types.ModuleList _list) {
    aterm.ATerm[] args = new aterm.ATerm[] {_list};
    return makeModules_Default(fun_Modules_Default, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.moduleapi.types.Modules Modules_DefaultFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Modules_Default);

    if (children != null) {
      return makeModules_Default(
        ModuleListFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.moduleapi.types.modules.Default arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getList().toTerm());
    return factory.make(pattern_Modules_Default, args);
  }

  public nl.cwi.sen1.moduleapi.types.module.Module makeModule_Module(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.moduleapi.types.module.Module) factory.build( new nl.cwi.sen1.moduleapi.types.module.Module(this, annos, fun, args));
  }

  public nl.cwi.sen1.moduleapi.types.module.Module makeModule_Module(nl.cwi.sen1.moduleapi.types.ModuleId _id, nl.cwi.sen1.moduleapi.types.AttributeStore _store) {
    aterm.ATerm[] args = new aterm.ATerm[] {_id, _store};
    return makeModule_Module(fun_Module_Module, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.moduleapi.types.Module Module_ModuleFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Module_Module);

    if (children != null) {
      return makeModule_Module(
        ModuleIdFromTerm((aterm.ATerm) children.get(0)),
        AttributeStoreFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.moduleapi.types.module.Module arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getId().toTerm());
    args.add(arg.getStore().toTerm());
    return factory.make(pattern_Module_Module, args);
  }

  public nl.cwi.sen1.moduleapi.types.moduleid.ModuleId makeModuleId_ModuleId(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.moduleapi.types.moduleid.ModuleId) factory.build( new nl.cwi.sen1.moduleapi.types.moduleid.ModuleId(this, annos, fun, args));
  }

  public nl.cwi.sen1.moduleapi.types.moduleid.ModuleId makeModuleId_ModuleId(int _id) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeInt(_id)};
    return makeModuleId_ModuleId(fun_ModuleId_ModuleId, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.moduleapi.types.ModuleId ModuleId_ModuleIdFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_ModuleId_ModuleId);

    if (children != null) {
      return makeModuleId_ModuleId(
        ((Integer) children.get(0)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.moduleapi.types.moduleid.ModuleId arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(new Integer(arg.getId()));
    return factory.make(pattern_ModuleId_ModuleId, args);
  }

  public nl.cwi.sen1.moduleapi.types.attribute.Attribute makeAttribute_Attribute(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.moduleapi.types.attribute.Attribute) factory.build( new nl.cwi.sen1.moduleapi.types.attribute.Attribute(this, annos, fun, args));
  }

  public nl.cwi.sen1.moduleapi.types.attribute.Attribute makeAttribute_Attribute(aterm.ATerm _namespace, nl.cwi.sen1.moduleapi.types.TableEntryTable _table) {
    aterm.ATerm[] args = new aterm.ATerm[] {_namespace, _table};
    return makeAttribute_Attribute(fun_Attribute_Attribute, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.moduleapi.types.Attribute Attribute_AttributeFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Attribute_Attribute);

    if (children != null) {
      return makeAttribute_Attribute(
        (aterm.ATerm) children.get(0),
        TableEntryTableFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.moduleapi.types.attribute.Attribute arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getNamespace());
    args.add(arg.getTable().toTerm());
    return factory.make(pattern_Attribute_Attribute, args);
  }

  public nl.cwi.sen1.moduleapi.types.tableentry.TableEntry makeTableEntry_TableEntry(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.moduleapi.types.tableentry.TableEntry) factory.build( new nl.cwi.sen1.moduleapi.types.tableentry.TableEntry(this, annos, fun, args));
  }

  public nl.cwi.sen1.moduleapi.types.tableentry.TableEntry makeTableEntry_TableEntry(aterm.ATerm _key, aterm.ATerm _value) {
    aterm.ATerm[] args = new aterm.ATerm[] {_key, _value};
    return makeTableEntry_TableEntry(fun_TableEntry_TableEntry, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.moduleapi.types.TableEntry TableEntry_TableEntryFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_TableEntry_TableEntry);

    if (children != null) {
      return makeTableEntry_TableEntry(
        (aterm.ATerm) children.get(0),
        (aterm.ATerm) children.get(1)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.moduleapi.types.tableentry.TableEntry arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getKey());
    args.add(arg.getValue());
    return factory.make(pattern_TableEntry_TableEntry, args);
  }

  public nl.cwi.sen1.moduleapi.types.dependencies.Dependencies makeDependencies_Dependencies(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.moduleapi.types.dependencies.Dependencies) factory.build( new nl.cwi.sen1.moduleapi.types.dependencies.Dependencies(this, annos, fun, args));
  }

  public nl.cwi.sen1.moduleapi.types.dependencies.Dependencies makeDependencies_Dependencies(nl.cwi.sen1.moduleapi.types.DependencyList _list) {
    aterm.ATerm[] args = new aterm.ATerm[] {_list};
    return makeDependencies_Dependencies(fun_Dependencies_Dependencies, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.moduleapi.types.Dependencies Dependencies_DependenciesFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Dependencies_Dependencies);

    if (children != null) {
      return makeDependencies_Dependencies(
        DependencyListFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.moduleapi.types.dependencies.Dependencies arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getList().toTerm());
    return factory.make(pattern_Dependencies_Dependencies, args);
  }

  public nl.cwi.sen1.moduleapi.types.dependency.Dependency makeDependency_Dependency(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.moduleapi.types.dependency.Dependency) factory.build( new nl.cwi.sen1.moduleapi.types.dependency.Dependency(this, annos, fun, args));
  }

  public nl.cwi.sen1.moduleapi.types.dependency.Dependency makeDependency_Dependency(nl.cwi.sen1.moduleapi.types.ModuleId _from, nl.cwi.sen1.moduleapi.types.ModuleIdList _list) {
    aterm.ATerm[] args = new aterm.ATerm[] {_from, _list};
    return makeDependency_Dependency(fun_Dependency_Dependency, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.moduleapi.types.Dependency Dependency_DependencyFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Dependency_Dependency);

    if (children != null) {
      return makeDependency_Dependency(
        ModuleIdFromTerm((aterm.ATerm) children.get(0)),
        ModuleIdListFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.moduleapi.types.dependency.Dependency arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getFrom().toTerm());
    args.add(arg.getList().toTerm());
    return factory.make(pattern_Dependency_Dependency, args);
  }

  public nl.cwi.sen1.moduleapi.types.attributemap.AttributeMap makeAttributeMap_AttributeMap(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.moduleapi.types.attributemap.AttributeMap) factory.build( new nl.cwi.sen1.moduleapi.types.attributemap.AttributeMap(this, annos, fun, args));
  }

  public nl.cwi.sen1.moduleapi.types.attributemap.AttributeMap makeAttributeMap_AttributeMap(nl.cwi.sen1.moduleapi.types.ModuleAttributeList _list) {
    aterm.ATerm[] args = new aterm.ATerm[] {_list};
    return makeAttributeMap_AttributeMap(fun_AttributeMap_AttributeMap, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.moduleapi.types.AttributeMap AttributeMap_AttributeMapFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_AttributeMap_AttributeMap);

    if (children != null) {
      return makeAttributeMap_AttributeMap(
        ModuleAttributeListFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.moduleapi.types.attributemap.AttributeMap arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getList().toTerm());
    return factory.make(pattern_AttributeMap_AttributeMap, args);
  }

  public nl.cwi.sen1.moduleapi.types.moduleattribute.ModuleAttribute makeModuleAttribute_ModuleAttribute(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.moduleapi.types.moduleattribute.ModuleAttribute) factory.build( new nl.cwi.sen1.moduleapi.types.moduleattribute.ModuleAttribute(this, annos, fun, args));
  }

  public nl.cwi.sen1.moduleapi.types.moduleattribute.ModuleAttribute makeModuleAttribute_ModuleAttribute(nl.cwi.sen1.moduleapi.types.ModuleId _id, aterm.ATerm _attribute) {
    aterm.ATerm[] args = new aterm.ATerm[] {_id, _attribute};
    return makeModuleAttribute_ModuleAttribute(fun_ModuleAttribute_ModuleAttribute, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.moduleapi.types.ModuleAttribute ModuleAttribute_ModuleAttributeFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_ModuleAttribute_ModuleAttribute);

    if (children != null) {
      return makeModuleAttribute_ModuleAttribute(
        ModuleIdFromTerm((aterm.ATerm) children.get(0)),
        (aterm.ATerm) children.get(1)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.moduleapi.types.moduleattribute.ModuleAttribute arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getId().toTerm());
    args.add(arg.getAttribute());
    return factory.make(pattern_ModuleAttribute_ModuleAttribute, args);
  }

  public nl.cwi.sen1.moduleapi.types.natcon.NatCon makeNatCon_NatCon(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.moduleapi.types.natcon.NatCon) factory.build( new nl.cwi.sen1.moduleapi.types.natcon.NatCon(this, annos, fun, args));
  }

  public nl.cwi.sen1.moduleapi.types.natcon.NatCon makeNatCon_NatCon(String _string) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_string, 0, true))};
    return makeNatCon_NatCon(fun_NatCon_NatCon, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.moduleapi.types.NatCon NatCon_NatConFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_NatCon_NatCon);

    if (children != null) {
      return makeNatCon_NatCon(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.moduleapi.types.natcon.NatCon arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getString());
    return factory.make(pattern_NatCon_NatCon, args);
  }

/*genMakeLists*/
  public nl.cwi.sen1.moduleapi.types.ModuleList makeModuleList() {
    return empty_ModuleList;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleList makeModuleList(nl.cwi.sen1.moduleapi.types.Module elem) {
    return makeModuleList(elem, empty_ModuleList);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleList makeModuleList(nl.cwi.sen1.moduleapi.types.Module head, nl.cwi.sen1.moduleapi.types.ModuleList tail) {
    return makeModuleList(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.moduleapi.types.ModuleList makeModuleList(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.moduleapi.types.ModuleList) factory.build(new nl.cwi.sen1.moduleapi.types.ModuleList(this, annos, head, tail));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleList makeModuleList(nl.cwi.sen1.moduleapi.types.Module elem0, nl.cwi.sen1.moduleapi.types.Module elem1) {
    return makeModuleList(elem0, makeModuleList(elem1));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleList makeModuleList(nl.cwi.sen1.moduleapi.types.Module elem0, nl.cwi.sen1.moduleapi.types.Module elem1, nl.cwi.sen1.moduleapi.types.Module elem2) {
    return makeModuleList(elem0, makeModuleList(elem1, elem2));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleList makeModuleList(nl.cwi.sen1.moduleapi.types.Module elem0, nl.cwi.sen1.moduleapi.types.Module elem1, nl.cwi.sen1.moduleapi.types.Module elem2, nl.cwi.sen1.moduleapi.types.Module elem3) {
    return makeModuleList(elem0, makeModuleList(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleList makeModuleList(nl.cwi.sen1.moduleapi.types.Module elem0, nl.cwi.sen1.moduleapi.types.Module elem1, nl.cwi.sen1.moduleapi.types.Module elem2, nl.cwi.sen1.moduleapi.types.Module elem3, nl.cwi.sen1.moduleapi.types.Module elem4) {
    return makeModuleList(elem0, makeModuleList(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleList makeModuleList(nl.cwi.sen1.moduleapi.types.Module elem0, nl.cwi.sen1.moduleapi.types.Module elem1, nl.cwi.sen1.moduleapi.types.Module elem2, nl.cwi.sen1.moduleapi.types.Module elem3, nl.cwi.sen1.moduleapi.types.Module elem4, nl.cwi.sen1.moduleapi.types.Module elem5) {
    return makeModuleList(elem0, makeModuleList(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleList reverse(nl.cwi.sen1.moduleapi.types.ModuleList arg) {
    nl.cwi.sen1.moduleapi.types.ModuleList reversed = makeModuleList();
    while (!arg.isEmpty()) {
      reversed = makeModuleList(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleList concat(nl.cwi.sen1.moduleapi.types.ModuleList arg0, nl.cwi.sen1.moduleapi.types.ModuleList arg1) {
    nl.cwi.sen1.moduleapi.types.ModuleList result = arg1;

    for (nl.cwi.sen1.moduleapi.types.ModuleList list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeModuleList(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleList append(nl.cwi.sen1.moduleapi.types.ModuleList list, nl.cwi.sen1.moduleapi.types.Module elem) {
    return concat(list, makeModuleList(elem));
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore makeAttributeStore() {
    return empty_AttributeStore;
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore makeAttributeStore(nl.cwi.sen1.moduleapi.types.Attribute elem) {
    return makeAttributeStore(elem, empty_AttributeStore);
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore makeAttributeStore(nl.cwi.sen1.moduleapi.types.Attribute head, nl.cwi.sen1.moduleapi.types.AttributeStore tail) {
    return makeAttributeStore(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore makeAttributeStore(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.moduleapi.types.AttributeStore) factory.build(new nl.cwi.sen1.moduleapi.types.AttributeStore(this, annos, head, tail));
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore makeAttributeStore(nl.cwi.sen1.moduleapi.types.Attribute elem0, nl.cwi.sen1.moduleapi.types.Attribute elem1) {
    return makeAttributeStore(elem0, makeAttributeStore(elem1));
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore makeAttributeStore(nl.cwi.sen1.moduleapi.types.Attribute elem0, nl.cwi.sen1.moduleapi.types.Attribute elem1, nl.cwi.sen1.moduleapi.types.Attribute elem2) {
    return makeAttributeStore(elem0, makeAttributeStore(elem1, elem2));
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore makeAttributeStore(nl.cwi.sen1.moduleapi.types.Attribute elem0, nl.cwi.sen1.moduleapi.types.Attribute elem1, nl.cwi.sen1.moduleapi.types.Attribute elem2, nl.cwi.sen1.moduleapi.types.Attribute elem3) {
    return makeAttributeStore(elem0, makeAttributeStore(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore makeAttributeStore(nl.cwi.sen1.moduleapi.types.Attribute elem0, nl.cwi.sen1.moduleapi.types.Attribute elem1, nl.cwi.sen1.moduleapi.types.Attribute elem2, nl.cwi.sen1.moduleapi.types.Attribute elem3, nl.cwi.sen1.moduleapi.types.Attribute elem4) {
    return makeAttributeStore(elem0, makeAttributeStore(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore makeAttributeStore(nl.cwi.sen1.moduleapi.types.Attribute elem0, nl.cwi.sen1.moduleapi.types.Attribute elem1, nl.cwi.sen1.moduleapi.types.Attribute elem2, nl.cwi.sen1.moduleapi.types.Attribute elem3, nl.cwi.sen1.moduleapi.types.Attribute elem4, nl.cwi.sen1.moduleapi.types.Attribute elem5) {
    return makeAttributeStore(elem0, makeAttributeStore(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore reverse(nl.cwi.sen1.moduleapi.types.AttributeStore arg) {
    nl.cwi.sen1.moduleapi.types.AttributeStore reversed = makeAttributeStore();
    while (!arg.isEmpty()) {
      reversed = makeAttributeStore(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore concat(nl.cwi.sen1.moduleapi.types.AttributeStore arg0, nl.cwi.sen1.moduleapi.types.AttributeStore arg1) {
    nl.cwi.sen1.moduleapi.types.AttributeStore result = arg1;

    for (nl.cwi.sen1.moduleapi.types.AttributeStore list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeAttributeStore(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore append(nl.cwi.sen1.moduleapi.types.AttributeStore list, nl.cwi.sen1.moduleapi.types.Attribute elem) {
    return concat(list, makeAttributeStore(elem));
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable makeTableEntryTable() {
    return empty_TableEntryTable;
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable makeTableEntryTable(nl.cwi.sen1.moduleapi.types.TableEntry elem) {
    return makeTableEntryTable(elem, empty_TableEntryTable);
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable makeTableEntryTable(nl.cwi.sen1.moduleapi.types.TableEntry head, nl.cwi.sen1.moduleapi.types.TableEntryTable tail) {
    return makeTableEntryTable(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable makeTableEntryTable(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.moduleapi.types.TableEntryTable) factory.build(new nl.cwi.sen1.moduleapi.types.TableEntryTable(this, annos, head, tail));
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable makeTableEntryTable(nl.cwi.sen1.moduleapi.types.TableEntry elem0, nl.cwi.sen1.moduleapi.types.TableEntry elem1) {
    return makeTableEntryTable(elem0, makeTableEntryTable(elem1));
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable makeTableEntryTable(nl.cwi.sen1.moduleapi.types.TableEntry elem0, nl.cwi.sen1.moduleapi.types.TableEntry elem1, nl.cwi.sen1.moduleapi.types.TableEntry elem2) {
    return makeTableEntryTable(elem0, makeTableEntryTable(elem1, elem2));
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable makeTableEntryTable(nl.cwi.sen1.moduleapi.types.TableEntry elem0, nl.cwi.sen1.moduleapi.types.TableEntry elem1, nl.cwi.sen1.moduleapi.types.TableEntry elem2, nl.cwi.sen1.moduleapi.types.TableEntry elem3) {
    return makeTableEntryTable(elem0, makeTableEntryTable(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable makeTableEntryTable(nl.cwi.sen1.moduleapi.types.TableEntry elem0, nl.cwi.sen1.moduleapi.types.TableEntry elem1, nl.cwi.sen1.moduleapi.types.TableEntry elem2, nl.cwi.sen1.moduleapi.types.TableEntry elem3, nl.cwi.sen1.moduleapi.types.TableEntry elem4) {
    return makeTableEntryTable(elem0, makeTableEntryTable(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable makeTableEntryTable(nl.cwi.sen1.moduleapi.types.TableEntry elem0, nl.cwi.sen1.moduleapi.types.TableEntry elem1, nl.cwi.sen1.moduleapi.types.TableEntry elem2, nl.cwi.sen1.moduleapi.types.TableEntry elem3, nl.cwi.sen1.moduleapi.types.TableEntry elem4, nl.cwi.sen1.moduleapi.types.TableEntry elem5) {
    return makeTableEntryTable(elem0, makeTableEntryTable(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable reverse(nl.cwi.sen1.moduleapi.types.TableEntryTable arg) {
    nl.cwi.sen1.moduleapi.types.TableEntryTable reversed = makeTableEntryTable();
    while (!arg.isEmpty()) {
      reversed = makeTableEntryTable(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable concat(nl.cwi.sen1.moduleapi.types.TableEntryTable arg0, nl.cwi.sen1.moduleapi.types.TableEntryTable arg1) {
    nl.cwi.sen1.moduleapi.types.TableEntryTable result = arg1;

    for (nl.cwi.sen1.moduleapi.types.TableEntryTable list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeTableEntryTable(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable append(nl.cwi.sen1.moduleapi.types.TableEntryTable list, nl.cwi.sen1.moduleapi.types.TableEntry elem) {
    return concat(list, makeTableEntryTable(elem));
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList makeDependencyList() {
    return empty_DependencyList;
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList makeDependencyList(nl.cwi.sen1.moduleapi.types.Dependency elem) {
    return makeDependencyList(elem, empty_DependencyList);
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList makeDependencyList(nl.cwi.sen1.moduleapi.types.Dependency head, nl.cwi.sen1.moduleapi.types.DependencyList tail) {
    return makeDependencyList(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList makeDependencyList(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.moduleapi.types.DependencyList) factory.build(new nl.cwi.sen1.moduleapi.types.DependencyList(this, annos, head, tail));
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList makeDependencyList(nl.cwi.sen1.moduleapi.types.Dependency elem0, nl.cwi.sen1.moduleapi.types.Dependency elem1) {
    return makeDependencyList(elem0, makeDependencyList(elem1));
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList makeDependencyList(nl.cwi.sen1.moduleapi.types.Dependency elem0, nl.cwi.sen1.moduleapi.types.Dependency elem1, nl.cwi.sen1.moduleapi.types.Dependency elem2) {
    return makeDependencyList(elem0, makeDependencyList(elem1, elem2));
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList makeDependencyList(nl.cwi.sen1.moduleapi.types.Dependency elem0, nl.cwi.sen1.moduleapi.types.Dependency elem1, nl.cwi.sen1.moduleapi.types.Dependency elem2, nl.cwi.sen1.moduleapi.types.Dependency elem3) {
    return makeDependencyList(elem0, makeDependencyList(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList makeDependencyList(nl.cwi.sen1.moduleapi.types.Dependency elem0, nl.cwi.sen1.moduleapi.types.Dependency elem1, nl.cwi.sen1.moduleapi.types.Dependency elem2, nl.cwi.sen1.moduleapi.types.Dependency elem3, nl.cwi.sen1.moduleapi.types.Dependency elem4) {
    return makeDependencyList(elem0, makeDependencyList(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList makeDependencyList(nl.cwi.sen1.moduleapi.types.Dependency elem0, nl.cwi.sen1.moduleapi.types.Dependency elem1, nl.cwi.sen1.moduleapi.types.Dependency elem2, nl.cwi.sen1.moduleapi.types.Dependency elem3, nl.cwi.sen1.moduleapi.types.Dependency elem4, nl.cwi.sen1.moduleapi.types.Dependency elem5) {
    return makeDependencyList(elem0, makeDependencyList(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList reverse(nl.cwi.sen1.moduleapi.types.DependencyList arg) {
    nl.cwi.sen1.moduleapi.types.DependencyList reversed = makeDependencyList();
    while (!arg.isEmpty()) {
      reversed = makeDependencyList(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList concat(nl.cwi.sen1.moduleapi.types.DependencyList arg0, nl.cwi.sen1.moduleapi.types.DependencyList arg1) {
    nl.cwi.sen1.moduleapi.types.DependencyList result = arg1;

    for (nl.cwi.sen1.moduleapi.types.DependencyList list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeDependencyList(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList append(nl.cwi.sen1.moduleapi.types.DependencyList list, nl.cwi.sen1.moduleapi.types.Dependency elem) {
    return concat(list, makeDependencyList(elem));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList makeModuleIdList() {
    return empty_ModuleIdList;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList makeModuleIdList(nl.cwi.sen1.moduleapi.types.ModuleId elem) {
    return makeModuleIdList(elem, empty_ModuleIdList);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList makeModuleIdList(nl.cwi.sen1.moduleapi.types.ModuleId head, nl.cwi.sen1.moduleapi.types.ModuleIdList tail) {
    return makeModuleIdList(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList makeModuleIdList(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.moduleapi.types.ModuleIdList) factory.build(new nl.cwi.sen1.moduleapi.types.ModuleIdList(this, annos, head, tail));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList makeModuleIdList(nl.cwi.sen1.moduleapi.types.ModuleId elem0, nl.cwi.sen1.moduleapi.types.ModuleId elem1) {
    return makeModuleIdList(elem0, makeModuleIdList(elem1));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList makeModuleIdList(nl.cwi.sen1.moduleapi.types.ModuleId elem0, nl.cwi.sen1.moduleapi.types.ModuleId elem1, nl.cwi.sen1.moduleapi.types.ModuleId elem2) {
    return makeModuleIdList(elem0, makeModuleIdList(elem1, elem2));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList makeModuleIdList(nl.cwi.sen1.moduleapi.types.ModuleId elem0, nl.cwi.sen1.moduleapi.types.ModuleId elem1, nl.cwi.sen1.moduleapi.types.ModuleId elem2, nl.cwi.sen1.moduleapi.types.ModuleId elem3) {
    return makeModuleIdList(elem0, makeModuleIdList(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList makeModuleIdList(nl.cwi.sen1.moduleapi.types.ModuleId elem0, nl.cwi.sen1.moduleapi.types.ModuleId elem1, nl.cwi.sen1.moduleapi.types.ModuleId elem2, nl.cwi.sen1.moduleapi.types.ModuleId elem3, nl.cwi.sen1.moduleapi.types.ModuleId elem4) {
    return makeModuleIdList(elem0, makeModuleIdList(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList makeModuleIdList(nl.cwi.sen1.moduleapi.types.ModuleId elem0, nl.cwi.sen1.moduleapi.types.ModuleId elem1, nl.cwi.sen1.moduleapi.types.ModuleId elem2, nl.cwi.sen1.moduleapi.types.ModuleId elem3, nl.cwi.sen1.moduleapi.types.ModuleId elem4, nl.cwi.sen1.moduleapi.types.ModuleId elem5) {
    return makeModuleIdList(elem0, makeModuleIdList(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList reverse(nl.cwi.sen1.moduleapi.types.ModuleIdList arg) {
    nl.cwi.sen1.moduleapi.types.ModuleIdList reversed = makeModuleIdList();
    while (!arg.isEmpty()) {
      reversed = makeModuleIdList(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList concat(nl.cwi.sen1.moduleapi.types.ModuleIdList arg0, nl.cwi.sen1.moduleapi.types.ModuleIdList arg1) {
    nl.cwi.sen1.moduleapi.types.ModuleIdList result = arg1;

    for (nl.cwi.sen1.moduleapi.types.ModuleIdList list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeModuleIdList(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList append(nl.cwi.sen1.moduleapi.types.ModuleIdList list, nl.cwi.sen1.moduleapi.types.ModuleId elem) {
    return concat(list, makeModuleIdList(elem));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList makeModuleAttributeList() {
    return empty_ModuleAttributeList;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList makeModuleAttributeList(nl.cwi.sen1.moduleapi.types.ModuleAttribute elem) {
    return makeModuleAttributeList(elem, empty_ModuleAttributeList);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList makeModuleAttributeList(nl.cwi.sen1.moduleapi.types.ModuleAttribute head, nl.cwi.sen1.moduleapi.types.ModuleAttributeList tail) {
    return makeModuleAttributeList(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList makeModuleAttributeList(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.moduleapi.types.ModuleAttributeList) factory.build(new nl.cwi.sen1.moduleapi.types.ModuleAttributeList(this, annos, head, tail));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList makeModuleAttributeList(nl.cwi.sen1.moduleapi.types.ModuleAttribute elem0, nl.cwi.sen1.moduleapi.types.ModuleAttribute elem1) {
    return makeModuleAttributeList(elem0, makeModuleAttributeList(elem1));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList makeModuleAttributeList(nl.cwi.sen1.moduleapi.types.ModuleAttribute elem0, nl.cwi.sen1.moduleapi.types.ModuleAttribute elem1, nl.cwi.sen1.moduleapi.types.ModuleAttribute elem2) {
    return makeModuleAttributeList(elem0, makeModuleAttributeList(elem1, elem2));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList makeModuleAttributeList(nl.cwi.sen1.moduleapi.types.ModuleAttribute elem0, nl.cwi.sen1.moduleapi.types.ModuleAttribute elem1, nl.cwi.sen1.moduleapi.types.ModuleAttribute elem2, nl.cwi.sen1.moduleapi.types.ModuleAttribute elem3) {
    return makeModuleAttributeList(elem0, makeModuleAttributeList(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList makeModuleAttributeList(nl.cwi.sen1.moduleapi.types.ModuleAttribute elem0, nl.cwi.sen1.moduleapi.types.ModuleAttribute elem1, nl.cwi.sen1.moduleapi.types.ModuleAttribute elem2, nl.cwi.sen1.moduleapi.types.ModuleAttribute elem3, nl.cwi.sen1.moduleapi.types.ModuleAttribute elem4) {
    return makeModuleAttributeList(elem0, makeModuleAttributeList(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList makeModuleAttributeList(nl.cwi.sen1.moduleapi.types.ModuleAttribute elem0, nl.cwi.sen1.moduleapi.types.ModuleAttribute elem1, nl.cwi.sen1.moduleapi.types.ModuleAttribute elem2, nl.cwi.sen1.moduleapi.types.ModuleAttribute elem3, nl.cwi.sen1.moduleapi.types.ModuleAttribute elem4, nl.cwi.sen1.moduleapi.types.ModuleAttribute elem5) {
    return makeModuleAttributeList(elem0, makeModuleAttributeList(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList reverse(nl.cwi.sen1.moduleapi.types.ModuleAttributeList arg) {
    nl.cwi.sen1.moduleapi.types.ModuleAttributeList reversed = makeModuleAttributeList();
    while (!arg.isEmpty()) {
      reversed = makeModuleAttributeList(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList concat(nl.cwi.sen1.moduleapi.types.ModuleAttributeList arg0, nl.cwi.sen1.moduleapi.types.ModuleAttributeList arg1) {
    nl.cwi.sen1.moduleapi.types.ModuleAttributeList result = arg1;

    for (nl.cwi.sen1.moduleapi.types.ModuleAttributeList list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeModuleAttributeList(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList append(nl.cwi.sen1.moduleapi.types.ModuleAttributeList list, nl.cwi.sen1.moduleapi.types.ModuleAttribute elem) {
    return concat(list, makeModuleAttributeList(elem));
  }

/*genTypeFromTermMethods*/
  public nl.cwi.sen1.moduleapi.types.Modules ModulesFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.moduleapi.types.Modules tmp;
    tmp = Modules_DefaultFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Modules: " + trm);
  }

  public nl.cwi.sen1.moduleapi.types.Module ModuleFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.moduleapi.types.Module tmp;
    tmp = Module_ModuleFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Module: " + trm);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleId ModuleIdFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.moduleapi.types.ModuleId tmp;
    tmp = ModuleId_ModuleIdFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a ModuleId: " + trm);
  }

  public nl.cwi.sen1.moduleapi.types.Attribute AttributeFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.moduleapi.types.Attribute tmp;
    tmp = Attribute_AttributeFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Attribute: " + trm);
  }

  public nl.cwi.sen1.moduleapi.types.TableEntry TableEntryFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.moduleapi.types.TableEntry tmp;
    tmp = TableEntry_TableEntryFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a TableEntry: " + trm);
  }

  public nl.cwi.sen1.moduleapi.types.Dependencies DependenciesFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.moduleapi.types.Dependencies tmp;
    tmp = Dependencies_DependenciesFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Dependencies: " + trm);
  }

  public nl.cwi.sen1.moduleapi.types.Dependency DependencyFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.moduleapi.types.Dependency tmp;
    tmp = Dependency_DependencyFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Dependency: " + trm);
  }

  public nl.cwi.sen1.moduleapi.types.AttributeMap AttributeMapFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.moduleapi.types.AttributeMap tmp;
    tmp = AttributeMap_AttributeMapFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a AttributeMap: " + trm);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttribute ModuleAttributeFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.moduleapi.types.ModuleAttribute tmp;
    tmp = ModuleAttribute_ModuleAttributeFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a ModuleAttribute: " + trm);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleList ModuleListFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.moduleapi.types.ModuleList result = makeModuleList();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.moduleapi.types.Module elem = ModuleFromTerm(list.getFirst());
            result = makeModuleList(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a ModuleList: " + trm);
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore AttributeStoreFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.moduleapi.types.AttributeStore result = makeAttributeStore();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.moduleapi.types.Attribute elem = AttributeFromTerm(list.getFirst());
            result = makeAttributeStore(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a AttributeStore: " + trm);
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable TableEntryTableFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.moduleapi.types.TableEntryTable result = makeTableEntryTable();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.moduleapi.types.TableEntry elem = TableEntryFromTerm(list.getFirst());
            result = makeTableEntryTable(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a TableEntryTable: " + trm);
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList DependencyListFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.moduleapi.types.DependencyList result = makeDependencyList();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.moduleapi.types.Dependency elem = DependencyFromTerm(list.getFirst());
            result = makeDependencyList(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a DependencyList: " + trm);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList ModuleIdListFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.moduleapi.types.ModuleIdList result = makeModuleIdList();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.moduleapi.types.ModuleId elem = ModuleIdFromTerm(list.getFirst());
            result = makeModuleIdList(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a ModuleIdList: " + trm);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList ModuleAttributeListFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.moduleapi.types.ModuleAttributeList result = makeModuleAttributeList();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.moduleapi.types.ModuleAttribute elem = ModuleAttributeFromTerm(list.getFirst());
            result = makeModuleAttributeList(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a ModuleAttributeList: " + trm);
  }

  public nl.cwi.sen1.moduleapi.types.NatCon NatConFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.moduleapi.types.NatCon tmp;
    tmp = NatCon_NatConFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a NatCon: " + trm);
  }

/*genTypeFromMethods*/
  public nl.cwi.sen1.moduleapi.types.Modules ModulesFromString(String str) {
    return ModulesFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.moduleapi.types.Modules ModulesFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ModulesFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.moduleapi.types.Module ModuleFromString(String str) {
    return ModuleFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.moduleapi.types.Module ModuleFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ModuleFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleId ModuleIdFromString(String str) {
    return ModuleIdFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleId ModuleIdFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ModuleIdFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.moduleapi.types.Attribute AttributeFromString(String str) {
    return AttributeFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.moduleapi.types.Attribute AttributeFromFile(java.io.InputStream stream) throws java.io.IOException {
    return AttributeFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.moduleapi.types.TableEntry TableEntryFromString(String str) {
    return TableEntryFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.moduleapi.types.TableEntry TableEntryFromFile(java.io.InputStream stream) throws java.io.IOException {
    return TableEntryFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.moduleapi.types.Dependencies DependenciesFromString(String str) {
    return DependenciesFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.moduleapi.types.Dependencies DependenciesFromFile(java.io.InputStream stream) throws java.io.IOException {
    return DependenciesFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.moduleapi.types.Dependency DependencyFromString(String str) {
    return DependencyFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.moduleapi.types.Dependency DependencyFromFile(java.io.InputStream stream) throws java.io.IOException {
    return DependencyFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.moduleapi.types.AttributeMap AttributeMapFromString(String str) {
    return AttributeMapFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.moduleapi.types.AttributeMap AttributeMapFromFile(java.io.InputStream stream) throws java.io.IOException {
    return AttributeMapFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttribute ModuleAttributeFromString(String str) {
    return ModuleAttributeFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttribute ModuleAttributeFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ModuleAttributeFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleList ModuleListFromString(String str) {
    return ModuleListFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleList ModuleListFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ModuleListFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore AttributeStoreFromString(String str) {
    return AttributeStoreFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore AttributeStoreFromFile(java.io.InputStream stream) throws java.io.IOException {
    return AttributeStoreFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable TableEntryTableFromString(String str) {
    return TableEntryTableFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable TableEntryTableFromFile(java.io.InputStream stream) throws java.io.IOException {
    return TableEntryTableFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList DependencyListFromString(String str) {
    return DependencyListFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList DependencyListFromFile(java.io.InputStream stream) throws java.io.IOException {
    return DependencyListFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList ModuleIdListFromString(String str) {
    return ModuleIdListFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList ModuleIdListFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ModuleIdListFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList ModuleAttributeListFromString(String str) {
    return ModuleAttributeListFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList ModuleAttributeListFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ModuleAttributeListFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.moduleapi.types.NatCon NatConFromString(String str) {
    return NatConFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.moduleapi.types.NatCon NatConFromFile(java.io.InputStream stream) throws java.io.IOException {
    return NatConFromTerm(factory.readFromFile(stream));
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
