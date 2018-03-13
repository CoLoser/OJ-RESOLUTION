#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	while(n--){
		double a, b, c;
		scanf("%lf%lf%lf", &a, &b, &c);
		double x = a + b;
		double y = b + c;
		double z = a + c;
		if(x > c && y > a && z > b){
			cout << "YES" <<endl;
		} else{
			cout <<"NO" <<endl;
		}		
	}
	return 0;	
}