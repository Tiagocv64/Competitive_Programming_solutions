#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    while (T-- > 0){
        int a,b,c;
        cin >> a >> b >> c;
        bool sol = false;
        for (int x = -10000; x <= 10000; x++){
            for (int y = x+1; x*x+y*y <= c; y++){
                int z = a-x-y;
                if (z <= y)
                    continue;
                if (x*y*z == b && x*x+y*y+z*z == c){
                    cout << x << " " << y << " " << z << endl;
                    sol = true;
                }
                if (sol)
                    break;
            }
            if (sol)
                break;
        }
        if (!sol)
            cout << "No solution.\n";
    }
}
