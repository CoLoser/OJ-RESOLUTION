#include <iostream>
#include <cstring>
using namespace std;
const int MAX_SIZE=81;
int main(){
	int N;
	cin>>N;
	while(N--){
		int count = 0,sum = 0;
		bool flag = false;
		char key[MAX_SIZE];
		cin >> key;
		int n = strlen(key);
		for(int i = 0; i < n; ++i){
			if(key[i] == 'O'){
				count ++; 
				sum+=count; 
			}else{
				count = 0;
			} 
		}
		cout << sum <<endl;
	}
	
	return 0;
} 