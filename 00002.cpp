#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int q , n1, n2;
    cin >> q;
    while (q > 0){
        cin >> n1 >> n2;
        for (int i = n1 ; i <= n2 ; i++){
            if (i == 1)
                continue;
            if(i == 2){
                cout << i << endl;
                continue;
            }
            bool prime = true;
            for (int j = 2 ; j <= sqrt(i) +1; j++){
                if (i % j == 0){
                prime = false;
                    break;
                }
            }
            if (prime)
                cout << i <<endl;

        }
        cout << endl;
        --q;
    }
}


