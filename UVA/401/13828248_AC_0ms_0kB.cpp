#include <iostream>
#include <string>
#include <cstring>
#include <map>

using namespace std;

string s1 = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
string s3[] = {"is not a palindrome.",
               "is a regular palindrome.",
               "is a mirrored string.",
               "is a mirrored palindrome."
              };
int main() {
	bool palindrome = true;
	bool mirrored = true;
	map<char, char> m;
	for(int i = 0; i < s1.size(); ++i) {
		if(s1[i] != ' ') {
			m[s1[i]] = s2[i];
			m[s2[i]] = s1[i];
		}

	}
	string s;
	while(cin >> s) {
		palindrome = true;
		mirrored = true;
		int len = s.size();
		for(int i = 0; i <= len / 2; ++i) {
			if(s[i] != s[len-i-1]) {
				palindrome = false;
			}
			if(s[i] != m[s[len-i-1]] && s[len-i-1] != m[s[i]]) {
				mirrored = false;
			}
		}

		int flag = 0;
		if(palindrome && mirrored)flag = 3;
		else if(!palindrome && mirrored) flag = 2;
		else if(palindrome && !mirrored) flag = 1;
		else flag = 0;
		cout << s << " -- " << s3[flag]<< "\n\n";
	}
	return 0;
}