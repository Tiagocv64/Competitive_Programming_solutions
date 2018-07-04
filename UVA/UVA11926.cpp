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
  int oneTasks, repTasks;
  while (cin >> oneTasks >> repTasks && (oneTasks != 0 || repTasks != 0)){
    bitset<1000001> minutes;
    int start, finish, interval;
    bool possible = true;
    while (oneTasks-- > 0){
      cin >> start >> finish;
      if (possible){
        LOOP(i,start,finish){ // -1 on purpose
          if (minutes[i]){
            possible = false;
            break;
          }
          minutes[i] = true;
        }
      }
    }
    while (repTasks-- > 0) {
      cin >> start >> finish >> interval;
      int curInter = 0;
      while (curInter + start < 1000001 && possible){
        for (int i = curInter+start;i < curInter+finish && i < 1000001; i++){
          if (minutes[i]){
            possible = false;
            break;
          }
          minutes[i] = true;
        }
        curInter += interval;
      }
    }
    if (possible){
      cout << "NO CONFLICT\n";
    } else {
      cout << "CONFLICT\n";
    }
  }
}
