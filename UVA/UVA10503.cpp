#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int n, m;
pair<int, int> l, r;
bool possible;

void solve(vector< pair<int,int> > v, int index, int last){
    if (possible)
        return;
    if (index == n && last == r.first){
        possible = true;
        return;
    }
    for (int i = 0; i < v.size(); i++){
        if (last == v[i].first){
            pair<int,int> tmp = v[i];
            v[i] = make_pair(-1,-1);
            solve(v, index+1, tmp.second);
            v[i] = tmp;
        } else if (last == v[i].second){
            pair<int,int> tmp = v[i];
            v[i] = make_pair(-1,-1);
            solve(v, index+1, tmp.first);
            v[i] = tmp;
        }
    }
}

int main(){
    while (cin >> n && n != 0){
        cin >> m;
        int left, right;
        cin >> left >> right;
        l = make_pair(left, right);
        cin >> left >> right;
        r = make_pair(left, right);
        vector< pair<int,int> > v;
        for (int i = 0; i < m; i++){
            cin >> left >> right;
            v.push_back(make_pair(left, right));
        }
        possible = false;
        solve(v, 0, l.second);

        if (possible)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}