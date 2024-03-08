def manhattan_distance(point1, point2):
    return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1])

    
with open("input.in") as f:
    lines = f.readlines()
    # moves = [line.strip().split() for line in lines]
    moves = [(line[0], int(line[1:])) for line in lines]
    print(moves)
    
ship_x = 0
ship_y = 0
waypoint_x = 10
waypoint_y = 1
for direction, value in moves:
    if direction == 'N':
        waypoint_y += value
    elif direction == 'S':
        waypoint_y -= value
    elif direction == 'E':
        waypoint_x += value
    elif direction == 'W':
        waypoint_x -= value
    elif direction == 'L':
        for _ in range(value // 90):
            waypoint_x, waypoint_y = -waypoint_y, waypoint_x
    elif direction == 'R':
        for _ in range(value // 90):
            waypoint_x, waypoint_y = waypoint_y, -waypoint_x
    elif direction == 'F':
        ship_x += waypoint_x * value
        ship_y += waypoint_y * value
        
print(manhattan_distance((0, 0), (ship_x, ship_y)))
        
        
