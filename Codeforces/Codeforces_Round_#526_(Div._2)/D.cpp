/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll lcm(ll a, ll b) { return (a*b)/__gcd(a, b); }
ll max(ll a, ll b) { return (a>=b)?a:b; }
ll min(ll a, ll b) { return (a<=b)?a:b; }

#define oo 1000000000000000000
#define maxn 300000 + 10

struct node {
  ll v, c;
  node* next;
};

node* head[maxn];
ll res, parent[maxn], maxWeight[maxn], w[maxn];

void dfs(ll u) {
  node* p = head[u];
  ll socon = 0, firstChild = -oo, secondChild = -oo, first = 0, second = 0;
  while (p != nullptr) {
    ll v = p->v;
    if (parent[v] == 0) {
      parent[v] = u;
      socon++;
      dfs(v);
      if (maxWeight[v] - p->c > firstChild) {
        firstChild = maxWeight[v] - p->c;
        first = v;
      }
    }
    p = p->next;
  }

  if (socon > 1) {
    p = head[u];
    while (p != nullptr) {
      ll v = p->v;
      if (parent[v] == u) {
        if (maxWeight[v] - p->c > secondChild && v != first) {
          secondChild = maxWeight[v] - p->c;
          second = v;
        }
      }
      p = p->next;
    }
    res = max(res, firstChild + secondChild + w[u]);
  }

  if (socon == 0) maxWeight[u] = w[u];
  else {
    res = max(res, firstChild + w[u]);
    maxWeight[u] = max(firstChild + w[u], w[u]);
  }
}

int main() {
  fio;
  ll n, u, v, c;
  cin >> n;
  res = -oo;
  FOR(i, 1, n) cin >> w[i], res = max(res, w[i]);
  node* p;
  FOR(i, 1, n - 1) {
    cin >> u >> v >> c;
    p = new node;
    p->v = v;
    p->c = c;
    p->next = head[u];
    head[u] = p;

    p = new node;
    p->v = u;
    p->c = c;
    p->next = head[v];
    head[v] = p;
  }
  parent[1] = -1;
  // res = -oo;
  dfs(1);
  cout << res;
  return 0;
}
