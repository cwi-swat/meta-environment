proc TBmakeArgs { name } {
  global Tide

  set args [info args $name]
  set ret ""

  foreach arg $args {
    if {[info default $name $arg val]} {
       lappend ret "$arg $val"
    } else {
       lappend ret $arg
    }
  }
  return $ret
}
proc TBprepareProc { proc } {
  global Tide

  puts stderr "TBprepareProc: $proc"
  if { ![info exists Tide($proc,line)] } {
    puts stderr "proc $proc is not indexed."
    return
  }
  if { ![info exists Tide($proc,body)] } {
    if { [info commands $proc] != $proc } {
      puts stderr "proc $proc is not defined."
      return
    }
    set Tide($proc,body) [split [info body $proc] \n]
    set Tide($proc,args) [TBmakeArgs $proc]
  }
  set last [expr $Tide($proc,line) + [llength $Tide($proc,body)]-1]

  set result [TBparseScript $proc]
  set port [tbport [list location before $Tide($proc,mod) $last 0 $last -1]]
  eval "TBorigProc $proc \{$Tide($proc,args)\} \
				\{#tide \n $result \nTBtide $port \{\}\}"
}
proc TBrestoreProc { proc } {
  global Tide

  eval "TBorigProc $proc \{$Tide($proc,args)\} \{ $res \}"
}
proc TBparseScript { proc } {
  global Tide

  set switch -1
  set mod $Tide($proc,mod)
  set start $Tide($proc,line)
  set script $Tide($proc,body)
  set len [llength $script]

  set lnum [expr $start]
  for { set cur 0 } { $cur < $len } { incr cur; incr lnum } {
     set line [lindex $script $cur]

     if { [regexp {^#line ([0-9]+) "([^"]+)"$} $line match nr module]} {
       set lnum $nr
       set mod $module
       continue
     }

     # Split the line into tokens
     regexp "(^\[ \t\]*)(\[^ \t;\]*)(.*)" $line match blank token rest

     # Skip empty and/or commented lines
     if { $token == "" || [string match "#*" $token] } { 
	append result $line\n ; continue
     }    

     if [string match "\}*" $token] {
       set rline $line
     } elseif {[regexp "(break|continue|return)(\[ \t;\]|$)" $line]} {
       # avoid uplevel with these
       set port [tbport [list location before $mod $lnum 0 $lnum -1]]
       set rline "TBtide $port \{\} ; $line"
     } elseif { [info complete $line] && $lnum > $switch } {
       set port [tbport [list location before $mod $lnum 0 $lnum -1]]
       set rline "TBtide $port \{$line\}"
     } elseif {[string match "bind" $token]} {
       set rline $line
       while {$lnum < $len} {
         if {[info complete $rline]} break
         append rline \n[lindex $script $lnum]
         incr lnum
       }
     } elseif {[string match "switch" $token]} {
       set temp $line
       set port [tbport [list location before $mod $lnum 0 $lnum -1]]
       set rline "TBtide $port {} ; $line"
       set l $lnum
       while {$l < $len} {
         if {[info complete $temp]} break
         append temp \n[lindex $script $l]
         incr l
       }
       set switch $l
       puts stderr "switch: $switch"
     } elseif {$lnum > $switch} {
       set port [tbport [list location before $mod $lnum 0 $lnum -1]]
       set rline "TBtide $port {} ; $line"
     } else {
       set rline $line
       puts stderr "inside switch: $rline"
     }
     append result "$rline\n"
  }
  return $result
}

proc TBindexFile { file } {
  global Tide

  foreach path $Tide(search-paths) {
    if {[file readable $path/$file]} {
      set f [open $path/$file]
      set line 1
      while { ![eof $f] } {
        gets $f l
        if { [regexp "^\[ \t\]*proc\[ \t\]*(\[^ \t\]*)\[ \t\]+" $l m name] } {
	  lappend Tide(do-prepare) $name
	  set Tide($name,line) $line
	  set Tide($name,mod) $file
        }
	incr line
      }
      break
    }
  }
}

proc tbport { port } {
  set port [lreplace $port 2 2 [TBstring [lindex $port 2]]]
  return \{[TBlist $port]\}
}

proc TBproc { name args body } {
  global Tide

  eval "TBorigProc $name \{$args\} \{ $body \}"
  if { [lsearch $name $Tide(dont-prepare)] == -1 } {
    set prep 0
    foreach pat $Tide(do-prepare) {
      if {[string match $pat $name]} {
        foreach pat $Tide(dont-prepare) {
          if {[string match $pat $name]} {
            eval "TBorigProc $name \{$args\} \{ $body \}"
            return
          }
        }
#        set Tide($name,body) $body
#        set Tide($name,args) $args
        TBprepareProc $name
      }
    }
  }
}

set Tide(do-prepare) {}
set Tide(dont-prepare) {}
set Tide(search-paths) { . }

if { [file readable ".tide/tclrc"] } {
  source ".tide/tclrc"
}

puts stderr "Tide(do-prepare) = $Tide(do-prepare)"

rename proc TBorigProc
rename TBproc proc
