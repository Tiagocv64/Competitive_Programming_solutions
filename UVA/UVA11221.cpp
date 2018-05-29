#include <iostream>
#include <string>
#include <math.h>

using namespace std;

char matrix[100][100];

int main(){
	int T, n = 0;
	string line, word;
	cin >> T;
	cin.ignore();
	while (n++ < T){
		word = "";
		getline(cin, line);
		for (char c : line){
			if (isalpha(c))
				word += c;
		}
		int K = sqrt(word.size());
		if (K*K != word.size()){
			K = -1;
		} else {
			bool possible = true;
			int index = 0;
			for (int i = 0; i < K; i++){
				for (int j = 0; j < K; j++){
					matrix[i][j] = word.at(index++);
				}
			}
			for (int i = 0; i < K; i++){
				for (int j = 0; j < K; j++){
					if (matrix[i][j] != matrix[j][i] || matrix[i][j] != matrix[K-1-i][K-1-j] || matrix[i][j] != matrix[K-1-j][K-1-i]){
						possible = false;
						break;
					}
				}
				if (!possible)
					break;
			}
			if (!possible)
				K = -1;
		}
		cout << "Case #" << n << ":\n";
		if (K == -1){
			cout << "No magic :(\n";
		} else {
			cout << K << "\n";
		}
	}
}