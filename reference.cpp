#include <iostream>
using namespace std;

class car {
	public:
		int wheels;
		float *dt;
	
	public: 
		car() {
			wheels = 4;
			dt = new float;
			*(this->dt) = 100;
		}
		
		car(int sb, int d) {
			wheels = sb;
			*dt = d;
		}
		~car() {
			delete(dt);
		}
		
		void nhap(){
			cout << "so banh";
			cin >> wheels;
			cout << "phan khoi";
			int temp;
			cin >> temp;
			*dt = temp;
		}
		
		void hienthidc() {
			cout << &wheels << " " << wheels<< endl;
			cout << dt <<" " << *dt << endl;
		}
		
		void changeWheels(int sb){
			wheels = sb;
		}
		
		void changeDt(int d) {
			*dt = d;
		}
		
		car(const car &b) {
			wheels = b.wheels;
			*dt = *b.dt;
		}
};

int main() {
	car car1;
	car1.changeDt(400);
	car1.changeWheels(8);
	car1.hienthidc();
	car car2(car1);
	car2.changeWheels(4);
	car2.changeDt(600);
	car2.hienthidc();
	car1.hienthidc();
	return 0;
}

