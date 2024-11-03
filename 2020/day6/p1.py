def sum():
    total_count = 0
    with open("input.in") as f:
        group_answers = set()
        for line in f:
            line = line.strip()
            if line == "":
                total_count += len(group_answers)
                group_answers = set()
            else:
                group_answers = group_answers.union(set(line))
                
        total_count += len(group_answers)
        return total_count
    
print(sum())
            