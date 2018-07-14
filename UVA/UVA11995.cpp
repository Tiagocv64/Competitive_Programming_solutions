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
#include <unordered_set>

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
  int N;
  while (cin >> N){
    int op, num;
    stack<int> st;
    queue<int> q;
    priority_queue<int> pq;
    bool canStack = true, canQueue = true, canPQ = true;
    while (N-- > 0){
      cin >> op >> num;
      if (op == 1){
        st.push(num);
        q.push(num);
        pq.push(num);
      } else {
        try{
          if ( st.size() == 0 || num != st.top())
            canStack = false;
          if (canStack) st.pop();
          } catch (...){
            canStack = false;
          }
        try{
          if (q.size() == 0 || num != q.front())
            canQueue = false;
          if (canQueue) q.pop();
        } catch (...){
          canQueue = false;
        }
        try{
          if ( pq.size() == 0 || num != pq.top())
            canPQ = false;
          if (canPQ) pq.pop();
        }catch (...){
          canPQ = false;
        }
      }
    }
    if (!canStack && !canPQ && !canQueue){
      cout << "impossible\n";
    } else if (canStack && !canPQ && !canQueue){
      cout << "stack\n";
    } else if (!canStack && canPQ && !canQueue){
      cout << "priority queue\n";
    } else if (!canStack && !canPQ && canQueue){
      cout << "queue\n";
    } else {
      cout << "not sure\n";
    }
  }
}
