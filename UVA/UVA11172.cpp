#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;

	while (n-- > 0){
		int n1, n2;

		cin >> n1 >> n2;
		cout << ((n1 < n2)? "<" : (n1 > n2)? ">" : "=") << endl;

	}

}