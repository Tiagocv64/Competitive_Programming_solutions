#include <iostream>
#include <math.h>

using namespace std;

int candy[10005] = {0};

int main()
{
    int n;
    cin >> n;
    while (n != -1){
        int sum = 0;
        for (int i = 0 ; i < n ; i++){
            cin >> candy[i];
            sum +=candy[i];
        }
        float avg = sum * 1.0 / n;
        int average = avg;
        if (!(avg == floor(avg))){
            cout << -1 << endl;
        } else {
            int ans = 0;
            for (int i = 0 ; i < n ; i++){
                if (candy[i] < average){
                    ans += average - candy[i];
                }
            }
            cout << ans << endl;
        }
        cin >> n;
    }
}

