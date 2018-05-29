#include <iostream>

using namespace std;

int main(){
	int T;
	cin >> T;
	int n = 1;
	while (n <= T){
		int n1,n2,n3;
		cin >> n1 >> n2 >> n3;
		cout << "Case " << n << ": "; 
		if ((n1 < n2 && n1 > n3) || (n1 > n2 && n1 < n3)){
			cout << n1 << endl;
		} else if ((n2 < n1 && n2 > n3) || (n2 > n1 && n2 < n3)){
			cout << n2 << endl;
		} else {
			cout << n3 << endl;
		}
		n++;
	}
}