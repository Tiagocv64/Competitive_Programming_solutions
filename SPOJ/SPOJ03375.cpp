#include <iostream>
#include <algorithm>

using namespace std;
int friends[1000] = {0};

 int main()
 {
    int q;
    cin >> q;
    int t = 1;
    while (t <= q){
        int n , f;
        cin >> n >> f;

        for (int i = 0; i < f ; i++){
            cin >> friends[i];
        }

        sort(friends , friends + f , greater<int>());

        int sum = 0;
        int i;
        for (i = 0 ; i < f ; i++){
            sum += friends[i];
            if (sum >= n)
                break;
        }
        i++;
        cout << "Scenario #" << t << ":" << endl;
        if (sum >= n){
            cout << i << endl;
        } else {
            cout << "impossible" << endl;
        }
        cout << endl;
        t++;
    }
 }
