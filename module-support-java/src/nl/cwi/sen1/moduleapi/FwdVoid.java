package nl.cwi.sen1.moduleapi;

public class FwdVoid extends jjtraveler.VoidVisitor implements Visitor, jjtraveler.Visitor {
  protected jjtraveler.Visitor any;

  public FwdVoid(jjtraveler.Visitor v) {
    this.any = v;
  }

  public void voidVisit(jjtraveler.Visitable v) throws jjtraveler.VisitFailure {
    if (v instanceof nl.cwi.sen1.moduleapi.AbstractType) {
      ((nl.cwi.sen1.moduleapi.AbstractType) v).accept(this);
    } else if (v instanceof nl.cwi.sen1.moduleapi.AbstractList) {
      ((nl.cwi.sen1.moduleapi.AbstractList) v).accept(this);
    } else {
      any.visit(v);
    }
  }

  public nl.cwi.sen1.moduleapi.types.Modules visit_Modules_Default(nl.cwi.sen1.moduleapi.types.modules.Default arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.moduleapi.types.Modules) any.visit(arg);
  }

  public nl.cwi.sen1.moduleapi.types.Module visit_Module_Module(nl.cwi.sen1.moduleapi.types.module.Module arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.moduleapi.types.Module) any.visit(arg);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleId visit_ModuleId_ModuleId(nl.cwi.sen1.moduleapi.types.moduleid.ModuleId arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.moduleapi.types.ModuleId) any.visit(arg);
  }

  public nl.cwi.sen1.moduleapi.types.Attribute visit_Attribute_Attribute(nl.cwi.sen1.moduleapi.types.attribute.Attribute arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.moduleapi.types.Attribute) any.visit(arg);
  }

  public nl.cwi.sen1.moduleapi.types.TableEntry visit_TableEntry_TableEntry(nl.cwi.sen1.moduleapi.types.tableentry.TableEntry arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.moduleapi.types.TableEntry) any.visit(arg);
  }

  public nl.cwi.sen1.moduleapi.types.Dependencies visit_Dependencies_Dependencies(nl.cwi.sen1.moduleapi.types.dependencies.Dependencies arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.moduleapi.types.Dependencies) any.visit(arg);
  }

  public nl.cwi.sen1.moduleapi.types.Dependency visit_Dependency_Dependency(nl.cwi.sen1.moduleapi.types.dependency.Dependency arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.moduleapi.types.Dependency) any.visit(arg);
  }

  public nl.cwi.sen1.moduleapi.types.AttributeMap visit_AttributeMap_AttributeMap(nl.cwi.sen1.moduleapi.types.attributemap.AttributeMap arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.moduleapi.types.AttributeMap) any.visit(arg);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttribute visit_ModuleAttribute_ModuleAttribute(nl.cwi.sen1.moduleapi.types.moduleattribute.ModuleAttribute arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.moduleapi.types.ModuleAttribute) any.visit(arg);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleList visit_ModuleList(nl.cwi.sen1.moduleapi.types.ModuleList arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.moduleapi.types.ModuleList) any.visit(arg);
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore visit_AttributeStore(nl.cwi.sen1.moduleapi.types.AttributeStore arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.moduleapi.types.AttributeStore) any.visit(arg);
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable visit_TableEntryTable(nl.cwi.sen1.moduleapi.types.TableEntryTable arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.moduleapi.types.TableEntryTable) any.visit(arg);
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList visit_DependencyList(nl.cwi.sen1.moduleapi.types.DependencyList arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.moduleapi.types.DependencyList) any.visit(arg);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList visit_ModuleIdList(nl.cwi.sen1.moduleapi.types.ModuleIdList arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.moduleapi.types.ModuleIdList) any.visit(arg);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList visit_ModuleAttributeList(nl.cwi.sen1.moduleapi.types.ModuleAttributeList arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.moduleapi.types.ModuleAttributeList) any.visit(arg);
  }

  public nl.cwi.sen1.moduleapi.types.NatCon visit_NatCon_NatCon(nl.cwi.sen1.moduleapi.types.natcon.NatCon arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.moduleapi.types.NatCon) any.visit(arg);
  }

}
