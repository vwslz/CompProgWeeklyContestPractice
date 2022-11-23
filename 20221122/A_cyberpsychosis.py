n=int(input())
d={}#key=item, val=count
homo=0
for _ in range(n):
    items=input().split()
    op,digit=items[0],items[1]
    hetero=0
    if(op=='insert'):
        if(digit not in d):
            d[digit]=0
        d[digit]+=1
        if(d[digit]==2):
            homo+=1
    elif(op=='delete'):
        if(digit in d):
            d[digit]-=1
            if(d[digit]==1):
                homo-=1
            if(d[digit]==0):
                del d[digit]
    
    hetero=len(d)
        
    if(hetero>=2 and homo>=1):
        print("both")
    elif(hetero>=2):
        print("hetero")
    elif(homo>=1):
        print("homo")
    else:
        print("neither")