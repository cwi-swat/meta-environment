#
#    ToolBus -- The ToolBus Application Architecture
#    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
#                             The  Netherlands.
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#

set X0   40
set Y0   150
set DX   20

wm withdraw .

proc mk-wave {n} {
     global X0 Y0 DX
     puts stderr "mk-wave: $n"
     set w .string
     toplevel $w
     wm title $w "String Vibrations"
     canvas $w.canvas -width [expr $n * $DX +4*$DX] -height 350
     pack $w.canvas

     $w.canvas create line $X0 [expr $Y0 +2] [expr $X0 +$n*$DX] [expr $Y0 + 2]
     puts stderr "before loop: '$n'"
     for {set i 0} {$i <= $n} {incr i} {
       puts stderr "drawing oval $i"
     $w.canvas create oval [expr $X0 + $i*$DX] [expr $Y0 + 2] [expr $X0+$i*$DX + 4] [expr $Y0 - 2] -fill red -tags point$i
     }
}

proc update {i newy} {
     global X0 Y0 DX

     #puts stderr "update: $i $newy"
     set Y [expr $Y0 + $newy*100]
     .string.canvas coords point$i [expr $X0 + $i*$DX] $Y [expr $X0+$i*$DX + 5] [expr $Y + 5]
}

proc rec-terminate { n } {
     exit
}
