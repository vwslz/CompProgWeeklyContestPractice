t = (int)(input())

def toDecimal(binary):
    ans = 0
    pow = 0
    for i in range(len(binary)-1,-1,-1):
        if binary[i]=="1":
            ans+= (2**pow)
        pow+=1
    return ans


for it in range(1,t+1):
    a = input()
    b = input()

    partsa = a.split(".")
    partsb = b.split(".")
    yes = True
    for i in range(len(partsb)):
        if toDecimal(partsb[i])!=(int)(partsa[i]):
            yes = False
        #print(f'parts b is {toDecimal(partsb[i])}')

    if yes:
        print(f'Case {it}: Yes')
    else:
        print(f'Case {it}: No')
