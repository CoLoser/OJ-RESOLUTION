#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define N 256
char s[N];
int count[N];

int main(void)
{
    int n, k, len, i, flag;

    scanf("%d", &n);
    getchar();
    while(n--) {
        gets(s);

        len = strlen(s) - 1;
        while(isdigit(s[len]))
            len--;
        k = atoi(&s[len + 1]);
        s[len] = '\0';

        memset(count, 0, sizeof(count));
        i = 0;
        while(s[i]) {
            count[(unsigned int) s[i]]++;
            i++;
        }

        flag = 0;
        for(i=1; i<N; i++) {
            if(count[i] == k) {
                if(flag)
                    printf(",");
                flag = 1;
                printf("'%c'", (char)i);
            }
        }
        printf("\n");
    }

    return 0;
}