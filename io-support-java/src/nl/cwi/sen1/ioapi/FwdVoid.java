package nl.cwi.sen1.ioapi;

public class FwdVoid extends jjtraveler.VoidVisitor implements Visitor, jjtraveler.Visitor {
  protected jjtraveler.Visitor any;

  public FwdVoid(jjtraveler.Visitor v) {
    this.any = v;
  }

  public void voidVisit(jjtraveler.Visitable v) throws jjtraveler.VisitFailure {
    if (v instanceof nl.cwi.sen1.ioapi.AbstractType) {
      ((nl.cwi.sen1.ioapi.AbstractType) v).accept(this);
    } else if (v instanceof nl.cwi.sen1.ioapi.AbstractList) {
      ((nl.cwi.sen1.ioapi.AbstractList) v).accept(this);
    } else {
      any.visit(v);
    }
  }

  public nl.cwi.sen1.ioapi.types.File visit_File_File(nl.cwi.sen1.ioapi.types.file.File arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.ioapi.types.File) any.visit(arg);
  }

  public nl.cwi.sen1.ioapi.types.Path visit_Path_Absolute(nl.cwi.sen1.ioapi.types.path.Absolute arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.ioapi.types.Path) any.visit(arg);
  }

  public nl.cwi.sen1.ioapi.types.Path visit_Path_Relative(nl.cwi.sen1.ioapi.types.path.Relative arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.ioapi.types.Path) any.visit(arg);
  }

  public nl.cwi.sen1.ioapi.types.Segment visit_Segment_Segment(nl.cwi.sen1.ioapi.types.segment.Segment arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.ioapi.types.Segment) any.visit(arg);
  }

  public nl.cwi.sen1.ioapi.types.SegmentList visit_SegmentList(nl.cwi.sen1.ioapi.types.SegmentList arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.ioapi.types.SegmentList) any.visit(arg);
  }

  public nl.cwi.sen1.ioapi.types.StrChar visit_StrChar_StrChar(nl.cwi.sen1.ioapi.types.strchar.StrChar arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.ioapi.types.StrChar) any.visit(arg);
  }

  public nl.cwi.sen1.ioapi.types.StrCon visit_StrCon_StrCon(nl.cwi.sen1.ioapi.types.strcon.StrCon arg) throws jjtraveler.VisitFailure {
    return (nl.cwi.sen1.ioapi.types.StrCon) any.visit(arg);
  }

}
