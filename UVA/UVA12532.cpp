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

int MAX = 100005;
int num[100005], r[100005], z[100005];
int N;

enum{ ZERO = 0, POS, NEG};

int getValor(int n){
  if (n < 0)
    return -1;
  else if (n > 0)
    return 1;
  else
    return 0;
}

int lsb(int n) { return n & (-n);}

int rsq(int n) { int sum = 1; for (; n > 0; n -= lsb(n)) sum *= num[n]; return sum;}
int rsq(int n1, int n2) { return rsq(n2) * rsq(n1-1); }
void adj(int n, int v) { for (; n <= N; n += lsb(n)) num[n] *= v; }

int rsqZ(int n) { int sum = 0; for (; n > 0; n -= lsb(n)) sum += z[n]; return sum;}
int rsqZ(int n1, int n2) { return rsqZ(n2) - rsqZ(n1-1); }
void adjZ(int n, int v) { for (; n <= N; n += lsb(n)) z[n] += v; }

void update(int i, int v){
  if( r[i] != v ){
    if (v == 0){
      if (r[i] == -1)
        adj(i, -1);
      adjZ(i, 1);
    } else { // v = 1, -1
      if (v == -1)
        adj(i, -1);

      if (r[i] == 0){
        adjZ(i, -1);
      } else if (v == 1){
        adj(i, -1);
      }
    }
    r[i] = v;
  }
}

void ans(int n1, int n2){
  int zero = rsqZ(n1, n2);
  int valor = rsq(n1, n2);
  if (zero > 0){
    cout << 0 ;
  } else if (valor > 0){
    cout << '+';
  } else {
    cout << '-';
  }
}

int main(){
  int K;
  while (cin >> N >> K){
    for (int i = 0; i <= N; i++){
      num[i] = 1;
      z[i] = 0;
      r[i] = 1;
    }
    int cur;
    for (int i = 1; i <= N; i++){
      cin >> cur;
      cur = getValor(cur);
      update(i, cur);
    }
    int n1, n2;
    char command;
    for (int i = 0; i < K; i++){
      cin >> command >> n1 >> n2;
      if (command == 'C'){
        n2 = getValor(n2);
        update(n1, n2);
      } else {
        ans(n1, n2);
      }
    }
    cout << endl;
  }

}
