#include <iostream>
#include <cstdio>
#include <cmath> 
#include <cstring>
using namespace std;

typedef unsigned long long ull;
//任意进制转化十进制返回十进制数
ull toDec(const char *p, int frombase)
{
    ull ans = 0;
    while(*p)
    {
        ans *= frombase;
        if(isdigit(*p)) ans += *p - '0';
        if(isalpha(*p)) ans += *p - 'A' + 10;
        p++;
    }
    return ans;
}
//在十进制的运算表下进行转化 (不包含0的情况, 若为零要预先判断)
void toAny(ull t, int tobase)
{
    if(t == 0) return;
    toAny(t/tobase, tobase);    //回溯直接逆序输出
    printf("%c", (t%tobase >= 10 ? t%tobase + 'A' - 10 : t%tobase + '0'));  //考虑大于10的情况
}

int main()
{
	int t;	
	while(cin >> t)
	{	
		getchar();
		while(t--)
		{
			char s[65];
			cin.getline(s, 65);
			bool flag = 1;
			for(int i = 0; i < strlen(s); ++i) if(s[i] == '1') flag = 0;
			if(flag) cout << 0 ;
			else toAny(toDec(s, 2), 3);	
			cout << endl;		
		}
	}
	return 0;
}