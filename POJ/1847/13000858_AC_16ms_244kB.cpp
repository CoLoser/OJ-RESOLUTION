#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;

const int maxn = 10005;
const int maxm = 105;
const int oo = 0xfffffff;

struct node
{
    int u, v, len, next;
}e[maxn];

int dis[maxn], head[maxn];
bool use[maxn];

void Add(int u, int v, int len, int k)
{
    e[k].u = u;
    e[k].v = v;
    e[k].len = len;
    e[k].next = head[u];
    head[u] = k;
}
void spfa(int s)
{
    stack<int> sta;
    sta.push(s);

    while(sta.size())
    {
        int i = sta.top();sta.pop();
        use[i] = false;

        for(int j=head[i]; j!=0; j=e[j].next)
        {
            int u = e[j].u, v=e[j].v, len = e[j].len;

            if(dis[u]+len < dis[v])
            {
                dis[v] = dis[u] + len;
                if(use[v] == false)
                {
                    use[v] = true;
                    sta.push(v);
                }
            }
        }
    }
}

int main()
{
    int N, A, B;

    while(scanf("%d%d%d", &N, &A, &B) != EOF)
    {
        int i, j, k=1;

        memset(head, 0, sizeof(head));
        for(i=1; i<=N; i++)
        {
            int M, v;
            dis[i] = oo;
            scanf("%d%d", &M, &v);

            Add(i, v, 0, k++);

            for(j=1; j<M; j++)
            {
                scanf("%d", &v);
                Add(i, v, 1, k++);
            }
        }

        dis[A] = 0;

        spfa(A);

        if(dis[B] == oo)
            printf("-1\n");
        else
            printf("%d\n", dis[B]);
    }

    return 0;
}