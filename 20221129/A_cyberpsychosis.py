n=int(input())
for _ in range(n):
    a,b,c=map(int,input().split(" "))
    ls=[a,b,c]
    ls.sort()
    print(ls[1])