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
	ll N, pos;
	while (cin >> N >> pos && (N != 0 || pos != 0)){
		int layer = 0, cur = 1;
		ll nFila, camada;
		while (true){
			nFila = layer*2+1;
			camada = nFila*4-4;
			if (cur + camada >= pos){
				cur++;
				break;
			}
			cur += camada;
			layer++;
		}
		int pSeq = pos-cur, Y = 0, X = 0;
		if (pSeq <= nFila-2){ //top
			Y = N/2+layer+1;
			X = -pSeq;
			X += N/2+layer;

		} else if (pSeq <= nFila*2-3){ //left
			X = N/2-layer+1;
			Y = -(pSeq-nFila+2);
			Y += N/2+layer+1;
		} else if (pSeq <= nFila*3-4){ //bot
			Y = N/2-layer+1;
			X = pSeq - nFila*2+3;
			X += N/2-layer+1;

		} else { //right
			X = N/2+layer+1;
			Y = pSeq-nFila*3+4;
			Y += N/2-layer+1;
		}
		cout << "Line = " << Y << ", column = " << X << ".\n";
	}
}