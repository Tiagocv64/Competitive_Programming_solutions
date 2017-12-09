#include <iostream>
#include <math.h>
using namespace std;
 //Compiler version g++ 6.3.0

 int main()
 {
 	float n;
 	cin >> n;
 	while (n != 0.00){
 		float current = 0.0;
 		float t = 2.0;
 		while (n > current) {
 			current += 1.0 / t ;
 			if (n - current < 0.000001){
 				current += 100.0;
 			}
 			t += 1;
 		}
 		t -= 2;
 		cout << t << " card(s)"<< endl;
 		cin >> n;
 	}
 }