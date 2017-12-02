#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int apples[100] = {0};
int diference[100] = {0};

void calculeAnswer() {
    int carrySub = 0;
    for (int i = 99 ; i >= 0 ; i--){
        int result = apples[i] - diference[i] - carrySub;
        carrySub = 0;
        while (result <= 0){
            carrySub++;
            result+= 10;
        }
        apples[i] = result % 10;
        carrySub -= result /10;
    }


    bool start = false, carryout = false, carryin = false;
    for (int i = 0 ; i < 100 ; i++){
        if (start){
            carryout = false;
            if (apples[i] & 1)
                carryout = true;
            apples[i] = apples[i] >> 1;
            if (carryin){
                apples[i] = apples[i] + 5;
            }

        } else if (apples[i] != 0){
            start = true;
            i--;
        }
        carryin = carryout;
    }
    for (int i = 99 ; i > 0 ; i--){
        if (apples[i] > 9){
            apples[i+1] += apples[i] / 10;
            apples[i] %= 10;
        }
    }

        int carryAdd = 0;
    for (int i = 99 ; i >= 0 ; i--){
        int result = apples[i] + diference[i] + carryAdd;
        carryAdd = 0;
        while (result >= 10){
            carryAdd++;
            result-= 10;
        }
        diference[i] = result % 10;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int q = 0;
    while (q < 10){
        string all, dif;
        cin >> all >> dif;
        for (int i = 0 ; i < all.size() ; i++){
            apples[100 - all.size() + i] = all[i] - '0';
        }
        for (int i = 0 ; i < dif.size() ; i++){
            diference[100 - dif.size() + i] = dif[i] - '0';
        }



        calculeAnswer();

        bool start = false;
        for (int l : diference){
            if(start){
                cout << l;
            } else {
                if (l != 0){
                    start = true;
                    cout << l;
                }
            }
        }
        if (!start){
            cout << 0;
        }
        cout << endl;

        start = false;
        for (int l : apples){
            if(start){
                cout << l;
            } else {
                if (l != 0){
                    start = true;
                    cout << l;
                }
            }
        }
        if (!start){
            cout << 0;
        }
        cout << endl;

        fill(apples, apples + 100 , 0);
        fill(diference, diference + 100 , 0);

        q++;
    }


}


