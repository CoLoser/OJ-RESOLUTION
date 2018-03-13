#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 105;
const int maxchar = 60;

string filename[maxn];

void print(const string& s, int len, char extra){
	cout << s;
	for(int i = 0; i < len - s.length(); ++i)
		cout << extra;
}
int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int len = 0;
		for(int i = 0; i < n; ++i){
			cin >> filename[i];
			len = max(len, (int)filename[i].length());
		}
		int row, col;
		col = (maxchar - len)/(len + 2) + 1;
		row = (n - 1)/col + 1;
		print("", 60, '-');
		cout << endl;
		sort(filename, filename + n);
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; ++j){
				int index = j * row + i;
				if(index < n) print(filename[index], j == col - 1 ? len : len + 2, ' ');
			}
			cout << endl;
		}
	}
	return 0;
}