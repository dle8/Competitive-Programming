#include <iostream>
#include <math.h>
#define maxn 10000+10
#define FOR(i, l, r) for (int i=l; i<=r; i++)
#define pi 3.14159265358979
#define eps 1e-5
using namespace std;
	
double r[maxn];	
	
double angle(double R, double r1, double r2) {
	double p = (R+r1+r2)/(double)2;
	double s = sqrt(p*(p-R)*(p-r1)*(p-r2));
	return asin((2*s)/((R+r1)*(R+r2)))*180.0/pi;
}	
	
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	double sum = 0;
	long n;
	cin >> n;
	FOR(i, 1, n) {
		cin >> r[i];
		sum+=r[i];
	}
	
	r[n+1] = r[1];
	double d = 0;
	double c = sum;
	
	while ((d-c)<eps) {
		double R = (d+c)/(double)2;
		double sum = 0;
		FOR(i, 1, n) sum+=angle(R, r[i], r[i+1]);
		if (sum-(2*pi)<eps && sum-(2*pi)>-eps) return cout << R, 0;
		if (sum-(2*pi)<-eps) c = R;
		else d = R; 
	}
	
	return 0;
}
