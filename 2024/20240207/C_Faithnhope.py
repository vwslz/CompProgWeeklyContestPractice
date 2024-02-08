N = int(input())
from math import log
for _ in range(N):
    a,b,S = map(float,input().split())
    if S ==0:
        print("{:.6f}".format(100)+'%')
    elif S/b>=a:
        print("0.000000%")
    else:
        print("{:.6f}".format((4*(a*b-S-S*log(a)+S*log(S/b))/(4*a*b))*100)+"%")
