/*
Author: Dung Tuan Le
University of Rochester
Created: 08/30/2018
*/

#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define oo 1000000000
using namespace std;

struct node {
	long count;
	node* c[255];
	
	node() {
		FOR(i, 0, 254) c[i] = nullptr; 
	}
};

long n;

class Trie {
	public:
		node* root;
		
	Trie() {
		add(root);
	}		

	~Trie() {}
	
	void add(node* &p) {
		p = new node;
		p->count = 0;
		for (char ch='a'; ch<='z'; ch++) p->c[ch] = nullptr;
	}
	
	void insert(string s) {
		long lengths = s.length();
		node* p = root;
		FOR(i, 0, lengths-1) {
			if (p->c[s[i]]==nullptr) add(p->c[s[i]]);
			p = p->c[s[i]];
		}
		p->count++;
	}
	
	bool find(string s) {
		long lengths = s.length();
		node* p = root;
		FOR(i, 0, lengths-1) {
			if (p->c[s[i]]==nullptr) return false;
			p = p->c[s[i]];
		}
		return (p->count>0);
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	cin >> n;
	Trie trie;
	FOR(i, 1, n) {
		cin >> s;
		trie.insert(s);
	}

	FOR(i, 1, n) {
		cin >> s;
		if (trie.find(s)) cout << s << " added into trie";
		else cout << s << " not added into trie";
		//cout << trie.find(s) << "\n";
		cout << "\n";
	}
	return 0;
}
