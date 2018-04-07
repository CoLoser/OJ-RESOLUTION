  
#include <stdio.h>  
#include <string.h>  
  
#define BASE 10  
#define N 200  
  
char a[N+1], b[N+1];  
char ans[N+1];  
  
int main(void)  
{  
    int anslen, carry, len, i, j;  
  
    scanf("%s", a);  
    scanf("%s", b);  
  
    memset(ans, 0, sizeof(ans));  
  
    anslen = len = strlen(a);  
    for(i=len-1, j=0; i>=0; i--)  
        ans[j++] = a[i] - '0';  
    len = strlen(b);  
    if(len > anslen)  
        anslen = len;  
    carry = 0;  
    for(i=len-1, j=0; i>=0; i--,j++) {  
        ans[j] += b[i] - '0' + carry;  
        carry = ans[j] / BASE;  
        ans[j] %= BASE;  
    }  
    while(carry > 0) {  
        ans[j] += carry;  
        carry = ans[j] / BASE;  
        ans[j++] %= BASE;  
    }  
    if(j > anslen)  
        anslen = j;  
  
    /* 去除前导的多个0 */  
    for(i=anslen-1; i>=0; i--)  
        if(ans[i])  
            break;  
    if(i < 0)  
        i = 0;  
  
    /* 输出结果 */  
    for(; i>=0; i--)  
        printf("%d", ans[i]);  
    printf("\n");  
  
    return 0;  
}  