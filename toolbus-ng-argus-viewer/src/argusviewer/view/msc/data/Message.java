package argusviewer.view.msc.data;

import prefuse.data.Schema;

import java.util.ArrayList;

/**
 * Message tuple for the Messages table in the Prefuse MSC data model.
 *
 * @author Riccardo Lippolis
 * @author Johnny Eradus
 */
@SuppressWarnings("unchecked")
/*
 * The Prefuse Tuple base class uses the raw 'Class' type,
 * which means this class needs to use it too. We do not want
 * warnings about this, so we suppress them. 
 */
public class Message extends AbstractTuple {

	private static final int HASH_CODE = 31;

	public static final String MESSAGE_FIELDNAME = "message";
	public static final Class<?> MESSAGE_FIELDTYPE = String.class;
	public static final String MESSAGE_DEFAULT_VALUE = "";
	private String m_message;

	public static final String SOURCEID_FIELDNAME = "sourceId";
	public static final Class<?> SOURCEID_FIELDTYPE = Integer.class;
	public static final int SOURCEID_DEFAULT_VALUE = -1;
	private int m_sourceId;

	public static final String TARGETIDS_FIELDNAME = "targetIds";
	public static final Class<?> TARGETIDS_FIELDTYPE = ArrayList.class;
	public static final ArrayList<String> TARGETIDS_DEFAULT_VALUE = new ArrayList<String>();
	private ArrayList<String> m_targetIds;

	public static final String TYPE_FIELDNAME = "type";
	public static final Class<?> TYPE_FIELDTYPE = Type.class;
	public static final Type TYPE_DEFAULT_VALUE = Type.TOOLCOMM;
	private Type m_type;

	public static final String TABLE_NAME = "messages";
	private static final int TABLE_COLUMNCOUNT = 4;
	public static final Schema TABLE_SCHEMA;

	static {
		TABLE_SCHEMA = new Schema(TABLE_COLUMNCOUNT);
		TABLE_SCHEMA.addColumn(MESSAGE_FIELDNAME, MESSAGE_FIELDTYPE, MESSAGE_DEFAULT_VALUE);
		TABLE_SCHEMA.addColumn(SOURCEID_FIELDNAME, SOURCEID_FIELDTYPE, Integer.valueOf(SOURCEID_DEFAULT_VALUE));
		TABLE_SCHEMA.addColumn(TARGETIDS_FIELDNAME, TARGETIDS_FIELDTYPE, TARGETIDS_DEFAULT_VALUE);
		TABLE_SCHEMA.addColumn(TYPE_FIELDNAME, TYPE_FIELDTYPE, TYPE_DEFAULT_VALUE);
	}

	/**
	 * The Type of Message. Possible types are:
	 * - TOOLCOMM : Communication between a tool and a process
	 * - ASYNC : Asynchronous communication (e.g. a broadcast message)
	 * - SYNC : Synchronous communication (e.g. a normal message)
	 */
	public enum Type {
		TOOLCOMM,
		ASYNC,
		SYNC
	}

	public static final String[] COLUMNS = {MESSAGE_FIELDNAME,
			SOURCEID_FIELDNAME, TARGETIDS_FIELDNAME, TYPE_FIELDNAME};

	/**
	 * Create a Message tuple with default values.
	 */
	public Message() {
		this(MESSAGE_DEFAULT_VALUE, SOURCEID_DEFAULT_VALUE, TARGETIDS_DEFAULT_VALUE, TYPE_DEFAULT_VALUE);
	}

	/**
	 * Create a new Message tuple with the specified values.
	 *
	 * @param message The message that is sent
	 * @param sourceId The source of the message, THIS IS THE TIMESTAMP
	 * @param targetIds The targets of the message
	 * @param type The type of message
	 */
	public Message(String message, int sourceId, ArrayList<String> targetIds, Type type) {
		m_message = message;
		m_sourceId = sourceId;
		m_targetIds = targetIds;
		m_type = type;
	}

