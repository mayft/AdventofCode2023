#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fd = fopen("sample_input.txt", "r");
    char buffer[300];
    fscanf(fd, "%8*s %[^\n]", buffer);
    if (strlen(buffer) >= 300) {
        printf("buffer is too small\n");
        return -1;
    }
    int seeds = 1;
    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] == ' ') {
            seeds++;
        }
    }
    int seed[seeds];
    

}