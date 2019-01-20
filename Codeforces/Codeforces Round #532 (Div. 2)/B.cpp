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
long a[maxn], d[maxn];

class pq{
	public:
		int heap[maxn], cs[maxn];
		int heapSize;

	void init() {
		heapSize = 0;
		memset(cs, 0, sizeof(cs));
	}

	int peek() {
		return heap[1];
	}

	bool empty() {
		return (heapSize == 0);
	}

	void update(int p, long c) {
		if (cs[p]==0) {
			heapSize++;
			heap[heapSize] = p;
			cs[p] = heapSize;
		}
		if (c == 1) upHeap(cs[p]);
    else downHeap(cs[p]);
	}

	void upHeap(int index) {
		int temp = heap[index];
		while (true){
			int parent = index/2;
			if (parent==0 || d[heap[parent]]<=d[temp]) break;
			heap[index]=heap[parent];
			cs[heap[index]]=index;
			index=parent;
		}
		heap[index]=temp;
		cs[heap[index]]=index;
	}

	void poll() {
		cs[heap[1]] = 0;
		cs[heap[heapSize]] = 1;
		swap(heap[1], heap[heapSize]);
		heapSize--;
		downHeap(1);
	}

	void downHeap(int index) {
		int temp = heap[index];
		while (true){
			int child = index*2;
			if (child<heapSize && d[heap[child]]>d[heap[child+1]]) child++;
			if (child>heapSize || d[temp]<=d[heap[child]]) break;
			heap[index]=heap[child];
			cs[heap[index]]=index;
			index=child;
		}
		heap[index]=temp;
		cs[heap[index]]=index;
	}
};


int main() {
	fio;
  long n, m;
  cin >> n >> m;
  FOR(i, 1, m) cin >> a[i];
  pq q;
  q.init();
  FOR(i, 1, n) q.update(i, 1);
  long cnt = 1;
  FOR(i, 1, m) {
    d[a[i]]++;
    q.update(a[i], 2);
    long u = q.peek();
    if (d[u] >= cnt) {
      cnt++;
      cout << 1;
    }
    else cout << 0;
  }
	return 0;
}
