package org.autocode.generator.java.plugin;

//{{{ imports

import org.autocode.*;
import org.autocode.property.*;
import org.autocode.generator.*;
import org.autocode.generator.repository.*;
import org.autocode.generator.java.*;
import org.autocode.generator.java.repository.*;

import java.util.*;

//}}}

public class Equality
  extends JavaGeneratorPlugin
{
  //{{{ public void generateEquals(JavaGenerator generator)

  public void generateEquals(JavaGenerator generator,
			     PropertyContext typeContext,
			     PropertyContext operationContext)
  {
    CodeBlock body = new CodeBlock();

    JavaMethod method
      = createMethod(operationContext, "equals", "boolean", body);
    method.addFormalParameter(new FormalParameter("peerObject", "Object"));
    
    body.addLine("if (!(peerObject instanceof " + typeContext.getName()
		 + ")) {");
    body.addLine("  return false;");
    body.addLine("}");
    body.addLine("");
    body.addLine(typeContext.getName() + " peer = (" +
		 typeContext.getName() + ")peerObject;");
    body.addLine("");

    //{{{ Add field equality checks

    Iterator iter = typeContext.getValueSet("field").iterator();
    while (iter.hasNext()) {
      String fieldName = (String)iter.next();
      PropertyContext fieldContext
	= new PropertyContext(typeContext, "field", fieldName);
      PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");

      String getter = fieldContext.getString("getter");
      if (getter == null) {
	throw new RuntimeException("operation 'equals' requires that a "
				   + "setter is defined for field "
				   + fieldName);
      }
      if (fieldTypeContext.getBoolean("reference-type")) {
	body.addLine("if (!peer." + getter + "().equals("
		     + getter + "())) {");
	body.addLine("  return false;");
	body.addLine("}");
      } else {
	body.addLine("if (peer." + getter + "() != " + getter + "()) {");
	body.addLine("  return false;");
	body.addLine("}");
      }
    }
    body.addLine("");
    if (operationContext.getBoolean("call-super")) {
      body.addLine("return super.equals(peer);");
    } else {
      body.addLine("return true;");
    }

    //}}}

    String typeName = generator.typeName(typeContext.getName());
    method.setDescription("checks (deep) equality between two "
			  + typeName + " objects.");

    generator.getCompilationUnit().addMethod(method);
  }

  //}}}

  public void generateHashCode()
  {
  }
}
