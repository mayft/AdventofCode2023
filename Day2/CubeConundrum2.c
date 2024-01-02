#include <stdio.h>
#include <string.h>

 int main() {
    FILE* fd = fopen("input.txt", "r");
    char game[200];
    int sum = 0;
    while (fscanf(fd, "%*4s %*i%*c %[^\n]", game) != EOF) {
        int r = 0;
        int g = 0;
        int b = 0;
        char* cubes = strtok(game, ";,");
        while(cubes) {
            int amt;
            char color;
            sscanf(cubes, " %i %c%*s ", &amt, &color);
            if (color == 'r' && amt > r) {
                r = amt;
            }
            else if (color == 'g' && amt > g) {
                g = amt;
            }
            else if (color == 'b' && amt > b) {
                b = amt;
            }
            cubes = strtok(NULL, ";,");
        }
        sum += r*g*b;
    }
    printf("%i\n", sum);
 }