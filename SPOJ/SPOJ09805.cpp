#include <iostream>

using namespace std;

int girls[21];
int state[21][101];

int getNumber(int restantes, int nGirl, int M){
	if (restantes == 0)
		return 1;
	if (restantes < 0 || nGirl >= M)
		return 0;
	if (state[nGirl][restantes] != -1)
		return state[nGirl][restantes];
	int max = 0;
	for (int i = 0; i <= girls[nGirl]; i++){
		max += getNumber(restantes - i, nGirl + 1, M);
	}
	state[nGirl][restantes] = max;
	return max;
}

int main(){
	int M, N;
	cin >> M >> N;

	while (!(M == 0 && N == 0)){
		int min, max;
		for (int i = 0; i < M; i++){
			cin >> min;
			N -= min;
			cin >> max;
			girls[i] = max-min;
		}
			if (N < 0){
				cout << 0 << endl;
				continue;
			} else if (N == 0){
				cout << 1 << endl;
				continue;
			}

		for (int y = 0; y < 21; y++){
			for (int x = 0; x < 101; x++){
				state[y][x] = -1;
			}
		}
	
		cout << getNumber(N, 0, M) << endl;;

		cin >> M >> N;
	}

}