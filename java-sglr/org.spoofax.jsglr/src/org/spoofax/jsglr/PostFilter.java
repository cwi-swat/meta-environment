/*
 * Created on 11.apr.2006
 *
 * Copyright (c) 2005, Karl Trygve Kalleberg <karltk@ii.uib.no>
 * 
 * Licensed under the GNU General Public License, v2
 */
package org.spoofax.jsglr;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import aterm.AFun;
import aterm.ATerm;

public class PostFilter {

    private static final int FILTER_DRAW = 1;

    private static final int FILTER_LEFT_WINS = 2;

    private static final int FILTER_RIGHT_WINS = 3;

    SGLR parser;

    AmbiguityManager ambiguityManager;

    ParseTable parseTable;

    Map<AmbKey, Integer> posTable;

    Map<AmbKey, IParseNode> resolvedTable;

    private AmbiguityMap markMap;

    private int parseTreePosition;

    PostFilter(SGLR parser) {
        this.parser = parser;
        resolvedTable = new HashMap<AmbKey, IParseNode>();
        posTable = new HashMap<AmbKey, Integer>();
    }

    private void initializeFromParser() {
        parseTable = parser.getParseTable();
        ambiguityManager = parser.getAmbiguityManager();
    }

    protected ATerm applyFilters(IParseNode root, String sort, int inputLength) throws SGLRException {
        
        if(SGLR.isDebugging()) {
            Tools.debug("applyFilters()");
        }
        
        initializeFromParser();

        IParseNode t = root;

        t = applyTopSortFilter(sort, t);

        t = applyCycleDetectFilter(t);

        t = applyOtherFilters(t);

        return convertToATerm(t);
        
    }

    private ATerm convertToATerm(IParseNode t) {
        
        if (SGLR.isDebugging()) {
            Tools.debug("convertToATerm: ", t);
        }

        ambiguityManager.resetAmbiguityCount();
        ATerm r = yieldTree(t);
        
        logStatus();
        
        int ambCount = ambiguityManager.getAmbiguitiesCount();
        if (SGLR.isDebugging()) {
            Tools.debug("yield: ", r);
        }
        final AFun parseTreeAfun = parseTable.getFactory().makeAFun("parsetree", 2, false);
        return parseTable.getFactory().makeAppl(parseTreeAfun, r,
                                                parseTable.getFactory().makeInt(ambCount));
    }

    private IParseNode applyOtherFilters(IParseNode t) throws FilterException {

        if (SGLR.isDebugging()) {
            Tools.debug("applyOtherFilters() - ", t);
        }

        if (parser.isFilteringEnabled()) {
            t = filterTree(t);
        }
        return t;
    }

    private IParseNode applyCycleDetectFilter(IParseNode t) throws FilterException {
        
        if (SGLR.isDebugging()) {
            Tools.debug("applyCycleDetectFilter() - ", t);
        }

        if (parser.isDetectCyclesEnabled()) {
            if (ambiguityManager.getMaxNumberOfAmbiguities() > 0) {
                if (isCyclicTerm(t)) {
                    throw new FilterException("Term is cyclic");
                }
            }
        }

        return t;
    }

    private IParseNode applyTopSortFilter(String sort, IParseNode t) throws SGLRException {

        if (SGLR.isDebugging()) {
            Tools.debug("applyTopSortFilter() - ", t);
        }

        if (sort != null) {
            t = selectOnTopSort();
            if (t == null) {
                throw new FilterException("Desired top sort not found");
            }
        }
        
        return t;
    }

    private void logStatus() {
        Tools.logger("Number of rejects: ", parser.getRejectCount());
        Tools.logger("Number of reductions: ", parser.getReductionCount());
        Tools.logger("Number of ambiguities: ", ambiguityManager.getMaxNumberOfAmbiguities());
        Tools.logger("Number of calls to Amb: ", ambiguityManager.getAmbiguityCallsCount());
        Tools.logger("Count Eagerness Comparisons: ", ambiguityManager.getEagernessComparisonCount(), " / ", ambiguityManager.getEagernessSucceededCount());
        Tools.logger("Number of Injection Counts: ", ambiguityManager.getInjectionCount());
    }

