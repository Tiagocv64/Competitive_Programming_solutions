#include <iostream>

using namespace std;

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    while (n1 != 0 || n2 != 0 || n3 != 0){
        int s1, s2, d1, d2;
        s1 = n2 - n1; s2 = n3 - n2;
        if(s1 == s2) {
            cout << "AP " << n3 + s1 << endl;
        } else {
            d1 = n2 / n1; d2 = n3 / n2;
            cout << "GP " << n3 * d1 << endl;
        }



        cin >> n1 >> n2 >> n3;
    }
}

