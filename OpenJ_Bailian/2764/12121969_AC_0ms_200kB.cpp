#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;

const int MAXN = 1005;
string arr;

void to_string(string &s, int t) //Type为类型
{
    ostringstream oss;
    oss<<t;
    s = oss.str();      //转化成字符串写入string中
}
int main()
{
	while(cin>>arr)
	{
		int ans = 0;
		for(int i = 0; i < arr.size(); ++i) ans += arr[i] - '0';
		to_string(arr, ans);
		ans = 0;
		while(arr.size() > 1)
		{
			for(int i = 0; i < arr.size(); ++i) ans += arr[i] - '0';
			to_string(arr, ans);
			ans = 0;
		}
		cout << arr <<endl;
	}
}