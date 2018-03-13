#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

const int MAXN = 10;
stack<int> sta;

char Order01[MAXN];
char Order02[MAXN];

int main()
{
	int t;
	int Ans[100];
	
	while(cin >> t)
	{
		cin >> Order01 >> Order02;
		
		sta.push(Order01[0]);
		
		int i = 0, j = 0, k = 1;
		Ans[0] = 1;
		
		while(i < t && j < t)
		{
			
			if(!sta.empty() && sta.top() == Order02[j])
			{
				sta.pop();
				Ans[k++] = 0;
				j++;
			}else{
				if(i == t) break;
				sta.push(Order01[++i]);
				Ans[k++] = 1;
				
			}
		}
		
		if(i == t) cout << "No." <<endl;
		else{
			cout << "Yes." <<endl;
			
			for(int i = 0; i < k; ++i)
			{
				printf("%s\n", Ans[i] ? "in" : "out");
			}
		} 
		cout << "FINISH" <<endl;
	}
	return 0;
}