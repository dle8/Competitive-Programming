#include <bits/stdc++.h>
using namespace std;

typedef struct node {
	long val, chiso;
	node* left;
	node* right;
	node* parent;
	node(){};
	node(long val1, long chiso1, node* left1, node* right1, node* parent1) {
		val = val1;
		chiso = chiso1;
		left = left1;
		right = right1;
		parent = parent1;
	}	
};

class BinarySearchTree {
	public:
		node* root;
	
	BinarySearchTree(){
		root = nullptr;
	}
	
	void add(long x) {
		if (root==nullptr) root = new node(x, -1, nullptr, nullptr, nullptr);
		else {
			if (root->val>=x) add(root, root->left, x, 1);
			else add(root, root->right, x, 2);
		}
	}
	
	void add(node* parent, node* child, long x, long chiso) {
		if (child==nullptr) child = new node(x, chiso, nullptr, nullptr, parent);
		else {
			if (child->val>=x) add(child, child->left, x, 1);
			else add(child, child->right, x, 2);				
		}
	}
	
	void del(long x) {
		if (root!=nullptr) {
			if (root->val>=x) del(root, root->left, x, 1);
			else del(root, root->right, x, 2);
			cout << "yes" << "\n";
		}
	}
	
	void del(node* parent, node* child, long x, long chiso) {
		if (child->val==x) {
			if (child->left==nullptr && child->right==nullptr) {
				if (chiso==1) parent->left = nullptr;
				else parent->right = nullptr;
				return;
			}
			if (child->left==nullptr || child->right==nullptr) {
				if (chiso==1) parent->left = (child->left==nullptr) ? child->right : child->left;
				else parent->right = (child->left==nullptr)? child->right : child->left;
				return;
			}
			//long predecessor = pred2(x);
			else {
				long successor = succ2(x);//no chac chan co successor boi child->right!=nullptr
				del(successor);
				child->val = successor;	
			}
		}
		else {
			if (child->val>x) del(child, child->left, x, 1);
			else del(child, child->right, x, 2);
		}
	}
	
	long succ(long x) {//tim thg min ma >x
		if (root==nullptr) return (x-2);//x-2 means the set is empty
		if (root->val>x) return succ(root, root->left, x);
		else return succ(root, root->right, x);
	}
	
	long succ(node* parent, node* child, long x) {
		if (x<child->val) {
			if (child->left==nullptr) return child->val;
			else return succ(child, child->left, x);
		}
		else {//if (child->val<=x)
			if (child->right==nullptr) return (x-1);//x-1 means the longing value dne
			else return succ(child, child->right, x);
		}
	}
	
	long succ2(long x) {//tim thg min>=x
		if (root==nullptr) return (x-2);
		if (x<root->val) return succ2(root, root->left, x);
		else return succ2(root, root->right, x);
	}
	
	long succ2(node* parent, node* child, long x) {
		if (x<child->val) {
			if (child->left==nullptr) return child->val;
			else return succ2(child, child->left, x);
		}
		else {//if (child->val<=x)
			if (child->right==nullptr) {
				if (child->val==x) return child->val;
				else return (x-1);
			}
			else return succ2(child, child->right, x);
		}
	}
	
	long pred(long x) {//tim thg max<x
		if (root==nullptr) return (x+2);
		if (root->val>x) return pred(root, root->left, x+1, x);
		else return pred(root, root->right, x+1, x);
	}
	
	long pred(node* parent, node* child, long diff, long x) {
		if (x<child->val) {
			if (child->left==nullptr) return (x+1);//cho prec2 la so sanh<=
			else return pred(child, child->left, diff, x);
		}
		else {//if (child->val<=x)
			if (child->val!=x) diff = child->val;
			if (child->right==nullptr) return diff;
			else return pred(child, child->right, diff, x);
		}
	}
	
	long pred2(long x) {//tim max ma <=x
		if (root==nullptr) return (x+2);
		if (root->val>x) return pred2(root, root->left, x);
		else return pred2(root, root->right, x);
	}
	
	long pred2(node* parent, node* child, long x) {
		if (x<child->val) {
			if (child->left==nullptr) return (x+1);
			else return pred2(child, child->left, x);
		}
		else {//if(child->val<=x)
			if (child->right==nullptr) return child->val;
			else return pred2(child, child->right, x);
		}
	}
	
	bool empty() {
		return (root == nullptr);
	}
	
	long min() {
		return getMin(root);
	}
	
	long getMin(node* parent) {
		if (parent->left==nullptr) return parent->val;
		else cout << parent->left->val << "\n";
			return getMin(parent->left);
	}
	
	long max() {
		return getMax(root);
	}
	
	long getMax(node* parent) {
		if (parent->right==nullptr) return parent->val;
		else return getMax(parent->right);
	}
	
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long res, command, x;
	BinarySearchTree bst;
	while (true) {
		cin >> command;
		if (command == 0) break;
		if (command == 1) {
			cin >> x;
			bst.add(x);
		}
		if (command == 2) {
			cin >> x;
			bst.del(x);
		}
		if (bst.empty()) {
			cout << "empty" << "\n";
			continue;
		}
		if (command == 3) cout << bst.min() << "\n";
		if (command == 4) cout << bst.max() << "\n";
		if (command == 5) {
			res = bst.succ(x);
			if (res<x) cout << "no" << "\n";
			else cout << res << "\n";
		}
		if (command == 6) {
			res = bst.succ2(x);
			if (res<x) cout << "no" << "\n";
			else cout << res << "\n";
		}
		if (command == 7) {
			res = bst.pred(x);
			if (res>x) cout << "no" << "\n";
			else cout << res << "\n";
		}
		if (command == 8) {
			res = bst.pred2(x);
			if (res>x) cout << "no" << "\n";
			else cout << res << "\n";
		}
	}
	return 0;
}