	/**
	 * Create a new Message tuple with only one target.
	 *
	 * @param message The message that is sent
	 * @param sourceId The source of the message
	 * @param targetId The target of the message
	 * @param type The type of message
	 */
	public Message(String message, int sourceId, String targetId, Type type) {
		ArrayList<String> targets = new ArrayList<String>();
		targets.add(targetId);

		m_message = message;
		m_sourceId = sourceId;
		m_targetIds = targets;
		m_type = type;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	protected String[] getColumns() {
		return COLUMNS;
	}

	/**
	 * {@inheritDoc}
	 */
	public Object get(String field) {
		if (field.equals(MESSAGE_FIELDNAME)) {
			return m_message;
		} else if (field.equals(SOURCEID_FIELDNAME)) {
			return Integer.valueOf(m_sourceId);
		} else if (field.equals(TARGETIDS_FIELDNAME)) {
			return m_targetIds;
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
	public Class<?> getColumnType(String field) {
		if (field.equals(MESSAGE_FIELDNAME)) {
			return MESSAGE_FIELDTYPE;
		} else if (field.equals(SOURCEID_FIELDNAME)) {
			return SOURCEID_FIELDTYPE;
		} else if (field.equals(TARGETIDS_FIELDNAME)) {
			return TARGETIDS_FIELDTYPE;
		} else if (field.equals(TYPE_FIELDNAME)) {
			return TYPE_FIELDTYPE;
		}

		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Class<?> getColumnType(int col) {
		return getColumnType(getColumns()[col]);
	}

	/**
	 * {@inheritDoc}
	 */
	public Object getDefault(String field) {
		if (field.equals(MESSAGE_FIELDNAME)) {
			return MESSAGE_DEFAULT_VALUE;
		} else if (field.equals(SOURCEID_FIELDNAME)) {
			return Integer.valueOf(SOURCEID_DEFAULT_VALUE);
		} else if (field.equals(TARGETIDS_FIELDNAME)) {
			return TARGETIDS_DEFAULT_VALUE;
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
			} else if (field.equals(SOURCEID_FIELDNAME)) {
				m_sourceId = ((Integer) value).intValue();
			} else if (field.equals(TARGETIDS_FIELDNAME)) {
				m_targetIds = (ArrayList<String>) value;
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
	 * @param field The fieldname
	 * @param type The data type
	 * @return Whether or not the pair is valid
	 */
	protected boolean isValidNameTypePair(String field, Class type) {
		if ((field.equals(MESSAGE_FIELDNAME)) && (type == MESSAGE_FIELDTYPE)) {
			return true;
		} else if ((field.equals(SOURCEID_FIELDNAME)) && (type == SOURCEID_FIELDTYPE)) {
			return true;
		} else if ((field.equals(TARGETIDS_FIELDNAME)) && (type == TARGETIDS_FIELDTYPE)) {
			return true;
		} else if ((field.equals(TYPE_FIELDNAME)) && (type == TYPE_FIELDTYPE)) {
			return true;
		}

		return false;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public boolean equals(Object o) {
		if (this == o) {
			return true;
		}
		if (o == null || getClass() != o.getClass()) {
			return false;
		}

		Message message = (Message) o;

		if (m_sourceId != message.m_sourceId) {
			return false;
		}
		if (m_message != null ? !m_message.equals(message.m_message) : message.m_message != null) {
			return false;
		}
		if (m_targetIds != null ? !m_targetIds.equals(message.m_targetIds) : message.m_targetIds != null) {
			return false;
		}
		if (m_type != message.m_type) {
			return false;
		}

		return true;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public int hashCode() {
		int result;
		result = (m_message != null ? m_message.hashCode() : 0);
		result = HASH_CODE * result + m_sourceId;
		result = HASH_CODE * result + (m_targetIds != null ? m_targetIds.hashCode() : 0);
		result = HASH_CODE * result + (m_type != null ? m_type.hashCode() : 0);
		return result;
	}
}