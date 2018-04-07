#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	if(a % 2 == 1 && b % 2 == 0) return 1;
	else if(a % 2 == 0 && b % 2 == 1) return 0;
	else return a < b;
}

const int MAXN = 10;
int arr[MAXN];

int main()
{
	for(int i = 0; i < MAXN; ++i) cin >> arr[i];
	sort(arr, arr + MAXN, cmp);
	for(int i = 0; i < MAXN; ++i) printf("%d%c", arr[i], i == MAXN - 1 ? '\n' : ' ');	
} 