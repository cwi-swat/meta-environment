
# master.tcl
# Jan Kort
# 8912041

proc rec-terminate {n} {
  destroy .
  exit
}

button .quit -text "Quit" -command {
  destroy .
  sendTB "snd-event(quit)"
}

pack .quit

