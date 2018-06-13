#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1000005;
int prime[MAXN];

void init() {
  memset(prime, 0, sizeof(prime));
  prime[0] = 1;
  prime[1] = 1;
  for (int i = 2; i <= sqrt(MAXN); ++i)
    if (!prime[i])
      for (int j = i * i; j < MAXN; j += i)
        prime[j] = 1;
}

int main() {
  init();
  int t, n, a, kase = 0;
  long long res;
  cin >> t;
  while (t--) {
    cin >> n;
    res = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a;
      while (1) {
        if (!prime[++a]) {
          res += a;
          break;
        }
      }
    }
    printf("Case %d: %lld Xukha\n", ++kase, res);
  }
  return 0;
}
