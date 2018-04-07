#include <iostream> 
#include <cstdio>

using namespace std;

double ScorePoint[101];
int StudyScore[11];
void init()
{
	for(int i = 0; i <= 100; ++i)
	{
		if(i < 60) ScorePoint[i] = 0;
		else if(i <= 63) ScorePoint[i] = 1;
		else if(i <= 67) ScorePoint[i] = 1.5;
		else if(i <= 71) ScorePoint[i] = 2.0;
		else if(i <= 74) ScorePoint[i] = 2.3;
		else if(i <= 77) ScorePoint[i] = 2.7;
		else if(i <= 81) ScorePoint[i] = 3.0;
		else if(i <= 84) ScorePoint[i] = 3.3;
		else if(i <= 89) ScorePoint[i] = 3.7;
		else ScorePoint[i] = 4.0;
	}
}
int main()
{
	double GPA = 0.0;
	int score, a, b, m;
	int t;
	init();
	while(scanf("%d", &t) != EOF)
	{
		GPA = 0.0;
		m = 0;
		for(int i = 0; i < t; ++i) cin >> StudyScore[i], m += StudyScore[i];
		for(int i = 0; i < t; ++i) cin >> score, GPA += ScorePoint[score]*StudyScore[i];
		printf("%.2f", GPA/m);
	}	
	return 0;
}