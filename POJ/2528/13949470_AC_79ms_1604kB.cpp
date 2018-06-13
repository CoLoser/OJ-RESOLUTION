#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 10000 + 100;
int li[MAXN], ri[MAXN], list[MAXN << 3];
int tree[MAXN << 4];
bool visit[MAXN << 3]; //对颜色进行标记
int ans;

void push_down(int root) { //向下更新
  tree[root << 1 | 1] = tree[root << 1] = tree[root];
  tree[root] = -1;
}

void update(int root, int l, int r, int op, int ed, int color) {
  if (op >= l && ed <= r) {
    tree[root] = color;
    return;
  }

  if (tree[root] != -1)
    push_down(root);

  int mid = (op + ed) / 2;
  if (l <= mid)
    update(root << 1, l, r, op, mid, color);
  if (r > mid)
    update(root << 1 | 1, l, r, mid + 1, ed, color);
}

void query(int root, int l, int r) {
  if (l == r) {
    if (!visit[tree[root]]) {
      ans++;
      visit[tree[root]] = true;
    }
    return;
  }

  if (tree[root] != -1)
    push_down(root);

  int mid = (l + r) / 2;
  query(root << 1, l, mid);
  query(root << 1 | 1, mid + 1, r);
}
int main() {
  int c, n;
  scanf("%d", &c);
  while (c--) {
    memset(visit, false, sizeof(visit));
    memset(tree, -1, sizeof(tree));
    ans = 0;
    scanf("%d", &n);
    int len = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &li[i], &ri[i]);
      list[++len] = li[i];
      list[++len] = ri[i];
    }

    sort(list + 1, list + len + 1);
    len = unique(list + 1, list + len + 1) - (list + 1);
    //加中间节点 防止覆盖
    int t = len;
    for (int i = 2; i <= len; ++i) {
      if (list[i] - list[i - 1] > 1) {
        list[++t] = list[i - 1] + 1;
      }
    }
    len = t;
    sort(list + 1, list + len + 1);

    for (int i = 1; i <= n; ++i) {
      int l = lower_bound(list + 1, list + len + 1, li[i]) - (list + 1);
      int r = lower_bound(list + 1, list + len + 1, ri[i]) - (list + 1);
      // cout << l + 1 << "  " << r + 1 << endl;
      update(1, l + 1, r + 1, 1, len, i);
    }
    query(1, 1, len);
    printf("%d\n", ans);
  }
  return 0;
}
