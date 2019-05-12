#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > ans;

void solve(vector<int> v){
    if (v.size() == 8){
        ans.push_back(v);
        return;
    }
    bool possible[8];
    int pos = v.size();
    for (int i = 0; i < 8; i++)
        possible[i] = true;
    for (int i = 0; i < v.size(); i++){
        possible[v[i]] = false;
        if (v[i] + pos - i < 8)
            possible[v[i] + pos - i] = false;
        if (v[i] - pos + i >= 0)
            possible[v[i] - pos + i] = false;
    }
    v.push_back(0);
    for (int i = 0; i < 8; i++){
        if (possible[i]){
            v[pos] = i;
            solve(v);
        }
    }        
}

int table[8];

int main(){
    vector<int> v;
    solve(v);
    int T = 1;
    while (cin >> table[0]){
        for (int i = 1; i < 8; i++)
            cin >> table[i];

        int steps = 8;
        int cur;
        for (auto & vec : ans){
            cur = 0;
            for (int i = 0; i < 8; i++){
                if (table[i]-1 != vec[i])
                    cur++;
            }
            steps = (steps > cur)? cur : steps;
        }

        cout << "Case " << T++ << ": " << steps << endl;
    }
}