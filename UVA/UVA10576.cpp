#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int s, d;

int solve(vector<int> v, int soma){
    if (v.size() > 4){
        int balance = 0;
        for (int j = v.size()-5; j < v.size(); j++){
            balance += v[j];
        }
        if (balance >= 0)
            return -1;        
    }
    if (v.size() == 12)
        return soma;
        
    v.push_back(s);
    int M = solve(v, soma+s);
    v[v.size()-1] = d;
    M = max(M, solve(v, soma+d));
    return M;    
}

int main(){

    while (cin >> s >> d){
        vector<int> v;
        d = -d;
        int ans = solve(v, 0);
        if (ans != -1)
            cout << ans << endl;
        else 
            cout << "Deficit" << endl;
    }
}