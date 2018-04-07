/* Bailian2798 2进制转化为16进制 */  
  
#include <stdio.h>  
#include <string.h>  
  
#define N 10000  
#define N2 4  
char s[N + N2 + 1];  
  
char convert[] = "0123456789ABCDEF";  
  
int main(void)  
{  
    int n, len, digits, i, k;  
  
    scanf("%d", &n);  
    getchar();  
    while(n--) {  
        gets(s + N2);  
  
        s[0] = s[1] = s[2] = s[3] = '0';  
        len = strlen(s + N2);               /* 2进制位数 */  
        digits = (len + N2 - 1) / N2;   /* 16进制位数 */  
        len += N2 - 1;  
        for(i=1, k=len; i<=digits; i++) {  
            s[k--] = convert[(s[len - 3] - '0') * 8 + (s[len - 2] - '0') * 4 + (s[len - 1] - '0') * 2 + (s[len] - '0')];  
            len -= N2;  
        }  
  
        printf("%s\n", &s[k + 1]);  
    }  
  
    return 0;  
}