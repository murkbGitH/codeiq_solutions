#import<stdio.h>
int i;main(){for(;++i<51;)printf(i%5?i%3?"%d":"fizz":i%3?"buzz":"FIZZBUZZ",i);}