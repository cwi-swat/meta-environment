
button .error -text "Error" -command "generate-error"
button .activate -text "Activate" -command "activate"
pack .error -side top -fill x
pack .activate -side top -fill x

proc generate-error { } {
  puts stderr "Generating an error!"
  set a [expr 4+abc]
  puts stderr "huh?, a=$a"
}

proc activate { } {
  puts stderr "Activate:"
  TBsend "snd-event(activate)"
}
