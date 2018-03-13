#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct BigInteger{
    const static int MOD = 10000;
    const static int DLEN = 4;

    int a[100], len;

    BigInteger()
    {
        memset(a, 0, sizeof(a));
        len = 1;
    }

    BigInteger(int v)
    {
        memset(a, 0, sizeof(a));
        len = 0;
        do
        {
            a[len++] = v%MOD;
            v /= MOD;
        }while(v);
    }

    BigInteger(const char s[])
    {
        memset(a, 0, sizeof(a));
        int L = strlen(s);
        len = L/DLEN;
        if(L%DLEN) len++;
        int idx = 0;

        for(int i = L - 1; i >= 0; i -= DLEN)
        {
            int t = 0;
            int k = i - DLEN + 1;
            if(k < 0) k = 0;
            for(int j = k;j <= i;j++)
                t = t*10 + s[j] - '0';
            a[idx++] = t;
        }
    }

    BigInteger operator + (const BigInteger &b) const
    {
        BigInteger res;
        res.len = max(len, b.len);

        for(int i = 0; i <= res.len; ++i)
            res.a[i] = 0;

        for(int i = 0; i < res.len; ++i)
        {
            res.a[i] += ((i < len)?a[i]:0)+((i < b.len)?b.a[i]:0);
            res.a[i+1] += res.a[i]/MOD;
            res.a[i] %= MOD;
        }
        if(res.a[res.len] > 0)res.len++;
        return res;
    }
    void output()
    {
        printf("%d",a[len-1]);
        for(int i = len-2;i >=0 ;i--)
            printf("%04d",a[i]);
        printf("\n");
    }

};

const int MAXN = 205;
char key[MAXN];

int main()
{
	BigInteger bint[MAXN];
	BigInteger b1(1), b2(2);
	bint[1] = b1;
	bint[2] = b2;
	for(int i = 3; i < MAXN; ++i)
		bint[i] = bint[i-1] + bint[i-2];
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> key;
		
		bint[strlen(key)].output();
	}
}