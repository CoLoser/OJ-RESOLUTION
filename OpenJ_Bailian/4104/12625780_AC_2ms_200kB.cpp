#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;


const int MAXN = 500;
char stack[MAXN + 1];
int pstack;

void push(char c)
{
	stack[pstack++] = c;
}

char pop()
{
	return stack[--pstack];
}
int main()
{
	char c;
	
	pstack = 0;
	
	for(;;)
	{
		c = getchar();
		
		if(c == ' ' || c == '\n' || c == EOF)
		{
			while(pstack)
				putchar(pop());
			if(c != EOF)
			{
				putchar(c);
			}
		 }else 
		 	push(c);
		
		
		if(c == EOF || c == '\n') break; 
	}
	return 0;
} 