#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int nMonths, nDown, month;
	float moneyDown, total, carValue , lossRate, rentMonth;
	cin >> nMonths >> moneyDown >> total >> nDown;

	while (nMonths >= 0){
		carValue = total + moneyDown; 
		rentMonth = total/nMonths;
		cin >> month >> lossRate;
		carValue -= carValue*lossRate;
		if (nDown > 1) cin >> month;
		nDown-= 2;
		if (carValue > total){
				cout << 0 << " months\n";	
				for (int i = 0; i < nDown; i++)
					cin >> lossRate >> month;
				if (nDown > -1)
					cin >> lossRate;
				cin >> nMonths >> moneyDown >> total >> nDown;
				continue;
		}
		for (int i = 1; i <= nMonths; i++){
			if (i == month){
				if (nDown <= 0){
					cin >> lossRate;
					carValue -= carValue*lossRate;
					nDown--;
				} else {
					cin >> lossRate >> month;
					nDown--;
					carValue -= carValue*lossRate;
				}								
			} else {
				carValue -= carValue*lossRate;
			}
			total -= rentMonth;
			
			if (carValue > total){
				if (i == 1){
					cout << i << " month\n";
				} else {
					cout << i << " months\n";
				}
				for (int i = 0; i < nDown; i++)
					cin >> lossRate >> month;
				if (nDown > -1)
					cin >> lossRate;
				break;
			}
		}
		cin >> nMonths >> moneyDown >> total >> nDown;
	}
}