#include <cstdio>
using namespace std;
int main(){
	int n; 
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; ++i){
		int px, py;
		int ax, ay, bx, by;
		scanf("%d%d", &px, &py);
		scanf("%d%d%d%d", &ax, &ay, &bx, &by);
		int row = bx - ax;
		int col = by - ay;
		if(px < ax || px > bx || py < ay || py >by)
			printf("Outside\n");
		else if(px == ax || px == bx || py == ay || py == by)
			printf("On\n");
		else
			printf("Inside\n");
	}
	}
	
	return 0;
}