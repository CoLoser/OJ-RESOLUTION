/**
  线段数之扫描线
*/
#include "algorithm"
#include "cmath"
#include "cstdio"
#include "cstring"
#include "iostream"
using namespace std;

const int MAXN = 205;
struct _Node { //表示矩形
  double xl, xr, yt, yb;
};
_Node node[MAXN];
int mp[MAXN][MAXN];
double X[MAXN], Y[MAXN];

//返回某条边所在的索引位置
int find(double arr[], double val, int len) {
  int L = 0, R = len - 1;

  while (L <= R) {
    int MID = L + (R - L) / 2;
    if (arr[MID] == val)
      return MID;
    else if (arr[MID] > val)
      R = MID - 1;
    else
      L = MID + 1;
  }
  return -1;
}
int main() {
  int n;
  int lenx, leny;
  int kase = 0;
  while (scanf("%d", &n) != EOF && n) {
    lenx = leny = 0;
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < n; ++i) {
      scanf("%lf%lf%lf%lf", &node[i].xl, &node[i].yb, &node[i].xr, &node[i].yt);
      X[lenx++] = node[i].xl;
      X[lenx++] = node[i].xr;
      Y[leny++] = node[i].yb;
      Y[leny++] = node[i].yt;
    }

    sort(X, X + lenx);
    sort(Y, Y + leny);
    lenx = unique(X, X + lenx) - X;
    leny = unique(Y, Y + leny) - Y; //去重

    //找出小矩形覆盖的范围, 并标记
    for (int i = 0; i < n; ++i) {
      int xl = find(X, node[i].xl, lenx);
      int xr = find(X, node[i].xr, lenx);
      int yb = find(Y, node[i].yb, leny);
      int yt = find(Y, node[i].yt, leny);

      //对返回的矩形进行标记
      for (int j = xl; j < xr; ++j)
        for (int k = yb; k < yt; ++k)
          mp[j][k]++;
    }

    //对标记过的矩形进行计算
    double res = 0;
    for (int i = 0; i < lenx; ++i)
      for (int j = 0; j < leny; ++j)
        if (mp[i][j])
          res += ((X[i + 1] - X[i]) * (Y[j + 1] - Y[j]));
    printf("Test case #%d\nTotal explored area: %.2f\n\n", ++kase, res);
  }

  return 0;
}
