package org.autocode.generator;

import org.autocode.property.*;

import java.util.*;
import java.lang.reflect.Method;

abstract public class AutocodeGenerator
{
  private PropertyContext generatorContext;

  //{{{ public void generate(PropertyContext context)

  public void generate(PropertyContext context)
  {
    generatorContext = context;

    Set types = context.getValueSet("type");
    Iterator iter = types.iterator();
    while (iter.hasNext()) {
      String typeName = (String)iter.next();
      generateType(typeName, new PropertyContext(context, "type", typeName));
    }
  }

  //}}}
  //{{{ protected void generateType(String typeName, PropertyContext context)

  protected void generateType(String typeName, PropertyContext context)
  {
    Set operations = context.getValueSet("operation");
    Iterator iter = operations.iterator();
    while (iter.hasNext()) {
      String operationName = (String)iter.next();
      PropertyContext opContext =
        new PropertyContext(context, "operation", operationName);
      generateTypeOperation(typeName, operationName, opContext);
    }

    Set fields = context.getValueSet("field");
    iter = fields.iterator();
    while (iter.hasNext()) {
      String fieldName = (String)iter.next();
      PropertyContext fieldContext =
        new PropertyContext(context, "field", fieldName);
      generateField(typeName, fieldName, fieldContext);
    }
  }

  //}}}

  //{{{ protected void generateTypeOperation(type, operation, context)

  protected void generateTypeOperation(String typeName,
				       String operationName,
				       PropertyContext typeContext)
  {
    Iterator iter = generatorContext.getValueSet("plugin").iterator();
    while (iter.hasNext()) {
      String pluginName = (String)iter.next();
      PropertyContext pluginContext = new PropertyContext(generatorContext);
      pluginContext.descend("plugin", pluginName);
      pluginContext.descend("provides", "operations");
      Set provides = pluginContext.getValueSet("type");
      if (provides.contains(operationName)) {
	System.out.println("plugin '" + pluginName
			   + "' provides type-operation: " + operationName);
	invokeType(pluginName, typeName, operationName, typeContext);
	return;
      }
    }

    throw new RuntimeException("no plugin found that provides "
			       + "type-operation '" + operationName + "'");
  }

  //}}}

  //{{{ private void invokeType(plugin, type, operation, context)

  private void invokeType(String pluginName, String typeName,
			  String operationName,
			  PropertyContext typeContext)
  {
    Class[] formalParams =
      { this.getClass(), typeContext.getClass(), typeName.getClass() };
    Object[] actualParams = { this, typeContext, typeName };

    PropertyContext pluginContext =
      new PropertyContext(generatorContext, "plugin", pluginName);
    String className = pluginContext.getString("class");

    try {
      Class pluginClass = Class.forName(className);
      String methodName = javaMethodName("generate-" + operationName);
      Method method;
      try {
	method = pluginClass.getMethod(methodName, formalParams);
      } catch (NoSuchMethodException e) {
	System.err.println("Plugin " + pluginName + " cannot generate "
			   + " type-operation: " + operationName);
	return;
      }

      GeneratorPlugin plugin = (GeneratorPlugin)pluginClass.newInstance();
      method.invoke(plugin, actualParams);
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  //}}}

  //{{{ protected void generateField(type, field, fieldContext)

  protected void generateField(String typeName, String fieldName,
			       PropertyContext fieldContext)
  {
    Set operations = fieldContext.getValueSet("operation");
    Iterator iter = operations.iterator();
    while (iter.hasNext()) {
      String operationName = (String)iter.next();
      PropertyContext opContext =
        new PropertyContext(fieldContext, "operation", operationName);
      generateFieldOperation(typeName, fieldName, operationName, opContext);
    }
  }

  //}}}
  //{{{ protected void generateFieldOperation(type, field, operation, context)

  protected void generateFieldOperation(String typeName,
					String fieldName,
					String operationName,
					PropertyContext fieldContext)
  {
    Iterator iter = generatorContext.getValueSet("plugin").iterator();
    while (iter.hasNext()) {
      String pluginName = (String)iter.next();
      PropertyContext pluginContext = new PropertyContext(generatorContext);
      pluginContext.descend("plugin", pluginName);
      pluginContext.descend("provides", "operations");
      Set provides = pluginContext.getValueSet("field");
      if (provides.contains(operationName)) {
	System.out.println("plugin '" + pluginName
			   + "' provides field-operation: " + operationName);
	return;
      }
    }

    throw new RuntimeException("no plugin found that provides "
			       + "field-operation '" + operationName + "'");
  }

  //}}}

  //{{{ public static String capitalize(String word)

  public static String capitalize(String word)
  {
    StringBuffer buf = new StringBuffer();
    buf.append(Character.toUpperCase(word.charAt(0)));
    buf.append(word.substring(1));

    return buf.toString();
  }

  //}}}
  //{{{ public static String loweralize(String word)

  public static String loweralize(String word)
  {
    StringBuffer buf = new StringBuffer();
    buf.append(Character.toLowerCase(word.charAt(0)));
    buf.append(word.substring(1));

    return buf.toString();
  }

  //}}}

  //{{{ public static String javaTypeName(String name)

  public static String javaTypeName(String name)
  {
    StringBuffer buf = new StringBuffer();

    WordIterator iter = new WordIterator(name);
    while (iter.hasNext()) {
      buf.append(capitalize(iter.next()));
    }

    return buf.toString();
  }

  //}}}
  //{{{ public static String javaAttributeName(String name)

  public static String javaAttributeName(String name)
  {
    StringBuffer buf = new StringBuffer("_");

    WordIterator iter = new WordIterator(name);
    buf.append(iter.next());
    while (iter.hasNext()) {
      buf.append(capitalize(iter.next()));
    }

    return buf.toString();
  }

  //}}}
  //{{{ public static String javaMethodName(String name)

  public static String javaMethodName(String name)
  {
    StringBuffer buf = new StringBuffer();

    WordIterator iter = new WordIterator(name);
    buf.append(loweralize((String)iter.next()));
    while (iter.hasNext()) {
      buf.append(capitalize(iter.next()));
    }

    return buf.toString();
  }

  //}}}
  //{{{ public static String javaParameterName(String name)

  public static String javaParameterName(String name)
  {
    StringBuffer buf = new StringBuffer("");
    WordIterator iter = new WordIterator(name);
    buf.append(iter.next());
    while (iter.hasNext()) {
      buf.append(capitalize(iter.next()));
    }

    return buf.toString();
  }

  //}}}
}
