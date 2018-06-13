#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;


//找到下一个的n位 
int buf[100];
int next(int n, int k){
	if(!k) return 0;
	
	long long k2 = (long long)k * k;
	int L = 0;
	while(k2){
		buf[L++] = k2%10;
		k2/=10;
	}
	if(n > L) n = L;
	int ans = 0;
	for(int i = 0; i < n; ++i) ans = ans*10 + buf[--L];	//取后n位 
	return ans; 
}

int main(){
	int t, n, k;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		
		//floyd判圈算法
		
		int ans = k;
		int k1 = k, k2 = k;
		
		do{
			k1 = next(n, k1);			//小孩1 
			k2 = next(n, k2); if(k2 > ans) ans = k2;	//小孩2 第一步 
			k2 = next(n, k2); if(k2 > ans) ans = k2;	//小孩2 第二步 
			//cout << k1 << "   " << k2 << endl;
		} while(k1 != k2);
		printf("%d\n", ans);
	}
} 