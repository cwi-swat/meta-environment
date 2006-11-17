/*
 * Created on 04.des.2005
 *
 * Copyright (c) 2005, Karl Trygve Kalleberg <karltk@ii.uib.no>
 * 
 * Licensed under the GNU Lesser General Public License, v2.1
 */
package org.spoofax.jsglr;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.io.Serializable;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermList;
import aterm.AFun;

public class ParseTable implements Serializable {

    static final long serialVersionUID = -3372429249660900093L;

    private State[] states;

    private int startState;

    private Label[] labels;

    private Priority[] priorities;
    
    private Associativity[] associativities;

    transient private ATermFactory factory;

    transient public AFun applAFun;

    transient public AFun ambAFun;

    private Label[] injections;

    public ParseTable(ATerm pt) throws InvalidParseTableException {
        parse(pt);
        initAFuns(pt.getFactory());
    }

    public void initAFuns(ATermFactory factory) {
        this.factory = factory;
        applAFun = factory.makeAFun("appl", 2, false);
        ambAFun = factory.makeAFun("amb", 1, false);
    }

    public ATermFactory getFactory() {
        return factory;
    }

    private boolean parse(ATerm pt) throws InvalidParseTableException {
        int version = Term.intAt(pt, 0);
        startState = Term.intAt(pt, 1);
        ATermList labelsTerm = Term.listAt(pt, 2);
        ATermAppl statesTerm = Term.applAt(pt, 3);
        ATermAppl prioritiesTerm = Term.applAt(pt, 4);

        if (version != 4) {
            return false;
        }

        labels = parseLabels(labelsTerm);
        states = parseStates(statesTerm);
        priorities = parsePriorities(prioritiesTerm);
        associativities = parseAssociativities(prioritiesTerm);

        injections = new Label[labels.length];
        for(int i=0;i<labels.length;i++)
            if(labels[i] != null && labels[i].isInjection())
                injections[i] = labels[i];
        
        return true;
    }

    private Priority[] parsePriorities(ATermAppl prioritiesTerm) throws InvalidParseTableException {

        ATermList prods = Term.listAt(prioritiesTerm, 0);
        List<Priority> ret = new ArrayList<Priority>();
        
        for (int i = 0; i < prods.getChildCount(); i++) {
            ATermAppl a = Term.applAt(prods, i);
            int left = Term.intAt(a, 0);
            int right = Term.intAt(a, 1);
            if (a.getName().equals("left-prio")) {
                // handled by parseAssociativities
            } else if (a.getName().equals("right-prio")) {
                // handled by parseAssociativities
            } else if (a.getName().equals("non-assoc")) {
                // handled by parseAssociativities
            } else if (a.getName().equals("gtr-prio")) {
                if(left != right)
                    ret.add(new Priority(Priority.GTR, left, right));
            } else {
                throw new InvalidParseTableException("Unknown priority : " + a.getName());
            }
        }
        return ret.toArray(new Priority[0]);
    }

    private Associativity[] parseAssociativities(ATermAppl prioritiesTerm) throws InvalidParseTableException {

        ATermList prods = Term.listAt(prioritiesTerm, 0);
        List<Associativity> ret = new ArrayList<Associativity>();
        
        for (int i = 0; i < prods.getChildCount(); i++) {
            ATermAppl a = Term.applAt(prods, i);
            int left = Term.intAt(a, 0);
            int right = Term.intAt(a, 1);
            if (a.getName().equals("left-prio")) {
                if(left == right)
                    ret.add(new Associativity(Priority.LEFT, left));
            } else if (a.getName().equals("right-prio")) {
                if(left == right)
                    ret.add(new Associativity(Priority.RIGHT, left));
            } else if (a.getName().equals("non-assoc")) {
                if(left == right)
                    ret.add(new Associativity(Priority.NONASSOC, left));
            } else if (a.getName().equals("gtr-prio")) {
                // handled by parsePriorities
            } else {
                throw new InvalidParseTableException("Unknown priority : " + a.getName());
            }
        }
        return ret.toArray(new Associativity[0]);
    }

    private Label[] parseLabels(ATermList labelsTerm) throws InvalidParseTableException {

        Label[] ret = new Label[labelsTerm.getChildCount() + 256 + 1];

        for (int i = 0; i < labelsTerm.getChildCount(); i++) {
            ATermAppl a = Term.applAt(labelsTerm, i);
            ATermAppl prod = Term.applAt(a, 0);
            int labelNumber = Term.intAt(a, 1);
            boolean injection = isInjection(prod);
            ProductionAttributes pa = parseProductionAttributes(Term.applAt(prod, 2));
            ret[labelNumber] = new Label(labelNumber, prod, pa, injection);
        }

        return ret;
    }

