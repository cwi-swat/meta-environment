# hello.tcl -- hello tool in Tcl/Tk

proc get-text {} {
   TBsend "snd-value(text(\"Hello World, my first ToolBus tool in Tcl!\n\"))"
}

proc rec-terminate { n } {
   exit
}
