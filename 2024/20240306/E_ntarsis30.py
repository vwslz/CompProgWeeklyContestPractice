import bisect


T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))

    # Compute prefix sums
    s = [0] * (n + 1)
    for i in range(n):
        s[i+1] = s[i] + a[i]
    rdiff = [n] * n
    for i in range(n-2, -1, -1):
        rdiff[i] = i + 1 if a[i] != a[i + 1] else rdiff[i + 1]
    ldiff = [-1] * n
    for i in range(1, n):
        ldiff[i] = i - 1 if a[i] != a[i - 1] else ldiff[i - 1]

    # Compute and print the answers
    final = [0]*n
    for i in range(n):
        ans = n
        if i + 1 < n:
            if a[i] < a[i + 1]:
                ans = 1
            r = bisect.bisect_left(s, s[i + 1] + a[i] + 1) - 1
            r = max(r, rdiff[i + 1])
            if r != n:
                ans = min(ans, r - i)
        if i > 0:
            if a[i] < a[i - 1]:
                ans = 1
            l = bisect.bisect_left(s, s[i] - a[i]) - 1
            l = min(l, ldiff[i - 1])
            if l != -1:
                ans = min(ans, i - l)
        if ans == n: final[i]=-1
        else: final[i]=ans
    print(*final)
