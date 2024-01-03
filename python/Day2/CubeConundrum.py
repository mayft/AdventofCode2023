import re

file = open("input.txt")
sum = 0

for line in file:
    game = re.search(r"Game (?P<id>\d+): (?P<games>[^\n]+)", line)
    possible = True
    rounds = re.split(r";", game.group("games"))
    for round in rounds:
        red = re.search(r"\d+(?= red)", round)
        if (not(not red or int(red.group()) <= 12)):
            possible = False
            break
        green = re.search(r"\d+(?= green)", round)
        if (not(not green or int(green.group()) <= 13)):
            possible = False
            break
        blue = re.search(r"\d+(?= blue)", round)
        if (not(not blue or int(blue.group()) <= 14)):
            possible = False
            break
    if (possible):
        sum += int(game.group("id"))
        
print(sum)