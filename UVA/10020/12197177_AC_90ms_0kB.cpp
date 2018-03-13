#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct _Node{
	int left;
	int right;
};
bool cmp(_Node rhs1, _Node rhs2)
{
	return rhs1.left < rhs2.left;
}
const int MAXN = 100000 + 1;
_Node arr[MAXN];
int ans[MAXN];
int pad[MAXN];

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int key, l, r, cnt = 0, num = 0, k = 0;
		cin >> key;
		while(cin >> l >> r)
		{
			if(l == 0 && r == 0) break;
			arr[cnt].left = l;
			arr[cnt].right = r;
			cnt ++;
		}
		sort(arr, arr + cnt, cmp);
		while (k < key) {
            int temp = k;
            for (int i = 0; i < cnt; i++)
                if (arr[i].left <= k && arr[i].right > temp) {
                    temp = arr[i].right;
                    ans[num] = i;
                }
            if (temp == k) {
                num = 0;
                break;
            }
            k = temp;
            num++;
        }
		printf("%d\n", num);
		for(int i = 0; i < num; ++i) printf("%d %d\n", arr[ans[i]].left, arr[ans[i]].right);
		cout << endl;
	}
}