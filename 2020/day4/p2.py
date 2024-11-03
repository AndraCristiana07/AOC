import re

def valid_passports():
    required_fields = {
        'byr': lambda x: 1920 <= int(x) <= 2002,
        'iyr': lambda x: 2010 <= int(x) <= 2020,
        'eyr': lambda x: 2020 <= int(x) <= 2030,
        'hgt': lambda x: (x.endswith('cm') and 150 <= int(x[:-2]) <= 193) or (x.endswith('in') and 59 <= int(x[:-2]) <= 76),
        'hcl': lambda x: bool(re.match(r'^#[0-9a-f]{6}$', x)),
        'ecl': lambda x: x in ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth'],
        'pid': lambda x: bool(re.match(r'^[0-9]{9}$', x)),
    }

    valid_passports = 0
    passport = {} 
    with open('input.in') as f:
        for line in f:
            if line == '\n':
                if all(field in passport for field in required_fields):
                    if all(rule(passport[field]) for field, rule in required_fields.items()):
                        valid_passports += 1
                passport = {} 
            else:
                fields = line.split()
                for field in fields:
                    key, value = field.split(":")
                    passport[key] = value

        if all(field in passport for field in required_fields):
            if all(rule(passport[field]) for field, rule in required_fields.items()):
                valid_passports += 1

    return valid_passports

print(valid_passports())
