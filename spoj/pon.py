import random
 
def bpow(a, b, m):
	a = a % m
	res = 1
	while b > 0:
		if b & 1:
			res = (res * a) % m
		a = (a * a) % m
		b >>= 1
	return res
 
def fermatPrimeTest(n, it):
	if n < 4:
		return (n == 2 or n == 3)
	while it > 0:
		a = 2 + random.randrange(0, n - 3)
		if bpow(a, n - 1, n) != 1 :
			return False
		it -= 1
	return True
 
t = int(input())
for i in range(t):
	n = int(input())
	if fermatPrimeTest(n, 20) : print('YES')
	else : print('NO')
