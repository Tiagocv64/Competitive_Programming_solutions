#include <iostream>

using namespace std;

int card[5][5];

bool replace(int n){
	if (n <= 15){
		for (int i = 0; i < 5; i++){
			if(card[i][0] == n){
				card[i][0] = 0;
				return true;
			}
		}
	} else if (n <= 30){
		for (int i = 0; i < 5; i++){
			if(card[i][1] == n){
				card[i][1] = 0;
				return true;
			}
		}
	} else if (n <= 45){
		for (int i = 0; i < 5; i++){
			if(card[i][2] == n){
				card[i][2] = 0;
				return true;
			}
		}		
	} else if (n <= 60){
		for (int i = 0; i < 5; i++){
			if(card[i][3] == n){
				card[i][3] = 0;
				return true;
			}
		}
	} else if (n <= 75){
		for (int i = 0; i < 5; i++){
			if(card[i][4] == n){
				card[i][4] = 0;
				return true;
			}
		}
	}
	return false;
}

bool checkWin(){
	int count = 0;
	for (int y = 0; y < 5; y++){
		count = 0;
		for (int x = 0; x < 5; x++){
			if (card[y][x] == 0)
				count++;
		}
		if(count == 5)
			return true;
	}
	for (int x = 0; x < 5; x++){
		count = 0;
		for (int y = 0; y < 5; y++){
			if (card[y][x] == 0)
				count++;
		}
		if(count == 5)
			return true;
	}
	count = 0;
	for (int i = 0; i < 5; i++){
		if (card[i][i] == 0)
			count++;
	}
	if (count == 5)
		return true;

	count = 0;

	for (int i = 0; i < 5; i++){
		if (card[i][5-i-1] == 0)
			count++;
	}
	if (count == 5)
		return true;

	return false;
}

int main(){
	int T;
	cin >> T;
	while (T-- > 0){
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				if(i != 2 || j != 2)
					cin >> card[i][j];
		card[2][2] = 0;

		int winPos = -1, cur;
		for (int i = 0; i < 75; i++){
			cin >> cur;
			if (winPos == -1){
				if(replace(cur) && checkWin())
					winPos = i+1;
			}
		}
		cout << "BINGO after " << winPos << " numbers announced\n";
	}

}