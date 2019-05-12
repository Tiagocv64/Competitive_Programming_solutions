#include <iostream>

using namespace std;

int p, n;
int bars[25];
bool possible;

void solve(int i, int l){
    if (possible)
        return;
    if (l > p)
        return;
    if (i > n)
        return;
    if (l == p){
        possible = true;
        return;
    }
    solve(i+1, l);
    solve(i+1, l+bars[i]);
    return;
}

int main(){
    int T;
    cin >> T;

    while (T-- > 0){
        cin >> p;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> bars[i];
        possible = false;
        solve(0, 0);

        if (possible)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}