#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
int n;  
        long long a[55] = {0,3,6,6};  
        for(int i = 4;i < 55; i++){  
                a[i] = a[i-1] + 2*a[i-2];  
        }  
        while(scanf("%d", &n) != EOF){  
                printf("%I64d\n", a[n]);  
        }  
        return 0; 
}
