#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100;
int array[MAXN];
int len;    //得到的结果的长度
//任意进制转化十进制
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

//以十进制的运算表为基础进行转换
void toAny(int t, int tobase)
{
	int count = 0;
    while(t) {
        int val = t % tobase;
        if(0 <= val && val <= 9)
            array[count] = val + '0';
        else if(10 <= val && val <= 15)
            array[count] = val - 10 + 'A';
        t /= tobase;
        count++;
    }
    
    if(count == 0)
        printf("      0\n");
    else if(count > 7)
        printf("  ERROR\n");
    else {
        int i;
        for(i=count; i<7; i++)
            array[i] = ' ';

        for(i=6; i>=0; i--)
            putchar(array[i]);
        putchar('\n');
    }
}
int main()
{
	char key[1024];
	int frombase, tobase;
	while(scanf("%s%d%d", key, &frombase, &tobase) != EOF)
	{
		toAny(toDec(key, frombase), tobase);
	}
	return 0;
}