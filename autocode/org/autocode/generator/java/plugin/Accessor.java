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

public class Accessor
  extends JavaGeneratorPlugin
{
  //{{{ private void addAttribute(compilationUnit, fieldContext, name, type)

  private void addAttribute(JavaCompilationUnit unit,
			    PropertyContext fieldContext,
			    String attrName, String attrType)
  {
    boolean isStatic = fieldContext.getBoolean("static");
    boolean isFinal = fieldContext.getBoolean("final");

    JavaAccessSpecifier access
      = JavaAccessSpecifier.parse(fieldContext.getString("access"));

    JavaAttribute attr =
      new JavaAttribute(attrName, attrType, access, isFinal, isStatic);

    String desc = "the " + fieldContext.getString("description") + ".";
    attr.setDescription(desc);

    if (!unit.hasAttribute(attr)) {
      unit.addAttribute(attr);
    }
  }

  //}}}

  //{{{ private void generateGet(name, generator, type, field, operation)

  private void generateGet(String name, JavaGenerator generator,
			   PropertyContext typeContext,
			   PropertyContext fieldContext,
			   PropertyContext operationContext)
  {
    PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
    String attrType = generator.typeName(fieldTypeContext);

    String fieldName = fieldContext.getName();
    String methodName = generator.methodName(name + "-" + fieldName);

    String attrName = generator.attributeName(fieldName);
    MethodBody body = new MethodBody();
    body.addLine("return " + attrName + ";");

    JavaMethod method
      = createMethod(operationContext, methodName, attrType, body);
    method.setDescription("gets the " + fieldContext.getString("description") + ".");

    JavaCompilationUnit unit = generator.getCompilationUnit();
    unit.addMethod(method);

    addAttribute(unit, fieldContext, attrName, attrType);
  }

  //}}}
  //{{{ public void generateGet(generator, type, field, operation)

  public void generateGet(JavaGenerator generator,
			  PropertyContext typeContext,
			  PropertyContext fieldContext,
			  PropertyContext operationContext)
  {
    generateGet("get", generator, typeContext, fieldContext, operationContext);
  }

  //}}}
  //{{{ public void generateIs(generator, type, field, operation)

  public void generateIs(JavaGenerator generator,
			 PropertyContext typeContext,
			 PropertyContext fieldContext,
			 PropertyContext operationContext)
  {
    generateGet("is", generator, typeContext, fieldContext, operationContext);
  }

  //}}}
  //{{{ public void generateSet(generator, type, field, operation)

  public void generateSet(JavaGenerator generator,
			  PropertyContext typeContext,
			  PropertyContext fieldContext,
			  PropertyContext operationContext)
  {
    PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
    String attrType = generator.typeName(fieldTypeContext);

    String fieldName = fieldContext.getName();
    String methodName = generator.methodName("set-" + fieldName);

    String attrName = generator.attributeName(fieldName);

    String paramName = generator.parameterName(fieldName);
    FormalParameter param = new FormalParameter(paramName, attrType);
    param.setDescription(fieldContext.getString("description"));

    MethodBody body = new MethodBody();
    body.addLine(attrName + " = " + paramName + ";");
    JavaMethod method = createMethod(operationContext, methodName, "void", body);
    method.addFormalParameter(param);
    method.setDescription("sets the " + fieldContext.getString("description") + ".");

    JavaCompilationUnit unit = generator.getCompilationUnit();
    unit.addMethod(method);

    addAttribute(unit, fieldContext, attrName, attrType);
  }

  //}}}
  //{{{ public void generateAdd(generator, type, field, operation)

  public void generateAdd(JavaGenerator generator,
			  PropertyContext typeContext,
			  PropertyContext fieldContext,
			  PropertyContext operationContext)
  {
    PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
    String attrType = generator.typeName(fieldTypeContext);

    String element = fieldTypeContext.getString("element-type");
    if (element == null) {
      throw new RuntimeException("field operation 'add' requires an "
				 + "element-type to be present in the "
				 + " field-type");
    }
    String elementType = generator.typeName(fieldTypeContext.getString("element-type"));
    
    String fieldName = fieldContext.getName();
    String methodName = generator.methodName("add-" + fieldName);

    String attrName = generator.attributeName(fieldName);

    String paramName = generator.parameterName(fieldName);
    FormalParameter param = new FormalParameter(paramName, elementType);
    param.setDescription(fieldContext.getString("description"));

    MethodBody body = new MethodBody();
    body.addLine(attrName + ".add(" + paramName + ");");
    JavaMethod method = createMethod(operationContext, methodName, "void", body);
    method.addFormalParameter(param);
    method.setDescription("adds a " + fieldContext.getString("description") + ".");

    JavaCompilationUnit unit = generator.getCompilationUnit();
    unit.addMethod(method);

    addAttribute(unit, fieldContext, attrName, attrType);
  }

  //}}}
  //{{{ public void generateMergeCollection(generator, type, field, operation)

  public void generateMergeCollection(JavaGenerator generator,
				      PropertyContext typeContext,
				      PropertyContext fieldContext,
				      PropertyContext operationContext)
  {
    JavaCompilationUnit unit = generator.getCompilationUnit();

    PropertyContext fieldTypeContext
      = new PropertyContext(fieldContext, "type");
    String attrType = generator.typeName(fieldTypeContext);

    String collection = fieldTypeContext.getString("collection-type");
    PropertyContext collectionContext
      = new PropertyContext(fieldTypeContext, "collection-type", collection);
    unit.mergeImportedCollection(collectionContext.getValueSet("import"));

    String fieldName = fieldContext.getName();
    String methodName = generator.methodName("merge-" + fieldName
					     + "-collection");

    String attrName = generator.attributeName(fieldName);

    FormalParameter param = new FormalParameter("collection", collection);

    MethodBody body = new MethodBody();
    body.addLine(attrName + ".addAll(collection);");
    JavaMethod method = createMethod(operationContext, methodName, "void", body);
    method.addFormalParameter(param);
    method.setDescription("add all elements of a collection to "
			  + fieldContext.getName() + ".");

    unit.addMethod(method);

    addAttribute(unit, fieldContext, attrName, attrType);
  }

  //}}}
  //{{{ public void generateFetchIterator(generator, type, field, operation)

  public void generateFetchIterator(JavaGenerator generator,
				    PropertyContext typeContext,
				    PropertyContext fieldContext,
				    PropertyContext operationContext)
  {
    JavaCompilationUnit unit = generator.getCompilationUnit();

    PropertyContext fieldTypeContext
      = new PropertyContext(fieldContext, "type");
    String attrType = generator.typeName(fieldTypeContext);

    String fieldName = fieldContext.getName();
    String methodName = generator.methodName("fetch-" + fieldName
					     + "-iterator");

    String attrName = generator.attributeName(fieldName);

    MethodBody body = new MethodBody();
    body.addLine("return " + attrName + ".iterator();");
    JavaMethod method = createMethod(operationContext, methodName,
				     "Iterator", body);
    method.setDescription("retrieve an iterator for " 
			  + fieldContext.getName() + ".");

    unit.addMethod(method);
    unit.addImported("java.util.Iterator");

    addAttribute(unit, fieldContext, attrName, attrType);
  }

  //}}}
  //{{{ public void generateInit(JavaGenerator generator)

  public void generateInit(JavaGenerator generator,
			   PropertyContext typeContext,
			   PropertyContext fieldContext,
			   PropertyContext operationContext)
  {
    PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
    if (!fieldTypeContext.getBoolean("collection")) {
      return;
    }

    JavaCompilationUnit unit = generator.getCompilationUnit();

    String fieldName = fieldContext.getName();
    String collection = fieldTypeContext.getString("interface");
    String methodName
      = generator.methodName("init-" + fieldName + "-" + collection);

    String implementation = fieldTypeContext.getString("implementation");
    PropertyContext implementationContext
      = new PropertyContext(fieldTypeContext, "implementation");
    Set imports = implementationContext.getValueSet("import");
    unit.mergeImportedCollection(imports);

    MethodBody body = new MethodBody();
    String attrName = generator.attributeName(fieldName);
    body.addLine(attrName + " = new " + implementation + "();");

    JavaMethod method = createMethod(operationContext, methodName, "void", body);
    method.setDescription("initializes the "
			  + fieldContext.getString("description") + ".");
    unit.addMethod(method);

    String attrType = generator.typeName(fieldTypeContext);
    addAttribute(unit, fieldContext, attrName, attrType);
  }

  //}}}
}
