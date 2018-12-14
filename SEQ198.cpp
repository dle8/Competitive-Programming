#include <bits/stdc++.h>
#define maxm 2000+10
#define maxa 109+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

struct node {
	long v, next;
};

node table[2*1000*1000+10];
long head[maxa], a[maxm], sl[maxa], d[maxa];
long m, index;
bool exist[maxa], check[maxa];

class pq {
	public: 
		long heap[maxa], cs[maxa], heapSize;
		
	pq() {
		heapSize = 0;
		memset(cs, 0, sizeof(cs));
	}
	
	/*void init() {
		heapSize = 0;
		memset(cs, 0, sizeof(cs));
	} */
	
	bool empty() {
		return (heapSize==0);
	}
	
	void update(long u) {
		if (cs[u]==0) {
			heapSize++;
			heap[heapSize] = u;
			cs[heap[heapSize]] = heapSize;
		}
		upHeap(cs[u]);
	}
	
	void upHeap(long index) {
		long temp = heap[index];
		while (true) {
			long parent = index/2;
			if (parent==0 || d[heap[parent]]>=d[temp]) break;
			heap[index] = heap[parent];
			cs[heap[index]] = index;
			index = parent;
		}
		heap[index] = temp;
		cs[heap[index]] = index;
	}
	
	long peek() {
		return (heap[1]);
	}
	
	void poll() {
		cs[heap[1]] = 0;
		heap[1] = heap[heapSize];
		cs[heap[1]] = 1;
		heapSize--;
		downHeap(1);
	}
	
	void downHeap(long index) {
		long temp = heap[index];
		while (true) {
			long child = 2*index;
			if (child<heapSize && d[heap[child]]<d[heap[child+1]]) child++;
			if (child>heapSize || d[temp]>=d[heap[child]]) break;
			heap[index] = heap[child];
			cs[heap[index]] = index;
			index = child;
		}
		heap[index] = temp;
		cs[heap[index]] = index;
	}
};

void addAdjacent(long u, long v) {
	index++;
	table[index].v = v;
	table[index].next = head[u];
	head[u] = index;
	
	index++;
	table[index].v = u;
	table[index].next = head[v];
	head[v] = index;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long u, v, count;
	cin >> m;
	memset(exist, false, sizeof(exist));
	FOR(i, 1, m) {
		cin >> a[i];
		sl[a[i]]++;
		exist[a[i]] = true;
	}
	
	sort(a+1, a+1+m);
	index = 0;
	FOR(i, 1, m) {
		if (exist[a[i]+1]) addAdjacent(a[i], a[i]+1);
		if (exist[a[i]+8]) addAdjacent(a[i], a[i]+8);
		if (exist[a[i]+9]) addAdjacent(a[i], a[i]+9);
	}
	
	memset(check, false, sizeof(check));
	FOR(i, 1, m) {
		if (check[a[i]]) continue;
		else check[a[i]] = true;
		long j = head[a[i]];
		while (j!=0) {
			v = table[j].v;
			d[a[i]]+=sl[v];
			j = table[j].next;
		}
	}
	
	pq q;
	FOR(i, 1, m) q.update(a[i]);
	while (true) {
		u = q.peek();
		q.poll();
		if (d[u]==0) break;
		count++;
		
		long j = head[u];
		while (j!=0) {
			v = table[j].v;
			d[v]--;
			q.update(v);
			j = table[j].next;
		}
	}
	
	cout << count;
	return 0;
}
