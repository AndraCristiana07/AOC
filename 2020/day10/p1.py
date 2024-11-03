def count_joltage_diff(adapters):
    adapters.sort()
    diff_1 = 0
    diff_3 = 1
    for i in range(len(adapters) - 1):
        diff = adapters[i + 1] - adapters[i]
        if diff == 1:
            diff_1 += 1
        elif diff == 3:
            diff_3 += 1
        
    print(diff_1, diff_3)
    return diff_1 * diff_3

with open("input.in") as f:
    lines = f.readlines()
    adapters = [int(line.strip()) for line in lines]
    adapters.append(0)
    print(count_joltage_diff(adapters))