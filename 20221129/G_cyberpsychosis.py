n=int(input())

for _ in range(n):
    item=str(input())
    last_d=int(item[-1])
    if(last_d%2==0):
        #even
        bformat=bin(int(item))[2:]
        bformat=bformat[::-1]
        revint=int(bformat,2)
        print(revint)
    else:
        print(item)
    