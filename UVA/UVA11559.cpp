#include <iostream>

using namespace std;

int main(){
	int participantes, budget, hotels, weeks;
	while (cin >> participantes){
		cin >> budget >> hotels >> weeks;
		int min = 1000000000;

		while (hotels-- > 0){
			int precoPessoa, vagas;
			cin >> precoPessoa;
			for (int i = 0; i < weeks; i++){
				cin >> vagas;
				if (vagas >= participantes && precoPessoa * participantes <= budget)
					if (precoPessoa * participantes < min)
						min = precoPessoa * participantes;
			}
		}

		if (min == 1000000000){
			cout << "stay home" << endl;
		} else {
			cout << min << endl;
		}
	}
}