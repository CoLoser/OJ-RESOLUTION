#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int a,b,r1,r2;
    int t;
    while(scanf("%d",&t) != EOF)
    {
        while(t--)
        {
            int fg=0;
            scanf("%d%d%d%d",&a,&b,&r1,&r2);
            if(2*max(r1,r2) > min(a,b))
                printf("NO\n");
            else
            {
              if((a-r2-r1)*(a-r2-r1)+(b-r2-r1)*(b-r2-r1) >= (r1+r2)*(r1+r2))
                  printf("YES\n");
              else
                  printf("NO\n");
            }
        }
    }
    return 0;
}