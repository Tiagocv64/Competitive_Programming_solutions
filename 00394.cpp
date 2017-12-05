#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long solucao[5001];

int main()
{
    ios::sync_with_stdio(false);

    while (true){
        solucao[0] = 1;
        solucao[1] = 1;
        string palavra;
        cin >> palavra;

        if (palavra[0] == '0'){
            break;
        }
        for (int i = 1; i < palavra.size(); i++){
            if(palavra[i] == '0' && (palavra[i-1] > '2' || palavra[i-1] == '0')){
                solucao[palavra.size()] = 0;
                break;
            }
            if(palavra[i] == '0'){
                solucao[i+1] = solucao[i-1];
                continue;
            }
            if(palavra[i-1] == '1'){
                solucao[i+1] = solucao[i] + solucao[i-1];
                continue;
            }
            if(palavra[i-1] == '2' && palavra[i] < '7'){
                solucao[i+1] = solucao[i] + solucao[i-1];
                continue;
            }

            solucao[i+1] = solucao[i];

        }
        cout << solucao[palavra.size()] << endl;
    }
}


