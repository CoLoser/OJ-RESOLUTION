#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

struct _Node{
	int first, second;
	bool operator < (const _Node& rhs) const
	{
		if(first == rhs.first) return second > rhs.second;
		else return first < rhs.first;
	}
	_Node(int f, int s){
		first = f;
		second = s;
	}
};


int main()
{
	int t, a, b;
	char key[10];
	int cnt;
	while(cin >> t)
	{
		cnt = 0;
		
		priority_queue< _Node > pq[4];
		for(int i = 0; i < t; ++i)
		{
			cin >> key;
			if(key[0] == 'I'){
				cin >> a >> b;
				cnt ++;
				pq[a].push(_Node(b, cnt));
			}else{
				cin >> a;
				if(pq[a].empty()) cout << "EMPTY" <<endl;
				else cout << pq[a].top().second <<endl, pq[a].pop();
			}
		}	
	}
	return 0;	
}