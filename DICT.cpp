#include <iostream>
#include <set>
#include <string.h>
#include <string>
#include <list>
#define maxn 25000+10
#define FOR(i, l, r) for(int i=l; i<=r; i++)
using namespace std;

long n;
set<string> Set;
set<string>::iterator it;
list<string>::iterator itList;

struct node {
	node* c[255];
	list<string> List;
	
	node() {
		for (char ch='a'; ch<='z'; ch++) c[ch] = nullptr;
		List.clear();
	}
};

class Trie {
	public:
		node* root;
		
	Trie() {
		add(root);
	}
	
	~Trie() {}
	
	void add(node* &p) {
		p = new node;
		for (char ch='a'; ch<='z'; ch++) p->c[ch] = nullptr;
	}
	
	void insert(string s) {
		long lengths = s.length();
		node* p = root;
		FOR(i, 0, lengths-1) {
			if (p->c[s[i]]==nullptr) add(p->c[s[i]]);
			p = p->c[s[i]];
			p->List.push_back(s);
		}
	}
	
	list<string> findPrefix(string s) {
		long lengths = s.length();
		node* p = root;	
		list<string> empty;
		FOR(i, 0, lengths-1) {
			if (p->c[s[i]]==nullptr) return empty;
			p = p->c[s[i]];
		}
		
		return p->List;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long k;
	list<string> res;
	string s;
	cin >> n;
	FOR(i, 1, n) {
		cin >> s;
		Set.insert(s);
	}
	
	Trie trie;
	for(it=Set.begin(); it!=Set.end(); ++it) trie.insert(*it);
	
	cin >> k;
	FOR(i, 1, k) {
		cin >> s;
		res = trie.findPrefix(s);
		cout << "Case #" << i << ":" << "\n";
		if (res.empty()) cout << "No match." << "\n";
		else {
			for (itList=res.begin(); itList!=res.end(); itList++) if (*itList!=s) cout << *itList << "\n";
		}
	}
	
	return 0;
}
