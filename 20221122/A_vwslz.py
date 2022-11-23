N = int(input())

res_lst = {}
homo_lst = {}

for i in range(N):
    #print(list(res_lst.keys()))
    #print(list(res_lst.values()))
    op, ele = input().split()
    if op == 'insert':
        if ele in res_lst:
            res_lst[ele] += 1
            if res_lst[ele] == 2:
                homo_lst[ele] = True
        else:
            res_lst[ele] = 1
    elif op == 'delete':
        if ele in res_lst:
            res_lst[ele] -= 1
            if res_lst[ele] == 1:
                homo_lst.pop(ele)
            if res_lst[ele] == 0:
                res_lst.pop(ele)
    if len(res_lst) < 2 and len(homo_lst) == 0:
        print('neither')
    elif len(res_lst) >= 2 and len(homo_lst) > 0:
        print('both')
    elif len(res_lst) >= 2:
        print('hetero')
    else:
        print('homo')
