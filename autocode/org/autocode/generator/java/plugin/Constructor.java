package org.autocode.generator.java;

//{{{ imports

import org.autocode.*;
import org.autocode.property.*;
import org.autocode.generator.*;
import org.autocode.generator.repository.*;
import org.autocode.generator.java.repository.*;

//}}}

public class Constructor
  extends JavaGeneratorPlugin
{
  //{{{ public void generateConstructor(JavaGenerator generator)

  public void generateConstructor(JavaGenerator generator, PropertyContext context,
				  String typeName)
  {
    /*
    JavaCompilationUnit unit = generator.getCompilationUnit();
    String constructorName = JavaGenerator.javaTypeName(type.getName());

    DataDefinition def = generator.getDataDefinition();
    String application = generator.getApplication();

    MethodBody body = new MethodBody();
    JavaMethod constructor = createTypeMethod("constructors",
					      constructorName, null, body);

    Iterator iter = type.fetchFieldIterator();
    while (iter.hasNext()) {
      Field field = (Field)iter.next();

      BasicType fieldType = field.getType();

      if (fieldType.instanceOfCollectionType()) {
	CollectionType collection = (CollectionType)fieldType;
	String collName = collection.getCollectionName();
	String init = JavaGenerator.javaMethodName("init-" + field.getName()
					       + "-" + collName);
	body.addLine(init + "();");
      } else {
	String paramName = JavaGenerator.javaParameterName(field.getName());
	String typeName = JavaGenerator.javaTypeName(fieldType);
	FormalParameter formal = new FormalParameter(paramName, typeName);
	constructor.addFormalParameter(formal);

	String setMethod = JavaGenerator.javaMethodName("set-" + field.getName());
	body.addLine(setMethod + "(" + paramName + ");");
      }
    }

    unit.addMethod(constructor);
    */
  }

  //}}}
}
