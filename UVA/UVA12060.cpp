#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <math.h>
#include <sstream>
#include <iomanip>

using namespace std;

#define LOOP(i,l,r) for (int i = l; i < r; i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure
#define TESTS(T) int T; cin >> T; while(T--)
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define PRESENT(c,x) ((c).find(x) != (c).end()) 
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end())
#define REMVAL(t,v) t.erase(remove(t.begin(),t.end(), v), t.end())
#define REMPOS(t,i) t.erase(t.begin()+i)
#define REMDUP(t) t.erase(unique(t.begin(), t.end() ), t.end());
#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define IOS ios_base::sync_with_stdio(false); //to desynchronize the input of cin and scanf
#define PI 3.1415926535897932384626
//for map, pair
#define mp make_pair
#define fi first
#define se second
//for vectors
#define pb push_back
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;

int main(){
	int n, T = 1;
	while (cin >> n && n != 0){
		int sum = 0, cur, i = 0, a = 0, b = 0, c = 0;
		while (i++ < n){
			cin >> cur;
			sum += cur;
		}
		bool negative = false;
		int l = sum, r = n, tmp;
		while(true){
			if (r == 0)
				break;
			tmp = l%r;
			l = r;
			r = tmp;
		}
		
		l = abs(l);

		b = sum/l; c = n/l; a = b/c; b = b%c;
		if (a < 0){
			negative = true;
			a = abs(a);
		}
		if(b < 0){
			b = abs(b);
			negative = true;
		}

		int nC = 0, nB = 0, nA = 0;
		tmp = c;
		while (tmp != 0){
			tmp/=10;
			nC++;
		}
		tmp = b;
		while (tmp != 0){
			tmp/=10;
			nB++;
		}
		tmp = a;
		while (tmp != 0){
			tmp/=10;
			nA++;
		}

		cout << "Case " << T++ << ":\n";

		if (b != 0 && a != 0){
			if (negative) {
				LOOP(i,0,nA+2)
					cout << " ";
				LOOP(i, 0, nC-nB)
					cout << " ";
				cout << b << "\n";
				cout << "- " << a;
				LOOP(i, 0, nC)
					cout << "-";
				cout << "\n";
				LOOP(i,0,nA+2)
					cout << " ";
				cout << c << "\n";
			} else {
				LOOP(i,0,nA)
					cout << " ";
				LOOP(i, 0, nC-nB)
					cout << " ";
				cout << b << "\n";
				cout << a;
				LOOP(i, 0, nC)
					cout << "-";
				cout << "\n";
				LOOP(i,0,nA)
					cout << " ";
				cout << c << "\n";
			}
		} else if (b == 0){
			if (negative) {
				cout << "- " << a << "\n";
			} else {
				cout << a << "\n";
			}
		} else { 
			if (negative) {
				LOOP(i,0,2)
					cout << " ";
				LOOP(i, 0, nC-nB)
					cout << " ";
				cout << b << "\n";
				cout << "- ";
				LOOP(i, 0, nC)
					cout << "-";
				cout << "\n";
				LOOP(i,0,2)
					cout << " ";
				cout << c << "\n";
			} else {
				LOOP(i, 0, nC-nB)
					cout << " ";
				cout << b << "\n";
				LOOP(i, 0, nC)
					cout << "-";
				cout << "\n";
				cout << c << "\n";
			}		
		}
	}
}