#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char magic[60];
int cube[6][9] = {
	{4,0,1,2,3,5,6,7,8},{22,9,10,11,21,23,33,34,35},{25,12,13,14,24,26,36,37,38},
	{28,15,16,17,27,29,39,40,41},{31,18,19,20,30,32,42,43,44},{49,45,46,47,48,50,51,52,53}
};
const int rot[12][20]= {
	{11,23,35,34,33,21, 9,10,51,48,45,36,24,12, 6, 3, 0,20,32,44},
	{ 9,10,11,23,35,34,33,21,36,24,12, 6, 3, 0,20,32,44,51,48,45},
	{14,13,26,38,37,36,24,12,45,46,47,39,27,15, 8, 7, 6,11,23,35},
	{12,24,13,14,26,38,37,36,39,27,15, 8, 7, 6,11,23,35,45,46,47},
	{17,29,41,40,39,27,15,16,47,50,53,42,30,18, 2, 5, 8,14,26,38},
	{15,16,17,29,41,40,39,27,42,30,18, 2, 5, 8,14,26,38,47,50,53},
	{18,19,20,32,44,43,42,30,53,52,51,33,21, 9, 0, 1, 2,17,29,41},
	{42,30,18,19,20,32,44,43,33,21, 9, 0, 1, 2,17,29,41,53,52,51},
	{ 0, 1, 2, 5, 8, 7, 6, 3,12,13,14,15,16,17,18,19,20, 9,10,11},
	{ 6, 3, 0, 1, 2, 5, 8, 7,15,16,17,18,19,20, 9,10,11,12,13,14},
	{45,46,47,50,53,52,51,48,44,43,42,41,40,39,38,37,36,35,34,33},
	{51,48,45,46,47,50,53,52,41,40,39,38,37,36,35,34,33,44,43,42}
};
int ans[2][10];
int lim;

bool check() {
	for(int i = 0; i < 6; ++i) {
		for(int j = 0; j < 8; ++j) {
			if(magic[cube[i][j]] != magic[cube[i][j+1]]) return false;
		}

	}
	return true;
}


void rotate(int flag) {
	int h = flag % 2 == 0 ? flag + 1 : flag - 1;
	char tmp[60];
	memcpy(tmp, magic, sizeof(magic));

	for(int i = 0; i < 20; ++i) {
		magic[rot[flag][i]] = tmp[rot[h][i]];
	}
}

int dfs(int cnt) {
	if(cnt >= lim) return check();
	char pre[60];
	memcpy(pre, magic, sizeof(magic));

	for(int i = 0; i < 12; ++i) {
		rotate(i);
		ans[0][cnt] = i/2;				//面
		ans[1][cnt] = (i%2 ? -1 : 1);   //方向
		if(dfs(cnt + 1)) return 1;
		memcpy(magic, pre, sizeof(pre));
	}
}
int main() {
	int t;
	char key[60];
	int kase = 0;
	cin >> t;
	while(t--) {
		if(kase++)getchar();
		for(int i = 0; i < 54; ++i) {
			while(1) {
				char x = getchar();
				if(isalpha(x)) {
					magic[i] = x;
					break;
				}
			}
		}

		for(lim = 0; lim <= 6; ++lim) {
			if(lim == 6) printf("-1\n");
			else if(dfs(0)) {
				printf("%d\n", lim);
				for(int i = 0; i < lim; ++i)
					printf("%d %d\n", ans[0][i], ans[1][i]);
				break;
			}
		}
	}
	return 0;
}