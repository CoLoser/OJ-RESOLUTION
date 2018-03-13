#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 50005
using namespace std;

//线段树模板

struct node{
	int l, r;
	int sum;
	int mid(){
		return (l + r)>>1;
	}
};

node tree[maxn*4];
int value[maxn];
char key[10];
int idx, v;
int cnt;

void init_tree(int root, int l, int r){
	tree[root].l = l;
	tree[root].r = r;
	
	if(l == r){
		 tree[root].sum = value[l];
		 return ;
	}
	init_tree(root<<1, l, (l + r)/2);
	init_tree(root<<1|1, (l + r)/2 + 1, r);
	
	tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
}

int query_tree(int root, int l, int r){
	if(l<=tree[root].l&&r>=tree[root].r) 
        return tree[root].sum;
    int mid=tree[root].mid(),ret=0;
    
    if(l<=mid) ret+=query_tree(root<<1,l,r);       
    if(r>mid)  ret+=query_tree(root<<1|1,l,r);
    return ret;
}

void update_tree(int root, int idx, int v){
	if(tree[root].l == tree[root].r){
		tree[root].sum = v;
		return;
	}

	if(idx <= tree[root].mid()) update_tree(root<<1, idx, v);
	else update_tree(root<<1|1, idx, v);

	tree[root].sum = tree[root<<1].sum + tree[root<<1|1].sum;
}


int main(){
	int n, m;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		cnt = 1;
		scanf("%d", &m);
		for(int j = 1; j <= m; ++j) scanf("%d", &value[j]);
		init_tree(1, 1, m);
		
		printf("Case %d:\n", i);
		
		while(scanf("%s", key) != EOF && key[0] != 'E' && cnt <= 40000){
			scanf("%d%d",&idx, &v);
			if(key[0] == 'Q'){
				if(idx > v) swap(idx, v);
				printf("%d\n", query_tree(1, idx, v));
			} 
			else if(key[0] == 'A'){
				 value[idx] += v;
				 update_tree(1, idx, value[idx]);
			}
			else if(key[0] == 'S'){
				value[idx] -= v;
				update_tree(1, idx, value[idx]);
			} 
			cnt ++;
			//cout << tree[1].sum <<endl;
		}
	}
	return 0;
}