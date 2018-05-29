#include <iostream>

using namespace std;

char board[100][100];

int main(){
	int Y, X, N = 1;
	cin >> Y >> X;
	while (Y!=0 && X!=0){
		for (int i = 0; i < Y; i++){
			for (int j = 0; j < X; j++){
				cin >> board[i][j];
			}
		}

		for (int i = 0; i < Y; i++){
			for (int j = 0; j < X; j++){
				if(board[i][j] == '*'){
					for (int y = i-1; y <= i+1; y++){
						if (y < 0 || y >= Y) continue;
						for (int x = j-1; x <= j+1; x++){
							if (x < 0 || x >= X) continue;
							if(board[y][x] == '.'){
								board[y][x] = '1';
							} else if(board[y][x] != '*'){
								board[y][x] = (char) board[y][x] + 1;
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < Y; i++){
			for (int j = 0; j < X; j++){
				if (board[i][j] == '.')
					board[i][j] = '0';
			}
		}

		cout << "Field #" << N++ << ":\n";
		for (int i = 0; i < Y; i++){
			for (int j = 0; j < X; j++){
				cout << board[i][j];
			}
			cout << endl;
		}
		cin >> Y >> X;
		if(Y!=0 && X!=0)
			cout << endl;
	}


}