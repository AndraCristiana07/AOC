def parse_rule(rule):
    bag, contents = rule.split(" bags contain ")
    contents_list = []
    if contents != "no other bags.":
        contents = contents.split(", ")
        for content in contents:
            quantity, color = content.split(" ", 1)
            color = color.replace(" bags", "").replace(" bag", "").replace(".", "")
            contents_list.append((int(quantity), color))
            
            
            
    return bag, contents_list

def parse_input_from_file(filename):
    rules = {}
    with open(filename, 'r') as f:
        lines = f.readlines()
        for line in lines:
            if line.strip():
                bag, contents_list = parse_rule(line.strip())
                rules[bag] = contents_list
    return rules

rules = parse_input_from_file("input.in")
print(rules)

def find_bag(rules, bag, containing_bags):
    for containing_bag, contents in rules.items():
        for quantity, color in contents:
            if color == bag:
                containing_bags.add(containing_bag)
                find_bag(rules, containing_bag, containing_bags)

def count_shiny_gold(rules, target_bag):
    containing_bags = set()
    find_bag(rules, target_bag, containing_bags)
    return len(containing_bags)
    
target_bag = 'shiny gold'
print(count_shiny_gold(rules, target_bag))


    



