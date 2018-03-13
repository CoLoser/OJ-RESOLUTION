#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 111;
#define ls root<<1
#define rs root<<1|1
struct edge{
	double l, r;
	double h;
	int flag; //矩形的上面还是下面
}edges[maxn<<1];

struct node{
	int l, r; //离散化之后的横坐标
	int cover; //覆盖?
	double len; //矩形的总长度
	int mid()
	{
		return (l + r)>>1;
	}
}tree[maxn<<3];

double xp[maxn<<1];

bool cmpedge(const edge& a, const edge& b){
	return a.h < b.h;
}


void pushup(int root)
{
	if(tree[root].cover){
		tree[root].len = xp[tree[root].r + 1] - xp[tree[root].l];
	}else if(tree[root].l == tree[root].r){ //为一点
		tree[root].len = 0;
	}else{  //处在左右子树,两段相加
		tree[root].len = tree[rs].len + tree[ls].len;
	}
}
void init(int root, int l, int r)
{
	tree[root].l = l;
	tree[root].r = r;
	if(l == r) return;
	int m = tree[root].mid();
	init(root<<1, l, m);
	init(root<<1|1, m + 1, r);
}

void update(int root, int l, int r, int val)
{
	//cout << "val = " << val << " root = " << root << " cover = " << tree[root].cover <<" len = "<< tree[root].len <<endl;
	if(tree[root].l == l && tree[root].r == r)
	{
		tree[root].cover += val;
		pushup(root);
		return;
	}
	
	int m = tree[root].mid();
	
	if(l > m) update(rs, l, r, val);
	else if(r <= m) update(ls, l, r, val);
	else update(ls, l, m, val), update(rs, m+1, r, val);
	pushup(root);
}


int main()
{
	int n, kase = 0;
	
	while(scanf("%d", &n) != EOF && n)
	{
		int idx = 0;
		double x1, x2, y1, y2;
		for(int i = 0; i < n; ++i)
		{
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			edges[idx].l = x1;
			edges[idx+1].l = x1;
			edges[idx].r = x2;
			edges[idx+1].r = x2;
			
			edges[idx].h = y1;
			edges[idx].flag = 1;
			
			edges[idx+1].h = y2;
			edges[idx+1].flag = -1;
			
			xp[idx] = x1;
			xp[idx+1] = x2;
			
			idx += 2;
		}
		
		//离散化处理
		
		sort(edges, edges+idx, cmpedge);
		sort(xp, xp + idx);
		
		int len = unique(xp, xp + idx) - xp; //去重
		
		init(1, 0, len - 1);
		double ans = 0.0;
		
		for(int i = 0; i < idx; ++i)
		{
			int l = lower_bound(xp, xp + len, edges[i].l) - xp;
			int r = lower_bound(xp, xp + len, edges[i].r) - xp - 1;
			//cout << l <<"-" << r <<endl;
			update(1, l, r, edges[i].flag);
			ans += (edges[i+1].h - edges[i].h) * tree[1].len;
		}
		printf("Test case #%d\n", ++kase);
		printf("Total explored area: %.2f\n", ans);
		printf("\n");
	}
	return 0;
}