#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string line, badChars = ".,!? ";
	while (getline(cin, line) && line != "DONE"){
		for (char c : badChars){
			line.erase(remove(line.begin(), line.end(), c), line.end());
		}
		transform(line.begin(), line.end(), line.begin(), ::tolower);

		bool isPalindrom = true;
		for (int i = 0; i < line.size(); i++){
			if (line.at(i) != line.at(line.size()-1-i)){
				isPalindrom = false;
				break;
			}
		}
		if (isPalindrom){
			cout << "You won't be eaten!\n";
		} else {
			cout << "Uh oh..\n";
		}
	}


}