    private ATerm yieldTree(IParseNode t) {
        return t.toParseTree(parser.getParseTable());
    }

    private IParseNode filterTree(IParseNode t) throws FilterException {
        ambiguityManager.resetClustersVisitedCount();
        return filterTree(t, 0, false);
    }

    private IParseNode filterTree(IParseNode t, int pos, boolean inAmbiguityCluster) throws FilterException {

        if (SGLR.isDebugging()) {
            Tools.debug("filterTree(node)    - ", t);
        }

        if (t instanceof Amb) {
            if (!inAmbiguityCluster) {
                LinkedList<IParseNode> ambs = new LinkedList<IParseNode>();
                ambs.add((Amb)t);
                t = filterAmbiguities(ambs, pos);
            }
        } else if(t instanceof ParseNode) {
            ParseNode node = (ParseNode) t;
            List<IParseNode> args = node.getKids();
            List<IParseNode> newArgs = filterTree(args, pos, false);

            if (parser.isRejectFilterEnabled() && parseTable.hasRejects()) {
                if (hasRejectProd(t))
                    throw new FilterException("");
            }

            t = new ParseNode(node.label, newArgs);
        } else if(t instanceof ParseProductionNode) {
            // do nothing
        } else {
            throw new FatalException();
        }

        if (parser.isFilteringEnabled()) {
            return applyAssociativityPriorityFilter(t);
        } else {
            return t;
        }
    }

    private List<IParseNode> filterTree(List<IParseNode> args, int pos, boolean inAmbiguityCluster) throws FilterException {

        if(SGLR.isDebugging()) {
            Tools.debug("filterTree(<nodes>) - ", args);
        }
        
        List<IParseNode> newArgs = new LinkedList<IParseNode>();
        boolean changed = false;

        for (IParseNode n : args) {
            IParseNode filtered = filterTree(n, pos, false);
            
            changed = !filtered.equals(n) || changed;
            newArgs.add(filtered);
        }

        /*
         * FIXME Shouldn't we do some filtering here?
        if (!changed) {
            Tools.debug("Dropping: ", args);
            newArgs = getEmptyList();
        }*/

        if (parser.isFilteringEnabled()) {
            List<IParseNode> filtered = new ArrayList<IParseNode>();
            for (IParseNode n : newArgs)
                filtered.add(applyAssociativityPriorityFilter(n));
            return filtered;
        } else {
            return newArgs;
        }
    }

    private IParseNode applyAssociativityPriorityFilter(IParseNode t) throws FilterException {
        // SG_Associativity_Priority_Filter(pt, t)   
        // - ok
        
        if(SGLR.isDebugging()) {
            Tools.debug("applyAssociativityPriorityFilter() - ", t);
        }
        
        IParseNode r = t;

        if (t instanceof ParseNode) {
            Label prodLabel = getProductionLabel(t);
            ParseNode n = (ParseNode) t;

            if (parser.isAssociativityFilterEnabled()) {
                if (prodLabel.isLeftAssociative()) {
                    r = applyLeftAssociativeFilter(n, prodLabel);
                } else if (prodLabel.isRightAssociative()) {
                    r = applyRightAssociativeFilter(n, prodLabel);
                }
                
            }

            if (parser.isPriorityFilterEnabled()) {
                Tools.debug(" - about to look up : ",  prodLabel.labelNumber);
                if (!lookupGtrPriority(prodLabel).isEmpty()) {
                    Tools.debug(" - found");
                    return applyPriorityFilter((ParseNode) r, prodLabel);
                }
                Tools.debug(" - not found");
            }
        }

        return r;
    }

