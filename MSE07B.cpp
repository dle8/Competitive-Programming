#include <bits/stdc++.h>
#include <string.h>
#define maxp 10000000+10
using namespace std;

int maso[maxp];

typedef struct node{
	int data;
	struct node left, right, parent;
} node;

class BST{
	public:
		node* root;
		int heapSize;
	
	void init() {
		heapSize = 0;
	}
	
	void add(int p) {
		node newelem;
		if (heapSize==0) {
			newelem.data = p;
			root = newelem;
			heapSize++;
			return;
		}
		heapSize++;
		node g = root;
		while (true){
			if (p>g.data) {
				if (g.right) break;//if g.right is not null
				g = g.right;
			}
			else {
				if (g.left) break;
				g = g.left;
			}
		}
		newelem.data = p;
		if (p>g.data) {
			newelem.parent = g;
			g.right = newelem;
		}
		else {
			newelem.parent = g;
			g.left = newelem;
		}
	}
	
	bool empty() {
		return (heapSize == 0);
	}
	
	int pollMax() {
		int result;
		node g = root;
		while (!g.right) g = g.right;
		result = g.data;
		heapSize--;
		if (g.parent) {
			root = g.left;
			if (!root) root.parent;
			return result;
		}
		g.parent.right = g.left;
		if (!g.left) g.left.parent = g.parent;
		return result;
	}
	
	int pollMin() {
		int result;
		node g = root;
		while (!g.left) g = g.left;
		result = g.data;
		heapSize--;
		if (g.parent) {
			root = g.right;
			if (!root) root.parent;
			return result;
		}
		g.parent.left = g.right;
		if (!g.right) g.right.parent = g.parent;
		return result;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int k, p, space1, space2;
	string input;
	BST bst;
	bst.init();
	while (getline(cin, input)) {
		if (input=="0") break;
		if (input=="2") {
			if (bst.empty()) cout << 0 << endl;
			else cout << maso[bst.pollMax()];
			continue;
		}
		if (input=="3") {
			if (bst.empty()) cout << 0 << endl;
			else cout << maso[bst.pollMin()];
			continue;
		}
		space1 = input.find(" ");
		space2 = input.rfind(" ");
		k = stoi(input.substr(space1, space2));
		p = stoi(input.substr(space2+1));
		bst.add(p);
		maso[p] = k;
	}		
	return 0;
}
