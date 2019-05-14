#include <iostream>
#include <algorithm>

using namespace std;

int num[100005];

int main(){
    int n;
    while (cin >> n){
        for (int i = 0; i < n; i++){
            cin >> num[i];
        }
        int k;
        cin >> k;
        sort(num, num+n);
        int l = 0, r = n-1;
        int ans1 = -1, ans2 = -1;
        while (l < r){
            int sum = num[l] + num[r];
            if (sum > k)
                r--;
            else if (sum < k)
                l++;
            else{
                ans1 = l++;
                ans2 = r--;
            }
        }
        cout << "Peter should buy books whose prices are " << num[ans1] << " and " << num[ans2] << ".\n\n";
    }
}