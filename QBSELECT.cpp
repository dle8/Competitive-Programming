#include <iostream>
using namespace std;

long n;
long f[16+5][10000+10];
long arr[16+5];
long c[5][10000+10];

long getBit(long i, long j) {//get bit thu j cua i
	return ((i>>(j-1)) & 1);
}

long max(long a, long b) {
	if (a>=b) return a;
	else return b;
}

bool check(long i) {
	for (int j=2; j<=4; j++) 
	if ((getBit(i,j)==1) && (getBit(i,j-1)==1)) return false;
	return true;
}

bool compatible(long i1, long i2) {
	for (int j=1; j<=4; j++) 
	if (getBit(i1,j) ==1 && getBit(i2, j) == 1) return false;
	return true;
}

long sumOfChosenBox(long i, long j) {//tong nhung o da chon cua arr[i] o cot j
	long sum = 0;
	for (int k=1; k<=4; k++) 
		if (getBit(i, k) == 1) sum+=c[k][j];
	return sum;
}

int main() {
	cin >> n;
	long sum;
	long totalSatisfy = 0;
	
	for (int i=1; i<=4; i++) {
		for (int j=1; j<=n; j++) cin >> c[i][j];
	}
	
	for (int i=0; i<=(1<<4)-1; i++) {//tinh ca truong hop 0000, tuc la k chon so nao trong cot
		if (check(i)) {//neu i bieu dien duoi dang nhi phan khong co 2 so 1 nao dung canh nhau thi cho vao mang arr
			totalSatisfy++;
			arr[totalSatisfy] = i;
		}
	}
	
	for (int i=1; i<=totalSatisfy; i++) {
		for (int j=1; j<=n; j++) f[i][j] = -1000000000;
 	}
 	
	for (int i=1; i<=totalSatisfy; i++) {
		sum = 0;
		for (int j=1; j<=4; j++) {
			if (getBit(arr[i], j) == 1) sum+=c[j][1];//i chi la index trong arr thoi
		}
		f[i][1] = sum;
	}
	
	for (int j=2; j<=n; j++) {//tu cot thu 2 tro di tinh theo cot truoc no
		for (int i=1; i<=totalSatisfy; i++) {
			sum = sumOfChosenBox(arr[i], j);
			for (int k=1; k<=totalSatisfy; k++) {
				if (compatible(arr[i], arr[k])) {//neu nhu arr[i] va arr[k] k co phan tu nao co canh chung
					f[i][j] = max(f[i][j], f[k][j-1]+sum);
				}
			}
		}
	}
	
	long res = -1000000000;
	for (int i=1; i<=totalSatisfy; i++) 
	if (f[i][n] > res) res = f[i][n];
	
	cout << res;
	
	return 0;
}
