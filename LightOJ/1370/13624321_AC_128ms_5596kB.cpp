#include "cmath"
#include "cstdio"
#include "cstring"
#include "iostream"
using namespace std;

typedef long long ll;
const int MAXN = 1000005;
int prime[MAXN];

void getPrime() {
  memset(prime, 0, sizeof(prime));

  prime[0] = 1;
  prime[1] = 1;
  for (int i = 2; i <= sqrt(MAXN); ++i)
    if (!prime[i])
      for (int j = i * i; j < MAXN; j += i)
        prime[j] = 1;
}
int main() {
  getPrime();
  int t, n, a, x = 0;
  ll res;
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
    printf("Case %d: %lld Xukha\n", ++x, res);
  }
  return 0;
}
