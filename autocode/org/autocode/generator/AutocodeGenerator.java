package org.autocode.generator;

//{{{ imports

import org.autocode.property.*;

import java.io.*;
import java.util.*;
import java.lang.reflect.Method;

//}}}

abstract public class AutocodeGenerator
{
  private PropertyContext generatorContext;

  abstract public void emit(PropertyContext generatorContext) throws IOException;

  //{{{ public PropertyContext getGeneratorContext()

  public PropertyContext getGeneratorContext()
  {
    return generatorContext;
  }

  //}}}

  //{{{ public void generate(PropertyContext generatorContext)

  public void generate(PropertyContext generatorContext)
  {
    this.generatorContext = generatorContext;

    System.out.println("forest: " + generatorContext.getRootForest());

    Set types = generatorContext.getValueSet("type");
    Iterator iter = types.iterator();
    while (iter.hasNext()) {
      String typeName = (String)iter.next();
      generateType(new PropertyContext(generatorContext, "type", typeName));
    }
  }

  //}}}
  //{{{ protected void generateType(PropertyContext typeContext)

  protected void generateType(PropertyContext typeContext)
  {
    System.out.println("generateType: " + typeContext);
    Set operations = typeContext.getValueSet("operation");
    Iterator iter = operations.iterator();
    while (iter.hasNext()) {
      String operationName = (String)iter.next();
      System.out.println("  operationName: " + operationName);
      PropertyContext operationContext
	= new PropertyContext(typeContext, "operation", operationName);
      generateTypeOperation(typeContext, operationContext);
    }

    Set fields = typeContext.getValueSet("field");
    iter = fields.iterator();
    while (iter.hasNext()) {
      String fieldName = (String)iter.next();
      System.out.println("  fieldName: " + fieldName);
      PropertyContext fieldContext =
        new PropertyContext(typeContext, "field", fieldName);
      generateField(typeContext, fieldContext);
    }
  }

  //}}}
  //{{{ protected void generateTypeOperation(typeContext, operationContext)

  protected void generateTypeOperation(PropertyContext typeContext,
			     PropertyContext operationContext)
  {
    String operationName = operationContext.getName();
    Iterator iter = generatorContext.getValueSet("plugin").iterator();
    while (iter.hasNext()) {
      String pluginName = (String)iter.next();
      PropertyContext pluginContext = new PropertyContext(generatorContext);
      pluginContext.descend("plugin", pluginName);

      PropertyContext providesContext = new PropertyContext(pluginContext);
      providesContext.descend("provides", "operations");

      Set providedOperations = providesContext.getValueSet("type");
      if (providedOperations.contains(operationName)) {
	System.out.println("plugin '" + pluginName
			   + "' provides type-operation: " + operationName);
	invokeType(typeContext, operationContext, pluginContext);
	return;
      }
    }

    throw new RuntimeException("no plugin found that provides "
			       + "type-operation '" + operationName + "'");
  }

  //}}}
  //{{{ private void invokeType(typeContext, operationContext, pluginContext)

  private void invokeType(PropertyContext typeContext,
			  PropertyContext operationContext,
			  PropertyContext pluginContext)
  {
    String typeName = typeContext.getName();
    String operationName = operationContext.getName();
    String pluginName = pluginContext.getName();

    Object[] parameters = { this, typeContext, operationContext };

    String pluginClassName = pluginContext.getString("class");

    try {
      Class pluginClass = Class.forName(pluginClassName);
      String methodName = javaMethodName("generate-" + operationName);
      Method method;
      try {
	method = pluginClass.getMethod(methodName, getFormalParameters(parameters));
      } catch (NoSuchMethodException e) {
	System.err.println("Plugin " + pluginName + " cannot generate "
			   + " type-operation: " + operationName);
	return;
      }

      GeneratorPlugin plugin = (GeneratorPlugin)pluginClass.newInstance();
      method.invoke(plugin, parameters);
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  //}}}

  //{{{ protected void generateField(typeContext, fieldContext)

  protected void generateField(PropertyContext typeContext,
			       PropertyContext fieldContext)
  {
    Set operations = fieldContext.getValueSet("operation");
    Iterator iter = operations.iterator();
    while (iter.hasNext()) {
      PropertyContext operationContext
	= new PropertyContext(fieldContext, "operation", (String)iter.next());
      generateFieldOperation(typeContext, fieldContext, operationContext);
    }
  }

  //}}}
  //{{{ protected void generateFieldOperation(typeContext, fieldContext, operationContext)

  protected void generateFieldOperation(PropertyContext typeContext,
				       	PropertyContext fieldContext,
					PropertyContext operationContext)
  {
    String typeName = typeContext.getName();
    String operationName = operationContext.getName();
    Iterator iter = generatorContext.getValueSet("plugin").iterator();
    while (iter.hasNext()) {
      String pluginName = (String)iter.next();
      PropertyContext pluginContext = new PropertyContext(generatorContext);
      pluginContext.descend("plugin", pluginName);

      PropertyContext providesContext = new PropertyContext(pluginContext);
      providesContext.descend("provides", "operations");
      Set providedOperations = providesContext.getValueSet("field");
      if (providedOperations.contains(operationName)) {
	System.out.println("plugin '" + pluginName
			   + "' provides field-operation: " + operationName);
	invokeField(typeContext, fieldContext, operationContext, pluginContext);
	return;
      }
    }

    throw new RuntimeException("no plugin found that provides "
			       + "field-operation '" + operationName + "'");
  }

  //}}}
  //{{{ protected void invokeField(typeContext, fieldContext, operationContext, pluginContext)

  protected void invokeField(PropertyContext typeContext,
			     PropertyContext fieldContext,
			     PropertyContext operationContext,
			     PropertyContext pluginContext)
  {
    String typeName = typeContext.getName();
    String fieldName = fieldContext.getName();
    String operationName = operationContext.getName();
    String pluginName = pluginContext.getName();

    Object[] parameters = { this, typeContext, fieldContext, operationContext };

    String className = pluginContext.getString("class");
    try {
      Class pluginClass = Class.forName(className);
      String methodName = javaMethodName("generate-" + operationName);
      Method method;
      try {
	method = pluginClass.getMethod(methodName,
				       getFormalParameters(parameters));
      } catch(NoSuchMethodException e) {
	System.err.println("Plugin " + pluginName + " cannot generate "
			   + " field-operation: "+ operationName);
	return;
      }

      GeneratorPlugin plugin = (GeneratorPlugin)pluginClass.newInstance();
      method.invoke(plugin, parameters);
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  //}}}

  //{{{ private Class[] getFormalParameters(Object[] actualParams)

  private Class[] getFormalParameters(Object[] actualParams)
  {
    Class[] formalParams = new Class[actualParams.length];
    for (int i=0; i<actualParams.length; i++) {
      formalParams[i] = actualParams[i].getClass();
    }
    return formalParams;
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
