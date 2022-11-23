import math
while True:
    try:

        a,b,c = map(int,input().split())
        
        p=(a+b+c)/2
        s_triangle=math.sqrt(p*(p-a)*(p-b)*(p-c))#traingle area
        
        r_inner = 2*s_triangle / (a+b+c)#inner circle radius
        s_inner = r_inner*r_inner*math.pi #inner circle area
        R_out = (a*b*c) / (4.0*s_triangle) #outer circle radius
        S_outer = R_out*R_out*math.pi #outer circle area
        ans1,ans2,ans3 = S_outer-s_triangle,s_triangle-s_inner, s_inner
        print(f'{ans1:.4f} {ans2:.4f} {ans3:.4f}')
    except EOFError:
        break
