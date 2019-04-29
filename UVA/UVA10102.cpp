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
#include <set>

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

int n[105][105];

int main(){
  int N;
  char c;
  while (cin >> N){
    for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
        cin >> c;
        n[i][j] = (int) c-'0';
      }
    }
    int min = 0;
    for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
        if (n[i][j] != 1) continue;
        int cur = 10000000;
        for (int y = 0; y < N; y++){
          for (int x = 0; x < N; x++){
            if (n[y][x] == 3)
              cur = std::min(cur, abs(i-y)+abs(j-x));
          }
        }
        min = max(min, cur);
      }
    }
    cout << min << endl;
  }
}
