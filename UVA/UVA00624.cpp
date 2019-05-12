#include <iostream>
#include <string>

using namespace std;

int tracks[25];
int n;
int p;
string ans;
int ansM;

void solve(int i, int count, string s){
    if (count > n)
        return;
    if (ansM < count){
        ans = s;
        ansM = count;
    }
    if (i >= p)
        return;
    solve(i+1, count+tracks[i], s + to_string(tracks[i]) + " ");
    solve(i+1, count, s);
}

int main(){

    while (cin >> n){
        cin >> p;
        for (int i = 0; i < p; i++)
            cin >> tracks[i];
        ans = "";
        ansM = 0;
        solve(0, 0, "");
        cout << ans << "sum:" << ansM << endl;
    }
}