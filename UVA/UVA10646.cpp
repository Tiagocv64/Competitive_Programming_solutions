#include <iostream>
#include <string>

using namespace std;

string cards[52];

int main(){
	int T, N = 0;
	cin >> T;
	while (N++ < T){
		int i = -1;
		while (++i < 52){
			cin >> cards[i];
		}
		cout << "Case " << N << ": " << cards[32] << endl;
	}
}