package metaedit.style;

import javax.swing.text.StyledDocument;

import locationapi.types.Area;
import locationapi.types.AreaAreas;
import locationapi.types.Slice;
import metaconfig.types.Property;
import aterm.ATermList;


public class Highlighter extends EditorStyle {
	private ATermList  slices;
	private AreaAreas areas;
	locationapi.Factory locationFactory;
	
	public Highlighter(Property property, locationapi.Factory locationFactory,  ATermList slices){
		super(property);
		this.slices=slices;
		this.locationFactory=locationFactory;
		
	}
	
	public void setHighlight(StyledDocument document){
		ATermList  copyClices=slices;
		while (!copyClices.isEmpty()){
			Slice slice= locationFactory.SliceFromTerm(copyClices.getFirst());
			if (slice.getId().equals(categoryName)){
				areas=(AreaAreas) slice.getAreas();
				if (areas!=null){
				while (!areas.isEmpty()) {
					Area area =(Area) areas.getFirst();
					if (area.hasOffset() && area.hasLength()) {
						setStyle(document, area.getOffset(), area.getLength());
					}
					areas =(AreaAreas)areas.getNext();
				}	
				}
			}
			copyClices=copyClices.getNext();	
		}
	}
	
}