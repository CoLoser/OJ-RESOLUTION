#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int SIZE = 1000;
struct S{
	int value;
	bool state;
};
S s[SIZE];
void sort(int n){
	int temp;
	for(int i = 0; i < n; ++i){
		for(int j = i; j < n; ++j){
			if(s[i].value < s[j].value)
				swap(s[i], s[j]);
		}
	}
}
int main(){
	int n;
	while(scanf("%d", &n) == 1 && n != 0){
		int a;
		for(int i = 0; i < n; ++i){
			scanf("%d", &a);
			s[i].value = abs(a);
			if(a < 0){
				s[i].state = false;
			}else{
				s[i].state = true;
			}
		}
		sort(n);
		bool flag = true;
		for(int i = 0; i < n; i++){
			if(flag){
				flag = false;
			}else{
				printf(" ");
			}
			if(s[i].state == false){
				printf("%d", s[i].value * (-1)); 
			}else{
				printf("%d", s[i].value);
			} 
		}
		printf("\n");
	}
	return 0;
}