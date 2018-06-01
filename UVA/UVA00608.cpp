#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <math.h>
#include <sstream>

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
	TESTS(T){
		vector<char> real, heavier, lighter;
		string left, right, pos;
		LOOP(i,0,3){
			cin >> left >> right >> pos;
			if (pos == "even"){
				FOREACH(it, left)
					real.pb(*it);
				FOREACH(it, right)
					real.pb(*it);
			} else if ( pos == "up"){
				FOREACH(it, left)
					heavier.pb(*it);
				FOREACH(it, right)
					lighter.pb(*it);
				LOOP(c,'A','M'){
					if (!CPRESENT(left, c) && !CPRESENT(right,c))
						real.pb(c);
				}
			} else {
				FOREACH(it, left)
					lighter.pb(*it);
				FOREACH(it, right)
					heavier.pb(*it);
				LOOP(c,'A','M'){
					if (!CPRESENT(left, c) && !CPRESENT(right,c))
						real.pb(c);
				}
			}
		}
		sort(ALL(real)); sort(ALL(heavier)); sort(ALL(lighter));
		REMDUP(real); REMDUP(heavier); REMDUP(lighter);
		FOREACH(it, real){
			REMVAL(heavier, *it);
			REMVAL(lighter, *it);
		}
		FOREACH(it, heavier){
			if (CPRESENT(lighter, *it)){
				REMVAL(lighter, *it);
				REMVAL(heavier, *it);
				it--;
			}
		}
		if (heavier.size() == 1){
			cout << heavier.at(0) << " is the counterfeit coin and it is heavy.\n";
		} else {
			cout << lighter.at(0) << " is the counterfeit coin and it is light.\n";
		}
	}
}