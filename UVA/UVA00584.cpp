#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
	string line;
	while (getline(cin, line) && line != "Game Over"){
		char jog1 = '0', jog2 = '0';
		int dup1 = 0, dup2 = 0, pontos = 0, round = 1;
		istringstream iss (line);
		while (iss >> jog1){
			
			if (jog1 == 'X'){
				pontos += 10;
				if (dup1 > 0)
					pontos += 10;
				if (dup2 > 0)
					pontos += 10;
				if (round < 10){
					if (dup1 <= 1){
						dup1 = 3;
					} else {
						dup2 = 3;
					}
				}
				dup1--; dup2--;

			} else {
				iss >> jog2;
				if (jog2 == '/'){
					pontos += 10;
					if (dup1 >= 2){
						pontos += 10;
					} else if (dup1 == 1){
						pontos += jog1 - '0';
					}
					if (dup2 >= 2){
						pontos += 10;
					} else if (dup2 == 1){
						pontos += jog1 - '0';
					}
					if (round < 10){
						if (dup1 <= 1){
							dup1 = 3;
						} else {
							dup2 = 3;
						}
					}
				} else {
					int curP = (int) ((jog1-'0') + (jog2-'0'));
					pontos += curP;
					if (dup1 >= 2){
						pontos += curP;
					} else if (dup1 == 1){
						pontos += jog1 - '0';
					}
					if (dup2 >= 2){
						pontos += curP;
					} else if (dup2 == 1){
						pontos += jog1 - '0';
					}
				}
				jog2 = '0';

				dup1-=2; dup2-=2;

			}
			round++;
		}

		cout << pontos << "\n";

	}


}