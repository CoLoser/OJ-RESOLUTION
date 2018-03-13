#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int T,N;
long long n,d;
int a,b,x,y;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        if(N<3){
            printf("IMPOSSIBLE\n");
            continue;
        }
        if(N%2){
            a=N/2;
            printf("%d = %d + %d\n",N,a,a+1);
            continue;
        }
        n=N;
        while(n%2==0){
            n/=2;
        }
        if(n == 1){
            printf("IMPOSSIBLE\n");
            continue;
        }
        y = 3;
		n = 2*N;
        d = sqrt(n*1.0)+5;
        for(y; y <= d; y++){
            if(n%y == 0){
                x = n/y;
                if((x + y) % 2) break;
            }
        }
        if(x < y)swap(x, y);

        b = (x+y-1)/2;
        a = (x-y+1)/2;
        printf("%d = %d",N,a);
        for(int i= a+1; i <= b; i++){
            printf(" + %d", i);
        }
        printf("\n");
    }
    return 0;
}