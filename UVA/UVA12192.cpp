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


int table[505][505];
int n, m, low, high;

bool possible(int k){
    if (k==0) return true;
    loop(i,0,n-k+1){
        int index = lower_bound(table[i], table[i]+m, low) - table[i];
        if (index >= m-k+1) continue;
        if (table[i][index] >= low && table[i+k-1][index+k-1] <= high)
            return true;
    }    
    return false;
}


int main(){
    IOS
    while (cin >> n >> m && n != 0){
        loop(i,0,n)
        loop(j,0,m)
            cin >> table[i][j];

        int q;
        cin >> q;
        loop(i,0,q){
            cin >> low >> high;
            int l = 0, h = min(n,m);
            while (l < h){
                int m = ((h+l)>>1)+1;
                if (possible(m)){
                    l = m;
                }else 
                    h = m-1;
            }
            cout << h << "\n";
        }
        cout << "-\n";
    }   

}