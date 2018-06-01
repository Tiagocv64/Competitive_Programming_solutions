#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<char> ans;

int main(){
	int round;
	string line;
	cin >> round;
	while(round != -1){
		cin >> line;
		ans.clear();
		for (int i = 0; i < line.size(); i++)
			ans.push_back(line.at(i));

		cin >> line;

		sort(ans.begin(), ans.end());

		vector<char>::iterator it;
		it = unique(ans.begin(), ans.end());
		ans.resize(distance(ans.begin(), it));

		int guessBadCount = 0;

		vector<char> guess;

		for (int i = 0; i < line.size(); i++){
			if (ans.size() == 0)
				break;
			if (find(guess.begin(), guess.end(), line.at(i)) != guess.end()){
				continue;
			} else {
				if (binary_search(ans.begin(), ans.end(), line.at(i))){
					ans.erase(remove(ans.begin(), ans.end(), line.at(i)), ans.end());
					guess.push_back(line.at(i));
				} else {
					guessBadCount++;
					guess.push_back(line.at(i));
				}
			}
		}

		cout << "Round " << round << endl;

		if (ans.size() == 0 && guessBadCount < 7){			
			cout << "You win.\n";
		} else if (guessBadCount >= 7) {
			cout << "You lose.\n";
		} else {
			cout << "You chickened out.\n";
		}

		cin >> round;
	}

}