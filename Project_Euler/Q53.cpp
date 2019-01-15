/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define eps 1e-9
#define _TIME
using namespace std;

typedef long long ll;
typedef long double ld;

#define maxn 100 + 10
ld c[maxn][maxn];
bool check[maxn][maxn];

ld calc(long n, long r) {
  ld res = 1.0;
  FOR(i, 1, r) res *= ((n - r + i) / ld(i));
  return res;
}

int main() {
#ifdef _TIME
  //freopen("", "r", stdin);
  long tt = clock();
#endif

	fio;
  long cnt = 0;
  FOR(n, 1, 100) {
    FOR(r, 0, n) {
      check[n][r] = check[n - 1][r - 1] && check[n - 1][r];
      if (!check[n - 1][r - 1] || !check[n - 1][r]) {
        c[n][r] = calc(n, r);
        check[n][r] = (c[n][r] - 1000000 > eps);
      }
      if (check[n][r]) cnt++;
    }
  }
  cout << cnt << '\n';

#ifdef _TIME
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif

	return 0;
}
