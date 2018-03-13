#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 100005;

struct Student{
	int number;
	char name[10];
	int score;
	void Print()
	{
		printf("%06d ", number);
		cout << name;
		printf(" %d\n", score);
	}
};
Student s[maxn];
bool cmpbynum(Student s1, Student s2)
{
	return s1.number < s2.number;
}
bool cmpbyname(Student s1, Student s2)
{
	if(strcmp(s1.name, s2.name) == 0) return s1.number < s2.number;
	else if(strcmp(s1.name, s2.name) < 0) return true;
	else return false;
}

bool cmpbyscore(Student s1, Student s2)
{
	if(s1.score == s2.score)return s1.number < s2.number;
	else return s1.score < s2.score;
}

int main()
{
	int n, flag;
	int kase = 1;
	while(scanf("%d%d", &n, &flag) != EOF)
	{
		if(n == 0 && flag == 0) break;
		for(int i = 0; i < n; ++i) scanf("%d%s%d", &s[i].number, &s[i].name, &s[i].score);
		
		if(flag == 1)sort(s, s + n, cmpbynum);
		else if(flag == 2)sort(s, s + n, cmpbyname);
		else sort(s, s + n, cmpbyscore);
		printf("Case %d:\n", kase++);
		for(int i = 0; i < n; ++i)
			s[i].Print();
	}
	return 0;
}