#include <bits/stdc++.h>
using namespace std;

set<long> Set;
set<long, greater<long>> rSet;
set<long>::iterator it;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long tcase, x;
	while (true) {
		cin >> tcase;
		if (tcase==0) break;
		if (tcase==1) {
			cin >> x;
			Set.insert(x);
			rSet.insert(x);
			continue;
		}
		if (tcase==2) {
			cin >> x;
			Set.erase(x);
			rSet.erase(x);
			continue;
		}
		if (Set.empty()) {
			cout << "empty" << "\n";
			continue;
		}
		if (tcase==3) {
			it = Set.begin();
			cout << *it << "\n";
		}
		if (tcase==4) {
			it = rSet.begin();
			cout << *it << "\n";
		}
		if (tcase==5) {
			cin >> x;
			it = Set.upper_bound(x);
			if (it==Set.end()) cout << "no" << "\n";
			else cout << *it << "\n";
		}
		if (tcase==6) {
			cin >> x;
			it = Set.lower_bound(x);
			if (it==Set.end()) cout << "no" << "\n";
			else cout << *it << "\n";
		}
		if (tcase==7) {
			cin >> x;
			it = rSet.upper_bound(x);
			if (it==rSet.end()) cout << "no" << "\n";
			else cout << *it << "\n";
		}
		if (tcase==8) {
			cin >> x;
			it = rSet.lower_bound(x);
			if (it==rSet.end()) cout << "no" << "\n";
			else cout << *it << "\n";
		}
	}
	return 0;
}
