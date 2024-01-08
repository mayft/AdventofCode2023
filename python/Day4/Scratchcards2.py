import re

file = open("input.txt", "r")
sum = 0

queue = [1]
for line in file:
    if (len(queue) == 0):
        queue.append(1)
    card = re.search("(?<=: )[^\n]+", line).group().split(" | ")
    winners = card[0].split()
    numbers = card [1].split()
    matches = 0
    for w in winners:
        for n in numbers:
            if (w ==n):
                matches+=1
                break
    amt = queue.pop(0)
    sum += amt
    for i in range(matches):
        if (i >= len(queue)):
            queue.append(1 + amt)
        else: 
            queue[i] += amt

print(sum)