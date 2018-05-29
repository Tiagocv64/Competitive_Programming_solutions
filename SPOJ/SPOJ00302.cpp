#include <iostream>

using namespace std;

 int main()
 {
    int q;
    cin >> q;

    while (q > 0){
        int n , m;
        cin >> n;
        m = n;
        int i = 1;
        for (; i < 10000000 ; i++){
            m-=i;
            if (m <= 0){
                break;
            }
        }

        int left = i + m;
        int right = (i+1) - left;

        cout << "TERM " << n << " IS ";

        if (i % 2 == 0){
            cout << left << "/" << right << endl;
        } else {
            cout << right << "/" << left << endl;
        }

        q--;
    }
 }
