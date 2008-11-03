#!/bin/sh

cpp sudoku.pp.rscript | grep -v "^#" > sudoku.rscript
