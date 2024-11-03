def count_trees(right, down):
    with open("input.in") as f:
        lines = f.readlines()
        terrain = [line.strip() for line in lines]
    
    trees = 0
    x = 0
    y = 0
    while y < len(terrain):
        if terrain[y][x] == "#":
            trees += 1
        x = (x + right) % len(terrain[0])
        y += down
        
    
    return trees
     
       
slopes = [
        (1, 1),
        (3, 1),
        (5, 1),
        (7, 1),
        (1, 2)
    ]
    
trees_encounteerd = []
for right, down in slopes:
    trees_encounteerd += [count_trees(right, down)]
prod = 1
for tree in trees_encounteerd:
    prod *= tree
    
    


print(prod)

        
    
