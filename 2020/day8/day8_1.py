def exec(instructions):
    acc = 0
    instr_idx = 0
    executed_instr = set()
    while instr_idx not in executed_instr:
        executed_instr.add(instr_idx)
        op, arg = instructions[instr_idx]
        if op == "acc":
            acc += arg
            instr_idx += 1
        elif op == "jmp":
            instr_idx += arg
        elif op == "nop":
            instr_idx += 1
            
    return acc
        
with open("input.in") as f:
    lines = f.readlines()
    code = [line.split() for line in lines]
    
code = [(op, int(arg)) for op, arg in code]

print(exec(code))

    
    
    
        