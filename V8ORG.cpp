#include <bits/stdc++.h> 
#include <string.h>
#define maxn 10000+100
using namespace std;
 
struct node {
	int c, next;
};
 
node mem[maxn];
int head[maxn], conKhongDoi[maxn], conThayDoi[maxn];
int k, n, result;
 
void dfs(int u) {
	int i = head[u];
	int c;
	while (i!=0)  {
		c = mem[i].c;//k can them mang check vi moi node chi co 1 cha
		dfs(c);
		conKhongDoi[u]+=conKhongDoi[c];
		i = mem[i].next;
	}
}
 
void secondDfs(int u) {
	int i = head[u];
	int c;
	while (i!=0) {
		c = mem[i].c;
		secondDfs(c);
		if (conThayDoi[c]>=k) {
			result++;
			conThayDoi[u]-=conKhongDoi[c];
		}
		i = mem[i].next;
	}
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int cha;
	cin >> k>> n;
	memset(head, 0, sizeof(head));
	result = 0;
	for (int i=1; i<=n; i++) conKhongDoi[i] = 1;
	for (int i=2; i<=n; i++) {
		cin >> cha;
		mem[i].c = i;
		mem[i].next = head[cha];
		head[cha] = i;
	}
	mem[n+1].c = 1;
	mem[n+1].next = head[0];
	head[0] = n+1;
	dfs(0);
	for (int i=0; i<=n; i++) conThayDoi[i] = conKhongDoi[i];
	secondDfs(0);
	cout << result;
	return 0;
} 
