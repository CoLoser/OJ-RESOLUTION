#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	int first = -1, second = -1, third = -1, tmp;
	
	for(int i = 0; i < 10; ++i)
	{
		cin >> tmp;
		
		if(third < tmp)
		{
			third = tmp;
			
			if(third > first)
			{
				swap(third, first);
				swap(second, third);
			}else if(second < third)
			{
				swap(second, third);
			}
		} 
	}
	cout << first << endl << second << endl << third <<endl;	
	return 0;
}