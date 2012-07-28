package nl.cwi.sen1.visplugin.table.model;


/**
 * Table sorter. Sorts a table using comparators
 *
 * @author Anton Gerdessen
 * @date 12-03-2007
 */
public class TableSorter {
    SortableTableModel model;

    /**
     * Constructor.
     *
     * @param model The model to sort
     * @author Anton Gerdessen
     * @date 12-03-2007
     */
    public TableSorter(SortableTableModel model) {
        this.model = model;
    }

    /**
     * Sort the table on a given column and an order.
     *
     * @param column the column to sort on
     * @param isAscent ascending (true) or or decending (false) order
     * @author Anton Gerdessen
     * @date 12-03-2007
     */
    public void sort(int column, boolean isAscent) {
        int rowCount = model.getRowCount();
        int[] indexes = model.getIndexes();

        // Quicksort
        for (int rowCounter = 0; rowCounter < rowCount - 1; rowCounter++) {
            int row1 = rowCounter;
            for (int row2 = rowCounter + 1; row2 < rowCount; row2++) {
                // Sort ascending.
                if (isAscent) {
                    if (compare(column, row2, row1) < 0) {
                        row1 = row2;
                    }
                // Sort decending.
                } else {
                    if (compare(column, row2, row1) > 0) {
                        row1 = row2;
                    }
                }
            }
            int tmp = indexes[rowCounter];
            indexes[rowCounter] = indexes[row1];
            indexes[row1] = tmp;
        }
    }

    /**
     * Compare two values in one column, these two values are the values
     * at (column, row1) and (column, row2).
     *
     * @param column the column to sort on
     * @param row1 The numbers to compare
     * @param row2 The numbers to compare
     * @author Anton Gerdessen
     * @date 12-03-2007
     */
    private int compare(int column, int row1, int row2) {
        Object o1 = model.getValueAt(row1, column);
        Object o2 = model.getValueAt(row2, column);

        // Check for null values, of a null is detected the 'other' is always greater
        // if both are null return equal
        if (o1 == null && o2 == null) {
            return 0;
        } else if (o1 == null) {
            return -1;
        } else if (o2 == null) {
            return 1;
        }

        // Determine the data type used in the column and call the compare for that type.
        // Default is the string compareTo.
        Class<?> type = model.getColumnClass(column);
        if (type.getSuperclass() == Number.class) {
            return compare((Number) o1, (Number) o2);
        } else if (type == String.class) {
            return ((String) o1).compareTo((String) o2);
        } else {
            return (o1.toString().compareTo(o2.toString()));
        }
    }

    /**
     * Number comparator based on doubles. Return -1 if num2
     * is greater, 1 if num1 is greater, else 0.
     *
     * @param num1 The numbers to compare
     * @param num2 The numbers to compare
     * @author Anton Gerdessen
     * @date 12-03-2007
     */
    private int compare(Number num1, Number num2) {
        double n1 = num1.doubleValue();
        double n2 = num2.doubleValue();

        if (n1 < n2) {
            return -1;
        } else if (n1 > n2) {
            return 1;
        } else {
            return 0;
        }
    }



}