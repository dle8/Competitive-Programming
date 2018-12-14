#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <string.h>
#define maxn 5000+10
#define maxm 10000+10
#define maxc 1000000000
using namespace std;

struct node {
	long u, v, f, c, next, cungngc;
};

node graph[2*maxm];
long trace[maxn], n, roads, head[maxn];
bool check[maxn];
ifstream fi;

long min(long a, long b) {
	if (a<b) return a;
	else return b;
}

void bfs(long u){
	long first=1,last=1;
	long Queue[maxn];
	Queue[1]=u;
	while (first<=last){
		long i=head[Queue[first]];
		first++;
		while (i!=0){
			long v=graph[i].v;
			if (trace[v]==0 && (graph[i].c>graph[i].f)){
				trace[v]=i;
				if (v==1) return;
				last++;
				Queue[last]=v;
			}
			i= graph[i].next;
		}
	}
}

void update(long id, long flow) {
	graph[id].f+=flow;
	graph[graph[id].cungngc].f-=flow;
}

void findMinCut(long u) {
	long v;
	long i = head[u];
	check[u] = false;
	while (i!=0) {
		v = graph[i].v;
		if (check[v] && (graph[i].c>graph[i].f)) findMinCut(v);
		i = graph[i].next;
	}
}

void findFlow() {
	long flow, sum, temp;
	while (true) {
		memset(trace, 0, sizeof(trace));
		trace[n]=-1;
		bfs(n);//tim duong tang luong
		if (trace[1]==0) break;
		
		temp = 1;
		flow = maxc;
		while (temp!=n) {
			flow = min(flow, graph[trace[temp]].c-graph[trace[temp]].f);
			temp = graph[trace[temp]].u;
		}
		temp = 1;
		while (temp!=n) {
			update(trace[temp], flow);
			temp = graph[trace[temp]].u;
		}
	}
	
	memset(check, true, sizeof(check));
	findMinCut(n);
	sum = 0;
	for (int i=1; i<=roads; i++) 
		if (!check[graph[i].u] && check[graph[i].v]) sum+=graph[i].c;	
		
	cout << sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int count, u, v, w;
	string s;
	
	cin >> n;
	roads = 0;
	while (cin>>u) {
		cin>>v>>w;
		roads++;
		graph[roads].u = u;
		graph[roads].v = v;
		graph[roads].c = w;
		graph[roads].f = 0;
		graph[roads].cungngc = roads+1;
		graph[roads].next = head[u];
		head[u] = roads;
		
		roads++;
		graph[roads].u = v;
		graph[roads].v = u;
		graph[roads].c = 0;
		graph[roads].f = 0;
		graph[roads].cungngc = roads-1;
		graph[roads].next = head[v];
		head[v] = roads;
	}
	findFlow();
	return 0;
}

