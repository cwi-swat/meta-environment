/*
 * Created on 01.apr.2006
 *
 * Copyright (c) 2005, Karl Trygve Kalleberg <karltk@ii.uib.no>
 * 
 * Licensed under the GNU General Public License, v2
 */
package org.spoofax.jsglr;

import java.util.HashMap;
import java.util.Map;

public class AmbiguityManager {

    private int injectionFilterSucceededCount;
    private int eagernessFilterSucceededCount;
    private int injectionCallsCount;
    private int eagernessGreaterCallsCount;
    private int preferAndAvoidCallsCount;
    private int ambiguityCallsCount;
    private int maxNumberOfAmbiguitiesCount;
    private int ambiguitiesCount;
    private int clustersVisitedCount;
    
    private Map<AmbKey,Integer> indexTable;
    private Map<Integer, Amb> clusterTable;
    
    private AmbiguityMap inputAmbiguityMap;


    AmbiguityManager(int inputLength) {
        indexTable = new HashMap<AmbKey, Integer>();
        clusterTable = new HashMap<Integer, Amb>();
        initializeAmbiguityMap(inputLength);
    }

    void initializeAmbiguityMap(int inputLength) {
        inputAmbiguityMap = new AmbiguityMap(inputLength);
    }
    
    void createAmbiguityCluster(IParseNode existing, IParseNode newNode, int pos) {
        
        increaseAmbiguityCalls();
        
        Amb newAmbiguities = null;
        
        int idx = getIndex(existing, pos);
        if(idx == -1) {
            idx = increaseMaxAmbiguityCount();
            addIndex(existing, pos, idx);
            newAmbiguities = new Amb(existing, newNode);
        } else {
            Amb oldAmbiguities = getClusterOnIndex(idx);
            if(oldAmbiguities.hasAmbiguity(newNode))
                return;
            newAmbiguities = new Amb(oldAmbiguities, newNode);
        }
        
        addIndex(newNode, pos, idx);
        updateCluster(idx, newAmbiguities);
        inputAmbiguityMap.mark(pos);
    }

    protected Amb getClusterOnIndex(int idx) {
        return clusterTable.get(idx);
    }

    private void updateCluster(int idx, Amb cluster) {
        clusterTable.put(idx, cluster);
    }

    private void addIndex(IParseNode t, int pos, int idx) {
        if(SGLR.isDebugging()) {
            Tools.debug("addIndex()");
            Tools.debug(" - " + t);
            Tools.debug(" - " + pos);
        }
        indexTable.put(new AmbKey(t, pos), idx);
    }

    private int getIndex(IParseNode existing, int pos) {
        Integer i = indexTable.get(new AmbKey(existing, pos));
        return i == null ? -1 : i.intValue();
    }

    private int increaseMaxAmbiguityCount() {
        return maxNumberOfAmbiguitiesCount++;
    }

    private int increaseAmbiguityCalls() {
        return ambiguityCallsCount++;
    }

    public int getAmbiguityCallsCount() {
        return ambiguityCallsCount;
    }
    
    public int getAmbiguitiesCount() {
        return ambiguitiesCount;
    }

    public int getMaxNumberOfAmbiguities() {
        return maxNumberOfAmbiguitiesCount;
    }

    public void resetClustersVisitedCount() {
        clustersVisitedCount = 0;
    }

    public void resetAmbiguityCount() {
        ambiguitiesCount = 0;
    }

    public void increaseAmbiguityCount() {
        ambiguitiesCount++;
    }

    public int getClusterIndex(IParseNode t, int pos) {
        if(SGLR.isDebugging()) {
            Tools.debug("getClusterIndex()");
            Tools.debug(" t - " + t);
            Tools.debug(" pos - " + pos);
            //Tools.debug(indexTable);
        }
        AmbKey k = new AmbKey(t, pos);
        Integer r = indexTable.get(k);
        return r == null ? -1 : r.intValue();
    }

    public boolean isInputAmbiguousAt(int pos) {
        return inputAmbiguityMap.isMarked(pos);
    }

    public void dumpIndexTable() {
        Tools.debug(indexTable);
    }

    public void increaseEagernessFilterSucceededCount() {
        eagernessFilterSucceededCount++;
    }

    public void increaseInjectionFilterSucceededCount() {
        injectionFilterSucceededCount++;
    }

    public int getEagernessComparisonCount() {
        return eagernessGreaterCallsCount;
    }

    public void increaseEagernessFilterCalledCount() {
        eagernessGreaterCallsCount++;
        
    }

    public int getEagernessSucceededCount() {
        return eagernessFilterSucceededCount;
    }

    public void increaseInjectionCount() {
        injectionCallsCount++;
        
    }

    public int getInjectionCount() {
        return injectionCallsCount;
    }

}
