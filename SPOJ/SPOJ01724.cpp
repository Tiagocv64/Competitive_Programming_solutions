#include <iostream>

using namespace std;

int main(){
    long long q, n, r;
    cin >> q;
    while (q > 0){
        cin >> n;
        r = (n*(n+2)*(2*n+1))/8;
        cout << r << endl;
        q--;
    }
}
