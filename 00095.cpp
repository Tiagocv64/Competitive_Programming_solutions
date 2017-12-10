#include <iostream>
#include <stack>

using namespace std;

int trucks[1001];

int main(){
   int n;
   cin >> n;
    while (n != 0){

        for (int i = 1 ; i <= n ; i++){
            cin >> trucks[i];
        }
        stack<int> road;
        road.push(0);
        int j = 1;
        for (int i = 1; i <= n ; i++){

            if (j > n){
                if (road.top() == i){
                    road.pop();
                    continue;
                } else {
                    break;
                }
            }

            if (trucks[j] != i && road.top() != i){
                road.push(trucks[j]);
                j++; i--;
                continue;
            }
            if (trucks[j] == i){
                j++;
            } else {
                road.pop();
            }
        }
        if (road.top() == 0){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
        cin >> n;
    }
}
