#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    bool a = true;
    while (a){
        cin >> i;
        if (i == 42){
            a = false;
            continue;
        }
        cout << i << endl;
    }
}
