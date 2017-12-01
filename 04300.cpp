#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int j = 1 ; j <= n ; j++){
        for (int i = 1 ; i <= sqrt(j) ; i++){
            if(j % i == 0)
                ans++;
        }
    }
    cout << ans << endl;

}

