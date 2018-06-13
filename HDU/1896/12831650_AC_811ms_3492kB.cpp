#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct _Node{
	int pos, dist;
	
	bool operator < (const _Node &rhs) const{
		if(pos == rhs.pos) return dist > rhs.dist;
		else return pos > rhs.pos;
	}
};
int main()
{
	int n, m, p, d, maxdist;
	_Node node;
	
	while(cin >> n)
	{
		while(n--)
		{
			priority_queue<_Node> pq;
			maxdist = 0;
			cin >> m;
			for(int i = 0; i < m; ++i)
			{
				cin >> p >> d;
				node.dist = d;
				node.pos = p;
				pq.push(node);
			}
			
			bool flag = true;
			
			while(!pq.empty())
			{
				node = pq.top();
				pq.pop();
				
				if(flag)
				{
					node.pos += node.dist;
					pq.push(node);
				}
				
				flag = !flag; 
			}
			cout << node.pos << endl;
		}
	}
}