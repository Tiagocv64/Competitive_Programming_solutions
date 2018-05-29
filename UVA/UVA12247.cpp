#include <iostream>
#include <algorithm>

using namespace std;

int a,b,c,x,y;

bool testPossible(int n){
	int G[] = {a,b,c};
	int B[] = {x,y,n};
	sort(G, G+3);
	do {
		int points = 0;
		for (int i = 0; i < 3; i++)
			if(B[i] >= G[i])
				points++;
		if (points < 2)
			return false;
	} while (next_permutation(G, G+3));
	return true;
}

bool testExists(int n){
	return n==a || n==b || n==c || n==x || n==y;
}

int main(){

	cin >> a >> b >> c >> x >> y;
	while ( a|b|c|x|y != 0){
	
		int lo = 1, hi = 53, mid;
		while (lo < hi){
			mid = (hi+lo)/2;
			if (testPossible(mid)){
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}

		for (int i = lo; i <= 53; i++){
			if (!testExists(i)){
				lo = i;
				break;
			}
		}

		if (lo == 53){
			cout << -1 << endl;
		} else {
			cout << lo << endl;
		}
		cin >> a >> b >> c >> x >> y; 
	}
}