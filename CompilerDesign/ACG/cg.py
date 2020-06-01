code = []
regval=0
def movvariable(value):
    global regval
    st1 = "MOV "+"R" + str(regval) + ","+"="+str(value)
    R1 = regval
    regval = (regval + 1)%13
    code.append(st1)
    st2 = "MOV "+"R" + str(regval) +","+ "[R" + str(R1) + "]"
    code.append(st2)
    R2 = regval
    regval = (regval + 1)%13
    return R1, R2
def movcommand(value):
    global regval
    lcode = "MOV "+"R"+str(regval)+"," + "#" + value
    code.append(lcode)
    R1 = regval
    regval = (regval + 1)%13
    return R1
def brnchcode(relop, l):
    global code
    if(relop == ">"):
        br = "BGT "+l
        code.append(br)
    elif(relop == "<"):
        br = "BLT "+l
        code.append(br)
    elif(relop == ">="):
        br = "BGE "+l
        code.append(br)
    elif(relop == "<="):
        br = "BLE "+l
        code.append(br)
    elif(relop == "=="):
        br = "BEQ "+l
        code.append(br)
    elif(relop == "!="):
        br = "BNE "+l
        code.append(br)
def binop(res, reg1, op, reg2):
    global code
    if(op == "+"):
        binstmt = "ADD "+"R"+str(res)+","+"R"+str(reg1)+",R"+str(reg2)
        code.append(st) 
    elif(op == "-"):
        binstmt = "SUBS "+"R"+str(res)+","+"R"+str(reg1)+",R"+str(reg2)
        code.append(st)           
    elif(op == "*"):
        binstmt = "MUL "+"R"+str(res)+","+"R"+str(reg1)+",R"+str(reg2)
        code.append(st)        
    elif(op == "/"):
        binstmt = "SDIV "+"R"+str(res)+","+"R"+str(reg1)+",R"+str(reg2)
        code.append(st)   
f= open("code.txt", "r")
f1= open("out.txt", "w")
lines = f.readlines()
vardec = []
varlist = []
for i in lines:
	i = i.strip("\n")
        
	if(len(i.split()) == 2):
            if(i.split()[0] == "GOTO"):
                st = "B " + i.split()[1]
                code.append(st)
            else:
                st = i
                code.append(st)
	if(len(i.split()) == 5):
            lhs, ass, arg1, op, arg2 = i.split()
            if(arg1.isdigit() and arg2.isdigit()):
                R1 = movcommand(arg1)
                R2 = movcommand(arg2)
                R3, R4 = movvariable(lhs)
                binop(R4, R1, op, R2)
                st = "STR R"+str(R4) + ", [R" + str(R3) + "]"
                code.append(st)
            elif(arg1.isdigit()):
                R1 = movcommand(arg1)
                R2, R3 = movvariable(arg2)
                R4, R5 = movvariable(lhs)
                binop(R5, R1, op, R3)
                st = "STR R"+str(R5) + ", [R" + str(R4) + "]"
                code.append(st)
            elif(arg2.isdigit()):
                R1,R2 = movvariable(arg1)
                R3 = movcommand(arg2)
                R4, R5 = movvariable(lhs)
                binop(R5, R2, op, R3)
                st = "STR R"+str(R5) + ", [R" + str(R4) + "]"
                code.append(st)                
            else:
                R1,R2 = movvariable(arg1)
                R3,R4 = movvariable(arg2)
                R5,R6 = movvariable(lhs)
                binop(R6, R2, op, R4)
                st = "STR R"+str(R6) + ", [R" + str(R5) + "]"
                code.append(st)   
	if(len(i.split()) == 4 and i.split()[0]!="ARR"):
            
            condition = i.split()[1]
            l = i.split()[3]
            flag = 0
            lhs = ""
            rhs = ""
            operator = [">", "<", ">=", "<=", "=", "!"]
            op = ""
            for j in condition:
                if(j in operator):
                    op = op + j
                    flag = 1
                    continue
                if(j == "="):
                    op = op + j
                    continue
                if(flag == 0):
                    lhs += j
                else:
                    rhs+=j
            
            if(rhs.isdigit() and lhs.isdigit()):
                R1 = movcommand(lhs)
                R2 = movcommand(rhs)
                br = "CMP R"+str(R1)+", "+"R"+str(R2)
                code.append(br)
                brnchcode(op, l)
                
            elif(lhs.isdigit()):
                R1 = movcommand(lhs)
                R2, R3 = movvariable(rhs)
                st4 = "CMP " + "R"+str(R1) + "," + "R" + str(R3)
                code.append(st4)
                brnchcode(op, l)
            elif(rhs.isdigit()):
                R1, R2 = movvariable(lhs)
                R3 = movcommand(rhs)
                st4 = "CMP " + "R"+str(R2) + "," + "R" + str(R3)
                code.append(st4)
                brnchcode(op, l)
            else:
                R1, R2 = movvariable(lhs)
                R3, R4 = movvariable(rhs)
                st4 = "CMP " + "R"+str(R2) + "," + "R" + str(R4)
                code.append(st4)
                brnchcode(op, l)   
	if(len(i.split()) == 3):
            variable = i.split()[0]
            value = i.split()[2]
            variable = str(variable)
            if variable not in varlist:
                varlist.append(variable)
            else:
                R1, R2 = movvariable(variable)
                R3 = movcommand(value)
                st = "STR R"+str(R3)+", [R" + str(R1) + "]"
                code.append(st)
for i in code:
	f1.write(str(i)+"\n")
f.close()
f1.close()
