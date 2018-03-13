#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

bool cmp(char a,char b)
{
    return a > b;
}

int calc(int v,int w,int x,int y,int z)
{
    return v - w*w + x*x*x - y*y*y*y + z*z*z*z*z;
}

void solve(int target, string& s)
{
    int n = s.length();

    for(int z=0; z<n; z++) {
        for(int y=0; y<n; y++) {
            if(y == z)
                continue;
            for(int x=0; x<n; x++) {
                if(x == z || x == y)
                    continue;
                for(int w=0; w<n; w++) {
                    if(w == z || w == y || w == x)
                        continue;
                    for(int v=0; v<n; v++) {
                        if(v == z || v == y || v == x || v == w)
                            continue;
                        if(calc(s[z]-'A'+1, s[y]-'A'+1, s[x]-'A'+1, s[w]-'A'+1, s[v]-'A'+1) == target) {
                            printf("%c%c%c%c%c\n", s[z], s[y], s[x], s[w], s[v]);
                            return ;
                        }
                    }
                }
            }
        }
    }
    printf("no solution\n");
}

int main()
{
    int target;
    string s;

    while(cin >> target >> s && target) {
        sort(s.begin(), s.end(), cmp);
        solve(target, s);
    }

    return 0;
}