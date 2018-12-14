#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i=l; i<=r; i++)
using namespace std;

stack<string> Stack;

bool isDigit(char c) {
	return ('0'<=c && c<='9');
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long sum;
	string s;
	cin >> s;
	
	long lengths = s.length();
	stringstream ss;
	
	FOR(i, 0, lengths-1) {
		if (s[i]=='(') Stack.push("(");
		if (isDigit(s[i])) {
			long top = stol(Stack.top());
			Stack.pop();
			Stack.push(to_string(top*(s[i]-'0')));
		}
		if (s[i]==')') {
			sum = 0;
			while (Stack.top()!="(") {
				string top = Stack.top();
				Stack.pop();
				sum+=stol(top);
			}
			Stack.pop();
			Stack.push(to_string(sum));
		}
		if (s[i]=='C') Stack.push("12");
		if (s[i]=='H') Stack.push("1");
		if (s[i]=='O') Stack.push("16");
	}
	
	sum = 0;
	while (!Stack.empty()) {
		sum+=stol(Stack.top());
		Stack.pop();
	}
	
	return cout << sum, 0;
}
