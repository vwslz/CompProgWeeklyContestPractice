import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    p = [0, 0] + list(map(int, input().split()))
    s = '#' + input()
    dp = [[0]*2 for _ in range(n+1)]
    for i in range(n, 0, -1):
        if s[i] == 'S': dp[i][1] = float("inf")
        if s[i] == 'P': dp[i][0] = float("inf")
        dp[p[i]][0] += min(dp[i][0], dp[i][1] + 1)
        dp[p[i]][1] += min(dp[i][0] + 1, dp[i][1])
    print(min(dp[0]))
