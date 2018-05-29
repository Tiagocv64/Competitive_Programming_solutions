#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int T;
	cin >> T;
	while (T-- > 0){
		int sum, diff;
		cin >> sum >> diff;
		int x = (sum - diff)/2;
		int n1 = x + diff, n2 = x;
		if (n1+n2 == sum && abs(n1-n2) == diff && n1 >= 0 && n2 >= 0){
			cout << n1 << " " << n2 << "\n";
		} else {
			cout << "impossible\n";
		}
	}


}