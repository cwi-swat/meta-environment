/*
 * Created on 03.des.2005
 *
 * Copyright (c) 2005, Karl Trygve Kalleberg <karltk@ii.uib.no>
 * 
 * Licensed under the GNU Lesser General Public License, v2.1
 */
package org.spoofax.jsglr;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import aterm.ATerm;

public class Main {

    public static void main(String[] args) throws FileNotFoundException, IOException, InvalidParseTableException {
        
        if(args.length < 2) {
            usage();
        }

        String parseTable = null;
        String input = null;
        String output = null;
        boolean debugging = false;
        boolean logging = false;
        boolean detectCycles = true;
        boolean filter = true;
        
        int skip = 0;
        for(int i=0;i<args.length;i++) {
            if(skip > 0)
                skip--;
            if(args[i].equals("-p")) {
                parseTable = args[i + 1];
                skip = 1;
            } else if(args[i].equals("-i")) {
                input = args[i + 1];
                skip = 1;
            } else if(args[i].equals("-o")) {
                output = args[i + 1];
                skip = 1;
            } else if(args[i].equals("-d")) {
                debugging = true;
            } else if(args[i].equals("-v")) {
                logging = true;
            } else if(args[i].equals("-f")) {
                filter = false;
            } else if(args[i].equals("-c")) {
                detectCycles = false;
            }
        }

        if(parseTable == null)
            usage();
        

        SGLR sglr = new SGLR();

        sglr.setDebug(debugging);
        sglr.setLogging(logging);
        sglr.setCycleDetect(detectCycles);
        sglr.setFilter(filter);
        
        sglr.loadParseTable(new FileInputStream(parseTable));
        InputStream fis = null;
        if(input == null)
            fis = System.in;
        else
            fis = new FileInputStream(input);
        
        OutputStream ous = null;
        if(output != null)
            ous = new FileOutputStream(output);
        else 
            ous = System.out;

        try {
            ATerm t = sglr.parse(fis);
        
            ous.write(t.toString().getBytes());
        } catch(SGLRException e) {
            System.err.println("Parsing failed : " + e);
        }
    }

    private static void usage() {
        System.out.println("Usage: org.spoofax.jsglr.Main -p <parsetable.tbl> -i <inputfile>");
        System.exit(-1);
    }
}
