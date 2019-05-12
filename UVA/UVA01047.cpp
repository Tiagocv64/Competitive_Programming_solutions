#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int t, n, m, T = 1;
    while (cin >> t >> n && (t != 0 || n != 0)){
        int towers[25];
        bitset<21> bits[21];
        int count[21];
        for (int i = 0; i < t; i++)
            cin >> towers[i];
        cin >> m;
        for (int i = 0; i < m; i++){
            int c, cur;
            cin >> c;
            for (int j = 0; j < c; j++){
                cin >> cur;
                bits[i].set(cur-1, true);
            }
            cin >> count[i];
        }
        string perm = "";
        
        for (int i = 0; i < n; i++)
            perm += "0";
        for (int i = n; i < t; i++)
            perm += "1";
        
        
        
        string bitM = "test";
        int maxCount = 0;

        do {
            string tmp = "";
            for (int i = perm.size()-1; i >= 0; i--)
                if (perm[i] == '0')
                    tmp += '1';
                else
                    tmp += '0';
            bitset<21> bs(tmp);
            int cou = 0;
            for (int i = 0; i < t; i++){
                if (perm[i] == '0'){
                    cou += towers[i];
                }
            }
            for (int i = 0; i < m; i++){
                int b = (bs & bits[i]).count();
                if (b > 1){
                    cou -= (b-1)*count[i];
                }
            }

            if (cou > maxCount){
                maxCount = cou;
                bitM = perm;
            }

        } while (next_permutation(perm.begin(), perm.end()));

        cout << "Case Number  " << T++ << endl;
        cout << "Number of Customers: " << maxCount << endl;
        cout << "Locations recommended: ";
        int already = 0;
        for (int i = 0; i < bitM.size(); i++){
            if (bitM[i] == '0'){
                if (already == n-1){
                    cout << i+1 << endl << endl;
                    break;
                } else {
                    cout << i+1 << " ";
                    already++;
                }
            }
        }
    }
}