    private IParseNode applyRightAssociativeFilter(ParseNode t, Label prodLabel) throws FilterException {
        // SG_Right_Associativity_Filter(t, prodl)
        // - almost ok
        
        if(SGLR.isDebugging()) {
            Tools.debug("applyRightAssociativeFilter() - ", t);
        }
        
        List<IParseNode> newAmbiguities = new LinkedList<IParseNode>();
        List<IParseNode> kids = t.getKids();
        IParseNode firstKid = kids.get(0);
        
        if(firstKid instanceof Amb) {
            
            List<IParseNode> ambs = ((Amb)firstKid).getAlternatives();
            List<IParseNode> restKids = kids.subList(1, t.kids.size() - 1);
            
            for(IParseNode amb : ambs) {
                if(((ParseNode)amb).getLabel() != prodLabel.labelNumber) {
                    newAmbiguities.add(amb);
                }
            }
        
            // FIXME is this correct?
            if(!newAmbiguities.isEmpty()) {
                if(newAmbiguities.size() > 1)
                    firstKid = new Amb(newAmbiguities);
                else 
                    firstKid = newAmbiguities.get(0);
                restKids.add(firstKid);
            } else {
                throw new FilterException("");
            }
            
            // FIXME is this correct?
            return new ParseNode(t.label, restKids);
            
        } else if(firstKid instanceof ParseNode) {
            if(((ParseNode)firstKid).getLabel() == prodLabel.labelNumber)
                throw new FilterException("");
        }
        return t;
    }

    private IParseNode applyPriorityFilter(ParseNode t, Label prodLabel) throws FilterException {
        // SG_Priority_Filter
        // - fishy
        
        if(SGLR.isDebugging()) {
            Tools.debug("applyPriorityFilter() - ", t);
        }
        
        List<IParseNode> newAmbiguities = new ArrayList<IParseNode>();
        List<IParseNode> kids = t.getKids();
        List<IParseNode> newKids = new LinkedList<IParseNode>();
        
        int l0 = prodLabel.labelNumber;

        for (IParseNode alt : kids) {
            IParseNode newKid = alt;
            IParseNode injection = jumpOverInjections(alt);

            if (injection instanceof Amb) {
                List<IParseNode> ambs = ((Amb) injection).getAlternatives();

                newAmbiguities.clear();
                for (IParseNode amb : ambs) {
                    IParseNode injAmb = jumpOverInjections(amb);

                    if (injAmb instanceof ParseNode) {
                        Label label = getProductionLabel(t);
                        if(hasGreaterPriority(l0, label.labelNumber)) {
                            newAmbiguities.add(amb);
                        }
                    }
                }
                
                if(!newAmbiguities.isEmpty()) {
                    IParseNode n = null;
                    if(newAmbiguities.size() > 1) {
                        n = new Amb(newAmbiguities);
                    } else {
                        n = newAmbiguities.get(0);
                    }
                    newKid = replaceUnderInjections(alt, injection, n);
                } else {
                    throw new FilterException("");
                }
            } else if (injection instanceof ParseNode) {
                int l1 = ((ParseNode) injection).label;
                if (hasGreaterPriority(l0, l1)) {
                    throw new FilterException("");
                }
            }
            
            newKids.add(newKid);
        }

        return new ParseNode(t.label, newKids);
    }

    private IParseNode replaceUnderInjections(IParseNode alt, IParseNode injection, IParseNode n) {
        // SG_Replace_Under_Injections
        // - not ok
        
        throw new NotImplementedException();
    }

    private IParseNode jumpOverInjections(IParseNode t) {

        if(SGLR.isDebugging()) {
            Tools.debug("jumpOverInjections() - ", t);
        }

        if (t instanceof ParseNode) {
            int prod = ((ParseNode) t).label;
            ParseNode n = (ParseNode)t;
            while (isUserDefinedLabel(prod)) {
                List<IParseNode> kids = n.getKids();
                IParseNode x = kids.get(0);
                if(x instanceof ParseNode) {
                    n = (ParseNode)x;
                    prod = n.label; 
                } else {
                    return x;
                }
            }
        }

        return t;
    }

    private boolean isUserDefinedLabel(int prod) {
        Label l = parseTable.lookupInjection(prod);
        if(l == null)
            return false;
        return l.isInjection();
    }

    private boolean hasGreaterPriority(int l0, int l1) {
        List<Label> prios = lookupGtrPriority(parseTable.getLabel(l0));
        return prios.contains(parseTable.getLabel(l1));
    }

    private List<Label> lookupGtrPriority(Label prodLabel) {
        return parseTable.getPriorities(prodLabel);
    }

