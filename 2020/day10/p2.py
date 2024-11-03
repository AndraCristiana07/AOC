import itertools

def count_arrangements(adapters):
    adapters.sort()
    arrangements = [0 for element in range(adapters[-1] +1)]
    arrangements[0] = 1
    
    for adapter in adapters:
        for i in range(1, 4): 
            if adapter - i >= 0:
                arrangements[adapter] += arrangements[adapter - i]
    
    return arrangements[-1]



with open("input.in") as f:
    lines = f.readlines()
    adapters = [int(line.strip()) for line in lines]
    adapters.append(0)
    print(count_arrangements(adapters))