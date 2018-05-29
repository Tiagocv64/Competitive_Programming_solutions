#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int T;
	cin >> T;
	while (T-- > 0){
		char piece;
		cin >> piece;
		int H, W;
		cin >> H >> W;
		if (piece == 'r'){
			cout << min(H,W) << endl;
		} else if (piece == 'k'){
			if (W%2==0){
				cout << H*(W/2) << endl;
			} else {
				cout << H*(W/2)+(H-1) << endl;
			}
		} else if (piece == 'Q'){
			cout << min(H, W) << endl;
		} else if (piece == 'K'){
			cout << ((H+1)/2) * ((W+1)/2) << endl;
		}
	}
}