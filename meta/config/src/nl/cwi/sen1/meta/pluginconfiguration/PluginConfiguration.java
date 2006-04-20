package nl.cwi.sen1.meta.pluginconfiguration;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;

import aterm.ATerm;
import aterm.ATermFactory;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class PluginConfiguration {
    private ATermList configuration = null;

    private ATermFactory factory;

    static void usage() {
        System.err.println("usage: pluginconfig"
                + " -config-file <configuration>"
                + "[-add <config.tb> | -remove <config.tb> " + "| -generate]");
        System.exit(0);
    }

    public static void main(String[] args) throws IOException {
        String pluginconfig = null;
        String configfile = null;
        String toolbusscript = null;
        boolean generate = false;
        boolean add = false;

        for (int i = 0; i < args.length; i++) {
            if (args[i].equals("-h")) {
                usage();
            } else if (args[i].equals("-add")) {
                pluginconfig = args[++i];
                add = true;
            } else if (args[i].equals("-remove")) {
                pluginconfig = args[++i];
                add = false;
            } else if (args[i].equals("-generate")) {
                generate = true;
            } else if (args[i].equals("-config-file")) {
                configfile = args[++i];
            } else if (args[i].equals("-toolbus-script")) {
                toolbusscript = args[++i];
            }
        }

        if (configfile == null || (pluginconfig == null && generate == false)
                || (toolbusscript == null && generate == true)) {
            usage();
        } else {
            PluginConfiguration config = new PluginConfiguration();

            config.readConfig(configfile);

            if (pluginconfig != null) {
                config.changeConfig(add, pluginconfig);
                config.writeConfig(configfile);
            }

            if (generate == true) {
                config.generate(toolbusscript);
            }
        }
    }

    public PluginConfiguration() {
        factory = new PureFactory();
    }

    private void generate(String toolbusscript) throws FileNotFoundException {
        PrintWriter out = new PrintWriter(new FileOutputStream(toolbusscript));

        genHeader(out);
        genIncludes(out);
        genFooter(out);

        out.close();
    }

    private void genHeader(PrintWriter out) {
        out.println("#ifndef __INITIALIZE_CONFIG__");
        out.println("#define __INITIALIZE_CONFIG__");
        out.println();
    }

    private void genIncludes(PrintWriter out) {
        while (!configuration.isEmpty()) {
            String include = trimquotes(configuration.getFirst().toString());
            configuration = configuration.getNext();

            out.println("#include <" + include + ">");
        }
    }

    private String trimquotes(String string) {
        return string.substring(1, string.length() - 1);
    }

    private void genFooter(PrintWriter out) {
        out.println();
        out.println("#endif /* __INITIALIZE_CONFIG__ */");
    }

    private void changeConfig(boolean add, String configfile) {
        ATerm config;
        ATermList temp = factory.makeList();
        while (!configuration.isEmpty()) {
            config = configuration.getFirst();
            configuration = configuration.getNext();
            if (!trimquotes(config.toString()).equals(configfile)) {
                temp = temp.append(config);
            }
        }
        configuration = temp.reverse();

        config = factory.make("<str>", configfile);
        if (add == true) {
            configuration = configuration.append(config);
        }
    }

    private void readConfig(String configfile) throws IOException {
        FileInputStream s = null;
        try {
            s = new FileInputStream(configfile);
        } catch (FileNotFoundException e) {
        }

        if (s != null) {
            configuration = (ATermList) factory.readFromFile(s);
        }

        if (configuration == null) {
            configuration = factory.makeList();
        }
    }

    private void writeConfig(String configfile) throws IOException {
        FileOutputStream s = null;
        s = new FileOutputStream(configfile);
        configuration.writeToTextFile(s);
    }
}
