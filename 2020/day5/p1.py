
def decode_seat(boarding_pass):
    row_lower = 0
    row_upper = 127
    col_lower = 0
    col_upper = 7
    for char in boarding_pass:
        if char == 'F':
           row_upper = (row_lower + row_upper) // 2
        elif char == 'B':
            row_lower = (row_lower + row_upper) // 2 + 1
        if char == 'L':
            col_upper = (col_lower + col_upper) // 2
        elif char == 'R':
            col_lower = (col_lower + col_upper) // 2 + 1
    print(row_lower, col_lower)
    return row_lower * 8 + col_lower
        

def highest_seat_id_from_file():
    highest_id = 0
    with open('input.in') as f:
        for line in f:
            boarding_pass = line.strip()
            seat_id = decode_seat(boarding_pass)
            if seat_id > highest_id:
                highest_id = seat_id
    return highest_id

print(highest_seat_id_from_file()) 
