#include <iostream>
#include <set>
#include <string>

using namespace std;

set<string> s1, s2;
string table1[6], table2[6];

void create1(int i, string s){
    if (i == 5){
        s1.insert(s);
        return;
    }
    for (int j = 0; j < 6; j++){
        create1(i+1, s + table1[j][i]);
    }
}

void create2(int i, string s){
    if (i == 5){
        s2.insert(s);
        return;
    }
    for (int j = 0; j < 6; j++){
        create2(i+1, s + table2[j][i]);
    }
}

int main(){
    int T, k;
    cin >> T;
    while (T-- > 0){
        cin >> k;
        for (int i = 0; i < 6; i++)
            cin >> table1[i];
        for (int i = 0; i < 6; i++)
            cin >> table2[i];
        s1.clear(); s2.clear();
        create1(0, "");
        create2(0, "");
        int count = 1;
        bool done = false;
        for (set<string>::iterator it = s1.begin(); it != s1.end(); it++){
            if (s2.count(*it) == 1){
                if (count == k){
                    cout << *it << "\n";
                    done = true;
                    break;
                } else
                    count++;
            }
        }
        if (!done)
            cout << "NO\n";
    }
}