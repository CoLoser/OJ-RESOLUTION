#include <iostream>
#include <cstring>
//拓展欧几里得
using namespace std;
typedef long long ll;
void extgcd(ll a, ll b, ll &x, ll &y, ll &d){
	if(!b){
		x = 1;
		y = 0;
		d = a;
	}else{
		extgcd(b, a%b, y, x, d);
		y -= x*(a/b);
	}
}
int main(){
	ll a, b, x, y, d;
	while(scanf("%lld%lld", &a, &b) != EOF && a > 0 && b > 0){
		extgcd(a, b, x, y, d);
		if(d == 1){
			 if( x < 0 )
                x += b ;
             cout << x << " " << ( 1 - a * x ) / b << endl ;
		}
		else printf("sorry\n");
	}
	return 0;
}