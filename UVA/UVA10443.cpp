#include <iostream>

using namespace std;

char boardCur[100][100], boardOld[100][100];

bool win(char c1, char c2){
	if (c1 == c2) return true;
	if (c1 == 'P'){
		if (c2 == 'S')
			return false;
		if (c2 == 'R')
			return true;
	} else if (c1 == 'S'){
		if (c2 == 'R')
			return false;
		if (c2 == 'P')
			return true;
	} else if (c1 == 'R'){
		if (c2 == 'P')
			return false;
		if (c2 == 'S')
			return true;
	}
	return true;
}

int main(){
	int T, r,c,n;
	cin >> T;
	while(T-- > 0){
		cin >> r >> c >> n;
		for (int y = 0; y < r; y++){
			for (int x = 0; x < c; x++){
				cin >> boardOld[y][x];
				boardCur[y][x] = boardOld[y][x];
			}
		}

		while (n-- > 0){
			for (int y = 0; y < r; y++){
				for (int x = 0; x < c; x++){
					if (x + 1 < c && boardOld[y][x] != boardOld[y][x+1]){
						if (win(boardOld[y][x], boardOld[y][x+1])){
							boardCur[y][x+1] = boardOld[y][x];
						} else {
							boardCur[y][x] = boardOld[y][x+1];
						}
					}
					if (y + 1 < r && boardOld[y][x] != boardOld[y+1][x]){
						if (win(boardOld[y][x], boardOld[y+1][x])){
							boardCur[y+1][x] = boardOld[y][x];
						} else {
							boardCur[y][x] = boardOld[y+1][x];
						}
					}
				}
			}

			for (int y = 0; y < r; y++){
				for (int x = 0; x < c; x++){
					boardOld[y][x] = boardCur[y][x];
				}
			}
		}

		for (int y = 0; y < r; y++){
			for (int x = 0; x < c; x++){
				cout << boardOld[y][x];
			}
			cout << "\n";
		}
		if (T != 0)
			cout << "\n";

	}


}