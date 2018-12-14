#include <bits/stdc++.h>
#include <list>
#include <queue>
using namespace std;

int n;
string s, t;
map<string, list<int>> mymap;
map<string, list<int>>::iterator it;

bool bfs() {
	list<int> newlist;
	string temp;
	char c;
	queue<string> q;
	q.push(s);
	mymap.insert(pair<string, list<int>>(s, newlist));
	while (true) {
		string str = q.front();
		q.pop();
		it = mymap.find(str);
		if(mymap[str].size()+1>10000 || it==mymap.end()) continue;
		if (str==t) return true;
		temp = str;
	//	cout << str  << endl;
		for (int i=0; i<(n-1); i++) {
			str = temp;
			c = str[i];
			str[i] = str[i+1];
			str[i+1] = c;
			newlist = mymap[temp];
			newlist.push_back(i+1);
			mymap.insert(pair<string, list<int>>(str, newlist));
			q.push(str);	
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> s >> t;
	bool found = bfs();
	if (!found) cout << -1;
	else {
		cout << mymap[t].size() << endl;
		for (list<int>::iterator iter=mymap[t].begin(); iter!=mymap[t].end(); ++iter) {
			cout << *iter << " ";
		}
	}
	return 0;
}
