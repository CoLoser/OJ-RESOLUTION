#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100;
char array[MAXN];
//任意进制转化十进制返回十进制数
int toDec(const char *p, int frombase)
{
    int ans = 0;
    while(*p)
    {
        ans *= frombase;
        if(isdigit(*p)) ans += *p - '0';
        if(isalpha(*p)) ans += *p - 'A' + 10;
        p++;
    }
    return ans;
}
//在十进制的运算表下进行转化
void toAny(int t, int tobase)
{
    if(t == 0) return;
    toAny(t/tobase, tobase);    //回溯直接逆序输出
    int x = t%tobase;
    printf("%c", (x >= 10 ? x + 'A' - 10 : x + '0'));  //考虑大于10的情况
}
int main()
{
	int frombase, tobase;
	while(cin >> frombase >> array >> tobase)
	{
		for(int i = 0; i < strlen(array); ++i)
			if(islower(array[i])) array[i] -= 32;
		if(strcmp(array, "0") != 0) toAny(toDec(array, frombase), tobase);
		else cout << "0" ;
		cout << endl;
	}

}