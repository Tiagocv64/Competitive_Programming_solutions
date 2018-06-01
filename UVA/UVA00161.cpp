#include <iostream>
#include <algorithm>

using namespace std;

int lights[105];

int MAX = 18001;

int main(){
	int n, minV, ans;
	while(cin >> lights[0] >> lights[1] >> lights[2]){
		minV = 100000000; ans = -1;		
		if (lights[0] == 0 && lights[1] == 0 && lights[2] == 0)
			break;

		if (lights[2] != 0){
			n = 3;
			minV = min(minV, lights[0]);
			minV = min(minV, lights[1]);
			minV = min(minV, lights[2]);
			while(cin >> lights[n] && lights[n] != 0){
				minV = min(minV, lights[n]);
				n++;
			}
		} else {
			n = 2;
			minV = min(minV, lights[0]);
			minV = min(minV, lights[1]);
		}

		for (int t = minV; t < MAX; t++){
			int times = 0;
			for (int i = 0; i < n; i++){
				int div = t/lights[i];
				int resto = t%lights[i];
				if (div % 2 == 0 && resto < lights[i]-5){
					times++;
				} else {
					break;
				}
			}
			if (times == n){	
				ans = t;
				break;
			}
		}

		if (ans == -1){
			cout << "Signals fail to synchronise in 5 hours\n";
		} else {
			int h = ans/3600;
			ans %= 3600;
			int m = ans/60;
			int s = ans%60;
			cout << "0" << h << ":";
			if (m < 10)
				cout << "0";
			cout << m << ":";
			if(s < 10)
				cout << "0";
			cout << s << "\n";
		}
	} 

}