    private boolean isInjection(ATermAppl prod) {

        List r = prod.match("prod([<term>],cf(sort(<term>)),<term>)");
        if (r != null && r.size() == 1) {
            ATerm x = (ATerm) r.get(0);
            return !(x.match("lit(<str>)") == null);
        }

        r = prod.match("prod([<term>],lex(sort(<str>)),<term>)");
        if (r != null && r.size() == 1) {
            ATerm x = (ATerm) r.get(0);
            return !(x.match("lit(<str)") == null);
        }

        return false;
    }

    private ProductionAttributes parseProductionAttributes(ATermAppl attr)
            throws InvalidParseTableException {
        if (attr.getName().equals("attrs")) {
            ATermList ls = (ATermList) attr.getChildAt(0);
            int type = 0;
            ATerm term = null;
            for (int i = 0; i < ls.getChildCount(); i++) {
                ATermAppl t = (ATermAppl) ls.getChildAt(i);
                String ctor = t.getName();
                if (ctor.equals("reject")) {
                    type = ProductionAttributes.REJECT;
                } else if (ctor.equals("prefer")) {
                    type = ProductionAttributes.PREFER;
                } else if (ctor.equals("avoid")) {
                    type = ProductionAttributes.AVOID;
                } else if (ctor.equals("bracket")) {
                    type = ProductionAttributes.BRACKET;
                } else if (ctor.equals("assoc")) {
                    ATermAppl a = (ATermAppl) t.getChildAt(0);
                    if (a.getName().equals("left")) {
                        type = ProductionAttributes.LEFT_ASSOCIATIVE;
                    } else if (a.getName().equals("right")) {
                        type = ProductionAttributes.RIGHT_ASSOCIATIVE;
                    } else {
                        throw new InvalidParseTableException("Unknown assocativity: " + a.getName());
                    }
                } else if (ctor.equals("term")) {
                    term = (ATerm) t.getChildAt(0).getChildAt(0);
                } else if (ctor.equals("id")) {
                    // FIXME Unimplemented
                } else {
                    throw new InvalidParseTableException("Unknown attribute: " + t);
                }
            }
            return new ProductionAttributes(type, term);
        } else if (attr.getName().equals("no-attrs")) {
            return new ProductionAttributes(ProductionAttributes.NO_TYPE, null);
        }
        throw new InvalidParseTableException("Unknown attribute type: " + attr);
    }

    private State[] parseStates(ATermAppl statesTerm) throws InvalidParseTableException {

        ATermList states = Term.listAt(statesTerm, 0);
        State[] ret = new State[states.getLength()];

        for (int i = 0; i < states.getLength(); i++) {

            ATermAppl stateRec = Term.applAt(states, i);
            int stateNumber = Term.intAt(stateRec, 0);
            Goto[] gotos = parseGotos(Term.listAt(stateRec, 1));
            Action[] actions = parseActions(Term.listAt(stateRec, 2));

            ret[i] = new State(stateNumber, gotos, actions);

        }

        return ret;
    }

    Map<Goto, Goto> gotoMap = new HashMap<Goto, Goto>();

    private Goto makeGoto(int newStateNumber, Range[] ranges) {
        Goto g = new Goto(ranges, newStateNumber);
        if (gotoMap.containsKey(g)) {
            return gotoMap.get(g);
        }
        gotoMap.put(g, g);
        return g;
    }

    private Action[] parseActions(ATermList actionList) throws InvalidParseTableException {

        Action[] ret = new Action[actionList.getChildCount()];

        for (int i = 0; i < actionList.getChildCount(); i++) {
            ATermAppl action = Term.applAt(actionList, i);
            Range[] ranges = parseRanges(Term.listAt(action, 0));
            ActionItem[] items = parseActionItems(Term.listAt(action, 1));
            ret[i] = new Action(ranges, items);
        }
        return ret;
    }

    private ActionItem[] parseActionItems(ATermList items) {

        ActionItem[] ret = new ActionItem[items.getChildCount()];

        for (int i = 0; i < items.getChildCount(); i++) {
            ActionItem item = null;
            ATermAppl a = Term.applAt(items, i);
            if (a.getName().equals("reduce")) {
                int productionArity = Term.intAt(a, 0);
                int label = Term.intAt(a, 1);
                int status = Term.intAt(a, 2);
                item = makeReduce(productionArity, label, status);
            } else if (a.getName().equals("accept")) {
                item = new Accept();
            } else if (a.getName().equals("shift")) {
                int nextState = Term.intAt(a, 0);
                item = makeShift(nextState);
            }
            ret[i] = item;
        }
        return ret;
    }

    Map<Reduce, Reduce> reduceMap = new HashMap<Reduce, Reduce>();

