#include <iostream>
#include <vector>

using namespace std;

int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int n;

bool isprime(int el){
    for (int i = 0; i < 11; i++)
        if (primes[i] == el)
            return true;

    return false;
}

void solve(vector<int> v){
    if (v.size() == n){
        if (!isprime(v[v.size()-1] + v[0]))
            return;

        for (int i = 0; i < v.size()-1; i++)
            cout << v[i] << " ";
        cout << v[v.size()-1] << endl;
        return;
    }
    bool possible[17];
    for (int i = 0; i <= n; i++)
        possible[i] = true;
    for (auto & el : v)
        possible[el] = false;

    int index = v.size();
    v.push_back(0);

    for (int i = 1; i <= n; i++)
        if (possible[i]){
            if (index == 0){
                v[index] = 1;
                solve(v);
                return;
            } else {
                if (isprime(v[index-1] + i)){
                    v[index] = i;
                    solve(v);
                }
            }
        }
    
}

int main(){
    int T = 1;
    while (cin >> n){
        if (T != 1)
            cout << endl;
        cout << "Case " << T++ << ":\n";
        vector<int> v;
        solve(v);
    }
}