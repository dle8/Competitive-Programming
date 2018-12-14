#include <bits/stdc++.h>
#include <string>
#include <string.h>
#include <map>
#define maxHeap 100000+10
using namespace std;

class heapMin {
	public:
		int heap[maxHeap];
		int heapSize;
	
	void init() {
		heapSize = 0;
	}
	
	void add(int p) {
		heapSize++;
		heap[heapSize] = p;
		upHeap(heapSize);
	}
	
	void upHeap(int index) {
		int temp = heap[index];
		while (true) {
			int parent = index/2;
			if (parent==0 || heap[parent]<=temp) break;
			heap[index] = heap[parent];
			index = parent;
		}
		heap[index] = temp;
	}
	
	int peek() {
		return heap[1];	
	}
	
	void poll() {
		heap[1] = heap[heapSize];
		heapSize--;
		downHeap(1);
	}
	
	void downHeap(int index) {
		int temp = heap[index];
		while (true) {
			int child = index*2;
			if (child<heapSize && heap[child]>heap[child+1]) child++;
			if (child>heapSize || temp<=heap[child]) break;
			heap[index] = heap[child];
			index = child;
		}
		heap[index] = temp;
	}
	
	bool empty() {
		return (heapSize == 0);
	}
};

class heapMax {
	public:
		int heap[maxHeap];
		int heapSize;
	
	void init() {
		heapSize = 0;
	}
	
	bool empty() {
		return (heapSize==0);
	}
	
	int peek() {
		return heap[1];
	}
	
	void add(int p) {
		heapSize++;
		heap[heapSize] = p;
		upHeap(heapSize);
	}
	
	void upHeap(int index) {
		int temp = heap[index];
		while (true) {
			int parent = index/2;
			if (parent==0 || heap[parent]>=temp) break;
			heap[index] = heap[parent];
			index = parent;
		}
		heap[index] = temp;
	}
	
	void poll() {
		heap[1] = heap[heapSize];
		heapSize--;
		downHeap(1);
	}
	
	void downHeap(int index) {
		int temp = heap[index];
		while (true) {
			int child = 2*index;
			if (child<heapSize && heap[child]<heap[child+1]) child++;
			if (child>heapSize || heap[child]<=temp) break;
			heap[index] = heap[child];
			index = child;
		}
		heap[index] = temp;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int space1, space2, k, p, Tcase;
	heapMin hmin;
	hmin.init();
	heapMax hmax;
	hmax.init();
	map<int, int> myMap;
	map<int, bool> inHeap;
	while (true) {
		cin>>Tcase;
		if (Tcase==0) break;
		if (Tcase==1){
			cin>>k>>p;
			myMap[p] = k;
			hmax.add(p);
			hmin.add(p);
			inHeap[p] = true;
		}
		if (Tcase==2) {
			while (!hmax.empty() && inHeap[hmax.peek()]==false) hmax.poll();
			if (hmax.empty()) cout << 0 << endl;
			else {
				cout << myMap[hmax.peek()] << endl;
				inHeap[hmax.peek()] = false;
				hmax.poll();
			}
		}
		if (Tcase==3) {
			while (!hmin.empty() && inHeap[hmin.peek()]==false) hmin.poll();
			if (hmin.empty()) cout << 0 << endl;
			else {
				cout << myMap[hmin.peek()] << endl;
				inHeap[hmin.peek()] = false;
				hmin.poll();
			}
		}
	}
	return 0;
}
