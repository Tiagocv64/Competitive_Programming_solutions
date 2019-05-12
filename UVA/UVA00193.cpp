#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

vector<int> e[105];
int n, m;
int ans;
bitset<105> vec;

void solve(int index, bitset<105> blacks, int count){
    if (count > ans){
        ans = count;
        vec = blacks;
    }
    if (n-index+1 + count < ans)
        return;
    if (index > n)
        return;
    
    solve(index+1, blacks, count);

    bool possible = true;

    for (int j = 0; j < e[index].size(); j++){
        if (blacks[e[index][j]]){
            possible = false;
        }
    }

    if (possible){
        blacks[index] = true;
        solve(index+1, blacks, count+1);
    }
}

int main(){
    int t;
    cin >> t;
    while (t-- > 0){
        cin >> n >> m;
        for (int i = 0; i <= n; i++){
            e[i].clear();
            e[i].push_back(i);
        }
            
        int l, r;
        for (int i = 0; i < m; i++){
            cin >> l >> r;
            e[l].push_back(r);
            e[r].push_back(l);
        }
        ans = 0;
        bitset<105> v;
        solve(1, v, 0);
        cout << ans << endl;
        int c = 0;
        for (int i = 0; i < vec.size(); i++)
            if (vec[i]){
                if (c + 1 == ans){
                    cout << i << endl;
                    break;
                } else {
                    cout << i << " ";
                    c++;
                }
            }
    }


}