#include <cstdio>
#include <string>
using namespace std;

int main()
{
	int ans = 0;
	int n;
	char key;
	scanf("%d", &n);
	getchar();
	while(n--){
		ans = 0;
		key = getchar();
		while(key != '\n'){
			if(isdigit(key)) ans++;
			key = getchar();
		}
		printf("%d\n", ans);
	}
}