    private IParseNode applyLeftAssociativeFilter(ParseNode t, Label prodLabel) throws FilterException {
        // SG_Right_Associativity_Filter()
        
        if(SGLR.isDebugging()) {
            Tools.debug("applyLeftAssociativeFilter() - ", t);
        }

        List<IParseNode> newAmbiguities = new ArrayList<IParseNode>();
        List<IParseNode> kids = t.getKids();
        IParseNode last = kids.get(kids.size() - 1);

        if (last instanceof Amb) {
            List<IParseNode> rest = new ArrayList<IParseNode>();
            rest.addAll(kids);
            rest.remove(rest.size() - 1);

            List<IParseNode> ambs = ((Amb) last).getAlternatives();
            for (IParseNode amb : ambs) {
                Label other = parseTable.getLabel(((ParseNode) amb).getLabel());
                if (!prodLabel.equals(other)) {
                    newAmbiguities.add(amb);
                }
            }

            if (!newAmbiguities.isEmpty()) {
                if (newAmbiguities.size() > 1) {
                    last = new Amb(newAmbiguities);
                } else {
                    last = newAmbiguities.get(0);
                }
                rest.add(last);
                return new Amb(rest);
            } else {
                throw new FilterException("");
            }
        } else if (last instanceof ParseNode) {
            Label other = parseTable.getLabel(((ParseNode) last).getLabel());
            if (prodLabel.equals(other)) {
                throw new FilterException("");
            }
        }
        
        return t;
    }

    private Label getProductionLabel(IParseNode t) {
        if (t instanceof ParseNode) {
            return parseTable.getLabel(((ParseNode) t).getLabel());
        } else if (t instanceof ParseProductionNode) {
            return parseTable.getLabel(((ParseProductionNode) t).getProduction());
        }
        return null;
    }

    private boolean hasRejectProd(IParseNode t) {
        return t instanceof ParseReject;
    }

    private IParseNode filterAmbiguities(List<IParseNode> ambs, int pos) throws FilterException {

        if(SGLR.isDebugging()) {
            Tools.debug("filterAmbiguities()");
        }

        int savedPos = parseTreePosition;

        if (parser.isRejectFilterEnabled() && parseTable.hasRejects()) {
            for (IParseNode amb : ambs) {
                if (amb instanceof Amb) {
                    throw new NotImplementedException();
                    //filterTree(amb, pos, true);
                    //return null;
                }
            }
        }

        List<IParseNode> newAmbiguities = new LinkedList<IParseNode>();

        for (IParseNode amb : ambs) {
            parseTreePosition = savedPos;
            newAmbiguities.add(filterTree(amb, pos, true));
        }

        if (parser.isFilteringEnabled()) {
            // FIXME ??
            if (newAmbiguities.size() > 1) {
                List<IParseNode> oldAmbiguities = new LinkedList<IParseNode>();
                oldAmbiguities.addAll(newAmbiguities);
                for (IParseNode amb : oldAmbiguities) {
                    if (newAmbiguities.remove(amb)) {
                        newAmbiguities = filterAmbiguityList(newAmbiguities, amb);
                    }
                }
            }
        }

        if (newAmbiguities.isEmpty())
            throw new FilterException("");

        if (newAmbiguities.size() == 1)
            return newAmbiguities.get(0);

        return new Amb(newAmbiguities);
    }

    private List<IParseNode> filterAmbiguityList(List<IParseNode> ambiguities, IParseNode t) {

        boolean keepT = true;
        List<IParseNode> r = new LinkedList<IParseNode>();

        if (ambiguities.isEmpty()) {
            r.add(t);
            return r;
        }

        for (IParseNode amb : ambiguities) {

            switch (filter(t, amb)) {
            case FILTER_DRAW:
                r.add(amb);
                break;
            case FILTER_RIGHT_WINS:
                r.add(amb);
                keepT = false;
            }
        }

        if (keepT) {
            r.add(t);
        }

        return r;
    }

