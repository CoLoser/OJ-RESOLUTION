#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	int t;
	while(cin >> t)
	{
		double n, sum = 0;
		for(int i = 0; i < t; ++i) cin >> n, sum += n;
		printf("%.2f", sum/t);
	 } 
	 return 0;
		
}