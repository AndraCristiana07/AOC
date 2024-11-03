def calculate_seat_id(boarding_pass):
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
    # print(row_lower, col_lower)
    return row_lower * 8 + col_lower

def find_missing_seat():
    seat_ids = set()
    with open('input.in') as f:
        for line in f:
            boarding_pass = line.strip()
            seat_ids.add(calculate_seat_id(boarding_pass))
        print(sorted(seat_ids))
    for seat_id in range(min(seat_ids), max(seat_ids)):
        if seat_id not in seat_ids :
            return seat_id


print(find_missing_seat()) 
