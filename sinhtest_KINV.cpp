#include <bits/stdc++.h>
#define FOR(i, l, r) for (int i=l; i<=r; i++)
using namespace std;

const long minn = 5, maxn = 15;
long n, k, tcount, stt, h[100];
list<long> hoanvi;
list<long>::iterator it;
bool check[100], flag;

long factorial(long n) {
	long result = 1;
	FOR(i, 1, n) result*=i;
	return result;
}

void sinhHoanVi(long i) {
	if (i==(n+1)) {
		tcount++;
		if (tcount==stt) {
			flag = true;
			FOR(j, 1, n) hoanvi.push_back(h[j]);	
		}
		return;
	}
	for (int j=1; j<=n; j++) {
		if (check[j]) {
			h[i] = j;
			check[j] = false;
			sinhHoanVi(i+1);
			if (flag) return;
			check[j] = true;
		}
	}
}

int main() {
	srand(time(NULL));
	FOR(i, 1, 10) {
		srand(time(NULL));
		ofstream inp("kinvinp.txt");
		n = minn + rand()%(maxn-minn+1);
		k = 2 + rand()%(n-2);
		inp << n << " " << k << "\n";
//		cout << n << " " << k << "\n";
		memset(check, true, sizeof(check));
		memset(h, 0, sizeof(h));
		long giaithua = factorial(n);
		stt = 1 + rand()%giaithua;
		tcount = 0;
		hoanvi.clear();
		flag = false;
		sinhHoanVi(1);
		for (it=hoanvi.end(); it!=hoanvi.begin(); --it) inp << *it << " ";
		
		inp.close();
		system("KINV.exe");
		system("KINV_sol.exe");
		if (system("fc kinvout.txt kinvans.txt")!=0) {
			cout << "Test " << i << ": WRONG!\n";
			return 0;
		}
		cout << "Test " << i << ": CORRECT!\n";
	}
	return 0;
}
