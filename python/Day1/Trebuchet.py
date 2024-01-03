
file = open("input.txt", "r")
sum = 0

for line in file:
    for char in line:
        if (char.isdigit()):
            sum += int(char) *10
            break
    for char in reversed(line):
        if (char.isdigit()):
            sum += int(char)
            break
    
print(sum)
    