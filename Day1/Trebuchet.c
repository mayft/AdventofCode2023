#include <stdio.h>
#include <string.h>

int check_num(char* buf, int c) {
    if (buf[c] <= '9' && buf[c] >= '0') {
        return buf[c] - 48;
    }
    
    char* numbers[10] = {"zero","one","two","three","four",
    "five","six","seven","eight","nine"};
    
    for (int i = 0; i < 10; i++) {
        if (strncmp(buf+c, numbers[i], strlen(numbers[i])) == 0) {
            return i;
        }
    }
    return 0;
}

int main() {
    FILE* fd = fopen("input.txt", "r");
    char buf[100];
    int sum = 0;
    while(fscanf(fd, "%s", buf) != EOF) {
        if (strlen(buf)>= 100) {
            printf("Buffer too small\n");
            return -1;
        }
        int c = 0;
        int n = 0;
        while (c < strlen(buf)) {
            if ((n = check_num(buf, c)) != 0) {
                sum += n * 10;
                break;
            }
            c++;
        }

        c = strlen(buf);
        while(c >= 0) {
            if ((n = check_num(buf, c)) != 0) {
                sum += n;
                break;
            }
            c--;
        }
    }
    printf("%i\n", sum);
}
