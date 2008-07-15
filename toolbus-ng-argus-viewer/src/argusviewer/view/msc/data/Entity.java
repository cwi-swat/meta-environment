package argusviewer.view.msc.data;

import prefuse.data.Schema;

/**
 * This class represents a tuple in the Entities table (a process or a tool)
 * of the Prefuse MSC data model.
 * 
 * @author Riccardo Lippolis
 * @author Johnny Eradus
 * @author John Franse
 * @author Tigran Kalaidjan
 * 
 */
/*
 * The Prefuse Tuple base class uses the raw 'Class' type,
 * which means this class needs to use it too. We do not want
 * warnings about this, so we suppress them. 
 */
public class Entity extends AbstractTuple {

	private static final int HASH_CODE = 31;

	public static final String ID_FIELDNAME = "id";
	public static final Class<?> ID_FIELDTYPE = Integer.class;
	public static final int ID_DEFAULT_VALUE = -1;
	private int m_id;
	
	public static final String NAME_FIELDNAME = "name";
	public static final Class<?> NAME_FIELDTYPE = String.class;
	public static final String NAME_DEFAULT_VALUE = "";
	private String m_name;
	
	public static final String TYPE_FIELDNAME = "type";
	public static final Class<?> TYPE_FIELDTYPE = Entity.Type.class;
	public static final Entity.Type TYPE_DEFAULT_VALUE = Entity.Type.PROCESS;
	private Type m_type;
	
	public static final String RUNNING_FIELDNAME = "running";
	public static final Class<?> RUNNING_FIELDTYPE = Boolean.class;
	public static final boolean RUNNING_DEFAULT_VALUE = true;
	private boolean m_running;

	public static final String STARTTICK_FIELDNAME = "starttick";
	public static final Class<?> STARTTICK_FIELDTYPE = Integer.class;
	public static final int STARTTICK_DEFAULT_VALUE = -1;
	private int m_startTick;

	public static final String ENDTICK_FIELDNAME = "endtick";
	public static final Class<?> ENDTICK_FIELDTYPE = Integer.class;
	public static final int ENDTICK_DEFAULT_VALUE = -1;
	private int m_endTick;

	public static final String TABLE_NAME = "entities";
	private static final int TABLE_COLUMNCOUNT = 6;
	public static final Schema TABLE_SCHEMA;
	static {
		TABLE_SCHEMA = new Schema(TABLE_COLUMNCOUNT);
		TABLE_SCHEMA.addColumn(ID_FIELDNAME, ID_FIELDTYPE, Integer.valueOf(ID_DEFAULT_VALUE));
		TABLE_SCHEMA.addColumn(NAME_FIELDNAME, NAME_FIELDTYPE, NAME_DEFAULT_VALUE);
		TABLE_SCHEMA.addColumn(TYPE_FIELDNAME, TYPE_FIELDTYPE, TYPE_DEFAULT_VALUE);
		TABLE_SCHEMA.addColumn(RUNNING_FIELDNAME, RUNNING_FIELDTYPE, Boolean.valueOf(RUNNING_DEFAULT_VALUE));
		TABLE_SCHEMA.addColumn(STARTTICK_FIELDNAME, STARTTICK_FIELDTYPE, Integer.valueOf(STARTTICK_DEFAULT_VALUE));
		TABLE_SCHEMA.addColumn(ENDTICK_FIELDNAME, ENDTICK_FIELDTYPE, Integer.valueOf(ENDTICK_DEFAULT_VALUE));
	}
	
	public static final String[] COLUMNS = {ID_FIELDNAME, NAME_FIELDNAME, TYPE_FIELDNAME, RUNNING_FIELDNAME, STARTTICK_FIELDNAME, ENDTICK_FIELDNAME};

	/**
	 * The Type of the Entity
	 */
	public enum Type {
		PROCESS,
		TOOL,
		SINK
	}

	/**
	 * Create a new Entity with default values.
	 */
	public Entity() {
		this(ID_DEFAULT_VALUE, NAME_DEFAULT_VALUE, TYPE_DEFAULT_VALUE, RUNNING_DEFAULT_VALUE, STARTTICK_DEFAULT_VALUE);
	}

	/**
	 * Create a new Entity of the given Type with default values.
	 * @param name the name of the Entity to create
	 * @param type the type of the Entity to create
	 */
	public Entity(String name, Type type) {
		this(ID_DEFAULT_VALUE, name, type, RUNNING_DEFAULT_VALUE, STARTTICK_DEFAULT_VALUE);
	}

	/**
	 * Create a new Entity with a given id and type.
	 * 
	 * @param id
	 *            The process or tool id
	 * @param name
	 * 			  The process or tool name
	 * @param type
	 *            The type of entity
	 * @param running
	 *            The status of entity
	 * @param startTick
	 *            The first tick of entity
	 */
	public Entity(int id, String name, Type type, boolean running, int startTick) {
		m_id = id;
		m_name = name;
		m_type = type;
		m_running = running;
		m_startTick = startTick;
		m_endTick = ENDTICK_DEFAULT_VALUE;
	}

