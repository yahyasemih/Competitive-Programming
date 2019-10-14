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
 
n = int(input())
if fermatPrimeTest(n, 20) == False:
	print('no')
	exit()
else :
	m = 0
	r = [0, 1, 2, -1, -1, 5, 9, -1, 8, 6]
	while n:
		m *= 10
		if r[n%10] == -1 :
			print('no')
			exit()
		m += r[n%10]
		n //= 10
	if fermatPrimeTest(m, 20):
		print('yes')
		exit()
print('no')
