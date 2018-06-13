#include <iostream>
#include <cstdio>
#include <algorithm>


using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1<<15 + 1;
int dp[MAXN], tim[MAXN];	//dp[i]表示第i种状态花费的最小时间
int deadline[16], finish[16];	//截止时间, 完成需要时间
string name[16];	//课程名
int path[MAXN];		//完成路径

void print(int x){
	if(!x) return;
	print(x - (1<<path[x]));
	cout << name[path[x]] << endl;
}
int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; ++i) cin >> name[i] >> deadline[i] >> finish[i];
		
		int bit = 1 << n; //总状态数
		
		for(int i = 1; i <= bit; ++i) {
			dp[i] = INF;
			for(int j = n - 1; j >= 0; --j){
				int tmp = 1<<j;
				
				if(!(tmp&i)) continue; //不能通过j到达状态i
				
				int score = tim[i - tmp] +  finish[j] - deadline[j];
				if(score < 0) score = 0;
				
				if(dp[i] > dp[i-tmp] + score){
					dp[i] = dp[i - tmp] + score;
					tim[i] = tim[i - tmp] + finish[j];
					path[i] = j;
				}
			}
		}
		
		printf("%d\n", dp[bit-1]);
		print(bit-1);
	}	
}