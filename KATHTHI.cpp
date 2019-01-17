/*
Author: Dung Tuan Le
University of Rochester
*/

/*
Tested: https://www.spoj.com/problems/KATHTHI/
*/

#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define fi first
#define se second
using namespace std;

#define maxn 1000 + 10
long test_cases, r, c, dist[maxn][maxn];
char gmap[maxn][maxn];
bool check[maxn][maxn];

struct node {
  long x, y;
};

ostream& operator<<(ostream &os, node exp) {
  return os << exp.x << " " << exp.y;
}

#define oo 1000000000

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> test_cases;
  FOR(current_test, 1, test_cases) {
    cin >> r >> c;
    FOR(i, 1, r) FOR(j, 1, c) cin >> gmap[i][j], dist[i][j] = oo;
    dist[1][1] = 0;
    memset(check, 0, sizeof(check));
    deque<node> dq;
    dq.push_back({1, 1});
    while (!dq.empty()) {
      node u = dq.front();
      dq.pop_front();
      if (check[u.x][u.y]) continue;
      check[u.x][u.y] = true;
      if (u.x > 1) {
        long guard = 0;
        if (gmap[u.x - 1][u.y] != gmap[u.x][u.y]) guard = 1;
        if (dist[u.x - 1][u.y] > dist[u.x][u.y] + guard) {
          dist[u.x - 1][u.y] = dist[u.x][u.y] + guard;
          if (guard == 1) dq.push_back({u.x - 1, u.y});
          else dq.push_front({u.x - 1, u.y});
        }
      }
      if (u.x < r) {
        long guard = 0;
        if (gmap[u.x][u.y] != gmap[u.x + 1][u.y]) guard = 1;
        if (dist[u.x + 1][u.y] > dist[u.x][u.y] + guard) {
          dist[u.x + 1][u.y] = dist[u.x][u.y] + guard;
          if (guard == 1) dq.push_back({u.x + 1, u.y});
          else dq.push_front({u.x + 1, u.y});
        }
      }
      if (u.y > 1) {
        long guard = 0;
        if (gmap[u.x][u.y - 1] != gmap[u.x][u.y]) guard = 1;
        if (dist[u.x][u.y - 1] > dist[u.x][u.y] + guard) {
          dist[u.x][u.y - 1] = dist[u.x][u.y] + guard;
          if (guard == 1) dq.push_back({u.x, u.y - 1});
          else dq.push_front({u.x, u.y - 1});
        }
      }
      if (u.y < c) {
        long guard = 0;
        if (gmap[u.x][u.y + 1] != gmap[u.x][u.y]) guard = 1;
        if (dist[u.x][u.y + 1] > dist[u.x][u.y] + guard) {
          dist[u.x][u.y + 1] = dist[u.x][u.y] + guard;
          if (guard == 1) dq.push_back({u.x, u.y + 1});
          else dq.push_front({u.x, u.y + 1});
        }
      }
    }
    cout << dist[r][c] << '\n';
  }
	return 0;
}
