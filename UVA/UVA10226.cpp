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
#include <list>
#include <stack>
#include <queue>

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
  int T;
  cin >> T;
  cin.ignore();
  cin.ignore();
  while (T-- > 0){
    map<string, int> trees;    
    string line;
    int total = 0;
    while(getline(cin, line) && line != ""){
      total++;
      if (PRESENT(trees, line))
        trees[line]++;
      else
        trees[line] = 1;
    }
    FOREACH(it, trees){
      cout << it->fi << " " << fixed << setprecision(4) << ((float)it->se)*100/total << "\n";
    }
    if (T != 0)
      cout << "\n";
  }
}
