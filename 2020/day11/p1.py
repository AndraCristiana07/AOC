def get_occupied_seats(row, col, max_row, max_col, seats):
    occupied = 0
    for i in range(max(row - 1, 0), min(row + 2, max_row)):
        for j in range(max(col - 1, 0), min(col + 2, max_col)):
            if i == row and j == col:
                continue
            if seats[i][j] == '#':
                occupied += 1
    return occupied


    
# def get_occupied_seats(seats):
#     occupied = 0
#     num_rows = len(seats)
#     num_cols = len(seats[0]) 
#     for row, col in seats:
#         if col >= num_cols or row >= num_rows:
#             continue
#         if seats[row][col] == '#':
#             occupied += 1
#     return occupied

    
def get_next_state(seats):
    new_seats = []
    num_rows = len(seats)
    num_cols = len(seats[0])
    for row in range(num_rows):
        new_row = []
        for col in range(num_cols):
            if seats[row][col] == '.':
                new_row.append('.')
                continue
            occupied = get_occupied_seats(row, col, num_rows, num_cols, seats)
            if seats[row][col] == 'L' and occupied == 0:
                new_row.append('#')
            elif seats[row][col] == '#' and occupied >= 4:
                new_row.append('L')
            else:
                new_row.append(seats[row][col])
        new_seats.append(new_row)
    print(new_seats)
    print('\n')
    return new_seats

    
with open('input.in', 'r') as f:
    seats = [list(line.strip()) for line in f]
while True:
    new_seats = get_next_state(seats)
    if new_seats == seats:
        break
    seats = new_seats
occupied = 0
for row in seats:
    occupied += row.count('#')
print(occupied)
