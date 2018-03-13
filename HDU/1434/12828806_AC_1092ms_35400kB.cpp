#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct _Node{
	int rp;
	string name;
	
	bool operator < (const _Node &rhs)const
	{
		if(rhs.rp == rp) return rhs.name > name;
		else return rhs.rp < rp;
	}
};

const int MAXN = 10000;


int main()
{   
	ios::sync_with_stdio(false);
	
	int n, m;
	string strname;
	int irp, no, jno;
	_Node node;
	
	while(cin >> n >> m)
	{
		priority_queue<_Node> pq[MAXN + 1];
		for(int i = 0; i < n; ++i)
		{
			int t;
			cin >> t;
			for(int j = 0; j < t; ++j)
			{
				cin >> strname >> irp;
				node.name  =  strname;
				node.rp = irp;
				pq[i].push(node);
			} 
		}
		
		for(int i = 0; i < m; ++i)
		{
			string option;
			cin >> option;
			
			if(option == "GETOUT"){
				cin >> no;
				cout << pq[no - 1].top().name << endl;;
				pq[no - 1].pop();
				
			}else if(option == "JOIN")
			{
				cin >> no >> jno;
				while(!pq[jno - 1].empty())
				{
					pq[no - 1].push(pq[jno - 1].top());
					pq[jno - 1].pop();
				}
			}else{
				cin >> no >> strname >> irp;
				node.name  =  strname;
				node.rp = irp;
				pq[no - 1].push(node);
			}
		}
	}
	return 0;
 } 