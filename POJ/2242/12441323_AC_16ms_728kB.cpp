#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define L(xa, ya, xb, yb) sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb))
using namespace std;
const double PI = 3.141592653589793;

int main()
{
	double x1, y1, x2, y2, x3, y3;
	double a, b, c, p, r;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
	{
		a = L(x1, y1, x2, y2);
		b = L(x1, y1, x3, y3);
		c = L(x2, y2, x3, y3);
		
		p = (a + b + c)/2;
		
		r = (a*b*c)/(4 * sqrt(p*(p - a)*(p - b)*(p - c)));
		
		printf("%.2f\n", 2*PI*r);
	}
}