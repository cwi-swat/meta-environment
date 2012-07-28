#!/bin/sh

cpp CFG.defacto | grep -v "^#" > JavaCFG.defacto
