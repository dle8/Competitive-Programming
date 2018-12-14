#include <bits/stdc++.h>
#include <math.h>
#define maxn 1000+10
using namespace std;

int n;
long long x[maxn], y[maxn];
double c[maxn][maxn];
double d[maxn];
bool check[maxn];

class heapMin {
	public:
		int heap[maxn];
		int heapSize;
		int cs[maxn];

	void init() {
		heapSize = 0;
		memset(cs, 0, sizeof(cs));
	}
	
	int peek() {
		return heap[1];
	}
	
	bool empty() {
		return (heapSize==0);
	}
	
	void update(int p) {
		if (cs[p]==0) {
			heapSize++;
			heap[heapSize] = p;
			cs[heap[heapSize]] = heapSize;
		}
		upHeap(cs[p]);
	}
	
	void upHeap(int index) {
		int parent;
		int temp = heap[index];
		while (true) {
			parent = index/2;
			if (parent==0 || d[heap[parent]]<=d[temp]) break;
			heap[index] = heap[parent];
			cs[heap[index]] = index;
			index = parent;
		}
		heap[index] = temp;
		cs[heap[index]] = index;
	}
	
	void poll() {
		heap[1] = heap[heapSize];
		cs[heap[1]] = 1;
		heapSize--;
		downHeap(1);
	}
	
	void downHeap(int index) {
		int left;
		int temp = heap[index];
		while (true) {
			left = 2*index;
			if (left<heapSize && d[heap[left]]>d[heap[left+1]]) left++;//tim thang con min
			if (left>heapSize || d[temp]<=d[heap[left]]) break;//neu nhu k co con hoac la thang index > con min cua no -> break
			heap[index] = heap[left];
			cs[heap[index]] = index;
			index = left;
		}
		heap[index] = temp;
		cs[heap[index]] = index;
	}
};

double getDist(int cot1, int cot2) {
	return sqrt((x[cot1]-x[cot2])*(x[cot1]-x[cot2]) + (y[cot1]-y[cot2])*(y[cot1]-y[cot2]));
}

void dijsktra() {
	int u;
	for (int i=1; i<=n; i++) d[i] = 1000000000;
	d[1] = 0;	
	heapMin hm;
	hm.init();
	hm.update(1);
	while (!hm.empty()) {
		u = hm.peek();
		hm.poll();
		if (u==n) break;
		check[u] = false;
		for (int i=1; i<=n; i++) 
			if (c[u][i]!=1000000000) {
				if (check[i] && d[i]>=d[u]+c[u][i]) {
					d[i] = d[u] + c[u][i];
					hm.update(i);		
				}	
			}
	}
	if (d[n]==1000000000) d[n] = -0.001;
	cout << int(d[n]*1000);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int u, v, w;
	double m;
	double temp;
	cin >> n >> w;
	cin >> m;
	
	for (int i=1; i<=n; i++) cin >> x[i] >> y[i];
	
	for (int i=1; i<=n-1; i++) {
		for (int j=i+1; j<=n; j++) {
			temp = getDist(i,j);
			if (temp>m) temp = 1000000000;
			c[i][j] = temp;
			c[j][i] = temp;
		} 
	}
	
	for (int i=1; i<=w; i++) {
		cin >> u >> v;
		c[u][v] = 0;
		c[v][u] = 0;
	}

	memset(check, true, sizeof(check));
	dijsktra();
	return 0;
}
