#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> ladders;
int pos[1000000];

int main(){
	int T;
	cin >> T;
	while (T-- > 0){
		ladders.clear();
		int players, snakes, rolls;
		cin >> players >> snakes >> rolls;
		for (int i = 0; i < players; i++)
			pos[i] = 1;
		int n1,n2;
		while (snakes-- > 0){
			cin >> n1 >> n2;
			ladders[n1] = n2;
		}
		int curPlayer = 0;
		while(rolls-- > 0){
			cin >> n1;
			pos[curPlayer] += n1;
			if(ladders.count(pos[curPlayer]) == 1){
				pos[curPlayer] = ladders[pos[curPlayer]];
			}
			pos[curPlayer] = min(pos[curPlayer], 100);
			if (pos[curPlayer] == 100)
				break;
			curPlayer = (curPlayer+1)%players;
		}

		while(rolls-- >0 ){
			cin >> n1;
		}
		curPlayer = 0;
		while (curPlayer++ < players){
			cout << "Position of player " << curPlayer << " is " << pos[curPlayer-1] << ".\n";
		}
	}
}