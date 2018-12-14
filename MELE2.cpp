#include <bits/stdc++.h>
#define maxn 100000+10
#define maxc 1000000000000000000+10
using namespace std;

long rb, rc, a, b, c;	
long long h, d[maxn];

class pq{
	public:
		long heap[maxn], cs[maxn];
		long heapSize;
		
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
	
	void update(int p) {
		if (cs[p]==0) {
			heapSize++;
			heap[heapSize] = p;
			cs[p] = heapSize;
		}
		upHeap(cs[p]);
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

void dijkstra() {
	long u, vb, vc;
	pq q;
	q.init();
	rb = b%a;
	rc = c%a;
	for (int i=0; i<a; i++) d[i] = maxc;
	d[0] = 0;
	q.update(0);
	while (!q.empty()) {
		u = q.peek();
		q.poll();
		
		vb = (u+rb)%a;
		if (d[vb]>d[u]+b) {
			d[vb] = d[u]+b;
			q.update(vb);
		}
		
		vc = (u+rc)%a;
		if (d[vc]>d[u]+c) {
			d[vc] = d[u]+c;
			q.update(vc);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long rb, rc, count, r;
	long long temp, res, k;
	cin >> h >> a >> b >> c;
	
	dijkstra();
	
	res = 0;
	temp = h-h%a;
	for (int i=0; i<a; i++) {
		if (d[i]>h) continue;//tao ra duoc so chia a du i+1 vi dang dung o bac thang 1
		k = temp+(i+1);
		if (k>h) k-=a;
		res+=((k-d[i]-1)/a+1);
	}	
	cout << res;
	return 0;
}
