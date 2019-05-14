#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<char, vector<int> > m;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        m[s[i]].push_back(i);

    int q;
    cin >> q;
    while (q-- > 0){
        cin >> s;
        bool possible = true;
        int ansb = -1, anse = -1;
        int pos = 0;
        vector<int>::iterator it;
        it = lower_bound(m[s[0]].begin(), m[s[0]].end(), pos);
        if (it == m[s[0]].end())
            possible = false;
        else {
            ansb = *it;
            pos = (*it)+1;
        }
        for (int i = 1; i < s.size()-1; i++){
            it = lower_bound(m[s[i]].begin(), m[s[i]].end(), pos);
            if (it == m[s[i]].end())
                possible = false;
            else
                pos = (*it)+1;
        }
        it = lower_bound(m[s[s.size()-1]].begin(), m[s[s.size()-1]].end(), pos);
        if (it == m[s[s.size()-1]].end())
            possible = false;
        else {
            anse = *it;
            pos = (*it)+1;
        }
        if (possible)
            cout << "Matched " << ansb << " " << anse << "\n";
        else 
            cout << "Not matched\n";
    }
}