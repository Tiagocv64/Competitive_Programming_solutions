#include <iostream>
#include <math.h>

using namespace std;

int main(){
   double n;
   cin >> n;
    while (n != 0){
        double answer;
        n /= M_PI;
        n *= n;
        n *= M_PI;
        n /= 2.0;

        printf("%.2f\n", n);

        cin >> n;
    }
}
