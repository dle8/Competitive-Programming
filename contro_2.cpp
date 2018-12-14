#include <bits/stdc++.h>
#define maxn 100000+100
using namespace std;

typedef struct node{
	long v,c;
	node* next;
};

long n,m;
node* head[maxn];

int main()
{
	long u,v,c;
	node* p = nullptr;
	
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>u>>v>>c;		
		p = new node;
		/*(*p).v=v;
		(*p).c=c;
		(*p).next=head[u];*/
		p->v=v;
		p->c=c;
		p->next=head[u];
		head[u]=p;		
		
		p = new node;
		p->v=u;
		p->c=c;
		p->next=head[v];
		head[v]=p;	
	}
	
	// print
	cout<<"==============================" << "\n";
	
	for (int u=1;u<=n;u++){
		node* p = head[u];
		while (p!=nullptr){
			cout<<u<<" "<<p->v<<" "<<p->c<<endl;
			p=p->next;
		}
	}
	return 0;
}
