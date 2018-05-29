#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    unsigned long long  q, n;
    cin >> q;
    while (q > 0){
        cin >> n;
        if (n == 0){
            cout << "NO\n";
            --q;
            continue;
        }
        unsigned long long sum = 0, current;
        for (unsigned long long i = 0 ; i < n ; i++){
            cin >> current;
            sum = (sum % n + current % n) % n;
        }
        if (sum % n == 0){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        --q;
    }
}