    private int filter(IParseNode left, IParseNode right) {
        // SG_Filter(t0, t1)
        
        if(SGLR.isDebugging()) {
            Tools.debug("filter()");
        }

        if (left.equals(right)) {
            return FILTER_LEFT_WINS;
        }

        // FIXME priority filter == preferences?
        if (parser.isPriorityFilterEnabled() && parseTable.hasPriorities()) {
            int r = filterOnIndirectPrefers(left, right);
            if (r != FILTER_DRAW)
                return r;
        }
        
        if (parser.isPriorityFilterEnabled() && parseTable.hasPriorities()) {
            int r = filterOnPreferCount(left, right);
            if (r != FILTER_DRAW)
                return r;
        }

        if (parser.isInjectionCountFilterEnabled()) {
            int r = filterOnInjectionCount(left, right);
            if (r != FILTER_DRAW)
                return r;
        }

        return FILTER_DRAW;
    }

    private int filterOnInjectionCount(IParseNode left, IParseNode right) {

        if(SGLR.isDebugging()) {
            Tools.debug("filterOnInjectionCount()");
        }

        ambiguityManager.increaseInjectionCount();
        
        int leftInjectionCount = countAllInjections(left);
        int rightInjectionCount = countAllInjections(right);

        if (leftInjectionCount != rightInjectionCount) {
            ambiguityManager.increaseInjectionFilterSucceededCount();
        }

        if (leftInjectionCount > rightInjectionCount) {
            return FILTER_RIGHT_WINS;
        } else if (rightInjectionCount > leftInjectionCount) {
            return FILTER_LEFT_WINS;
        }

        return FILTER_DRAW;
    }

    private int countAllInjections(IParseNode t) {
        if (t instanceof Amb) {
            // Trick from forest.c
            return countAllInjections(((Amb) t).getAlternatives().get(0));
        } else if (t instanceof ParseNode) {
            int c = getProductionLabel(t).isInjection() ? 1 : 0;
            return c + countAllInjections(((ParseNode) t).getKids());
        }
        return 0;
    }

    private int countAllInjections(List<IParseNode> ls) {
        int r = 0;
        for (IParseNode n : ls)
            r += countAllInjections(n);
        return r;
    }

    private int filterOnPreferCount(IParseNode left, IParseNode right) {

        if(SGLR.isDebugging()) {
            Tools.debug("filterOnPreferCount()");
        }

        ambiguityManager.increaseEagernessFilterCalledCount();
        
        int r = FILTER_DRAW;
        if (parseTable.hasPrefers() || parseTable.hasAvoids()) {
            int leftPreferCount = countPrefers(left);
            int rightPreferCount = countPrefers(right);
            int leftAvoidCount = countAvoids(left);
            int rightAvoidCount = countAvoids(right);

            if ((leftPreferCount > rightPreferCount && leftAvoidCount <= rightAvoidCount)
                    || (leftPreferCount == rightPreferCount && leftAvoidCount < rightAvoidCount)) {
                Tools.logger("Eagerness priority: ", left, " > ", right);
                r = FILTER_LEFT_WINS;
            }

            if ((rightPreferCount > leftPreferCount && rightAvoidCount <= leftAvoidCount)
                    || (rightPreferCount == leftPreferCount && rightAvoidCount < leftPreferCount)) {
                if (r != FILTER_DRAW) {
                    Tools.logger("Symmetric eagerness priority: ", left, " == ", right);
                    r = FILTER_DRAW;
                } else {
                    Tools.logger("Eagerness priority: ", right, " > ", left);
                    r = FILTER_RIGHT_WINS;
                }
            }
        }

        if (r != FILTER_DRAW) {
            ambiguityManager.increaseEagernessFilterSucceededCount();
        }

        return r;
    }

    private int countPrefers(IParseNode t) {
        if (t instanceof Amb) {
            return countPrefers(((Amb) t).getAlternatives());
        } else if (t instanceof ParseNode) {
            int type = getProductionType(t);
            if (type == ProductionAttributes.PREFER)
                return 1;
            else if (type == ProductionAttributes.AVOID)
                return 0;
            return countPrefers(((ParseNode) t).getKids());
        }
        return 0;
    }

    private int countPrefers(List<IParseNode> ls) {
        int r = 0;
        for (IParseNode n : ls)
            r += countPrefers(n);
        return r;
    }

