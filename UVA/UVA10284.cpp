#include <iostream>
#include <string>

using namespace std;

char board[8][8];
bool attacked[8][8];

void checkLines(int y, int x){
	for (int i = x+1; i < 8; i++){
		if (board[y][i] != '.') break;
		attacked[y][i] = true;
	}
	for (int i = x-1; i >= 0; i--){
		if (board[y][i] != '.') break;
		attacked[y][i] = true;
	}
	for (int i = y+1; i < 8; i++){
		if (board[i][x] != '.') break;
		attacked[i][x] = true;
	}
	for (int i = y-1; i >= 0; i--){
		if (board[i][x] != '.') break;
		attacked[i][x] = true;
	}
}
void checkDiagonal(int y, int x){
	int y1 = y, x1 = x;
	for (y1 = y-1, x1 = x-1; y1 >= 0 && x1 >= 0; y1--, x1--){
		if (board[y1][x1] != '.') break;
		attacked[y1][x1] = true;
	}
	for (y1 = y-1, x1 = x+1; y1 >= 0 && x1 < 8; y1--, x1++){
		if (board[y1][x1] != '.') break;
		attacked[y1][x1] = true;
	}
	for (y1 = y+1, x1 = x-1; y1 < 8 && x1 >= 0; y1++, x1--){
		if (board[y1][x1] != '.') break;
		attacked[y1][x1] = true;
	}
	for (y1 = y+1, x1 = x+1; y1 < 8 && x1 < 8; y1++, x1++){
		if (board[y1][x1] != '.') break;
		attacked[y1][x1] = true;
	}
}
void checkKing(int y, int x){
	y--; x--;
	int countY, countX;
	for (countY = 0; countY < 3; countY++){
		for (countX = 0; countX < 3; countX++){
			if (countX+x < 8 && countX+x >= 0 && countY+y < 8 && countY+y >= 0){
				attacked[countY+y][countX+x] = true;
			}
		}
	}
}
void checkPawn(int y, int x, bool upAttack){
	if (upAttack){
		if (y-1 >= 0 && x-1 >= 0){
			attacked[y-1][x-1] = true;
		}
		if (y-1 >= 0 && x+1 < 8){
			attacked[y-1][x+1] = true;
		}
	} else {
		if (y+1 < 8 && x-1 >= 0){
			attacked[y+1][x-1] = true;
		}
		if (y+1 < 8 && x+1 < 8){
			attacked[y+1][x+1] = true;
		}
	}
}

void checkHorse(int y, int x){
	if (x-1 >= 0 && y-2 >= 0)
		attacked[y-2][x-1]= true;
	if (x+1 < 8 && y-2 >= 0)
		attacked[y-2][x+1]= true;
	if (x+2 < 8 && y-1 >= 0)
		attacked[y-1][x+2]= true;
	if (x+2 < 8 && y+1 < 8)
		attacked[y+1][x+2]= true;

	if (x+1 < 8 && y+2 < 8)
		attacked[y+2][x+1]= true;
	if (x-1 >= 0 && y+2 < 8)
		attacked[y+2][x-1]= true;
	if (x-2 >= 0 && y-1 >= 0)
		attacked[y-1][x-2]= true;
	if (x-2 >= 0 && y+1 < 8)
		attacked[y+1][x-2]= true;
}

int main(){
	string line;

	while (cin >> line){
		for (int i = 0; i < 8; i++)
			for (int t = 0; t < 8; t++)
				attacked[i][t] = false;

		int y = 0, x = 0;
		for (int i = 0; i < line.size(); i++){
			char cur = line.at(i);
			if (cur <= '9' && cur >= '0'){
				int t;
				for (t = x; t < x + (cur - '0'); t++){
					board[y][t] = '.';
				}
				x = t;
			} else if (cur == '/') {
				x = 0;
				y++;
			} else {
				board[y][x] = cur;
				attacked[y][x] = true;
				x++;
			}
		}

		for (y = 0; y < 8; y++){
			for (x = 0; x < 8; x++){
				char cur = board[y][x];
				if(cur == '.'){
					continue;
				} else if (cur == 'K' || cur == 'k'){
					checkKing(y, x);
				} else if (cur == 'Q' || cur == 'q'){
					checkDiagonal(y, x);
					checkLines(y, x);
				} else if (cur == 'B' || cur == 'b'){
					checkDiagonal(y, x);
				} else if (cur == 'N' || cur == 'n'){
					checkHorse(y, x);
				} else if (cur == 'R' || cur == 'r'){
					checkLines(y, x);
				} else if (cur == 'P'){
					checkPawn(y, x, true);
				} else if (cur == 'p'){
					checkPawn(y, x, false);
				}
			}
		}
		int ans = 0;
		for (y = 0; y < 8; y++){
			for (x = 0; x < 8; x++){
				if (!attacked[y][x])
					ans++;
			}
		}
		cout << ans << endl;
	}
}