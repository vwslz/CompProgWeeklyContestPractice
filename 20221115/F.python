import math
n = int(input())
n_max = 10**9

def isPrime(in_m):
    for m in range(in_m+1, n_max, 1):
        is_prime = True
        if m % 2 == 0 or m % 3 == 0:
            is_prime = False
        else:
            for d in range(5, int(math.sqrt(m)) + 1, 1):
                if m % d == 0:
                    is_prime = False
                    break
        if is_prime:
            return m

for i in range(n):
    m = int(input())
    if m == 1:
        print(2)
    elif m == 2:
        print(3)
    else:
        print(isPrime(m))
