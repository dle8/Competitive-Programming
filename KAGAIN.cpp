#include <iostream>
#define maxn 30000+100
using namespace std;

struct a {
	int nguoi, dau, cuoi;
};

int n;
int stack[maxn];
a quandoan[maxn];

void process() {
	//dung stack max-> thang pop ra luon luon la thang lon nhat
	int first, top, d, c, max, power;
	first = 1;
	top = 0;
	for (int i=1; i<=n; i++) 
	{
		while (top>=first && quandoan[stack[top]].nguoi>quandoan[i].nguoi) //pop top ra -> xu ly nhung tgian no o trong stack
		{
			quandoan[stack[top]].cuoi = i-1;
			top--;
		}
		top++;
		stack[top] = i;
		quandoan[stack[top]].dau = i;
	}
	
	while (top>=first) 
	{
		quandoan[stack[top]].cuoi = n;
		top--;
	}
	
	first = 1;
	top = 0;
	for (int i=n; i>=1; i--)
	{
		while (top>=first && quandoan[stack[top]].nguoi>quandoan[i].nguoi) {
			quandoan[stack[top]].dau = i+1;
			top--;
		}
		top++;
		stack[top] = i;
	}
	while (top>=first)
	{
		quandoan[stack[top]].dau = 1;
		top--;
	}
	
	max = -1000000000;
	d = 1000000000;
	for (int i=1; i<=n; i++) 
	{
		power = quandoan[i].nguoi*(quandoan[i].cuoi - quandoan[i].dau+1);
		if (power > max) 
		{
			max = power;
			d = quandoan[i].dau;
			c = quandoan[i].cuoi;
		}
		else if (power == max)
		{
			if (quandoan[i].dau<d)
			{
				d = quandoan[i].dau;
				c = quandoan[i].cuoi;
			}
		}
	}
	
	cout << max << " " << d << " " << c << endl;
}

int main() {
	int num;
	int test;
	cin >> test;
	for (int i=1; i<=test; i++) 
	{
		cin >> n;
		for (int j=1; j<=n; j++) 
		{
			cin >> num;
			quandoan[j].nguoi = num;
		}
		process();
	}
	return 0;
}
