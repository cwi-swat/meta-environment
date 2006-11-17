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
import java.io.InvalidClassException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Vector;

import aterm.ATerm;
import aterm.pure.ATermImpl;
import aterm.pure.PureFactory;

public class SGLR {

    // FIXME: Should probably be put elsewhere
    private static final int EOF = 256;

    private PureFactory factory;

    private Frame acceptingStack;

    private List<Frame> activeStacks;

    private ParseTable parseTable;

    private int currentToken;

    private int tokensSeen;

    private int lineNumber;

    private int columnNumber;

    private Queue<ActionState> forShifter;

    private Queue<Frame> forActor;

    private Queue<Frame> forActorDelayed;

    private int maxBranches;

    private int maxToken;

    private int maxLine;

    private int maxColumn;

    private int maxTokenNumber;

    private static boolean debugging;

    private boolean logging;

    private AmbiguityManager ambiguityManager;

    private boolean detectCycles;

    private boolean filter;

    private PostFilter postFilter;

    private boolean rejectFilter;

    private boolean associtivityFilter;

    private boolean priorityFilter;

    private boolean injectionCountFilter;

    private int rejectCount;
    
    private int reductionCount;
    

    SGLR() {
        basicInit(null);
    }

    public SGLR(InputStream is) throws IOException, InvalidParseTableException {
        basicInit(null);
        loadParseTable(is);
    }

    public SGLR(PureFactory pf, InputStream is) throws IOException, InvalidParseTableException {
        basicInit(pf);
        loadParseTable(is);
    }

    static final Map<String, ParseTable> parseTables = new HashMap<String, ParseTable>();

