import sys
input = sys.stdin.readline
from math import gcd
n = int(input())
nums = [int(x) for x in input().split()]
graph=[0]*n
for i in range(n):
    for j in range(n):
        if gcd(nums[i],nums[j])>1:
            graph[i]|=1<<j
left = [0]*(n+1)
right = [0]*n
for l in range(n):
    r=l+1
    left[r]|=1<<l
    right[l]|=1<<r
for i in range(2,n+1):
    for l in range(n+1-i):
        r=l+i
        x=(1<<r-l-1)-1
        if (graph[l]>>l+1)&(right[l+1]>>l+2)&(left[r]>>l+1)&x:
            left[r]|=1<<l
        if (graph[r-1]>>l)&(right[l]>>l+1)&(left[r-1]>>l)&x:
            right[l]|=1<<r
print("Yes") if right[0]>>1&left[n]&((1<<n)-1) else print("No")
