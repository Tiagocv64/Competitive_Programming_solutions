#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int q, a, b;
    cin >> q;
    while (q > 0){
        cin >> a >> b;
        if (b == 0){
            cout << 1 << endl;
            q--;
            continue;
        }
        int ans = pow ((a % 10) , (b % 4 + 4));
        ans %= 10;
        cout << ans << endl;
        q--;
    }
}

