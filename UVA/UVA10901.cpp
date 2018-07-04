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

struct car{
  int id;
  int time;
  string side;
};

car lista[10001];

int main(){
  TESTS(T){
    int n, t, m, cur;
    cin >> n >> t >> m;
    string side;
    LOOP(i,0,m){
      cin >> cur >> side;
      car c1;
      c1.id = i;
      c1.time = cur;
      c1.side = side;
      lista[i] = c1;
    }
    queue<car> left, right, boat;
    LOOP(i,0,m){
      if (lista[i].side == "right"){
        right.push(lista[i]);
      } else {
        left.push(lista[i]);
      }
    }
    car cfinal;
    cfinal.time = 1000000;
    cfinal.id = -1;
    cfinal.side = "right";
    right.push(cfinal);
    left.push(cfinal);
    side = "left";
    int curT = 0;
    while (left.front().time != 1000000 || right.front().time != 1000000){
      if (side == "left"){
        while (left.front().time <= curT && boat.size() < n){
          boat.push(left.front());
          left.pop();
        }
        if (boat.empty()){
          if (right.front().time < left.front().time){
            side = "right";
            curT = max(right.front().time + t, curT + t);
          } else {
            curT = max(left.front().time, curT);
          }
        } else {
          curT += t;
          side = "right";
          while(!boat.empty()){
            lista[boat.front().id].time = curT;
            boat.pop();
          }
        }
      } else {
        while (right.front().time <= curT && boat.size() < n){
          boat.push(right.front());
          right.pop();
        }
        if (boat.empty()){
          if (left.front().time < right.front().time){
            side = "left";
            curT = max(left.front().time + t, curT + t);
          } else {
            curT = max(right.front().time, curT);
          }
        } else {
          curT += t;
          side = "left";
          while(!boat.empty()){
            lista[boat.front().id].time = curT;
            boat.pop();
          }
        }
      }

    }
    LOOP(i,0,m)
      cout << lista[i].time << "\n";
    if (T != 0)
      cout << "\n";
  }
}
