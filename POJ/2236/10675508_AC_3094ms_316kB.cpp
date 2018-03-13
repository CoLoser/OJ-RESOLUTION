#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAX_SIZE=1002;
int Set_father[MAX_SIZE];
int Set_Count[MAX_SIZE];
int index,num;
struct Point{
	double x,y;
};
Point point[MAX_SIZE];
double CalDistance(Point a, Point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void Initialization(){
	num=0;
	for(int i = 0; i < MAX_SIZE; ++i){
		Set_father[i]=i;
		Set_Count[i]=0;
	}
}
int find(int p){
	if(p==Set_father[p]){
		return Set_father[p];
	}
	return Set_father[p]=find(Set_father[p]);
}
void Union(int a,int b){
	int x,y;
	x=find(a);
	y=find(b);
	if(x!=y){
		Set_father[y]=x;
	}
}
int main(){
	double d;
	int x,y;
	char key;
	cin>>index>>d;
	Initialization();
	for(int i = 1; i <= index; ++i){
		cin>>point[i].x>>point[i].y;
	}
	while(scanf("%c",&key)!=EOF){
		if(key=='O'){
			cin>>x;
			for(int i = 0; i < num; i++){
				if(CalDistance(point[Set_Count[i]],point[x])<=d+1e-6){
					Union(Set_Count[i],x);
				}	
			}
			Set_Count[num++]=x;
		}
		if(key=='S')
		{
			cin>>x>>y;
			if(find(x)==find(y))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
	}
	return 0;
}