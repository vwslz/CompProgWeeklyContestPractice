item=input()

def LTE(a,b):
    if(len(a)!=len(b)):
        #smaller length always smaller
        return len(a)<len(b)
    #same len
    for i in range(len(a)):
        if(a[i]<b[i]):
            return True
        elif(a[i]>b[i]):
            return False
    #equal
    return True

if(item[0]!='-'):
    #positive
    if LTE(item,'127'):
        print("byte")
    elif LTE(item,'32767'):
        print("short")
    elif LTE(item,'2147483647'):
        print("int")
    elif LTE(item,'9223372036854775807'):
        print("long")
    else:
        print("BigInteger")
else:
    #negative
    item=item[1:]
    if LTE(item,'128'):
        print("byte")
    elif LTE(item,'32768'):
        print("short")
    elif LTE(item,'2147483648'):
        print("int")
    elif LTE(item,'9223372036854775808'):
        print("long")
    else:
        print("BigInteger")