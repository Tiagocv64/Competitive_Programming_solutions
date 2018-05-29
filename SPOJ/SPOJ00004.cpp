#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack<string> letters , simbols;
    int q;
    cin >> q;
    while (q > 0){
        string expression, answer = "";
        cin >> expression;
        for (char c : expression){
            if ( !(c == ')') ){
                if( c =='+' || c == '-' || c == '/' || c == '*' || c == '^'){
                    simbols.push(string(1, c));
                } else {
                    letters.push(string(1, c));
                }
            } else {
                string current;
                current = letters.top(); letters.pop();
                current = letters.top() + current; letters.pop();
                letters.pop(); // (
                current += simbols.top(); simbols.pop();
                letters.push(current);
            }
        }
        cout << letters.top() << endl;
        letters.pop();
        --q;
    }
}


