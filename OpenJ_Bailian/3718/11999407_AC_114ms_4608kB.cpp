#include <iostream>
#include <cstdio>

using namespace std;

const int SIZE = 16;

int main()
{
	int t;
	unsigned short int a, b, a1, a2;
	cin >> t;
	while(t--)
	{
		scanf("%hd%hd", &a, &b);
		bool flag = false;
		if(a == b) flag = true;
		else{

			for(int i = 1; i < SIZE; ++i)
			{
				a1 = a << i;
				a2 = a >> (SIZE - i);

				if((a1 | a2) == b)
					flag = true;
			}
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}