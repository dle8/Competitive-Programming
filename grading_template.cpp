#include <bits/stdc++.h>
using namespace std;

const int ntest = ;

//viet lai ham random cho long long. so duoc sinh ra se nam trong khoang l va h
long long Rand(long long l, long long h) {
	return l + ((long long)rand() * (RAND_MAX+1) * (RAND_MAX+1)*(RAND_MAX+1)+
				(long long)rand() * (RAND_MAX+1) * (RAND_MAX+1)+
				(long long)rand() * (RAND_MAX+1)+
				rand())%(h-l+1);
}

int main() {
	srand(time(NULL));
	for (int itest = 1; itest<=ntest; itest++) {
		ofstream inp((NAME + ".inp").c_str());
		//code phan sinh test o day
		inp.close();
		//neu dung linux thi "./" + ten  chuong trinh
		system((NAME+".exe").c_str());
		system((NAME+"_trau.exe").c_str())
		//neu dung linux thi thay fc bang diff
		if (system(("fc"+NAME+".out"+NAME+".ans").c_str())!=0) {
			cout << "test " << itest << ": wrong!\n";
			return 0;
		}	         
		cout << "test " << itest << ": correct!\n";                                             		
	}
	return 0;
}
