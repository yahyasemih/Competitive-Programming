import math
n, t  = [int(e) for e in input().split()]
if n == 1 and t < 10:
    print(t)
    exit(0)
s = int('1'+((n-1)*'0'))
while s % t != 0:
    s += 1
if (len(str(s)) == n):
    print(s)
else:
    print(-1)
