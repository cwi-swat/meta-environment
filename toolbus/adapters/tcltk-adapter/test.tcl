proc input { arg } {
  puts stderr "input: '$arg'"
  set Arg [TBstring "a\[b\]c\""]
  TBsend "snd-event(output($Arg))"
}

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

proc activate { } {
  puts stderr "Activate:"
  TBsend "snd-event(activate)"
}

proc generate-error { } {
  puts stderr "Generating an error!"
  set a [expr 4+abc]
  puts stderr "huh?, a=$a"
}

proc rec-ack-event { event } {
  puts stderr "ack: $event"
}

proc rec-terminate { arg } {
  exit
}

button .error -text "Error" -command "generate-error"
button .activate -text "Activate" -command "activate"
pack .error -side top -fill x
pack .activate -side top -fill x
