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
#include <unordered_map>

using namespace std;

#define loop(iii,l,r) for (int iii = l; iii < r; iii++)
#define tests int T; cin >> T; while(T--)
#define TESTS int t, T = 0; cin >> t; while (t-- && ++T)
#define all(c) (c).begin(),(c).end() //handy for function like "sort()"
#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); //to desynchronize the input of cin and scanf
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
typedef vector<ii> vii;

// *****************************



int main(){
    IOS

    ui n, l, u;
    while (cin >> n >> l >> u){
        bool bigger = true, smaller = true;
        ui ans = 0;
        for (int i =31; i >= 0; i--){
            ui bit = 1 << i;
            if (bigger){
                if ( (u&bit)==bit && (l&bit)==0){
                    if (n&bit){
                        bigger = false;
                    } else {
                        smaller = false;
                        ans += bit;
                    }
                } else if ((u&bit)==bit && (l&bit)==bit){
                    if (smaller){
                        ans += bit;
                    } else {
                        if ((n&bit)==0)
                            ans+=bit;
                        else 
                            bigger = false;
                    }                    
                }
            } else if (smaller){
                if ((l&bit)==0 && (n&bit)==0){
                    smaller = false;
                }
                if (!((l&bit)==0 && (n&bit)==bit)){
                    ans += bit;
                }
            } else {
                if ((n&bit)==0){
                    ans += bit;
                }
            }
        }
        cout << ans << "\n";
    }
    
}

// bigger = true
//     00 -> 0 t t
//     11 -> 1 t t
//     10 0 -> 1 t f
//     10 1 -> 0 f t
//     01 -> 0 
// smaller = true
//     1 1 -> 1 t
//     0 0 -> 1 f
//     1 0 -> 1 t
//     0 1 -> 0 t