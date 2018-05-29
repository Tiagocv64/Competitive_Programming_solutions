#include <iostream>
#include <map>
#include <string>

using namespace std;

string cards[13];

int main(){

	std::map<char, int> mapSuits;
	std::map<char, bool> mapStopped;
	std::map<char, int> suitRank;

	while (cin >> cards[0]){
		suitRank['S'] = 3; suitRank['H'] = 2; suitRank['D'] = 1; suitRank['C'] = 0; 
		mapSuits['S'] = 0; mapSuits['D'] = 0; mapSuits['H'] = 0; mapSuits['C'] = 0;
		mapStopped['S'] = false; mapStopped['D'] = false; mapStopped['H'] = false; mapStopped['C'] = false;
		int points = 0, maxSuit = 0;
		char possibleSuit;
		mapSuits[cards[0].at(1)] += 1;
		for (int i = 1; i < 13; i++){
			cin >> cards[i];
			mapSuits[cards[i].at(1)] += 1;
		}
			
		for (int i = 0; i < 13; i++){
			char number = cards[i].at(0), suit = cards[i].at(1);
			if (number == 'A'){
				points += 4;
				mapStopped[suit] = true;
			} else if (number == 'K'){
				points += 3;
				if (mapSuits[suit] <= 1){
					points -= 1;
				} else {
					mapStopped[suit] = true;
				}
			} else if (number == 'Q'){
				points += 2;
				if (mapSuits[suit] <= 2){
					points -= 1;
				} else {
					mapStopped[suit] = true;
				}
			} else if (number == 'J'){
				points += 1;
				if (mapSuits[suit] <= 3)
					points -= 1;
			}
		}

		if (points >= 16 && mapStopped['S'] && mapStopped['D'] && mapStopped['H'] && mapStopped['C']){
			cout << "BID NO-TRUMP" << endl;
			continue;
		}

		for (map<char, int>::iterator it = mapSuits.begin(); it != mapSuits.end(); ++it){
			if (it->second < 2){
				points += 2;
			} else if (it->second == 2){
				points += 1;
			}
			if (it->second > maxSuit){
				maxSuit = it->second;
				possibleSuit = it->first;
			} else if (it->second == maxSuit && suitRank[it->first] > suitRank[possibleSuit]){
				maxSuit = it->second;
				possibleSuit = it->first;
			}
		}

		if (points < 14){
			cout << "PASS" << endl; 
		} else {
			cout << "BID " << possibleSuit << endl;
		}

	}
}