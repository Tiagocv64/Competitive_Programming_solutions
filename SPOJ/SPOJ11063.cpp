#include <iostream>

using namespace std;

int main(){
    int q;
    long long f3, l3, sum;
    cin >> q;
    while (q > 0){
        cin >> f3 >> l3 >> sum;
        long long length = sum * 1.0 / ((f3+l3) / 2.0);
        long long term = (l3 - f3) / (length -5);

        cout << length << endl;

        long long initial = f3 - (term * 2);

        for (int i=0 ; i < length -1; i++){
            cout << initial + i*term<< " ";
        }
        cout << initial + (length-1) * term << endl;
        q--;
    }
}
