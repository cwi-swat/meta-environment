/*************************************************************************
 * Copyright (c) 2009 University of Amsterdam, The Netherlands.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 ************************************************************************/
package org.dancingbear.graphbrowser.editor.draw2d.figure.shapes;

import org.eclipse.draw2d.Graphics;
import org.eclipse.draw2d.Shape;
import org.eclipse.draw2d.geometry.Dimension;
import org.eclipse.draw2d.geometry.PointList;
import org.eclipse.draw2d.geometry.Rectangle;

/**
 * Representation of a parallelogram.
 * 
 * @author Ka-Sing Chou
 * @date 10-03-2009
 */
public class ParallelogramShape extends Shape {

    private final static double STEEPNESS = 0.25;

    /**
     * @see Shape#fillShape(Graphics)
     */
    @Override
    protected void fillShape(Graphics graphics) {
        PointList points = calculatePoints();
        graphics.fillPolygon(points);
    }

    /**
     * @see Shape#outlineShape(Graphics)
     */
    @Override
    protected void outlineShape(Graphics graphics) {
        PointList points = calculatePoints();
        graphics.drawPolygon(points);
    }

    /**
     * Retrieve points of parallelogram, based on current boundaries.
     * 
     * @return points
     */
    private PointList calculatePoints() {
        Rectangle bounds = getBounds();
        Dimension distance = getSize().getScaled(0.5 * STEEPNESS);
        PointList parallelogram = new PointList(4);
        parallelogram
                .addPoint(bounds.getTopLeft().translate(distance.width, 0));
        parallelogram.addPoint(bounds.getTopRight());
        parallelogram.addPoint(bounds.getBottomRight().translate(
                -distance.width, 0));
        parallelogram.addPoint(bounds.getBottomLeft());
        return parallelogram;
    }
}
