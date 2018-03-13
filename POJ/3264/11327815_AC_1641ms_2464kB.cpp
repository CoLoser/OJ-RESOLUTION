#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int ans_x;
int ans_y;
const int maxn = 1000010;
struct node{
	int l, r;
	int max_value;
	int min_value;
	int mid(){
		return (l + r) >> 1;
	}
};
node tree[maxn<<2];
int value[maxn];
int n, m;
void init(int root, int l, int r)
{
	tree[root].l = l;
	tree[root].r = r;
	tree[root].max_value = 0;
	tree[root].min_value = maxn;
	if(l == r){
		tree[root].max_value = tree[root].min_value = value[l];
		return ;
	}
	int m = tree[root].mid();
	
	init(root<<1, l, m);
	init(root<<1|1, m + 1, r);
	
	tree[root].max_value = max(tree[root<<1].max_value, tree[root<<1|1].max_value);
	tree[root].min_value = min(tree[root<<1].min_value, tree[root<<1|1].min_value);
}
void query(int root, int l, int r)
{
	if(tree[root].l == l && tree[root].r == r)
	{
		ans_x = max(ans_x, tree[root].max_value);
		ans_y = min(ans_y, tree[root].min_value);
		return;
	}
	
	int m = tree[root].mid();
	if(l > m) query(root<<1|1, l, r);
	else if(r <= m) query(root<<1, l, r);
	else {
		query(root<<1, l, m);
		query(root<<1|1, m+1, r);
	}
}
int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		
		for(int i = 1; i <= n; ++i) scanf("%d", &value[i]);
		init(1, 1 , n);
		int l, r;
		for(int i = 0; i < m; ++i)
		{
			scanf("%d%d", &l, &r);
			ans_x = 0;
			ans_y = maxn;
			query(1, l ,r);
			printf("%d\n", ans_x - ans_y);
		}
	}
	return 0;
}