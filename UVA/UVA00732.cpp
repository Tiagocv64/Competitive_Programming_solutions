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

string source, target;

bool validPerm(string perm){
  int pushs = 0, pops = 0;
  LOOP(i,0,perm.size()){
    if (perm.at(i) == 'i'){
      pushs++;
    } else {
      pops++;
    }
    if (pops > pushs || pushs > target.size())
      return false;
  }
  return true;
}

bool possiblePerm(string perm){
  if(!validPerm(perm)) return false;
  string cur = "";
  stack<char> st;
  int index = 0;
  LOOP(i, 0, perm.size()){
    if (perm.at(i) == 'i'){
      st.push(source.at(index++));
    } else {
      cur += st.top();
      st.pop();
      if (cur.at(cur.size()-1) != target.at(cur.size()-1)) return false;
    }
  }
  return true;
}

void recFind(string perm, int index){
  if (index == 2*target.size()){
    LOOP(i,0,perm.size()-1)
      cout << perm.at(i) << " ";
    cout << perm.at(perm.size()-1) << "\n";
  }
  if (possiblePerm(perm+"i"))
    recFind(perm+"i", index+1);
  if (possiblePerm(perm+"o"))
    recFind(perm+"o", index+1);
}


int main(){
  while (cin >> source >> target){

    cout << "[\n";
    if (source.size() == target.size())
      recFind("", 0);
    cout << "]\n";
  }
}
