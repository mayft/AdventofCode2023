import re

file = open("input.txt", "r")
sum = 0

for line in file:
    game = re.search(r"Game \d+: ([^\n]+)", line)
    cubes = re.split(r"[,;] ", game.group(1))
    r = 0
    g = 0
    b = 0
    for set in cubes:
        c= re.search(r"(\d+) (\S+)", set) 
        if (c):
            if (c.group(2) == "red" and int(c.group(1)) > r):
                r = int(c.group(1))
            elif (c.group(2) == "green" and int(c.group(1)) > g):
                g = int(c.group(1))
            elif (c.group(2) == "blue" and int(c.group(1)) > b):
                b = int(c.group(1))
    sum += r*g*b
    
print(sum)