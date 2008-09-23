package argusviewer.view.architectureview;

import argusviewer.view.msc.data.AbstractTuple;
import prefuse.data.Schema;
import toolbus.atom.Atom;
import toolbus.atom.msg.RecMsg;
import toolbus.atom.msg.SndMsg;
import toolbus.atom.note.RecNote;
import toolbus.atom.note.SndNote;
import toolbus.atom.tool.AckEvent;
import toolbus.atom.tool.Connect;
import toolbus.atom.tool.DisConnect;
import toolbus.atom.tool.Do;
import toolbus.atom.tool.Eval;
import toolbus.atom.tool.Event;
import toolbus.atom.tool.Execute;
import toolbus.atom.tool.GetPerfStats;
import toolbus.atom.tool.RecPerfStats;
import toolbus.atom.tool.RecVal;
import toolbus.atom.tool.SndKill;
import toolbus.atom.tool.Terminate;

/**
 * @author Tigran Kalaidjan
 * @author John Franse
 *
 */
/*
 * The Prefuse Tuple base class uses the raw 'Class' type,
 * which means this class needs to use it too. We do not want
 * warnings about this, so we suppress them. 
 */
public class Message extends AbstractTuple {
	public static final String MESSAGE_FIELDNAME = "message";
	public static final Class<?> MESSAGE_FIELDTYPE = String.class;
	public static final String MESSAGE_DEFAULT_VALUE = "";
	private String m_message;
	
	public static final String SOURCENAME_FIELDNAME = "sourceName";
	public static final Class<?> SOURCENAME_FIELDTYPE = String.class;
	public static final String SOURCENAME_DEFAULT_VALUE = "";
	private String m_sourceName;
	
	public static final String SOURCETYPE_FIELDNAME = "sourceType";
	public static final Class<?> SOURCETYPE_FIELDTYPE = String.class;
	public static final String SOURCETYPE_DEFAULT_VALUE = "";
	private String m_sourceType;
	
	public static final String TARGETNAME_FIELDNAME = "targetName";
	public static final Class<?> TARGETNAME_FIELDTYPE = String.class;
	public static final String TARGETNAME_DEFAULT_VALUE = "";
	private String m_targetName;
	
	public static final String TARGETTYPE_FIELDNAME = "targetType";
	public static final Class<?> TARGETTYPE_FIELDTYPE = String.class;
	public static final String TARGETTYPE_DEFAULT_VALUE = "";
	private String m_targetType;
	
	public static final String TYPE_FIELDNAME = "type";
	public static final Class<?> TYPE_FIELDTYPE = Type.class;
	public static final Type TYPE_DEFAULT_VALUE = Type.TOOLCOMM;
	private Type m_type;
	
	public static final String TABLE_NAME = "messages";
	private static final int TABLE_COLUMNCOUNT = 6;
	public static final Schema TABLE_SCHEMA;
	static{
		TABLE_SCHEMA = new Schema(TABLE_COLUMNCOUNT);
		TABLE_SCHEMA.addColumn(MESSAGE_FIELDNAME, MESSAGE_FIELDTYPE, MESSAGE_DEFAULT_VALUE);
		TABLE_SCHEMA.addColumn(SOURCENAME_FIELDNAME, SOURCENAME_FIELDTYPE, SOURCENAME_DEFAULT_VALUE);
		TABLE_SCHEMA.addColumn(SOURCETYPE_FIELDNAME, SOURCETYPE_FIELDTYPE, SOURCETYPE_DEFAULT_VALUE);
		TABLE_SCHEMA.addColumn(TARGETNAME_FIELDNAME, TARGETNAME_FIELDTYPE, TARGETNAME_DEFAULT_VALUE);
		TABLE_SCHEMA.addColumn(TARGETTYPE_FIELDNAME, TARGETTYPE_FIELDTYPE, TARGETTYPE_DEFAULT_VALUE);
		TABLE_SCHEMA.addColumn(TYPE_FIELDNAME, TYPE_FIELDTYPE, TYPE_DEFAULT_VALUE);
	}
	
	/**
	 * The Type of Message. Possible types are:
	 * - TOOLCOMM : Communication between a tool and a process 
	 * - ASYNC : Asynchronous communication (e.g. a broadcast message)
	 * - SYNC : Synchronous communication (e.g. a normal message)
	 */
	public enum Type{
		TOOLCOMM,
		ASYNC,
		SYNC
	}
	
	
	// Static types for statements to see
	// whether it's tool communication or sync communication etc.
	public static final Class<Atom>[] ASYNC_COMMUNICATION = new Class[] {
		RecNote.class,
		SndNote.class
	};
	public static final Class<Atom>[] SYNC_COMMUNICATION = new Class[] {
		RecMsg.class,
		SndMsg.class
	};
	public static final Class<Atom>[] TOOL_COMMUNICATION = new Class[] {
		AckEvent.class,
		Connect.class,
		DisConnect.class,
		Do.class,
		Eval.class,
		Event.class,
		Execute.class,
		GetPerfStats.class,
		RecPerfStats.class,
		RecVal.class,
		SndKill.class,
		Terminate.class
	};
	
	public static final String[] COLUMNS = { MESSAGE_FIELDNAME,
			SOURCENAME_FIELDNAME, SOURCETYPE_FIELDNAME, TARGETNAME_FIELDNAME, TARGETTYPE_FIELDNAME, TYPE_FIELDNAME };
	
