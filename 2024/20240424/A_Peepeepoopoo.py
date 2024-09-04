def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    m = int(data[1])
    group_sizes = list(map(int, data[2:]))

    bus_count = 0
    current_load = 0

    for size in group_sizes:
        if current_load + size > m:
            bus_count += 1
            current_load = size
        else:
            current_load += size

    if current_load > 0:
        bus_count += 1

    print(bus_count)

if __name__ == "__main__":
    main()
