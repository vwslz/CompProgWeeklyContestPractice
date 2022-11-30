n,V=map(int,input().split(" "))
alist=[int(x) for x in input().split(" ")]
blist=[int(x) for x in input().split(" ")]
#empty one item from blist
ans=0
minrate=100000
for i in range(n):
    #empty ith item from blist,see if it works
    rate=blist[i]/alist[i] # how many food should cook
    minrate=min(minrate,rate)
total=0
for i in range(n):
    total+=alist[i]*minrate
print(min(V,total))