#include <iostream>
#include <cstdio>

using namespace std;

bool judge(int n)
{
	return n == ((n%10)*(n%10)*(n%10) + (n/100)*(n/100)*(n/100) + ((n/10)%10)*((n/10)%10)*((n/10)%10));
}
int main()
{
	for(int i = 100; i <= 999; ++i)
		if(judge(i)) printf("%d\n", i);
	return 0;
}