    private Reduce makeReduce(int arity, int label, int status) {
        Reduce s = new Reduce(arity, label, status);
        if (reduceMap.containsKey(s)) {
            return reduceMap.get(s);
        }
        reduceMap.put(s, s);
        return s;
    }

    Map<Shift, Shift> shiftMap = new HashMap<Shift, Shift>();

    private Shift makeShift(int nextState) {
        Shift s = new Shift(nextState);
        if (shiftMap.containsKey(s)) {
            return shiftMap.get(s);
        }
        shiftMap.put(s, s);
        return s;
    }

    private Goto[] parseGotos(ATermList gotos) throws InvalidParseTableException {

        Goto[] ret = new Goto[gotos.getChildCount()];

        for (int i = 0; i < gotos.getChildCount(); i++) {
            ATermAppl go = Term.applAt(gotos, i);
            ATermList rangeList = Term.listAt(go, 0);
            int newStateNumber = Term.intAt(go, 1);
            Range[] ranges = parseRanges(rangeList);
            //int[] productionLabels = parseProductionLabels(rangeList);
            ret[i] = makeGoto(newStateNumber, ranges);
        }

        return ret;
    }

//    private int[] parseProductionLabels(ATermList ranges) throws InvalidParseTableException {
//
//        int[] ret = new int[ranges.getChildCount()];
//
//        for (int i = 0; i < ranges.getChildCount(); i++) {
//            ATerm t = Term.termAt(ranges, i);
//            if (Term.isInt(t)) {
//                ret[i] = Term.toInt(t);
//            } else {
////                else if(Term.isAppl(t) && ((ATermAppl)t).getName().equals("range")) {
////                int s = Term.intAt(t, 0);
////                int e = Term.intAt(t, 1);
//                Tools.debug(t);
//                throw new InvalidParseTableException("");
//            }
//        }
//        return ret;
//    }

    private Range[] parseRanges(ATermList ranges) throws InvalidParseTableException {

        Range[] ret = new Range[ranges.getChildCount()];

        for (int i = 0; i < ranges.getChildCount(); i++) {
            ATerm t = Term.termAt(ranges, i);
            if (Term.isInt(t)) {
                ret[i] = makeRange(Term.toInt(t));
            } else {
                int low = Term.intAt(t, 0);
                int hi = Term.intAt(t, 1);
                ret[i] = makeRange(low, hi);
            }
        }
        return ret;
    }

    Map<Range, Range> rangeMap = new HashMap<Range, Range>();

    private Range makeRange(int low, int hi) throws InvalidParseTableException {
        Range r = new Range(low, hi);
        if (rangeMap.containsKey(r)) {
            return rangeMap.get(r);
        }
        rangeMap.put(r, r);
        return r;
    }

    private Range makeRange(int n) throws InvalidParseTableException {
        return makeRange(n, n);
    }

    public State getInitialState() {
        return states[startState];
    }

    public State go(State s, int label) {
        return states[s.go(label)];
    }

    public Label getLabel(int label) {
        return labels[label];
    }

    public State getState(int s) {
        return states[s];
    }

    public int getStateCount() {
        return states.length;
    }

    public int getProductionCount() {
        return labels.length - 256;
    }

    public int getActionEntryCount() {
        int total = 0;
        for (State s : states) {
            total += s.getActionItemCount();
        }
        return total;
    }

    public int getGotoCount() {
        int total = 0;
        for (State s : states) {
            total += s.getGotoCount();
        }
        return total;
    }

    public int getActionCount() {
        int total = 0;
        for (State s : states) {
            total += s.getActionCount();
        }
        return total;
    }

    public boolean hasRejects() {

        for (State s : states) {
            if (s.rejectable()) {
                return true;
            }
        }

        return false;
    }

    public boolean hasPriorities() {
        return priorities.length > 0 || associativities.length > 0;
    }

    public boolean hasPrefers() {
        for (State s : states) {
            if (s.hasPrefer()) {
                return true;
            }
        }
        return false;
    }

    public boolean hasAvoids() {
        for (State s : states) {
            if (s.hasAvoid()) {
                return true;
            }
        }
        return false;
    }

    public IParseNode lookupProduction(int currentToken) {
        return new ParseProductionNode(currentToken);
    }

    public ATerm getProduction(int prod) {
        if (prod < 256) {
            return factory.makeInt(prod);
        }
        return labels[prod].prod;
    }

    public List<Label> getPriorities(Label prodLabel) {
        List<Label> ret = new ArrayList<Label>();
        for (Priority p : priorities) {
            if (p.left == prodLabel.labelNumber && p.type == Priority.GTR) {
                ret.add(labels[p.right]);
            }
        }
        return ret;
    }

    public Label lookupInjection(int prod) {
        return injections[prod];
    }
}
