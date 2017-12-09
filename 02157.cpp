#include <iostream>
#include <string>
#include <sstream>
using namespace std;
 //Compiler version g++ 6.3.0
int numbers[3] = {0};
 int main()
 {
 	int q;
 	string s;
 	cin >> q;
 	while (q > 0){
 		cin >> s;
 		if (s.find("machula") != string::npos){
 			cin >> s;
 			cin >> numbers[1];
 			cin >> s;
 			cin >> numbers[2];
 			numbers[0] = numbers[2] - numbers[1];
 			cout << numbers[0] << " + " << numbers[1] << " = " << numbers[2] << endl;
 			q--;
 			continue;
 		}
 		stringstream(s) >> numbers[0];
 		cin >> s;
 		cin >> s;
 		if (s.find("machula") != string::npos){
 			cin >> s;
 			cin >> numbers[2];
 			numbers[1] = numbers[2] - numbers[0];
 			cout << numbers[0] << " + " << numbers[1] << " = " << numbers[2] << endl;
 			q--;
 			continue;
 		}

 		stringstream(s) >> numbers[1];
 		cin >> s;
 		cin >> s;

 		cout << numbers[0] << " + " << numbers[1] << " = " << numbers[1] + numbers[0] << endl;
 		q--;
 	}
 }
