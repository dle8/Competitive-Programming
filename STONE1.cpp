#include <bits/stdc++.h>
#include <string.h>
#include <string>
#include <sstream>
#include <algorithm>
#define maxArr 10000+10
#define maxn 400+10
using namespace std;

struct node {
	int v, next;
};

node tree[maxArr];
int n;
int head[maxn], soi[maxn];//soi[i] la so soi can dung cho cay con goc i

int max(int a, int b){
	if (a>=b) return a;
	else return b;
}

bool decrease(const int&a, const int&b) {
	return (a>b);
}

void dfs(int u) {
	int v, soiConLai, index;
	int b[maxn];
	int i = head[u];
	index = 0;
	if (i==0) {
		soi[u] = 1;
		return;
	}
	while (i!=0) {
		index++;
		v = tree[i].v;
		dfs(v);
		b[index] = soi[v];
		i = tree[i].next;
	}
	sort(b+1, b+index+1, decrease);//sort giam dan. Xet thang con co so soi lon hon truoc
	soiConLai = 0;
	for (int i=1; i<=index; i++) {
		if (soiConLai<b[i]) {
			soi[u]+=b[i]-soiConLai;
			soiConLai = b[i];
		}
		soiConLai--;
	}
//	cout << u << " " << soi[u] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int dem, u, m, index, v;
	cin >> n;
	cin.ignore();
	string input;
	index = 0;
	memset(soi, 0, sizeof(soi));
	while (getline(cin, input)) {
		if (input=="") break;
		stringstream ss(input);
		string token;
		dem  = 0;
		while (getline(ss, token, ' ')) {
			dem++;
			if (dem==1) {
				u = stoi(token);
				continue;
			}
			if (dem!=2) {
				index++;
				tree[index].v = stoi(token);
				tree[index].next = head[u];
				head[u] = index;
			}
		}
	}
	dfs(1);
	cout << soi[1];
	return 0;
}
