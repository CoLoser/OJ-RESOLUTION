#include <iostream>
using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		int ans = 0;
		while(n != 1){
			if(n % 2){
				n = (3 * n + 1) / 2; 
			} else{
				n /= 2;
			}
			ans ++;
		}
		cout << ans <<endl;
	}
	return 0;
}