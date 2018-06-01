#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);

	string word, bestName;
	float bestMoney, curMoney;
	int req, prop, RFP = 1, curReq, bestReq, i, x;
	cin >> req >> prop;
	while (req != 0 && prop != 0){
		bestMoney = 10000000;
		bestReq = -1;

		cin.ignore(200, '\n');
		for (i = 0; i < req; i++)
			cin.ignore(200, '\n');

		for (i = 0; i < prop; i++){
			getline(cin, word);
			cin >> curMoney >> curReq;
			if (bestReq < curReq){
				bestName = word;
				bestReq = curReq;
				bestMoney = curMoney;
			} else if (bestReq == curReq){
				if (bestMoney > curMoney){
					bestName = word;
					bestReq = curReq;
					bestMoney = curMoney;
				}
			}
			cin.ignore(200, '\n');		
			
			for (x = 0; x < curReq; x++)
				cin.ignore(200, '\n');
		}
		cout << "RFP #" << RFP++ << "\n" << bestName << "\n";
		cin >> req >> prop;
		if (req != 0 && prop != 0)
			cout << "\n";
	}
}