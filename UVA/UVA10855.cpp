#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <math.h>
#include <sstream>
#include <iomanip>
#include <bitset>

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
	int N, n;
	while (cin >> N >> n && (N != 0 || n != 0)){
		cin.ignore();
		vector<string> big, small;
		LOOP(i,0,N){
			string line;
			getline(cin, line);
			big.pb(line);
		}
		LOOP(i,0,n){
			string line;
			getline(cin, line);
			small.pb(line);
		}
		int sol[] = {0,0,0,0};

		LOOP(Y,0,N-n+1){
			LOOP(X,0,N-n+1){
				bitset<4> match;
				LOOP(y,0,n){
					LOOP(x,0,n){
						if (small[y][x] != big[Y+y][X+x])
							match.set(0,1);
						if (small[n-x-1][y] != big[Y+y][X+x])
							match.set(1,1);
						if (small[n-y-1][n-x-1] != big[Y+y][X+x])
							match.set(2,1);
						if (small[x][n-y-1] != big[Y+y][X+x])
							match.set(3,1);
					}
				}
				if (!match[0])
					sol[0]++;
				if (!match[1])
					sol[1]++;
				if (!match[2])
					sol[2]++;
				if (!match[3])
					sol[3]++;
			}
		}
		LOOP(i,0,3)
			cout << sol[i] << " ";
		cout << sol[3] << "\n";
	}
}