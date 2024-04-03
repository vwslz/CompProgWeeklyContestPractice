n = int(input())
a = list(map(int, input().strip().split()))
m = int(input())
q = list(map(int, input().strip().split()))

pref = [0]
s = 0
for i in a:
    s += i
    pref.append(s)

for i in q:
    l, r = 1, n
    while l <= r:
        m = (l + r) // 2
        if pref[m] >= i and pref[m - 1] < i:
            print(m)
            break
        elif pref[m] < i:
            l = m + 1
        else:
            r = m - 1
