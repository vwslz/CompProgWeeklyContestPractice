n = int(input())
for _ in range(n):
    def solve(l):
        s = []
        for c in l:
            if c == '(':
                s.append(c)
            elif c == '[':
                s.append(c)
            elif c == ']':
                if not s or s[-1] != '[':
                    print("No")
                    return
                s.pop()
            elif c == ')':
                if not s or s[-1] != '(':
                    print("No")
                    return
                s.pop()
        if s:
            print("No")
        else:
            print("Yes")
    l = input()
    solve(l)
