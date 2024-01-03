
file = open("input.txt", "r")
sum = 0
numbers = {"one": 1, "two": 2, "three": 3, "four": 4, "five": 5,
            "six": 6, "seven": 7, "eight": 8, "nine": 9}

for line in file:
    findex = -1
    first = 0
    lindex = -1
    last = 0
    for n in numbers.keys():
        f = line.find(n)
        l = line.rfind(n)
        if (f >= 0 and (findex < 0 or f < findex)):
            first = numbers.get(n)
            findex = f
        if (l >= 0 and l > lindex):
            last = numbers.get(n)
            lindex = l

    for i, char in enumerate(line):
        if (char.isdigit() and (i < findex or findex == -1)):
            first = int(char)
            break

    for i, char in enumerate(reversed(line)):
        if (char.isdigit() and len(line)-1-i > lindex):
            last = int(char)
            break
    sum += first * 10 + last

print(sum)