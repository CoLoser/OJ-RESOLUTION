#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int value[11] = {0, 0, 64, 32, 16, 8, 0, 4, 2, 1, 0}; // 根据输入格式 |(四个).(三个)| 写出位权

char key[12];

int main()
{
	gets(key);
	while(gets(key) && key[0] != ' ')
	{
		int cnt = 0;
		for(int i = 2; i < 10; ++i)
			if(key[i] == 'o') cnt += value[i];
		printf("%c", cnt);
	}
}