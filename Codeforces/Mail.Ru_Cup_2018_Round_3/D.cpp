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

#define maxn 100000 + 10

struct node {
	long v;
	node* next;
};

node* head[maxn];
long leafNode[maxn], a[maxn];

void dfs(long u) {
	node* p = head[u];
	bool isLeaf = true;
	while (p != nullptr) {
		isLeaf = false;
		long v = p->v;
		dfs(v);
		leafNode[u] += leafNode[v];
		p = p->next;
	}
	if (isLeaf) leafNode[u] = 1;
}

int main() {
	fio;

	long n, pi;
	cin >> n;
	node* p;
	FOR(i, 2, n) {
		cin >> pi;
		p = new node;
		p->v = i;
		p->next = head[pi];
		head[pi] = p;
	}

	dfs(1);

	FOR(i, 1, n) a[i] = i;
	sort(a + 1, a + 1 + n, [](long u, long v) {
		return leafNode[u] < leafNode[v];
	});

	FOR(i, 1, n) cout << leafNode[a[i]] << " ";

	return 0;
}
