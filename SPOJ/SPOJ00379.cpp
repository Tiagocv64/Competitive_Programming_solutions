#include <iostream>
#include <stack>

using namespace std;

int permutation1[1000001] , permutation2[1000001];

int main(){
    int n;
    cin >> n;
    while (n != 0){

        for (int i = 1 ; i <= n ; i++){
            cin >> permutation1[i];
            permutation2[permutation1[i]] = i;
        }

        bool ambig = true;
        for (int i = 1 ; i <= n ; i++){
            if (permutation1[i] != permutation2[i]){
                ambig = false;
                break;
            }
        }

        if (ambig){
            cout << "ambiguous" << endl;
        } else {
            cout << "not ambiguous" << endl;
        }
        cin >> n;
    }
}
