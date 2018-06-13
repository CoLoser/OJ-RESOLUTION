#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

map<string, string> ssmap;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string order, from, tmp;
	char buf[11];
	
	cin >> order;
	while(cin >> order >> from)
	{
		if(order == "END") break;

		ssmap[from] = order;
	}
	getchar();
	
	char c;
	int i = 0;  
    while(scanf("%c", &c)) {  
        if(isalpha(c))  
            buf[i++] = c;  
        else{  
            buf[i] = '\0';  
            if(strcmp(buf, "END") == 0)  
                break;  
            if(ssmap.find(buf) != ssmap.end()) {  
                printf("%s", ssmap[buf].c_str());  
            } else  
                printf("%s", buf);  
            putchar(c);  
  
            i = 0;  
        }  
    }  
	return 0;
}