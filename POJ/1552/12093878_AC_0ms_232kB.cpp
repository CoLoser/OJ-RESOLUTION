#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> vec;
vector<int> vec_t;
int main()
{
	int t, cnt = 0;
	while(scanf("%d", &t) != EOF && t != -1)
	{
		vec.clear();
		vec_t.clear();
		cnt = 0;
		vec.push_back(t);
		while(scanf("%d", &t) != EOF && t) vec.push_back(t);
		for(int i = 0; i < vec.size(); ++i) vec_t.push_back(vec[i]*2);
		for(int i = 0; i < vec_t.size(); ++i)
			for(int j = 0; j < vec.size(); ++j)
				if(vec[j] == vec_t[i]){
					cnt ++;
					break;
				}
		cout << cnt <<endl;
	}
	return 0;
}