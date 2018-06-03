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

void makeRange(int b, int a){
	string before = to_string(b), after = to_string(a);
	LOOP(i,0,before.size()){
		if (before.at(i) != after.at(i)){
			cout << "0" << before.substr(0,i) << before.substr(i, before.size()-i) << "-" << after.substr(i, after.size()-i) << "\n";
			break;
		}
	}
}

int main(){
	IOS;
	int n, T = 1;
	while (cin >> n && n != 0){
				
		int before, current, next;
		cin >> before;
		next = before+1;
		n--;
		cout << "Case " << T++ << ":\n";
		while (n-- >= 0){
			if (n != -1)
				cin >> current;
			if (current == next){
				next++;
			} else {
				if (before == next-1){
					//nothing
					cout << "0" << before << "\n";
				} else {
					makeRange(before, next-1);
				}
				before = current;
				next = current+1;
			}
		}
		cout << "\n";
	}
}