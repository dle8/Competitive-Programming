#include <bits/stdc++.h>

using namespace std;

int t,n,m,sumA,sumB,a[1000],b[1000],countA,countB;
bool flag;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x;

	cin>>t;
	for (int o=1;o<=t;o++){
		sumA=0;
		sumB=0;
		countA=0;
		countB=0;
		cin>>n>>m;
		for (int i=1;i<=n;i++){
			cin>>x;
			if (x!=0) {
				countA++;
				a[countA]=x;
			}

			sumA=sumA+x;
		}
		for (int i=1;i<=m;i++){
			cin>>x;
			if (x!=0){
				countB++;
				b[countB]=x;
			}

			sumB=sumB+x;
		}
		n=countA;
		m=countB;
		sort(a+1,a+n+1);
		sort(b+1,b+m+1);

		if (sumA!=sumB) cout<<"Alice"<<endl;
		else {
			if (sumA==0) cout<<"Bob"<<endl;
			else{
				if (m!=n) cout<<"Alice"<<endl;
				else {
					flag=true;
					for (int i=1;i<=n;i++)
					if (a[i]!=b[i]) {
						flag=false;
						cout<<"Alice"<<endl;
						break;
					}
					if (flag) cout<<"Bob"<<endl;
				}
			}
		}
	}
	return 0;
}
