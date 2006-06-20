package nl.cwi.sen1.modulemanager.model;

import java.util.HashSet;
import java.util.Set;

import nl.cwi.sen1.moduleapi.types.ModuleId;

public class SCC {
    Set<ModuleId> modules;
    
    public SCC() {
        modules = new HashSet<ModuleId>();
    }
    
    public SCC(Set<ModuleId> modules) {
        this.modules = modules;
    }
    
    public Set<ModuleId> getModules() {
        return modules;
    }

    public void add(ModuleId top) {
        modules.add(top);
    }
}
