#include <iostream>
#include <set>
#include <string>

using namespace std;

int t, n;

int num[15];
set<string> ans;

void solve(int index, int count, string s){
    if (count == t){
        ans.insert(s);
        return;
    }
    if (count > t)
        return;
    if (index >=n)
        return;
    
    solve(index+1, count, s);
    if (count == 0){
        solve(index+1, count+num[index], s + to_string(num[index]));
    } else {
        solve(index+1, count+num[index], s + "+" + to_string(num[index]));
    }
}

int main(){
    while (cin >> t >> n && n != 0){
        for (int i = 0; i < n; i++)
            cin >> num[i];
        ans.clear();
        solve(0,0,"");
        cout << "Sums of " << t << ":\n";
        for (set<string>::reverse_iterator it = ans.rbegin(); it != ans.rend(); it++)
            cout << *it << endl;
        if (ans.size() == 0)
            cout << "NONE\n";
    }
}