#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, char> reverses;

int main(){
	reverses['A'] = 'A';
	reverses['E'] = '3';
	reverses['H'] = 'H';
	reverses['I'] = 'I';
	reverses['J'] = 'L';
	reverses['L'] = 'J';
	reverses['M'] = 'M';
	reverses['O'] = 'O';
	reverses['S'] = '2';
	reverses['T'] = 'T';
	reverses['U'] = 'U';
	reverses['V'] = 'V';
	reverses['W'] = 'W';
	reverses['X'] = 'X';
	reverses['Y'] = 'Y';
	reverses['Z'] = '5';
	reverses['1'] = '1';
	reverses['2'] = 'S';
	reverses['3'] = 'E';
	reverses['5'] = 'Z';
	reverses['8'] = '8';
	
	string word;
	while(cin >> word){
		bool regular = true, inverted = true;
		for (int i = 0; i < word.size()/2; i++){
			if (word.at(i) != word.at(word.size()-1-i)){
				regular = false;
				break;
			}
		}

		for (int i = 0; i < word.size(); i++){
			if (reverses.count(word.at(word.size()-1-i)) == 1){
				if (word.at(i) != reverses[word.at(word.size()-1-i)]){
					inverted = false;
					break;
				}
			} else {
				inverted = false;
				break;
			}
		}

		if (regular && inverted){
			cout << word << " -- is a mirrored palindrome.\n\n";
		} else if (regular){
			cout << word << " -- is a regular palindrome.\n\n";
		} else if (inverted){
			cout << word << " -- is a mirrored string.\n\n";
		} else {
			cout << word << " -- is not a palindrome.\n\n";
		}
	}
}