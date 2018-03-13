#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	for(int i = 1000; i <= 9999; ++i)
	{
		//十六进制
		int ans_16 = 0;
		ans_16 = (i/4096)%16 + (i/256)%16 + (i/16)%16 + i%16;
		
		//十二进制
		int ans_12 = 0;
		ans_12 = (i/1728)%12 + (i/144)%12 + (i/12)%12 + i%12;
		
		//十进制
		int ans_10 = 0;
		ans_10 = (i/1000)%10 + (i/100)%10 + (i/10)%10 + i%10;
		
		if(ans_16 == ans_12 && ans_12 == ans_10) printf("%d\n", i);
	}
}