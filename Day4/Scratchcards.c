#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE* fd = fopen("input.txt", "r");
    int points = 0;
    char card[200];
    while (fscanf(fd, "%*4c %*i%*c%[^\n] ", card) != EOF) {
        int matches = 0;
        char *list;
        char *numbers = strtok_r(card, "|", &list);
        int winner[30];
        int i = 0;
        char *n;
        char *num = strtok_r(numbers, " ", &n);
        while (num) {
            winner[i] = atoi(num);
            i++;
            if (i >= 30) {
                printf("overflow\n");
                return 1;
            }
            num = strtok_r(NULL, " ", &n);
        }
        numbers = strtok_r(NULL, "|", &list);
        num = strtok_r(numbers, " ", &n);
        while (num) {
            for (int j = 0; j < i; j++) {
                if (atoi(num) == winner[j]) {
                    if (matches) {
                        matches *=2;
                    } 
                    else {
                        matches++;
                    }
                    break;
                }
            }
            num = strtok_r(NULL, " ", &n);
        }
        points += matches;
    }
    printf("%i\n", points);
}