    private int countAvoids(IParseNode t) {
        if (t instanceof Amb) {
            return countAvoids(((Amb) t).getAlternatives());
        } else if (t instanceof ParseNode) {
            int type = getProductionType(t);
            if (type == ProductionAttributes.PREFER)
                return 0;
            else if (type == ProductionAttributes.AVOID)
                return 1;
            return countAvoids(((ParseNode) t).getKids());
        }
        return 0;
    }

    private int countAvoids(List<IParseNode> ls) {
        int r = 0;
        for (IParseNode n : ls)
            r += countAvoids(n);
        return r;
    }

    private int filterOnIndirectPrefers(IParseNode left, IParseNode right) {
        // SG_Indirect_Eagerness_Filter
        
        if(SGLR.isDebugging()) {
            Tools.debug("filterOnIndirectPrefers()");
        }

        if (left instanceof Amb || right instanceof Amb)
            return FILTER_DRAW;

        if (!left.equals(right))
            return filterOnDirectPrefers(left, right);

        ParseNode l = (ParseNode) left;
        ParseNode r = (ParseNode) right;

        List<IParseNode> leftArgs = l.getKids();
        List<IParseNode> rightArgs = r.getKids();

        int diffs = computeDistinctArguments(leftArgs, rightArgs);

        if (diffs == 1) {
            for (int i = 0; i < leftArgs.size(); i++) {
                IParseNode leftArg = leftArgs.get(i);
                IParseNode rightArg = rightArgs.get(i);

                if (!leftArg.equals(rightArg)) {
                    return filterOnIndirectPrefers(leftArg, rightArg);
                }
            }

        }
        return FILTER_DRAW;
    }

    private int filterOnDirectPrefers(IParseNode left, IParseNode right) {
        // SG_Direct_Eagerness_Filter
        
        if(SGLR.isDebugging()) {
            Tools.debug("filterOnDirectPrefers()");
        }

        if (isLeftMoreEager(left, right))
            return FILTER_LEFT_WINS;
        if (isLeftMoreEager(right, left))
            return FILTER_RIGHT_WINS;

        return FILTER_DRAW;
    }

    private boolean isLeftMoreEager(IParseNode left, IParseNode right) {

        if (isMoreEager(left, right))
            return true;

        IParseNode newLeft = jumpOverInjectionsModuloEagerness(left);
        IParseNode newRight = jumpOverInjectionsModuloEagerness(right);

        if (newLeft instanceof ParseNode && newRight instanceof ParseNode)
            return isMoreEager(left, right);

        return false;
    }

    private IParseNode jumpOverInjectionsModuloEagerness(IParseNode t) {

        if(SGLR.isDebugging()) {
            Tools.debug("jumpOverInjectionsModuloEagerness()");
        }

        int prodType = getProductionType(t);

        if (t instanceof ParseNode && prodType != ProductionAttributes.PREFER
                && prodType != ProductionAttributes.AVOID) {

            Label prod = getLabel(t);
            ParseNode n = (ParseNode) t;

            while (prod.isInjection()) {
                IParseNode x = (ParseNode) n.getKids().get(0);

                int prodTypeX = getProductionType(x);

                if (x instanceof ParseNode && prodTypeX != ProductionAttributes.PREFER
                        && prodTypeX != ProductionAttributes.AVOID) {
                    prod = getLabel(x);
                } else {
                    return n;
                }
            }
        }
        return t;
    }

    private Label getLabel(IParseNode t) {
        if (t instanceof ParseNode) {
            ParseNode n = (ParseNode) t;
            return parseTable.getLabel(n.label);
        } else if (t instanceof ParseProductionNode) {
            ParseProductionNode n = (ParseProductionNode) t;
            return parseTable.getLabel(n.prod);
        }
        return null;
    }

    private int getProductionType(IParseNode t) {
        return getLabel(t).getAttributes().type;
    }

    private boolean isMoreEager(IParseNode left, IParseNode right) {
        int leftLabel = ((ParseNode) left).getLabel();
        int rightLabel = ((ParseNode) right).getLabel();

        Label leftProd = parseTable.getLabel(leftLabel);
        Label rightProd = parseTable.getLabel(rightLabel);

        if (leftProd.isMoreEager(rightProd))
            return true;

        return false;
    }

