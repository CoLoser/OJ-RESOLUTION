#include <iostream>  
#include <stdio.h>  
#include <string.h>  
using namespace std;  
   
int main()  
{  
    int n;  
    char s[99],str[99];  
    cin>>n;  
    memset(str,0,sizeof(str));  
    for(int i=1;i<=n+n-1;i++)  
    {  
        scanf("%s",s);  
        int len=strlen(s);  
        for(int j=0;j<len;j++) 
		{
			str[j]=s[j]^str[j]; 
		}           
    }  
    cout<<str<<endl;  
    return 0;  
}  