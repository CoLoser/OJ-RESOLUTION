#include "algorithm"
#include "cstdio"
#include "cstring"
#include "iostream"

using namespace std;

int dp[10][2];
int digit[10];

int solove(int len, bool state,
           bool fpos) { // state 为当前状态表示上一位是否为6,
                        // fpos表示是否可以到达最高位，
                        // 203 个位和十位最高为9百位最高为2
  if (len == 0)
    return 1;
  if (fpos == 0 && dp[len][state] != -1)
    return dp[len][state];
  int res = 0;
  int fmaxpos = fpos ? digit[len] : 9;

  for (int i = 0; i <= fmaxpos; ++i) {
    if (i == 4 || (state && i == 2))
      continue;
    res += solove(len - 1, i == 6, fpos && i == fmaxpos);
  }
  if (!fpos)
    dp[len][state] = res;
  return res;
}

int getDigit(int num) {
  int len = 0;
  while (num) {
    digit[++len] = num % 10;
    num /= 10;
  }
  return solove(len, 0, 1);
}

int main(int argc, char const *argv[]) {
  int l, r;
  memset(dp, -1, sizeof(dp));
  while (cin >> l >> r && l || r) {

    printf("%d\n", getDigit(r) - getDigit(l - 1));
  }
  return 0;
}
