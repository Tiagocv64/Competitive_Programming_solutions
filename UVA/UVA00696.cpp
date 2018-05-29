#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
	int r, c;
	cin >> r >> c;
	while (r != 0 || c != 0){
		int n;
		if (r == 0 || c == 0){
			n = 0;
		} else if (r == 1 || c == 1){
			n = max(r, c);
		} else if (r == 2 || c == 2){
			n = max(r,c)/4*4 + min(max(r,c)%4,2) * 2;
		} else {
			n = ceil(r*1.0*c/2);
		}
		cout << n << " knights may be placed on a " << r << " row " << c << " column board.\n";
		cin >> r >> c;
	}
}