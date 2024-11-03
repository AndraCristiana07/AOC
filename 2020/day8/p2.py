def exec(instructions):
    acc = 0
    instr_idx = 0
    executed_instr = set()
    while instr_idx not in executed_instr:
        if instr_idx == len(instructions):
            return acc
        executed_instr.add(instr_idx)
        op, arg = instructions[instr_idx]
        if op == "acc":
            acc += arg
            instr_idx += 1
        elif op == "jmp":
            instr_idx += arg
        elif op == "nop":
            instr_idx += 1
            
    return -1

def fix(instructions):
    for i in range(len(instructions)):
        op, arg = instructions[i]
        if op == "jmp":
            instructions[i] = ("nop", arg)
            acc = exec(instructions)  
            if acc != -1:
                return acc   
            instructions[i] = ("jmp", arg)
        
        elif op == "nop":
            instructions[i] = ("jmp", arg)
            acc = exec(instructions)  
            if acc != -1:
                return acc   
            instructions[i] = ("nop", arg)
        
       
    return -1
            
    
    
    
    
with open("input.in") as f:
    lines = f.readlines()
    code = [line.split() for line in lines]
    
code = [(op, int(arg)) for op, arg in code]

print(fix(code))
