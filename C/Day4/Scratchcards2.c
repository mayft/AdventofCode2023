#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cards {
    int count;
    struct cards *next;
};

int getmatches(char* card) {
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
        if (i >= 30){
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
                matches++;
                break;
            }
        }
        num = strtok_r(NULL, " ", &n);
    }
    return matches;
}

int main() {
    FILE* fd = fopen("input.txt", "r");
    int total_cards = 0;
    char card[200];
    struct cards *cur = (struct cards*)malloc(sizeof(struct cards));
    cur->count = 1;
    cur->next = NULL;
    while (fscanf(fd, "%*4c %*i%*c%[^\n] ", card) != EOF) {
        total_cards += cur->count;
        int matches = getmatches(card);
        struct cards *ptr = cur;
        for (int i = 0; i < matches; i++) {
            if (ptr->next) {
                ptr->next->count += cur->count;
                ptr = ptr->next;
            }
            else {
                ptr->next = (struct cards*)malloc(sizeof(struct cards));
                ptr->next->count = 1 + cur->count;
                ptr = ptr->next;
                ptr->next = NULL;
            }
        }
        struct cards *tmp = cur;
        if (!cur->next) {
            cur->next = (struct cards*)malloc(sizeof(struct cards));
            cur->next->count = 1;
            cur->next->next = NULL;
        }
        cur = cur->next;
        free(tmp);
    }
    printf("%i\n", total_cards);
}