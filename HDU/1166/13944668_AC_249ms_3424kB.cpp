#include <iostream>

using namespace std;

struct _Node {
  int l, r, sum;
  int mid() { return (l + r) >> 1; }
};
const int MAXN = 50005;
_Node tree[MAXN << 2];
int value[MAXN];

void push_up(int root) {
  tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;
}
void init(int root, int l, int r) {
  tree[root].l = l;
  tree[root].r = r;

  if (l == r) {
    tree[root].sum = value[l];
    return;
  }
  init(root << 1, l, (l + r) / 2);
  init(root << 1 | 1, (l + r) / 2 + 1, r);

  push_up(root);
}

int query(int root, int l, int r) {
  if (l <= tree[root].l && r >= tree[root].r) {
    return tree[root].sum;
  }
  int m = tree[root].mid();
  int res = 0;
  if (l <= m)
    res += query(root << 1, l, r);
  if (r > m)
    res += query(root << 1 | 1, l, r);
  return res;
}

void update(int root, int idx, int value) {
  if (tree[root].l == tree[root].r) {
    tree[root].sum = value;
    return;
  }

  if (idx <= tree[root].mid())
    update(root << 1, idx, value);
  else
    update(root << 1 | 1, idx, value);

  push_up(root);
}
int main() {
  int t, n;
  char order[10];
  scanf("%d", &t);
  int kase = 0;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
      scanf("%d", &value[i]);
    init(1, 1, n);
    int cnt = 0, a, b;
    printf("Case %d:\n", ++kase);
    while (scanf("%s", order) != EOF && order[0] != 'E' && ++cnt <= 40000) {
      scanf("%d%d", &a, &b);
      if (order[0] == 'Q') {
        if (a > b)
          swap(a, b);
        printf("%d\n", query(1, a, b));
      } else if (order[0] == 'S') {
        value[a] -= b;
        update(1, a, value[a]);
      } else if (order[0] == 'A') {
        value[a] += b;
        update(1, a, value[a]);
      }
    }
  }
  return 0;
}
