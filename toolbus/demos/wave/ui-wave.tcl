
set X0   40
set Y0   150
set DX   20

wm withdraw .

proc mk-wave {n} {
     global X0 Y0 DX
     set w .string
     toplevel $w
     wm title $w "String Vibrations"
     canvas $w.canvas -width [expr $n * $DX +4*$DX] -height 350
     pack $w.canvas

     $w.canvas create line $X0 [expr $Y0 +2] [expr $X0 +$n*$DX] [expr $Y0 + 2]
     for {set i 0} {$i <= $n} {incr i} {
     $w.canvas create oval [expr $X0 + $i*$DX] [expr $Y0 + 2] [expr $X0+$i*$DX + 4] [expr $Y0 - 2] -fill black -tags point$i
     }
}

proc update {i newy} {
     global X0 Y0 DX
     set Y [expr $Y0 + $newy*100]
     .string.canvas coords point$i [expr $X0 + $i*$DX] $Y [expr $X0+$i*$DX + 5] [expr $Y + 5]
}

proc rec-terminate { n } {
     exit
}
