#include <iostream>
#include <string>
#define maxn 1000000+100
using namespace std;
string a, b;
int nextgiong[maxn], nextkhac[maxn],m,n;

void init() {//tinh mang next
	int temp;
	nextgiong[0]=-1;
	nextkhac[0]=-1;
	for (int i = 1 ; i<n ; i++){
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

void kmp() {
	int i, j;
	
	i=0;
	j=0;

	while (i<m){//vi index bat dau tu -1
		while (j>-1 && a[i]!=b[j]) j = nextkhac[j];
		if (j==n-1) {
			cout<<(i-n+1+1)<<" ";
			j=nextgiong[j];
		}
		i++;
		j++;
	}
}

int main() {
	getline(cin,a);
	getline(cin,b);
	m=a.length();
	n=b.length();
	init();
	kmp();
	return 0;
}
