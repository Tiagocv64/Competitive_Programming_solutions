#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  while (n != 0){

    int ans = 0;
    for (int i = 1 ; i <= n ; i++){
        int hip = n - i + 1;
        ans += hip * hip;
    }
    cout << ans << endl;
    cin >> n;
  }
}

