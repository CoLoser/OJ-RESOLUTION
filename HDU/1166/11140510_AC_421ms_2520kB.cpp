#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<vector>
#include<fstream>
#include<list>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s,0,sizeof(s))

const double PI = 3.141592653589;
const int INF = 0x3fffffff;

long long c[100010];
int n;

inline int lowbit(int x) {
    return x & -x;
}

void update(int idx, int v) {
    while (idx <= n) {
        c[idx] += v;
        idx += lowbit(idx);
    }
}

long long query(int x) {// The sum of 1 to x
    long long ans = 0;
    while(x > 0) {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    //        freopen("/Users/really/Documents/code/input","r",stdin);
    //    freopen("/Users/really/Documents/code/output","w",stdout);
        ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int k = 1; k <= t; k++) {
        ms(c);
        cout << "Case " << k << ":" << endl;
        cin >> n;
        int a;
        for(int i = 1; i <= n; i++) {
            cin >> a;
            update(i, a);
        }
        string s;
        int l, r;
        while(cin >> s) {
            if(s == "End")
                break;
            else if(s == "Query") {
                cin >> l >> r;
                cout << query(r) - query(l-1) << endl;
            }
            else if(s == "Add") {
                cin >> l >> r;
                update(l, r);
            }
            else if(s == "Sub") {
                cin >> l >> r;
                update(l, -r);
            }
        }
    }

    return 0;
}