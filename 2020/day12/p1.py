def manhattan_distance(point1, point2):
    return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1])

with open("input.in") as f:
    lines = f.readlines()
    # moves = [line.strip().split() for line in lines]
    moves = [(line[0], int(line[1:])) for line in lines]
    print(moves)
    

x = 0
y = 0
dx = 1  # east
dy = 0

for direction, value in moves:
    if direction == 'N':
        y += value
    elif direction == 'S':
        y -= value
    elif direction == 'E':
        x += value
    elif direction == 'W':
        x -= value
    elif direction == 'L':
        for _ in range(value // 90):
            dx, dy = -dy, dx  
    elif direction == 'R':
        for _ in range(value // 90):
            dx, dy = dy, -dx  
    elif direction == 'F':
        x += dx * value
        y += dy * value

print(manhattan_distance((0, 0), (x, y)))
