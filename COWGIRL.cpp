#include <iostream>
#define maxn 30+5
using namespace std;

int n, m;

void swap(int&a, int&b){
	int temp = a;
	a = b;
	b = temp;
}

int getBit(int i, int j){//getbit thu j cua i
	return (i>>(j-1)&1);
}

bool compatible(int cot1, int cot2){
	int o1, o2, o3, o4;
	for (int i=1; i<=n-1; i++) {
		o1 = getBit(cot1, i);
		o2 = getBit(cot2, i);
		o3 = getBit(cot1, i+1);
		o4 = getBit(cot2,i+1);
		if (o1==o2&& o2==o4 && o1==o3) return false;	
	}
	return true;
}

void process() {
	int result;
	int f[maxn][maxn];
	for (int i=0; i<maxn; i++)
		for (int j=0; j<maxn; j++) f[i][j] = 0;
	for (int j=0; j<(1<<n); j++)
		f[1][j] = 1;
	for (int i=2; i<=m; i++)
		for (int j=0; j<(1<<n); j++){
			for (int k=0; k<(1<<n); k++) {
				if (compatible(j,k)) f[i][j]+=f[i-1][k];				
			}
		}
		
	result = 0;
	for (int j=0; j<(1<<n); j++) result+=f[m][j];
	cout << result << endl;
}

int main(){
	int test;
	cin >> test;
	for (int k=1; k<=test; k++) {
		cin >> m >> n;
		if (n>m) swap(n, m);
		process();
	}
	return 0;
}
