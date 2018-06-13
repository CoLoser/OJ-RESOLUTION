#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;
struct _Node {
  int l, r;
  ll sum;
  int mid() { return (l + r) >> 1; }
};
const int MAXN = 100005;
// int value[MAXN];
int lazy[MAXN << 2];
_Node tree[MAXN << 2];

void push_up(int root) {
  tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;
}
void push_down(int root, int len) {
  if (lazy[root]) {
    lazy[root << 1] = lazy[root];
    lazy[root << 1 | 1] = lazy[root];

    tree[root << 1].sum = lazy[root] * (len - (len >> 1));
    tree[root << 1 | 1].sum = lazy[root] * (len >> 1);

    lazy[root] = 0;
  }
}
void init(int root, int l, int r) {
  tree[root].l = l;
  tree[root].r = r;

  if (l == r) {
    tree[root].sum = 1;
    return;
  }

  int m = (l + r) >> 1;
  init(root << 1, l, m);
  init(root << 1 | 1, m + 1, r);
  push_up(root);
}

void update(int root, int l, int r, int value) {
  if (l == tree[root].l && r == tree[root].r) {
    lazy[root] = value;
    tree[root].sum = (ll)value * (r - l + 1);
    return;
  }

  if (tree[root].l == tree[root].r) {
    return;
  }

  int mid = tree[root].mid();
  push_down(root, tree[root].r - tree[root].l + 1);

  if (l > mid) {
    update(root << 1 | 1, l, r, value);
  } else if (r <= mid) {
    update(root << 1, l, r, value);
  } else {
    update(root << 1, l, mid, value);
    update(root << 1 | 1, mid + 1, r, value);
  }

  push_up(root);
}

int main() {
  int t, n, m, a, b, c;
  scanf("%d", &t);
  for (int i = 1; i <= t; ++i) {
    scanf("%d%d", &n, &m);
    memset(lazy, 0, sizeof(lazy));
    init(1, 1, n);
    for (int j = 0; j < m; ++j) {
      scanf("%d%d%d", &a, &b, &c);
      update(1, a, b, c);
    }
    printf("Case %d: The total value of the hook is %lld.\n", i, tree[1].sum);
  }
  return 0;
}
