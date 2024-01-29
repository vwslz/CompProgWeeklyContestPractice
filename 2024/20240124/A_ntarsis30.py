s1 = list(input())
s2 = list(input())
n = len(s1)
pre = [-10**18]*4
pre[2*int(s1[0] == "X")+int(s2[0] == "X")] = 0

for i in range(1,n):
    dp = [-10**18]*4
    x = 2*int(s1[i] == "X")+int(s2[i] == "X")
    dp[x] = max(pre)

    if x == 0:
        dp[3] = max(pre[1],pre[2]) + 1
        dp[1] = pre[0] + 1
        dp[2] = pre[0] + 1
    elif x != 3:
        dp[3] = pre[0] + 1
    # print(dp)
    pre = dp
print(max(pre))
