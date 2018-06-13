#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
	double x1, y1, x2, y2, x3, y3;
	
	int t;
	cin >> t;
	while(t--){
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		
		double area = (y1-y3)*(x3-x2)-(y1-y3)*(pow(x3-x1,3)-pow(x2-x1,3))/(3.0*pow(x3-x1,2))+(y3-y2)*(x3-x2)/2.0;
		printf("%.2f\n", area);
	}
	return 0;
}
