T = int(input())

for i_t in range(T):
    n = int(input())
    heights = list(map(int, input().split()))
    costs = list(map(int, input().split()))

    map_h_to_c = {}

    for i in range(n):
        if heights[i] in map_h_to_c:
            map_h_to_c[heights[i]] += costs[i]
        else:
            map_h_to_c[heights[i]] = costs[i]

    heights_uni = map_h_to_c.keys()
    costs_uni = map_h_to_c.values()

    heights_uni, costs_uni = zip(*sorted(zip(heights_uni, costs_uni)))

    # print(heights_uni)
    # print(costs_uni)
    n = len(heights_uni)
    iter_h = 0
    res = 0
    iter_l = 0
    iter_r = sum(costs_uni)

    for i in range(n):
        res += (heights_uni[i]) * costs_uni[i]

    res_min = res

    for i in range(0, n, 1):
        res += iter_l * (heights_uni[i] - iter_h)
        res -= iter_r * (heights_uni[i] - iter_h)
        iter_h = heights_uni[i]
        iter_l += costs_uni[i]
        iter_r -= costs_uni[i]
        if res < res_min:
            res_min = res

    print(res_min)
