#!/usr/bin/python
import sys
if sys.version_info[0]>=3: xrange=range
from fractions import gcd
def miller_rabin(n):
	n=abs(n) #todo#
	if n==2: return True
	if n==1 or n%2==0: return False
	d=n-1
	s=0
	while d%2==0:
		d//=2
		s+=1
	a=1
	for _ in xrange(5): #todo#
		a+=1
		while gcd(a,n)!=1: a+=1 #todo#
		r=pow(a,d,n)
		if r==1 or r==n-1: continue
		for j in xrange(s):
			r=pow(r,2,n)
			if r==n-1: break
		else:
			return False
	return True

def rho3(n):
	#get one divisor
	def rhonext(x,n,seed): return (x*x+seed)%n
	for seed in [1,3,5]: #todo#
		x=y=1 #todo#
		q=i=1
		while True:
			if i==q:
				y=x
				q*=2
			x=rhonext(x,n,seed)
			d=gcd(abs(x-y),n)
			if d>1:
				if d==n: break
				return d
			i+=1
	return None

def rho2(n):
	#get all divisors
	r=[]
	while n>1:
		if miller_rabin(n):
			return r+[n]
		else:
			x=rho3(n)
			if not x:
				#STDERR.puts 'suspicious: %d'%n
				return r+[n]
			r+=rho2(x)
			n//=x
	return r

def rho(n):
	r=[]
	if n<0:
		r.append(-1)
		n=-n
	if n<2: return r
	for e in [2]: #todo#
		while n%e==0:
			n//=e
			r.append(e)
	if n==1: return r
	return r+rho2(n)

from collections import Counter,defaultdict
from functools import reduce
'''
try:
	import sympy
	factor=sympy.factorint
except ImportError:
	try:
		import nzmath
		factor=nzmath.factor.methods.factor
	except ImportError:
		import sys
		print('sympy or nzmath is required')
		sys.exit(1)
'''
factor=lambda n:Counter(rho(n))

def solve(h):
	return (reduce(lambda s,e:s*(2*e[1]+1),h.items(),1)+1)//2
def range_factor(r):
	h=defaultdict(int)
	for i in r:
		for e in factor(i).items(): h[e[0]]+=e[1]
	return h

print(solve(factor(24)))
print(solve(factor(720)))
print(solve(range_factor(range(1,51))))

# print (reduce(lambda s,e:s*(2*e[1]+1),__import__('sympy').factorint(reduce(lambda a,b:a*b,range(1,51))).items(),1)+1)/2
