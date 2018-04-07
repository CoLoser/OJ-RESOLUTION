#include <iostream>
#include <cstdio>

using namespace std;

bool heap_year(int n)
{
	if(n % 4 == 0 && (n % 100 != 0 || n % 400 == 0) && n % 3200 != 0) return true;
	else return false;
}
int main()
{
	int t;
	while(cin >> t) printf("%c\n", heap_year(t) ? 'Y' : 'N');
	return 0;
 } 