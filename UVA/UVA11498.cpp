#include <iostream>

using namespace std;

int main(){
	int k;
	cin >> k;
	while (k != 0){
		int n = k;
		int dX, dY;
		cin >> dX >> dY;
		while (n-- > 0){
			int x, y;
			cin >> x >> y;
			if (x == dX || y == dY){
				cout << "divisa" << endl;
			} else if(x < dX){
				if (y < dY){
					cout << "SO" << endl;
				} else {
					cout << "NO" << endl;
				}
			} else {
				if (y < dY){
					cout << "SE" << endl;
				} else {
					cout << "NE" << endl;
				}
			}
		}
		cin >> k;
	}
}