#include <iostream>
#include <string.h>
using namespace std;
struct Number{
	int arr[5];
	void cal(int num){
		int sum=1;
		for(int i = 0; i < 5; ++i){
			arr[i]=(num/sum)%10;
			sum*=10;
		}
	}
};
int main(){
	//abcde/fghij=n;
	int n,m,ans,x,count[10];
	bool flag=true;
	while(scanf("%d", &n) != EOF&&n != 0){
		x=0;
		if(flag){
			flag=false;
		}else{
			cout<<endl;
		}
		for(int i = 1234; i < 98765; i++){
		ans = i*n;
		Number nu[2];
		memset(count,0,sizeof(count));
		nu[0].cal(i);
		nu[1].cal(ans);
		if(ans > 98765) break;		
		for(int j = 0; j < 5; ++j){
			count[nu[0].arr[j]]++;
			count[nu[1].arr[j]]++;
		}
		for(m = 0; m <= 9; m++){
			//cout<<count[m]<<" ";
			if(count[m]>1){
				break;
			}
		}
		//cout<<endl;
		if(m == 10){
			printf("%d%d%d%d%d / %d%d%d%d%d = %d\n", nu[1].arr[4], nu[1].arr[3], nu[1].arr[2], nu[1].arr[1], nu[1].arr[0], nu[0].arr[4], nu[0].arr[3], nu[0].arr[2], nu[0].arr[1], nu[0].arr[0], n);
			x++;
		}else{
			continue;
		}	
	}
	if(x == 0){
		cout<<"There are no solutions for "<<n<<"."<<endl; 
	}
	}
	return 0;
}