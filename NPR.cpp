#include <bits/stdc++.h>
#define FORU(i, l, r) for (int i=l; i<=r; i++)
#define FORD(i, l, r) for (int i=l; i>=r; i--)
using namespace std;

struct node {
	long count;
	node* c[255];
};

class Trie {
	public:
		node* root;
	
	Trie() {
		add(root);
	}
	
	void add(node* &p) {
		p = new node;
		p->count = 0;
		for (char ch='a'; ch<='z'; ch++) p->c[ch] = nullptr;
	}
	
	void insert(string s) {
		long lengths = s.length();
		node* p = root;
		FORD(i, lengths-1, 0) {
			if (p->c[s[i]]==nullptr) add(p->c[s[i]]);
			p = p->c[s[i]];
		}
		p->count++;
	}
	
	string getNPR(string s) {
		long diffAt;
		long lengths = s.length();
		node* tmp; node* p = root;
		string res = "";
		FORD(i, lengths-1, 0) {
			if (p->c[s[i]]==nullptr) break;
			for (char ch = 'a'; ch<='z'; ch++) {
				if (p->c[s[i]]!=nullptr && ch!=s[i]) {
					tmp = p->c[s[i]];
					diffAt = i;
				}
			}
			res = s[i] + res;
			p = p->c[s[i]];
		}
		
		if (res==s) {
			res = res.substr(lengths-diffAt);
			for (char ch = 'a'; ch<='z'; ch++) {
				if (p->c[s[diffAt]]!=nullptr && ch!=s[diffAt]) {
					res = ch + res;
					break;
				}
			}
			bool flag = false;
			p = tmp;
			while (true) {
				flag = true;
				for (char ch = 'a'; ch<='z'; ch++) {
					if (p->c[ch]!=nullptr) {
						p = p->c[ch];
						flag = false;
						break;	
					}
				}
				
				if (flag) break;
			}
		}
		return res;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	Trie trie;
	while (true) {
		getline(cin, s);
		if (s=="") break;
		trie.insert(s);
	}

	while (true) {
		getline(cin, s);
		if (s=="") break;
		cout << trie.getNPR(s) << "\n";
	}
	
	return 0;
}
