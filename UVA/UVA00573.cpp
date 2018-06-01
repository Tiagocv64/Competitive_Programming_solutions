#include <iostream>

using namespace std;

int main(){
	int H, U, D, F;
	cin >> H >> U >> D >> F;
	H*=100; U*=100; D*=100;
	while (H != 0){
		int day = 0, curH = 0, climb;
		while (true){
			int climb = U-(U/100*F*day);
			if (climb >= 0){
			curH += U-(U/100*F*day);
				if (curH > H){
					cout << "success on day " << ++day << endl;
					cin >> H >> U >> D >> F;
					H*=100; U*=100; D*=100;
					break;
				}
			}
			curH -= D;
			if (curH < 0) {
				cout << "failure on day " << ++day << endl;
				cin >> H >> U >> D >> F;
				H*=100; U*=100; D*=100;
				break;
			}
			day++;
		}
	}
}