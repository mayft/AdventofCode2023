#include <stdio.h>
#include <string.h>

int main() {
    FILE* fd = fopen("input.txt", "r");
    char game[200];
    int id;
    int sum = 0;
    while (fscanf(fd, "%*4s %i%*c %[^\n]", &id, game) != EOF) {
        char *r1 = game;
        int valid = 1;
        char* round = strtok_r(game, ";", &r1);
        while(round) {
            char* r2;
            char* cubes = strtok_r(round, ",", &r2);
            while(cubes) {
                int amt;
                char color;
                sscanf(cubes, " %i %c%*s ", &amt, &color);
                if (color == 'r' && amt > 12) {
                    valid = 0;
                    break;
                }
                else if (color == 'g' && amt > 13) {
                    valid = 0;
                    break;
                }
                else if (color == 'b' && amt > 14) {
                    valid = 0;
                    break;
                }
                cubes = strtok_r(NULL, ",", &r2);
            }
            
            if(!valid) break;
            round = strtok_r(NULL, ";", &r1);
        }
        if (valid) sum += id;
    }
    printf("%i\n", sum);
}