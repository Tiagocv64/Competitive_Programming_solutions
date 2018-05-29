#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int q;
    long long number, result;
    cin >> q;
    while (q > 0) {
        cin >> number;
        number--;
        long long before, after;
        before = number / 4;
        after = number % 4;
        result = before * 1000;
        switch (after){
            case 0:
                result += 192;
                break;
            case 1:
                result += 442;
                break;
            case 2:
                result += 692;
                break;
            case 3:
                result += 942;
        }

        cout << result << endl;
        q--;
    }
}


