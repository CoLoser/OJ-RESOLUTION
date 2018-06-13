#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t;
	while(cin >> t && t)
	{
		for(int i = 1; i <=t; ++i) printf("%3d", i);
		printf("\n");
		
		for(int i = 0; i < t - 2; ++i)
		{
			printf("%3d", 4*(t - 1) - i);
			
			for(int j = 0; j < t - 2; ++j) printf("   ");
			
			printf("%3d\n", t + 1 + i);
		}
		
		if(t > 1)
		{
			for(int i = 3*t - 2; i >= 2*t - 1; --i) printf("%3d", i);
			printf("\n");
		}
		
	}
}