my @a=split('',"aAあア");loop (my $i=0;$i<26;$i++) {my @e<==map {chr(ord($_)+$i)}<==@a;print(@e,reverse @e);}