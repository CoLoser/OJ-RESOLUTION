#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Team{
	string name;
	int solved;
	int penate;
};
const int MAXN = 100;
Team team[MAXN];
bool cmp(Team rhs1, Team rhs2)
{
	if(rhs1.solved == rhs2.solved) return rhs1.penate < rhs2.penate;
	else return rhs1.solved > rhs2.solved;
}
void init()
{
	for(int i = 0; i < MAXN; ++i)
		team[i].penate = team[i].solved = 0;
}
int main()
{
	int t;
	string name;
	int solveTime, penate;
	while(cin >> t)
	{
		init();
		for(int i = 0; i < t; ++i)
		{
			cin >> name;
			for(int j = 0; j < 4; ++j)
			{
				cin >> penate >> solveTime;
				if(solveTime != 0) team[i].solved++, team[i].penate += solveTime + (penate - 1) * 20;
			}
			team[i].name = name;
		}

		sort(team, team + t, cmp);
	//	for(int i = 0; i < t; ++i) cout << team[i].name << "   " << team[i].solved << "   " << team[i].penate <<endl;
		
		cout << team[0].name << " " << team[0].solved << " " << team[0].penate<<endl;
	}
}