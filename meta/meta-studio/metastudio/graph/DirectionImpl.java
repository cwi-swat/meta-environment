package metastudio.graph;

import aterm.*;
import java.io.InputStream;
import java.io.IOException;

abstract public class DirectionImpl extends MetaGraphConstructor
{
  public static Direction fromString(String str)
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().parse(str);
    return fromTerm(trm);
  }
  public static Direction fromTextFile(InputStream stream) throws aterm.ParseError, IOException
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().readFromTextFile(stream);
    return fromTerm(trm);
  }
  public boolean isEqual(Direction peer)
  {
    return term.isEqual(peer.toTerm());
  }
  public static Direction fromTerm(aterm.ATerm trm)
  {
    Direction tmp;
    if ((tmp = Direction_Forward.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Direction_Back.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Direction_Both.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Direction_None.fromTerm(trm)) != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Direction: " + trm);
  }

  public boolean isForward()
  {
    return false;
  }

  public boolean isBack()
  {
    return false;
  }

  public boolean isBoth()
  {
    return false;
  }

  public boolean isNone()
  {
    return false;
  }


}

