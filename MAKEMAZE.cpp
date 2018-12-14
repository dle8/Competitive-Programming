/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define eps 1e-9

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<ll, ll> pllll;
typedef pair<ld, ld> Point;
typedef pair<Point, Point> line;
struct strLine { ld a, b, c; };

typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;

const double pi = 3.141592653589793;

ll gcd(ll a, ll b) { return (b==0)?a:gcd(b, a%b); }
ll lcm(ll a, ll b) { return (a*b)/gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

#define maxn 20 + 10

int main() {
	fio;

  long test_cases, m, n, exitPoint;
  char maze[maxn][maxn];
  bool visited[maxn][maxn];
  bool inQueue[maxn][maxn];
  cin >> test_cases;
  FOR(current_test, 1, test_cases) {
    cin >> m >> n;

    FOR(i, 1, m)
    FOR(j, 1, n) {
      cin >> maze[i][j];
    }

    pii s = mp(0,0);
    pii t = mp(0,0);
    exitPoint = 0;
    FOR(j, 1, n) {
      if (maze[1][j] == '.') {
        exitPoint++;
        if (s.fi == 0) {
          s.fi = 1;
          s.se = j;
        }
        else {
          t.fi = 1;
          t.se = j;
        }
      }
      if (m != 1 && maze[m][j] == '.') {
        exitPoint++;
        if (s.fi == 0) {
          s.fi = m;
          s.se = j;
        }
        else {
          t.fi = m;
          t.se = j;
        }
      }
    }

    FOR(i, 2, m - 1) {
      if (maze[i][1] == '.') {
        exitPoint++;
        if (s.fi == 0) {
          s.fi = i;
          s.se = 1;
        }
        else {
          t.fi = i;
          t.se = 1;
        }
      }
      if (n != 1 && maze[i][n] == '.') {
        exitPoint++;
        if (s.fi == 0) {
          s.fi = i;
          s.se = n;
        }
        else {
          t.fi = i;
          t.se = n;
        }
      }
    }

    if (exitPoint != 2) {
      cout << "invalid" << "\n";
      continue;
    }

    queue<pii> q;
    memset(visited, false, sizeof(visited));
    memset(inQueue, false, sizeof(inQueue));
    q.push(s);
    inQueue[s.fi][s.se] = true;
    while (!q.empty()) {
      pii u = q.front();
      q.pop();

      visited[u.fi][u.se] = true;

      if (u.fi + 1 <= m && !visited[u.fi + 1][u.se] && maze[u.fi + 1][u.se] == '.' && !inQueue[u.fi + 1][u.se]) {
        inQueue[u.fi + 1][u.se] = true;
        q.push(mp(u.fi + 1, u.se));
      }

      if (u.fi - 1 >= 1 && !visited[u.fi - 1][u.se]  && maze[u.fi - 1][u.se] == '.' && !inQueue[u.fi - 1][u.se]) {
        inQueue[u.fi - 1][u.se] = true;
        q.push(mp(u.fi - 1, u.se));
      }

      if (u.se - 1 >= 1 && !visited[u.fi][u.se - 1] && maze[u.fi][u.se - 1] == '.' && !inQueue[u.fi][u.se - 1]) {
        inQueue[u.fi][u.se - 1] = true;
        q.push(mp(u.fi, u.se - 1));
      }

      if (u.se + 1 <= n && !visited[u.fi][u.se + 1] && maze[u.fi][u.se + 1] == '.' && !inQueue[u.fi][u.se + 1]) {
        inQueue[u.fi][u.se + 1] = true;
        q.push(mp(u.fi, u.se + 1));
      }
    }

    cout << ((visited[t.fi][t.se]) ? "valid" : "invalid") << "\n";
  }

	return 0;
}
