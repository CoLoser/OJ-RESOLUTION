#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;
int r, x, y;
void bitSet1(int t){
	r |= (1<<(t));
}
void bitSet0(int t){
	r &= (~(1<<(t)));
}
int main(){
	
	while(scanf("%x,%d,%d", &r, &x, &y) != EOF){
		bitSet0(x);
		bitSet0(y-2);
		bitSet1(y-1);
		bitSet1(y);
		printf("%x\n", r);
	}
	return 0;
}