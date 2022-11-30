import math

def binsearch(hi,lo,precision,A,B,C):
    while(lo<hi and hi-lo>precision):
        mid=(lo+hi)/2
        res=A*mid+B*math.sin(mid)-C
        if(res==0):
            return mid
        elif(res<0):
            lo=mid
        else:
            hi=mid
    return lo
n=int(input())
for _ in range(n):
    a,b,c=map(int,input().split(" "))
    res=binsearch(100000,0,0.000001,a,b,c)
    print(f'{res:.6f}')