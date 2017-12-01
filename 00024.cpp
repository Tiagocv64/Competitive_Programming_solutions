#include <iostream>

using namespace std;
int factorial[105][160];

int main()
{
    factorial[1][0] = 1;
    for (int i = 2; i < 101 ; i++){
        int carry = 0;
        for (int j = 0 ; j < 160 ; j++){
            int result = factorial[i-1][j] * i + carry;
            factorial[i][j] = result % 10;
            carry = result / 10;
        }
    }
    int q;
    cin >> q;
    while (q > 0){
        int n;
        cin >> n;
        bool start = false;
        for (int j = 159 ; j >= 0 ; j--){
            if (start){
                cout << factorial[n][j];
                continue;
            }
            if (factorial[n][j] != 0){
                start = true;
                cout << factorial[n][j];
                continue;
            }
        }
        cout << endl;
        --q;
    }
}


