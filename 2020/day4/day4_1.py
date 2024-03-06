def valid_passports():
    required_fields = ['byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid']
    valid_passports = 0
    with open('input.in') as f:
        passport = {}
        for line in f:
            if line == '\n':
                if all(field in passport for field in required_fields):
                    valid_passports += 1
                passport = {}
            else:
                fields = line.split()
                # print(fields)
                for field in fields:
                    # print(field)
                    key, value = field.split(":")
                    passport[key] = value
                    
        if all(field in passport for field in required_fields):
            valid_passports += 1
                
    return valid_passports
    
print(valid_passports())
                
                
                
        
    