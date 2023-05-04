import ast
import functools

def check(list1, list2):

    if(type(list1) == type(1)):
        if(type(list2) == type(1)):
            if(list1 > list2):
                return -1
            elif(list1 < list2):
                return 1
            else:
                return 0
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
                elif elem == -1:
                    return -1
                else:
                    continue
            if(len(list1)>len(list2)):
                return -1
            elif(len(list1) < len(list2)):
                return 1
            else:
                return 0

file1 = open("act.txt")
Lines = file1.readlines()
lines = []
for line in Lines:
    if(line != "\n"):
        lines.append(ast.literal_eval(line.split()[0]))


lines.append([[2]])
lines.append([[6]])
lines = sorted(lines, key=functools.cmp_to_key(check), reverse=True)

for i in range(len(lines)):
    if(lines[i] == [[2]] or lines[i] == [[6]]):
        print(i+1)

# print(check([[4,4],4,4],[[4,4],4,4,4]))   