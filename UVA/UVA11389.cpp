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

int a[105], b[105];

int main(){
    IOS

    int n, d, r;
    while (cin >> n >> d >> r && n != 0){
        loop(i,0,n)
            cin >> a[i];
        loop(i,0,n)
            cin >> b[i];
        sort(a, a+n);
        sort(b, b+n, greater<int>());
        int ans = 0;
        loop(i,0,n)
            ans += max(0, a[i]+b[i]-d)*r;
        cout << ans << "\n";
    }

}