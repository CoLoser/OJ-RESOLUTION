#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

char final[] = {
	11, 12, 13, 14, 15, 16, 17, 1,
	21, 22, 23, 24, 25, 26, 27, 1,
	31, 32, 33, 34, 35, 36, 37, 1,
	41, 42, 43, 44, 45, 46, 47, 1, 0
};

struct _Node{
	char key[40];
	int step;
};

char str[40];

void Move(_Node &now, int val) {  
    for(int i = 0; ; ++i)  
        if(now.key[i] == val) {  
            now.key[i] = 1;  
            return;  
        }  
} 
int bfs(){
	queue<_Node> q;
	_Node cur;
	strcpy(cur.key, str);
	cur.step = 0;
	q.push(cur);
	
	map<string, int> visit;
	int t = 1;
	visit[str] = t++;
	if(visit[final] == visit[str]) return 0;
	visit[final] = t++;
	while(!q.empty()){
		_Node u = q.front();
		q.pop();
		for(int i = 0; i < 32; ++i){
			if(u.key[i] == 1 && u.key[i-1] != 1 && u.key[i-1]%10 != 7){
				_Node tmp = u;
				Move(tmp, tmp.key[i-1] + 1);
				tmp.key[i] = tmp.key[i - 1] + 1;
				++tmp.step;
				if(visit[tmp.key] == visit[final]) return tmp.step;  
                if(visit[tmp.key] == 0) {  
                    visit[tmp.key] = t++;  
                    q.push(tmp);  
                }  
			}
		}
	}
	return -1;
}
int main(){
	int t;
	cin >> t;
	while(t--) {  
		int i, k, j, tmp;
        for(i = k = 0; i < 4; ++i) {  
            str[k++] = (i + 1) * 10 + 1;  
            for(j = 1; j < 8; ++j) {  
                scanf("%d", &tmp);  
                str[k] = tmp;  
                if(str[k] % 10 == 1)   
                    str[k] = 1;  
                ++k;  
            }  
        }  
        printf("%d\n", bfs());  
    }  
    return 0;
}