#include <bits/stdc++.h>
#include <string.h>
#define maxm 200000+100
#define maxn 200000+100
using namespace std;

struct room {
	int num, mau;
};

struct hanglang {
	room v;
	int c, next;
};

hanglang hall[2*maxm];

int n,m;
int path[maxn], result[maxn], trace[maxn], d[maxn], head[maxn];
bool check[maxn];

void swap(room&a, room &b) 
{
	room temp = a;
	a = b;
	b = temp;
}

class pq {
	public:
		room heap[maxn];
		int heapSize;
	
	void init() {
		heapSize = 0;
	}
	
	void add(room r) {
		heapSize++;
		heap[heapSize] = r;
		upHeap(heapSize);
	}
	
	void upHeap(int index) {
		if (index>1) {
			if (d[heap[index/2].num] > d[heap[index].num]) {
				swap(heap[index/2], heap[index]);
				upHeap(index/2);
			}
			else if (d[heap[index/2].num] == d[heap[index].num]) {
				if (heap[index/2].mau > heap[index].mau) {
					swap(heap[index/2], heap[index]);
					upHeap(index/2);
				}
			}
		}
	}
	
	bool empty() {
		return (heapSize == 0);
	}
	
	room peek() {
		return heap[1];
	}
	
	void poll() {
		swap(heap[1], heap[heapSize]);
		heapSize--;
		downHeap(1);
	}
	
	void downHeap(int index) {
		int smallerChild;
		int left = 2*index;
		int right = 2*index+1;
		if (left>heapSize) return;
		if (right>heapSize) smallerChild = left;
		else{
			if (d[heap[left].num] > d[heap[right].num]) smallerChild = right;
			else if (d[heap[left].num] < d[heap[right].num]) smallerChild = left;
			else {
				if (heap[left].mau > heap[right].mau) smallerChild = right;
				else smallerChild = left;
			}
		}
		if (d[heap[index].num] < d[heap[smallerChild].num]) return;
		if (d[heap[index].num] > d[heap[smallerChild].num]) {
			swap (heap[index], heap[smallerChild]);
			downHeap(smallerChild);
		}
		else if (d[heap[index].num] == d[heap[smallerChild].num] && heap[index].mau > heap[smallerChild].mau){
			swap(heap[index], heap[smallerChild]);
			downHeap(smallerChild);
		}
	}
};

int min(int a, int b) {
	if (a<=b) return a;
	else return b;
}

void dijkstra()
{
	int k, dem;
	room u, v;
	pq queue;
	
	memset(check, true, sizeof(check));
	for (int i=1; i<=n; i++) {
		d[i] = 1000000000;
		result[i] = 1000000000+10;	
	}
	d[1] = 0;

	u.num = 1;
	queue.init();
	queue.add(u);

	while (!queue.empty()) {
		room temp = queue.peek();
		queue.poll();
		while (!queue.empty() && queue.peek().num == temp.num) queue.poll();
		check[temp.num] = false;//danh dau phong nay da di qua
		int i = head[temp.num];
		while (i!=0) {
			v = hall[i].v;
			if (check[v.num]) {
				if (d[v.num] >= d[temp.num] + hall[i].c) {
					d[v.num] = d[temp.num] + hall[i].c;
					trace[v.num] = temp.num;
					result[v.num] = min(result[v.num], v.mau);	
				}
				queue.add(v);
			}
			i = hall[i].next;
		}
	}
	
//	for (int i=1; i<=n; i++) cout << result[1] << endl;
	
	cout << d[n] << endl;
	k = n;
	dem = 0;
	while (k!=1) {
		dem++;
		path[dem] = result[k];
		k = trace[k];
	}
	
	for (int i=dem; i>=1; i--) cout << path[i] << " ";
}

int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int u, v, mau;
	cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		cin >> u >> v >> mau;
		room r;
		r.num = v;
		r.mau = mau;
		
		hall[2*i].v = r;
		hall[2*i].c = 1;
		hall[2*i].next = head[u];
		head[u] = 2*i;
		
		r.num = u;
		
		hall[2*i+1].v = r;
		hall[2*i+1].c = 1;
		hall[2*i+1].next = head[v];
		head[v] = 2*i+1;
	}
	
	dijkstra();
	return 0;
}
