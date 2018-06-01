#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<string,string> > vec;

bool compPair(pair<string, string> p1, pair<string, string> p2){
	return p1.second < p2.second;
}

int main(){
	int T;
	cin >> T;
	cin.ignore(); cin.ignore();
	while(T-- > 0){
		vec.clear();
		string word, line;
		while(getline(cin, line) && line != ""){
			word = line;
			word.erase(remove(word.begin(), word.end(), ' '), word.end());
			sort(word.begin(), word.end());
			vec.push_back(make_pair(word, line));
		}
		sort(vec.begin(), vec.end(), compPair);
		for(int i = 0; i < vec.size(); i++){
			for (int j = i +1; j < vec.size(); j++){
				if (vec.at(i).first == vec.at(j).first){
					cout << vec.at(i).second << " = " << vec.at(j).second << "\n";
				}
			}
		}
		if (T != 0)
			cout << "\n";
	}



}