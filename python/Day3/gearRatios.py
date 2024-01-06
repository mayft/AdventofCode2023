import re

def findpart(prev, cur, next):
    numbers = re.finditer("\d+", cur)
    total = 0
    for n in numbers:
        parts = 0
        if ((cur[n.span()[0]-1] != '.') or (cur[n.span()[1]] != '.')):
            total += int(n.group())
        else :
            for i in range(n.span()[0]-1, n.span()[1]+1):
                if ((not prev[i].isnumeric() and prev[i] != '.')
                or (not next[i].isnumeric() and next[i] != '.')):
                    total += int(n.group())
                    break
    return total


file = open("input.txt", "r", newline='\n')
sum = 0

cur = '.'+file.readline().strip('\n')+'.'
prev = '.' * len(cur)

for line in file:
    next = '.'+line.strip('\n')+'.'
    sum += findpart(prev, cur, next)
    tmp = cur
    prev = tmp
    cur = next
    
next = '.'*len(cur)
sum += findpart(prev, cur, next)
print(sum)
