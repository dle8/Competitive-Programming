#include <iostream>
#include <math.h>

using namespace std;

int n, x;
int h[1000000+10], cachto[1000000+10];
int left[1000000+10];

struct elem {
	int value = 1000010;
	int index;
};

elem it[4000000];

int min(int a, int b) {
	if (a<=b) return a;
	else return b;
}

void update(int cs, int u, int v, int i, int val) {
	if (u==i && v==i) {
		it[cs].value = val;
		it[cs].index = i;
	}
	else {
		if (i<=(u+v)/2) {
			update(2*cs, u, (u+v)/2, i, val);
			if (it[cs].value > it[2*cs].value) {
				it[cs].value = it[2*cs].value;
				it[cs].index = it[2*cs].index;
			}	
		}
		if (i>=(u+v)/2+1) {
			update(2*cs+1, (u+v)/2+1, v, i, val);
			if (it[cs].value > it[2*cs+1].value) {
				it[cs].value = it[2*cs+1].value;
				it[cs].index = it[2*cs+1].index;
			}	
		}
	}
}

elem itmin(int cs, int u, int v, int x, int y) {
	if (u==x && v==y) return it[cs];
	else {
		if (x>=(u+v)/2+1) return itmin(2*cs+1, (u+v)/2+1, v, x, y);
		if (y<=(u+v)/2) return itmin(2*cs, u, (u+v)/2, x, y);
		else {
			elem result;
			elem p1 = itmin(2*cs, u, (u+v)/2, x, (u+v)/2);
			elem p2 = itmin(2*cs+1, (u+v)/2+1, v, (u+v)/2+1, y);
			if (p1.value <= p2.value) {
				result.value = p1.value;
				result.index = p1.index;
			}
			else {
				result.value = p2.value;
				result.index = p2.index;//** tim so min gan hon
			}
		}
	}
}

int main() {
	int nextRight, rightBound, chiso;
	int leftOverArea = 0;
	int stroke = 0;
	elem min;
	cin >> n >> x;
	chiso = -1;
	
	for (int i=1; i<=n; i++) {
		cin >> h[i];
		update(1, 1, n, i, h[i]);
	}
	
	cachto[1] = itmin(1, 1, n, 1, x).value;
	leftOverArea+=h[1]-cachto[1];
	stroke++;
	for (int i=2; i<=n; i++) {
		if (cachto[i-1] >= h[i]) cachto[i] = h[i];
		else {
			if (i+x-1 > n) rightBound = n;
			else rightBound = i+x-1;
			if (chiso == -1) {
				min = itmin(1, 1, n, i, rightBound); 
				nextRight = min.value;
				chiso = min.index;
			}
			if (i>chiso) {
				min = itmin(1, 1, n, i, rightBound); 
				nextRight = min.value;
				chiso = min.index;
			} 
			else if (nextRight > h[i]){
					nextRight = h[i];
					chiso = i;
				}
			if (cachto[i-1] < nextRight) cachto[i] = nextRight;
			else cachto[i] = cachto[i-1];		
			leftOverArea +=abs(h[i]-cachto[i]);
		}
	}
	
	/*	for (int i=1; i<=n; i++) {
		cout << cachto[i] << endl;
	}*/
	
	cout << leftOverArea << endl;
	return 0;
}
