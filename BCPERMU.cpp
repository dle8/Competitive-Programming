#include <iostream>

using namespace std;

int a[12];
bool visited[12];
int n;
int count = 1;


void tryPermu(int index) {
	if (index == n) {
		cout << count << " ";
		for (int i=0; i<n; i++) {
			cout<<a[i]+1;
		}
		count++;
		cout << "\n";
	} else {
		for (int i=0; i<n; i++) {
			if (!visited[i]) {
				a[index] = i;
				visited[i] = true;
				tryPermu(index+1);
				visited[i] = false;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i=0; i<n; i++) {
		a[i] = 0;
		visited[i] = false;	
	}
	tryPermu(0);
}
