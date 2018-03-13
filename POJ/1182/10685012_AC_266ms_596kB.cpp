#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int SIZE = 50010;
struct node{
	int parent;
	int relation; //与父类的关系三种 分别为0同类 1被根节点吃 2吃根节点 
};
node p[SIZE];
int find(int x){
	int temp;
	if(x == p[x].parent) return x;
	temp = p[x].parent;
	p[x].parent = find(temp);
	p[x].relation = (p[x].relation + p[temp].relation) % 3;
	return p[x].parent; 
}
int main()
{
	int n, k;
	int d, a, b;
	int root1, root2;
	int ans = 0;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i) //初始化
	{
		p[i].parent = i;
		p[i].relation = 0;
	}
	for(int i = 1; i <= k; ++i)
	{
		scanf("%d%d%d", &d, &a, &b);
		if(a > n || b > n) //条件2
		{
			ans++;
			continue;
		}
		if(d == 2 && a == b) //条件3
		{
			ans++;
			continue;
		}
		root1 = find(a);
		root2 = find(b);
		if(root1 != root2) // 合并
		{
			p[root2].parent = root1;
			p[root2].relation = (3 + (d - 1) +p[a].relation - p[b].relation) % 3;
		}
		else
		{
			if(d == 1 && p[a].relation != p[b].relation)
			{
				ans++;
				continue;
			}
			if(d == 2 && ((3 - p[a].relation + p[b].relation) % 3 != d - 1))
			{
				ans++;
				continue;}
		}
	}
	printf("%d\n", ans);
	return 0;
}
