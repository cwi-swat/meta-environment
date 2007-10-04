package nl.cwi.sen1.visplugin.table.model;

import java.io.FileOutputStream;
import java.io.IOException;

import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.IdCon;
import nl.cwi.sen1.relationstores.types.RElem;
import nl.cwi.sen1.relationstores.types.RElemElements;
import nl.cwi.sen1.relationstores.types.RStore;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RTupleRtuples;
import nl.cwi.sen1.relationstores.types.RType;
import nl.cwi.sen1.visplugin.VisualizationFactorySingleton;

/**
 * Provides exporting functions for data in the SortableTableModel.
 *
 * @author Anton Gerdessen
 * @author Arend van Beelen
 * @date 13-03-2007
 */
public class SortableTableModelExporter {

    Factory m_factory;
    SortableTableModel m_model;

    /**
     * Default constructor.
     *
     * @param model The model on which the exporter will operate.
     *
     * @author Anton Gerdessen
     * @author Arend van Beelen
     * @date 13-03-2007
     */
    public SortableTableModelExporter(SortableTableModel model) {
        m_factory = VisualizationFactorySingleton.getFactoryInstance();
        m_model = model;
    }

    /**
     * Exports a selection from a table model to an RStore file.
     *
     * @param filename File to save the generated RStore to.
     * @param selectedRows An array containing the indexes of all the table
     *                     rows that will be exported. If the array is empty,
     *                     the entire table will be exported.
     *
     * @author Anton Gerdessen
     * @author Arend van Beelen
     * @date 13-03-2007
     */
    public void exportToRStore(String filename, int[] selectedRows) {

        // select all rows if an empty list of rows is given
        if(selectedRows.length == 0) {
            selectedRows = new int[m_model.getRowCount()];
            for(int rowIndex = 0; rowIndex < m_model.getRowCount(); rowIndex++) {
                selectedRows[rowIndex] = rowIndex;
            }
        }

        RElemElements elements = m_factory.makeRElemElements();
        for(int rowIndex : selectedRows) {
            RElem element = m_model.getRElemForRow(rowIndex);
            elements = elements.append(element);
        }
        IdCon variable = m_model.getRTupleVariable();
        RType rType = m_model.getRTupleRType();
        RElem value = m_factory.makeRElem_Set(elements);
        RTuple rTuple = m_factory.makeRTuple_Rtuple(variable, rType, value);
        RTupleRtuples rTupleRTuples = m_factory.makeRTupleRtuples(rTuple);
        RStore rStore = m_factory.makeRStore_Rstore(rTupleRTuples);
        try {
            rStore.toTerm().writeToTextFile(new FileOutputStream(filename));
        }
        catch(IOException exception) {
            System.err.println("Could not write RStore to file " + filename + ".");
        }
    }
}
