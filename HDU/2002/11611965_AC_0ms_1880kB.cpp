#include <iostream>
#include <cstdio>
#include <cmath>
#define PI 3.1415927
#define V(r) 4.0*PI*r*r*r/3

using namespace std;

int main()
{
	double r;
	while(scanf("%lf", &r) != EOF)
		printf("%.3f\n", V(r));
	return 0;
}