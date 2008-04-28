package nl.cwi.sen1.moduleapi;

public interface Visitor {
  public abstract nl.cwi.sen1.moduleapi.types.Modules visit_Modules_Default(nl.cwi.sen1.moduleapi.types.modules.Default arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.moduleapi.types.Module visit_Module_Module(nl.cwi.sen1.moduleapi.types.module.Module arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.moduleapi.types.ModuleId visit_ModuleId_ModuleId(nl.cwi.sen1.moduleapi.types.moduleid.ModuleId arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.moduleapi.types.Attribute visit_Attribute_Attribute(nl.cwi.sen1.moduleapi.types.attribute.Attribute arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.moduleapi.types.TableEntry visit_TableEntry_TableEntry(nl.cwi.sen1.moduleapi.types.tableentry.TableEntry arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.moduleapi.types.Dependencies visit_Dependencies_Dependencies(nl.cwi.sen1.moduleapi.types.dependencies.Dependencies arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.moduleapi.types.Dependency visit_Dependency_Dependency(nl.cwi.sen1.moduleapi.types.dependency.Dependency arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.moduleapi.types.AttributeMap visit_AttributeMap_AttributeMap(nl.cwi.sen1.moduleapi.types.attributemap.AttributeMap arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.moduleapi.types.ModuleAttribute visit_ModuleAttribute_ModuleAttribute(nl.cwi.sen1.moduleapi.types.moduleattribute.ModuleAttribute arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.moduleapi.types.ModuleList visit_ModuleList(nl.cwi.sen1.moduleapi.types.ModuleList arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.moduleapi.types.AttributeStore visit_AttributeStore(nl.cwi.sen1.moduleapi.types.AttributeStore arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.moduleapi.types.TableEntryTable visit_TableEntryTable(nl.cwi.sen1.moduleapi.types.TableEntryTable arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.moduleapi.types.DependencyList visit_DependencyList(nl.cwi.sen1.moduleapi.types.DependencyList arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.moduleapi.types.ModuleIdList visit_ModuleIdList(nl.cwi.sen1.moduleapi.types.ModuleIdList arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.moduleapi.types.ModuleAttributeList visit_ModuleAttributeList(nl.cwi.sen1.moduleapi.types.ModuleAttributeList arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.moduleapi.types.NatCon visit_NatCon_NatCon(nl.cwi.sen1.moduleapi.types.natcon.NatCon arg) throws jjtraveler.VisitFailure;
}
