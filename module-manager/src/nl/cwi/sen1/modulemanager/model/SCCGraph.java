package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class SCCGraph extends HashMap<SCC, Set<SCC>> {
    public SCCGraph() {
        super();
    }

    public Iterator<SCC> keyIterator() {
        return keySet().iterator();
    }
    
    public void print() {
        for (Iterator<SCC> iter = keyIterator(); iter.hasNext();) {
            SCC scc = iter.next();
            System.err.println("SCC: " + scc.getModules());
            Set<SCC> sccs = get(scc);
            for (Iterator<SCC> descendantScc = sccs.iterator(); descendantScc
                    .hasNext();) {
                SCC descendant = descendantScc.next();
                System.err.println("+- " + descendant.getModules());
            }
        }
    }

}
