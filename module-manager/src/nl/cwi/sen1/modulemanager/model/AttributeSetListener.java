package nl.cwi.sen1.modulemanager.model;

import nl.cwi.sen1.moduleapi.types.ModuleId;
import aterm.ATerm;

public interface AttributeSetListener {
	public void attributeSet(ModuleId id, ATerm namespace, ATerm key, ATerm oldValue, ATerm newValue);
}
