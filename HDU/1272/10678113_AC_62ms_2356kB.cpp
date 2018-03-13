#include<stdio.h>  
#include<iostream>
using namespace std;  
  
int set[100010];   
bool mark[100010];  
  
int findx(int x)    
{    
    int r=x;   
    while(set[r]!=r)    
        r=set[r];    
    return r;    
}    
  
bool merge(int x,int y)    
{    
    int fx,fy;    
    fx=findx(x);    
    fy=findx(y);    
    if(fx!=fy)   
    {  
     set[fx]=fy;  
     return true;  
    }  
    else  
    return false;  
}    
  
int main()  
{  
    int a,b,i,flag,cnt;  
    int min,max;  
    while(scanf("%d%d",&a,&b)&&(a!=-1 && b!=-1))  
    {  
          
        flag=1;cnt=0;  
         if(a==0 && b==0)  
        {  
            printf("Yes\n");  
            continue;  
        }  
  
        for(i=0;i<100010;i++)  
        {  
        set[i]=i;mark[i]=0;  
        }  
        min=9999999;max=-1;  
        while(a||b)  
        {  
            if(a>max) max=a;  
            if(b>max) max=b;  
            if(a<min) min=a;  
            if(b<min) min=b;  
            mark[a]=1;mark[b]=1;  
           if(merge(a,b)==false)  
              flag=0;  
           scanf("%d%d",&a,&b);  
        }  
          
        if(flag==0)  
        printf("No\n");  
        else  
        {  
            for(i=min;i<=max;i++){
            	//cout<< set[i] << " " << mark[i] <<endl; 
	            if(mark[i] && set[i]==i)  
	                cnt++;//这里有一点需要注意，这里也是很多人卡壳的地方！  
	        //题目给出的并不一定是只有一个集合，它可能给出多个集合，彼此并不联通  
	        //而这种情况按照上面的方式判断不出来，因此我们最后还要判断集合的个数  
			}  
			if(cnt==1)  
	                printf("Yes\n");  
	        else  
	                printf("No\n");
              
        }  
    }  
    //system("pause");  
    return 0;  
}  