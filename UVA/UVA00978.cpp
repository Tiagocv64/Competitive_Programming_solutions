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

struct classcomp{
  bool operator() (int l, int r){ return l > r;}
};

int main(){
  TESTS(N){
    int fields, NB, NG;
    cin >> fields >> NG >> NB;
    multiset<int, classcomp> SB, SG;
    vector<int> remB, remG;
    int cur;
    while(NG-- > 0){
      cin >> cur;
      SG.insert(cur);
    }
    while(NB-- > 0){
      cin >> cur;
      SB.insert(cur);
    }
    while(!SB.empty() && !SG.empty()){
      cur = fields;
      multiset<int, classcomp>::iterator iB, iG;
      iB = SB.begin(); iG = SG.begin();
      remB.clear(); remG.clear();
      while (cur-- > 0 && iB != SB.end() && iG != SG.end()){
        if (*iB > *iG){
          remB.pb(*iB-*iG);
        } else if (*iB < *iG){
          remG.pb(*iG-*iB);
        }
        iB++; iG++;
      }
      SB.erase(SB.begin(), iB);
      SG.erase(SG.begin(), iG);
      LOOP(i,0,remB.size())
        SB.insert(remB[i]);
      LOOP(i,0,remG.size())
        SG.insert(remG[i]);
    }
    if (SB.empty() && SG.empty()){
      cout << "green and blue died\n";
    } else if (SB.empty()){
      cout << "green wins\n";
      FOREACH(it,SG)
        cout << *it << "\n";
    } else {
      cout << "blue wins\n";
      FOREACH(it,SB)
        cout << *it << "\n";
    }
    if (N > 0)
      cout << "\n";
  }
}
