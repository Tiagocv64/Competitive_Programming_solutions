#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> list, ans;
map<string, string> mymap;

int main(){
	string word, cur;
	while (cin >> word && word != "#"){
		cur = word;
		transform(cur.begin(), cur.end(), cur.begin(), ::tolower);
		sort(cur.begin(), cur.end());
		mymap[cur] = word;
		list.push_back(cur);
	}

	sort(list.begin(), list.end());

	bool valid = true;
	for (int i = 0; i < list.size(); i++){
		valid = true;
		if(i > 0 && list.at(i) == list.at(i-1))
			valid = false;
		if (i < list.size()-1 && list.at(i) == list.at(i+1))
			valid = false;
		if (valid)
			ans.push_back(mymap[list.at(i)]);
	}
	sort(ans.begin(), ans.end());
	for (string w : ans){
		cout << w << "\n";
	}

}