	/**
	 * Create a Message tuple with default values.
	 */
	public Message() {
		this(MESSAGE_DEFAULT_VALUE, SOURCENAME_DEFAULT_VALUE, SOURCETYPE_DEFAULT_VALUE, 
				TARGETNAME_DEFAULT_VALUE, TARGETTYPE_DEFAULT_VALUE, TYPE_DEFAULT_VALUE);
	}
	
	/**
	 * Create a new Message tuple with the specified values.
	 * 
	 * @param message The message that is sent
	 * @param sourceName The source of the message
	 * @param sourceType The source type of the message
	 * @param targetName The targets of the message
	 * @param targetType The targets type of the message
	 * @param type The type of message
	 */
	public Message(String message, String sourceName, String sourceType, String targetName, String targetType, Type type) {
		m_message = message;
		m_sourceName = sourceName;
		m_sourceType = sourceType;
		m_targetName = targetName;
		m_targetType = targetType;
		m_type = type;
	}

	
	/**
	 * {@inheritDoc}
	 */
	protected String[] getColumns() {
		return COLUMNS;
	}

	/**
	 * {@inheritDoc}
	 */
	public Object get(String field) {
		if (field.equals(MESSAGE_FIELDNAME)) {
			return m_message;
		} else if (field.equals(SOURCENAME_FIELDNAME)) {
			return m_sourceName;
		} else if (field.equals(SOURCETYPE_FIELDNAME)) {
			return m_sourceType;
		} else if (field.equals(TARGETNAME_FIELDNAME)) {
			return m_targetName;
		} else if (field.equals(TARGETTYPE_FIELDNAME)) {
			return m_targetType;
		} else if (field.equals(TYPE_FIELDNAME)) {
			return m_type;
		}

		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Object get(int col) {
		return get(getColumns()[col]);
	}

	/**
	 * {@inheritDoc}
	 */
	public Class getColumnType(String field) {
		if (field.equals(MESSAGE_FIELDNAME)) {
			return MESSAGE_FIELDTYPE;
		} else if (field.equals(SOURCENAME_FIELDNAME)) {
			return SOURCENAME_FIELDTYPE;
		} else if (field.equals(SOURCETYPE_FIELDNAME)) {
			return SOURCETYPE_FIELDTYPE;
		} else if (field.equals(TARGETNAME_FIELDNAME)) {
			return TARGETNAME_FIELDTYPE;
		} else if (field.equals(TARGETTYPE_FIELDNAME)) {
			return TARGETTYPE_FIELDTYPE;
		} else if (field.equals(TYPE_FIELDNAME)) {
			return TYPE_FIELDTYPE;
		}

		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Class getColumnType(int col) {
		return getColumnType(getColumns()[col]);
	}

	/**
	 * {@inheritDoc}
	 */
	public Object getDefault(String field) {
		if (field.equals(MESSAGE_FIELDNAME)) {
			return MESSAGE_DEFAULT_VALUE;
		} else if (field.equals(SOURCENAME_FIELDNAME)) {
			return SOURCENAME_DEFAULT_VALUE;
		} else if (field.equals(SOURCETYPE_FIELDNAME)) {
			return SOURCETYPE_DEFAULT_VALUE;
		} else if (field.equals(TARGETNAME_FIELDNAME)) {
			return TARGETNAME_DEFAULT_VALUE;
		} else if (field.equals(TARGETTYPE_FIELDNAME)) {
			return TARGETTYPE_DEFAULT_VALUE;
		} else if (field.equals(TYPE_FIELDNAME)) {
			return TYPE_DEFAULT_VALUE;
		}

		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Schema getSchema() {
		return TABLE_SCHEMA;
	}

	/**
	 * {@inheritDoc}
	 */
	public void revertToDefault(String field) {
		set(field, getDefault(field));
	}

	/**
	 * {@inheritDoc}
	 */
	public void set(String field, Object value) {
		
		if (canSet(field, value.getClass())) {
			if (field.equals(MESSAGE_FIELDNAME)) {
				m_message = (String) value;
			} else if (field.equals(SOURCENAME_FIELDNAME)) {
				m_sourceName = (String) value;
			} else if (field.equals(SOURCETYPE_FIELDNAME)) {
				m_sourceType = (String) value;
			} else if (field.equals(TARGETNAME_FIELDNAME)) {
				m_targetName = (String) value;
			} else if (field.equals(TARGETTYPE_FIELDNAME)) {
				m_targetType = (String) value;
			} else if (field.equals(TYPE_FIELDNAME)) {
				m_type = (Message.Type) value;
			}
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void set(int col, Object value) {
		set(getColumns()[col], value);
	}
	
	/**
	 * Checks for a given fieldname/type pair if it is a valid combination for
	 * this tuple.
	 * 
	 * @param field
	 *            The fieldname
	 * @param type
	 *            The data type
	 * @return Whether or not the pair is valid
	 */
	protected boolean isValidNameTypePair(String field, Class type) {
		if (field.equals(MESSAGE_FIELDNAME)) {
			return (type == MESSAGE_FIELDTYPE);
		} else if (field.equals(SOURCENAME_FIELDNAME)) {
			return (type == SOURCENAME_FIELDTYPE);
		} else if (field.equals(SOURCETYPE_FIELDNAME)) {
			return (type == SOURCETYPE_FIELDTYPE);
		} else if (field.equals(TARGETNAME_FIELDNAME)) {
			return (type == TARGETNAME_FIELDTYPE);
		} else if (field.equals(TARGETTYPE_FIELDNAME)) {
			return (type == TARGETTYPE_FIELDTYPE);
		} else if (field.equals(TYPE_FIELDNAME)) {
			return (type == TYPE_FIELDTYPE);
		}
		return false;
	}
}