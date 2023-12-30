#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char t[200];
    char m[200];
    char b[200];
    char* top = t;
    char* mid = m;
    char* bot = b;
    int sum = 0;

    FILE* fd = fopen("input.txt", "r");
    fscanf(fd, "%s", mid+1);
    mid[0] = '.';
    int line = strlen(mid);
    mid[line]= '.';
    memset(top, '.', line+1);
    int end = 0;
    while(!end) {

        if (fscanf(fd, "%s", bot+1) == EOF) {
            memset(bot, '.', line+1);
            end = 1;
        }

        int i = 1;
        bot[0] = '.';
        bot[line] = '.';
        while (i < line) {
            if (isdigit(mid[i])) {
                int min = i - 1;
                int max = i + 1;
                int num = mid[i] - 48;
                while (isdigit(mid[i+1])) {
                    i++;
                    max++;
                    num = num*10+mid[i]-48;
                }
                int ispart = 0;
                if ((!isdigit(mid[min]) && mid[min] != '.')
                ||(!isdigit(mid[max]) && mid[max] != '.')) {
                    ispart = 1;
                }
                int j = min;
                while (j <= max) {
                    if ((!isdigit(top[j]) && top[j] != '.')
                    ||(!isdigit(bot[j]) && bot[j] != '.')) {
                        ispart = 1;
                        break;
                    }
                    j++;
                }                
                if (ispart) sum += num;
            }
            i++;
        }
        char* tmp = top;
        top = mid;
        mid = bot;
        bot = tmp;
    }
     
    printf("%i\n", sum);
}

