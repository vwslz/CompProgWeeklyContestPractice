num_tests=int(input())
for _ in range(num_tests):
    string=input()
    if string.count('B')>=3:
        print('B')
    else:
        print('A')
