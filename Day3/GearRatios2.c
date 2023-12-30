#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int gearratio(int i, char *t, char *m, char *b) {
    int numbers = 0;
    int ratio = 1;
    if (isdigit(m[i-1])) {
        numbers++;
        int num = m[i-1]-48;
        int digit = 1;
        while (isdigit(m[i-1-digit])) {
            num +=  (int)pow(10, digit)*(m[i-1-digit]-48);
            digit ++;
        }
        ratio *= num;
    }
    if (isdigit(m[i+1])) {
        numbers++;
        int num = m[i+1]-48;

        int digit = 2;
        while (isdigit(m[i+digit])) {
            num =  num* 10 + m[i+digit]-48;
            digit++;
        }
        ratio *= num;
    }
    for (int j = i-1; j <= i+1; j++) {
        if (isdigit(t[j])) {
            numbers++;
            if (numbers>2) 
            return 0;
            int num = t[j]-48;

            int digit = 1;
            while (isdigit(t[j-digit])) {
                num +=  (int)pow(10, digit)*(t[j-digit]-48);
                digit ++;
            }

            while (isdigit(t[j+1])) {
                num =  num* 10 + t[j+1]-48;
                j++;
            }
            ratio *= num;
            j++;
        }
    }
    for (int j = i-1; j <= i+1; j++) {
        if (isdigit(b[j])) {
            numbers++;
            if (numbers>2) 
            return 0;
            int num = b[j]-48;

            int digit = 1;
            while (isdigit(b[j-digit])) {
                num +=  (int)pow(10, digit)*(b[j-digit]-48);
                digit ++;
            }

            while (isdigit(b[j+1])) {
                num =  num* 10 + b[j+1]-48;
                j++;
            }
            j++;
            ratio *= num;
        }
    }
    if (numbers!=2) 
    return 0;
    return ratio;
}

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
    while (!end) {
        if (fscanf(fd, "%s", bot+1) == EOF) {
            memset(bot, '.', line+1);
            end = 1;
        }

        int i = 1;
        bot[0] = '.';
        bot[line] = '.';
        while (i < line) {
            if(mid[i] == '*') {
                int g = gearratio(i, top, mid, bot);
                if (g) sum+=g;
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