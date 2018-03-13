#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a, b;
	bool flag;
	while(cin >> a >> b)
	{
		if(a == 0 && b == 0) break;
		flag = true;
		a *= 100;
		for(int i = 0; i <= 99; ++i)
		{
			if((a + i) % b == 0){
				if(flag)
					printf("%02d", i), flag = false;
				else
					printf(" %02d", i);
			}
		}
		printf("\n");
	}
}