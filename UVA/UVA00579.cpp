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

#define LOOP(i,l,r) for (int i = l; l < r; i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define PRESENT(c,x) ((c).find(x) != (c).end()) 
#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define IOS ios_base::sync_with_stdio(false); //to synchronize the input of cin and scanf
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
	float h, m;
	while (scanf("%f:%f", &h, &m) && (h != 0 || m != 0)){
		h = h*5+m/12;
		float ans = min(abs(m+60-h), abs(h-m))*6;
		ans = min(ans , abs(360-ans));
		cout << fixed << setprecision(3) << ans << "\n";
	}
}