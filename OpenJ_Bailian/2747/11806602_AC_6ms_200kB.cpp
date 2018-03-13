#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(cin >>n)
    {
    	int MAX = 0;
    	for(int i = 0; i <= n; ++i)
			for(int j = 0; j <= n; ++j)
				for(int k = 0; k <= n; ++k)
					{
						if((i + j)%2 == 0 && (j + k) % 3 == 0 && (i + j + k) % 5 ==0)
							MAX = max(MAX, i + j + k);
                    }
		cout << MAX <<endl;
	}
}