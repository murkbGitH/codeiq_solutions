for {set J 1} {$J < 9} {incr J} {for {set I 36} {$I < 117} {set I [expr $I+$J*2]} {puts -nonewline [format %c $I]}}