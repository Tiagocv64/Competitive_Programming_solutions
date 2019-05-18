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


int main() {
    IOS

    int T;
    int t = 1;
    cin >> T;
    int n, l;
    int lastF, lastB, m, meters;
    bool forward = true;
    char cur;
    while (T-- > 0){
        cin >> n >> l;
        lastF = 0; lastB = 0;
        m = 0;
        for (int i = 0; i < n; i++){
            cin >> cur;
            if (cur == 'B'){
                cin >> cur;
                cin >> meters;
                m = max(m, max(meters - lastF, meters - lastB));
                lastB = lastF = meters;
            } else {
                cin >> cur;
                cin >> meters;
                if (forward){
                    m = max(m, meters - lastF);
                    lastF = meters;
                } else {
                    m = max(m, meters - lastB);
                    lastB = meters;
                }
                forward = !forward;
            }
        }
        m = max(m, max(l - lastF, l - lastB));
        cout << "Case " << t++ << ": " << m << "\n";
    }
    return 0;
}

