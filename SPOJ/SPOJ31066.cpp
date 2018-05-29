#include <iostream>
#include <vector>

using namespace std;

bool posPrimes[500001];
vector<int> primes;

int main(){

	for (int i = 0; i < 500001; i++)
		posPrimes[i] = true;

	for (int i = 2; i < 500001; i++){
		if (!posPrimes[i]) continue;
		primes.push_back(i);
		int number = i + i;
		while (number <= 500001){
			posPrimes[number] = false;
			number += i;
		}
	}

	int testes, current = 1, given, found = 0;
	cin >> testes;

	while (current <= testes){
		cin >> given;
		cout << "Case " << current++ << ": ";

		for (int i = 0; i < primes.size(); i++){
			if (given % primes.at(i) == 0){
				cout << primes.at(i) << " ";
				found++;
			}
		}

		if (found == 0)
			cout << given << " ";
		
		cout << endl;
		found = 0;
	}

}