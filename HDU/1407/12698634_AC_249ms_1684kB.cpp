#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 101;
int main()
{
	int t;
	while(cin >> t && t)
	{
		bool flag = 0;
		for(int i01 = 1; i01 < MAXN; ++i01)
		{
			for(int i02 = i01; i02 < MAXN; ++i02)
			{
				for(int i03 = i02; i03 < MAXN; ++i03)
				{
					if(i01*i01 + i02*i02 + i03*i03 == t)
					{
						 printf("%d %d %d\n", i01, i02, i03);
						 flag = 1;
						 break;
					}
				}
				if(flag) break;
			}
			if(flag) break;
		}
	}
	return 0;
}