#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int T, N;
	cin >> T;
	N = 1;
	while (N <= T){
		int n, min = -1, cur;
		cin >> n;
		while (n-- > 0){
			cin >> cur;
			min = max(min, cur);
		}
		cout << "Case " << N << ": " << min << endl;
		N++;
	}
}