#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	long long arr[56]={1,2,3};
	for(int i = 3; i < 56; i++){
		arr[i]=arr[i-1]+arr[i-3]; 
	} 
	int m;
	scanf("%d",&m);
	while(m!=0){
		cout<<arr[m-1]<<endl;
		scanf("%d",&m);
	}
	return 0;
}