    private int computeDistinctArguments(List<IParseNode> leftArgs, List<IParseNode> rightArgs) {
        // countDistinctArguments
        int r = 0;
        for (int i = 0; i < leftArgs.size(); i++) {
            if (!leftArgs.equals(rightArgs))
                r++;
        }
        return r;
    }

    private List<IParseNode> getEmptyList() {
        return new ArrayList<IParseNode>(0);
    }

    private List<IParseNode> getCluster(IParseNode t, int pos) {
        int idx = ambiguityManager.getClusterIndex(t, pos);
        Amb amb = idx == -1 ? null : ambiguityManager.getClusterOnIndex(idx);
        return amb == null ? getEmptyList() : amb.getAlternatives();
    }

    private boolean isCyclicTerm(IParseNode t) {

        ambiguityManager.dumpIndexTable();

        List<IParseNode> cycles = computeCyclicTerm(t);

        return cycles != null && cycles.size() > 0;
    }

    private List<IParseNode> computeCyclicTerm(IParseNode t) {
        PositionMap visited = new PositionMap(ambiguityManager.getMaxNumberOfAmbiguities());

        ambiguityManager.resetAmbiguityCount();
        initializeMarks();
        parseTreePosition = 0;

        return computeCyclicTerm(t, false, visited);
    }

    private List<IParseNode> computeCyclicTerm(IParseNode t, boolean inAmbiguityCluster,
            PositionMap visited) {

        if (SGLR.isDebugging()) {
            Tools.debug("computeCyclicTerm() - ", t);
        }

        if (t instanceof ParseProductionNode) {
            parseTreePosition++;
            if (SGLR.isDebugging()) {
                Tools.debug(" bumping");
            }
            return null;
        } else if (t instanceof ParseNode) {
            Amb ambiguities = null;
            List<IParseNode> cycle = null;
            int clusterIndex;
            ParseNode n = (ParseNode) t;

            if (inAmbiguityCluster) {
                cycle = computeCyclicTerm(n.getKids(), false, visited);
            } else {
                if (ambiguityManager.isInputAmbiguousAt(parseTreePosition)) {
                    ambiguityManager.increaseAmbiguityCount();
                    clusterIndex = ambiguityManager.getClusterIndex(t, parseTreePosition);
                    if (SGLR.isDebugging()) {
                        Tools.debug(" - clusterIndex : ", clusterIndex);
                    }
                    if (markMap.isMarked(clusterIndex)) {
                        return new ArrayList<IParseNode>();
                    }
                    ambiguities = ambiguityManager.getClusterOnIndex(clusterIndex);
                } else {
                    clusterIndex = -1;
                }

                if (ambiguities == null) {
                    cycle = computeCyclicTerm(((ParseNode) t).getKids(), false, visited);
                } else {
                    int length = visited.getValue(clusterIndex);
                    int savePos = parseTreePosition;

                    if (length == -1) {
                        markMap.mark(clusterIndex);
                        cycle = computeCyclicTermInAmbiguityCluster(ambiguities, visited);
                        visited.put(clusterIndex, parseTreePosition - savePos);
                        markMap.unmark(clusterIndex);
                    } else {
                        parseTreePosition += length;
                    }
                }
            }
            return cycle;
        } else {
            throw new FatalException();
        }
    }

    private List<IParseNode> computeCyclicTermInAmbiguityCluster(Amb ambiguities,
            PositionMap visited) {

        int savedPos = parseTreePosition;

        for (IParseNode n : ambiguities.getAlternatives()) {
            parseTreePosition = savedPos;
            List<IParseNode> cycle = computeCyclicTerm(n, true, visited);
            if (cycle != null)
                return cycle;
        }
        return null;
    }

    private List<IParseNode> computeCyclicTerm(List<IParseNode> kids, boolean b, PositionMap visited) {

        for (IParseNode kid : kids) {
            List<IParseNode> cycle = computeCyclicTerm(kid, false, visited);
            if (cycle != null)
                return cycle;
        }
        return null;
    }

    private void initializeMarks() {
        markMap = new AmbiguityMap(1024);
    }

    private IParseNode selectOnTopSort() {
        throw new NotImplementedException();
    }

}
