(print (apply str (map (fn [J] (apply str (map (fn [I] (char (+ (* I (* J 2)) 36))) (range (+ 1 (quot 40 J)))))) (range 1 9))))