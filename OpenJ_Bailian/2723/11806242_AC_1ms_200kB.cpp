#include <iostream>
#include <cstdio>

using namespace std;

const int DAYS = 7;
const int N = 13;

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	int w;
	while(cin >> w)
	{
		for(int i = 0; i < 12; ++i)
		{
			int t = (w - 1 + N) % DAYS;
			if(t == 5) cout << i+1 <<endl;
			w = (w + days[i]) % DAYS;
		}
	}
	return 0;
}