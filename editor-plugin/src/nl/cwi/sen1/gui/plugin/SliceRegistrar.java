package nl.cwi.sen1.gui.plugin;

import locationapi.Factory;
import locationapi.types.Area;
import locationapi.types.AreaAreas;
import locationapi.types.Slice;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class SliceRegistrar {
	private static Factory factory;

	static public void registerSlices(EditorPane editor, ATermList slices) {
		initFactory(slices);
		
		editor.pauseUndo();
	
		for ( ; !slices.isEmpty(); slices = slices.getNext()) {
			Slice slice = factory.SliceFromTerm(slices.getFirst());
			registerSlice(editor, slice);
		}
		
		editor.resumeUndo();
	}

	static private void registerSlice(EditorPane editor, Slice slice) {
		String name = slice.getId();
		AreaAreas areas = slice.getAreas();
		
		for ( ; !areas.isEmpty(); areas = areas.getTail()) {
			Area area = areas.getHead();
			editor.setStyle(area.getOffset(), area.getLength(), name);
		}
	}
	
	private static void initFactory(ATermList slices) {
		if (factory == null) {
			factory = Factory.getInstance((PureFactory) slices.getFactory());
		}
	}

}

