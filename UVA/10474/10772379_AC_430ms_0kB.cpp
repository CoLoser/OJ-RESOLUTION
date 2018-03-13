#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dat[10010];
int cmp_int(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int n,q,now=0;
    while(scanf("%d %d",&n,&q)!=EOF)
    {
        int i,j;
        if(n==0&&q==0)
            break;
        printf("CASE# %d:\n",++now);
        memset(dat,0,sizeof(dat));
        for(i=0;i<n;i++)
            scanf("%d",&dat[i]);
        qsort(dat,n,sizeof(int),cmp_int);
        for(i=0;i<q;i++)
        {
            int num,flag=0;
            scanf("%d",&num);
            for(j=0;j<n;j++)
            {
                if(num==dat[j])
                {
                    printf("%d found at %d\n",num,j+1);
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                printf("%d not found\n",num);
        }

    }
    return 0;
}