	/**
	 * {@inheritDoc}
	 */
	public Object get(String field) {
		if (field.equals(ID_FIELDNAME)) {
			return Integer.valueOf(m_id);
		} else if (field.equals(NAME_FIELDNAME)) {
			return m_name;
		} else if (field.equals(TYPE_FIELDNAME)) {
			return m_type;
		} else if (field.equals(RUNNING_FIELDNAME)) {
			return Boolean.valueOf(m_running);
		} else if (field.equals(STARTTICK_FIELDNAME)) {
			return Integer.valueOf(m_startTick);
		} else if (field.equals(ENDTICK_FIELDNAME)) {
			return Integer.valueOf(m_endTick);
		}

		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Object get(int col) {
		if ((0 <= col) && (col < COLUMNS.length)) {
			return get(COLUMNS[col]);
		}

		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Class<?> getColumnType(String field) {
		if (field.equals(ID_FIELDNAME)) {
			return ID_FIELDTYPE;
		} else if (field.equals(NAME_FIELDNAME)) {
			return NAME_FIELDTYPE;
		} else if (field.equals(TYPE_FIELDNAME)) {
			return TYPE_FIELDTYPE;
		} else if (field.equals(RUNNING_FIELDNAME)) {
			return RUNNING_FIELDTYPE;
		} else if (field.equals(STARTTICK_FIELDNAME)) {
			return STARTTICK_FIELDTYPE;
		} else if (field.equals(ENDTICK_FIELDNAME)) {
			return ENDTICK_FIELDTYPE;
		}
		
		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Class<?> getColumnType(int col) {
		if ((0 <= col) && (col < COLUMNS.length)) {
			return getColumnType(COLUMNS[col]);
		}
		
		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	public Object getDefault(String field) {
		if (field.equals(ID_FIELDNAME)) {
			return Integer.valueOf(ID_DEFAULT_VALUE);
		} else if (field.equals(NAME_FIELDNAME)) {
			return NAME_DEFAULT_VALUE;
		} else if (field.equals(TYPE_FIELDNAME)) {
			return TYPE_DEFAULT_VALUE;
		} else if (field.equals(RUNNING_FIELDNAME)) {
			return Boolean.valueOf(RUNNING_DEFAULT_VALUE);
		} else if (field.equals(STARTTICK_FIELDNAME)) {
			return Integer.valueOf(STARTTICK_DEFAULT_VALUE);
		} else if (field.equals(ENDTICK_FIELDNAME)) {
			return Integer.valueOf(ENDTICK_DEFAULT_VALUE);
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
		if (field.equals(ID_FIELDNAME)) {
			set(field, Integer.valueOf(ID_DEFAULT_VALUE));
		} else if (field.equals(NAME_FIELDNAME)) {
			set(field, NAME_DEFAULT_VALUE);
		} else if (field.equals(TYPE_FIELDNAME)) {
			set(field, TYPE_DEFAULT_VALUE);
		} else if (field.equals(RUNNING_FIELDNAME)) {
			set(field, Boolean.valueOf(RUNNING_DEFAULT_VALUE));
		} else if (field.equals(STARTTICK_FIELDNAME)) {
			set(field, Integer.valueOf(STARTTICK_DEFAULT_VALUE));
		} else if (field.equals(ENDTICK_FIELDNAME)) {
			set(field, Integer.valueOf(ENDTICK_DEFAULT_VALUE));
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void set(String field, Object value) {
		Class<?> valueType = value.getClass();

		if (canSet(field, valueType)) {
			if (field.equals(ID_FIELDNAME)) {
				m_id = ((Integer) value).intValue();
			} else if (field.equals(NAME_FIELDNAME)) {
				m_name = (String) value;
			} else if (field.equals(TYPE_FIELDNAME)) {
				m_type = (Entity.Type) value;
			} else if (field.equals(RUNNING_FIELDNAME)) {
				m_running = ((Boolean) value).booleanValue();
			} else if (field.equals(STARTTICK_FIELDNAME)) {
				m_startTick = ((Integer) value).intValue();
			} else if (field.equals(ENDTICK_FIELDNAME)) {
				m_endTick = ((Integer) value).intValue();
			}
		}
	}

	/**
	 * {@inheritDoc}
	 */
	public void set(int col, Object value) {
		if ((0 <= col) && (col < COLUMNS.length)) {
			set(COLUMNS[col], value);
		}
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
		if (field.equals(ID_FIELDNAME)) {
			return type.equals(ID_FIELDTYPE);
		} else if (field.equals(NAME_FIELDNAME)) {
			return type.equals(NAME_FIELDTYPE);
		} else if (field.equals(TYPE_FIELDNAME)) {
			return type.equals(TYPE_FIELDTYPE);
		} else if (field.equals(RUNNING_FIELDNAME)) {
			return type.equals(RUNNING_FIELDTYPE);
		} else if (field.equals(STARTTICK_FIELDNAME))  {
			return type.equals(STARTTICK_FIELDTYPE);
		} else if (field.equals(ENDTICK_FIELDNAME)) {
			return type.equals(ENDTICK_FIELDTYPE);
		}

		return false;
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
	@Override
	public boolean equals(Object o) {
		if (this == o) {
			return true;
		}
		if (o == null || getClass() != o.getClass()) {
			return false;
		}

		Entity entity = (Entity) o;

		if (m_id != entity.m_id) {
			return false;
		}
		if (m_name != null ? !m_name.equals(entity.m_name) : entity.m_name != null) {
			return false;
		}
		if (m_type != entity.m_type) {
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
		result = m_id;
		result = HASH_CODE * result + (m_name != null ? m_name.hashCode() : 0);
		result = HASH_CODE * result + (m_type != null ? m_type.hashCode() : 0);
		result = HASH_CODE * result + (m_running ? 1 : 0);
		result = HASH_CODE * result + m_startTick;
		result = HASH_CODE * result + m_endTick;
		return result;
	}
}
