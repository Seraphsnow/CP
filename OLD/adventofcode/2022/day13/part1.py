import ast

def check(list1, list2):

    if(type(list1) == type(1)):
        if(type(list2) == type(1)):
            if(list1 > list2):
                return 0
            elif(list1 < list2):
                return 1
            else:
                return -1
        else:
            return check([list1], list2)
    else:
        if(type(list2) == type(1)):
            return check(list1, [list2])
        else:
            for i in range(min(len(list1), len(list2))):
                elem = check(list1[i], list2[i])
                if(elem == 1):
                    return 1
                elif elem == 0:
                    return 0
                else:
                    continue
            if(len(list1)>len(list2)):
                return 0
            elif(len(list1) < len(list2)):
                return 1
            else:
                return -1

file1 = open("act.txt")
Lines = file1.readlines()
lines = []
for line in Lines:
    if(line != "\n"):
        lines.append(ast.literal_eval(line.split()[0]))

# print(lines)
i = 0
ans = 0
while 2*i < len(lines):
    if check(lines[2*i], lines[2*i+1]) == -1:
        print("error", i)
    ans = ans + check(lines[2*i], lines[2*i+1])*(i+1)
    i = i+1

print(ans)
# print(check([[4,4],4,4],[[4,4],4,4,4]))