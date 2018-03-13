#include <iostream>
#include <cstdio>
#include <cstring>

using  namespace std;

const int MAXN = 1000;
int arr[MAXN];

int main()
{
	int n;
	while(cin >> n)
	{
		int flag = 0;
		for(int i = 0; i < n; ++i) cin >> arr[i];
		int i, j;
		for(i = 'A'; i <= 'Z'; ++i)
		{
			for(j = 0; j < n; ++j)
				if(!isupper(arr[j]^i)) break;
			if(j == n){
				flag = i;
				break;
			} 
		}
		
		for(int i = 0; i < n; ++i)
			cout << (char)(arr[i]^flag);
		cout << "\n";
	}
	return 0;
	
	
	
}