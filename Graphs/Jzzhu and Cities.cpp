/*
Author: Dung Tuan Le
University of Rochester
*/

#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define FORALL(iter, x) for (auto iter = x.begin(); iter != x.end(); iter++)
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;

typedef long long ll;

#define maxn 100000 + 10
#define maxm 300000 + 10
const ll inf = 1e18;
ll n, m, k, d[maxn], cnt[maxn];
vector<pair<ll, ll>> adj[maxn];
pair<ll, ll> train[maxm];
bool check[maxn];

class PQ{
	public:
		ll heap[2 * maxn], cs[2 * maxn];
		ll heapSize;

	void init() {
		heapSize = 0;
		memset(cs, 0, sizeof(cs));
	}

	ll top() {
		return heap[1];
	}

	bool empty() {
		return (heapSize == 0);
	}

	void update(int p) {
		if (cs[p]==0) {
			heapSize++;
			heap[heapSize] = p;
			cs[p] = heapSize;
		}
		upHeap(cs[p]);
	}

	void upHeap(int index) {
		ll temp = heap[index];
		while (true){
			ll parent = index/2;
			if (parent==0 || d[heap[parent]]<=d[temp]) break;
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
		swap(heap[1], heap[heapSize]);
		heapSize--;
		downHeap(1);
	}

	void downHeap(int index) {
		ll temp = heap[index];
		while (true){
			ll child = index*2;
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

void dijkstra() {
  FOR(i, 1, n) d[i] = inf;
  d[1] = 0;
  PQ pq;
	pq.init();
	pq.update(1);
  while (!pq.empty()) {
    ll u = pq.top();
    pq.pop();
    FOR(i, 0, sz(adj[u]) - 1) {
      pair<ll, ll> p = adj[u][i];
      if (d[p.fi] > d[u] + p.se) {
        d[p.fi] = d[u] + p.se;
        pq.update(p.fi);
      }
    }
  }
}

int main() {
	fio;
  cin >> n >> m >> k;
  FOR(i, 1, m) {
    ll u, v, x;
    cin >> u >> v >> x;
    adj[u].pb({v, x});
    adj[v].pb({u, x});
  }
	set<pair<ll, ll>> mset;
	map<pair<ll, ll>, ll> duplicate;
  FOR(i, 1, k) {
		ll v, len;
		cin >> v >> len;
		mset.insert({v, len});
		duplicate[{v, len}]++;
  }
	for (auto iter = mset.begin(); iter != mset.end(); iter++) {
		pair<ll, ll> p = (*iter);
		adj[1].pb({p.fi, p.se});
		adj[p.fi].pb({1, p.se});
	}
  dijkstra();
  memset(cnt, 0, sizeof(cnt));
  FOR(i, 1, n) {
    FOR(j, 0, sz(adj[i]) - 1) {
      ll v = adj[i][j].fi;
      if (d[i] == d[v] + adj[i][j].se) cnt[i]++;
    }
  }
  ll res = 0;
	for (auto iter = mset.begin(); iter != mset.end(); iter++) {
		pair<ll, ll> p = (*iter);
		ll v = p.fi;
		ll len = p.se;
		if (len > d[v]) res += duplicate[p];
		else if (len == d[v]) {
			if (cnt[v] > 1) res += duplicate[p];
			else res += (duplicate[p] - 1);
		}
	}
  cout << res;
	return 0;
}
