#line 23 "test.tcl.nw"
proc input { arg } {
  puts stderr "input: '$arg'"
#  TBsend "snd-event(output([TBstring $arg]))"
  set Arg [TBstring "a\[b\]c\""]
  TBsend "snd-event(output($Arg))"
}
#line 34 "test.tcl.nw"
proc input2 { arg } {
  puts stderr "input2: '$arg'"
  foreach el $arg {
    puts stderr "el: $el"
    if { [llength $el] > 1 } {
      foreach subel $el {
        puts stderr "subel: $subel"
      }
    }
  }
}
#line 72 "test.tcl.nw"
proc activate { } {
  puts stderr "Activate:"
  TBsend "snd-event(activate)"
}
#line 62 "test.tcl.nw"
proc generate-error { } {
  puts stderr "Generating an error!"
  set a [expr 4+abc]
  puts stderr "huh?, a=$a"
}
#line 49 "test.tcl.nw"
proc rec-ack-event { event } {
  puts stderr "ack: $event"
}
#line 55 "test.tcl.nw"
proc rec-terminate { arg } {
  exit
}

#line 12 "test.tcl.nw"
button .error -text "Error" -command "generate-error"
button .activate -text "Activate" -command "activate"
pack .error -side top -fill x
pack .activate -side top -fill x
