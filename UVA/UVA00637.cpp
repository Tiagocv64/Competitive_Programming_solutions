#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n;
	while (cin >> n && n != 0){
		cout << "Printing order for " << n << " pages:\n";
		int sheets = ceil(n*1.0/4);
		int MAX = sheets*4+1;
		for (int i = 1; i <= sheets*2 && i <= n; i++){
			if (i % 2 == 0){
				int other = MAX - i;
				if (other > n){
					cout << "Sheet " << ceil(i*1.0/2) << ", back : " << i << ", Blank\n";
				} else {
					cout << "Sheet " << ceil(i*1.0/2) << ", back : " << i << ", " << other << "\n";
				}
			} else {
				int other = MAX - i;
				if (other > n){
					cout << "Sheet " << ceil(i*1.0/2) << ", front: Blank, " << i << "\n";
				} else {
					cout << "Sheet " << ceil(i*1.0/2) << ", front: " << other << ", " << i << "\n";
				}
			}
		}
	}
}