/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define pb push_back
#define sz(x) int(x.size())

using namespace std;

#define FORALL(iter, x) for (auto iter = x.begin(); iter != x.end(); iter++)
#define maxn 200000 + 10
long n, m, cnt;
set<long> s2;
set<long> notEdge[maxn];
vector<long> temp;

void visit(long s) {
  if (s2.find(s) != s2.end()) s2.erase(s2.find(s));
  queue<long> q;
  q.push(s);
  while (!q.empty()) {
    long u = q.front();
    q.pop();
    temp.clear();
    cnt++;
    FORALL(iter, s2) {
      long v = (*iter);
      if (notEdge[u].find(v) == notEdge[u].end()) {
        temp.pb(v);
        q.push(v);
      }
    }
    FOR(i, 0, sz(temp) - 1) if (s2.find(temp[i]) != s2.end()) s2.erase(s2.find(temp[i]));
  }
}

int main() {
	fio;
  cin >> n >> m;
  FOR(i, 1, m) {
    long u, v;
    cin >> u >> v;
    notEdge[u].insert(v);
    notEdge[v].insert(u);
  }
  FOR(i, 1, n) s2.insert(i);
  vector<long> res;
  FOR(i, 1, n) if (s2.find(i) != s2.end()) {
    cnt = 0;
    visit(i);
    res.pb(cnt);
  }
  sort(res.begin(), res.end());
  cout << sz(res) << '\n';
  FOR(i, 0, sz(res) - 1) cout << res[i] << " ";
	return 0;
}
