#include <iostream>
#include <math.h>
using namespace std;
 //Compiler version g++ 6.3.0

 int main()
 {
 	long long number;
 	bool found = false;
 	cin >> number;
 	for (int i = 0 ; i < 62 ; i++){
 		if (pow(2 , i) == number){
 			cout << "TAK" << endl;
 			found = true;
 		}
 	}
 	if (!found)
 		cout << "NIE" << endl;
 }