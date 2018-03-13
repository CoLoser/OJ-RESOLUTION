#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<queue>
#include<stack>
using namespace std;

const int maxn = 20005;
const int BigNum = 10000;

struct node
{
    int op, u, v;
}data[maxn*3];

int f[maxn], val[maxn];
int h[maxn], use[maxn];

int Find(int x)
{
    if(f[x] != x)
        f[x] = Find(f[x]);
    return f[x];
}
void Union(int u, int v)
{
    u = Find(u), v = Find(v);

    if(u != v)
    {
        if(val[u] < val[v])
            f[u] = v;
        else if(val[u] > val[v])
            f[v] = u;
        else if(u < v)
            f[v] = u;
        else
            f[u] = v;
    }
}

int main()
{
    int N, t=0;

    while(scanf("%d", &N) != EOF)
    {
        int i, M, u, v, Q;
        char s[10];

        for(i=0; i<N; i++)
        {
            f[i] = i;
            scanf("%d", &val[i]);
        }

        scanf("%d", &M);

        for(i=0; i<M; i++)
        {
            scanf("%d%d", &u, &v);
            if(u > v)swap(u, v);
            h[i] = u + v*BigNum;
            use[i] = 0;
        }

        sort(h, h+M);

        scanf("%d", &Q);

        for(i=0; i<Q; i++)
        {
            scanf("%s", s);

            if(s[0] == 'd')
            {
                scanf("%d%d", &u, &v);

                if(u > v)swap(u, v);
                data[i].u = u;data[i].v = v;
                data[i].op = 0;
                int k = lower_bound(h, h+M, u+v*BigNum) - h;
                use[k] = 1;
            }
            else
            {
                scanf("%d", &u);
                data[i].op = 1, data[i].u = u;
            }
        }

        for(i=0; i<M; i++)
        {
            u = h[i] % BigNum, v = h[i] / BigNum;
            if(use[i] == 0)
                Union(u, v);
        }

        stack<int>sta;

        for(i=Q-1; i>=0; i--)
        {
            if(data[i].op == 0)
                Union(data[i].u, data[i].v);
            else
            {
                u = Find(data[i].u);

                if(val[u] <= val[data[i].u])
                    sta.push(-1);
                else
                    sta.push(u);
            }
        }

        if(t++)printf("\n");
        while(sta.size())
        {
            printf("%d\n", sta.top());
            sta.pop();
        }
    }

    return 0;
}