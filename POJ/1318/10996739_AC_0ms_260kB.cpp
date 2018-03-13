#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map<string, string> m;
char key[20];
char tmp1[20], tmp2[20];

int main(){
	while(scanf("%s", key) != EOF && strcmp(key, "XXXXXX")){
		string t = key;
		sort(key, key + strlen(key));
		m[t] = key;
	}
	while(scanf("%s", tmp1) != EOF && strcmp(tmp1, "XXXXXX")){
		sort(tmp1, tmp1 + strlen(tmp1));
		string s = "";
		bool flag = true;
		for(map<string, string>::iterator it = m.begin(); it != m.end(); ++it){
			for(int i = 0; i <= (it -> second).size(); i++){
				tmp2[i] = (it->second)[i];
			}
			if(!strcmp(tmp2, tmp1)){
				 cout << it->first<<endl;
				 flag = false;
			}
		}
		if(flag) cout << "NOT A VALID WORD" <<endl;
		cout << "******" <<endl;
	}
}