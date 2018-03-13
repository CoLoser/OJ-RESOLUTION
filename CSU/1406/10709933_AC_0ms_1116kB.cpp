#include <cstdio>
using namespace std;
int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		while(n--){
			double a, b;
			scanf("%lf%lf", &a, &b);
			double BMI = a/(b*b);
			if(BMI<18.5) printf("Underweight\n");
			else if(BMI>=23.0) printf("Overweight\n");
			else printf("Normal\n");
			BMI = 0.0;
		}
	}
	return 0;
}