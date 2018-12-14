#include <bits/stdc++.h>
#define maxn 200000+10
using namespace std;

long n, k;
long place[maxn];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long openbrac, closebrac, count, index;
	string res = "", s, origin;
	cin >> n >> k;
	cin >> s;
	origin = s;
	count = 0;
	index = 0;
	while (true) {
		count+=2;
		if (count>k) break;
		openbrac = s.find("(");
		index++;
		place[index] = openbrac;
		closebrac = s.rfind(")");
		index++;
		place[index] = closebrac;
		
		s = s.substr(openbrac+1, closebrac-openbrac-1);
		cout << s << "\n";
	}
	sort(place+1, place+1+index);
	for (int i=1; i<=index; i++) res+=origin[place[i]];
	cout << res;
	return 0;
}
