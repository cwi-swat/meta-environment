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
    JavaCompilationUnit unit = generator.getCompilationUnit();
    PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
    String fieldName = fieldContext.getName();
    String attrType = generator.typeName(fieldTypeContext);
    String attrName = generator.attributeName(fieldName);
    String methodName = generator.methodName(name + "-" + fieldName);
    fieldContext.setSingletonValue("getter", methodName);
    CodeBlock body = new CodeBlock();
    JavaMethod method;


    if (fieldTypeContext.getName().equals("map")) {
      PropertyContext keyTypeContext
	= new PropertyContext(fieldTypeContext, "key-type");
      String keyType = generator.typeName(keyTypeContext);

      PropertyContext valueTypeContext
	= new PropertyContext(fieldTypeContext, "value-type");
      String valueType = generator.typeName(valueTypeContext);

      body.addLine("return (" + valueType + ")" + attrName + ".get(key);");
      method = createMethod(operationContext, methodName, valueType, body);
      FormalParameter param = new FormalParameter("key", keyType);
      method.addFormalParameter(param);
    } else {
      body.addLine("return " + attrName + ";");

      method = createMethod(operationContext, methodName, attrType, body);
      method.setDescription("gets the " + fieldContext.getString("description") + ".");
    }
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
  //{{{ public void generateContainsValue(generator, type, field, operation)

  public void generateContainsValue(JavaGenerator generator,
				    PropertyContext typeContext,
				    PropertyContext fieldContext,
				    PropertyContext operationContext)
  {
    PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
    if (!fieldTypeContext.getBoolean("collection")) {
      throw new RuntimeException("operation 'contains-value' can only be generated for collections");
    }

    String call, typeProperty;

    if (fieldTypeContext.getName().equals("map")) {
      call = "containsValue";
      typeProperty = "value-type";
    } else {
      call = "contains";
      typeProperty = "element-type";
    }

    String fieldName = fieldContext.getName();
    String attrName = generator.attributeName(fieldName);
    String methodName
      = generator.methodName("contains-" + fieldName + "-value");

    String paramName = generator.parameterName(fieldName);

    CodeBlock body = new CodeBlock("return " + attrName + "." + call
				   + "(" + paramName + ");");
    JavaMethod method = createMethod(operationContext, methodName,
				     "boolean", body);

    PropertyContext valueTypeContext
      = new PropertyContext(fieldTypeContext, typeProperty);

    String valueType = generator.typeName(valueTypeContext);

    FormalParameter param = new FormalParameter(paramName, valueType);
    method.addFormalParameter(param);

    JavaCompilationUnit unit = generator.getCompilationUnit();
    unit.addMethod(method);
  }

  //}}}
  //{{{ public void generateContainsKey(generator, type, field, operation)

  public void generateContainsKey(JavaGenerator generator,
				  PropertyContext typeContext,
				  PropertyContext fieldContext,
				  PropertyContext operationContext)
  {
    PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
    if (!fieldTypeContext.getName().equals("map")) {
      throw new RuntimeException("operation 'contains-key' can only be generated for map types");
    }

    String fieldName = fieldContext.getName();
    String attrName = generator.attributeName(fieldName);
    String methodName
      = generator.methodName("contains-" + fieldName + "-key");

    String paramName = generator.parameterName(fieldName + "-key");

    CodeBlock body = new CodeBlock("return " + attrName + ".containsKey("
				   + paramName + ");");
    JavaMethod method = createMethod(operationContext, methodName,
				     "boolean", body);

    PropertyContext keyTypeContext
      = new PropertyContext(fieldTypeContext, "key-type");
    String keyType = generator.typeName(keyTypeContext);

    FormalParameter param = new FormalParameter(paramName, keyType);
    method.addFormalParameter(param);

    JavaCompilationUnit unit = generator.getCompilationUnit();
    unit.addMethod(method);
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

    CodeBlock body = new CodeBlock();
    body.addLine(attrName + " = " + paramName + ";");
    JavaMethod method = createMethod(operationContext, methodName, "void", body);
    method.addFormalParameter(param);
    method.setDescription("sets the " + fieldContext.getString("description") + ".");

    JavaCompilationUnit unit = generator.getCompilationUnit();
    unit.addMethod(method);

    addAttribute(unit, fieldContext, attrName, attrType);
  }

  //}}}
  //{{{ public void generatePut(generator, type, field, operation)

  public void generatePut(JavaGenerator generator,
			  PropertyContext typeContext,
			  PropertyContext fieldContext,
			  PropertyContext operationContext)
  {
    PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
    if (!fieldTypeContext.getName().equals("map")) {
      throw new RuntimeException("operation 'put' can only be generated for map types");
    }

    String attrType = generator.typeName(fieldTypeContext);

    String fieldName = fieldContext.getName();
    String methodName = generator.methodName("put-" + fieldName);

    String attrName = generator.attributeName(fieldName);

    CodeBlock body = new CodeBlock(attrName + ".put(key, value);");
    JavaMethod method = createMethod(operationContext, methodName, "void", body);

    //{{{ Add key parameter

    PropertyContext keyTypeContext
      = new PropertyContext(fieldTypeContext, "key-type");
    String keyType = generator.typeName(keyTypeContext);
    method.addFormalParameter(new FormalParameter("key", keyType));

    //}}}
    //{{{ Add value parameter

    PropertyContext valueTypeContext
      = new PropertyContext(fieldTypeContext, "value-type");
    String valueType = generator.typeName(valueTypeContext);
    method.addFormalParameter(new FormalParameter("value", valueType));

    method.setDescription("sets the " + fieldContext.getString("description") + ".");

    //}}}

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
				 + "field-type");
    }
    String elementType = generator.typeName(fieldTypeContext.getString("element-type"));
    
    String fieldName = fieldContext.getName();
    String methodName = generator.methodName("add-" + fieldName);

    String attrName = generator.attributeName(fieldName);

    String paramName = generator.parameterName(fieldName);
    FormalParameter param = new FormalParameter(paramName, elementType);
    param.setDescription(fieldContext.getString("description"));

    CodeBlock body = new CodeBlock();
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

    unit.addImported("java.util.Collection");

    String fieldName = fieldContext.getName();
    String methodName = generator.methodName("merge-" + fieldName
					     + "-collection");

    String attrName = generator.attributeName(fieldName);

    FormalParameter param = new FormalParameter("collection", "Collection");

    CodeBlock body = new CodeBlock();
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
    if (!fieldTypeContext.getBoolean("collection")) {
      throw new RuntimeException("operation 'fetch-iterator' can only be generated for collections");
    }

    String attrType = generator.typeName(fieldTypeContext);

    String fieldName = fieldContext.getName();
    String methodName = generator.methodName("fetch-" + fieldName
					     + "-iterator");

    String attrName = generator.attributeName(fieldName);

    CodeBlock body = new CodeBlock();
    if (fieldTypeContext.getName().equals("map")) {
      body.addLine("return " + attrName + ".values().iterator();");
    } else {
      body.addLine("return " + attrName + ".iterator();");
    }
    JavaMethod method = createMethod(operationContext, methodName,
				     "Iterator", body);
    method.setDescription("retrieve an iterator for " 
			  + fieldContext.getName() + ".");

    unit.addMethod(method);
    unit.addImported("java.util.Iterator");

    addAttribute(unit, fieldContext, attrName, attrType);
  }

  //}}}
  //{{{ public void generateInit(generator, type, field, operation)

  public void generateInit(JavaGenerator generator,
			   PropertyContext typeContext,
			   PropertyContext fieldContext,
			   PropertyContext operationContext)
  {
    PropertyContext fieldTypeContext = new PropertyContext(fieldContext, "type");
    if (!fieldTypeContext.getBoolean("collection")) {
      throw new RuntimeException("operation 'init' can only be generated for collections");
    }

    JavaCompilationUnit unit = generator.getCompilationUnit();

    String collection = fieldTypeContext.getString("interface");

    String implementation = fieldTypeContext.getString("implementation");
    PropertyContext implementationContext
      = new PropertyContext(fieldTypeContext, "implementation");
    Set imports = implementationContext.getValueSet("import");
    unit.mergeImportedCollection(imports);

    CodeBlock body = new CodeBlock();
    String fieldName = fieldContext.getName();
    String attrName = generator.attributeName(fieldName);
    body.addLine(attrName + " = new " + implementation + "();");
    String methodName
      = generator.methodName("init-" + fieldName + "-" + collection);

    JavaMethod method = createMethod(operationContext, methodName, "void", body);
    method.setDescription("initializes the "
			  + fieldContext.getString("description") + ".");
    unit.addMethod(method);

    String attrType = generator.typeName(fieldTypeContext);
    addAttribute(unit, fieldContext, attrName, attrType);
  }

  //}}}
}
