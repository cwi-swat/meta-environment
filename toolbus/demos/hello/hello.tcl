proc get-text {} {
   TBsend "snd-value(\"Hello World, my first ToolBus tool in Tcl!\n\")"
}

proc rec-terminate { n } {
   exit
}
