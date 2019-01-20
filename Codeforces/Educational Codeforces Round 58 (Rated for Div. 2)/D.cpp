#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;

typedef long long ll;
typedef pair<long, long> pll;

ll max(ll a, ll b) { return (a >= b ) ? a : b; }

#define maxn 200000 + 10
long a[maxn], cnt, longestPath, longestEnd, res;
vector<long> neighbor[maxn];
bool mark[maxn], check[maxn];
pll edge[maxn];

inline bool isPrime(long x) {
  if (x <= 1) return false;
  if (x == 2 || x == 3) return true;
  FOR(i, 2, sqrt(x)) if (x % i == 0) return false;
  return true;
}

void dfs(long u) {
  check[u] = true;
  mark[u] = true;
  cnt++;
  if (cnt > longestPath) {
    longestPath = cnt;
    longestEnd = u;
  }
  FOR(i, 0, sz(neighbor[u]) - 1) {
    long v = neighbor[u][i];
    if (!mark[v]) dfs(v);
  }
  cnt--;
  mark[u] = false;
}

void findDiameter(long u) {
  cnt = 0, longestPath = 0;
  dfs(u);
  cnt = 0, longestPath = 0;
  dfs(longestEnd);
  res = max(res, longestPath);
}

int main() {
  fio;
  long n;
  cin >> n;
  long maxa = 0;
  FOR(i, 1, n) {
    cin >> a[i];
    maxa = max(maxa, a[i]);
  }
  res = 0;
  vector<long> validVertice;
  FOR(i, 1, n - 1) cin >> edge[i].fi >> edge[i].se;
  FOR(x, 2, sqrt(maxa)) if (isPrime(x)) {
    FOR(i, 1, n) neighbor[i].clear();
    FOR(i, 1, n - 1) {
      if (a[edge[i].fi] % x != 0 || a[edge[i].se] % x != 0) continue;
      neighbor[edge[i].fi].push_back(edge[i].se);
      neighbor[edge[i].se].push_back(edge[i].fi);
    }
    validVertice.clear();
    FOR(i, 1, n) if (a[i] % x == 0) {
      while (a[i] % x == 0) a[i] /= x;
      validVertice.push_back(i);
    }
    memset(check, false, sizeof(check));
    memset(mark, false, sizeof(mark));
    FOR(i, 0, sz(validVertice) - 1) {
      if (!check[validVertice[i]]) findDiameter(validVertice[i]);
    }
  }
  FOR(i, 1, n) neighbor[i].clear();
  FOR(i, 1, n - 1) {
    if (a[edge[i].fi] != a[edge[i].se] || a[edge[i].fi] == 1 || a[edge[i].se] == 1) continue;
    neighbor[edge[i].fi].push_back(edge[i].se);
    neighbor[edge[i].se].push_back(edge[i].fi);
  }
  memset(check, false, sizeof(check));
  memset(mark, false, sizeof(mark));
  FOR(i, 1, n) if (!check[i] && a[i] != 1) findDiameter(i);
  cout << res;
  return 0;
}
