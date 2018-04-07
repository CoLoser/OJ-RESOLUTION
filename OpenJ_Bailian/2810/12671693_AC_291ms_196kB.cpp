#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 100;

int Pow(int _x, int _y)
{
	int ans = 1;
	for(int i = 1; i <= _y; ++i) ans *= _x;
	return ans;
}


int main()
{
	int t;
	while(cin >> t)
	{
		for(int i01 = 2; i01 <= t; ++i01)
			for(int i02 = 2; i02 <= t; ++i02)
				for(int i03 = 2; i03 <= t; ++i03)
					for(int i04 = 2; i04 <= t; ++i04)
						if(Pow(i01, 3) == Pow(i02, 3) + Pow(i03, 3) + Pow(i04, 3) && i02 <= i03 && i03 <= i04)
							printf("Cube = %d, Triple = (%d,%d,%d)\n", i01, i02, i03, i04);
	}
	return 0;
}