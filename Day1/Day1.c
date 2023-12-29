#include <stdio.h>
#include <string.h>

int main(void) {
    FILE* fd = fopen("input1.txt", "r");
    int sum = 0;
    int i = 0;
    char buf [100];
    while(fscanf(fd, "%s", buf) != EOF) {
        int c = 0;
        while (buf[c] != '\n') {
            if (buf[c] <= '9' && buf[c] >= '0') {
                sum += (buf[c] - 48) * 10;
                break;
            }
            c++;
        }
        c = strlen(buf);
        while (c >= 0) {
            if (buf[c] <= '9' && buf[c] >= '0') {
                sum += buf[c]- 48;
                break;
            }    
            c--;
        }
    }
    
    printf("%i\n", sum);
    return 0;
}