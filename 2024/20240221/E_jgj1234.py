num_tests=int(input())
for _ in range(num_tests):
    n,k=list(map(int,input().split()))
    start=1
    gap=2
    while True:
        num_iteration=(n+start)//(gap)
        if k-num_iteration<=0:
            print(start+gap*(k-1))
            break
        k-=num_iteration
        start*=2
        gap*=2
