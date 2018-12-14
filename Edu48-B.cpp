#include <iostream>
#include <string>
#include <string.h>
#define maxn 1000+10
using namespace std;

long n, m, q;
string s, t;
long nextgiong[maxn], nextkhac[maxn];

void init(string a, string b) {//tinh mang next
	long temp;
	nextgiong[0]=-1;
	nextkhac[0]=-1;
	for (int i = 1 ; i<t.length() ; i++){
		//tim next khac cua i
		temp = nextgiong[i-1];
		if (b[temp+1]!=b[i]) nextkhac[i] = temp+1;
		else nextkhac[i] = nextkhac[nextgiong[i-1]+1];
		//tim next giong cua i
		
		temp = nextgiong[i-1];
		if (b[temp+1]==b[i]) nextgiong[i] = temp +1;
		else {
			temp = nextgiong[i-1] + 1;
			while (temp>-1 && b[temp] != b[i]) temp = nextkhac[temp];
			nextgiong[i] = temp;
		}
	}
}

long kmp(string a, string b) {
	long i, j, count;
	
	i=0;
	j=0;
	count = 0;
	while (i<a.length()){//vi index bat dau tu -1
		while (j>-1 && a[i]!=b[j]) j = nextkhac[j];
		if (j==b.length()-1) {
			count++;
			j=nextgiong[j];
		}
		i++;
		j++;
	}
	
	return count;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long li, ri;
	string str;
	cin >> n >> m >> q;
	cin >> s;
	cin >> t;
	for (int i=1; i<=q; i++) {
		cin >> li >> ri;
		memset(nextgiong, 0, sizeof(nextgiong));
		memset(nextkhac, 0, sizeof(nextkhac));
		
		str = s.substr(li-1, ri-li+1);
		init(str, t);
		cout << kmp(str, t) << "\n";
	}
	return 0;
}
