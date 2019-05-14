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

struct points {
    int l, r, t, b;
};
int n, m;
char table[205][205];
stack<points> st;

int main(){
    IOS

    char c;
    while (cin >> c && c != '#'){
        cin >> n >> m;

        if (c == 'B'){
            loop(i,0,n)
            loop(j,0,m)
            cin >> table[i][j];
            points p; p.l=0; p.r=m-1; p.t=0; p.b=n-1;
            st.push(p);
            string ans = "";
            while (!st.empty()){
                p = st.top(); st.pop();
                char last = table[p.t][p.l];
                bool pos = true;
                loop(i,p.t,p.b+1)
                loop(j,p.l,p.r+1)
                    if (table[i][j] != last){
                        pos = false;
                    }
                if (pos) {
                    ans += last;
                    continue;
                } 
                // cout << p.l << " " << p.b << " " << p.r  << " " << p.t << endl;
                if (p.l==p.r){
                    points pt, pb;
                    pt.t = p.t; pt.l = pt.r = p.l; pt.b = (p.b-p.t)/2+p.t;
                    pb.t = pt.b+1; pb.l = pb.r = p.r; pb.b = p.b;
                    st.push(pb);
                    st.push(pt);
                    ans += 'D';
                } else if (p.t==p.b){
                    points pl, pr;
                    pl.l = p.l; pl.t = pl.b = p.b; pl.r = (p.r-p.l)/2+p.l;
                    pr.l = pl.r+1 ; pr.t = pr.b = p.b; pr.r = p.r;
                    st.push(pr);
                    st.push(pl);
                    ans += 'D';
                } else {
                    points ptl, ptr, pbl, pbr;
                    ptl.l = p.l; ptl.t = p.t; ptl.r = (p.r-p.l)/2+p.l; ptl.b = (p.b-p.t)/2+p.t;
                    ptr.l = ptl.r+1; ptr.t = p.t; ptr.r = p.r; ptr.b = (p.b-p.t)/2+p.t;
                    pbl.l = p.l; pbl.t = ptl.b+1; pbl.r = (p.r-p.l)/2+p.l; pbl.b = p.b;
                    pbr.l = pbl.r+1; pbr.t = ptr.b+1; pbr.r = p.r; pbr.b = p.b;
                    st.push(pbr);
                    st.push(pbl);
                    st.push(ptr);
                    st.push(ptl);
                    ans += 'D';
                }
            }
            cout << "D" << setw(4) << n << setw(4) << m << "\n";
            loop(x,1,ans.size()+1){
                cout << ans[x-1];
                if (x%50==0 && x != ans.size()) cout <<"\n";
            }
            cout << "\n";
        } else {
            string s;
            cin >> s;
            // cout << "STRING " << s << endl;
            points p; p.l=0; p.r=m-1; p.t=0; p.b=n-1;
            st.push(p);
            string ans = "";
            int index = 0;
            while (!st.empty() && index < s.size()){
                p = st.top(); st.pop();
                char ch = s[index++];
                // cout << ch << " == " << endl;
                if (ch == '0'){
                    // cout << "00000 " << p.l << " " << p.b << " " << p.r  << " " << p.t << endl;
                    loop(i,p.t,p.b+1)
                    loop(j,p.l,p.r+1)
                        table[i][j] = '0';
                } else if (ch == '1'){
                    // cout << "11111 " << p.l << " " << p.b << " " << p.r  << " " << p.t << endl;
                    loop(i,p.t,p.b+1)
                    loop(j,p.l,p.r+1)
                        table[i][j] = '1';
                } else {
                    if (p.l==p.r){
                        points pt, pb;
                        pt.t = p.t; pt.l = pt.r = p.l; pt.b = (p.b-p.t)/2+p.t;
                        pb.t = pt.b+1; pb.l = pb.r = p.r; pb.b = p.b;
                        st.push(pb);
                        st.push(pt);
                    } else if (p.t==p.b){
                        points pl, pr;
                        pl.l = p.l; pl.t = pl.b = p.b; pl.r = (p.r-p.l)/2+p.l;
                        pr.l = pl.r+1 ; pr.t = pr.b = p.b; pr.r = p.r;
                        st.push(pr);
                        st.push(pl);
                    } else {
                        points ptl, ptr, pbl, pbr;
                        ptl.l = p.l; ptl.t = p.t; ptl.r = (p.r-p.l)/2+p.l; ptl.b = (p.b-p.t)/2+p.t;
                        ptr.l = ptl.r+1; ptr.t = p.t; ptr.r = p.r; ptr.b = (p.b-p.t)/2+p.t;
                        pbl.l = p.l; pbl.t = ptl.b+1; pbl.r = (p.r-p.l)/2+p.l; pbl.b = p.b;
                        pbr.l = pbl.r+1; pbr.t = ptr.b+1; pbr.r = p.r; pbr.b = p.b;
                        st.push(pbr);
                        st.push(pbl);
                        st.push(ptr);
                        st.push(ptl);
                    }
                }
            }
            loop(i,0,n)
            loop(j,0,m)
                ans += table[i][j];
            cout << "B" << setw(4) << n << setw(4) << m << "\n";
            loop(x,1,ans.size()+1){
                cout << ans[x-1];
                if (x%50==0 && x != ans.size()) cout <<"\n";
            }
            cout << "\n";
        }
        
    }

}