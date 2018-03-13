#include <stdio.h>  
#include <math.h>  
#include <stdlib.h>  
  
char a[32];  
  
double expr(void)  
{  
    scanf("%s", a);  
    if(a[0] == '+')  
        return expr() + expr();  
    else if(a[0] == '-')  
        return expr() - expr();  
    else if(a[0] == '*')  
        return expr() * expr();  
    else if(a[0] == '/')  
        return expr() / expr();  
    else  
        return atof(a);  
}  
  
int main(void)  
{  
    printf("%lf\n", expr());  
  
    return 0;  
}  