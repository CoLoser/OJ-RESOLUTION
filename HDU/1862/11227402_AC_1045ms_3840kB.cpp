#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100005;

struct node{
	int score;
	int num;
	char name[10];
};
node student[maxn];

bool cmpbynum(node a, node b){
	return a.num<b.num;
}

bool cmpbyname(node a, node b){
	if(strcmp(a.name, b.name) > 0) return false;
	else if(strcmp(a.name, b.name)) return true;
	else{
		return cmpbynum(a, b);
	}
}

bool cmpbyscore(node a, node b){
	if(a.score == b.score) return cmpbynum(a, b);
	else return a.score<b.score;
}


int main()
{
	int n, c;
	int idx = 1;
	while(scanf("%d%d", &n, &c) != EOF)
	{
		if(n == 0 && c == 0) break;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d %s %d", &student[i].num, student[i].name, &student[i].score);
		}
		printf("Case %d:\n", idx++);
		if(c == 1) sort(student, student + n, cmpbynum);
		else if(c == 2) sort(student, student + n, cmpbyname);
		else sort(student, student + n, cmpbyscore);
		for(int i = 0; i < n; ++i){
			printf("%06d %s %d\n", student[i].num, student[i].name, student[i].score);
		}
	}
}