#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct _Node{
	double j, f;
	double jf;
	_Node(){};
	_Node(double _j, double _f){
		j = _j;
		f = _f;
		jf = _j/_f;
	}
};
bool cmp(_Node n1, _Node n2){
	return n1.jf > n2.jf;
}

_Node arr[1005];
int main()
{
	int m, n;
	
	while(cin >> m >> n && m != -1 && n != -1){
		for(int i = 0; i < n; ++i){
			cin >> arr[i].j >> arr[i].f;
			arr[i].jf = arr[i].j/arr[i].f;
		}
		sort(arr, arr + n, cmp);
		
		double res = 0;
		for(int i = 0; i < n; ++i){
			int t = m - arr[i].f;
			if(t >= 0) res += arr[i].j;
			else {
				res += arr[i].jf*m;
				break;
			}
			m -= arr[i].f;
		}
		printf("%.3f\n", res);
	}
}
