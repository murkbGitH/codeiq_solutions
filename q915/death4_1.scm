(map (lambda (J) (map (lambda (I) (display(integer->char(+ (* I (* (+ 1 J) 2)) 36)))) (iota (+ 1 (quotient 40 (+ 1 J)))))) (iota 8))