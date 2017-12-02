#include <iostream>

using namespace std;

static long long coin[10000001] = {0};

long long maxcoin(long long n);

long long bettercoin(long long n){
    long long more = 0 , added = 0;
    for (int i = 1 ; i < 8 ; i++){
        added = 0;
        if (i & 1 == 1)
            added += maxcoin(n/2);
        if (i & 2 == 2)
            added += maxcoin(n/3);
        if (i & 4 == 4)
            added += maxcoin(n/4);
        more = max(added, more);
    }
    return more;
}

long long maxcoin(long long n){
    if ( n < 10000000)
        if (coin[n] != 0)
            return coin[n];
    if (n == 0)
        return 0;
    return coin[min(10000000LL, n)] = max(bettercoin(n) , n);
}

int main()
{
    ios::sync_with_stdio(false);
    coin[1] = 1;
    int number;
    while (cin >> number){
        cout << maxcoin(number) << "\n";
    }

}


