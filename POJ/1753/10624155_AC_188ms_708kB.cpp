#include "iostream"
#include "stdio.h"
using namespace std;
int state[16];
int bit[16] = {1};
int field = 0;
int minNum = 0xFF;
void readData()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			field <<= 1;
			if (getchar() == 'b')
				field |= 1;
		}
		getchar();
	}
}
void calState()
{
	for (int i = 1; i <= 16; i++)
	{
		int v = 0, k = 1 << (i - 1); v |= k;
		if ((i + 1) % 4 != 1) v |= k << 1;
		if ((i - 1) % 4 != 0) v |= k >> 1;
		if (i > 4)  v |= k >> 4;
		if (i < 13) v |= k << 4;
		state[16 - i] = v;
		//cout << v << endl;
	}

}
void calBit()
{
	int count = 1;
	for (int i = 0; i < 16; ++i)
	{
		bit[i] = count;
		count *= 2;
	}

}
bool check()
{
	return field == 0x0000 || field == 0xFFFF;
}
void flip()
{
	for (int i = 0; i < 0xFFFF; ++i)
	{
		int temp = field;
		int cnt = 0;
		for (int j = 0; j < 16; ++j)
		{
			if (i & bit[j])
			{
				field ^= state[j];
				cnt++;
			}
		}
		if (check() && cnt < minNum)
		{
			minNum = cnt;
		}
		field = temp;
	}
}
void print()
{
	if (minNum == 0xFF)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		cout << minNum << endl;
	}
}
int main(int argc, char const *argv[])
{
	readData();
	calState();
	calBit();
	flip();
	print();
	return 0;
}