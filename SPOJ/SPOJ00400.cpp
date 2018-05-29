#include <iostream>
#include <string>

using namespace std;

int main()
{
    int c;
    cin >> c;
    while(c != 0) {
        string sentence, result = "";
        cin >> sentence;
        int Nletters = sentence.size();
        for (int i = 0 ; i < c ; i++){
            for (int k = 0 ; k*c + i < sentence.size() ; k++){
                int j = k*c;
                if (k % 2){ //odd
                    result += sentence[j+ c-1-i];
                } else {
                    result += sentence[j+ i];
                }
            }
        }
        cout << result << endl;
        cin >> c;
    }
}

