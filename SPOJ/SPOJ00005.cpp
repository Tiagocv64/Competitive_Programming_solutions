#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    long long q;
    cin >> q;
    while (q > 0) {
        string number, answer = "";
        cin >> number;
        int wordlen ;
        answer.reserve(wordlen+1);
        wordlen = number.size();
        bool next = false, same = true;
        for (int i = wordlen/2 - 1 ; i >= 0 ; i--){
            if (number[i] < number[wordlen-1-i]){
                next = true;
                same = false;
                break;
            }
            if (number[i] > number[wordlen-1-i]){
                next = false;
                same = false;
                break;
            }
            if (number[i] != number[wordlen-1-i])
                same = false;
        }
        if (wordlen == 1){
            if(number[0] < '9'){
                char c = number[0] + 1;
                cout << c << endl;
            } else {
                cout << 11 << endl;
            }
            --q;
            continue;
        }
        //length even
        if (wordlen % 2 == 0){
            //passed current palindrome
            if (next || same){
                bool carry = true;
                for (int i =  wordlen/2 - 1 ; i >= 0 ; i--){
                    if (number[i] == '9' && carry){
                        answer += '0';
                        continue;
                    }
                    if (carry){
                        answer += number[i] + 1;
                        carry = false;
                    } else {
                        answer += number[i];
                    }
                }
                if (carry)
                    answer += '1';
            //in current palindrome
            } else {
                for (int i =  wordlen/2 - 1 ; i >= 0 ; i--){
                    answer += number[i];
                }
            }

            reverse(answer.begin() , answer.end());
            int cursize = answer.size();
            if (cursize * 2 != wordlen){
                for (int i = cursize - 2 ; i >= 0 ; i--){
                    answer += answer[i];
                }
            } else {
                for (int i = cursize - 1 ; i >= 0 ; i--){
                    answer += answer[i];
                }
            }

            cout << answer << endl;

        //length palindrome odd
        } else {

             //passed current palindrome
            if (next || same){
                bool carry = true;
                for (int i =  wordlen/2 ; i >= 0 ; i--){
                    if (number[i] == '9' && carry){
                        answer += '0';
                        continue;
                    }
                    if (carry){
                        answer += number[i] + 1;
                        carry = false;
                    } else {
                        answer += number[i];
                    }
                }
                if (carry)
                    answer += '1';
            //in current palindrome
            } else {
                for (int i =  wordlen/2 ; i >= 0 ; i--){
                    answer += number[i];
                }
            }

            reverse(answer.begin() , answer.end());
            int cursize = answer.size();
            if (cursize * 2 != wordlen + 1){
                for (int i = cursize - 3 ; i >= 0 ; i--){
                    answer += answer[i];
                }
            } else {
                for (int i = cursize - 2 ; i >= 0 ; i--){
                    answer += answer[i];
                }
            }

            cout << answer << endl;

        }

        q--;
    }
}


