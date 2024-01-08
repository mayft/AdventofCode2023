import re

file = open("input.txt", "r")
sum = 0

for line in file:
    card = re.search("(?<=: )[^\n]+", line).group().split(" | ")
    winners = card[0].split()
    numbers = card[1].split()
    matches = 0
    for w in winners:
        for n in numbers:
            if (w == n):
                if (matches == 0):
                    matches = 1
                else:
                    matches *= 2
                break
    sum += matches
print(sum)