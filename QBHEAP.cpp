#include <iostream>
#include <string>
#include <string.h>
#include <list>
#define maxn 100000
using namespace std;

void swap(int&a, int&b) {
	int temp = a;
	a = b;
	b = temp;
}

class pq {
	public:
		int heap[maxn];
		int heapSize ;
		 
	void init() {
		heapSize = 0;
	}
	
	bool empty() {
		return (heapSize == 0);
	}
	
	int size() {
		return heapSize;
	}
	
	void add(int elem) {
		heapSize++;
		heap[heapSize] = elem;
		upHeap(heapSize);
	}
	
	void upHeap(int index) {
		if (index>1 && heap[index/2] <= heap[index]) {
			swap(heap[index/2], heap[index]);
			upHeap(index/2);	
		}
	} 

	int peek() {
		return heap[1];
	}	
	
	void poll() {
		swap(heap[1], heap[heapSize]);
		heapSize--;
		downHeap(1);
	}
	
	void downHeap(int index) {
		int left = 2*index;
		int right = 2*index+1;
		int biggerChild;
		if (left>heapSize) return;
		if (right>heapSize) biggerChild = left;
		else {
			if (heap[left]<heap[right]) biggerChild = right;
			else biggerChild = left;
		}
		if (heap[biggerChild] < heap[index]) return;
		swap(heap[biggerChild], heap[index]);
		downHeap(biggerChild);
	}
	
	void print() {
		for (int i=1; i<=heapSize; i++) cout << heap[i] << endl;
	}
};

int main() {
	pq queue;
	int elem, temp;
	list<int> container;
	queue.init();
	string s;
	while (getline(cin, s)) {
		if (s=="") break;
		if (s[0] == '+') {
			elem = stoi(s.substr(1));
			if (queue.size() <15000) queue.add(elem);
		}
		if (s[0] == '-') {
			if (queue.empty()) continue;
			temp = queue.peek();
			while (!queue.empty() && queue.peek() == temp) queue.poll();
		}
	}
	while (!queue.empty()) {
		temp = queue.peek();
		container.push_back(temp);
		while (!queue.empty() && (queue.peek() == temp)) queue.poll();
	}
	cout << container.size() << endl;;
	for (list<int>::iterator it = container.begin(); it!=container.end(); ++it)
		cout << *it << endl;
	return 0;
}
