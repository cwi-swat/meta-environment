package org.autocode.generator;

import org.autocode.property.*;
import org.autocode.property.parser.*;

import java.io.*;
import java.util.*;

public class Main
{
  //{{{ public static final void main(String[] args)

  public static final void main(String[] args)
    throws IOException, ParseException, ClassNotFoundException, InstantiationException, IllegalAccessException
  {
    new Main(args);
  }

  //}}}

  //{{{ private void Main(String[] args)

  private Main(String[] args)
    throws IOException, ParseException, ClassNotFoundException, InstantiationException, IllegalAccessException
  {
    PropertyForest forest;
    String application = "";
    List files = new LinkedList();

    for (int i=0; i<args.length; i++) {
      if (args[i].equals("--define") || args[i].equals("-D")) {
	i++;
      } else if (args[i].equals("--application") || args[i].equals("-a")) {
	application = args[++i];
      } else if (args[i].startsWith("-")) {
	throw new IllegalArgumentException(args[i]);
      } else {
	files.add(args[i]);
      }
    }

    // Read Autocode defaults
    String defaults = "AutocodeGenerator.aco";
    InputStream stream = getClass().getResourceAsStream(defaults);
    Reader reader = new InputStreamReader(stream);
    PropertyParser parser = new PropertyParser(reader);
    forest = parser.PropertyForest();
    reader.close();

    Iterator iter = files.iterator();
    while (iter.hasNext()) {
      String fileName = (String)iter.next();
      reader = new FileReader(fileName);
      PropertyParser.ReInit(reader);
      //parser = new PropertyParser(reader);
      forest.merge(parser.PropertyForest());
      reader.close();
    }

    if (application == null) {
      throw new IllegalArgumentException("missing application");
    }

    PropertyContext root = new PropertyContext(forest);
    Set generators = root.getValueSet("generator");

    PropertyContext appContext = new PropertyContext(root, "application",
						     application);
    String generator = appContext.getSingletonValue("generator");
    if (!generators.contains(generator)) {
      throw new RuntimeException("no such generator: " + generator);
    }

    PropertyContext genContext = new PropertyContext(root, "generator",
						     generator);
    String className = genContext.getSingletonValue("class");

    System.out.println("generator = " + generator + ", " + className);

    defaults = "/" + className.replace('.', '/') + ".aco";
    stream = getClass().getResourceAsStream(defaults);
    reader = new InputStreamReader(stream);
    PropertyParser.ReInit(reader);
    forest.merge(parser.PropertyForest());
    reader.close();

    /*
    Property plugins = def.getApplicationProperty("plugins", application);
    System.out.println("plugins = " + plugins);

    Class generatorClass = Class.forName(className);
    AutocodeGenerator generator = (AutocodeGenerator)generatorClass.newInstance();
    generator.setDataDefinition(def);
    generator.setApplication(application);

    generator.generate();
    generator.emit();
    */
  }

  //}}}
}
