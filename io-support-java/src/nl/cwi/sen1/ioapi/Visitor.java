package nl.cwi.sen1.ioapi;

public interface Visitor {
  public abstract nl.cwi.sen1.ioapi.types.File visit_File_File(nl.cwi.sen1.ioapi.types.file.File arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.ioapi.types.Path visit_Path_Absolute(nl.cwi.sen1.ioapi.types.path.Absolute arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.ioapi.types.Path visit_Path_Relative(nl.cwi.sen1.ioapi.types.path.Relative arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.ioapi.types.Segment visit_Segment_Segment(nl.cwi.sen1.ioapi.types.segment.Segment arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.ioapi.types.SegmentList visit_SegmentList(nl.cwi.sen1.ioapi.types.SegmentList arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.ioapi.types.StrChar visit_StrChar_StrChar(nl.cwi.sen1.ioapi.types.strchar.StrChar arg) throws jjtraveler.VisitFailure;
  public abstract nl.cwi.sen1.ioapi.types.StrCon visit_StrCon_StrCon(nl.cwi.sen1.ioapi.types.strcon.StrCon arg) throws jjtraveler.VisitFailure;
}
