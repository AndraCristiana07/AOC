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

def count_inner_bags(rules, bag_color):
    total_bags = 0
    for count, inner_bag_color in rules[bag_color]:
        total_bags += count + count * count_inner_bags(rules, inner_bag_color)
    return total_bags

    
target_bag = 'shiny gold'
print(count_inner_bags(rules, target_bag))


    



