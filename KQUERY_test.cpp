#include <cstdio>
#include <stdlib.h> 
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int n=300000;
	int q=200000;
	freopen("input.txt","w",stdout);
	printf("%d\n",n);
	for (int i=1;i<=n;i++) printf("%d ",rand() %1000000000);
	printf("\n");
	printf("%d\n",q);
	for (int i=1;i<=q;i++) {
		int u=rand() %n +1;
		int v = rand() %(n-u+1) + u;
		printf("%d %d %d\n",u,v,rand() %1000000000);	
	}
	fclose(stdout);
	return 0;
}
