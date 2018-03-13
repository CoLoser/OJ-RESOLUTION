#include "iostream"
#include "map"
#include "string"
using namespace std;
int main(int argc, char const *argv[])
{
	map<char, int> templet;
	templet['A'] = 4;
	templet['K'] = 3;
	templet['Q'] = 2;
	templet['J'] = 1;
	string s;
	int count = 0;
	for (int i = 0; i < 13; ++i)
	{
		cin >> s;
		count += templet[s[1]];

	}
	cout << count << endl;
	return 0;
}