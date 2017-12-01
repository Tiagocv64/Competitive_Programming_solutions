#include <iostream>

using namespace std;

int main()
{
    int q, x, y;
    cin >> q;
    while (q > 0){
        cin >> x >> y;
        if ((x == y+2 || x == y) && (x >= 0 && y >= 0)){
            if (y % 2 == 0){
                if (x == y){
                    cout << y*2 << endl;
                } else {
                    cout << y*2+2 << endl;
                }
            }else{
                if(x == y){
                    cout << (y-1) * 2 + 1 << endl;
                } else {
                    cout << (y-1) * 2 + 3 << endl;
                }
            }
        }else {
            cout << "No Number\n";
        }
        --q;
    }
}

