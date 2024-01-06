import re

def gearratio(p, c, n, gear):
    start = gear.span()[0]-1
    end = gear.span()[1]
    gearnumbers = 0
    ratio = 1
    if (c[start].isnumeric()):
        ratio *= int(re.search("\d+$", c[:start+1]).group())
        gearnumbers +=1
    if (c[end].isnumeric()):
        ratio *= int(re.search("^\d+", c[end:]).group())
        gearnumbers +=1
    top = re.finditer("\d+", p)
    bottom = re.finditer("\d+", n)
    for num in top:
        if (start<= num.start() <= end or start <= num.end()-1 <= end):
            ratio *=int(num.group())
            gearnumbers+=1
    for num in bottom:
        if (start<= num.start() <= end or start <= num.end()-1 <= end):
            ratio *=int(num.group())
            gearnumbers+=1
    if (gearnumbers == 2): return ratio
    return 0


file = open("input.txt", "r")
sum = 0

cur = '.'+file.readline().strip('\n')+'.'
prev = '.' * len(cur)

for line in file:
    next = '.'+line+'.'
    gears = re.finditer("\*", cur)
    for g in gears:
        sum+= gearratio(prev, cur, next, g)
    tmp = cur
    prev = tmp
    cur = next
next = '.'*len(cur)
gears = re.finditer("\*", cur)
for g in gears:
    sum+= gearratio(prev, cur, next, g)

print(sum)
