#include <bits/stdc++.h>
#include <list>
#define maxn (1<<16)+100
using namespace std;

int d[maxn];

void swap(int&a, int&b){
	int temp = a;
	a = b;
	b = temp;
}

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

int setBit(int c, int k, int x) {
	if (c==1) x = (x | (1<<(k-1)));
	else x = (x & (!(1<<(k-1))));
	return x;
}

int getBit(int i, int j) {
	return ((i>>(j-1))&1);
}

list<int> getBoard(int board) {
	int temp;
	temp = 0;
	list<int> boardList;
	for (int j=1; j<=16; j++) 
		if (getBit(board, j)==1) {
			if (j+4<=16 && getBit(board, j+4)==0) {//1 goes up
				temp = board-(1<<(j-1));
				temp = temp+(1<<(j+4-1));
				boardList.push_back(temp);
			}
			
			if (j-4>=1 && getBit(board, j-4)==0) {
				temp = board -(1<<(j-1));
				temp = temp+ (1<<(j-4-1));
				boardList.push_back(temp);
			}
			
			if (j%4!=0 && getBit(board, j+1) == 0){
				temp = board - (1<<(j-1));
				temp = temp+(1<<(j+1-1));
				boardList.push_back(temp);
			}
			
			if (j%4!=1 && getBit(board, j-1)==0) {
				temp = board - (1<<(j-1));
				temp = temp+ (1<<(j-1-1));
				boardList.push_back(temp);
			}
		}
		
	return boardList;
}

void dijkstra(int s, int t) {
	int u, v;
	bool check[maxn];
	list<int> boards;//get the board that is one-swap away from the original board
	pq queue;
	memset(check, true, sizeof(check));
	for (int i=1; i<=(1<<16); i++) d[i] = 1000000000;
	d[s] = 0;
	queue.init();
	queue.update(s);
	
	while (!queue.empty()) {
		u = queue.peek();
		queue.poll();
		check[u] = false;
		boards = getBoard(u);
		for (list<int>::iterator iter = boards.begin(); iter!=boards.end(); iter++) {
			if (check[*iter]) {
				if (d[*iter] > d[u]+1) d[*iter] = d[u]+1;
				queue.update(*iter);
			}
		}
	}
	
	cout << d[t];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int s, t;
	string str;
	s = 0;
	for (int i=1; i<=4; i++) {
		cin >> str;
		for (int j=0; j<str.length(); j++) {
			if (str[j]=='1') {
				s+=setBit(1, (16-(i-1)*4-(j+1))+1, 0);
			}
		}	
	}
	t = 0;
	for (int i=1; i<=4; i++) {
		cin >> str;
		for (int j=0; j<str.length(); j++) {
			if (str[j] == '1'){
				t+=setBit(1, (16-(i-1)*4-(j+1))+1, 0);
			}
		}
	}
	dijkstra(s, t);
	return 0;
}
