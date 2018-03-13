#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 55;
int arr[MAXN], f[MAXN];

bool check(int n)
{
	int t = sqrt(n);
	return t*t == n;
}


int main()
{
	for(int i = 1, j = 0; j < MAXN; ++i)
	{
		int flag = 0;
		for(int k = 1; k <= j && !flag; k++){
			if(check(arr[k] + i)){
				arr[k] = i;
				flag = 1;
			}
		}
		
		if(!flag){
			f[j] = i - 1;
			arr[++j] = i;
		}
	}
	
	int t, n;
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		cout << f[n] <<endl;
	}
	
}
