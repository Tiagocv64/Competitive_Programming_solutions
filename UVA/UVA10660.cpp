#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;

    for (int i = 0; i < T; i++){
        int table[5][5] = {0};
        int el;
        cin >> el;
        int col, row;
        for (int j = 0; j < el; j++){
            cin >> row >> col;
            cin >> table[row][col];
        }

        int ans = 10000000;
        int anss[5];

        for (int p1 = 0; p1 < 21; p1++){
            int r1 = p1/5;
            int c1 = p1%5;
            for (int p2 = p1+1; p2 < 22; p2++){
                int r2 = p2/5;
                int c2 = p2%5;
                for (int p3 = p2+1; p3 < 23; p3++){
                    int r3 = p3/5;
                    int c3 = p3%5;
                    for (int p4 = p3+1; p4 < 24; p4++){
                        int r4 = p4/5;
                        int c4 = p4%5;
                        for (int p5 = p4+1; p5 < 25; p5++){
                            int r5 = p5/5;
                            int c5 = p5%5;
                            int cur;
                            int total = 0;
                            for (int r = 0; r < 5; r++){
                                for (int c = 0; c < 5; c++){
                                    cur = min(abs(c-c1)+abs(r-r1), abs(c-c2)+abs(r-r2));
                                    cur = min(cur, abs(c-c3)+abs(r-r3));
                                    cur = min(cur, abs(c-c4)+abs(r-r4));
                                    cur = min(cur, abs(c-c5)+abs(r-r5));
                                    total += cur*table[r][c];
                                }
                            }
                            if (total < ans){
                                ans = total;
                                anss[0] = p1;
                                anss[1] = p2;
                                anss[2] = p3;
                                anss[3] = p4;
                                anss[4] = p5;
                            }
                        }
                    }
                }
            }
        }
        for (int j = 0; j < 4; j++)
            cout << anss[j] << " ";
        cout << anss[4] << endl;
    }

}