    public SGLR(final PureFactory pf, String parseTableFileName) throws IOException, InvalidParseTableException {

        assert factory == null;
        assert parseTable == null;

        // Try to get cached
        parseTable = parseTables.get(parseTableFileName);
        if(parseTable != null) {

            basicInit((PureFactory)parseTable.getFactory());

        } else {

            // Init with a new factory for both serialized or BAF instances.
            basicInit(pf);

            // Try to load from serialized form
            boolean tableWasPersisted = false;
            try {
                final FileInputStream in = new FileInputStream(parseTableFileName + ".bin");
                ObjectInputStream reader = new ObjectInputStream(in);

                // todo: find a better solution to make the current factory available to the various readResolve()
                ATermImpl.the_factory = getFactory();
                parseTable = (ParseTable)reader.readObject();
                in.close();
                reader.close();
                forceGC();
                parseTable.initAFuns(getFactory());

                tableWasPersisted = true;
            }
            catch (ClassNotFoundException e) {
                throw new RuntimeException(e);
            }
            catch (InvalidClassException e) {
                // ... some problem loading; load from TBL file
                loadParseTable(new FileInputStream(parseTableFileName));

            } catch (FileNotFoundException e) {
                // ... not present or some other problem loading; load from TBL file
                loadParseTable(new FileInputStream(parseTableFileName));
            }

            // Cache
            parseTables.put(parseTableFileName, parseTable);

            // If not serialized then save it in this form
            if(!tableWasPersisted) {
                try {
                    final FileOutputStream out = new FileOutputStream(parseTableFileName + ".bin");
                    ObjectOutputStream writer = new ObjectOutputStream(out);
                    writer.writeObject(parseTable);

                    writer.close();
                    out.close();
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

    }

    public static void forceGC() {
        System.gc();
        try {
            Thread.sleep(200); // Allows gc to do its work.
        } catch (InterruptedException e) {
            throw new Error(e);
        }
    }

    private void basicInit(PureFactory pf) {
        debugging = false;
        detectCycles = true;
        logging = false;
        factory = pf;
        if (factory == null)
            factory = new PureFactory();
        activeStacks = new Vector<Frame>();

        forActor = new LinkedList<Frame>();
        forActorDelayed = new LinkedList<Frame>();
        forShifter = new LinkedList<ActionState>();

        // FIXME This is *wrong*
        ambiguityManager = new AmbiguityManager(10000);
        
        // FIXME filter flags should probably be moved to PostFilter class 
        filter = true;
        rejectFilter = true;
        injectionCountFilter = true;
        priorityFilter = true;
        associtivityFilter = true;
        
        postFilter = new PostFilter(this);
    }

    public static boolean isDebugging() {
        return debugging;
    }

    public boolean isLogging() {
        return logging;
    }

    public void setLogging(boolean enableLogging) {
        logging = enableLogging;
        Tools.setOutput(".jsglr-log");
    }

    public void setDebug(boolean enableDebug) {
        debugging = enableDebug;
    }

    public void loadParseTable(InputStream r) throws IOException, InvalidParseTableException {
        if(isDebugging()) {
        	Tools.debug("loadParseTable()");
        }
        long start = System.currentTimeMillis();
        ATerm pt = factory.readFromFile(r);

        parseTable = new ParseTable(pt);
        long elapsed = System.currentTimeMillis() - start;

        if (isLogging()) {
            Tools.logger("Loading parse table took " + elapsed/1000.0f + "s");
            Tools.logger("No. of states: ", parseTable.getStateCount());
            Tools.logger("No. of productions: ", parseTable.getProductionCount());
            Tools.logger("No. of action entries: ", parseTable.getActionCount());
            Tools.logger("No. of gotos entries: ", parseTable.getGotoCount());

            Tools.logger((parseTable.hasRejects() ? "Includes" : "Excludes"), " rejects");
            Tools.logger((parseTable.hasPriorities() ? "Includes" : "Excludes"), " priorities");
            Tools.logger((parseTable.hasPrefers() ? "Includes" : "Excludes"), " prefer actions");
            Tools.logger((parseTable.hasAvoids() ? "Includes" : "Excludes"), " avoid actions");
        }
    }

    /**
     * Initializes the active stacks. At the start of parsing there is only one
     * active stack, and this stack contains the start symbol obtained from the
     * parse table.
     *
     * @return the initial stack
     */
    private Frame initActiveStacks() {
        activeStacks.clear();
        Frame st0 = new Frame(parseTable.getInitialState());
        activeStacks.add(st0);
        return st0;
    }

    public ATerm parse(InputStream fis) throws IOException, SGLRException {

        if (isDebugging()) {
            Tools.debug("parse() - ", dumpActiveStacks());
        }

        long start = System.currentTimeMillis();

        tokensSeen = 0;
        columnNumber = 0;
        lineNumber = 1;

        acceptingStack = null;
        Frame st0 = initActiveStacks();

        bootstrapTemporaryObjectsOnce();

        do {
            if (isLogging()) {
                Tools.logger("Current token (#", tokensSeen, "): ", charify(currentToken));
            }

            currentToken = getNextToken(fis);

            //PoolContext.enter(); //todo managed
            //Path.FACTORY.attach(PoolContext.current());  //todo managed

            parseCharacter();
            shifter();

            //PoolContext.exit(); //todo managed

        } while (currentToken != SGLR.EOF && activeStacks.size() > 0);

        if (isLogging()) {
            Tools.logger("Number of lines: ", lineNumber);
            Tools.logger("Maximum ", maxBranches, " parse branches reached at token ",
                         charify(maxToken), ", line ", maxLine, ", column ", maxColumn,
                         " (token #", maxTokenNumber, ")");

            long elapsed = System.currentTimeMillis() - start;
            Tools.logger("Parse time: " + elapsed/1000.0f + "s");
        }

        if(isDebugging()) {
            Tools.debug("Parsing complete: all tokens read");
        }

        if (acceptingStack == null)
            return null;

        if(isDebugging()) {
            Tools.debug("Accepting stack exists");
        }

        Link s = acceptingStack.findLink(st0);

        if(s == null)
            throw new ParseException("Accepting stack has no link");
        
        if(isDebugging()) {
            Tools.debug("internal parse tree:\n", s.label);
        }
        
        return postFilter.applyFilters(s.label, null, tokensSeen);
        
    }

    private static boolean doBootstrap = false; //todo managed
    
    public void bootstrapTemporaryObjectsOnce() {
        if(doBootstrap) {
            //todo managed
//            PoolContext.enter();
//
//            Path.FACTORY.attach(PoolContext.current());
//
//            for(int i = 0; i < 500000; i++) {
//                Path.FACTORY.object();
//            }
//            PoolContext.exit();
//            doBootstrap = false;
//
//            Path.logNewInstanceCreation = true;
        }
    }

    private void shifter() {
        if (isLogging()) {
            Tools.logger("#", tokensSeen, ": shifting ", forShifter.size(), " parser(s) -- token ",
                         charify(currentToken), ", line ", lineNumber, ", column ", columnNumber);
        }

        if (isDebugging()) {
            Tools.debug("shifter() - " + dumpActiveStacks());

            Tools.debug(" token   : " + currentToken);
            Tools.debug(" parsers : " + forShifter.size());
        }
        clearActiveStacks(false);

        IParseNode prod = parseTable.lookupProduction(currentToken);

        while (forShifter.size() > 0) {
            ActionState as = forShifter.remove();

            Frame st1 = findStack(activeStacks, as.s);
            if (st1 == null) {
                st1 = new Frame(as.s);
                activeStacks.add(st1);
            }
            st1.addLink(as.st, prod, 1);
        }

    }

    private String charify(int currentToken) {
        switch (currentToken) {
        case 32:
            return "\\32";
        case 256:
            return "EOF";
        case '\n':
            return "\\n";
        case 0:
            return "\\0";
        default:
            return "" + (char) currentToken;
        }
    }

    private void parseCharacter() {

        if (isDebugging()) {
            Tools.debug("parseCharacter() - " + dumpActiveStacks());
            Tools.debug(" # active stacks : " + activeStacks.size());
        }

        /*forActor = */computeStackOfStacks(activeStacks);

        if (isDebugging()) {
            Tools.debug(" # for actor     : " + forActor.size());
        }

        clearForActorDelayed(false); //todo: use true?
        clearForShifter(false); //todo: use true?

        while (forActor.size() > 0 || forActorDelayed.size() > 0) {
            if (forActor.size() == 0) {
                forActor.add(forActorDelayed.remove());
            }
            if (forActor.size() > 0) {
                Frame st = forActor.remove();
                if (!st.allLinksRejected()) {
                    actor(st);
                }
            }
        }
    }

    private void actor(Frame st) {

        if (isDebugging()) {
            Tools.debug("actor() - ", dumpActiveStacks());
        }

        State s = st.peek();

        if (isDebugging()) {
            Tools.debug(" state   : ", s.stateNumber);
            Tools.debug(" token   : ", currentToken);
        }

        List<ActionItem> actionItems = s.getActionItems(currentToken);

        if (isDebugging()) {
            Tools.debug(" actions : ", actionItems);
        }

        for (ActionItem ai : actionItems) {
            if (ai instanceof Shift) {
                Shift sh = (Shift) ai;
                forShifter.add(new ActionState(st, parseTable.getState(sh.nextState)));
                statsRecordParsers();
            } else if (ai instanceof Reduce) {
                Reduce red = (Reduce) ai;
                doReductions(st, red.production);
            } else if (ai instanceof Accept) {
                acceptingStack = st;
                if (isLogging()) {
                    Tools.logger("Reached the accept state");
                }
            }
        }
    }

    private void statsRecordParsers() {
        if (forShifter.size() > maxBranches) {
            maxBranches = forShifter.size();
            maxToken = currentToken;
            maxColumn = columnNumber;
            maxLine = lineNumber;
            maxTokenNumber = tokensSeen;
        }
    }

    private void doReductions(Frame st, Production prod) {

        if (isDebugging()) {
            Tools.debug("doReductions() - " + dumpActiveStacks());

            Tools.debug(" state : " + st.peek().stateNumber);
            Tools.debug(" token : " + currentToken);
            Tools.debug(" label : " + prod.label);
            Tools.debug(" arity : " + prod.arity);
            Tools.debug(" stack : " + st.dumpStack());
        }

        List<Path> paths = st.computePathsToRoot(prod.arity);

        final int pathsCount = paths.size();
        if (isDebugging()) {
            Tools.debug(" paths : " + pathsCount);
        }

        for (int i = 0; i < pathsCount; i++) {
            Path path = paths.get(i);

            List<IParseNode> kids = path.getATerms();

            if (isDebugging()) {
                Tools.debug(" path: ", path);
                Tools.debug(" kids: ", kids);
            }

            Frame st0 = path.getEnd();

            if (isDebugging()) {
                Tools.debug(st0.state);
            }

            State next = parseTable.go(st0.peek(), prod.label);

            if (isLogging()) {
                Tools.logger("Goto(", st0.peek().stateNumber, ",", prod.label + ") == ",
                             next.stateNumber);
            }

            reducer(st0, next, prod, kids, path.getLength());
        }

        activeStacks.remove(st);

        paths.clear();

        if (isDebugging()) {
            Tools.debug("<doReductions() - " + dumpActiveStacks());
        }
    }

    private void reducer(Frame st0, State s, Production prod, List<IParseNode> kids, int length) {

        if (isLogging()) {
            Tools.logger("Reducing; state ", s.stateNumber, ", token: ", charify(currentToken),
                         ", production: ", prod.label);
        }

        if (isDebugging()) {
            Tools.debug("reducer() - ", dumpActiveStacks());

            Tools.debug(" state      : ", s.stateNumber);
            Tools.debug(" token      : ", charify(currentToken) + " (" + currentToken + ")");
            Tools.debug(" production : ", prod.label);
        }

        increaseReductionCount();
        
        IParseNode t = prod.apply(kids);

        Frame st1 = findStack(activeStacks, s);
        if (st1 == null) {
            /* Found no existing stack with for state s; make new stack */
            st1 = new Frame(s);
            Link nl = st1.addLink(st0, t, length);
            activeStacks.add(st1);
            if (st1.peek().rejectable()) {
                forActorDelayed.add(st1);
            } else {
                forActor.add(st1);
            }

            if (prod.status == Production.REJECT) {
                if (isLogging()) {
                    Tools.logger("Reject [new]");
                }
                nl.reject();
                increaseRejectCount();
            }
        } else {
            /* A stack with state s exists; check for ambiguities */
            Link nl = st1.findLink(st0);

            if (nl != null) {
                if (isLogging()) {
                    Tools.logger("Ambiguity: direct link ", st0.state.stateNumber, " -> ",
                                 st1.state.stateNumber, " ", (prod.isReject() ? "{reject}" : ""));
                    if(nl.label instanceof ParseNode) {
                        Tools.logger("nl is ", nl.isRejected() ? "{reject}" : "", " for ", ((ParseNode)nl.label).label);
                    }
                }
                
                if(isDebugging()) {
                    Tools.debug("createAmbiguityCluster - ", tokensSeen - nl.getLength() - 1, "/", nl.getLength());
                }
                
                
                new Amb(nl.label, t);
                nl.addAmbiguity(t);
                
                //ambiguityManager.createAmbiguityCluster(nl.label, t, tokensSeen - nl.getLength() - 1);
                

                if (prod.isReject()) {
                    nl.reject();
                }

            } else {
                nl = st1.addLink(st0, t, length);
                if (isDebugging()) {
                    Tools.debug(" added link ", nl, " from ", st1.state.stateNumber, " to ",
                                st0.state.stateNumber);
                }

                if (prod.isReject())
                    nl.reject();

                // Note: ActiveStacks can be modified inside doLimitedReductions
                for (int i = 0; i< activeStacks.size(); i++) {
                    Frame st2 = activeStacks.get(i);
                    if (st2.allLinksRejected())
                        continue;
                    if (forActor.contains(st2))
                        continue;
                    if (forActorDelayed.contains(st2))
                        continue;

                    for (ActionItem ai : st2.peek().getActionItems(currentToken)) {
                        if (ai instanceof Reduce) {
                            Reduce red = (Reduce) ai;
                            doLimitedReductions(st2, red.production, nl);
                        }
                    }

                }
            }
        }
    }

    private void increaseReductionCount() {
        reductionCount++;
    }

    protected void increaseRejectCount() {
        rejectCount++;
    }
    
    protected int getRejectCount() {
        return rejectCount;
    }

    private Frame findStack(List<Frame> stacks, State s) {
        // We need only check the top frames of the active stacks.
        if (isDebugging()) {
            Tools.debug("findStack() - ", dumpActiveStacks());
            Tools.debug(" looking for ", s.stateNumber);
        }

        final int size = stacks.size();
        for (int i = 0; i < size; i++) {
            if (stacks.get(i).state.stateNumber == s.stateNumber) {
                return stacks.get(i);
            }
        }
        return null;
    }

    private void doLimitedReductions(Frame st, Production prod, Link l) {
        if (isDebugging()) {
            Tools.debug("doLimitedReductions() - ", dumpActiveStacks());

            Tools.debug(" state : ", st.peek().stateNumber);
            Tools.debug(" token : ", currentToken);
            Tools.debug(" label : ", prod.label);
            Tools.debug(" arity : ", prod.arity);
            Tools.debug(" stack : ", st.dumpStack());
        }

        List<Path> paths = st.computePathsToRoot(prod.arity, l);

        if (isDebugging()) {
            Tools.debug(paths);
        }

        final int pathsCount = paths.size();
        for (int i = 0; i < pathsCount; i++) {
            Path path = paths.get(i);

            List<IParseNode> kids = path.getATerms();

            if (isDebugging()) {
                Tools.debug(path);
            }

            Frame st0 = path.getEnd();

            if (isDebugging()) {
                Tools.debug(st0.state);
            }
            State next = parseTable.go(st0.peek(), prod.label);

            if (isLogging()) {
                Tools.logger("Goto(", st0.peek().stateNumber, ",", prod.label, ") == ",
                             next.stateNumber);
            }

            reducer(st0, next, prod, kids, path.getLength());
        }
        paths.clear();
    }

    private /*Stack<Frame> */void computeStackOfStacks(List<Frame> st) {
        clearForActor(false);
        Queue<Frame> ret = forActor;
        final int size = st.size();
        for (int i = 0; i < size; i++) {
            ret.add(st.get(i));
        }
    }

    private int getNextToken(InputStream fis) throws IOException {
        int t = fis.read();

        tokensSeen++;

        if (isDebugging()) {
            Tools.debug("getNextToken() - ", t);
        }

        switch(t) {
        case '\n':
            lineNumber++;
            columnNumber = 0;
            break;
        case '\t':
            columnNumber = (columnNumber / 8 + 1 ) * 8;
            break;
        case -1:
            return SGLR.EOF;
        default:
            columnNumber++;
        }

        return t;
    }

    private String dumpActiveStacks() {
        StringBuffer sb = new StringBuffer();
        boolean first = true;
        if (activeStacks == null) {
            sb.append(" GSS unitialized");
        } else {
            sb.append("{").append(activeStacks.size()).append("} ");
            for (Frame f : activeStacks) {
                if (!first)
                    sb.append(", ");
                sb.append(f.dumpStack());
                first = false;
            }
        }
        return sb.toString();
    }

    public void setCycleDetect(boolean detectCycles) {
        this.detectCycles = detectCycles;
    }

    public boolean isDetectCyclesEnabled() {
        return filter && detectCycles;
    }

    public void setFilter(boolean filter) {
        this.filter = filter;
    }

    public void clear() {
        if(this.acceptingStack != null) {
            this.acceptingStack.clear();
        }

        clearActiveStacks(true);
        clearForActorDelayed(true);
        clearForActor(true);
        clearForShifter(true);

        this.parseTable = null;
        this.factory = null;
        this.ambiguityManager = null; //todo clear
    }

    private void clearForShifter(boolean all) {
        if (all) {
            for (ActionState as : forShifter) {
                as.clear(all);
            }
        }
        this.forShifter.clear();
    }

    private void clearForActor(boolean all) {
        if(all) {
            for(Frame frame : forActor) {
                frame.clear();
            }
        }
        forActor.clear();
    }

    private void clearForActorDelayed(boolean all) {
        if (all) {
            for(Frame frame : forActorDelayed) {
                frame.clear();
            }
        }
        forActorDelayed.clear();
    }

    private void clearActiveStacks(boolean all) {
        if (all) {
            for (int i = 0; i < activeStacks.size(); i++) {
                Frame frame = activeStacks.get(i);
                frame.clear();
            }
        }
        activeStacks.clear();
    }

    public boolean isFilteringEnabled() {
        return filter;
    }

    ParseTable getParseTable() {
        return parseTable;
    }

    AmbiguityManager getAmbiguityManager() {
        return ambiguityManager;
    }

    public boolean isRejectFilterEnabled() {
        return filter && rejectFilter;
    }

    public boolean isAssociativityFilterEnabled() {
        return filter && associtivityFilter;
    }

    public boolean isPriorityFilterEnabled() {
        return filter && priorityFilter;
    }

    public PureFactory getFactory() {
        return factory;
    }

    public boolean isInjectionCountFilterEnabled() {
        return filter && injectionCountFilter;
    }

    public int getReductionCount() {
        return reductionCount;
    }
    
    public int getRejectionCount() {
        return rejectCount;
    }
}
