#include <iostream>
#include <string>

using namespace std;

int n;
int seq[15];
bool solved = false;
int digit[10] = { 0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B };

void solve(int curDigit, int curIndex, int bitmask){
    if (solved)
        return;

    if (curIndex >= n){
        solved = true;
        return;
    }

    if (!(seq[curIndex] & bitmask)) {  // same bitmask
        if (((digit[curDigit] ^ seq[curIndex]) & seq[curIndex]) == 0){  // more burnt
            int b = (digit[curDigit] ^ seq[curIndex]) | bitmask;
            solve(curDigit-1, curIndex+1, b);
        }
    } 
}

int main(){

    while (cin >> n && n != 0){
        string cur;
        for (int i = 0; i < n; i++){
            cin >> cur;
            int count = 0;
            for (int j = 0; j < cur.size(); j++){
                count = count << 1;
                count += (cur[j] == 'Y')? 1 : 0;
            }
            seq[i] = count;
        }
        solved = false;
        for (int i = 9; i >= n-1; i--)
            solve(i, 0, 0);
        if (solved)
            cout << "MATCH\n";
        else
            cout << "MISMATCH\n";
    }
}