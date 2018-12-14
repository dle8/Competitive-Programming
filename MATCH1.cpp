#include <iostream>
#include <string.h>
#include <string>

using namespace std;
 
struct duo {
	int v, next;
};
 
int n, m, p, result;
duo arr[150000+10];
int first, last;
bool check[50000+10];
bool flag;
int head[50000+10];
int match[50000+10];
int trace[50000+10];
 
void dfs(int u) {//tham cac dinh chua tham
	//duyet moi dinh ke u
	int i = head[u];
	int v;
	while (i!=0) {
		v = arr[i].v;//v la 1 dinh thuoc Y
		if (match[v]==0) flag = true;//neu Y chua dc tham -> co bao la da tim thay
		else if (match[v] != 0 && trace[v] <= 0) {
			trace[v] = u;
			dfs(match[v]);//dfs(v) hay dfs(match[v]);
			trace[v] = 0;
		}
		if (flag) {
			match[v] = u;
			check[u] = false;
			trace[v] = -u;//coi nhu tim duoc X tuong ung, vua reset mang trace cho lan dfs sau.
			return;
		}
		i = arr[i].next;
	}
}
 
int maxiMatching() {
	first = 0;
	last = 1;
	
	int stack[150000+100];
	int numberOfNotMatchX, oldNumberOfNotMatchX;
	
	for (int i=1; i<=m; i++) 
		if (check[i]) {//neu chua tham X thi bo vao stack
			first++;
			stack[first] = i;
			numberOfNotMatchX++;
		}
		
	while (true) {
		oldNumberOfNotMatchX = numberOfNotMatchX;
		for (int i=first; i>=last; i--) {
			flag = false;
			dfs(stack[i]);
			if (flag) {//co bao la tim dc duong mo
				result++;
				stack[i] = stack[first];
				first--;
				numberOfNotMatchX--;
			}
		}
		//bo thang vua dc ghep ra khoi stack
		
		if (numberOfNotMatchX == oldNumberOfNotMatchX) break;//k tim thay them duong mo nao
	}
	
	cout << result << endl;
}
 
int main() {
	int u, v;
	first = 0;
	memset(check, true, sizeof(check));
	memset(trace, 0, sizeof(trace));
	result = 0;
	string s;
	int i = 0;
	
	cin >> m >> n;
	cin.ignore();
	while (getline(cin, s)) {
		if (s=="") break;
		int space = s.find(" ");
		u = stoi(s.substr(0, space));
		v = stoi(s.substr(space+1));
		
		i++;
		arr[i].v = v;
		arr[i].next = head[u];
		head[u] = i;	
		
		if (check[u] && match[v]==0) {
			result++;
			check[u] = false;//danh dau dinh X nay da co duong
			match[v] = u;
			trace[v] = -u;	
		}
	}
	
	maxiMatching();
	for (int i=1; i<=n; i++) {
		if (match[i]!=0) cout << match[i] << " " << i << endl;
	}
	return 0;
} 
