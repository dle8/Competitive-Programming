#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define REP(i, r, l) for (int i=r; i>=l; i--)
#define maxl 400+10
using namespace std;

long priority(char c) {
	if (c=='+' || c=='-') return 1;
	if (c=='*'|| c=='/')return 2;
	if (c=='^') return 3;
}

bool isOperator(char c) {
	return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long test_cases, lengths, top;
	string res, s;
	cin >> test_cases;
	cin.ignore();
	
	char Stack[maxl];
	memset(Stack, 0, sizeof(Stack));
	FOR(current_test, 1, test_cases) {
		getline(cin, s);
		res = "";
		lengths = s.length();
		top = 0;
		FOR(i, 0, lengths-1) {
			if (s[i]=='('){ 
				Stack[++top] = s[i];
			}
			else if (s[i]==')' && top>0) {
				while (Stack[top]!='('){ res+=Stack[top--];}
				top--;
			}
			else if (isOperator(s[i])) {
				if (priority(Stack[top])<priority(s[i]) || top == 0) Stack[++top] = s[i];
				else {
					while (priority(Stack[top])>=priority(s[i]) && top>0) {
						res+=Stack[top--];
					}
					Stack[++top] = s[i];
				}
			}
			else res+=s[i];
			cout << res << "\n";
		}

		while (top>0) res+=Stack[top--];
		cout << res << "\n";
	}
	return 0;
}

