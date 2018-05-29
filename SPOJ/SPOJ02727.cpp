#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 int main()
 {
    int q;
    cin >> q;

    while (q > 0){

        int godN, megaN;
        cin >> godN >> megaN;
        vector<int> godArmy (godN);
        vector<int> megaArmy (megaN);
        for (int i = 0 ; i < godN; i++)
            cin >> godArmy.at(i);

        for (int i = 0 ; i < megaN; i++)
            cin >> megaArmy.at(i);

        sort(godArmy.begin(), godArmy.end());
        sort(megaArmy.begin(), megaArmy.end());

        int g = 0, m = 0;

        while (g != godN && m != megaN){
            if (godArmy.at(g) < megaArmy.at(m)){
                g++;
            } else {
                m++;
            }
        }

        if (g == godN){
            cout << "MechaGodzilla" << endl;
        } else {
            cout << "Godzilla" << endl;
        }

        q--;
    }
 }
