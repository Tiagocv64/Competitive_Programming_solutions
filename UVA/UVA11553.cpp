#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    int table[8][8];
    while (T-- > 0){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> table[i][j];

        string s = "";
        for (int i = 0; i < n; i++)
            s += '0' + i;

        int minB = 100000;
        do {
            // cout << s << endl;
            int cur = 0;
            for (int i = 0; i < s.size(); i++){
                cur += table[i][s[i]-'0'];
            }
            minB = (minB > cur)? cur : minB;
        } while (next_permutation(s.begin(), s.end()));

        cout << minB << endl;
    }
    
}