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
#define sz(x) int(x.size())
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

/* tach xau
string str = "Hello World"; stringstream ss(str);
while (ss >> token) cout << token << endl;
*/

#define maxn 100000 + 10
long n, m, u[maxn], v[maxn], c[maxn], order[maxn], cnt, res[maxn], deg[maxn];
vector<long> neighbor[maxn];
bool check[maxn], flag;

class pq{
	public:
		long heap[maxn], cs[maxn];
		long heapSize;

	void init() {
		heapSize = 0;
		memset(cs, 0, sizeof(cs));
	}

	long top() {
		return heap[1];
	}

	bool empty() {
		return (heapSize == 0);
	}

	void push(long p) {
		if (cs[p]==0) {
			heap[++heapSize] = p;
			cs[p] = heapSize;
		}
		upHeap(cs[p]);
	}

	void upHeap(long index) {
		long temp = heap[index];
		while (true){
			long parent = index/2;
			if (parent==0 || deg[heap[parent]]<=deg[temp]) break;
			heap[index]=heap[parent];
			cs[heap[index]]=index;
			index=parent;
		}
		heap[index]=temp;
		cs[heap[index]]=index;
	}

	void pop() {
		cs[heap[1]] = 0;
		cs[heap[heapSize]] = 1;
		heap[1] = heap[heapSize--];
		downHeap(1);
	}

	void downHeap(long index) {
		long temp = heap[index];
		while (true){
			long child = index*2;
			if (child<heapSize && deg[heap[child]]>deg[heap[child+1]]) child++;
			if (child>heapSize || deg[temp]<=deg[heap[child]]) break;
			heap[index]=heap[child];
			cs[heap[index]]=index;
			index=child;
		}
		heap[index]=temp;
		cs[heap[index]]=index;
	}
} q;

bool ok(long bound) {
  memset(deg, 0, sizeof(deg));
  memset(order, 0, sizeof(order));
  FOR(i, 1, n) neighbor[i].clear();
  FOR(i, 1, m) if (c[i] > bound) {
    neighbor[u[i]].pb(v[i]);
    deg[v[i]]++;
  }
  q.init();
  FOR(i, 1, n) q.push(i);
  cnt = 0;
  memset(check, false, sizeof(check));
  while (!q.empty()) {
    long u = q.top();
    q.pop();
    if (check[u]) return false;
    check[u] = true;
    order[u] = ++cnt;
    FOR(i, 0, sz(neighbor[u]) - 1) {
      long v = neighbor[u][i];
      deg[v]--;
      q.push(v);
    }
  }
  return true;
}

int main() {
	fio;
  cin >> n >> m;
  long maxc = 0;
  FOR(i, 1, m) {
    cin >> u[i] >> v[i] >> c[i];
    maxc = max(maxc, c[i]);
  }
  long l = 0;
  long r = maxc;
  while (l <= r) {
    long mid = (l + r) / 2;
    if (ok(mid)) r = mid - 1;
    else l = mid + 1;
  }
  cout << l << " ";
  ok(l);
  cnt = 0;
  FOR(i, 1, m) if (order[u[i]] > order[v[i]] && c[i] <= l) res[++cnt] = i;
  cout << cnt << '\n';
  FOR(i, 1, cnt) cout << res[i] << " ";
	return 0;
}
