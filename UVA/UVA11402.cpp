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

int st [4096005], lz[4096005];
bitset<1024005> pirates;
int N;

enum {CLR = 0, ONE, ZERO, INV};

int left(int n){ return (n << 1) + 1;}
int right(int n){ return (n << 1) + 2;}
void build(int l, int r, int p){
  if (l > r)
    return;

  lz[p] = CLR;

  if (l == r){
    st[p] = pirates[l];
  } else {
    int nl = left(p), nr = right(p);
    int mid = (l+r)/2;
    build(l, mid, nl);
    build(mid + 1, r, nr);
    st[p] = st[nl] + st[nr];
  }
}


int flip(int E){
  switch (E) {
    case ONE:
      return ZERO;
    case ZERO:
      return ONE;
    case INV:
      return CLR;
    default:
      return INV;
  };
}

void propagate(int l, int r, int p){
  if (lz[p] == CLR) return;
  if (lz[p] == ONE){
    st[p] = r-l+1;
  } else if (lz[p] == ZERO){
    st[p] = 0;
  } else {
    st[p] = (r-l+1)-st[p];
  }
  if (l != r){
    if (lz[p] == INV){
      lz[left(p)] = flip(lz[left(p)]);
      lz[right(p)] = flip(lz[right(p)]);
    } else {
      lz[left(p)] = lz[right(p)] = lz[p];
    }
  }
  lz[p] = CLR;
  return;
}

int query(int begin, int end, int l, int r, int p){

  if (lz[p] != CLR)
    propagate(l, r, p);

  if (r < begin || l > end || r < l)
    return 0;

  if (begin <= l && r <= end)
    return st[p];

  int mid = (l+r)/2;
  return query(begin, end, l, mid, left(p)) +
          query(begin, end, mid+1, r, right(p));
}
void update(int begin, int end, int l, int r, int p, int E){

  if (lz[p] != CLR)
    propagate(l, r, p);

  if (r < begin || l > end || l > r)
    return;

  if (begin <= l && r <= end){
    if (E == ONE){
      st[p] = r-l+1;
      if (l != r)
        lz[left(p)] = lz[right(p)] = ONE;
    } else if (E == ZERO){
      st[p] = 0;
      if (l != r)
        lz[left(p)] = lz[right(p)] = ZERO;
    } else if (E == INV){
      st[p] = (r-l+1) - st[p];
      if (l != r){
        lz[left(p)] = flip(lz[left(p)]);
        lz[right(p)] = flip(lz[right(p)]);
      }
    }
    return;
  }
  int mid = (l+r)/2;
  update(begin, end, l, mid, left(p), E);
  update(begin, end, mid+1, r, right(p), E);
  st[p] = st[left(p)] + st[right(p)];
}



void build(int n){ N = n ;build(0, n-1, 0); }
int query(int begin, int end) { return query(begin, end, 0, N-1, 0); }
void update(int L, int R, char c) {
  int E = CLR;
  if (c == 'F') E = ONE;
  else if (c == 'E') E = ZERO;
  else if (c == 'I') E = INV;
  update(L, R, 0, N-1, 0, E);
}


int main(){
  int T, t = 0, q = 0;
  cin >> T;
  while (t++ < T){
    int M, m, i = 0;
    N = 0;
    string line;
    cin >> M;
    while (M-- > 0){
      cin >> m >> line;
      N += m * line.size();
      while (m-- > 0){
        for (char c : line){
          pirates[i++] = (c == '1');
        }
      }
    }
    i = 2048000;
    for (i--; i >= 0; i--){
      lz[i] = CLR;
      st[i] = 0;
    }
    build(N);
    int Q;
    cin >> Q;
    q = 1;
    cout << "Case " << t << ":\n";
    int n1, n2;
    char c;
    while (Q-- > 0){
      cin >> c >> n1 >> n2;
      if (c == 'S')
        cout << "Q" << q++ << ": " << query(n1, n2) << endl;
      else
        update(n1, n2, c);
    }
  }
}
