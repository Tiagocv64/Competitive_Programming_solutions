#include <iostream>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q > 0){
        int n, ans = 0;
        cin >> n;
        for (int i = 5 ; i <= n ; i= i * 5){
            ans += n/i;
        }
        cout << ans << endl;
        --q;
    }
}


