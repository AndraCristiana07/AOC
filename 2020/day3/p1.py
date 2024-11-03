
def count_trees():
    with open("input.in") as f:
        lines = f.readlines()
        terrain = [line.strip() for line in lines]
    
        trees = 0
        x = 0
        for line in terrain:
            if line[x] == "#":
                trees += 1
            x = (x + 3) % len(line)
            
        
        return trees
    
print(count_trees())

        
    
