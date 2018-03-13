#include <iostream>

using namespace std;
typedef long long ll;

int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << (ll)(n * n)%10000<<endl;
	}
}