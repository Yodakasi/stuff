import sys

def init_vars(code):
    variable_quntity = 0
    tmp = 0
    for letter in code:
        if letter == ">":
            tmp = tmp + 1
        if letter == "<":
            tmp = tmp - 1
        if tmp > variable_quntity:
            variable_quntity = tmp
    return variable_quntity

def loop_end(code, i):
    nested_loops = 0
    while i < len(code):
        if code[i] == '[':
            nested_loops = nested_loops + 1
        elif code[i] == ']' and nested_loops == 0:
            return i + 1
        elif code[i] == ']' and nested_loops > 0:
            nested_loops = nested_loops - 1
        elif code[i] == ']' and nested_loops < 0:
            print nested_loops
            print "Parse error"
            sys.exit()
        i = i + 1
    return 0

def main():
    if len(sys.argv) < 2:
        print "Usage python interpreter.py <name of brainfuck script>"
    f = open(sys.argv[1], "r")
    code = f.read()
    var_count = init_vars(code)
    variables = [0]
    i = 0
    pc = 0
    loop_start = [0]
    while pc < len(code):
        if code[pc] == '[' and variables[i]:
            loop_start.append(pc + 1)
        elif code[pc] == '[' and not variables[i]:
            pc = loop_end(code, pc + 1)
            continue
        elif code[pc] == ']':
            if variables[i]:
                pc = loop_start[-1]
                continue
            else:
                loop_start.pop()
        elif code[pc] == '>':
            i = i + 1
            if len(variables) < i + 1:
                variables.append(0)
        elif code[pc] == '<':
            i = i - 1
        elif code[pc] == '+':
            variables[i] = variables[i] + 1
        elif code[pc] == '-':
            variables[i] = variables[i] - 1
        elif code[pc] == '.':
            sys.stdout.write(chr(variables[i]))
        elif code[pc] == ',':
            variables[i] = ord(sys.stdin.read(1))
        pc = pc + 1

if __name__ == '__main__':
    main()