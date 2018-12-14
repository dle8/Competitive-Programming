#include <iostream>
#include <string.h>
#define maxn 300+10
using namespace std;
int n, dem;

struct edge {
	int v, c, next;
};

edge roads[2*maxn*maxn];
bool check[maxn];
int d[maxn], head[maxn];

void swap(int&a, int&b) {
	int temp = a;
	a = b;
	b = temp;
}

class pq {
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
	
	void update(int p) {
		if (cs[p] == 0) {
			heapSize++;
			heap[heapSize] = p;
			cs[p] = heapSize;
			upHeap(heapSize);
		}
		else upHeap(cs[p]);
	}
	
	void upHeap(int index) {
		if (index>1) {
			if (d[heap[index/2]]>d[heap[index]]) {
				swap(heap[index/2], heap[index]);
				swap(cs[heap[index/2]], cs[heap[index]]);
				upHeap(index/2);
			}
		}
	}
	
	void poll() {
		swap(cs[heap[1]], cs[heap[heapSize]]);
		swap(heap[1], heap[heapSize]);
		cs[heap[heapSize]] = 0;
		heapSize--;
		downHeap(1);
	}
	
	void downHeap(int index) {
		int smallerChild;
		int left = 2*index;
		int right = 2*index+1;
		if (left>heapSize) return;
		if (right>heapSize) smallerChild = left;
		else {
			if (d[heap[left]]>d[heap[right]]) smallerChild = right;
			else smallerChild = left;
		}
		if (d[heap[index]]>d[heap[smallerChild]]) {
			swap(heap[index], heap[smallerChild]);
			swap(cs[heap[index]], cs[heap[smallerChild]]);
			downHeap(smallerChild);
		}
	}
};

void prim() {
	int soDinhTrongKhung, v, u;
	long weight;
	for (int i=1; i<=(n+1); i++) d[i] = 1000000000;
	memset(check, true, sizeof(check));
	d[1] = 0;
	soDinhTrongKhung = 0;
	pq queue;
	queue.init();
	queue.update(1);
	weight = 0;
	while (!queue.empty()) {
		u = queue.peek();
		queue.poll();
		check[u] = false;
		weight+=d[u];
		soDinhTrongKhung++;
		if (soDinhTrongKhung == (n+1)) break;
		
		int i = head[u];
		while (i!=0) {
			v = roads[i].v;
			if (check[v]) {
				d[v] = min(d[v], roads[i].c);//d[v] dc update bang min d[v] hoac canh cua v voi dinh u vua duoc add vao cay khung
				queue.update(v);	
			}
			i = roads[i].next;
		}
	}
	cout << weight;
}

int main() {
	int input, w;
	cin >> n;
	dem = 0;
	for (int i=1; i<=n; i++){
		dem++;
		cin >> w;
		roads[2*dem].v = i;
		roads[2*dem].c = w;	
		roads[2*dem].next = head[n+1];
		head[n+1] = 2*dem;
		
		roads[2*dem+1].v = n+1;
		roads[2*dem+1].c = w;
		roads[2*dem+1].next = head[i];
		head[i] = 2*dem+1;
	} 
	
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=n; j++) {
			if (i>j) {
				dem++;
				roads[2*dem].v = j;
				cin >> roads[2*dem].c;
				roads[2*dem].next = head[i];
				head[i] = 2*dem;
				
				roads[2*dem+1].v = i;
				roads[2*dem+1].c = roads[2*dem].c;
				roads[2*dem+1].next = head[j];
				head[j] = 2*dem + 1;
			}
			else cin >> input;
		}
	prim();
	return 0;
}
