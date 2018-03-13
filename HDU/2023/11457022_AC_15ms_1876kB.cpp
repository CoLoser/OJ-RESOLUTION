#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
double stu[55];
double cou[10];
int score[55][10];

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		int ans = 0;
		memset(stu, 0, sizeof(stu));
		memset(cou, 0, sizeof(cou));
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
			{
				scanf("%d", &score[i][j]);
				stu[i] += score[i][j];
			}
				
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				cou[i] += score[j][i];
		for(int i = 0; i < n; ++i){
			printf("%.2f%c", stu[i]/m, i == n - 1?'\n':' ');
			int flag = true;
			for(int j = 0; j < m; ++j)
			{
				if(score[i][j] < cou[j]/n) flag = false;
			}
			if(flag) ans ++;
		}
			
		for(int i = 0; i < m; ++i)
		{
			printf("%.2f%c", cou[i]/n, i == m - 1?'\n':' ');
		}

		printf("%d\n", ans);
		printf("\n");
	}
	return 0;
}