/* Bailian4021 最大乘积 */

#include <stdio.h>
#include <limits.h>

int main(void)
{
    int m, n, a, i;
    long long ncount, maxn, minn, pcount, minp, zeros, start, flagstart;

    scanf("%d", &m);
    while(m--) {
        scanf("%d", &n);

        ncount = 0;                 /* 负数个数 */
        maxn = INT_MIN;       		/* 负数最大值 */
        minn = 0;                   /* 负数最小值 */
        pcount = 0;                 /* 自然数个数 */
        minp = INT_MAX;       		/* 自然数最小值 */
        zeros = 0;                  // 0的个数
		flagstart = 0;              //第一个为负数的数
        int flag1 = 1;
        int flag2 = 1;
        for(i=1; i<=n; i++) {
            scanf("%d", &a);
			if(flag1)
			{
				flag1 = 0;
				start = a;
			}
            if(a < 0) {
            	if(flag2)
            	{
					flag2 = 0;
					flagstart = a;
				}
                ncount++;
                if(a > maxn)
                    maxn = a;
                else if(a < minn)
                    minn = a;
            } else if(a > 0){
                pcount++;
                if(a < minp)
                    minp = a;
            }else zeros ++;
        }

        if(zeros > 1)
        {
        	printf("%d\n", start);
		}else if(zeros == 1)
		{
			if(ncount % 2 == 0) printf("%d\n", 0);
			else if(ncount % 2 == 1) printf("%d\n", flagstart);
		}else if(zeros == 0)
		{
			if(ncount %2 == 1) printf("%d\n", maxn);
			else if(ncount %2 == 0) printf("%d\n", pcount == 0 ? minn : minp);
		}
    }

    return 0;
}