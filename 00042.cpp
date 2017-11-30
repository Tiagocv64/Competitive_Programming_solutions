#include <iostream>

using namespace std;

long long convert(long long n){
    long long as = 0;
    while (n != 0){
        as = as*10 + n%10;
        n /= 10;
    }
    return as;
}

int main()
{
    int i;
    long long n1, n2;
    cin >> i;
    while (i >0){
        cin >> n1 >> n2;
        n1 = convert(n1);
        n2 = convert(n2);
        n1 += n2;
        n1 = convert(n1);
        cout << n1 << endl;
        --i;
    }
}


