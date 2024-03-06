def sum():
    total_count = 0
    with open("input.in") as f:
        group_answers = None  
        for line in f:
            line = line.strip()
            if line == "":
                if group_answers is not None:
                    total_count += len(group_answers)
                group_answers = None  
            else:
                if group_answers is None:
                    group_answers = set(line)
                else:
                    group_answers = group_answers.intersection(set(line))
                
        if group_answers is not None:
            total_count += len(group_answers)
    return total_count

print(sum())
