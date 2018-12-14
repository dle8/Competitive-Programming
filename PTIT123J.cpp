#include <iostream>
#include <stack>
using namespace std;

bool compatible(char c1, char c2) {
	if (c1=='(' && c2==')') return true;
	if (c1=='[' && c2==']') return true;
	return false;
}

int main() {
	string s;
	bool check;
//	cin.ignore();
	while (getline(cin, s)) {
		if (s==".") break;
		check = true;
		stack<char> stk;
		for (int i=0; i<s.length(); i++) {
			if (s[i] == '[' || s[i] == '(') stk.push(s[i]);
			if (s[i] == ')' || s[i] == ']') {
				if (stk.empty()) {
					check = false;
					break;
				}
				while (!stk.empty()) {
					if (compatible(stk.top(), s[i])) stk.pop();
					else {
						stk.pop();
						check = false;
					}
					break;
				}
				if (!check) break;
			}
		}
		if (!stk.empty()) check = false;
		if (check) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
