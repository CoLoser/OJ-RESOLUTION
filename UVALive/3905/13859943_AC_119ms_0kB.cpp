#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Event {
	double pos;
	int type;		//1 为右端点, 0为左端点

	bool operator < (const Event rhs) {				//按照时间和左右位置排序, 时间小的在前, 右端点优先
		if(pos == rhs.pos) return type > rhs.type;
		else return pos < rhs.pos;
	}
};
const int MAXN = 100005;
Event event[MAXN*2];
int w, h, n;

void update(int x, int a, int w, double &L, double &R) {
	if(a == 0) {							//不移动
		if(x <= 0 || x >= w) R = L - 1; 	//无解
	} else if(a > 0) {						//向右上移动
		L = max(L, (double)(0 - x)/a);		//在相框内的开始时间   0-x表示进入前相框边界的距离, 除以a为进入的时间 有一点进去即为进去, 取最大值
		R = min(R, (double)(w - x)/a);		//在相框内的结束时间   w-x表示出去前相框边界的距离, 除以a为出去的时间  有一点出来即为出来, 取最小值
	} else {								//向左下移动
		L = max(L, (double)(w - x)/a);		//在相框内的开始时间
		R = min(R, (double)(0 - x)/a);		//在相框内的结束时间
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &w, &h, &n);
		int a, b, x, y, len = 0;
		
		for(int i = 0; i < n; ++i) {
			scanf("%d%d%d%d", &x, &y, &a, &b);
			double L = 0, R = 1e9;
			update(x, a, w, L, R);			//计算横向
			update(y, b, h, L, R); 			//计算纵向

			if(L < R) {
				event[len++] = (Event) {
					L, 0
				};
				event[len++] = (Event) {
					R, 1
				};
			}
		}

		sort(event, event + len);

		//扫描线
		int cnt = 0, ans = 0;
		for(int i = 0; i < len; ++i) {
			if(event[i].type == 0) ans = max(ans, ++cnt);
			else cnt--;
		}
		printf("%d\n", ans);
	}
}