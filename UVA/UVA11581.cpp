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

int before[3][3], after[3][3];

int main(){
  TESTS(T){
    char c;
    LOOP(i,0,3)
      LOOP(j,0,3)
        if (cin >> c && c == '1'){
          before[i][j] = 1;
        } else {
          before[i][j] = 0;
        }
    int ans = -1;
    while (true){
      bool done = true;
      LOOP(i,0,3)
        LOOP(j,0,3){
          if (before[i][j] != 0)
            done = false;
        }

      if (done)
        break;

      LOOP(i,0,3)
        LOOP(j,0,3){
          int count = 0;
          if (i-1 >= 0 && before[i-1][j] == 1)
            count++;
          if (i+1 < 3 && before[i+1][j] == 1)
            count++;
          if (j-1 >= 0 && before[i][j-1] == 1)
            count++;
          if (j+1 < 3 && before[i][j+1] == 1)
            count++;
          after[i][j] = count%2;
        }

        LOOP(i,0,3)
          LOOP(j,0,3)
            before[i][j] = after[i][j];


      ans++;
    }
    cout << ans << "\n";
  }
}
