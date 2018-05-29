#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int seqA[10001], seqB[10001];
vector<int> corners;

int main(){
	int nA, nB;
	cin >> nA;
	while(nA != 0){
		corners.clear();
		for (int i = 0; i < nA; i++)
			cin >> seqA[i];
		cin >> nB;
		for (int i = 0; i < nB; i++)
			cin >> seqB[i];
		for (int i = 0; i < nA; i++)
			if(binary_search(seqB, seqB + nB, seqA[i]))
				corners.push_back(seqA[i]);

		int posA = 0, posB = 0, maxA = 0, maxB = 0;
		for (int i = 0; i < corners.size(); i++){
			int corner = corners.at(i);
			while (seqA[posA] != corner){
				maxA += seqA[posA];
				posA++;
			}
			while (seqB[posB] != corner){
				maxB += seqB[posB];
				posB++;
			}
			if (maxA > maxB){
				maxB = maxA + seqA[posA];
				maxA += seqA[posA];
			} else {
				maxA = maxB + seqB[posB];
				maxB += seqB[posB];
			}
			posA++;
			posB++;
		}

		while (posA < nA){
			maxA += seqA[posA];
			posA++;
		}
		while (posB < nB){
			maxB += seqB[posB];
			posB++;
		}

		cout << max(maxA, maxB) << endl;

		cin >> nA;
	}

}