package toolbus.util.collections;

/**
 * Specifies the return type contants for the entry handlers.<br />
 * 
 * These constants can be used in combination. For example you can return BREAK, which will
 * terminate the iteration; but also 'BREAK & REMOVE', which will both remove the current node and 
 * the terminate the iteration. BREAK and CONTINUE are however conflicting; in this case only the
 * BREAK will have an effect. By default you should return CONTINUE.
 * 
 * @author Arnold Lankamp
 */
public interface EntryHandlerConstants{
	public final static int CONTINUE = 0;
	public final static int BREAK = 1;
	public final static int REMOVE = 2;
}
