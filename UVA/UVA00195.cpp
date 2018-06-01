#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool mysort(char c1, char c2){
	if (c1 == c2){
		return false;
	} else if (toupper(c1) == c2){
		return false;
	} else if (toupper(c2) == c1){
		return true;
	} else if(toupper(c1) < toupper(c2)) {
		return true;
	} else {
		return false;
	}
}

int main(){
	int T;
	cin >> T;
	while(T-- > 0){
		string word;
		cin >> word;
		sort(word.begin(), word.end(), mysort);
		do {
			cout << word << "\n";
		} while (next_permutation(word.begin(), word.end(), mysort));
	}

}