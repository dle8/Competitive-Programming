#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <stdlib.h> 
#include <ctime>
#define maxn 300000+10
#define maxq 200000+10
using namespace std;

int n;
long u[maxq], v[maxq], k[maxq], a[maxn], res[maxq], bit[maxn], csA[maxn], csK[maxq];//mang b danh dau nhung phan tu nho hon k

void swap(long &a, long &b) {
	long temp = a;
	a = b;
	b = temp;
}

void sortA(int dau, int cuoi) {
	int i = dau;
	int j = cuoi;
	long mid = a[rand() %(cuoi-dau+1) + dau];
	
	do  {
		while (a[i]>mid) i++;
		while (a[j]<mid) j--;
		if (i<=j)  {
			swap(a[i], a[j]);
			swap(csA[i], csA[j]);
			i++;
			j--;
		}	
	} while (i<=j);
	if (i<cuoi) sortA(i, cuoi);
	if (dau<j) sortA(dau, j);
}

void sortK(int dau, int cuoi) {
	int  i= dau;
	int j = cuoi;
	long mid = k[csK[rand() %(cuoi-dau+1) + dau]];
	
	do {
		while (k[csK[i]]>mid) i++;
		while (k[csK[j]]<mid) j--;
		if (i<=j) {
			//swap(k[i], k[j]);
			swap(csK[i], csK[j]);
			//swap(u[i], u[j]);
			//swap(v[i], v[j]);
			i++;
			j--;
		}
	} while (i<=j);
	if (i<cuoi) sortK(i, cuoi);
	if (dau<j) sortK(dau, j);
}

void update(int cs) {
	while (cs<=n){
		bit[cs]+=1;
		cs=cs+(cs&(-cs));
	}
}

int getQuery(int cs) {
	int temp = 0;
	while (cs>0) {
		temp+=bit[cs];
		cs = cs-(cs&(-cs));
	}
	return temp;
}

int main() {
	const clock_t begin_time = clock();
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	srand (time(NULL));
	freopen("input.txt","r",stdin);
	int index, q;
	scanf("%ld",&n);
	for (int i=1; i<=n; i++) {
		scanf("%ld",&a[i]);
		csA[i] = i;//mang csA luu vi  tri ban dau cua a[i]
	}
	sortA(1, n);
	scanf("%ld",&q);
	for (int i=1; i<=q; i++) {
		scanf("%ld %ld %ld",&u[i],&v[i],&k[i]);
		csK[i] = i;//mang csK luu vi tri ban dau cua k[i]
	}
	fclose(stdin);
	sortK(1, q);	
	
	index = 1;
	
	for (int i=1; i<=q; i++) {
		for (int j=index; j<=n; j++) {
			if (a[j]>k[csK[i]]) {
				update(csA[j]);
				index=j+1;	
			}
			else break;
		}
		res[csK[i]] = getQuery(v[csK[i]])-getQuery(u[csK[i]]-1);
	}
	freopen("output.txt","w",stdout);
	for (int i=1; i<=q; i++)
		printf("%ld\n",res[i]);
	cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC<<endl;
	fclose(stdout);
	return 0;
}
