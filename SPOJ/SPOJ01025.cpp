#include <iostream>
#include <algorithm>

using namespace std;

int pairsX[1005] = {0};
int pairsY[1005] = {0};

int main()
{
    int q;
    cin >> q;
    while (q > 0){
        int n , sum = 0;;
        cin >> n;
        int i = 0;
        while (i < n){
            cin >> pairsX[i];
            i++;
        }
        i = 0;

        while (i < n){
            cin >> pairsY[i];
            i++;
        }
        sort(pairsX, pairsX + n);
        sort(pairsY, pairsY + n);
        i = 0;
        while (i < n){
            sum += pairsX[i] * pairsY[i];
            i++;
        }

        cout << sum << endl;
        q--;
    }
}

